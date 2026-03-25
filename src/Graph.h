#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include "Value.h"

using namespace std;

struct Node {
    int id;
    vector<string> labels;
    unordered_map<string, Value> properties;

    bool hasLabel(const string& label) const {
        for (const auto& l : labels) {
            if (l == label) return true;
        }
        return false;
    }
};

struct Edge {
    int id;
    int sourceId;
    int targetId;
    string sourceLabel; // Track source label for output
    string targetLabel; // Track target label for output
    string label;
    unordered_map<string, Value> properties;
};

class Graph {
public:
    unordered_map<int, shared_ptr<Node>> nodes;
    unordered_map<int, shared_ptr<Edge>> edges;
    int nextNodeId = 1;
    int nextEdgeId = 1;

    // Indexes: Label -> [NodeId]
    unordered_map<string, vector<int>> labelIndex;
    unordered_map<string, vector<int>> edgeLabelIndex;

    // Adjacency: sourceId -> [EdgeId]
    unordered_map<int, vector<int>> outEdges;

    void addNode(shared_ptr<Node> node) {
        nodes[node->id] = node;
        for (const auto& label : node->labels) {
            labelIndex[label].push_back(node->id);
        }
    }

    void addEdge(shared_ptr<Edge> edge) {
        edges[edge->id] = edge;
        edgeLabelIndex[edge->label].push_back(edge->id);
        outEdges[edge->sourceId].push_back(edge->id);
    }

    shared_ptr<Node> createNode(vector<string> labels, unordered_map<string, Value> props) {
        auto node = make_shared<Node>();
        node->id = nextNodeId++;
        node->labels = labels;
        node->properties = props;
        addNode(node);
        return node;
    }

    shared_ptr<Edge> createEdge(int sourceId, int targetId, string label, unordered_map<string, Value> props) {
        auto edge = make_shared<Edge>();
        edge->id = nextEdgeId++;
        edge->sourceId = sourceId;
        edge->targetId = targetId;
        edge->label = label;
        edge->properties = props;
        
        // Track labels for output formatting
        if (nodes.count(sourceId) && !nodes[sourceId]->labels.empty()) {
            edge->sourceLabel = nodes[sourceId]->labels[0];
        } else {
            edge->sourceLabel = "Node";
        }
        
        if (nodes.count(targetId) && !nodes[targetId]->labels.empty()) {
            edge->targetLabel = nodes[targetId]->labels[0];
        } else {
            edge->targetLabel = "Node";
        }

        addEdge(edge);
        return edge;
    }

    // scans
    vector<shared_ptr<Node>> getNodesByLabel(const string& label) {
        vector<shared_ptr<Node>> result;
        if (labelIndex.find(label) != labelIndex.end()) {
            for (int id : labelIndex[label]) {
                result.push_back(nodes[id]);
            }
        }
        return result;
    }

    vector<shared_ptr<Edge>> getEdgesByLabel(const string& label) {
        vector<shared_ptr<Edge>> result;
        if (edgeLabelIndex.find(label) != edgeLabelIndex.end()) {
            for (int id : edgeLabelIndex[label]) {
                result.push_back(edges[id]);
            }
        }
        return result;
    }
    
    vector<shared_ptr<Node>> getAllNodes() {
        vector<shared_ptr<Node>> result;
        for (auto& pair : nodes) {
            result.push_back(pair.second);
        }
        return result;
    }

    vector<shared_ptr<Edge>> getAllEdges() {
        vector<shared_ptr<Edge>> result;
        for (auto& pair : edges) {
            result.push_back(pair.second);
        }
        return result;
    }
    // updates
    bool deleteNode(int id) {
        if (nodes.find(id) == nodes.end()) return false;
        
        // Remove from label index
        auto node = nodes[id];
        for (const auto& label : node->labels) {
            auto& vec = labelIndex[label];
            vec.erase(remove(vec.begin(), vec.end(), id), vec.end());
            if (vec.empty()) labelIndex.erase(label);
        }
        
        // Find all connected edges
        vector<int> edgesToDelete;
        for (const auto& pair : edges) {
            if (pair.second->sourceId == id || pair.second->targetId == id) {
                edgesToDelete.push_back(pair.first);
            }
        }
        
        // Delete connected edges
        for (int edgeId : edgesToDelete) {
            deleteEdge(edgeId);
        }
        
        nodes.erase(id);
        return true;
    }

    bool deleteEdge(int id) {
        if (edges.find(id) == edges.end()) return false;
        
        auto edge = edges[id];
        
        // Remove from label index
        auto& vec = edgeLabelIndex[edge->label];
        vec.erase(remove(vec.begin(), vec.end(), id), vec.end());
        if (vec.empty()) edgeLabelIndex.erase(edge->label);
        
        // Remove from outEdges index
        auto& outVec = outEdges[edge->sourceId];
        outVec.erase(remove(outVec.begin(), outVec.end(), id), outVec.end());
        if (outVec.empty()) outEdges.erase(edge->sourceId);
        
        edges.erase(id);
        return true;
    }
};
