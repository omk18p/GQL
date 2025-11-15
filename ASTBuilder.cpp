#include "ASTBuilder.h"
#include "GQLParser.h"

std::unique_ptr<QueryNode> ASTBuilder::build(GQLParser::GqlProgramContext* ctx) {
    root = std::make_unique<QueryNode>();
    visit(ctx);
    return std::move(root);
}

antlrcpp::Any ASTBuilder::visitGqlProgram(GQLParser::GqlProgramContext* ctx) {
    if (ctx->programActivity()) visit(ctx->programActivity());
    if (ctx->SESSION() && ctx->CLOSE()) {
        root->children.push_back(std::make_unique<SessionCloseNode>());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitProgramActivity(GQLParser::ProgramActivityContext* ctx) {
    if (ctx->sessionActivity()) visit(ctx->sessionActivity());
    if (ctx->transactionActivity()) visit(ctx->transactionActivity());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSessionActivity(GQLParser::SessionActivityContext* ctx) {
    for (auto* s : ctx->sessionSetCommand()) visit(s);
    for (auto* r : ctx->sessionResetCommand()) visit(r);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSessionSetCommand(GQLParser::SessionSetCommandContext* ctx) {
    root->children.push_back(std::make_unique<SessionSetNode>(ctx->getText()));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSessionResetCommand(GQLParser::SessionResetCommandContext* ctx) {
    root->children.push_back(std::make_unique<SessionResetNode>(ctx->getText()));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitTransactionActivity(GQLParser::TransactionActivityContext* ctx) {
    if (ctx->startTransactionCommand()) visit(ctx->startTransactionCommand());
    if (ctx->procedureBody()) {
        // Visit procedure body which contains statements
        visit(ctx->procedureBody());
    }
    if (ctx->COMMIT()) root->children.push_back(std::make_unique<TransactionNode>("COMMIT"));
    if (ctx->ROLLBACK()) root->children.push_back(std::make_unique<TransactionNode>("ROLLBACK"));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitProcedureBody(GQLParser::ProcedureBodyContext* ctx) {
    if (ctx->statementBlock()) {
        visit(ctx->statementBlock());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitStatementBlock(GQLParser::StatementBlockContext* ctx) {
    if (ctx->statement()) {
        visit(ctx->statement());
    }
    for (auto* nextStmt : ctx->nextStatement()) {
        visit(nextStmt);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitStatement(GQLParser::StatementContext* ctx) {
    if (ctx->linearCatalogModifyingStatement()) {
        visit(ctx->linearCatalogModifyingStatement());
    }
    if (ctx->linearDataModifyingStatement()) {
        visit(ctx->linearDataModifyingStatement());
    }
    if (ctx->compositeQueryStatement()) {
        visit(ctx->compositeQueryStatement());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLinearCatalogModifyingStatement(GQLParser::LinearCatalogModifyingStatementContext* ctx) {
    // linearCatalogModifyingStatement: (primitiveCatalogModifyingStatement | callProcedureStatement)+
    // Visit all primitive catalog modifying statements and procedure calls
    for (auto* stmt : ctx->primitiveCatalogModifyingStatement()) {
        visit(stmt);
    }
    for (auto* stmt : ctx->callProcedureStatement()) {
        visit(stmt);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPrimitiveCatalogModifyingStatement(GQLParser::PrimitiveCatalogModifyingStatementContext* ctx) {
    auto catalogNode = std::make_unique<CatalogStatementNode>();
    
    // Handle CREATE SCHEMA
    if (ctx->CREATE() && ctx->SCHEMA()) {
        catalogNode->action = "CREATE";
        catalogNode->objectType = "SCHEMA";
        if (ctx->catalogSchemaParentAndName()) {
            catalogNode->name = ctx->catalogSchemaParentAndName()->getText();
            size_t lastSlash = catalogNode->name.find_last_of('/');
            if (lastSlash != std::string::npos && lastSlash + 1 < catalogNode->name.length()) {
                catalogNode->name = catalogNode->name.substr(lastSlash + 1);
            }
        }
        if (ctx->IF() && ctx->NOT() && ctx->EXISTS()) {
            catalogNode->name = "IF NOT EXISTS " + catalogNode->name;
        }
    }
    // Handle DROP SCHEMA
    else if (ctx->DROP() && ctx->SCHEMA()) {
        catalogNode->action = "DROP";
        catalogNode->objectType = "SCHEMA";
        if (ctx->catalogSchemaParentAndName()) {
            catalogNode->name = ctx->catalogSchemaParentAndName()->getText();
            size_t lastSlash = catalogNode->name.find_last_of('/');
            if (lastSlash != std::string::npos && lastSlash + 1 < catalogNode->name.length()) {
                catalogNode->name = catalogNode->name.substr(lastSlash + 1);
            }
        }
        if (ctx->IF() && ctx->EXISTS()) {
            catalogNode->name = "IF EXISTS " + catalogNode->name;
        }
    }
    // Handle CREATE GRAPH
    else if (ctx->CREATE() && (ctx->GRAPH() || ctx->PROPERTY())) {
        catalogNode->action = "CREATE";
        catalogNode->objectType = "GRAPH";
        if (ctx->catalogGraphParentAndName()) {
            catalogNode->name = ctx->catalogGraphParentAndName()->getText();
        }
        if (ctx->IF() && ctx->NOT() && ctx->EXISTS()) {
            catalogNode->name = "IF NOT EXISTS " + catalogNode->name;
        } else if (ctx->OR() && ctx->REPLACE()) {
            catalogNode->name = "OR REPLACE " + catalogNode->name;
        }
        // Extract graph type and source information (stored in name for now)
        if (ctx->openGraphType() || ctx->ofGraphType()) {
            catalogNode->name += " " + (ctx->openGraphType() ? ctx->openGraphType()->getText() : ctx->ofGraphType()->getText());
        }
        if (ctx->graphSource()) {
            catalogNode->name += " " + ctx->graphSource()->getText();
        }
    }
    // Handle DROP GRAPH
    else if (ctx->DROP() && (ctx->GRAPH() || ctx->PROPERTY())) {
        catalogNode->action = "DROP";
        catalogNode->objectType = "GRAPH";
        if (ctx->catalogGraphParentAndName()) {
            catalogNode->name = ctx->catalogGraphParentAndName()->getText();
        }
        if (ctx->IF() && ctx->EXISTS()) {
            catalogNode->name = "IF EXISTS " + catalogNode->name;
        }
    }
    // Handle CREATE GRAPH TYPE
    else if (ctx->CREATE() && ctx->TYPE()) {
        catalogNode->action = "CREATE";
        catalogNode->objectType = "GRAPH_TYPE";
        if (ctx->catalogGraphTypeParentAndName()) {
            catalogNode->name = ctx->catalogGraphTypeParentAndName()->getText();
        }
        if (ctx->IF() && ctx->NOT() && ctx->EXISTS()) {
            catalogNode->name = "IF NOT EXISTS " + catalogNode->name;
        } else if (ctx->OR() && ctx->REPLACE()) {
            catalogNode->name = "OR REPLACE " + catalogNode->name;
        }
        if (ctx->graphTypeSource()) {
            catalogNode->name += " " + ctx->graphTypeSource()->getText();
        }
    }
    // Handle DROP GRAPH TYPE
    else if (ctx->DROP() && ctx->TYPE()) {
        catalogNode->action = "DROP";
        catalogNode->objectType = "GRAPH_TYPE";
        if (ctx->catalogGraphTypeParentAndName()) {
            catalogNode->name = ctx->catalogGraphTypeParentAndName()->getText();
        }
        if (ctx->IF() && ctx->EXISTS()) {
            catalogNode->name = "IF EXISTS " + catalogNode->name;
        }
    }
    
    root->children.push_back(std::move(catalogNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPrimitiveQueryStatement(GQLParser::PrimitiveQueryStatementContext* ctx) {
    if (ctx->matchStatement()) {
        visit(ctx->matchStatement());
    }
    // Handle LET statement
    if (ctx->LET()) {
        auto letNode = std::make_unique<LetStatementNode>();
        // Push the node first so visitLetVariableDefinition can find it
        root->children.push_back(std::move(letNode));
        
        // Now visit variable definitions (they will add to the node we just pushed)
        for (auto* letVarDef : ctx->letVariableDefinition()) {
            visit(letVarDef);
        }
    }
    // Handle FOR statement
    if (ctx->FOR()) {
        auto forNode = std::make_unique<ForStatementNode>();
        if (!ctx->bindingVariable().empty()) {
            forNode->variable = ctx->bindingVariable(0)->getText();
        }
        if (ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "COLLECTION";
            exprNode->value = ctx->valueExpression()->getText();
            forNode->collectionExpression = std::move(exprNode);
        }
        if (ctx->WITH()) {
            if (ctx->ORDINALITY()) {
                forNode->withOrdinality = true;
            } else if (ctx->OFFSET()) {
                forNode->withOffset = true;
            }
            // Extract ordinality/offset variable
            if (ctx->bindingVariable().size() > 1) {
                forNode->ordinalityVar = ctx->bindingVariable(1)->getText();
            }
        }
        root->children.push_back(std::move(forNode));
    }
    // Handle FILTER statement
    if (ctx->FILTER()) {
        auto filterNode = std::make_unique<FilterStatementNode>();
        if (ctx->whereClause()) {
            visit(ctx->whereClause());
            // The whereClause visitor adds to currentMatchNode if available, otherwise root
            // We need to attach it to filterNode instead
        } else if (ctx->searchCondition()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "CONDITION";
            exprNode->value = ctx->searchCondition()->getText();
            filterNode->condition = std::move(exprNode);
        }
        root->children.push_back(std::move(filterNode));
    }
    // Handle ORDER BY statement
    if (ctx->orderByAndPageStatement()) {
        visit(ctx->orderByAndPageStatement());
    }
    // Note: PrimitiveQueryStatement doesn't have primitiveResultStatement directly
    // It's handled at a higher level in the statement hierarchy
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitStartTransactionCommand(GQLParser::StartTransactionCommandContext* ctx) {
    root->children.push_back(std::make_unique<TransactionNode>("START"));
    return nullptr;
}

// MATCH statement visitors
antlrcpp::Any ASTBuilder::visitMatchStatement(GQLParser::MatchStatementContext* ctx) {
    auto matchNode = std::make_unique<MatchStatementNode>();
    
    // Check for OPTIONAL keyword
    if (ctx->OPTIONAL()) {
        matchNode->optional = true;
    }
    
    currentMatchNode = matchNode.get();  // Set current match node
    
    // Visit the graph pattern binding table
    if (ctx->graphPatternBindingTable()) {
        visit(ctx->graphPatternBindingTable());
    }
    
    currentMatchNode = nullptr;  // Clear current match node
    root->children.push_back(std::move(matchNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitGraphPatternBindingTable(GQLParser::GraphPatternBindingTableContext* ctx) {
    // Visit graph pattern
    if (ctx->graphPattern()) {
        visit(ctx->graphPattern());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitGraphPattern(GQLParser::GraphPatternContext* ctx) {
    // Visit path patterns
    for (auto* pathPattern : ctx->pathPattern()) {
        visit(pathPattern);
    }
    
    // Visit WHERE clause if present - GraphPattern has searchCondition, not whereClause
    if (ctx->searchCondition() && currentMatchNode) {
        auto whereNode = std::make_unique<WhereClauseNode>();
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "CONDITION";
        exprNode->value = ctx->searchCondition()->getText();
        whereNode->condition = std::move(exprNode);
        currentMatchNode->whereClause = std::move(whereNode);
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPathPattern(GQLParser::PathPatternContext* ctx) {
    // Visit path pattern expression
    if (ctx->pathPatternExpression()) {
        visit(ctx->pathPatternExpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPpePathTerm(GQLParser::PpePathTermContext* ctx) {
    // Single path term
    if (ctx->pathTerm()) {
        visit(ctx->pathTerm());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPpePatternUnion(GQLParser::PpePatternUnionContext* ctx) {
    // Visit path terms
    for (auto* pathTerm : ctx->pathTerm()) {
        visit(pathTerm);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPpeMultisetAlternation(GQLParser::PpeMultisetAlternationContext* ctx) {
    // Visit path terms
    for (auto* pathTerm : ctx->pathTerm()) {
        visit(pathTerm);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPathTerm(GQLParser::PathTermContext* ctx) {
    // Visit path factors
    for (auto* pathFactor : ctx->pathFactor()) {
        visit(pathFactor);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPfPathPrimary(GQLParser::PfPathPrimaryContext* ctx) {
    // Simple path primary
    if (ctx->pathPrimary()) {
        visit(ctx->pathPrimary());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPfQuantifiedPathPrimary(GQLParser::PfQuantifiedPathPrimaryContext* ctx) {
    // Quantified path primary (with *, +, {n}, etc.)
    if (ctx->pathPrimary()) {
        visit(ctx->pathPrimary());
    }
    // TODO: Handle quantifier
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPfQuestionedPathPrimary(GQLParser::PfQuestionedPathPrimaryContext* ctx) {
    // Optional path primary (with ?)
    if (ctx->pathPrimary()) {
        visit(ctx->pathPrimary());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPpElementPattern(GQLParser::PpElementPatternContext* ctx) {
    // Element pattern in path primary
    if (ctx->elementPattern()) {
        visit(ctx->elementPattern());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPpParenthesizedPathPatternExpression(GQLParser::PpParenthesizedPathPatternExpressionContext* ctx) {
    // Parenthesized path pattern expression
    if (ctx->parenthesizedPathPatternExpression()) {
        visit(ctx->parenthesizedPathPatternExpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPpSimplifiedPathPatternExpression(GQLParser::PpSimplifiedPathPatternExpressionContext* ctx) {
    // Simplified path pattern expression
    if (ctx->simplifiedPathPatternExpression()) {
        visit(ctx->simplifiedPathPatternExpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitElementPattern(GQLParser::ElementPatternContext* ctx) {
    // Handle node patterns: (variable:label {properties})
    if (ctx->elementPatternFiller()) {
        auto nodePattern = std::make_unique<NodePatternNode>();
        
        // Extract variable name
        if (ctx->elementPatternFiller()->elementVariableDeclaration()) {
            auto varDecl = ctx->elementPatternFiller()->elementVariableDeclaration();
            if (varDecl->elementVariable()) {
                if (varDecl->elementVariable()->bindingVariable()) {
                    nodePattern->variable = varDecl->elementVariable()->bindingVariable()->getText();
                }
            }
        }
        
        // Extract labels - parse the label expression to get just the label name
        if (ctx->elementPatternFiller()->isLabelExpression()) {
            auto labelExpr = ctx->elementPatternFiller()->isLabelExpression()->labelExpression();
            if (labelExpr) {
                // Try to cast to LabelExpressionName to extract label directly
                auto labelNameCtx = dynamic_cast<GQLParser::LabelExpressionNameContext*>(labelExpr);
                if (labelNameCtx && labelNameCtx->labelName() && labelNameCtx->labelName()->identifier()) {
                    std::string labelName = labelNameCtx->labelName()->identifier()->getText();
                    nodePattern->labels.push_back(labelName);
                } else {
                    // Fallback: extract from text and remove colon prefix
                    std::string labelText = ctx->elementPatternFiller()->isLabelExpression()->getText();
                    // Remove leading colon if present
                    if (!labelText.empty() && labelText[0] == ':') {
                        labelText = labelText.substr(1);
                    }
                    if (!labelText.empty()) {
                        nodePattern->labels.push_back(labelText);
                    }
                }
            }
        }
        
        // Extract properties - parse property map properly
        // Store reference to nodePattern before visiting properties
        NodePatternNode* nodePatternPtr = nodePattern.get();
        
        if (ctx->elementPatternFiller()->elementPatternPredicate()) {
            auto pred = ctx->elementPatternFiller()->elementPatternPredicate();
            if (pred->elementPropertySpecification()) {
                // Temporarily add nodePattern to currentMatchNode so property visitor can find it
                bool wasAdded = false;
                if (currentMatchNode) {
                    currentMatchNode->patterns.push_back(std::move(nodePattern));
                    wasAdded = true;
                }
                
                visit(pred->elementPropertySpecification());
                // Property map parsing will populate nodePattern->properties
                
                // If we added it, we need to get it back (it's already in patterns)
                if (wasAdded && currentMatchNode && !currentMatchNode->patterns.empty()) {
                    nodePatternPtr = static_cast<NodePatternNode*>(currentMatchNode->patterns.back().get());
                }
            }
        }
        
        // Add to current match node if available, otherwise to root
        if (currentMatchNode) {
            // Check if already added (from property parsing above)
            if (currentMatchNode->patterns.empty() || 
                currentMatchNode->patterns.back().get() != nodePatternPtr) {
                currentMatchNode->patterns.push_back(std::move(nodePattern));
            }
        } else {
            root->children.push_back(std::move(nodePattern));
        }
    } else if (ctx->fullEdgePattern()) {
        // Handle full edge patterns
        visit(ctx->fullEdgePattern());
    } else if (ctx->abbreviatedEdgePattern()) {
        // Handle abbreviated edge patterns
        visit(ctx->abbreviatedEdgePattern());
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitFullEdgePattern(GQLParser::FullEdgePatternContext* ctx) {
    auto edgePattern = std::make_unique<EdgePatternNode>();
    
    // Determine direction based on which alternative matched
    if (ctx->LEFT_ARROW_BRACKET() && ctx->RIGHT_BRACKET_MINUS()) {
        edgePattern->direction = "<--";
    } else if (ctx->TILDE_LEFT_BRACKET() && ctx->RIGHT_BRACKET_TILDE()) {
        edgePattern->direction = "<->";
    } else if (ctx->MINUS_LEFT_BRACKET() && ctx->BRACKET_RIGHT_ARROW()) {
        edgePattern->direction = "-->";
    } else if (ctx->LEFT_ARROW_BRACKET() && ctx->BRACKET_RIGHT_ARROW()) {
        edgePattern->direction = "<->";
    } else if (ctx->MINUS_LEFT_BRACKET() && ctx->RIGHT_BRACKET_MINUS()) {
        edgePattern->direction = "<--";
    } else {
        edgePattern->direction = "-->";  // Default
    }
    
    // Extract edge filler information
    if (ctx->elementPatternFiller()) {
        auto filler = ctx->elementPatternFiller();
        
        // Extract variable name
        if (filler->elementVariableDeclaration()) {
            auto varDecl = filler->elementVariableDeclaration();
            if (varDecl->elementVariable() && varDecl->elementVariable()->bindingVariable()) {
                edgePattern->variable = varDecl->elementVariable()->bindingVariable()->getText();
            }
        }
        
        // Extract labels
        if (filler->isLabelExpression()) {
            auto labelExpr = filler->isLabelExpression()->labelExpression();
            if (labelExpr) {
                // Try to cast to LabelExpressionName to extract label directly
                auto labelNameCtx = dynamic_cast<GQLParser::LabelExpressionNameContext*>(labelExpr);
                if (labelNameCtx && labelNameCtx->labelName() && labelNameCtx->labelName()->identifier()) {
                    std::string labelName = labelNameCtx->labelName()->identifier()->getText();
                    edgePattern->labels.push_back(labelName);
                } else {
                    // Fallback: extract from text and remove colon prefix
                    std::string labelText = filler->isLabelExpression()->getText();
                    if (!labelText.empty() && labelText[0] == ':') {
                        labelText = labelText.substr(1);
                    }
                    if (!labelText.empty()) {
                        edgePattern->labels.push_back(labelText);
                    }
                }
            }
        }
        
        // Extract properties
        if (filler->elementPatternPredicate()) {
            auto pred = filler->elementPatternPredicate();
            if (pred->elementPropertySpecification()) {
                std::string propText = pred->elementPropertySpecification()->getText();
                if (!propText.empty() && propText[0] == '{') {
                    edgePattern->properties["raw"] = propText;
                }
            }
        }
    }
    
    // Add to current match node if available, otherwise to root
    if (currentMatchNode) {
        currentMatchNode->patterns.push_back(std::move(edgePattern));
    } else {
        root->children.push_back(std::move(edgePattern));
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAbbreviatedEdgePattern(GQLParser::AbbreviatedEdgePatternContext* ctx) {
    auto edgePattern = std::make_unique<EdgePatternNode>();
    
    // Determine direction from token
    if (ctx->LEFT_ARROW()) {
        edgePattern->direction = "<-";
    } else if (ctx->RIGHT_ARROW()) {
        edgePattern->direction = "->";
    } else if (ctx->TILDE()) {
        edgePattern->direction = "-";
    } else if (ctx->LEFT_ARROW_TILDE()) {
        edgePattern->direction = "<-";
    } else if (ctx->TILDE_RIGHT_ARROW()) {
        edgePattern->direction = "->";
    } else if (ctx->LEFT_MINUS_RIGHT()) {
        edgePattern->direction = "-";
    } else if (ctx->MINUS_SIGN()) {
        edgePattern->direction = "-";
    } else {
        edgePattern->direction = "-";
    }
    
    // Abbreviated edges don't have variables or labels
    edgePattern->variable = "";
    
    // Add to current match node if available, otherwise to root
    if (currentMatchNode) {
        currentMatchNode->patterns.push_back(std::move(edgePattern));
    } else {
        root->children.push_back(std::move(edgePattern));
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPrimitiveResultStatement(GQLParser::PrimitiveResultStatementContext* ctx) {
    if (ctx->RETURN()) {
        auto returnNode = std::make_unique<ReturnStatementNode>();
        
        // Check for DISTINCT
        if (ctx->setQuantifier() && ctx->setQuantifier()->DISTINCT()) {
            returnNode->distinct = true;
        }
        
        // Set current return node so visitReturnItem can attach to it
        currentReturnNode = returnNode.get();
        
        // Visit return items (they will attach to currentReturnNode)
        for (auto* returnItem : ctx->returnItem()) {
            visit(returnItem);
        }
        
        // Clear current return node
        currentReturnNode = nullptr;
        
        // Attach to current match node if available, otherwise find last MatchStatement
        if (currentMatchNode) {
            currentMatchNode->returnStatement = std::move(returnNode);
        } else {
            // Find the last MatchStatement in root children and attach RETURN to it
            bool attached = false;
            for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
                if ((*it)->type == ASTNode::MATCH_STATEMENT) {
                    MatchStatementNode* matchNode = static_cast<MatchStatementNode*>(it->get());
                    matchNode->returnStatement = std::move(returnNode);
                    attached = true;
                    break;
                }
            }
            if (!attached) {
                // No match statement found, add to root
                root->children.push_back(std::move(returnNode));
            }
        }
        
        // Handle ORDER BY if present (it's part of primitiveResultStatement)
        if (ctx->orderByAndPageStatement()) {
            visit(ctx->orderByAndPageStatement());
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitReturnItem(GQLParser::ReturnItemContext* ctx) {
    if (ctx->aggregatingValueExpression()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "VARIABLE";
        exprNode->value = ctx->aggregatingValueExpression()->getText();
        
        // Attach to current return node if available
        if (currentReturnNode) {
            currentReturnNode->expressions.push_back(std::move(exprNode));
        } else if (currentMatchNode && currentMatchNode->returnStatement) {
            // Fallback: attach to match statement's return statement
            ReturnStatementNode* returnNode = static_cast<ReturnStatementNode*>(currentMatchNode->returnStatement.get());
            returnNode->expressions.push_back(std::move(exprNode));
        } else {
            // Look for last return statement in root children
            bool added = false;
            for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
                if ((*it)->type == ASTNode::RETURN_STATEMENT) {
                    ReturnStatementNode* returnNode = static_cast<ReturnStatementNode*>(it->get());
                    returnNode->expressions.push_back(std::move(exprNode));
                    added = true;
                    break;
                }
            }
            if (!added) {
                // If no return statement found, add to root
                root->children.push_back(std::move(exprNode));
            }
        }
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitWhereClause(GQLParser::WhereClauseContext* ctx) {
    auto whereNode = std::make_unique<WhereClauseNode>();
    
    if (ctx->searchCondition()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "CONDITION";
        exprNode->value = ctx->searchCondition()->getText();
        whereNode->condition = std::move(exprNode);
    }
    
    // Add to current match node if available, otherwise to root
    if (currentMatchNode) {
        currentMatchNode->whereClause = std::move(whereNode);
    } else {
        root->children.push_back(std::move(whereNode));
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLabelExpressionName(GQLParser::LabelExpressionNameContext* ctx) {
    // Label expression is just a label name
    // Extract the label name and store it for the current pattern being built
    // This is called when visiting a label expression that's a simple name
    if (ctx->labelName() && ctx->labelName()->identifier()) {
        std::string labelName = ctx->labelName()->identifier()->getText();
        // Store label name - we'll need to attach it to the current pattern
        // For now, return it as the result so calling code can use it
        return labelName;
    }
    return std::string("");
}

antlrcpp::Any ASTBuilder::visitLabelExpressionNegation(GQLParser::LabelExpressionNegationContext* ctx) {
    // Label expression negation: !labelExpression
    // Visit the nested label expression and mark it as negated
    if (ctx->labelExpression()) {
        visit(ctx->labelExpression());
        // Return the negated expression (for now as text, could be structured)
        std::string expr = ctx->labelExpression()->getText();
        return "!" + expr;
    }
    return std::string("!");
}

antlrcpp::Any ASTBuilder::visitLabelExpressionConjunction(GQLParser::LabelExpressionConjunctionContext* ctx) {
    // Label expression conjunction: labelExpression & labelExpression
    // Visit both expressions and combine them
    std::string left, right;
    if (ctx->labelExpression().size() >= 2) {
        visit(ctx->labelExpression(0));
        visit(ctx->labelExpression(1));
        left = ctx->labelExpression(0)->getText();
        right = ctx->labelExpression(1)->getText();
        return left + "&" + right;
    }
    return ctx->getText();
}

antlrcpp::Any ASTBuilder::visitLabelExpressionDisjunction(GQLParser::LabelExpressionDisjunctionContext* ctx) {
    // Label expression disjunction: labelExpression | labelExpression
    // Visit both expressions and combine them
    std::string left, right;
    if (ctx->labelExpression().size() >= 2) {
        visit(ctx->labelExpression(0));
        visit(ctx->labelExpression(1));
        left = ctx->labelExpression(0)->getText();
        right = ctx->labelExpression(1)->getText();
        return left + "|" + right;
    }
    return ctx->getText();
}

antlrcpp::Any ASTBuilder::visitLabelExpressionParenthesized(GQLParser::LabelExpressionParenthesizedContext* ctx) {
    // Label expression parenthesized: (labelExpression)
    // Visit the nested expression and wrap it in parentheses
    if (ctx->labelExpression()) {
        visit(ctx->labelExpression());
        std::string expr = ctx->labelExpression()->getText();
        return "(" + expr + ")";
    }
    return std::string("()");
}

antlrcpp::Any ASTBuilder::visitLabelExpressionWildcard(GQLParser::LabelExpressionWildcardContext* ctx) {
    // Label expression wildcard: %
    // Return the wildcard symbol
    return std::string("%");
}

antlrcpp::Any ASTBuilder::visitGraphPatternQuantifier(GQLParser::GraphPatternQuantifierContext* ctx) {
    // Graph pattern quantifier: *, +, {n}, {n,m}
    // Extract the quantifier and return it as a string
    if (ctx->ASTERISK()) {
        return std::string("*");
    } else if (ctx->PLUS_SIGN()) {
        return std::string("+");
    } else if (ctx->LEFT_BRACE()) {
        // Handle {n} or {n,m} or {,m} or {n,}
        std::string quantifier = "{";
        if (ctx->unsignedInteger().size() > 0) {
            quantifier += ctx->unsignedInteger(0)->getText();
        }
        if (ctx->COMMA()) {
            quantifier += ",";
            if (ctx->unsignedInteger().size() > 1) {
                quantifier += ctx->unsignedInteger(1)->getText();
            }
        }
        quantifier += "}";
        return quantifier;
    }
    return std::string("");
}

// Phase 2: Primitive query statement visitors
antlrcpp::Any ASTBuilder::visitLetVariableDefinition(GQLParser::LetVariableDefinitionContext* ctx) {
    LetStatementNode::LetVariableDefinition def;
    
    // Handle VALUE bindingVariable (typed? valueType)? (EQUALS_OPERATOR valueExpression)
    if (ctx->VALUE()) {
        if (ctx->bindingVariable()) {
            def.variable = ctx->bindingVariable()->getText();
        }
        // TODO: Handle typed and valueType
        if (ctx->EQUALS_OPERATOR() && ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "VALUE";
            exprNode->value = ctx->valueExpression()->getText();
            def.valueExpression = std::move(exprNode);
            def.hasValue = true;
        }
    } else if (ctx->bindingVariable()) {
        // Handle bindingVariable EQUALS_OPERATOR valueExpression
        def.variable = ctx->bindingVariable()->getText();
        if (ctx->EQUALS_OPERATOR() && ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "VALUE";
            exprNode->value = ctx->valueExpression()->getText();
            def.valueExpression = std::move(exprNode);
            def.hasValue = true;
        }
    }
    
    // Find the last LET statement node in root children and add to it
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::LET_STATEMENT) {
            LetStatementNode* letNode = static_cast<LetStatementNode*>(it->get());
            letNode->definitions.push_back(std::move(def));
            break;
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitOrderByAndPageStatement(GQLParser::OrderByAndPageStatementContext* ctx) {
    // Create OrderByStatementNode and push it first so visitors can find it
    auto orderByNode = std::make_unique<OrderByStatementNode>();
    root->children.push_back(std::move(orderByNode));
    
    // Handle orderByClause offsetClause? limitClause?
    if (ctx->orderByClause()) {
        visit(ctx->orderByClause());
    }
    // Handle offsetClause limitClause?
    if (ctx->offsetClause()) {
        visit(ctx->offsetClause());
    }
    // Handle limitClause
    if (ctx->limitClause()) {
        visit(ctx->limitClause());
    }
    
    // If we have a current match node, we should attach ORDER BY to it
    // For now, ORDER BY is a separate node - could be attached to MatchStatement later
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitOrderByClause(GQLParser::OrderByClauseContext* ctx) {
    OrderByStatementNode* orderByNode = nullptr;
    
    // Find last OrderByStatementNode in root children
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::ORDER_BY_STATEMENT) {
            orderByNode = static_cast<OrderByStatementNode*>(it->get());
            break;
        }
    }
    
    if (!orderByNode) {
        // Create new one if not found
        auto newNode = std::make_unique<OrderByStatementNode>();
        orderByNode = newNode.get();
        root->children.push_back(std::move(newNode));
    }
    
    // Visit sort specifications
    for (auto* sortSpec : ctx->sortSpecification()) {
        visit(sortSpec);
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSortSpecification(GQLParser::SortSpecificationContext* ctx) {
    OrderByStatementNode::SortSpecification spec;
    
    // Extract sort key expression (aggregatingValueExpression)
    if (ctx->aggregatingValueExpression()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "SORT_KEY";
        exprNode->value = ctx->aggregatingValueExpression()->getText();
        spec.sortKey = std::move(exprNode);
    }
    
    // Extract direction (ASC/DESC/ASCENDING/DESCENDING)
    if (ctx->ASC() || ctx->ASCENDING()) {
        spec.direction = "ASC";
    } else if (ctx->DESC() || ctx->DESCENDING()) {
        spec.direction = "DESC";
    }
    
    // Find last OrderByStatementNode in root children
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::ORDER_BY_STATEMENT) {
            OrderByStatementNode* orderByNode = static_cast<OrderByStatementNode*>(it->get());
            orderByNode->sortSpecs.push_back(std::move(spec));
            break;
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitOffsetClause(GQLParser::OffsetClauseContext* ctx) {
    OrderByStatementNode* orderByNode = nullptr;
    
    // Find last OrderByStatementNode in root children
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::ORDER_BY_STATEMENT) {
            orderByNode = static_cast<OrderByStatementNode*>(it->get());
            break;
        }
    }
    
    if (!orderByNode) {
        // Create new one if not found
        auto newNode = std::make_unique<OrderByStatementNode>();
        orderByNode = newNode.get();
        root->children.push_back(std::move(newNode));
    }
    
    // Extract offset expression (nonNegativeIntegerSpecification)
    if (ctx->nonNegativeIntegerSpecification()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "OFFSET";
        exprNode->value = ctx->nonNegativeIntegerSpecification()->getText();
        orderByNode->offset = std::move(exprNode);
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLimitClause(GQLParser::LimitClauseContext* ctx) {
    OrderByStatementNode* orderByNode = nullptr;
    
    // Find last OrderByStatementNode in root children
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::ORDER_BY_STATEMENT) {
            orderByNode = static_cast<OrderByStatementNode*>(it->get());
            break;
        }
    }
    
    if (!orderByNode) {
        // Create new one if not found
        auto newNode = std::make_unique<OrderByStatementNode>();
        orderByNode = newNode.get();
        root->children.push_back(std::move(newNode));
    }
    
    // Extract limit expression (nonNegativeIntegerSpecification)
    if (ctx->nonNegativeIntegerSpecification()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "LIMIT";
        exprNode->value = ctx->nonNegativeIntegerSpecification()->getText();
        orderByNode->limit = std::move(exprNode);
    }
    
    return nullptr;
}

// Phase 3: Data modifying statement visitors
antlrcpp::Any ASTBuilder::visitLinearDataModifyingStatement(GQLParser::LinearDataModifyingStatementContext* ctx) {
    if (ctx->ambientLinearDataModifyingStatement()) {
        visit(ctx->ambientLinearDataModifyingStatement());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAmbientLinearDataModifyingStatement(GQLParser::AmbientLinearDataModifyingStatementContext* ctx) {
    // Visit simple data accessing statements
    for (auto* stmt : ctx->simpleDataAccessingStatement()) {
        visit(stmt);
    }
    // Visit primitive result statement if present
    if (ctx->primitiveResultStatement()) {
        visit(ctx->primitiveResultStatement());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSimpleDataAccessingStatement(GQLParser::SimpleDataAccessingStatementContext* ctx) {
    if (ctx->simpleQueryStatement()) {
        visit(ctx->simpleQueryStatement());
    }
    if (ctx->primitiveDataModifyingStatement()) {
        visit(ctx->primitiveDataModifyingStatement());
    }
    if (ctx->callProcedureStatement()) {
        visit(ctx->callProcedureStatement());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSimpleQueryStatement(GQLParser::SimpleQueryStatementContext* ctx) {
    if (ctx->primitiveQueryStatement()) {
        visit(ctx->primitiveQueryStatement());
    }
    if (ctx->callProcedureStatement()) {
        visit(ctx->callProcedureStatement());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPrimitiveDataModifyingStatement(GQLParser::PrimitiveDataModifyingStatementContext* ctx) {
    // Handle INSERT statement
    if (ctx->INSERT()) {
        auto insertNode = std::make_unique<InsertStatementNode>();
        InsertStatementNode* insertNodePtr = insertNode.get();
        root->children.push_back(std::move(insertNode));
        
        if (ctx->insertGraphPattern()) {
            visit(ctx->insertGraphPattern());
        }
    }
    // Handle SET statement
    else if (ctx->SET()) {
        auto setNode = std::make_unique<SetStatementNode>();
        SetStatementNode* setNodePtr = setNode.get();
        root->children.push_back(std::move(setNode));
        
        // Visit set items
        for (auto* setItem : ctx->setItem()) {
            visit(setItem);
        }
    }
    // Handle REMOVE statement
    else if (ctx->REMOVE()) {
        auto removeNode = std::make_unique<RemoveStatementNode>();
        RemoveStatementNode* removeNodePtr = removeNode.get();
        root->children.push_back(std::move(removeNode));
        
        // Visit remove items
        for (auto* removeItem : ctx->removeItem()) {
            visit(removeItem);
        }
    }
    // Handle DELETE statement
    else if (ctx->DELETE()) {
        auto deleteNode = std::make_unique<DeleteStatementNode>();
        
        // Check for DETACH or NODETACH
        if (ctx->DETACH()) {
            deleteNode->detach = true;
        } else if (ctx->NODETACH()) {
            deleteNode->nodetach = true;
        }
        
        // Extract value expressions to delete
        for (auto* valueExpr : ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "DELETE_TARGET";
            exprNode->value = valueExpr->getText();
            deleteNode->expressions.push_back(std::move(exprNode));
        }
        
        root->children.push_back(std::move(deleteNode));
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitInsertGraphPattern(GQLParser::InsertGraphPatternContext* ctx) {
    // Visit insert path patterns
    for (auto* insertPathPattern : ctx->insertPathPattern()) {
        visit(insertPathPattern);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitInsertPathPattern(GQLParser::InsertPathPatternContext* ctx) {
    // Pattern: insertNodePattern (insertEdgePattern insertNodePattern)*
    // Visit first node pattern
    if (!ctx->insertNodePattern().empty()) {
        visit(ctx->insertNodePattern(0));
    }
    // Visit edge-node pairs
    for (size_t i = 0; i < ctx->insertEdgePattern().size(); i++) {
        visit(ctx->insertEdgePattern(i));
        // Each edge is followed by a node (index i+1 since first node is at index 0)
        if (i + 1 < ctx->insertNodePattern().size()) {
            visit(ctx->insertNodePattern(i + 1));
        }
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitInsertNodePattern(GQLParser::InsertNodePatternContext* ctx) {
    // Create node pattern for insertion
    if (ctx->insertElementPatternFiller()) {
        auto nodePattern = std::make_unique<NodePatternNode>();
        
        // Extract variable and labels from insertElementPatternFiller
        auto filler = ctx->insertElementPatternFiller();
        if (filler->elementVariableDeclaration()) {
            auto varDecl = filler->elementVariableDeclaration();
            if (varDecl->elementVariable() && varDecl->elementVariable()->bindingVariable()) {
                nodePattern->variable = varDecl->elementVariable()->bindingVariable()->getText();
            }
        }
        
        // Extract labels from labelAndPropertySetSpecification
        if (filler->labelAndPropertySetSpecification()) {
            auto labelSpec = filler->labelAndPropertySetSpecification();
            if (labelSpec->labelSetSpecification()) {
                // For now, extract as text - proper parsing would handle label sets
                std::string labelText = labelSpec->labelSetSpecification()->getText();
                if (!labelText.empty()) {
                    nodePattern->labels.push_back(labelText);
                }
            }
        }
        
        // Add to last InsertStatementNode
        for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
            if ((*it)->type == ASTNode::INSERT_STATEMENT) {
                InsertStatementNode* insertNode = static_cast<InsertStatementNode*>(it->get());
                insertNode->insertPatterns.push_back(std::move(nodePattern));
                break;
            }
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitInsertEdgePattern(GQLParser::InsertEdgePatternContext* ctx) {
    auto edgePattern = std::make_unique<EdgePatternNode>();
    
    // Determine direction
    if (ctx->LEFT_ARROW_BRACKET() && ctx->RIGHT_BRACKET_MINUS()) {
        edgePattern->direction = "<--";
    } else if (ctx->MINUS_LEFT_BRACKET() && ctx->BRACKET_RIGHT_ARROW()) {
        edgePattern->direction = "-->";
    } else if (ctx->TILDE_LEFT_BRACKET() && ctx->RIGHT_BRACKET_TILDE()) {
        edgePattern->direction = "<->";
    } else {
        edgePattern->direction = "-->";  // Default
    }
    
    // Extract edge filler information
    if (ctx->insertElementPatternFiller()) {
        auto filler = ctx->insertElementPatternFiller();
        if (filler->elementVariableDeclaration()) {
            auto varDecl = filler->elementVariableDeclaration();
            if (varDecl->elementVariable() && varDecl->elementVariable()->bindingVariable()) {
                edgePattern->variable = varDecl->elementVariable()->bindingVariable()->getText();
            }
        }
        if (filler->labelAndPropertySetSpecification()) {
            auto labelSpec = filler->labelAndPropertySetSpecification();
            if (labelSpec->labelSetSpecification()) {
                std::string labelText = labelSpec->labelSetSpecification()->getText();
                if (!labelText.empty()) {
                    edgePattern->labels.push_back(labelText);
                }
            }
        }
    }
    
    // Add to last InsertStatementNode
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::INSERT_STATEMENT) {
            InsertStatementNode* insertNode = static_cast<InsertStatementNode*>(it->get());
            insertNode->insertPatterns.push_back(std::move(edgePattern));
            break;
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSetItem(GQLParser::SetItemContext* ctx) {
    SetStatementNode::SetItem item;
    
    // Extract variable
    if (ctx->bindingVariableReference() && ctx->bindingVariableReference()->bindingVariable()) {
        item.variable = ctx->bindingVariableReference()->bindingVariable()->getText();
    }
    
    // Handle different SET item types
    // Type 1: variable.property = expression
    if (ctx->PERIOD() && ctx->propertyName()) {
        item.type = "PROPERTY";
        item.propertyName = ctx->propertyName()->getText();
        if (ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "VALUE";
            exprNode->value = ctx->valueExpression()->getText();
            item.valueExpression = std::move(exprNode);
        }
    }
    // Type 2: variable = {key: value, ...}
    else if (ctx->LEFT_BRACE()) {
        item.type = "MAP";
        if (ctx->propertyKeyValuePairList()) {
            // For now, store as raw text
            item.propertyMap["raw"] = ctx->propertyKeyValuePairList()->getText();
        }
        if (ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "MAP_VALUE";
            exprNode->value = ctx->valueExpression()->getText();
            item.valueExpression = std::move(exprNode);
        }
    }
    // Type 3: variable:label (label addition)
    else if (ctx->isOrColon() && ctx->labelName()) {
        item.type = "LABEL";
        item.labelName = ctx->labelName()->getText();
    }
    
    // Add to last SetStatementNode
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::SET_STATEMENT) {
            SetStatementNode* setNode = static_cast<SetStatementNode*>(it->get());
            setNode->items.push_back(std::move(item));
            break;
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitRemoveItem(GQLParser::RemoveItemContext* ctx) {
    RemoveStatementNode::RemoveItem item;
    
    // Extract variable
    if (ctx->bindingVariableReference() && ctx->bindingVariableReference()->bindingVariable()) {
        item.variable = ctx->bindingVariableReference()->bindingVariable()->getText();
    }
    
    // Handle different REMOVE item types
    // Type 1: variable.property
    if (ctx->PERIOD() && ctx->propertyName()) {
        item.type = "PROPERTY";
        item.propertyName = ctx->propertyName()->getText();
    }
    // Type 2: variable:label
    else if (ctx->isOrColon() && ctx->labelName()) {
        item.type = "LABEL";
        item.labelName = ctx->labelName()->getText();
    }
    
    // Add to last RemoveStatementNode
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::REMOVE_STATEMENT) {
            RemoveStatementNode* removeNode = static_cast<RemoveStatementNode*>(it->get());
            removeNode->items.push_back(std::move(item));
            break;
        }
    }
    
    return nullptr;
}

// Phase 4: Composite query statement visitors
antlrcpp::Any ASTBuilder::visitCompositeQueryStatement(GQLParser::CompositeQueryStatementContext* ctx) {
    if (ctx->compositeQueryExpression()) {
        visit(ctx->compositeQueryExpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitCompositeQueryExpression(GQLParser::CompositeQueryExpressionContext* ctx) {
    // Handle recursive case: compositeQueryExpression queryConjunction linearQueryStatement
    if (ctx->compositeQueryExpression()) {
        // Build left side recursively
        auto leftResult = visit(ctx->compositeQueryExpression());
        std::unique_ptr<ASTNode> leftNode;
        
        // Extract the node from the result (it should be in root->children)
        // Find the last node that was just added (should be the left side)
        if (!root->children.empty()) {
            leftNode = std::move(root->children.back());
            root->children.pop_back();
        }
        
        // Visit query conjunction to get operator info
        std::string op = "UNION";
        bool distinct = false;
        bool all = false;
        if (ctx->queryConjunction()) {
            // We'll extract operator info in visitQueryConjunction
            // For now, visit it to get the info
            visit(ctx->queryConjunction());
            // The operator info will be stored temporarily - we'll handle it below
        }
        
        // Visit right side (linearQueryStatement)
        visit(ctx->linearQueryStatement());
        std::unique_ptr<ASTNode> rightNode;
        if (!root->children.empty()) {
            rightNode = std::move(root->children.back());
            root->children.pop_back();
        }
        
        // Create composite query node
        auto compositeNode = std::make_unique<CompositeQueryNode>();
        
        // Extract operator from queryConjunction
        if (ctx->queryConjunction()) {
            if (ctx->queryConjunction()->UNION()) {
                op = "UNION";
            } else if (ctx->queryConjunction()->EXCEPT()) {
                op = "EXCEPT";
            } else if (ctx->queryConjunction()->INTERSECT()) {
                op = "INTERSECT";
            } else if (ctx->queryConjunction()->OTHERWISE()) {
                op = "OTHERWISE";
            }
            
            if (ctx->queryConjunction()->setQuantifier()) {
                if (ctx->queryConjunction()->setQuantifier()->DISTINCT()) {
                    distinct = true;
                } else if (ctx->queryConjunction()->setQuantifier()->ALL()) {
                    all = true;
                }
            }
        }
        
        compositeNode->operator_ = op;
        compositeNode->distinct = distinct;
        compositeNode->all = all;
        compositeNode->left = std::move(leftNode);
        compositeNode->right = std::move(rightNode);
        
        root->children.push_back(std::move(compositeNode));
    }
    // Handle base case: linearQueryStatement
    else if (ctx->linearQueryStatement()) {
        visit(ctx->linearQueryStatement());
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitQueryConjunction(GQLParser::QueryConjunctionContext* ctx) {
    // This is called as part of visitCompositeQueryExpression
    // The operator info is extracted there, so we don't need to do anything here
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLinearQueryStatement(GQLParser::LinearQueryStatementContext* ctx) {
    if (ctx->focusedLinearQueryStatement()) {
        visit(ctx->focusedLinearQueryStatement());
    } else if (ctx->ambientLinearQueryStatement()) {
        visit(ctx->ambientLinearQueryStatement());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitFocusedLinearQueryStatement(GQLParser::FocusedLinearQueryStatementContext* ctx) {
    // Handle useGraphClause and simpleQueryStatement+ primitiveResultStatement
    // Also handle selectStatement directly
    if (ctx->selectStatement()) {
        visit(ctx->selectStatement());
    }
    for (auto* stmt : ctx->simpleQueryStatement()) {
        visit(stmt);
    }
    if (ctx->primitiveResultStatement()) {
        visit(ctx->primitiveResultStatement());
    }
    if (ctx->nestedQuerySpecification()) {
        visit(ctx->nestedQuerySpecification());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAmbientLinearQueryStatement(GQLParser::AmbientLinearQueryStatementContext* ctx) {
    // Handle simpleQueryStatement* primitiveResultStatement
    // This is similar to ambientLinearDataModifyingStatement
    for (auto* stmt : ctx->simpleQueryStatement()) {
        visit(stmt);
    }
    if (ctx->primitiveResultStatement()) {
        visit(ctx->primitiveResultStatement());
    }
    if (ctx->nestedQuerySpecification()) {
        visit(ctx->nestedQuerySpecification());
    }
    return nullptr;
}

// Phase 5: SELECT statement visitors
antlrcpp::Any ASTBuilder::visitSelectStatement(GQLParser::SelectStatementContext* ctx) {
    auto selectNode = std::make_unique<SelectStatementNode>();
    
    // Check for DISTINCT
    if (ctx->setQuantifier() && ctx->setQuantifier()->DISTINCT()) {
        selectNode->distinct = true;
    }
    
    // Check for SELECT *
    if (ctx->ASTERISK()) {
        selectNode->selectAll = true;
    }
    
    // Push select node first so visitSelectItem can find it
    root->children.push_back(std::move(selectNode));
    
    // Visit select items (they will add to the select node)
    for (auto* selectItem : ctx->selectItem()) {
        visit(selectItem);
    }
    
    // Visit select statement body (FROM clause)
    if (ctx->selectStatementBody()) {
        visit(ctx->selectStatementBody());
    }
    
    // Visit WHERE clause
    if (ctx->whereClause()) {
        visit(ctx->whereClause());
        // WHERE clause visitor will add to root, we need to attach it to SELECT
        // Find the last WhereClauseNode and attach to SELECT
        for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
            if ((*it)->type == ASTNode::WHERE_CLAUSE) {
                std::unique_ptr<ASTNode> whereNode = std::move(*it);
                root->children.erase(std::next(it).base());
                // Attach to SELECT
                for (auto it2 = root->children.rbegin(); it2 != root->children.rend(); ++it2) {
                    if ((*it2)->type == ASTNode::SELECT_STATEMENT) {
                        SelectStatementNode* selectNode = static_cast<SelectStatementNode*>(it2->get());
                        selectNode->whereClause = std::move(whereNode);
                        break;
                    }
                }
                break;
            }
        }
    }
    
    // GROUP BY and HAVING are already handled by their visitors (they attach to SELECT)
    
    // Visit ORDER BY clause
    if (ctx->orderByClause()) {
        visit(ctx->orderByClause());
        // ORDER BY visitor adds to root, attach to SELECT
        for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
            if ((*it)->type == ASTNode::ORDER_BY_STATEMENT) {
                std::unique_ptr<ASTNode> orderByNode = std::move(*it);
                root->children.erase(std::next(it).base());
                // Attach to SELECT
                for (auto it2 = root->children.rbegin(); it2 != root->children.rend(); ++it2) {
                    if ((*it2)->type == ASTNode::SELECT_STATEMENT) {
                        SelectStatementNode* selectNode = static_cast<SelectStatementNode*>(it2->get());
                        selectNode->orderByClause = std::move(orderByNode);
                        break;
                    }
                }
                break;
            }
        }
    }
    
    // Visit OFFSET and LIMIT
    if (ctx->offsetClause()) {
        visit(ctx->offsetClause());
        // OFFSET is added to OrderByStatementNode, but for SELECT we need to handle it separately
        // For now, it's handled by orderByClause if present
    }
    if (ctx->limitClause()) {
        visit(ctx->limitClause());
        // LIMIT is added to OrderByStatementNode, but for SELECT we need to handle it separately
        // For now, it's handled by orderByClause if present
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSelectItem(GQLParser::SelectItemContext* ctx) {
    if (ctx->aggregatingValueExpression()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "SELECT_ITEM";
        exprNode->value = ctx->aggregatingValueExpression()->getText();
        
        // Check for alias (AS identifier)
        if (ctx->AS() && ctx->identifier()) {
            exprNode->value += " AS " + ctx->identifier()->getText();
        }
        
        // Add to last SelectStatementNode
        for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
            if ((*it)->type == ASTNode::SELECT_STATEMENT) {
                SelectStatementNode* selectNode = static_cast<SelectStatementNode*>(it->get());
                selectNode->selectItems.push_back(std::move(exprNode));
                break;
            }
        }
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSelectStatementBody(GQLParser::SelectStatementBodyContext* ctx) {
    // Handle FROM clause with selectGraphMatch or selectQuerySpecification
    if (ctx->FROM()) {
        // Visit selectGraphMatch items
        for (auto* match : ctx->selectGraphMatch()) {
            visit(match);
        }
        // Visit selectQuerySpecification if present
        if (ctx->selectQuerySpecification()) {
            visit(ctx->selectQuerySpecification());
        }
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSelectGraphMatch(GQLParser::SelectGraphMatchContext* ctx) {
    // Extract match statement from selectGraphMatch
    // selectGraphMatch: graphExpression matchStatement
    if (ctx->matchStatement()) {
        // Find the SelectStatementNode first (it should be the last one)
        SelectStatementNode* selectNode = nullptr;
        for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
            if ((*it)->type == ASTNode::SELECT_STATEMENT) {
                selectNode = static_cast<SelectStatementNode*>(it->get());
                break;
            }
        }
        
        if (selectNode) {
            // Create MatchStatementNode directly for FROM clause
            auto matchNode = std::make_unique<MatchStatementNode>();
            
            // Extract and store graphExpression if present
            if (ctx->graphExpression()) {
                auto graphExprNode = std::make_unique<ExpressionNode>();
                graphExprNode->type = "GRAPH_EXPRESSION";
                graphExprNode->value = ctx->graphExpression()->getText();
                matchNode->graphExpression = std::move(graphExprNode);
            }
            
            // Check for OPTIONAL keyword
            if (ctx->matchStatement()->OPTIONAL()) {
                matchNode->optional = true;
            }
            
            // Set currentMatchNode so child visitors attach to it
            currentMatchNode = matchNode.get();
            
            // Visit the graph pattern binding table to populate the match node
            if (ctx->matchStatement()->graphPatternBindingTable()) {
                visit(ctx->matchStatement()->graphPatternBindingTable());
            }
            
            // Clear currentMatchNode
            currentMatchNode = nullptr;
            
            // Add to SelectStatementNode's fromMatches (don't add to root)
            selectNode->fromMatches.push_back(std::move(matchNode));
        }
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitGroupByClause(GQLParser::GroupByClauseContext* ctx) {
    auto groupByNode = std::make_unique<GroupByClauseNode>();
    
    // GROUP BY uses bindingVariableReference (not aggregatingValueExpression)
    for (auto* varRef : ctx->bindingVariableReference()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "GROUP_BY";
        exprNode->value = varRef->getText();
        groupByNode->groupingExpressions.push_back(std::move(exprNode));
    }
    
    // Add to last SelectStatementNode
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::SELECT_STATEMENT) {
            SelectStatementNode* selectNode = static_cast<SelectStatementNode*>(it->get());
            selectNode->groupByClause = std::move(groupByNode);
            break;
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitHavingClause(GQLParser::HavingClauseContext* ctx) {
    auto havingNode = std::make_unique<HavingClauseNode>();
    
    if (ctx->searchCondition()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "HAVING";
        exprNode->value = ctx->searchCondition()->getText();
        havingNode->condition = std::move(exprNode);
    }
    
    // Add to last SelectStatementNode
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::SELECT_STATEMENT) {
            SelectStatementNode* selectNode = static_cast<SelectStatementNode*>(it->get());
            selectNode->havingClause = std::move(havingNode);
            break;
        }
    }
    
    return nullptr;
}

// Phase 6: Procedure call visitors
antlrcpp::Any ASTBuilder::visitCallProcedureStatement(GQLParser::CallProcedureStatementContext* ctx) {
    auto procNode = std::make_unique<ProcedureCallNode>();
    
    // Check for OPTIONAL keyword
    if (ctx->OPTIONAL()) {
        procNode->optional = true;
    }
    
    // Visit procedure call to extract name and arguments
    if (ctx->procedureCall()) {
        visit(ctx->procedureCall());
        
        // Extract procedure call info (it should have been added to root or we need to extract it)
        // For now, set a placeholder name
        procNode->name = "procedure_call";
    }
    
    root->children.push_back(std::move(procNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitProcedureCall(GQLParser::ProcedureCallContext* ctx) {
    // Handle two forms:
    // 1. (bindingVariableReference, ...)? nestedProcedureSpecification
    // 2. procedureReference (valueExpression, ...)? yieldClause?
    
    ProcedureCallNode* procNode = nullptr;
    
    // Find or create ProcedureCallNode
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::PROCEDURE_CALL) {
            procNode = static_cast<ProcedureCallNode*>(it->get());
            break;
        }
    }
    
    if (!procNode) {
        // Create new one if not found
        auto newNode = std::make_unique<ProcedureCallNode>();
        procNode = newNode.get();
        root->children.push_back(std::move(newNode));
    }
    
    // Handle form 1: nestedProcedureSpecification
    if (ctx->nestedProcedureSpecification()) {
        visit(ctx->nestedProcedureSpecification());
        // Extract binding variables if present
        for (auto* varRef : ctx->bindingVariableReference()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "PROC_ARG";
            exprNode->value = varRef->getText();
            procNode->arguments.push_back(std::move(exprNode));
        }
    }
    // Handle form 2: procedureReference with arguments
    else if (ctx->procedureReference()) {
        procNode->name = ctx->procedureReference()->getText();
        // Extract value expressions as arguments
        for (auto* valueExpr : ctx->valueExpression()) {
            auto exprNode = std::make_unique<ExpressionNode>();
            exprNode->type = "PROC_ARG";
            exprNode->value = valueExpr->getText();
            procNode->arguments.push_back(std::move(exprNode));
        }
        // Handle yieldClause if present
        if (ctx->yieldClause()) {
            visit(ctx->yieldClause());
        }
    }
    
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitNestedProcedureSpecification(GQLParser::NestedProcedureSpecificationContext* ctx) {
    // Extract procedure name from nestedProcedureSpecification
    // For now, extract as text
    ProcedureCallNode* procNode = nullptr;
    for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
        if ((*it)->type == ASTNode::PROCEDURE_CALL) {
            procNode = static_cast<ProcedureCallNode*>(it->get());
            break;
        }
    }
    
    if (procNode && ctx->getText().length() > 0) {
        // Extract procedure name (simplified - would need proper parsing)
        procNode->name = ctx->getText();
    }
    
    return nullptr;
}

// Phase 7: USE Graph clause visitors
antlrcpp::Any ASTBuilder::visitUseGraphClause(GQLParser::UseGraphClauseContext* ctx) {
    auto useGraphNode = std::make_unique<UseGraphNode>();
    
    // Extract graph expression
    if (ctx->graphExpression()) {
        auto exprNode = std::make_unique<ExpressionNode>();
        exprNode->type = "GRAPH_EXPRESSION";
        exprNode->value = ctx->graphExpression()->getText();
        useGraphNode->graphExpression = std::move(exprNode);
    }
    
    root->children.push_back(std::move(useGraphNode));
    return nullptr;
}

// Phase 8: Expression parsing visitors
antlrcpp::Any ASTBuilder::visitSearchCondition(GQLParser::SearchConditionContext* ctx) {
    // searchCondition is a booleanValueExpression
    if (ctx->booleanValueExpression()) {
        return visit(ctx->booleanValueExpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitBooleanValueExpression(GQLParser::BooleanValueExpressionContext* ctx) {
    // booleanValueExpression is just a valueExpression
    if (ctx->valueExpression()) {
        return visit(ctx->valueExpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitComparisonExprAlt(GQLParser::ComparisonExprAltContext* ctx) {
    // Handle comparison: valueExpression compOp valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "BINARY_OP";
    
    if (ctx->compOp()) {
        exprNode->operator_ = ctx->compOp()->getText();
    }
    
    // Visit left and right operands
    if (ctx->valueExpression().size() >= 2) {
        visit(ctx->valueExpression(0));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->left = std::move(root->children.back());
            root->children.pop_back();
        }
        
        visit(ctx->valueExpression(1));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitConjunctiveExprAlt(GQLParser::ConjunctiveExprAltContext* ctx) {
    // Handle AND: valueExpression AND valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "BINARY_OP";
    exprNode->operator_ = "AND";
    
    // Visit left and right operands
    if (ctx->valueExpression().size() >= 2) {
        visit(ctx->valueExpression(0));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->left = std::move(root->children.back());
            root->children.pop_back();
        }
        
        visit(ctx->valueExpression(1));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitDisjunctiveExprAlt(GQLParser::DisjunctiveExprAltContext* ctx) {
    // Handle OR/XOR: valueExpression (OR | XOR) valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "BINARY_OP";
    
    if (ctx->OR()) {
        exprNode->operator_ = "OR";
    } else if (ctx->XOR()) {
        exprNode->operator_ = "XOR";
    }
    
    // Visit left and right operands
    if (ctx->valueExpression().size() >= 2) {
        visit(ctx->valueExpression(0));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->left = std::move(root->children.back());
            root->children.pop_back();
        }
        
        visit(ctx->valueExpression(1));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPrimaryExprAlt(GQLParser::PrimaryExprAltContext* ctx) {
    // Handle primary expression: valueExpressionPrimary
    if (ctx->valueExpressionPrimary()) {
        return visit(ctx->valueExpressionPrimary());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitValueExpressionPrimary(GQLParser::ValueExpressionPrimaryContext* ctx) {
    auto exprNode = std::make_unique<ExpressionNode>();
    
    // Handle property access: valueExpressionPrimary.propertyName
    if (ctx->PERIOD() && ctx->propertyName()) {
        exprNode->type = "PROPERTY_ACCESS";
        
        // Visit the object (left side of .)
        if (ctx->valueExpressionPrimary()) {
            visit(ctx->valueExpressionPrimary());
            // The object expression should be in root->children now
            // Extract it
            if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
                exprNode->object = std::move(root->children.back());
                root->children.pop_back();
            }
        }
        
        // Extract property name
        if (ctx->propertyName()) {
            exprNode->propertyName = ctx->propertyName()->getText();
        }
    }
    // Handle aggregate function
    else if (ctx->aggregateFunction()) {
        visit(ctx->aggregateFunction());
        return nullptr; // Already added by visitAggregateFunction
    }
    // Handle binding variable reference
    else if (ctx->bindingVariableReference()) {
        visit(ctx->bindingVariableReference());
        return nullptr; // Already added by visitBindingVariableReference
    }
    // Handle literals and other primaries
    else {
        // Check if it's a literal
        std::string text = ctx->getText();
        exprNode->type = "LITERAL";
        exprNode->value = text;
        
        // Try to determine literal type
        if (text == "true" || text == "false") {
            exprNode->literalType = "BOOLEAN";
        } else if (text == "NULL" || text == "null") {
            exprNode->literalType = "NULL";
        } else if (!text.empty() && text[0] == '"') {
            exprNode->literalType = "STRING";
        } else if (!text.empty() && text[0] == '\'') {
            exprNode->literalType = "STRING";
        } else {
            // Try to parse as number
            bool isFloat = text.find('.') != std::string::npos || 
                          text.find('e') != std::string::npos || 
                          text.find('E') != std::string::npos;
            if (isFloat) {
                exprNode->literalType = "FLOAT";
            } else {
                // Check if it's all digits (with optional sign)
                bool isInteger = true;
                size_t start = 0;
                if (!text.empty() && (text[0] == '+' || text[0] == '-')) {
                    start = 1;
                }
                for (size_t i = start; i < text.size(); ++i) {
                    if (!std::isdigit(text[i])) {
                        isInteger = false;
                        break;
                    }
                }
                if (isInteger && text.size() > start) {
                    exprNode->literalType = "INTEGER";
                } else {
                    exprNode->type = "EXPRESSION";
                }
            }
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitBindingVariableReference(GQLParser::BindingVariableReferenceContext* ctx) {
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "VARIABLE";
    
    if (ctx->bindingVariable()) {
        exprNode->value = ctx->bindingVariable()->getText();
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPropertyName(GQLParser::PropertyNameContext* ctx) {
    // Property name is usually extracted as part of property access
    // This visitor is called when propertyName is visited separately
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAddSubtractExprAlt(GQLParser::AddSubtractExprAltContext* ctx) {
    // Handle addition/subtraction: valueExpression (+ | -) valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "BINARY_OP";
    
    // operator_ is a token pointer, not a function
    if (ctx->operator_) {
        exprNode->operator_ = ctx->operator_->getText();
    } else if (ctx->PLUS_SIGN()) {
        exprNode->operator_ = "+";
    } else if (ctx->MINUS_SIGN()) {
        exprNode->operator_ = "-";
    }
    
    // Visit left and right operands
    if (ctx->valueExpression().size() >= 2) {
        visit(ctx->valueExpression(0));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->left = std::move(root->children.back());
            root->children.pop_back();
        }
        
        visit(ctx->valueExpression(1));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitMultDivExprAlt(GQLParser::MultDivExprAltContext* ctx) {
    // Handle multiplication/division: valueExpression (* | /) valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "BINARY_OP";
    
    // operator_ is a token pointer
    if (ctx->operator_) {
        exprNode->operator_ = ctx->operator_->getText();
    } else if (ctx->ASTERISK()) {
        exprNode->operator_ = "*";
    } else if (ctx->SOLIDUS()) {
        exprNode->operator_ = "/";
    }
    
    // Visit left and right operands
    if (ctx->valueExpression().size() >= 2) {
        visit(ctx->valueExpression(0));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->left = std::move(root->children.back());
            root->children.pop_back();
        }
        
        visit(ctx->valueExpression(1));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSignedExprAlt(GQLParser::SignedExprAltContext* ctx) {
    // Handle unary plus/minus: (+ | -) valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "UNARY_OP";
    
    // sign is a token pointer - check token type
    if (ctx->sign) {
        std::string signText = ctx->sign->getText();
        if (signText == "+") {
            exprNode->operator_ = "+";
        } else if (signText == "-") {
            exprNode->operator_ = "-";
        }
    }
    
    // Visit the operand
    if (ctx->valueExpression()) {
        visit(ctx->valueExpression());
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitNotExprAlt(GQLParser::NotExprAltContext* ctx) {
    // Handle NOT: NOT valueExpression
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "UNARY_OP";
    exprNode->operator_ = "NOT";
    
    // Visit the operand
    if (ctx->valueExpression()) {
        visit(ctx->valueExpression());
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->right = std::move(root->children.back());
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitValueFunctionExprAlt(GQLParser::ValueFunctionExprAltContext* ctx) {
    // Handle function calls: valueFunction
    if (ctx->valueFunction()) {
        return visit(ctx->valueFunction());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitValueFunction(GQLParser::ValueFunctionContext* ctx) {
    // Route to specific function types
    if (ctx->numericValueFunction()) {
        return visit(ctx->numericValueFunction());
    }
    // Add other function types as needed (datetime, string, list, etc.)
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitNumericValueFunction(GQLParser::NumericValueFunctionContext* ctx) {
    // numericValueFunction is for non-aggregate numeric functions
    // Aggregate functions are handled by visitAggregateFunction
    // For now, extract as text
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "FUNCTION_CALL";
    exprNode->value = ctx->getText();
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAggregateFunction(GQLParser::AggregateFunctionContext* ctx) {
    // Handle aggregate functions: COUNT, SUM, AVG, MIN, MAX, etc.
    auto exprNode = std::make_unique<ExpressionNode>();
    exprNode->type = "FUNCTION_CALL";
    
    // Extract function name from tokens
    // Grammar: COUNT(*), or (AVG|COUNT|MAX|MIN|SUM|...) (valueExpression)
    if (ctx->COUNT()) {
        exprNode->value = "COUNT";
    } else if (ctx->SUM()) {
        exprNode->value = "SUM";
    } else if (ctx->AVG()) {
        exprNode->value = "AVG";
    } else if (ctx->MAX()) {
        exprNode->value = "MAX";
    } else if (ctx->MIN()) {
        exprNode->value = "MIN";
    } else if (ctx->STDDEV_POP()) {
        exprNode->value = "STDDEV_POP";
    } else if (ctx->STDDEV_SAMP()) {
        exprNode->value = "STDDEV_SAMP";
    } else if (ctx->PERCENTILE_CONT()) {
        exprNode->value = "PERCENTILE_CONT";
    } else if (ctx->PERCENTILE_DISC()) {
        exprNode->value = "PERCENTILE_DISC";
    } else if (ctx->COLLECT_LIST()) {
        exprNode->value = "COLLECT_LIST";
    }
    
    // Handle COUNT(*)
    if (ctx->ASTERISK()) {
        auto asteriskNode = std::make_unique<ExpressionNode>();
        asteriskNode->type = "LITERAL";
        asteriskNode->value = "*";
        asteriskNode->literalType = "ASTERISK";
        exprNode->arguments.push_back(std::move(asteriskNode));
    }
    
    // Extract arguments from valueExpression (returns pointer, not vector)
    if (ctx->valueExpression()) {
        visit(ctx->valueExpression());
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->arguments.push_back(std::move(root->children.back()));
            root->children.pop_back();
        }
    }
    
    // Handle PERCENTILE functions with two arguments
    if (ctx->numericValueExpression().size() >= 2) {
        visit(ctx->numericValueExpression(0));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->arguments.push_back(std::move(root->children.back()));
            root->children.pop_back();
        }
        visit(ctx->numericValueExpression(1));
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            exprNode->arguments.push_back(std::move(root->children.back()));
            root->children.pop_back();
        }
    }
    
    root->children.push_back(std::move(exprNode));
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitElementPropertySpecification(GQLParser::ElementPropertySpecificationContext* ctx) {
    // Parse property map: {key: value, key2: value2}
    if (ctx->propertyKeyValuePairList()) {
        visit(ctx->propertyKeyValuePairList());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPropertyKeyValuePairList(GQLParser::PropertyKeyValuePairListContext* ctx) {
    // Visit all property key-value pairs
    for (auto* pair : ctx->propertyKeyValuePair()) {
        visit(pair);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPropertyKeyValuePair(GQLParser::PropertyKeyValuePairContext* ctx) {
    // Parse a single property key-value pair: propertyName: valueExpression
    std::string key;
    if (ctx->propertyName()) {
        key = ctx->propertyName()->getText();
    }
    
    // Find the current node pattern to attach properties to
    // This should be called from within visitElementPattern
    NodePatternNode* currentNode = nullptr;
    if (currentMatchNode && !currentMatchNode->patterns.empty()) {
        auto& lastPattern = currentMatchNode->patterns.back();
        if (lastPattern->type == ASTNode::NODE_PATTERN) {
            currentNode = static_cast<NodePatternNode*>(lastPattern.get());
        }
    } else {
        // Also check root->children for standalone node patterns
        for (auto it = root->children.rbegin(); it != root->children.rend(); ++it) {
            if ((*it)->type == ASTNode::NODE_PATTERN) {
                currentNode = static_cast<NodePatternNode*>(it->get());
                break;
            }
        }
    }
    
    // Visit the value expression
    if (ctx->valueExpression()) {
        visit(ctx->valueExpression());
        if (!root->children.empty() && root->children.back()->type == ASTNode::EXPRESSION) {
            auto valueExpr = std::move(root->children.back());
            root->children.pop_back();
            
            if (currentNode && !key.empty()) {
                // Store as expression node in properties map
                // For now, store the text representation
                if (valueExpr->type == ASTNode::EXPRESSION) {
                    auto* expr = static_cast<ExpressionNode*>(valueExpr.get());
                    currentNode->properties[key] = expr->value;
                } else {
                    // Fallback: use the expression's text representation
                    std::string exprText = ctx->valueExpression()->getText();
                    currentNode->properties[key] = exprText;
                }
            }
        }
    }
    
    return nullptr;
}



