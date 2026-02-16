//! This crate provides HTML language support for the [tree-sitter] parsing library.
//!
//! Typically, you will use the [`LANGUAGE`] constant to add this language to a
//! tree-sitter [`Parser`], and then use the parser to parse some code:
//!
//! ```
//! let code = r#"
//! "#;
//! let mut parser = tree_sitter::Parser::new();
//! let language = tree_sitter_html::LANGUAGE;
//! parser
//!     .set_language(&language.into())
//!     .expect("Error loading HTML parser");
//! let tree = parser.parse(code, None).unwrap();
//! assert!(!tree.root_node().has_error());
//! ```
//!
//! [`Parser`]: https://docs.rs/tree-sitter/0.25.10/tree_sitter/struct.Parser.html
//! [tree-sitter]: https://tree-sitter.github.io/

use tree_sitter_language::LanguageFn;

extern "C" {
    fn tree_sitter_html() -> *const ();
}

/// The tree-sitter [`LanguageFn`] for this grammar.
pub const LANGUAGE: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_html) };

/// The content of the [`node-types.json`] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers/6-static-node-types
pub const NODE_TYPES: &str = include_str!("../../src/node-types.json");

// NOTE: uncomment these to include any queries that this grammar contains:

// pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");

#[cfg(test)]
mod tests {
    fn parse(source: &str) -> tree_sitter::Tree {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&super::LANGUAGE.into())
            .expect("Error loading HTML parser");
        parser.parse(source, None).expect("Failed to parse source")
    }

    #[test]
    fn test_can_load_grammar() {
        let _ = parse("<div></div>");
    }

    #[test]
    fn test_malformed_implied_end_inputs_terminate() {
        for source in ["<p><div", "<li><li", "<ul><li>text<li"] {
            let tree = parse(source);
            assert!(tree.root_node().has_error(), "expected parse error for {source:?}");
        }
    }

    #[test]
    fn test_erroneous_foreign_end_tag_restores_html_namespace() {
        let tree = parse("<svg></bogus><foo><![CDATA[x]]></foo>");
        let sexp = tree.root_node().to_sexp();
        assert!(
            !sexp.contains("(cdata"),
            "CDATA should not be accepted after leaving SVG namespace: {sexp}"
        );
    }

    #[test]
    fn test_deep_custom_nesting_does_not_crash() {
        let depth = 320;
        let mut source = String::new();
        source.reserve(depth * 7);
        for _ in 0..depth {
            source.push_str("<x>");
        }
        for _ in 0..depth {
            source.push_str("</x>");
        }

        let tree = parse(&source);
        assert!(!tree.root_node().has_error(), "deep nesting should parse cleanly");
    }
}
