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
    Graph& graph;
    PhysicalOperator(Graph& g) : graph(g) {}
    virtual void open() = 0;
    virtual bool next(Row& row) = 0;
    virtual void close() = 0;
    virtual ~PhysicalOperator() = default;
};

// Memory Full Scan
class MemoryFullScan : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    string variable;
    vector<shared_ptr<Node>> nodes;
    size_t currentIndex = 0;

public:
    MemoryFullScan(Graph& g, unique_ptr<PhysicalOperator> c, string v);

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Label Scan
class MemoryLabelScan : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    string label;
    string variable;
    vector<shared_ptr<Node>> nodes;
    size_t currentIndex = 0;

public:
    MemoryLabelScan(Graph& g, unique_ptr<PhysicalOperator> c, string l, string v);

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Edge Scan
class MemoryEdgeScan : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    string label;
    string variable;
    vector<shared_ptr<Edge>> edges;
    size_t currentIndex = 0;

public:
    MemoryEdgeScan(Graph& g, unique_ptr<PhysicalOperator> c, string l, string v);

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
    MemoryFilter(Graph& g, unique_ptr<PhysicalOperator> c, string cond);

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
    MemoryProject(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> f);

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
    MemoryLimit(Graph& g, unique_ptr<PhysicalOperator> c, int l);

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
    MemoryOffset(Graph& g, unique_ptr<PhysicalOperator> c, int o);

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
    MemorySort(Graph& g, unique_ptr<PhysicalOperator> c, vector<pair<string, bool>> items);

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
    MemoryAggregate(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> g_list, vector<string> m);

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
    MemoryNestedLoopJoin(Graph& g, unique_ptr<PhysicalOperator> l, unique_ptr<PhysicalOperator> r, string cond);

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Delete
class MemoryDelete : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    vector<string> variables;
    bool detach;
    int deletedCount = 0;
    bool done = false;

public:
    MemoryDelete(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> vars, bool d);

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Insert
class MemoryInsert : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    vector<PhysicalInsertNode> insertNodes;
    vector<PhysicalInsertEdge> insertEdges;
    int insertedNodesCount = 0;
    int insertedEdgesCount = 0;
    bool done = false;

public:
    MemoryInsert(Graph& g, unique_ptr<PhysicalOperator> c, vector<PhysicalInsertNode> n, vector<PhysicalInsertEdge> e);

    void open() override;
    bool next(Row& row) override;
    void close() override;
};

// Memory Update
class MemoryUpdate : public PhysicalOperator {
private:
    unique_ptr<PhysicalOperator> child;
    vector<PhysicalUpdateItem> items;
    int updatedCount = 0;
    bool done = false;

public:
    MemoryUpdate(Graph& g, unique_ptr<PhysicalOperator> c, vector<PhysicalUpdateItem> i);

    void open() override;
    bool next(Row& row) override;
    void close() override;
};
