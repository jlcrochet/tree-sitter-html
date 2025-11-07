/**
 * @file Tree-sitter parser for HTML
 * @author Jeffrey Crochet
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const WHITESPACE = /[\t\n\f\r ]+/

const G = {
  name: 'html',

  externals: $ => [
    $._start_tag_name,
    $._void_start_tag_name,
    $._script_start_tag_name,
    $._style_start_tag_name,
    $._escapable_raw_text_start_tag_name,
    $._foreign_start_tag_name,
    $._end_tag_name,
    $.erroneous_end_tag_name,
    $._self_closing_tag_delimiter,
    // $.text,
    $.character_reference,
    $.ambiguous_ampersand,
    $._cdata_text,
    $._comment_text,
  ],

  extras: _ => [],

  rules: {
    document: $ => optional(seq(
      optional('\uFEFF'),
      optional(seq(optional(WHITESPACE), $.doctype)),
      repeat1(choice(
        WHITESPACE,
        $.element,
        $.script_element,
        $.style_element,
        // $.text,
        $.character_reference,
        $.ambiguous_ampersand,
        $.comment,
        $.erroneous_end_tag
      ))
    )),

    // This covers all elements except `script` and `style`, which need to have their own symbols in the grammar in order to facilitate syntax injection
    element: $ => choice(
      $._void_element,
      $._escapable_raw_text_element,
      $._foreign_element,
      $._normal_element
    ),

    _void_element: $ => alias($._void_start_tag, $.start_tag),
    _void_start_tag: $ => seq(
      '<',
      alias($._void_start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      choice('>', '/>')
    ),

    script_element: $ => seq(
      alias($._script_start_tag, $.start_tag),
      repeat(choice(
        WHITESPACE,
        // $.text
      )),
      $.end_tag
    ),
    _script_start_tag: $ => seq(
      '<',
      alias($._script_start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      '>'
    ),

    style_element: $ => seq(
      alias($._style_start_tag, $.start_tag),
      repeat(choice(
        WHITESPACE,
        // $.text
      )),
      $.end_tag
    ),
    _style_start_tag: $ => seq(
      '<',
      alias($._style_start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      '>'
    ),

    _escapable_raw_text_element: $ => seq(
      alias($._escapable_raw_text_start_tag, $.start_tag),
      repeat(choice(
        WHITESPACE,
        // $.text,
        $.character_reference,
        $.ambiguous_ampersand,
      )),
      $.end_tag
    ),
    _escapable_raw_text_start_tag: $ => seq(
      '<',
      alias($._escapable_raw_text_start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      '>'
    ),

    _foreign_element: $ => choice(
      seq(
        alias($._foreign_start_tag, $.start_tag),
        repeat(choice(
          WHITESPACE,
          // $.text,
          $.character_reference,
          $.ambiguous_ampersand,
          $.cdata,
          alias($._foreign_element, $.element),
          $.comment,
          $.erroneous_end_tag
        )),
        $.end_tag
      ),
      alias($._self_closing_foreign_start_tag, $.start_tag),
    ),
    _foreign_start_tag: $ => seq(
      '<',
      alias($._foreign_start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      '>'
    ),
    _self_closing_foreign_start_tag: $ => seq(
      '<',
      alias($._foreign_start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      alias($._self_closing_tag_delimiter, '/>')
    ),

    _normal_element: $ => seq(
      $.start_tag,
      repeat(choice(
        WHITESPACE,
        // $.text,
        $.character_reference,
        $.ambiguous_ampersand,
        $.element,
        $.script_element,
        $.style_element,
        $.comment,
        $.erroneous_end_tag
      )),
      $.end_tag
    ),

    start_tag: $ => seq(
      '<',
      alias($._start_tag_name, $.tag_name),
      repeat(seq(WHITESPACE, $.attribute)),
      optional(WHITESPACE),
      '>'
    ),

    end_tag: $ => seq(
      '</',
      alias($._end_tag_name, $.tag_name),
      optional(WHITESPACE),
      '>'
    ),

    erroneous_end_tag: $ => seq(
      '</',
      $.erroneous_end_tag_name,
      optional(WHITESPACE),
      '>'
    ),

    cdata: $ => seq(
      '<![CDATA[',
      alias($._cdata_text, $.text),
      ']]>'
    ),

    comment: $ => seq(
      '<!--',
      alias($._comment_text, $.text),
      '-->'
    ),

    doctype: $ => seq(
      '<!',
      /DOCTYPE/i,
      WHITESPACE,
      /html/i,
      optional($._doctype_legacy_string),
      optional(WHITESPACE),
      '>'
    ),
    _doctype_legacy_string: $ => token(seq(
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
        // optional(WHITESPACE),
        '=',
        // optional(WHITESPACE),
        $.attribute_value,
      ))
    ),
    attribute_name: _ => /[^\u0000-\u001F\u007F-\u009F "'>\/=\uFDD0-\uFDEF\uFFFE\uFFFF\u{1FFFE}\u{1FFFF}\u{2FFFE}\u{2FFFF}\u{3FFFE}\u{3FFFF}\u{4FFFE}\u{4FFFF}\u{5FFFE}\u{5FFFF}\u{6FFFE}\u{6FFFF}\u{7FFFE}\u{7FFFF}\u{8FFFE}\u{8FFFF}\u{9FFFE}\u{9FFFF}\u{AFFFE}\u{AFFFF}\u{BFFFE}\u{BFFFF}\u{CFFFE}\u{CFFFF}\u{DFFFE}\u{DFFFF}\u{EFFFE}\u{EFFFF}\u{FFFFE}\u{FFFFF}\u{10FFFE}\u{10FFFF}]+/u,
    attribute_value: $ => choice(
      // Unquoted
      repeat1(choice(
        /[^\t\n\f\r "'=<>`&]+/,
        $.character_reference,
        $.ambiguous_ampersand,
        '&',
      )),
      // Single-quoted
      seq(
        "'",
        /[^'&]+/,
        $.character_reference,
        $.ambiguous_ampersand,
        '&',
        "'"
      ),
      // Double-quoted
      seq(
        '"',
        /[^"&]+/,
        $.character_reference,
        $.ambiguous_ampersand,
        '&',
        '"'
      ),
    ),
  }
}

module.exports = grammar(G)
