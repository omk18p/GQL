#include "PhysicalOperator.h"
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// --- Helper Functions ---

// Simple parser for "variable.property"
pair<string, string> parseVarProp(const string& s) {
    size_t dotPos = s.find('.');
    if (dotPos == string::npos) return {s, ""}; // Just variable
    return {s.substr(0, dotPos), s.substr(dotPos + 1)};
}

// Evaluate expression on a Row
// Supports: "p.age", "30", "p.age > 30"
Value evaluate(const Row& row, const string& expr, Graph& graph) {
    auto trim = [](string s) {
        if (s.empty()) return s;
        size_t start = s.find_first_not_of(" \t\n\r");
        if (start == string::npos) return string("");
        size_t end = s.find_last_not_of(" \t\n\r");
        string t = s.substr(start, end - start + 1);
        
        while (t.size() >= 2 && t.front() == '(' && t.back() == ')') {
            int depth = 0;
            bool matching = true;
            for (size_t i = 0; i < t.size() - 1; ++i) {
                if (t[i] == '(') depth++;
                else if (t[i] == ')') depth--;
                if (depth == 0) { matching = false; break; }
            }
            if (matching) {
                t = t.substr(1, t.size() - 2);
                start = t.find_first_not_of(" \t\n\r");
                if (start == string::npos) return string("");
                end = t.find_last_not_of(" \t\n\r");
                t = t.substr(start, end - start + 1);
            } else break;
        }
        return t;
    };

    string tExpr = trim(expr);
    if (tExpr.empty()) return Value(false);

    auto findWordDepth = [&row, &graph](const string& s, const string& word) -> size_t {
        int depth = 0;
        string upperS = s; for(auto &c : upperS) c = toupper(c);
        string upperW = word; for(auto &c : upperW) c = toupper(c);

        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') depth++;
            else if (s[i] == ')') depth--;
            else if (depth == 0) {
                if (upperS.size() >= i + upperW.size() && upperS.substr(i, upperW.length()) == upperW) {
                    auto isBoundary = [](char c) { return !isalnum(c) && c != '_'; };
                    bool leftOk = (i == 0 || isBoundary(s[i-1]));
                    bool rightOk = (i + upperW.length() == s.length() || isBoundary(s[i+upperW.length()]));
                    if (leftOk && rightOk) return i;
                }
            }
        }
        return string::npos;
    };

    size_t orPos = findWordDepth(tExpr, "OR");
    if (orPos != string::npos) {
        return Value(evaluate(row, tExpr.substr(0, orPos), graph).toBool() || evaluate(row, tExpr.substr(orPos + 2), graph).toBool());
    }

    size_t andPos = findWordDepth(tExpr, "AND");
    if (andPos != string::npos) {
        return Value(evaluate(row, tExpr.substr(0, andPos), graph).toBool() && evaluate(row, tExpr.substr(andPos + 3), graph).toBool());
    }

    auto findOpDepth = [](const string& s, const string& op) -> size_t {
        int depth = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') depth++;
            else if (s[i] == ')') depth--;
            else if (depth == 0) {
                if (s.size() >= i + op.size() && s.substr(i, op.length()) == op) return i;
            }
        }
        return string::npos;
    };

    string ops[] = {">=", "<=", "<>", "=", ">", "<"};
    for (const string& op : ops) {
        size_t pos = findOpDepth(tExpr, op);
        if (pos != string::npos) {
            Value lv = evaluate(row, tExpr.substr(0, pos), graph);
            Value rv = evaluate(row, tExpr.substr(pos + op.length()), graph);
            if (op == "=") return Value(lv.toString() == rv.toString());
            if (op == ">") return Value(lv.toDouble() > rv.toDouble());
            if (op == "<") return Value(lv.toDouble() < rv.toDouble());
            if (op == ">=") return Value(lv.toDouble() >= rv.toDouble());
            if (op == "<=") return Value(lv.toDouble() <= rv.toDouble());
            if (op == "<>") return Value(lv.toString() != rv.toString());
        }
    }

    if (tExpr.find('.') != string::npos) {
        size_t dotPos = tExpr.find('.');
        string var = tExpr.substr(0, dotPos);
        string prop = tExpr.substr(dotPos + 1);
        string fullKey = var + "." + prop;
        
        // 1. Try context row first (for aliases/aggregates)
        if (row.values.count(fullKey)) return row.values.at(fullKey);
        
        // 2. Try looking up in the graph via node/edge ID in the row
        if (row.values.count(var)) {
            Value varVal = row.values.at(var);
            if (holds_alternative<Node*>(varVal.data)) {
                Node* node = get<Node*>(varVal.data);
                if (node->properties.count(prop)) return node->properties.at(prop);
            } else if (holds_alternative<Edge*>(varVal.data)) {
                Edge* edge = get<Edge*>(varVal.data);
                if (edge->properties.count(prop)) return edge->properties.at(prop);
            } else if (holds_alternative<int>(varVal.data)) {
                int id = get<int>(varVal.data);
                if (graph.nodes.count(id)) {
                    auto node = graph.nodes.at(id);
                    if (node->properties.count(prop)) return node->properties.at(prop);
                } else if (graph.edges.count(id)) {
                    auto edge = graph.edges.at(id);
                    if (edge->properties.count(prop)) return edge->properties.at(prop);
                }
            }
            return varVal; // Fallback to ID if property not found
        }
    } else {
        // Standalone variable lookup
        if (row.values.count(tExpr)) return row.values.at(tExpr);
    }
    
    // String literals: 'string' or "string"
    if (tExpr.size() >= 2 && 
        ((tExpr.front() == '\'' && tExpr.back() == '\'') || 
         (tExpr.front() == '"' && tExpr.back() == '"'))) {
        return Value(tExpr.substr(1, tExpr.size() - 2));
    }
    
    try {
        if (tExpr.find_first_not_of("0123456789.-") == string::npos && tExpr != "." && tExpr != "-") {
            return Value(stod(tExpr));
        }
    } catch (...) {}

    return Value(tExpr);
}


