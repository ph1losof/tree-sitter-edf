package tree_sitter_edf_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-edf"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_edf.Language())
	if language == nil {
		t.Errorf("Error loading Edf grammar")
	}
}
