#include "parser.h"
#include <vector>
#include <iostream>

using namespace std;

Parser::Parser(const vector<Token> &tokens)
{
    this->tokens = tokens;
    this->currentPos = 0;
}

ASTNode *Parser::parse()
{
    ASTNode *root = new ASTNode{BLOCK, "Root"};
    while (this->currentPos < tokens.size())
    {
        ASTNode *statement = this->parseStatement();
        root->children.push_back(statement);
    }
    return root;
}

ASTNode *Parser::parseStatement()
{
    cout << "Parse statement" << endl;
    Token token = tokens[currentPos];
    if (token.type == KEYWORD)
    {
        if (token.value == "int")
        {
            return parseDeclaration();
        }
        if (token.value == "char")
        {
            return parseDeclaration();
        }
        if (token.value == "void")
        {
            return parseDeclaration();
        }
        if (token.value == "if")
        {
        }
        if (token.value == "else")
        {
        }
        if (token.value == "return")
        {
        }
        if (token.value == "while")
        {
        }
        if (token.value == "break")
        {
        }
        else
        {
            throw "Unknown keyword: " + token.value;
        }
    }
    else if (token.type == PUNCTUATOR)
    {
        if (token.value == ")")
        {
            return nullptr;
        }
    }
    else if (token.type == IDENTIFIER)
    {
        return parseAssignment();
    }
    else
    {
        throw "Unknown token type: " + token.type;
    }
}

ASTNode *Parser::parseDeclaration()
{
    ASTNode *declaration = new ASTNode{DECLARATION, "Declaration"};
    currentPos++;
    if (tokens[currentPos].type == IDENTIFIER)
    {
        declaration->children.push_back(new ASTNode{IDENTIFIER_NODE, tokens[currentPos].value});
        currentPos++;
        // Variable
        if (tokens[currentPos].type == OPERATOR and tokens[currentPos].value == "=")
        {
            declaration->children.push_back(parseExpression());
            return declaration;
        }
        else if (tokens[currentPos].type == PUNCTUATOR)
        {
            // if end of declaration
            if (tokens[currentPos].value == "," || tokens[currentPos].value == ")" || tokens[currentPos].value == ";")
            {
                return declaration;
            }
            // Function
            if (tokens[currentPos].value == "(")
            {
                while (tokens[currentPos].value != ")")
                {
                    currentPos++;
                    ASTNode *temp = parseStatement();
                    if (temp != nullptr)
                    {
                        declaration->children.push_back(temp);
                    }
                }
                currentPos++;
                if (tokens[currentPos].value == ";")
                {
                    return declaration;
                }
                else if (tokens[currentPos].value == "{")
                {
                    while (tokens[currentPos].value != "}")
                    {
                        currentPos++;
                        ASTNode *temp = parseStatement();
                        if (temp != nullptr)
                        {
                            declaration->children.push_back(temp);
                        }
                    }
                    currentPos++;
                    return declaration;
                }
                else
                {
                    throw "Missing semicolon or opening curly brace";
                }
            }
            if (tokens[currentPos].value == "(")
            {
                declaration->children.push_back(parseDeclaration());
                return declaration;
            }
            // Array definition
            // else if (tokens[currentPos].value == "[")
            // {
            // }
            else
            {
                throw "Missing opening parenthesis";
            }
        }
        else
        {
            throw "Missing opening parenthesis";
        }
    }
    throw invalid_argument("Missing identifier");
}

ASTNode *Parser::parseAssignment()
{
    cout << "Parse assignment" << endl;
    ASTNode *assignment = new ASTNode{ASSIGNMENT, "Assignment"};
    if (tokens[currentPos].type == IDENTIFIER)
    {
        assignment->children.push_back(new ASTNode{IDENTIFIER_NODE, tokens[currentPos].value});
        currentPos++;
        if (tokens[currentPos].type == ASSIGNMENT)
        {
            if (tokens[currentPos].value == "=")
            {
                assignment->children.push_back(new ASTNode{ASSIGNMENT, "="});
                assignment->children.push_back(parseExpression());
                return assignment;
            }
        }
    }
    throw invalid_argument("Missing identifier");
}

ASTNode *Parser::parseExpression()
{
    cout << "Parse expression" << endl;
    ASTNode *expression = new ASTNode{BINARY_OPERATION, tokens[currentPos].value};
    expression->children.push_back(parseTerm());
    while (tokens[currentPos].type == OPERATOR)
    {
        ASTNode *binary_operation = new ASTNode{BINARY_OPERATION, tokens[currentPos].value};
        currentPos++;
        binary_operation->children.push_back(parseTerm());
        expression->children.push_back(binary_operation);
    }
    return expression;
}

ASTNode *Parser::parseTerm()
{
    cout << "Parse term" << endl;
    ASTNode *term = new ASTNode{BINARY_OPERATION, tokens[currentPos].value};
    term->children.push_back(parseFactor());
    while (tokens[currentPos].value == "*" || tokens[currentPos].value == "/")
    {
        ASTNode *binary_operation = new ASTNode{BINARY_OPERATION, tokens[currentPos].value};
        currentPos++;
        binary_operation->children.push_back(parseFactor());
        term->children.push_back(binary_operation);
    }
    return term;
}

ASTNode *Parser::parseFactor()
{
    cout << "Parse factor" << endl;
    if (tokens[currentPos].type == IDENTIFIER || tokens[currentPos].type == NUMBER)
    {
        ASTNode *identifier = new ASTNode{IDENTIFIER_NODE, tokens[currentPos].value};
        currentPos++;
        cout << "Return factor" << endl;
        return identifier;
    }
    else if (tokens[currentPos].type == PUNCTUATOR)
    {
        if (tokens[currentPos].value == "(")
        {
            currentPos++;
            ASTNode *expression = parseExpression();
            if (tokens[currentPos].value == ")")
            {
                currentPos++;
                cout << "Return factor" << endl;
                return expression;
            }
            else
            {
                throw "Missing closing parenthesis";
            }
        }
    }

    throw "Unknown token type: " + tokens[currentPos].type;
}

// Function to generate MIPS code from the AST (simplified)
void Parser::generateCode(ASTNode *node)
{
    if (node == nullptr)
    {
        return;
    }

    switch (node->type)
    {
    case BLOCK:
        for (ASTNode *child : node->children)
        {
            generateCode(child);
        }
        break;
    case DECLARATION:
        // Generate MIPS code for variable declaration
        cout << "Declare variable: " << node->children[0]->value << endl;
        if (node->children.size() >= 2)
        {
            generateCode(node->children[1]);
        }
        break;
    case ASSIGNMENT:
        // Generate MIPS code for assignment
        cout << "Assign: " << node->children[0]->value << " = ";
        generateCode(node->children[1]);
        cout << endl;
        break;
    case BINARY_OPERATION:
        // Generate MIPS code for binary operation
        generateCode(node->children[0]);
        cout << " " << node->value << " ";
        generateCode(node->children[1]);
        break;
    case IDENTIFIER_NODE:
        cout << node->value;
        break;
    case NUMBER_NODE:
        cout << node->value;
        break;
    default:
        break;
    }
}