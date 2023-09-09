#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

using namespace std;

enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    OPERATOR,
    NUMBER,
    PUNCTUATOR,
    SEMICOLON,
};

struct Token
{
    TokenType type;
    string value;
};

class Lexer
{
public:
    vector<Token> tokenize(const string &input);

private:
    bool isWhitespace(char c);
    bool isOperator(char c);
    bool isPunctuator(char c);
    bool isKeyword(const string &token);
    bool isNumber(const string &token);
};

const vector<string> KEYWORDS = {
    "auto",
    "int",
    "struct",
    "break",
    "else",
    "switch",
    "case",
    "enum",
    "register",
    "typedef",
    "char",
    "extern",
    "return",
    "const",
    "unsigned",
    "continue",
    "for",
    "signed",
    "void",
    "default",
    "if",
    "while",
    "do",
    "goto",
    "sizeof",
};

#endif