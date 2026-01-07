#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 32
#define ALIAS_COUNT 0
#define TOKEN_COUNT 20
#define EXTERNAL_TOKEN_COUNT 8
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  aux_sym__line_token1 = 1,
  anon_sym_POUND = 2,
  sym_comment_content = 3,
  anon_sym_EQ = 4,
  sym_export_keyword = 5,
  sym_key = 6,
  anon_sym_SQUOTE = 7,
  anon_sym_SQUOTE2 = 8,
  anon_sym_DQUOTE = 9,
  anon_sym_DQUOTE2 = 10,
  sym_inline_comment = 11,
  sym__unquoted_content = 12,
  sym__single_quoted_content = 13,
  sym__double_quoted_content = 14,
  sym_simple_variable = 15,
  sym_variable_expansion = 16,
  sym_command_substitution = 17,
  sym_backtick_substitution = 18,
  sym_escape_sequence = 19,
  sym_source_file = 20,
  sym_comment = 21,
  sym_pair = 22,
  sym_single_quoted_string = 23,
  sym_single_quoted_content = 24,
  sym_double_quoted_string = 25,
  sym_double_quoted_content = 26,
  sym_unquoted_value = 27,
  sym_unquoted_content = 28,
  aux_sym_source_file_repeat1 = 29,
  aux_sym_double_quoted_string_repeat1 = 30,
  aux_sym_unquoted_value_repeat1 = 31,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__line_token1] = "_line_token1",
  [anon_sym_POUND] = "#",
  [sym_comment_content] = "comment_content",
  [anon_sym_EQ] = "=",
  [sym_export_keyword] = "export_keyword",
  [sym_key] = "key",
  [anon_sym_SQUOTE] = "'",
  [anon_sym_SQUOTE2] = "'",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_DQUOTE2] = "\"",
  [sym_inline_comment] = "inline_comment",
  [sym__unquoted_content] = "_unquoted_content",
  [sym__single_quoted_content] = "_single_quoted_content",
  [sym__double_quoted_content] = "_double_quoted_content",
  [sym_simple_variable] = "simple_variable",
  [sym_variable_expansion] = "variable_expansion",
  [sym_command_substitution] = "command_substitution",
  [sym_backtick_substitution] = "backtick_substitution",
  [sym_escape_sequence] = "escape_sequence",
  [sym_source_file] = "source_file",
  [sym_comment] = "comment",
  [sym_pair] = "pair",
  [sym_single_quoted_string] = "single_quoted_string",
  [sym_single_quoted_content] = "single_quoted_content",
  [sym_double_quoted_string] = "double_quoted_string",
  [sym_double_quoted_content] = "double_quoted_content",
  [sym_unquoted_value] = "unquoted_value",
  [sym_unquoted_content] = "unquoted_content",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_double_quoted_string_repeat1] = "double_quoted_string_repeat1",
  [aux_sym_unquoted_value_repeat1] = "unquoted_value_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__line_token1] = aux_sym__line_token1,
  [anon_sym_POUND] = anon_sym_POUND,
  [sym_comment_content] = sym_comment_content,
  [anon_sym_EQ] = anon_sym_EQ,
  [sym_export_keyword] = sym_export_keyword,
  [sym_key] = sym_key,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [anon_sym_SQUOTE2] = anon_sym_SQUOTE,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_DQUOTE2] = anon_sym_DQUOTE,
  [sym_inline_comment] = sym_inline_comment,
  [sym__unquoted_content] = sym__unquoted_content,
  [sym__single_quoted_content] = sym__single_quoted_content,
  [sym__double_quoted_content] = sym__double_quoted_content,
  [sym_simple_variable] = sym_simple_variable,
  [sym_variable_expansion] = sym_variable_expansion,
  [sym_command_substitution] = sym_command_substitution,
  [sym_backtick_substitution] = sym_backtick_substitution,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_source_file] = sym_source_file,
  [sym_comment] = sym_comment,
  [sym_pair] = sym_pair,
  [sym_single_quoted_string] = sym_single_quoted_string,
  [sym_single_quoted_content] = sym_single_quoted_content,
  [sym_double_quoted_string] = sym_double_quoted_string,
  [sym_double_quoted_content] = sym_double_quoted_content,
  [sym_unquoted_value] = sym_unquoted_value,
  [sym_unquoted_content] = sym_unquoted_content,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_double_quoted_string_repeat1] = aux_sym_double_quoted_string_repeat1,
  [aux_sym_unquoted_value_repeat1] = aux_sym_unquoted_value_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__line_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [sym_comment_content] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_export_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_key] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE2] = {
    .visible = true,
    .named = false,
  },
  [sym_inline_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__unquoted_content] = {
    .visible = false,
    .named = true,
  },
  [sym__single_quoted_content] = {
    .visible = false,
    .named = true,
  },
  [sym__double_quoted_content] = {
    .visible = false,
    .named = true,
  },
  [sym_simple_variable] = {
    .visible = true,
    .named = true,
  },
  [sym_variable_expansion] = {
    .visible = true,
    .named = true,
  },
  [sym_command_substitution] = {
    .visible = true,
    .named = true,
  },
  [sym_backtick_substitution] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_pair] = {
    .visible = true,
    .named = true,
  },
  [sym_single_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_single_quoted_content] = {
    .visible = true,
    .named = true,
  },
  [sym_double_quoted_string] = {
    .visible = true,
    .named = true,
  },
  [sym_double_quoted_content] = {
    .visible = true,
    .named = true,
  },
  [sym_unquoted_value] = {
    .visible = true,
    .named = true,
  },
  [sym_unquoted_content] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_double_quoted_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_unquoted_value_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '"') ADVANCE(23);
      if (lookahead == '#') ADVANCE(8);
      if (lookahead == '\'') ADVANCE(21);
      if (lookahead == '=') ADVANCE(11);
      if (lookahead == 'e') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(7);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '"') ADVANCE(22);
      if (lookahead == '#') ADVANCE(24);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '"') ADVANCE(22);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(23);
      if (lookahead == '\'') ADVANCE(21);
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(1);
      if (lookahead == '"') ADVANCE(22);
      if (lookahead == '#') ADVANCE(8);
      if (lookahead == '\'') ADVANCE(20);
      if (lookahead == 'e') ADVANCE(17);
      if (lookahead == '\t' ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(aux_sym__line_token1);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_comment_content);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(9);
      if (lookahead != 0 &&
          lookahead != '\t' &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(10);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_comment_content);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_export_keyword);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'o') ADVANCE(15);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'p') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'r') ADVANCE(16);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 't') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == 'x') ADVANCE(14);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(sym_key);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(19);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_SQUOTE2);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_DQUOTE2);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_inline_comment);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\r') ADVANCE(24);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 3, .external_lex_state = 2},
  [3] = {.lex_state = 3, .external_lex_state = 2},
  [4] = {.lex_state = 4, .external_lex_state = 3},
  [5] = {.lex_state = 4, .external_lex_state = 3},
  [6] = {.lex_state = 3, .external_lex_state = 2},
  [7] = {.lex_state = 4, .external_lex_state = 3},
  [8] = {.lex_state = 3, .external_lex_state = 2},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 4, .external_lex_state = 3},
  [12] = {.lex_state = 3, .external_lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 4, .external_lex_state = 4},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 3},
  [24] = {.lex_state = 3},
  [25] = {.lex_state = 3},
  [26] = {.lex_state = 3},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 4},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__line_token1] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [sym_export_keyword] = ACTIONS(1),
    [sym_key] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE2] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_DQUOTE2] = ACTIONS(1),
    [sym__unquoted_content] = ACTIONS(1),
    [sym__single_quoted_content] = ACTIONS(1),
    [sym__double_quoted_content] = ACTIONS(1),
    [sym_simple_variable] = ACTIONS(1),
    [sym_variable_expansion] = ACTIONS(1),
    [sym_command_substitution] = ACTIONS(1),
    [sym_backtick_substitution] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(35),
    [sym_comment] = STATE(9),
    [sym_pair] = STATE(9),
    [aux_sym_source_file_repeat1] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__line_token1] = ACTIONS(5),
    [anon_sym_POUND] = ACTIONS(7),
    [sym_export_keyword] = ACTIONS(9),
    [sym_key] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(13), 1,
      aux_sym__line_token1,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(19), 1,
      sym_inline_comment,
    ACTIONS(21), 1,
      sym__unquoted_content,
    STATE(6), 2,
      sym_unquoted_content,
      aux_sym_unquoted_value_repeat1,
    STATE(23), 3,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_unquoted_value,
    ACTIONS(23), 4,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
  [31] = 8,
    ACTIONS(15), 1,
      anon_sym_SQUOTE,
    ACTIONS(17), 1,
      anon_sym_DQUOTE,
    ACTIONS(21), 1,
      sym__unquoted_content,
    ACTIONS(25), 1,
      aux_sym__line_token1,
    ACTIONS(27), 1,
      sym_inline_comment,
    STATE(6), 2,
      sym_unquoted_content,
      aux_sym_unquoted_value_repeat1,
    STATE(22), 3,
      sym_single_quoted_string,
      sym_double_quoted_string,
      sym_unquoted_value,
    ACTIONS(23), 4,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
  [62] = 4,
    ACTIONS(29), 1,
      anon_sym_DQUOTE2,
    ACTIONS(31), 1,
      sym__double_quoted_content,
    STATE(5), 2,
      sym_double_quoted_content,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(33), 5,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
      sym_escape_sequence,
  [80] = 4,
    ACTIONS(35), 1,
      anon_sym_DQUOTE2,
    ACTIONS(37), 1,
      sym__double_quoted_content,
    STATE(5), 2,
      sym_double_quoted_content,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(40), 5,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
      sym_escape_sequence,
  [98] = 4,
    ACTIONS(21), 1,
      sym__unquoted_content,
    ACTIONS(43), 2,
      aux_sym__line_token1,
      sym_inline_comment,
    STATE(8), 2,
      sym_unquoted_content,
      aux_sym_unquoted_value_repeat1,
    ACTIONS(45), 4,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
  [116] = 4,
    ACTIONS(31), 1,
      sym__double_quoted_content,
    ACTIONS(47), 1,
      anon_sym_DQUOTE2,
    STATE(4), 2,
      sym_double_quoted_content,
      aux_sym_double_quoted_string_repeat1,
    ACTIONS(49), 5,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
      sym_escape_sequence,
  [134] = 4,
    ACTIONS(53), 1,
      sym__unquoted_content,
    ACTIONS(51), 2,
      aux_sym__line_token1,
      sym_inline_comment,
    STATE(8), 2,
      sym_unquoted_content,
      aux_sym_unquoted_value_repeat1,
    ACTIONS(56), 4,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
  [152] = 6,
    ACTIONS(7), 1,
      anon_sym_POUND,
    ACTIONS(9), 1,
      sym_export_keyword,
    ACTIONS(11), 1,
      sym_key,
    ACTIONS(59), 1,
      ts_builtin_sym_end,
    ACTIONS(61), 1,
      aux_sym__line_token1,
    STATE(10), 3,
      sym_comment,
      sym_pair,
      aux_sym_source_file_repeat1,
  [173] = 6,
    ACTIONS(63), 1,
      ts_builtin_sym_end,
    ACTIONS(65), 1,
      aux_sym__line_token1,
    ACTIONS(68), 1,
      anon_sym_POUND,
    ACTIONS(71), 1,
      sym_export_keyword,
    ACTIONS(74), 1,
      sym_key,
    STATE(10), 3,
      sym_comment,
      sym_pair,
      aux_sym_source_file_repeat1,
  [194] = 1,
    ACTIONS(77), 7,
      sym__double_quoted_content,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
      sym_escape_sequence,
      anon_sym_DQUOTE2,
  [204] = 1,
    ACTIONS(79), 7,
      sym__unquoted_content,
      sym_simple_variable,
      sym_variable_expansion,
      sym_command_substitution,
      sym_backtick_substitution,
      aux_sym__line_token1,
      sym_inline_comment,
  [214] = 2,
    ACTIONS(83), 1,
      sym_key,
    ACTIONS(81), 4,
      ts_builtin_sym_end,
      aux_sym__line_token1,
      anon_sym_POUND,
      sym_export_keyword,
  [224] = 2,
    ACTIONS(87), 1,
      sym_key,
    ACTIONS(85), 4,
      ts_builtin_sym_end,
      aux_sym__line_token1,
      anon_sym_POUND,
      sym_export_keyword,
  [234] = 2,
    ACTIONS(91), 1,
      sym_key,
    ACTIONS(89), 4,
      ts_builtin_sym_end,
      aux_sym__line_token1,
      anon_sym_POUND,
      sym_export_keyword,
  [244] = 2,
    ACTIONS(95), 1,
      sym_key,
    ACTIONS(93), 4,
      ts_builtin_sym_end,
      aux_sym__line_token1,
      anon_sym_POUND,
      sym_export_keyword,
  [254] = 2,
    ACTIONS(99), 1,
      sym_key,
    ACTIONS(97), 4,
      ts_builtin_sym_end,
      aux_sym__line_token1,
      anon_sym_POUND,
      sym_export_keyword,
  [264] = 2,
    ACTIONS(103), 1,
      sym_key,
    ACTIONS(101), 4,
      ts_builtin_sym_end,
      aux_sym__line_token1,
      anon_sym_POUND,
      sym_export_keyword,
  [274] = 3,
    ACTIONS(105), 1,
      anon_sym_SQUOTE2,
    ACTIONS(107), 1,
      sym__single_quoted_content,
    STATE(29), 1,
      sym_single_quoted_content,
  [284] = 2,
    ACTIONS(109), 1,
      aux_sym__line_token1,
    ACTIONS(111), 1,
      sym_comment_content,
  [291] = 1,
    ACTIONS(113), 2,
      aux_sym__line_token1,
      sym_inline_comment,
  [296] = 2,
    ACTIONS(13), 1,
      aux_sym__line_token1,
    ACTIONS(19), 1,
      sym_inline_comment,
  [303] = 2,
    ACTIONS(115), 1,
      aux_sym__line_token1,
    ACTIONS(117), 1,
      sym_inline_comment,
  [310] = 1,
    ACTIONS(119), 2,
      aux_sym__line_token1,
      sym_inline_comment,
  [315] = 1,
    ACTIONS(121), 2,
      aux_sym__line_token1,
      sym_inline_comment,
  [320] = 1,
    ACTIONS(123), 2,
      aux_sym__line_token1,
      sym_inline_comment,
  [325] = 1,
    ACTIONS(125), 1,
      anon_sym_EQ,
  [329] = 1,
    ACTIONS(115), 1,
      aux_sym__line_token1,
  [333] = 1,
    ACTIONS(127), 1,
      anon_sym_SQUOTE2,
  [337] = 1,
    ACTIONS(129), 1,
      anon_sym_SQUOTE2,
  [341] = 1,
    ACTIONS(131), 1,
      sym_key,
  [345] = 1,
    ACTIONS(133), 1,
      aux_sym__line_token1,
  [349] = 1,
    ACTIONS(13), 1,
      aux_sym__line_token1,
  [353] = 1,
    ACTIONS(135), 1,
      aux_sym__line_token1,
  [357] = 1,
    ACTIONS(137), 1,
      ts_builtin_sym_end,
  [361] = 1,
    ACTIONS(139), 1,
      anon_sym_EQ,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 31,
  [SMALL_STATE(4)] = 62,
  [SMALL_STATE(5)] = 80,
  [SMALL_STATE(6)] = 98,
  [SMALL_STATE(7)] = 116,
  [SMALL_STATE(8)] = 134,
  [SMALL_STATE(9)] = 152,
  [SMALL_STATE(10)] = 173,
  [SMALL_STATE(11)] = 194,
  [SMALL_STATE(12)] = 204,
  [SMALL_STATE(13)] = 214,
  [SMALL_STATE(14)] = 224,
  [SMALL_STATE(15)] = 234,
  [SMALL_STATE(16)] = 244,
  [SMALL_STATE(17)] = 254,
  [SMALL_STATE(18)] = 264,
  [SMALL_STATE(19)] = 274,
  [SMALL_STATE(20)] = 284,
  [SMALL_STATE(21)] = 291,
  [SMALL_STATE(22)] = 296,
  [SMALL_STATE(23)] = 303,
  [SMALL_STATE(24)] = 310,
  [SMALL_STATE(25)] = 315,
  [SMALL_STATE(26)] = 320,
  [SMALL_STATE(27)] = 325,
  [SMALL_STATE(28)] = 329,
  [SMALL_STATE(29)] = 333,
  [SMALL_STATE(30)] = 337,
  [SMALL_STATE(31)] = 341,
  [SMALL_STATE(32)] = 345,
  [SMALL_STATE(33)] = 349,
  [SMALL_STATE(34)] = 353,
  [SMALL_STATE(35)] = 357,
  [SMALL_STATE(36)] = 361,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [40] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_double_quoted_string_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquoted_value, 1, 0, 0),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_unquoted_value_repeat1, 2, 0, 0),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_value_repeat1, 2, 0, 0), SHIFT_REPEAT(12),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_unquoted_value_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(10),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_content, 1, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unquoted_content, 1, 0, 0),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 3, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 3, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 3, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pair, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 5, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pair, 5, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 2, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 4, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pair, 4, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 6, 0, 0),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pair, 6, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_string, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 3, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_double_quoted_string, 2, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_single_quoted_content, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [137] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__unquoted_content = 0,
  ts_external_token__single_quoted_content = 1,
  ts_external_token__double_quoted_content = 2,
  ts_external_token_simple_variable = 3,
  ts_external_token_variable_expansion = 4,
  ts_external_token_command_substitution = 5,
  ts_external_token_backtick_substitution = 6,
  ts_external_token_escape_sequence = 7,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__unquoted_content] = sym__unquoted_content,
  [ts_external_token__single_quoted_content] = sym__single_quoted_content,
  [ts_external_token__double_quoted_content] = sym__double_quoted_content,
  [ts_external_token_simple_variable] = sym_simple_variable,
  [ts_external_token_variable_expansion] = sym_variable_expansion,
  [ts_external_token_command_substitution] = sym_command_substitution,
  [ts_external_token_backtick_substitution] = sym_backtick_substitution,
  [ts_external_token_escape_sequence] = sym_escape_sequence,
};