// --- MemoryFullScan ---

MemoryFullScan::MemoryFullScan(Graph& g, unique_ptr<PhysicalOperator> c, string v) 
    : PhysicalOperator(g), child(move(c)), variable(v) {}

void MemoryFullScan::open() {
    if (child) {
        child->open();
        Row dummy;
        while(child->next(dummy)) {}
        child->close();
    }
    nodes = graph.getAllNodes();
    currentIndex = 0;
}

bool MemoryFullScan::next(Row& row) {
    if (currentIndex >= nodes.size()) return false;
    
    auto node = nodes[currentIndex];
    currentIndex++;
    
    row.values[variable] = Value(node.get()); 
    row.values[variable + ".id"] = Value(node->id); 
    
    for (auto& prop : node->properties) {
        row.values[variable + "." + prop.first] = prop.second;
    }
    
    return true;
}

void MemoryFullScan::close() {
    nodes.clear();
}


// --- MemoryLabelScan ---

MemoryLabelScan::MemoryLabelScan(Graph& g, unique_ptr<PhysicalOperator> c, string l, string v) 
    : PhysicalOperator(g), child(move(c)), label(l), variable(v) {}

void MemoryLabelScan::open() {
    if (child) {
        child->open();
        Row dummy;
        while(child->next(dummy)) {}
        child->close();
    }
    nodes = graph.getNodesByLabel(label);
    currentIndex = 0;
}

bool MemoryLabelScan::next(Row& row) {
    if (currentIndex >= nodes.size()) return false;
    
    // Load current node into row
    auto node = nodes[currentIndex];
    currentIndex++;
    
    // Populate row with node properties flattened
    // AND the node reference itself (simulated by ID + all props)
    
    // 1. Variable itself and .id
    row.values[variable] = Value(node.get()); 
    row.values[variable + ".id"] = Value(node->id); 
    
    // 2. Properties
    for (auto& prop : node->properties) {
        row.values[variable + "." + prop.first] = prop.second;
    }
    
    return true;
}

void MemoryLabelScan::close() {
    nodes.clear();
}


// --- MemoryEdgeScan ---

MemoryEdgeScan::MemoryEdgeScan(Graph& g, unique_ptr<PhysicalOperator> c, string l, string v) 
    : PhysicalOperator(g), child(move(c)), label(l), variable(v) {}

