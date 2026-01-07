//! Tree-sitter grammar for EDF (Ecolog Dotenv File Format)
//!
//! This crate provides a tree-sitter parser for `.env` files following the
//! EDF specification: <https://github.com/ph1losof/ecolog-spec>

use tree_sitter_language::LanguageFn;

extern "C" {
    fn tree_sitter_edf() -> *const ();
}

/// Returns the tree-sitter Language for EDF.
pub const LANGUAGE: LanguageFn = unsafe { LanguageFn::from_raw(tree_sitter_edf) };

/// The syntax highlighting query for EDF.
pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");

/// The content of the [`grammar.js`][] file for this grammar.
///
/// [`grammar.js`]: https://tree-sitter.github.io/tree-sitter/creating-parsers#the-grammar-dsl
pub const GRAMMAR: &str = include_str!("../../grammar.js");

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_can_load_grammar() {
        let mut parser = tree_sitter::Parser::new();
        parser
            .set_language(&LANGUAGE.into())
            .expect("Error loading EDF parser");
    }

    #[test]
    fn test_highlights_query_is_valid() {
        let language: tree_sitter::Language = LANGUAGE.into();
        let query = tree_sitter::Query::new(&language, HIGHLIGHTS_QUERY);
        assert!(query.is_ok(), "Highlights query should be valid: {:?}", query.err());
    }

    #[test]
    fn test_highlights_query_has_captures() {
        let language: tree_sitter::Language = LANGUAGE.into();
        let query = tree_sitter::Query::new(&language, HIGHLIGHTS_QUERY).unwrap();
        assert!(
            query.capture_names().len() > 0,
            "Highlights query should define captures"
        );
    }
}
