/**
 * @file Tree-sitter parser for HTML
 * @author Jeffrey Crochet
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "html",

  externals: $ => [
    $._start_tag_name,
    $._start_tag_name_script,
    $._start_tag_name_style,
    $._start_tag_name_void,
    $._end_tag_name,
    $.erroneous_end_tag_name,
    '/>',
    $._implicit_end_tag,
    $.raw_text,
    $.comment,
  ],

  extras: $ => [
    $.comment,
    /\s+/,
  ],

  rules: {
    document: $ => repeat($._node),

    doctype: $ => seq(
      '<!',
      alias($._doctype, 'doctype'),
      /[^>]+/,
      '>'
    ),

    _doctype: _ => /[Dd][Oo][Cc][Tt][Yy][Pp][Ee]/,

    _node: $ => choice(
      $.doctype,
      $.element,
      $.script_element,
      $.style_element,
      $.void_element,
      $.erroneous_end_tag,
      $.text
    ),

    element: $ => choice(
      seq(
        $.start_tag,
        repeat($._node),
        choice($.end_tag, $._implicit_end_tag)
      ),
      $.self_closing_tag
    ),

    script_element: $ => seq(
      alias($.script_start_tag, $.start_tag),
      optional($.raw_text),
      $.end_tag
    ),

    style_element: $ => seq(
      alias($.style_start_tag, $.start_tag),
      optional($.raw_text),
      $.end_tag
    ),

    void_element: $ => alias($.void_start_tag, $.start_tag),

    start_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat($.attribute),
      '>'
    ),

    script_start_tag: $ => seq(
      '<',
      alias($._start_tag_name_script, $.tag_name),
      repeat($.attribute),
      '>'
    ),

    style_start_tag: $ => seq(
      '<',
      alias($._start_tag_name_style, $.tag_name),
      repeat($.attribute),
      '>'
    ),

    void_start_tag: $ => seq(
      '<',
      alias($._start_tag_name_void, $.tag_name),
      repeat($.attribute),
      choice('>', '/>')
    ),

    self_closing_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat($.attribute),
      '/>'
    ),

    end_tag: $ => seq(
      '</',
      alias($._end_tag_name, $.tag_name),
      '>'
    ),

    erroneous_end_tag: $ => seq(
      '</',
      $.erroneous_end_tag_name,
      '>'
    ),

    attribute: $ => seq(
      $.attribute_name,
      optional(seq(
        '=',
        choice(
          $.attribute_value,
          $.quoted_attribute_value
        )
      ))
    ),

    attribute_name: _ => /[^<>"'/=\s]+/,

    attribute_value: _ => /[^<>"'=\s]+/,

    quoted_attribute_value: $ => choice(
      seq("'", optional(alias(/[^']+/, $.attribute_value)), "'"),
      seq('"', optional(alias(/[^"]+/, $.attribute_value)), '"')
    ),

    text: _ => /[^<>]+/,
  }
});
