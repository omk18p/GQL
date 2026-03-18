# GQL Query Engine & Execution Pipeline

A complete C++ implementation of a Graph Query Language (GQL) engine, featuring an ANTLR4-based parser, a multi-stage compilation pipeline (AST -> Logical Plan -> Physical Plan), and a high-performance pipelined execution engine.

## 📋 Table of Contents

- [Overview](#overview)
- [Key Features](#key-features)
- [Project Structure](#project-structure)
- [Architecture](#architecture)
- [Build & Usage](#build--usage)
- [Supported GQL Features](#supported-gql-features)
- [Demo & Testing](#demo--testing)

## 🎯 Overview

This project implements a fully functional GQL query engine. It goes beyond simple parsing to provide a complete execution environment where queries are compiled into physical operators that mutate and query an in-memory graph data structure.

### Key Achievements

- **Full CRUD Support**: Complete implementation of `INSERT`, `UPDATE` (SET/REMOVE), and `DELETE` (including DETACH).
- **Pipelined Execution**: High-performance "Open-Next-Close" iterator model allowing streaming data processing.
- **Multi-Stage Planning**: Robust translation from AST to Logical Plan, followed by Physical Plan optimization (e.g., Index vs. Full Scans).
- **Advanced Analytics**: Support for complex joins, aggregations (`COUNT`, `SUM`, `AVG`, etc.), and sorting.

## ✨ Key Features

- **Pipelined DML**: Run complex queries like `INSERT...MATCH...SET...RETURN` in a single execution pipeline.
- **Real-time Property Lookups**: Live graph property resolution ensures that `RETURN` results reflect mutations immediately.
- **Flexible Joins**: Implicit property-based joins across multiple entities (e.g., `WHERE u.id = o.user_id`).
- **Boolean Logic**: Depth-aware expression evaluator supporting nested `AND`/`OR` chains and arithmetic.
- **Optimized Scans**: Automatic selection of Label-based Index Scans for faster node lookup.

## 📁 Project Structure

```
GQL/
├── src/                            # Core engine source code
│   ├── main.cpp                    # Entry point & eCommerce dataset
│   ├── ASTBuilder.h/cpp            # AST construction
│   ├── LogicalPlanBuilder.h/cpp    # Logical plan generation
│   ├── PhysicalPlanner.h/cpp       # Physical plan & Scan optimization
│   ├── PhysicalOperator.h/cpp      # Execution operators (Scans, Joins, DML)
│   └── ExecutionBuilder.h/cpp      # Execution tree construction
├── tests/                          # Categorized test suite
│   ├── simple/                     # Basic MATCH and literal filters
│   ├── medium/                     # Joins, Aggregations, and DML
│   ├── difficult/                  # Complex eCommerce analytics
│   └── demo/                       # Curated walkthrough queries
├── generated/                      # ANTLR4 generated source
└── grammar/                        # GQL .g4 grammar files
```

## 🏗️ Build & Usage

### 1. Build the Engine
```bash
g++ -std=c++17 -I/usr/local/include/antlr4-runtime -Isrc -Igenerated \
    src/*.cpp generated/*.cpp -lantlr4-runtime -L/usr/local/lib -o gqlparser
```

### 2. Run a Demo Query
The engine comes with a pre-loaded eCommerce dataset (Users, Orders, Products, Categories).
```bash
./gqlparser tests/demo/demo5_complex.gql
```

## 🎯 Supported GQL Features

### Pattern Matching & DML
```gql
-- Insert a new user
INSERT (n:Users {name: "Antigravity", age: 100})

-- Match, Update, and Return in one go
MATCH (u:Users) WHERE u.name = "Antigravity"
SET u.age = 101
RETURN u.name, u.age;
```

### Advanced Analytics
```gql
MATCH (u:Users), (o:Orders)
WHERE u.user_id = o.user_id
RETURN u.name, SUM(o.amount) AS total_spent
ORDER BY total_spent DESC;
```

## 🧪 Demo & Testing

We have organized 5 specialized demo queries to showcase the engine's capabilities:
- **Demo 1**: Simple Scan (`tests/demo/demo1_simple.gql`)
- **Demo 2**: Filtered Scan (`tests/demo/demo2_filter.gql`)
- **Demo 3**: Property-based Join (`tests/demo/demo3_join.gql`)
- **Demo 4**: Aggregation & Sorting (`tests/demo/demo4_aggregate.gql`)
- **Demo 5**: Multi-hop Analytical Query (`tests/demo/demo5_complex.gql`)

## 📄 License

This project is part of academic research on Graph Query Language processing and follows the ISO GQL standard specifications.

---
**Developed by Vaibhav Kondekar** | A robust research prototype for GQL Query Processing.

