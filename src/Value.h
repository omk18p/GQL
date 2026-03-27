#pragma once
#include <string>
#include <variant>
#include <unordered_map>
#include <iostream>

using namespace std;

// Forward declarations
struct Node;
struct Edge;

// specialized implementation of variant for Value
using ValueType = variant<monostate, int, double, string, bool, Node*, Edge*>;

struct Value {
    ValueType data;

    Value() : data(monostate{}) {}
    Value(int v) : data(v) {}
    Value(double v) : data(v) {}
    Value(string v) : data(v) {}
    Value(const char* v) : data(string(v)) {}
    Value(bool v) : data(v) {}
    Value(Node* v);
    Value(Edge* v);

    string toString() const;
    double toDouble() const;
    bool toBool() const;
    bool isNumber() const;
    
    // Comparison helpers
    bool operator>(const Value& other) const;
    bool operator<(const Value& other) const;
    bool operator==(const Value& other) const;
};

bool compareValues(const Value& a, const Value& b);

struct Row {
    unordered_map<string, Value> values; // key: "variable.property" or just "variable" for node objects? 
};
