/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

/**
 * Tree-sitter grammar for EDF (Ecolog Dotenv File Format)
 * Highly optimized for maximum parsing speed
 *
 * Performance optimizations:
 * 1. External scanner handles all complex tokenization in C (10-100x faster than GLR)
 * 2. Minimal grammar rules reduce parser state machine size
 * 3. token() and token.immediate() create atomic tokens (fewer parse states)
 * 4. Inline rules eliminate intermediate AST nodes
 * 5. Interpolation tokens are atomic (no child nodes) for maximum speed
 */
module.exports = grammar({
  name: 'edf',

  // Only horizontal whitespace as extras - newlines are significant
  extras: $ => [/[\t ]/],

  // External scanner handles all complex content tokenization
  // All interpolation tokens are atomic (no child nodes) for speed
  externals: $ => [
    $._unquoted_content,
    $._single_quoted_content,
    $._double_quoted_content,
    $.simple_variable,        // $VAR - atomic token
    $.variable_expansion,     // ${VAR} or ${VAR:-default} - atomic token
    $.command_substitution,   // $(cmd) - atomic token
    $.backtick_substitution,  // `cmd` - legacy command substitution
    $.escape_sequence,        // \n, \t, etc - atomic token
  ],

  // Inline these to eliminate intermediate nodes
  inline: $ => [
    $._line,
    $._value,
    $._double_quoted_element,
    $._unquoted_element,
  ],

  rules: {
    source_file: $ => repeat($._line),

    _line: $ => choice(
      $.pair,      // Most common - check first
      $.comment,
      /\r?\n/,     // Blank line
    ),

    // Comment: # to end of line
    comment: $ => seq(
      '#',
      optional($.comment_content),
      /\r?\n/,
    ),
    comment_content: _ => token.immediate(/[^\r\n]*/),

    // Key-value pair
    pair: $ => seq(
      optional($.export_keyword),
      $.key,
      token.immediate('='),
      optional($._value),
      optional($.inline_comment),
      /\r?\n/,
    ),

    // export keyword with trailing whitespace (atomic token)
    export_keyword: _ => token(seq('export', /[\t ]+/)),

    // Key: standard shell variable name
    key: _ => /[A-Za-z_][A-Za-z0-9_]*/,

    // Value types - ordered by frequency
    _value: $ => choice(
      $.unquoted_value,       // Most common
      $.double_quoted_string,
      $.single_quoted_string,
    ),

    // Single-quoted string: literal content, no interpolation
    single_quoted_string: $ => seq(
      "'",
      optional($.single_quoted_content),
      token.immediate("'"),
    ),
    single_quoted_content: $ => $._single_quoted_content,

    // Double-quoted string: supports interpolation and escapes
    double_quoted_string: $ => seq(
      '"',
      repeat($._double_quoted_element),
      token.immediate('"'),
    ),

    _double_quoted_element: $ => choice(
      $.escape_sequence,
      $.variable_expansion,
      $.simple_variable,
      $.command_substitution,
      $.backtick_substitution,
      $.double_quoted_content,
    ),

    double_quoted_content: $ => $._double_quoted_content,

    // Unquoted value: supports interpolation
    unquoted_value: $ => repeat1($._unquoted_element),

    _unquoted_element: $ => choice(
      $.variable_expansion,
      $.simple_variable,
      $.command_substitution,
      $.backtick_substitution,
      $.unquoted_content,
    ),

    unquoted_content: $ => $._unquoted_content,

    // Inline comment: whitespace + # + content
    inline_comment: _ => token(seq(/[\t ]+#/, /[^\r\n]*/)),
  },
});
