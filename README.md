# tree-sitter-edf

Tree-sitter grammar for EDF (Ecolog Dotenv File Format).

## Overview

This is a tree-sitter parser for `.env` files following the [EDF specification](https://github.com/ph1losof/ecolog-spec). EDF is a strict, unambiguous format for environment configuration files that supports variable interpolation and command substitution.

## Features

- Key-value pairs with optional `export` keyword
- Single-quoted strings (literal, no interpolation or escaping)
- Double-quoted strings with escape sequences (`\n`, `\t`, `\\`, `\"`, `\$`)
- Unquoted values with backslash line continuation
- Shell-style variable interpolation:
  - Simple variables: `$VAR`
  - Braced variables: `${VAR}`
  - Default values: `${VAR:-default}`
- Command substitution: `$(command)` and `` `command` ``
- Comments (line and inline)

## Example

```env
# Database configuration
export DATABASE_URL="postgres://user:pass@localhost:5432/db"

# Literal string (no interpolation)
API_KEY='sk-abc123'

# Variable interpolation
CONFIG_DIR=$HOME/.config
DATA_PATH=${CONFIG_DIR}/data

# Default values
LOG_LEVEL=${LOG_LEVEL:-info}

# Command substitution
HOSTNAME=$(hostname)
CURRENT_USER=`whoami`

# Unquoted values
DEBUG=true
PORT=3000
```

## Installation

### Neovim (nvim-treesitter)

> **Note:** A PR to add EDF to nvim-treesitter is pending: [nvim-treesitter#8412](https://github.com/nvim-treesitter/nvim-treesitter/pull/8412)
>
> Once merged, you can install with `:TSInstall edf`

Until then, add the following to your Neovim configuration:

```lua
local parser_config = require('nvim-treesitter.parsers').get_parser_configs()
parser_config.edf = {
  install_info = {
    url = 'https://github.com/ph1losof/tree-sitter-edf',
    files = { 'src/parser.c', 'src/scanner.c' },
  },
  filetype = 'edf',
}

-- Associate .env files with edf filetype
vim.filetype.add({
  pattern = {
    ['%.env'] = 'edf',
    ['%.env%..*'] = 'edf',
  },
})
```

Then run `:TSInstall edf`

### Rust

```toml
[dependencies]
tree-sitter-edf = "0.1"
```

```rust
use tree_sitter_edf::LANGUAGE;

let mut parser = tree_sitter::Parser::new();
parser.set_language(&LANGUAGE.into()).unwrap();
```

## Development

```bash
# Install dependencies
npm install

# Generate parser
npx tree-sitter generate

# Run tests
npx tree-sitter test

# Interactive playground
npx tree-sitter build --wasm && npx tree-sitter playground
```

## License

MIT
