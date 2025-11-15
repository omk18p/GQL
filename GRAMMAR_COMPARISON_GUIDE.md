# Grammar Comparison Guide

This guide explains how to run queries with both the **previous (original)** and **reduced (compressed)** grammars for performance comparison.

## Current Setup

- **Current Grammar**: `GQL.g4` (Reduced/Compressed version - ~280 rules)
- **Previous Grammar**: Not present (you need to provide it)

## Quick Start

### 1. Run a Single Query with Current (Reduced) Grammar

```bash
./run_single_query.sh "test queries/Q1.gql"
```

This uses the current reduced grammar (`GQL.g4`).

### 2. Run a Single Query with Previous Grammar

First, you need to have your previous grammar file. Name it one of:
- `GQL_original.g4`
- `GQL_previous.g4`

Then run:
```bash
./run_with_previous_grammar.sh "test queries/Q1.gql"
```

### 3. Compare Both Grammars Side-by-Side

```bash
./compare_grammars.sh "test queries/Q1.gql"
```

This will:
- Run the query with previous grammar
- Run the query with reduced grammar
- Show a comparison table with timing metrics
- Calculate performance improvement percentage

## Setting Up Previous Grammar

If you have a backup or previous version of your grammar:

1. **Copy your previous grammar file** to the project root:
   ```bash
   cp /path/to/previous/grammar.g4 GQL_original.g4
   ```
   OR
   ```bash
   cp /path/to/previous/grammar.g4 GQL_previous.g4
   ```

2. **Verify the file exists**:
   ```bash
   ls -la GQL_original.g4  # or GQL_previous.g4
   ```

3. **Run comparison**:
   ```bash
   ./compare_grammars.sh "test queries/Q1.gql"
   ```

## Scripts Overview

### `run_single_query.sh`
- Runs a query with the **current reduced grammar**
- Automatically compiles if needed
- Shows parse tree, AST, and timing

### `run_with_previous_grammar.sh`
- Runs a query with the **previous grammar**
- Temporarily switches to previous grammar
- Restores current grammar after execution
- Creates `gqlparser_previous` executable

### `compare_grammars.sh`
- Compares both grammars on the same query
- Shows side-by-side timing comparison
- Calculates performance improvement
- Automatically handles grammar switching

## Example Output

When running `compare_grammars.sh`:

```
==========================================
Grammar Comparison Test
Query: test queries/Q1.gql
==========================================

1. Testing with PREVIOUS grammar...
-----------------------------------
Running query with previous grammar...
  Parse Time: 18 ms
  AST Time: 0 ms
  Total Time: 18 ms

2. Testing with REDUCED grammar...
-----------------------------------
Running query with reduced grammar...
  Parse Time: 16 ms
  AST Time: 0 ms
  Total Time: 16 ms

==========================================
Comparison Summary
==========================================
Metric               Previous      Reduced
----------------------------------------
Parse Time (ms)             18           16
AST Time (ms)               0            0
Total Time (ms)             18           16

Performance Improvement: 11.11%
```

## Testing Multiple Queries

To test multiple queries and compare:

```bash
# Test a simple query
./compare_grammars.sh "test queries/Q1.gql"

# Test a medium complexity query
./compare_grammars.sh "test queries/Q25.gql"

# Test a complex query
./compare_grammars.sh "test queries/Q75.gql"

# Test a very complex query
./compare_grammars.sh "test queries/Q100.gql"
```

## Notes

1. **Grammar Switching**: The scripts automatically handle switching between grammars and restore the current one after testing.

2. **Compilation**: Both parsers are compiled automatically. The previous grammar parser is named `gqlparser_previous` and is cleaned up after comparison.

3. **Backup**: Current generated files are backed up before switching to previous grammar and restored afterward.

4. **Timing**: Results show:
   - Lexing + Parsing Time
   - AST Construction Time
   - Total Execution Time

5. **Performance Metrics**: The comparison script calculates the percentage improvement when both grammars produce valid numeric results.

## Troubleshooting

### Previous Grammar Not Found
If you see "Previous grammar file not found":
- Ensure your previous grammar is named `GQL_original.g4` or `GQL_previous.g4`
- Check it's in the project root directory

### Compilation Errors
If compilation fails:
- Check ANTLR4 is installed: `antlr4 --version`
- Verify ANTLR4 runtime is in `/usr/local/lib`
- Check C++17 compiler is available: `g++ --version`

### Permission Denied
Make scripts executable:
```bash
chmod +x run_single_query.sh run_with_previous_grammar.sh compare_grammars.sh
```

## Expected Results

Based on the grammar compression:
- **Reduced grammar**: ~280 rules (~30% reduction)
- **Previous grammar**: ~400 rules (if original)

The reduced grammar should show:
- Similar or better parsing performance
- Same language recognition
- Potentially faster parse times due to reduced rule complexity

