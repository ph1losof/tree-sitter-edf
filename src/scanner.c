#include "tree_sitter/parser.h"
#include <stdbool.h>

/**
 * External scanner for EDF - Optimized for maximum speed
 *
 * Key insight: When returning false after advancing, tree-sitter does NOT
 * restore lexer position. So we must either:
 * 1. Only advance when certain of success, OR
 * 2. Handle fallback within the same code path
 */

enum TokenType {
  UNQUOTED_CONTENT,
  SINGLE_QUOTED_CONTENT,
  DOUBLE_QUOTED_CONTENT,
  SIMPLE_VARIABLE,
  VARIABLE_EXPANSION,
  COMMAND_SUBSTITUTION,
  BACKTICK_SUBSTITUTION,
  ESCAPE_SEQUENCE,
};

#if defined(__GNUC__) || defined(__clang__)
  #define LIKELY(x)   __builtin_expect(!!(x), 1)
  #define UNLIKELY(x) __builtin_expect(!!(x), 0)
  #define HOT __attribute__((hot))
#else
  #define LIKELY(x)   (x)
  #define UNLIKELY(x) (x)
  #define HOT
#endif

#define CHAR_SPACE    0x01
#define CHAR_NEWLINE  0x02
#define CHAR_ALPHA    0x04
#define CHAR_DIGIT    0x08
#define CHAR_UNDER    0x10

static const unsigned char CHAR_TABLE[256] = {
  [0x00] = CHAR_NEWLINE,
  ['\t'] = CHAR_SPACE,
  ['\n'] = CHAR_NEWLINE,
  ['\r'] = CHAR_NEWLINE,
  [' ']  = CHAR_SPACE,
  ['0'] = CHAR_DIGIT, ['1'] = CHAR_DIGIT, ['2'] = CHAR_DIGIT, ['3'] = CHAR_DIGIT,
  ['4'] = CHAR_DIGIT, ['5'] = CHAR_DIGIT, ['6'] = CHAR_DIGIT, ['7'] = CHAR_DIGIT,
  ['8'] = CHAR_DIGIT, ['9'] = CHAR_DIGIT,
  ['A'] = CHAR_ALPHA, ['B'] = CHAR_ALPHA, ['C'] = CHAR_ALPHA, ['D'] = CHAR_ALPHA,
  ['E'] = CHAR_ALPHA, ['F'] = CHAR_ALPHA, ['G'] = CHAR_ALPHA, ['H'] = CHAR_ALPHA,
  ['I'] = CHAR_ALPHA, ['J'] = CHAR_ALPHA, ['K'] = CHAR_ALPHA, ['L'] = CHAR_ALPHA,
  ['M'] = CHAR_ALPHA, ['N'] = CHAR_ALPHA, ['O'] = CHAR_ALPHA, ['P'] = CHAR_ALPHA,
  ['Q'] = CHAR_ALPHA, ['R'] = CHAR_ALPHA, ['S'] = CHAR_ALPHA, ['T'] = CHAR_ALPHA,
  ['U'] = CHAR_ALPHA, ['V'] = CHAR_ALPHA, ['W'] = CHAR_ALPHA, ['X'] = CHAR_ALPHA,
  ['Y'] = CHAR_ALPHA, ['Z'] = CHAR_ALPHA,
  ['_'] = CHAR_UNDER,
  ['a'] = CHAR_ALPHA, ['b'] = CHAR_ALPHA, ['c'] = CHAR_ALPHA, ['d'] = CHAR_ALPHA,
  ['e'] = CHAR_ALPHA, ['f'] = CHAR_ALPHA, ['g'] = CHAR_ALPHA, ['h'] = CHAR_ALPHA,
  ['i'] = CHAR_ALPHA, ['j'] = CHAR_ALPHA, ['k'] = CHAR_ALPHA, ['l'] = CHAR_ALPHA,
  ['m'] = CHAR_ALPHA, ['n'] = CHAR_ALPHA, ['o'] = CHAR_ALPHA, ['p'] = CHAR_ALPHA,
  ['q'] = CHAR_ALPHA, ['r'] = CHAR_ALPHA, ['s'] = CHAR_ALPHA, ['t'] = CHAR_ALPHA,
  ['u'] = CHAR_ALPHA, ['v'] = CHAR_ALPHA, ['w'] = CHAR_ALPHA, ['x'] = CHAR_ALPHA,
  ['y'] = CHAR_ALPHA, ['z'] = CHAR_ALPHA,
};

