#include "lexer.h"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool isWhitespace(char c);
// Function to tokenize C code
vector<Token> Lexer::tokenize(const string &code)
{
    vector<Token> tokens;
    string currentToken;

    for (char c : code)
    {
        if (this->isWhitespace(c))
        {
            if (!currentToken.empty())
            {
                Token token;
                token.value = currentToken;

                // Determine token type
                if (this->isKeyword(currentToken))
                {
                    token.type = KEYWORD;
                }
                else if (this->isNumber(currentToken))
                {
                    token.type = NUMBER;
                }
                else
                {
                    // Assume it's an identifier
                    token.type = IDENTIFIER;
                }

                tokens.push_back(token);
            }
            currentToken.clear();
        }
        else if (isalnum(c) || c == '_')
        {
            currentToken += c;
        }
        else
        {
            if (!currentToken.empty())
            {
                Token token;
                token.value = currentToken;
                token.type = IDENTIFIER; // Assume it's an identifier
                if (this->isNumber(currentToken))
                {
                    // Assume it's a number
                    token.type = NUMBER;
                }

                tokens.push_back(token);
                currentToken.clear();
            }
            // Handle operators
            if (this->isOperator(c))
            {
                currentToken = c;
                Token token;
                token.value = currentToken;
                token.type = OPERATOR;

                tokens.push_back(token);
                currentToken.clear();
            }
            // Handle Punctuators
            else if (this->isPunctuator(c))
            {
                currentToken = c;
                Token token;
                token.value = currentToken;
                token.type = PUNCTUATOR;

                tokens.push_back(token);
                currentToken.clear();
            }
        }
    }
    return tokens;
}

bool Lexer::isWhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

bool Lexer::isOperator(char c)
{
    return (c == '=' || c == '<' || c == '>' || c == '+' || c == '-');
}

bool Lexer::isPunctuator(char c)
{
    return (c == ';' || c == '{' || c == '}' || c == '(' || c == ')' || c == ',');
}

bool Lexer::isNumber(const string &token)
{
    return (token.find_first_not_of("0123456789") == string::npos);
}

bool Lexer::isKeyword(const string &token)
{
    return (find(KEYWORDS.begin(), KEYWORDS.end(), token) != KEYWORDS.end());
}