void MemoryEdgeScan::open() {
    if (child) {
        child->open();
        Row dummy;
        while(child->next(dummy)) {}
        child->close();
    }
    if (label.empty()) {
        edges = graph.getAllEdges();
    } else {
        edges = graph.getEdgesByLabel(label);
    }
    currentIndex = 0;
}

bool MemoryEdgeScan::next(Row& row) {
    if (currentIndex >= edges.size()) return false;
    
    auto edge = edges[currentIndex];
    currentIndex++;
    
    // Populate row with edge properties
    row.values[variable] = Value(edge.get());
    row.values[variable + ".id"] = Value(edge->id);
    row.values[variable + "._source"] = Value(edge->sourceId);
    row.values[variable + "._target"] = Value(edge->targetId);
    
    // Support non-underscored for join conditions if needed
    row.values[variable + ".source"] = Value(edge->sourceId);
    row.values[variable + ".target"] = Value(edge->targetId);
    
    for (auto& prop : edge->properties) {
        row.values[variable + "." + prop.first] = prop.second;
    }
    
    return true;
}

void MemoryEdgeScan::close() {
    edges.clear();
}


// --- MemoryFilter ---

MemoryFilter::MemoryFilter(Graph& g, unique_ptr<PhysicalOperator> c, string cond) 
    : PhysicalOperator(g), child(move(c)), condition(cond) {}

void MemoryFilter::open() {
    child->open();
}

bool MemoryFilter::next(Row& row) {
    while (child->next(row)) {
        if (evaluate(row, condition, graph).toBool()) return true;
    }
    return false;
}

void MemoryFilter::close() {
    child->close();
}


// --- MemoryProject ---

MemoryProject::MemoryProject(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> f) 
    : PhysicalOperator(g), child(move(c)), fields(f) {}

void MemoryProject::open() {
    child->open();
}

bool MemoryProject::next(Row& row) {
    if (!child->next(row)) return false;
    
    Row projectedRow;
    for (const string& field : fields) {
        Value val = evaluate(row, field, graph);
        projectedRow.values[field] = val;
    }
    
    row = projectedRow;
    return true;
}

void MemoryProject::close() {
    child->close();
}

// --- MemoryLimit ---

MemoryLimit::MemoryLimit(Graph& g, unique_ptr<PhysicalOperator> c, int l) : PhysicalOperator(g), child(std::move(c)), limit(l) {}

void MemoryLimit::open() {
    child->open();
    count = 0;
}

bool MemoryLimit::next(Row& row) {
    if (count >= limit) return false;
    
    if (child->next(row)) {
        count++;
        return true;
    }
    return false;
}

void MemoryLimit::close() {
    child->close();
}

// --- MemoryOffset ---

MemoryOffset::MemoryOffset(Graph& g, unique_ptr<PhysicalOperator> c, int o) : PhysicalOperator(g), child(std::move(c)), offset(o) {}

void MemoryOffset::open() {
    child->open();
    count = 0;
}

bool MemoryOffset::next(Row& row) {
    // Skip rows
    while (count < offset) {
        Row dummy;
        if (!child->next(dummy)) return false;
        count++;
    }
    
    return child->next(row);
}

void MemoryOffset::close() {
    child->close();
}

// --- MemorySort ---

MemorySort::MemorySort(Graph& g, unique_ptr<PhysicalOperator> c, vector<pair<string, bool>> items) 
    : PhysicalOperator(g), child(move(c)) {
    for (auto& item : items) {
        sortItems.push_back({item.first, item.second});
    }
}

void MemorySort::open() {
    child->open();
    sortedRows.clear();
    currentIndex = 0;
    
    // 1. Slurp all rows into memory
    Row row;
    while (child->next(row)) {
        sortedRows.push_back(row);
    }
    
    // 2. Sort them
    sort(sortedRows.begin(), sortedRows.end(), [this](const Row& a, const Row& b) {
        for (const auto& item : sortItems) {
            Value valA = evaluate(a, item.field, graph);
            Value valB = evaluate(b, item.field, graph);
            
            // If they are equal, move to the next sort criteria
            if (valA == valB) continue;
            
            // Otherwise, sort based on ascending/descending
            if (item.ascending) {
                return valA < valB;
            } else {
                return valB < valA; // Descending
            }
        }
        return false; // All criteria equal, preserve original order (or not stable)
    });
}

