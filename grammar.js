/**
 * @file Tree-sitter parser for HTML
 * @author Jeffrey Crochet
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const WHITESPACE = /[\t\n\f\r ]+/

module.exports = grammar({
  name: 'html',

  externals: $ => [
    $._start_tag_name,
    $._void_start_tag_name,
    $._script_start_tag_name,
    $._style_start_tag_name,
    $._escapable_raw_text_start_tag_name,
    $._end_tag_name,
    $._erroneous_end_tag_name,
    $._self_closing_tag_delimiter,
    // $.implied_end_tag,
    $.text,
    $._raw_text,
    $._escapable_raw_text,
    $._full_character_reference,
    $._short_character_reference,
    $.invalid_character_reference,
    $._cdata_text,
    $._comment_text,
  ],

  extras: _ => [],

  rules: {
    document: $ => optional(seq(
      optional('\uFEFF'),
      optional(seq(optional($._whitespace), $.doctype)),
      repeat1($._content)
    )),

    // This covers all normal element content outside of raw text and escapable raw text elements, which are covered separately below
    _content: $ => choice(
      $._whitespace,
      $.element,
      $.script_element,
      $.style_element,
      $.text,
      $.character_reference,
      $.invalid_character_reference,
      $.cdata,
      $.comment,
      $.erroneous_end_tag
    ),

    _whitespace: _ => WHITESPACE,

    character_reference: $ => choice(
      $._full_character_reference,
      $._short_character_reference,
    ),

    // This covers all elements except `script` and `style`, which need to have their own symbols in the grammar in order to facilitate syntax injection
    element: $ => choice(
      $._void_element,
      $._escapable_raw_text_element,
      // NOTE: In this context, a "normal" element is just any other non-void element. What kind of content a "normal" element is allowed to have is determined by the external scanner.
      $._normal_element,
    ),

    _void_element: $ => alias($._void_start_tag, $.start_tag),
    _void_start_tag: $ => seq(
      '<',
      alias($._void_start_tag_name, $.tag_name),
      repeat(seq($._whitespace, $.attribute)),
      optional($._whitespace),
      choice('>', '/>')
    ),

    _normal_element: $ => choice(
      alias($._self_closing_tag, $.start_tag),
      seq(
        $.start_tag,
        repeat($._content),
        $.end_tag
        // choice($.end_tag, $.implied_end_tag)
      )
    ),

    script_element: $ => seq(
      alias($._script_start_tag, $.start_tag),
      optional($._whitespace),
      alias($._raw_text, $.text),
      optional($._whitespace),
      $.end_tag
    ),
    _script_start_tag: $ => seq(
      '<',
      alias($._script_start_tag_name, $.tag_name),
      repeat(seq($._whitespace, $.attribute)),
      optional($._whitespace),
      '>'
    ),

    style_element: $ => seq(
      alias($._style_start_tag, $.start_tag),
      optional($._whitespace),
      alias($._raw_text, $.text),
      optional($._whitespace),
      $.end_tag
    ),
    _style_start_tag: $ => seq(
      '<',
      alias($._style_start_tag_name, $.tag_name),
      repeat(seq($._whitespace, $.attribute)),
      optional($._whitespace),
      '>'
    ),

    _escapable_raw_text_element: $ => seq(
      alias($._escapable_raw_text_start_tag, $.start_tag),
      optional($._whitespace),
      repeat(choice(
        alias($._escapable_raw_text, $.text),
        $.character_reference,
        $.invalid_character_reference
      )),
      optional($._whitespace),
      $.end_tag
    ),
    _escapable_raw_text_start_tag: $ => seq(
      '<',
      alias($._escapable_raw_text_start_tag_name, $.tag_name),
      repeat(seq($._whitespace, $.attribute)),
      optional($._whitespace),
      '>'
    ),

    start_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat(seq($._whitespace, $.attribute)),
      optional($._whitespace),
      '>'
    ),

    end_tag: $ => seq(
      '</',
      alias($._end_tag_name, $.tag_name),
      optional($._whitespace),
      '>'
    ),

    _self_closing_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat(seq($._whitespace, $.attribute)),
      optional($._whitespace),
      alias($._self_closing_tag_delimiter, '/>')
    ),

    erroneous_end_tag: $ => seq(
      '</',
      alias($._erroneous_end_tag_name, $.tag_name),
      optional($._whitespace),
      '>'
    ),

    cdata: $ => seq(
      '<![CDATA[',
      optional(alias($._cdata_text, $.text)),
      ']]>'
    ),

    comment: $ => seq(
      '<!--',
      optional(alias($._comment_text, $.text)),
      '-->'
    ),

    doctype: $ => seq(
      '<!',
      /DOCTYPE/i,
      $._whitespace,
      /html/i,
      optional($._doctype_legacy_string),
      optional($._whitespace),
      '>'
    ),
    _doctype_legacy_string: _ => token(seq(
      WHITESPACE,
      /SYSTEM/i,
      WHITESPACE,
      choice(
        '"about:legacy-compat"',
        "'about:legacy-compat'"
      )
    )),

    attribute: $ => seq(
      $.attribute_name,
      optional(seq(
        // This rule seems to do a better job at prioritizing whitespace before the `=` than simply making a regular sequence:
        alias(
          token(seq(optional(WHITESPACE), '=', optional(WHITESPACE))),
          '='
        ),
        $.attribute_value,
      ))
    ),
    attribute_name: _ => /[^\u0000-\u001F\u007F-\u009F "'>\/=\uFDD0-\uFDEF\uFFFE\uFFFF\u{1FFFE}\u{1FFFF}\u{2FFFE}\u{2FFFF}\u{3FFFE}\u{3FFFF}\u{4FFFE}\u{4FFFF}\u{5FFFE}\u{5FFFF}\u{6FFFE}\u{6FFFF}\u{7FFFE}\u{7FFFF}\u{8FFFE}\u{8FFFF}\u{9FFFE}\u{9FFFF}\u{AFFFE}\u{AFFFF}\u{BFFFE}\u{BFFFF}\u{CFFFE}\u{CFFFF}\u{DFFFE}\u{DFFFF}\u{EFFFE}\u{EFFFF}\u{FFFFE}\u{FFFFF}\u{10FFFE}\u{10FFFF}]+/u,
    attribute_value: $ => choice(
      // Unquoted
      repeat1(choice(
        /[^\t\n\f\r "'=<>`&]+/,
        alias($._full_character_reference, $.character_reference),
        $.invalid_character_reference,
        /&[^\t\n\f\r "'=<>`&]*/,
      )),
      // Single-quoted
      seq(
        "'",
        repeat(choice(
          /[^'&]+/,
          alias($._full_character_reference, $.character_reference),
          $.invalid_character_reference,
          /&[^&']*/,
        )),
        "'"
      ),
      // Double-quoted
      seq(
        '"',
        repeat(choice(
          /[^"&]+/,
          alias($._full_character_reference, $.character_reference),
          $.invalid_character_reference,
          /&[^&"]*/,
        )),
        '"'
      ),
    ),
  }
})