static const bool ts_external_scanner_states[5][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__unquoted_content] = true,
    [ts_external_token__single_quoted_content] = true,
    [ts_external_token__double_quoted_content] = true,
    [ts_external_token_simple_variable] = true,
    [ts_external_token_variable_expansion] = true,
    [ts_external_token_command_substitution] = true,
    [ts_external_token_backtick_substitution] = true,
    [ts_external_token_escape_sequence] = true,
  },
  [2] = {
    [ts_external_token__unquoted_content] = true,
    [ts_external_token_simple_variable] = true,
    [ts_external_token_variable_expansion] = true,
    [ts_external_token_command_substitution] = true,
    [ts_external_token_backtick_substitution] = true,
  },
  [3] = {
    [ts_external_token__double_quoted_content] = true,
    [ts_external_token_simple_variable] = true,
    [ts_external_token_variable_expansion] = true,
    [ts_external_token_command_substitution] = true,
    [ts_external_token_backtick_substitution] = true,
    [ts_external_token_escape_sequence] = true,
  },
  [4] = {
    [ts_external_token__single_quoted_content] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_edf_external_scanner_create(void);
void tree_sitter_edf_external_scanner_destroy(void *);
bool tree_sitter_edf_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_edf_external_scanner_serialize(void *, char *);
void tree_sitter_edf_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_edf(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_edf_external_scanner_create,
      tree_sitter_edf_external_scanner_destroy,
      tree_sitter_edf_external_scanner_scan,
      tree_sitter_edf_external_scanner_serialize,
      tree_sitter_edf_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