bool MemorySort::next(Row& row) {
    if (currentIndex >= sortedRows.size()) return false;
    row = sortedRows[currentIndex++];
    return true;
}

void MemorySort::close() {
    sortedRows.clear();
    child->close();
}

struct GroupState {
    Row groupRow; // Holds the grouping keys
    unordered_map<string, Value> accumulators;
    unordered_map<string, int> counts; // For AVG
    unordered_map<string, unordered_set<string>> distinctValues; // For DISTINCT
};

// --- MemoryAggregate ---

MemoryAggregate::MemoryAggregate(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> grp, vector<string> m) 
    : PhysicalOperator(g), child(move(c)), groupings(grp), measures(m) {}

void MemoryAggregate::open() {
    child->open();
    aggregatedRows.clear();
    currentIndex = 0;
    
    unordered_map<string, GroupState> groups;
    
    Row row;
    int rowCount = 0;
    while (child->next(row)) {
        rowCount++;
        // 1. Compute Group Key
        string groupKey = "";
        Row currentGroupRow;
        for (const string& g : groupings) {
            Value v = evaluate(row, g, graph);
            groupKey += v.toString() + "|";
            currentGroupRow.values[g] = v;
        }
        
        if (groups.find(groupKey) == groups.end()) {
            GroupState newState;
            newState.groupRow = currentGroupRow;
            groups[groupKey] = newState;
        }
        GroupState& state = groups[groupKey];
        
        // 2. Accumulate Measures
        for (const string& m : measures) {
            // Parse measure: e.g. "COUNT(p) AS c" or "AVG(p.age)"
            string func, expr, alias;
            bool isDistinct = false;
            size_t openParen = m.find('(');
            size_t closeParen = m.find(')');
            if (openParen != string::npos && closeParen != string::npos) {
                func = m.substr(0, openParen);
                expr = m.substr(openParen + 1, closeParen - openParen - 1);
                
                if (expr.find("DISTINCT ") == 0) {
                    isDistinct = true;
                    expr = expr.substr(9);
                }
                
                size_t asPos = m.find(" AS ");
                if (asPos != string::npos) {
                    alias = m.substr(asPos + 4);
                } else {
                    alias = m; // Default to full string if no alias
                }
                
                Value val = (expr.empty() || expr == "*") ? Value(1) : evaluate(row, expr, graph);
                
                if (func == "COUNT") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = Value(0);
                    }
                    if (!holds_alternative<monostate>(val.data)) {
                        if (isDistinct) {
                            string valStr = val.toString();
                            if (state.distinctValues[alias].find(valStr) == state.distinctValues[alias].end()) {
                                state.distinctValues[alias].insert(valStr);
                                int currentCount = std::get<int>(state.accumulators[alias].data);
                                state.accumulators[alias] = Value(currentCount + 1);
                            }
                        } else {
                            int currentCount = std::get<int>(state.accumulators[alias].data);
                            state.accumulators[alias] = Value(currentCount + 1);
                        }
                    }
                } else if (func == "SUM") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = Value(0.0);
                    }
                    double currentSum = state.accumulators[alias].toDouble();
                    state.accumulators[alias] = Value(currentSum + val.toDouble());
                } else if (func == "MAX") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = val;
                    } else {
                        if (val > state.accumulators[alias]) {
                            state.accumulators[alias] = val;
                        }
                    }
                } else if (func == "MIN") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = val;
                    } else {
                        if (val < state.accumulators[alias]) {
                            state.accumulators[alias] = val;
                        }
                    }
                } else if (func == "AVG") {
                    if (state.accumulators.find(alias) == state.accumulators.end()) {
                        state.accumulators[alias] = Value(0.0);
                        state.counts[alias] = 0;
                    }
                    double currentSum = state.accumulators[alias].toDouble();
                    state.accumulators[alias] = Value(currentSum + val.toDouble());
                    state.counts[alias]++;
                }
            }
        }
    }
    
    // 3. Finalize and Store Rows
    for (auto& pair : groups) {
        Row finalRow = pair.second.groupRow;
        for (const string& m : measures) {
            string alias = m;
            size_t asPos = m.find(" AS ");
            if (asPos != string::npos) {
                alias = m.substr(asPos + 4);
            }
            
            // Handle AVG final division
            if (m.find("AVG(") == 0) {
                if (pair.second.counts[alias] > 0) {
                    double sum = pair.second.accumulators[alias].toDouble();
                    int count = pair.second.counts[alias];
                    finalRow.values[alias] = Value(sum / count); 
                } else {
                    finalRow.values[alias] = Value(); // NULL
                }
            } else {
                finalRow.values[alias] = pair.second.accumulators[alias];
            }
        }
        aggregatedRows.push_back(finalRow);
    }
}

