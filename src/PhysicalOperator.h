#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Value.h"
#include "Graph.h"
#include "PhysicalPlan.h"

using namespace std;

// Base Physical Operator
class PhysicalOperator {
public:
    virtual void open() = 0;
    virtual bool next(Row& row) = 0;
    virtual void close() = 0;
    virtual ~PhysicalOperator() = default;
};

// Memory Full Scan
class MemoryFullScan : public PhysicalOperator {
private:
    Graph& graph;
    unique_ptr<PhysicalOperator> child;
    string variable;
    vector<shared_ptr<Node>> nodes;
    size_t currentIndex = 0;

public:
    MemoryFullScan(Graph& g, unique_ptr<PhysicalOperator> c, string v) 
        : graph(g), child(move(c)), variable(v) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Index Scan
class MemoryIndexScan : public PhysicalOperator {
private:
    Graph& graph;
    unique_ptr<PhysicalOperator> child;
    string label;
    string variable;
    vector<shared_ptr<Node>> nodes;
    size_t currentIndex = 0;

public:
    MemoryIndexScan(Graph& g, unique_ptr<PhysicalOperator> c, string l, string v) 
        : graph(g), child(move(c)), label(l), variable(v) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Edge Scan
class MemoryEdgeScan : public PhysicalOperator {
private:
    Graph& graph;
    unique_ptr<PhysicalOperator> child;
    string label;
    string variable;
    vector<shared_ptr<Edge>> edges;
    size_t currentIndex = 0;

public:
    MemoryEdgeScan(Graph& g, unique_ptr<PhysicalOperator> c, string l, string v) 
        : graph(g), child(move(c)), label(l), variable(v) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Filter
class MemoryFilter : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    string condition; // "p.age > 30"

public:
    MemoryFilter(unique_ptr<PhysicalOperator> c, string cond) 
        : child(move(c)), condition(cond) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Project
class MemoryProject : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    vector<string> fields; // "p.name", "p.age"

public:
    MemoryProject(unique_ptr<PhysicalOperator> c, vector<string> f) 
        : child(move(c)), fields(f) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Limit
class MemoryLimit : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    int limit;
    int count = 0;

public:
    MemoryLimit(unique_ptr<PhysicalOperator> c, int l) 
        : child(move(c)), limit(l) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Offset
class MemoryOffset : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    int offset;
    int count = 0;

public:
    MemoryOffset(unique_ptr<PhysicalOperator> c, int o) 
        : child(move(c)), offset(o) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Sort
class MemorySort : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    struct SortItem {
        string field;
        bool ascending;
    };
    vector<SortItem> sortItems;
    vector<Row> sortedRows;
    size_t currentIndex = 0;

public:
    MemorySort(unique_ptr<PhysicalOperator> c, vector<pair<string, bool>> items) 
        : child(move(c)) {
            for (auto& item : items) {
                sortItems.push_back({item.first, item.second});
            }
        }

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Aggregate
class MemoryAggregate : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    vector<string> groupings;
    vector<string> measures;
    
    // To hold the aggregated results before yielding
    vector<Row> aggregatedRows;
    size_t currentIndex = 0;

public:
    MemoryAggregate(unique_ptr<PhysicalOperator> c, vector<string> g, vector<string> m)
        : child(move(c)), groupings(g), measures(m) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Nested Loop Join
class MemoryNestedLoopJoin : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> left;
    unique_ptr<PhysicalOperator> right;
    string condition;
    Row currentLeftRow;
    bool leftFinished = false;
    bool rightOpen = false;

public:
    MemoryNestedLoopJoin(unique_ptr<PhysicalOperator> l, unique_ptr<PhysicalOperator> r, string cond) 
        : left(move(l)), right(move(r)), condition(cond) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Delete
class MemoryDelete : public PhysicalOperator {
private:
    Graph& graph;
    unique_ptr<PhysicalOperator> child;
    vector<string> variables;
    bool detach;
    int deletedCount = 0;
    bool done = false;

public:
    MemoryDelete(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> vars, bool d)
        : graph(g), child(move(c)), variables(vars), detach(d) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Insert
class MemoryInsert : public PhysicalOperator {
private:
    Graph& graph;
    unique_ptr<PhysicalOperator> child;
    vector<PhysicalInsertNode> insertNodes;
    vector<PhysicalInsertEdge> insertEdges;
    int insertedNodesCount = 0;
    int insertedEdgesCount = 0;
    bool done = false;

public:
    MemoryInsert(Graph& g, unique_ptr<PhysicalOperator> c, vector<PhysicalInsertNode> n, vector<PhysicalInsertEdge> e)
        : graph(g), child(move(c)), insertNodes(n), insertEdges(e) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Update
class MemoryUpdate : public PhysicalOperator {
private:
    Graph& graph;
    unique_ptr<PhysicalOperator> child;
    vector<PhysicalUpdateItem> items;
    int updatedCount = 0;
    bool done = false;

public:
    MemoryUpdate(Graph& g, unique_ptr<PhysicalOperator> c, vector<PhysicalUpdateItem> i)
        : graph(g), child(move(c)), items(i) {}

    void open() override;
    bool next(Row& row) override;
    void close() override;
};
