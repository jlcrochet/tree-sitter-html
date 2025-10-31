# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a Tree-sitter parser for HTML that uses an external scanner with an optimized tag stack implementation. The parser handles HTML's context-sensitive nature (matching opening/closing tags) efficiently using enum-based lookups and xxHash for foreign elements.

## Essential Commands

### Development
```bash
# Generate parser from grammar
tree-sitter generate

# Parse a file (for testing)
tree-sitter parse <file.html>

# Parse with debug output
tree-sitter parse <file.html> --debug

# Run tree-sitter tests
tree-sitter test
# Or via Makefile
make test

# Run Node.js tests
npm test
```

### Building
```bash
# Build static and shared libraries
make

# Build WASM version
npm run prestart

# Clean build artifacts
make clean
```

### Interactive Testing
```bash
# Launch tree-sitter playground
npm start
```

## Architecture

### Grammar Definition (`grammar.js`)
- Defines the HTML document structure with external scanner integration
- External tokens: tag names, end tags, self-closing delimiters, raw text, comments
- Special handling for `<script>` and `<style>` elements that contain raw text

### External Scanner (`src/scanner.c`)

The external scanner is the heart of this parser and handles context-sensitive parsing:

**Tag Stack System:**
- Uses `enum Element` values (not strings) for known HTML elements
- Tag stack: `Array(enum Element)` stores opened tags
- Hash stack: `Array(XXH64_hash_t)` stores hashes for foreign/unknown elements
- Void elements (img, br, meta, etc.) are never pushed to the stack

**Lookup Table (`src/tables/html_elements.h`):**
- Generated using `triehash` from `src/tables/html_elements.txt`
- Provides O(1) case-insensitive tag name → enum Element lookup
- Returns `E_Unknown` for foreign/custom elements

**Foreign Element Handling:**
- Unknown elements use xxHash64 for efficient comparison without string storage
- xxHash submodule: `src/xxHash/` (included via git submodule)
- Hashes are computed once during tag name scanning and stored in parallel hash stack

**Key Functions:**
- `scan_tag_name()`: Scans tag name, returns Element enum + hash for unknowns
- `scan_raw_text()`: Handles raw text content for script/style elements
- `scan_comment()`: Handles HTML comments
- Tag matching uses stack comparison (enum-to-enum or hash-to-hash)

### State Serialization

The scanner serializes its state for incremental parsing:
- Format: `[tag_count][elem1][hash1?][elem2][hash2?]...`
- Each Element is 1 byte
- Unknown elements followed by 8-byte XXH64 hash
- Limited to 255 tags on stack (buffer size constraints)

## Important Implementation Details

### Void Elements
These elements never get pushed to the tag stack as they're self-closing:
```c
area, base, br, col, embed, hr, img, input, link, meta, param, source, track, wbr
```

### Implicit End Tags
Currently disabled (returns early without closing tags automatically). HTML5 has complex rules for when tags implicitly close (e.g., `<p>` closes when `<div>` starts). This is marked as TODO in the scanner.

### External Symbol Order
The enum order in `src/scanner.c` must match the externals array order in `grammar.js`:
```
0: START_TAG_NAME
1: START_TAG_NAME_SCRIPT
2: START_TAG_NAME_STYLE
3: END_TAG_NAME
4: ERRONEOUS_END_TAG_NAME
5: SELF_CLOSING_TAG_DELIMITER
6: IMPLICIT_END_TAG
7: RAW_TEXT
8: COMMENT
```

## Regenerating the Lookup Table

If you modify `src/tables/html_elements.txt`, regenerate the lookup header:

```bash
triehash --ignore-case --enum-name=Element \
  --function-name=lookup_element --label-prefix=E_ \
  src/tables/html_elements.txt > src/tables/html_elements.h
```

The format of `html_elements.txt`:
- First line: `= 0` (sets E_Unknown = 0)
- Following lines: one HTML element name per line

## Git Submodule

The xxHash library is included as a git submodule at `src/xxHash/`. After cloning:

```bash
git submodule update --init --recursive
```

## Multi-Language Bindings

The parser supports multiple language bindings (configured in `tree-sitter.json`):
- C (via tree-sitter API)
- Node.js (node-gyp)
- Python
- Rust
- Go
- Swift

Build artifacts are generated in `bindings/` directory.