bool MemoryAggregate::next(Row& row) {
    if (currentIndex >= aggregatedRows.size()) return false;
    row = aggregatedRows[currentIndex++];
    return true;
}

void MemoryAggregate::close() {
    aggregatedRows.clear();
    child->close();
}

// --- MemoryNestedLoopJoin ---

MemoryNestedLoopJoin::MemoryNestedLoopJoin(Graph& g, unique_ptr<PhysicalOperator> l, unique_ptr<PhysicalOperator> r, string cond) 
    : PhysicalOperator(g), left(move(l)), right(move(r)), condition(cond) {}

void MemoryNestedLoopJoin::open() {
    left->open();
    leftFinished = false;
    rightOpen = false;
}

bool MemoryNestedLoopJoin::next(Row& row) {
    while (true) {
        if (!rightOpen) {
            if (!left->next(currentLeftRow)) {
                return false;
            }
            right->open();
            rightOpen = true;
        }

        Row rightRow;
        if (right->next(rightRow)) {
            Row combinedRow = currentLeftRow;
            for (auto& pair : rightRow.values) {
                combinedRow.values[pair.first] = pair.second;
            }

            if (condition.empty()) {
                 row = combinedRow;
                 return true;
            }

            Value res = evaluate(combinedRow, condition, graph);
            if (holds_alternative<bool>(res.data) && get<bool>(res.data)) {
                row = combinedRow;
                return true;
            }
        } else {
            right->close();
            rightOpen = false;
        }
    }
}

void MemoryNestedLoopJoin::close() {
    left->close();
    if (rightOpen) {
        right->close();
        rightOpen = false;
    }
}

// --- MemoryDelete ---

MemoryDelete::MemoryDelete(Graph& g, unique_ptr<PhysicalOperator> c, vector<string> vars, bool d)
    : PhysicalOperator(g), child(move(c)), variables(vars), detach(d) {}

void MemoryDelete::open() {
    if (child) child->open();
    deletedCount = 0;
    done = false;
}

bool MemoryDelete::next(Row& row) {
    if (done) return false;
    
    if (!child || !child->next(row)) {
        done = true;
        return false;
    }
    
    for (const string& var : variables) {
        if (row.values.find(var) != row.values.end()) {
            Value val = row.values[var];
            if (holds_alternative<int>(val.data)) {
                int id = get<int>(val.data);
                
                if (graph.nodes.count(id)) {
                    if (detach) {
                        vector<int> edgesToDelete;
                        for (const auto& pair : graph.edges) {
                            if (pair.second->sourceId == id || pair.second->targetId == id) {
                                edgesToDelete.push_back(pair.first);
                            }
                        }
                        for (int edgeId : edgesToDelete) {
                            graph.deleteEdge(edgeId);
                        }
                    }
                    if (graph.deleteNode(id)) deletedCount++;
                } else if (graph.edges.count(id)) {
                    if (graph.deleteEdge(id)) deletedCount++;
                }
            }
        }
    }
    
    return true;
}

void MemoryDelete::close() {
    if (child) child->close();
}

// --- MemoryInsert ---

MemoryInsert::MemoryInsert(Graph& g, unique_ptr<PhysicalOperator> c, vector<PhysicalInsertNode> n, vector<PhysicalInsertEdge> e)
    : PhysicalOperator(g), child(move(c)), insertNodes(n), insertEdges(e) {}

void MemoryInsert::open() {
    if (child) child->open();
    insertedNodesCount = 0;
    insertedEdgesCount = 0;
    done = false;
}

