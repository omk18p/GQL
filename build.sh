#!/bin/bash
g++ -O0 -std=c++17 \
  -I/usr/local/include/antlr4-runtime \
  -Isrc -Igenerated \
  src/main.cpp \
  src/ASTNodes.cpp \
  src/ASTBuilder.cpp \
  src/ASTPrinter.cpp \
  src/LogicalPlanNodes.cpp \
  src/LogicalPlanBuilder.cpp \
  src/LogicalPlanPrinter.cpp \
  src/PhysicalPlanner.cpp \
  src/PhysicalOperator.cpp \
  src/ExecutionBuilder.cpp \
  generated/GQLLexer.cpp \
  generated/GQLParser.cpp \
  generated/GQLBaseVisitor.cpp \
  -lantlr4-runtime -L/usr/local/lib \
  -o gqlparser

if [ $? -eq 0 ]; then
  echo "✅ Build successful! Refresh the browser to see updated data."
else
  echo "❌ Build failed. Fix the errors above."
fi
