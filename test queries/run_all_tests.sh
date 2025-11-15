#!/bin/bash

# GQL Parser Performance Test Script
# This script runs all test queries and collects timing data

OUTPUT_FILE="test_results.csv"
PARSER="./gqlparser"

# Check if parser exists
if [ ! -f "$PARSER" ]; then
    echo "Error: Parser not found at $PARSER"
    echo "Please compile the parser first using:"
    echo "  g++ -std=c++17 -I/usr/local/include/antlr4-runtime \\"
    echo "      main.cpp ASTNodes.cpp ASTBuilder.cpp ASTPrinter.cpp \\"
    echo "      GQLLexer.cpp GQLParser.cpp GQLBaseVisitor.cpp GQLBaseListener.cpp \\"
    echo "      -lantlr4-runtime -L/usr/local/lib -o gqlparser"
    exit 1
fi

# Create results file with header
echo "Query Number,Query File,Parse Time (ms),AST Time (ms),Total Time (ms),Status" > "$OUTPUT_FILE"

# Counter for queries
query_count=0

# Function to extract timing from parser output
extract_timing() {
    local output="$1"
    local parse_time=$(echo "$output" | grep -oP 'Lexing \+ Parsing Time: \K\d+')
    local ast_time=$(echo "$output" | grep -oP 'AST Construction Time: \K\d+')
    local total_time=$(echo "$output" | grep -oP 'Total Execution Time: \K\d+')
    
    # Default to 0 if not found
    parse_time=${parse_time:-0}
    ast_time=${ast_time:-0}
    total_time=${total_time:-0}
    
    echo "$parse_time,$ast_time,$total_time"
}

# Test queries from Q1 to Q105
for i in {1..105}; do
    query_file="Q${i}.gql"
    
    if [ -f "$query_file" ]; then
        query_count=$((query_count + 1))
        echo "Testing $query_file ($query_count/105)..."
        
        # Run parser and capture output
        output=$($PARSER "$query_file" 2>&1)
        exit_code=$?
        
        if [ $exit_code -eq 0 ]; then
            timing=$(extract_timing "$output")
            echo "$i,$query_file,$timing,SUCCESS" >> "$OUTPUT_FILE"
            echo "  ✓ Success"
        else
            echo "$i,$query_file,0,0,0,FAILED" >> "$OUTPUT_FILE"
            echo "  ✗ Failed (exit code: $exit_code)"
        fi
    else
        echo "Warning: $query_file not found, skipping..."
    fi
done

echo ""
echo "=========================================="
echo "Test Summary"
echo "=========================================="
echo "Total queries tested: $query_count"
echo "Results saved to: $OUTPUT_FILE"
echo ""
echo "Generating summary statistics..."

# Generate summary if we have results
if [ -f "$OUTPUT_FILE" ] && [ $query_count -gt 0 ]; then
    # Calculate averages (skip header line)
    awk -F',' 'NR>1 && $6=="SUCCESS" {
        parse_sum+=$3
        ast_sum+=$4
        total_sum+=$5
        success_count++
    }
    END {
        if (success_count > 0) {
            printf "Average Parse Time: %.2f ms\n", parse_sum/success_count
            printf "Average AST Time: %.2f ms\n", ast_sum/success_count
            printf "Average Total Time: %.2f ms\n", total_sum/success_count
            printf "Successful queries: %d\n", success_count
        }
    }' "$OUTPUT_FILE"
fi

echo ""
echo "Done! Check $OUTPUT_FILE for detailed results."

