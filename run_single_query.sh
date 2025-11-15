#!/bin/bash

# Script to run a single query with the current (reduced) grammar
# Usage: ./run_single_query.sh <query_file>

if [ $# -lt 1 ]; then
    echo "Usage: $0 <query_file>"
    echo "Example: $0 'test queries/Q1.gql'"
    exit 1
fi

QUERY_FILE="$1"

# Check if parser exists
if [ ! -f "./gqlparser" ]; then
    echo "Error: Parser not found. Compiling..."
    g++ -std=c++17 -I/usr/local/include/antlr4-runtime \
        main.cpp ASTNodes.cpp ASTBuilder.cpp ASTPrinter.cpp \
        GQLLexer.cpp GQLParser.cpp GQLBaseVisitor.cpp GQLBaseListener.cpp \
        -lantlr4-runtime -L/usr/local/lib -o gqlparser
    
    if [ $? -ne 0 ]; then
        echo "Compilation failed!"
        exit 1
    fi
fi

# Check if query file exists
if [ ! -f "$QUERY_FILE" ]; then
    echo "Error: Query file not found: $QUERY_FILE"
    exit 1
fi

echo "=========================================="
echo "Running query with REDUCED grammar"
echo "Query file: $QUERY_FILE"
echo "=========================================="
echo ""

./gqlparser "$QUERY_FILE"

