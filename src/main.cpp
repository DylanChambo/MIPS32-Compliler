#include <lexer.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void compileFile(string filename);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return EXIT_FAILURE;
    }

    compileFile(argv[1]);

    return 0;
}

void compileFile(string filename)
{
    // Read the file into memory
    ifstream inputFile(filename);
    std::string contents;
    getline(inputFile, contents, '\0');

    Lexer *lexer = new Lexer(contents);
    vector<Token> tokens = lexer->tokenize();

    // Print the tokens
    for (const Token &token : tokens)
    {
        switch (token.type)
        {
            TOKEN_TYPE_LIST(TOKEN_TYPE_ENUM_CASE)
        }
        if (token.value != "")
            cout << ", Value: " << token.value;
        cout << endl;
    }
}