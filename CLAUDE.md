# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a Tree-sitter grammar for HTML. Tree-sitter is an incremental parsing library that generates parsers from grammar definitions. This parser aims to produce accurate parse trees for HTML documents.

## Common Commands

### Generate parser from grammar
```bash
tree-sitter generate
```

### Run tests
```bash
tree-sitter test
```

### Run a specific test or tests matching a pattern
```bash
tree-sitter test -f "test name pattern"
```

### Parse a file
```bash
tree-sitter parse path/to/file.html
```

### Build and run playground
```bash
pnpm start
```

### Run Node.js binding tests
```bash
pnpm test
```

### Build C library (static and shared)
```bash
make
```

## Architecture

### Grammar Definition
- `grammar.js` - The main grammar definition that tree-sitter uses to generate the parser
- `src/parser.c` - Generated parser (do not edit directly)
- `src/grammar.json` - Generated grammar metadata

### External Scanner
The parser uses a custom external scanner (`src/scanner.c`) to handle HTML-specific parsing that cannot be expressed in the declarative grammar:
- Tag name classification (void, raw text, escapable raw text, normal elements)
- Namespace tracking (HTML, MathML, SVG)
- Open element stack management
- Text content parsing (including raw text in `<script>`/`<style>`)
- Character reference parsing (both full `&amp;` and short `&#123;` forms)
- CDATA and comment text

### Lookup Tables
`src/tables/` contains generated hash-based lookup tables:
- `html_elements.h` - HTML element classification
- `mathml_elements.h` - MathML element lookup
- `svg_elements.h` - SVG element lookup
- `html_full_character_references.h` - Named character references (e.g., `&amp;`)
- `html_short_character_references.h` - Character references without semicolons

The `.txt` files in `src/tables/` are the source data for generating the `.h` files.

### Query Files
- `queries/highlights.scm` - Syntax highlighting queries
- `queries/injections.scm` - Language injection queries (for embedded JS/CSS)
- `queries/indents.scm` - Indentation queries

### Language Bindings
The `bindings/` directory contains bindings for multiple languages:
- C, Go, Node.js, Python, Rust, Swift

## Key Concepts

### Element Categories
The grammar distinguishes between:
- **Void elements** - Self-closing elements like `<br>`, `<img>`, `<input>`
- **Raw text elements** - `<script>`, `<style>` (content not parsed as HTML)
- **Escapable raw text elements** - `<textarea>`, `<title>` (character references parsed)
- **Normal elements** - All other elements with standard HTML content

### External Tokens
The grammar declares external tokens that the scanner handles:
- `_start_tag_name`, `_void_start_tag_name`, `_raw_text_start_tag_name`, etc.
- `text`, `_raw_text`, `_escapable_raw_text`
- `_full_character_reference`, `_short_character_reference`
- `_cdata_text`, `_comment_text`
