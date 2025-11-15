# GQL Parser Test Suite

## Overview
This directory contains 105 comprehensive test queries for the GQL parser, organized by complexity:
- **Small Queries**: Q1-Q20 (20 queries)
- **Medium Queries**: Q21-Q50 (30 queries)
- **Complex Queries**: Q51-Q80 (30 queries)
- **Very Complex Queries**: Q81-Q105 (25 queries)

## Files

- `TEST_REPORT.md` - Complete test report with all 105 queries documented
- `Q1.gql` through `Q105.gql` - Individual query files for each test
- `run_all_tests.sh` - Automated test runner script
- `generate_all_queries.py` - Script to regenerate query files from report

## Quick Start

### 1. Run a Single Query
```bash
# From the project root directory
./gqlparser "test queries/Q1.gql"
```

### 2. Run All Tests Automatically
```bash
# From the test queries directory
cd "test queries"
./run_all_tests.sh
```

This will:
- Run all 105 queries
- Collect timing data for each query
- Generate `test_results.csv` with performance metrics
- Display summary statistics

### 3. View Results
After running the test suite, check `test_results.csv`:
```bash
cat test_results.csv
```

The CSV contains:
- Query Number
- Query File
- Parse Time (ms)
- AST Construction Time (ms)
- Total Execution Time (ms)
- Status (SUCCESS/FAILED)

## Query Categories

### Small Queries (Q1-Q20)
Basic operations:
- Simple MATCH statements
- Basic CREATE/DELETE
- Simple aggregations
- Basic WHERE clauses

### Medium Queries (Q21-Q50)
Intermediate complexity:
- Multi-hop relationships
- Complex WHERE conditions
- Multiple operations
- OPTIONAL MATCH
- LET statements
- FILTER clauses

### Complex Queries (Q51-Q80)
Advanced features:
- Deep path patterns
- Multiple aggregations
- Complex ORDER BY
- UNION queries
- SELECT statements
- Complex transactions

### Very Complex Queries (Q81-Q105)
Maximum complexity:
- Multi-pattern queries
- Nested aggregations
- Complex LET with CASE
- Multiple OPTIONAL MATCH
- Complex transactions
- All features combined

## Performance Analysis

After running all tests, you can analyze:

1. **Average parse time by complexity**
2. **AST construction overhead**
3. **Query type performance**
4. **Complexity impact on parsing**

## Regenerating Query Files

If you modify `TEST_REPORT.md`, regenerate all query files:
```bash
python3 generate_all_queries.py
```

## Notes

- All queries follow ISO/IEC 39075:2024 GQL standard
- Queries are syntactically valid but may require graph data for execution
- Timing focuses on parsing and AST construction phases
- Some very complex queries may take longer to parse

## Troubleshooting

### Parser not found
If `run_all_tests.sh` fails with "Parser not found":
1. Ensure you're in the project root
2. Compile the parser: `g++ -std=c++17 ...` (see `cmd.txt`)
3. Ensure `gqlparser` is in the project root

### Permission denied
Make scripts executable:
```bash
chmod +x run_all_tests.sh generate_all_queries.py
```

### Missing query files
Regenerate all queries:
```bash
python3 generate_all_queries.py
```

