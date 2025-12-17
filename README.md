# tree-sitter-html

An alternative Tree-sitter grammar for HTML with improved memory efficiency and spec compliance.

## Why use this over [tree-sitter/tree-sitter-html](https://github.com/tree-sitter/tree-sitter-html)?

### Memory-efficient element tracking

The official grammar stores tag names as heap-allocated strings in the element stack. This grammar uses **enums and trie-based hash lookups** instead:

- Known HTML/SVG/MathML elements are stored as single-byte enum values
- More tags can be stored on the stack before the limit defined by `TREE_SITTER_SERIALIZATION_BUFFER_SIZE` is reached

### Implied end tags

This grammar implements HTML's [implied end tag](https://html.spec.whatwg.org/multipage/parsing.html#optional-tags) rules. Elements like `<li>`, `<p>`, `<td>`, etc. are automatically closed when appropriate:

```html
<ul>
  <li>First    <!-- implicitly closed by next <li> -->
  <li>Second   <!-- implicitly closed by </ul> -->
</ul>
```

### Foreign content support

Proper namespace tracking for embedded SVG and MathML content, including nested foreign elements. For example, CDATA is only parsed inside foreign element content.

### Character reference validation

Parses and validates both full (`&amp;`) and legacy short (`&copy`) character references, with distinct nodes for invalid references.
