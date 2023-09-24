#include <lexer.h>

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

    Lexer *lexer = new Lexer(inputCode);

    vector<Token> tokens = lexer->tokenize();

    // Print the tokens
    for (const Token &token : tokens)
    {
        cout << "Type: " << token.type << endl;
        cout << ", Value: " << token.value << endl;
    }
}