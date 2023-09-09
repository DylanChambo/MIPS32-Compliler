#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <string>
#include <vector>

using namespace std;

// Node types for the parse tree
enum NodeType
{
    ASSIGNMENT,
    BINARY_OPERATION,
    IDENTIFIER_NODE,
    NUMBER_NODE,
    STATEMENT,
    DECLARATION,
    BLOCK
};
// Abstract Syntax Tree (AST) Node
struct ASTNode
{
    NodeType type;
    string value;
    vector<ASTNode *> children;
};

class Parser
{
private:
    vector<Token> tokens;
    size_t currentPos;

public:
    Parser(const vector<Token> &tokens);
    ASTNode *parse();
    void generateCode(ASTNode *node);

private:
    bool match(TokenType expected);
    ASTNode *parseStatement();
    ASTNode *parseDeclaration();
    ASTNode *parseAssignment();
    ASTNode *parseExpression();
    ASTNode *parseFactor();
    ASTNode *parseTerm();
};

#endif