void *tree_sitter_edf_external_scanner_create(void) { return NULL; }
void tree_sitter_edf_external_scanner_destroy(void *p) { (void)p; }
unsigned tree_sitter_edf_external_scanner_serialize(void *p, char *b) { (void)p; (void)b; return 0; }
void tree_sitter_edf_external_scanner_deserialize(void *p, const char *b, unsigned l) { (void)p; (void)b; (void)l; }

static inline bool is_space(int32_t c) {
  return (c < 256) && (CHAR_TABLE[(unsigned char)c] & CHAR_SPACE);
}

static inline bool is_eol(int32_t c) {
  return (c < 256) && (CHAR_TABLE[(unsigned char)c] & CHAR_NEWLINE);
}

static inline bool is_var_start(int32_t c) {
  return (c < 256) && (CHAR_TABLE[(unsigned char)c] & (CHAR_ALPHA | CHAR_UNDER));
}

static inline bool is_var_char(int32_t c) {
  return (c < 256) && (CHAR_TABLE[(unsigned char)c] & (CHAR_ALPHA | CHAR_DIGIT | CHAR_UNDER));
}

static inline void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

static inline void skip(TSLexer *lexer) {
  lexer->advance(lexer, true);
}

HOT bool tree_sitter_edf_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  (void)payload;
  int32_t c = lexer->lookahead;

  // === ESCAPE SEQUENCE: \n, \t, \r, \\, \", \$ ===
  if (c == '\\' && valid_symbols[ESCAPE_SEQUENCE]) {
    advance(lexer);
    c = lexer->lookahead;
    if (c == 'n' || c == 't' || c == 'r' || c == '\\' || c == '"' || c == '$') {
      advance(lexer);
      lexer->result_symbol = ESCAPE_SEQUENCE;
      return true;
    }
    // Invalid escape - this shouldn't happen in well-formed input
    return false;
  }

  // === SINGLE QUOTED CONTENT ===
  if (valid_symbols[SINGLE_QUOTED_CONTENT]) {
    if (c == '\'' || c == 0) return false;
    while (lexer->lookahead != '\'' && lexer->lookahead != 0) {
      advance(lexer);
    }
    lexer->result_symbol = SINGLE_QUOTED_CONTENT;
    return true;
  }

  // === DOUBLE QUOTED STRING ELEMENTS ===
  // When inside double quotes, we need to handle:
  // - escape_sequence (starts with \) - handled above
  // - variable_expansion (${...})
  // - simple_variable ($VAR)
  // - command_substitution ($(...))
  // - double_quoted_content (everything else)
  if (valid_symbols[DOUBLE_QUOTED_CONTENT]) {
    // This means we're inside double quotes
    // Check for $ to see if it's interpolation or content

    if (c == '"' || c == 0) return false;  // End of string

    if (c == '$') {
      advance(lexer);
      int32_t next = lexer->lookahead;

      // ${VAR} or ${VAR:-default}
      if (next == '{' && valid_symbols[VARIABLE_EXPANSION]) {
        advance(lexer);
        if (!is_var_start(lexer->lookahead)) {
          // Invalid ${, treat as content
          goto double_quoted_content_continue;
        }

        do { advance(lexer); } while (is_var_char(lexer->lookahead));
        c = lexer->lookahead;

        if (c == '}') {
          advance(lexer);
          lexer->result_symbol = VARIABLE_EXPANSION;
          return true;
        }

        if (c == ':') { advance(lexer); c = lexer->lookahead; }
        if (c != '-' && c != '+') {
          // Invalid expansion, treat as content
          goto double_quoted_content_continue;
        }
        advance(lexer);

        int depth = 1;
        while (depth > 0) {
          c = lexer->lookahead;
          if (c == 0) goto double_quoted_content_continue;
          if (c == '}') { depth--; if (depth > 0) advance(lexer); }
          else if (c == '$') { advance(lexer); if (lexer->lookahead == '{') { advance(lexer); depth++; } }
          else if (c == '\\') { advance(lexer); if (lexer->lookahead != 0) advance(lexer); }
          else advance(lexer);
        }
        advance(lexer);
        lexer->result_symbol = VARIABLE_EXPANSION;
        return true;
      }

      // $(command)
      if (next == '(' && valid_symbols[COMMAND_SUBSTITUTION]) {
        advance(lexer);
        int depth = 1;
        while (depth > 0) {
          c = lexer->lookahead;
          if (c == 0) goto double_quoted_content_continue;
          if (c == ')') { depth--; if (depth > 0) advance(lexer); }
          else if (c == '(') { depth++; advance(lexer); }
          else if (c == '\\') { advance(lexer); if (lexer->lookahead != 0) advance(lexer); }
          else if (c == '\'') {
            advance(lexer);
            while (lexer->lookahead != 0 && lexer->lookahead != '\'') advance(lexer);
            if (lexer->lookahead == '\'') advance(lexer);
          }
          else if (c == '"') {
            advance(lexer);
            while (lexer->lookahead != 0 && lexer->lookahead != '"') {
              if (lexer->lookahead == '\\') { advance(lexer); if (lexer->lookahead != 0) advance(lexer); }
              else advance(lexer);
            }
            if (lexer->lookahead == '"') advance(lexer);
          }
          else advance(lexer);
        }
        advance(lexer);
        lexer->result_symbol = COMMAND_SUBSTITUTION;
        return true;
      }

      // $VAR
      if (is_var_start(next) && valid_symbols[SIMPLE_VARIABLE]) {
        do { advance(lexer); } while (is_var_char(lexer->lookahead));
        lexer->result_symbol = SIMPLE_VARIABLE;
        return true;
      }

      // $ not followed by valid interpolation - it's part of content
      // Fall through to content scanning (we've already consumed $)
    }

    // `command` - backtick substitution (legacy syntax)
    // Must have content - reject empty `` or consecutive ```
    if (c == '`' && valid_symbols[BACKTICK_SUBSTITUTION]) {
      advance(lexer);
      // Check for empty backticks `` - treat as literal
      if (lexer->lookahead == '`') {
        // Don't consume second backtick, fall through to content
        goto double_quoted_content_continue;
      }
      bool has_content = false;
      while (lexer->lookahead != '`' && lexer->lookahead != 0) {
        has_content = true;
        if (lexer->lookahead == '\\') {
          advance(lexer);
          if (lexer->lookahead != 0) advance(lexer);
        } else {
          advance(lexer);
        }
      }
      if (has_content && lexer->lookahead == '`') {
        advance(lexer);
        lexer->result_symbol = BACKTICK_SUBSTITUTION;
        return true;
      }
      // Unclosed or empty backtick - treat as content
      goto double_quoted_content_continue;
    }

    // Scan content until we hit ", \, $, `, or EOF
    double_quoted_content_continue:
    while (LIKELY(true)) {
      c = lexer->lookahead;
      if (c == '"' || c == '\\' || c == '$' || c == '`' || c == 0) break;
      advance(lexer);
    }
    lexer->result_symbol = DOUBLE_QUOTED_CONTENT;
    return true;
  }

  // === UNQUOTED VALUE ELEMENTS ===
  if (valid_symbols[UNQUOTED_CONTENT]) {
    // Reject if starting with quote, space, or EOL
    if (c == '"' || c == '\'' || is_space(c) || is_eol(c)) return false;

    bool has_content = false;

    // Handle $ - check for interpolation first
    if (c == '$') {
      advance(lexer);
      int32_t next = lexer->lookahead;

      // ${VAR}
      if (next == '{' && valid_symbols[VARIABLE_EXPANSION]) {
        advance(lexer);
        if (!is_var_start(lexer->lookahead)) goto unquoted_content_continue;

        do { advance(lexer); } while (is_var_char(lexer->lookahead));
        c = lexer->lookahead;

        if (c == '}') {
          advance(lexer);
          lexer->result_symbol = VARIABLE_EXPANSION;
          return true;
        }

        if (c == ':') { advance(lexer); c = lexer->lookahead; }
        if (c != '-' && c != '+') goto unquoted_content_continue;
        advance(lexer);

        int depth = 1;
        while (depth > 0) {
          c = lexer->lookahead;
          if (c == 0) goto unquoted_content_continue;
          if (c == '}') { depth--; if (depth > 0) advance(lexer); }
          else if (c == '$') { advance(lexer); if (lexer->lookahead == '{') { advance(lexer); depth++; } }
          else if (c == '\\') { advance(lexer); if (lexer->lookahead != 0) advance(lexer); }
          else advance(lexer);
        }
        advance(lexer);
        lexer->result_symbol = VARIABLE_EXPANSION;
        return true;
      }

      // $(command)
      if (next == '(' && valid_symbols[COMMAND_SUBSTITUTION]) {
        advance(lexer);
        int depth = 1;
        while (depth > 0) {
          c = lexer->lookahead;
          if (c == 0) goto unquoted_content_continue;
          if (c == ')') { depth--; if (depth > 0) advance(lexer); }
          else if (c == '(') { depth++; advance(lexer); }
          else if (c == '\\') { advance(lexer); if (lexer->lookahead != 0) advance(lexer); }
          else if (c == '\'') {
            advance(lexer);
            while (lexer->lookahead != 0 && lexer->lookahead != '\'') advance(lexer);
            if (lexer->lookahead == '\'') advance(lexer);
          }
          else if (c == '"') {
            advance(lexer);
            while (lexer->lookahead != 0 && lexer->lookahead != '"') {
              if (lexer->lookahead == '\\') { advance(lexer); if (lexer->lookahead != 0) advance(lexer); }
              else advance(lexer);
            }
            if (lexer->lookahead == '"') advance(lexer);
          }
          else advance(lexer);
        }
        advance(lexer);
        lexer->result_symbol = COMMAND_SUBSTITUTION;
        return true;
      }

      // $VAR
      if (is_var_start(next) && valid_symbols[SIMPLE_VARIABLE]) {
        do { advance(lexer); } while (is_var_char(lexer->lookahead));
        lexer->result_symbol = SIMPLE_VARIABLE;
        return true;
      }

      // $ not followed by valid interpolation - include in content
      has_content = true;
    }

    // `command` - backtick substitution (legacy syntax)
    // Must have content - reject empty `` or consecutive ```
    if (c == '`' && valid_symbols[BACKTICK_SUBSTITUTION]) {
      advance(lexer);
      // Check for empty backticks `` - treat as literal
      if (lexer->lookahead == '`') {
        // Don't consume second backtick, fall through to content
        has_content = true;
        goto unquoted_content_continue;
      }
      bool backtick_has_content = false;
      while (lexer->lookahead != '`' && lexer->lookahead != 0 && !is_eol(lexer->lookahead)) {
        backtick_has_content = true;
        if (lexer->lookahead == '\\') {
          advance(lexer);
          if (lexer->lookahead != 0 && !is_eol(lexer->lookahead)) advance(lexer);
        } else {
          advance(lexer);
        }
      }
      if (backtick_has_content && lexer->lookahead == '`') {
        advance(lexer);
        lexer->result_symbol = BACKTICK_SUBSTITUTION;
        return true;
      }
      // Unclosed or empty backtick - treat as content
      has_content = true;
    }

    // Scan unquoted content
    unquoted_content_continue:
    while (LIKELY(true)) {
      c = lexer->lookahead;

      if (UNLIKELY(is_eol(c))) break;

      if (UNLIKELY(c == '$' || c == '`')) {
        // Stop before $ or ` to let interpolation be parsed separately
        lexer->mark_end(lexer);
        break;
      }

      if (UNLIKELY(is_space(c))) {
        lexer->mark_end(lexer);
        while (is_space(lexer->lookahead)) advance(lexer);
        c = lexer->lookahead;
        if (c == '#' || is_eol(c) || c == '$' || c == '`') break;
        has_content = true;
        continue;
      }

      if (UNLIKELY(c == '\\')) {
        advance(lexer);
        has_content = true;
        c = lexer->lookahead;
        if (c == '\n') { advance(lexer); while (is_space(lexer->lookahead)) skip(lexer); }
        else if (c == '\r') { advance(lexer); if (lexer->lookahead == '\n') advance(lexer); while (is_space(lexer->lookahead)) skip(lexer); }
        continue;
      }

      advance(lexer);
      has_content = true;
    }

    if (!has_content) return false;
    lexer->result_symbol = UNQUOTED_CONTENT;
    return true;
  }

  return false;
}
