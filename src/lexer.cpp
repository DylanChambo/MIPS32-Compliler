#include "lexer.h"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool isWhitespace(char c);
// Function to tokenize C code
vector<Token> tokenize(const string &code)
{
    vector<Token> tokens;
    string currentToken;

    for (char c : code)
    {
        if (isWhitespace(c))
        {
            if (!currentToken.empty())
            {
                Token token;
                token.value = currentToken;

                // Determine token type
                if (find(KEYWORDS.begin(), KEYWORDS.end(), currentToken) != KEYWORDS.end())
                {
                    token.type = KEYWORD;
                }
                else if (currentToken.find_first_not_of("0123456789") == string::npos)
                {
                    // Assume it's a number
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
                if (currentToken.find_first_not_of("0123456789") == string::npos)
                {
                    // Assume it's a number
                    token.type = NUMBER;
                }

                tokens.push_back(token);
                currentToken.clear();
            }

            // Handle operators
            if (c == '=' || c == '<' || c == '>' || c == '+' || c == '-')
            {
                currentToken = c;
                Token token;
                token.value = currentToken;
                token.type = OPERATOR;

                tokens.push_back(token);
                currentToken.clear();
            }
            else if (c == ';' || c == '{' || c == '}' || c == '(' || c == ')')
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

bool isWhitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}