#pragma once

#include <string>
#include <vector>

using namespace std;
#define TOKEN_TYPE_LIST(E) \
    E(IDENTIFIER)          \
    E(NUMBER)              \
    /* Keywords */         \
    E(INT)                 \
    E(VOID)                \
    E(RETURN)              \
    E(IF)                  \
    E(ELSE)                \
    E(WHILE)               \
    E(FOR)                 \
    /* Operators */        \
    E(ASSIGN)              \
    E(PLUS)                \
    E(MINUS)               \
    E(TIMES)               \
    E(DIVIDE)              \
    E(AND)                 \
    E(BIT_AND)             \
    E(OR)                  \
    E(BIT_OR)              \
    /* Comparisons */      \
    E(EQUALS)              \
    E(NEQUALS)             \
    E(NOT)                 \
    E(GT)                  \
    E(LT)                  \
    E(LTEQ)                \
    E(GTEQ)                \
    /* Punctuation */      \
    E(SEMICOLON)           \
    E(COMMA)               \
    E(LPAREN)              \
    E(RPAREN)              \
    E(LCURLY)              \
    E(RCURLY)              \
    E(LSQUARE)             \
    E(RSQUARE)

#define TOKEN_TYPE_ENUM_DEF(name) name,
#define TOKEN_TYPE_ENUM_CASE(name) \
    case name:                     \
        cout << #name;             \
        break;

enum TokenType
{

    TOKEN_TYPE_LIST(TOKEN_TYPE_ENUM_DEF)
};

struct Token
{
    TokenType type;
    std::string value;


};

bool operator==(const Token& lhs, const Token& rhs);


class Lexer
{
private:
    std::string m_code;
    int m_position = 0;
    int m_char = 1;
    int m_line = 1;

public:
    Lexer(const string &code);
    vector<Token> tokenize();

private:
    char peek(int offset = 0);
    char consume();
};
