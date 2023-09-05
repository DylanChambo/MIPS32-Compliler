#include <lexer.h>

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char **argv)
{
    string inputCode = "int main() { if (x > 0) { x = x - 1; } return 0; }";
    vector<Token> tokens = tokenize(inputCode);

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

    return 0;
}