bool MemoryInsert::next(Row& row) {
    if (done) return false;
    
    bool hasNext = false;
    if (child) {
        hasNext = child->next(row);
    } else {
        // Simple INSERT with no child (e.g. INSERT (n))
        // We only do this once
        hasNext = !done;
    }
    
    if (!hasNext) {
        done = true;
        return false;
    }
    
    unordered_map<string, int> createdVarIds;
    
    // Insert Nodes
    for (const auto& n : insertNodes) {
        unordered_map<string, Value> props;
        for (auto& p : n.properties) {
            props[p.key] = evaluate(row, p.expressionString, graph);
        }
        auto node = graph.createNode(n.labels, props);
        createdVarIds[n.variable] = node->id;
        row.values[n.variable] = Value((int)node->id); // Feed newly created node into context
        insertedNodesCount++;
    }
    
    // Insert Edges
    for (const auto& e : insertEdges) {
        unordered_map<string, Value> props;
        for (auto& p : e.properties) {
            props[p.key] = evaluate(row, p.expressionString, graph);
        }
        
        int sourceId = -1;
        int targetId = -1;
        
        if (row.values.count(e.sourceVar) && holds_alternative<int>(row.values.at(e.sourceVar).data)) {
            sourceId = get<int>(row.values.at(e.sourceVar).data);
        } else if (createdVarIds.count(e.sourceVar)) {
            sourceId = createdVarIds[e.sourceVar];
        }
        
        if (row.values.count(e.targetVar) && holds_alternative<int>(row.values.at(e.targetVar).data)) {
            targetId = get<int>(row.values.at(e.targetVar).data);
        } else if (createdVarIds.count(e.targetVar)) {
            targetId = createdVarIds[e.targetVar];
        }
        
        if (sourceId != -1 && targetId != -1) {
            auto edge = graph.createEdge(sourceId, targetId, e.labels.empty() ? "" : e.labels[0], props);
            if (edge) {
                createdVarIds[e.variable] = edge->id;
                row.values[e.variable] = Value((int)edge->id);
                insertedEdgesCount++;
            }
        } else {
            cout << "[Warning] Could not resolve endpoints for inserting edge '" << e.variable << "'. Source=" << e.sourceVar << " (id:" << sourceId << "), Target=" << e.targetVar << " (id:" << targetId << ")\n";
        }
    }
    
    if (!child) done = true; // Simple INSERT finishes after one row
    return true;
}

void MemoryInsert::close() {
    if (child) child->close();
}

// --- MemoryUpdate ---

MemoryUpdate::MemoryUpdate(Graph& g, unique_ptr<PhysicalOperator> c, vector<PhysicalUpdateItem> i)
    : PhysicalOperator(g), child(move(c)), items(i) {}

void MemoryUpdate::open() {
    if (child) child->open();
    updatedCount = 0;
    done = false;
}

bool MemoryUpdate::next(Row& row) {
    if (done) return false;
    
    if (!child || !child->next(row)) {
        done = true;
        return false;
    }
    
    for (const auto& item : items) {
        if (row.values.find(item.variable) != row.values.end()) {
            Value val = row.values[item.variable];
            if (holds_alternative<int>(val.data)) {
                int id = get<int>(val.data);
                
                if (graph.nodes.find(id) != graph.nodes.end()) {
                    auto node = graph.nodes[id];
                    if (item.type == PhysicalUpdateItem::SET_PROPERTY) {
                        node->properties[item.key] = evaluate(row, item.expressionString, graph);
                        updatedCount++;
                    } else if (item.type == PhysicalUpdateItem::REMOVE_PROPERTY) {
                        node->properties.erase(item.key);
                        updatedCount++;
                    }
                } else if (graph.edges.find(id) != graph.edges.end()) {
                    auto edge = graph.edges[id];
                    if (item.type == PhysicalUpdateItem::SET_PROPERTY) {
                        edge->properties[item.key] = evaluate(row, item.expressionString, graph);
                        updatedCount++;
                    } else if (item.type == PhysicalUpdateItem::REMOVE_PROPERTY) {
                        edge->properties.erase(item.key);
                        updatedCount++;
                    }
                }
            }
        }
    }
    
    return true;
}

void MemoryUpdate::close() {
    if (child) child->close();
}
