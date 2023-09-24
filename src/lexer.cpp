#include "lexer.h"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

Lexer::Lexer(const string &code)
{
    m_code = code;
}

// Function to tokenize C code
vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;
    string currentToken;

    while (peek() != '\0')
    {
        printf("Char: %c\n", consume());
    }

    return tokens;
}

char Lexer::peek(int offset)
{
    if (m_position + offset >= m_code.length())
    {
        return '\0';
    }
    return m_code[m_position + offset];
}

char Lexer::consume()
{
    return m_code[m_position++];
}