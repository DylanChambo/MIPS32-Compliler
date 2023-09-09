#include "lexer.h"
#include "parser.h"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void compileFile();

int main(int argc, char **argv)
{
    compileFile();
    return 0;
}

void compileFile()
{
    string inputCode = "int main() { if (x > 0) { x = x - 1; } return 0; }";

    Lexer *lexer = new Lexer();

    vector<Token> tokens = lexer->tokenize(inputCode);

    // Print the tokens
    for (const Token &token : tokens)
    {
        cout << "Type: ";
        switch (token.type)
        {
        case KEYWORD:
            cout << "Keyword";
            break;
        case IDENTIFIER:
            cout << "Identifier";
            break;
        case NUMBER:
            cout << "Number";
            break;
        case OPERATOR:
            cout << "Operator";
            break;
        case PUNCTUATOR:
            cout << "Punctuator";
            break;
        default:
            cout << "Unknown";
            break;
        }
        cout << ", Value: " << token.value << endl;
    }

    Parser parser(tokens);
    // Create an example AST
    ASTNode *root = parser.parse();

    parser.generateCode(root);
}