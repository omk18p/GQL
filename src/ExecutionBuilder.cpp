#include "ExecutionBuilder.h"
#include <iostream>

unique_ptr<PhysicalOperator> ExecutionBuilder::build(PhysicalPlanNode* plan) {
    if (!plan) return nullptr;
    
    // Recursive build
    unique_ptr<PhysicalOperator> childOp = nullptr;
    if (!plan->children.empty()) {
        childOp = build(plan->children[0].get());
    }
    
    switch (plan->type) {
        case PhysicalOperatorType::MEM_SCAN_FULL: {
            auto scanNode = dynamic_cast<PhysicalFullScan*>(plan);
            if (scanNode) {
                return make_unique<MemoryFullScan>(graph, move(childOp), scanNode->variable);
            }
            break;
        }
        case PhysicalOperatorType::MEM_SCAN_INDEX: {
            auto scanNode = dynamic_cast<PhysicalIndexScan*>(plan);
            if (scanNode) {
                return make_unique<MemoryIndexScan>(graph, move(childOp), scanNode->label, scanNode->variable);
            }
            break;
        }
        case PhysicalOperatorType::MEM_SCAN_EDGE: {
            auto scanNode = dynamic_cast<PhysicalEdgeScan*>(plan);
            if (scanNode) {
                return make_unique<MemoryEdgeScan>(graph, move(childOp), scanNode->label, scanNode->variable);
            }
            break;
        }
        case PhysicalOperatorType::MEM_FILTER: {
            auto filterNode = dynamic_cast<PhysicalFilter*>(plan);
            if (filterNode && childOp) {
                return make_unique<MemoryFilter>(graph, move(childOp), filterNode->conditionDescription);
            }
            break;
        }
        case PhysicalOperatorType::MEM_PROJECT: {
            auto projectNode = dynamic_cast<PhysicalProject*>(plan);
            if (projectNode && childOp) {
                return make_unique<MemoryProject>(graph, move(childOp), projectNode->fields);
            }
            break;
        }
        case PhysicalOperatorType::MEM_LIMIT: {
            auto limitNode = dynamic_cast<PhysicalLimit*>(plan);
            if (limitNode && childOp) {
                return make_unique<MemoryLimit>(graph, move(childOp), limitNode->limit);
            }
            break;
        }
        case PhysicalOperatorType::MEM_OFFSET: {
            auto offsetNode = dynamic_cast<PhysicalOffset*>(plan);
            if (offsetNode && childOp) {
                return make_unique<MemoryOffset>(graph, move(childOp), offsetNode->offset);
            }
            break;
        }
        case PhysicalOperatorType::MEM_SORT: {
            auto sortNode = dynamic_cast<PhysicalSort*>(plan);
            if (sortNode && childOp) {
                vector<pair<string, bool>> items;
                for (const auto& item : sortNode->items) {
                    items.push_back({item.field, item.ascending});
                }
                return make_unique<MemorySort>(graph, move(childOp), items);
            }
            break;
        }
        case PhysicalOperatorType::MEM_AGGREGATE: {
            auto aggNode = dynamic_cast<PhysicalAggregate*>(plan);
            if (aggNode && childOp) {
                return make_unique<MemoryAggregate>(graph, move(childOp), aggNode->groupings, aggNode->measures);
            }
            break;
        }
        case PhysicalOperatorType::MEM_NESTED_LOOP_JOIN: {
            auto joinNode = dynamic_cast<PhysicalNestedLoopJoin*>(plan);
            if (joinNode && plan->children.size() >= 2) {
                auto left = build(plan->children[0].get());
                auto right = build(plan->children[1].get());
                if (left && right) {
                    return make_unique<MemoryNestedLoopJoin>(graph, move(left), move(right), joinNode->condition);
                }
            }
            break;
        }
        case PhysicalOperatorType::MEM_INSERT: {
            auto insertNode = dynamic_cast<PhysicalInsert*>(plan);
            if (insertNode) {
                return make_unique<MemoryInsert>(graph, move(childOp), insertNode->insertNodes, insertNode->insertEdges);
            }
            break;
        }
        case PhysicalOperatorType::MEM_DELETE: {
            auto deleteNode = dynamic_cast<PhysicalDelete*>(plan);
            if (deleteNode) {
                return make_unique<MemoryDelete>(graph, move(childOp), deleteNode->variables, deleteNode->detach);
            }
            break;
        }
        case PhysicalOperatorType::MEM_UPDATE: {
            auto updateNode = dynamic_cast<PhysicalUpdate*>(plan);
            if (updateNode) {
                return make_unique<MemoryUpdate>(graph, move(childOp), updateNode->items);
            }
            break;
        }
        default:
            cerr << "Unsupported physical operator type in execution builder: " << (int)plan->type << endl;
            return nullptr;
    }
    return nullptr;
}
