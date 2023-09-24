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
    m_line = 1;
}

// Function to tokenize C code
vector<Token> Lexer::tokenize()
{
    vector<Token> tokens;
    string currentToken;
    m_line = 1;

    while (peek() != '\0')
    {
        // If the first character is a alpha character, it is either a keyword or an identifier
        if (isalpha(peek()))
        {
            currentToken.push_back(consume());
            // Keep adding characters till we reach a non-alphanumeric or '_' character
            while (isalnum(peek()) || peek() == '_')
            {
                currentToken.push_back(consume());
            }
            // Check if the string is a keyword
            if (currentToken == "int")
                tokens.push_back({.type = TokenType::INT});
            else if (currentToken == "void")
                tokens.push_back({.type = TokenType::VOID});
            else if (currentToken == "return")
                tokens.push_back({.type = TokenType::RETURN});
            else if (currentToken == "if")
                tokens.push_back({.type = TokenType::IF});
            else if (currentToken == "else")
                tokens.push_back({.type = TokenType::ELSE});
            else if (currentToken == "while")
                tokens.push_back({.type = TokenType::WHILE});
            else if (currentToken == "for")
                tokens.push_back({.type = TokenType::FOR});
            else
                // If it is not a keyword, it must be an identifier
                tokens.push_back({.type = TokenType::IDENTIFIER, .value = currentToken});

            currentToken.clear();
        }

        // If the first token is a digit, it is a number literal
        else if (isdigit(peek()))
        {
            currentToken.push_back(consume());
            // Keep adding numeric character till we reach a non-numeric character
            while (isdigit(peek()))
            {
                currentToken.push_back(consume());
            }
            // Add the number literal token
            tokens.push_back({.type = TokenType::NUMBER, .value = currentToken});
            currentToken.clear();
        }

        // Check for different operators
        else if (peek() == '=')
        {
            consume();
            // Check if the next character is '='
            if (peek() == '=') // ==
            {
                consume();
                tokens.push_back({.type = TokenType::EQUALS});
            }
            else // =
            {
                tokens.push_back({.type = TokenType::ASSIGN});
            }
        }
        else if (peek() == '+')
        {
            consume();
            tokens.push_back({.type = TokenType::PLUS});
        }
        else if (peek() == '-')
        {
            consume();
            tokens.push_back({.type = TokenType::MINUS});
        }
        else if (peek() == '*')
        {
            consume();
            tokens.push_back({.type = TokenType::TIMES});
        }
        else if (peek() == '/')
        {
            consume();
            if (peek() == '/')
            {
                // Consume the rest of the line as it is a comment
                while (peek() != '\n' && peek() != '\0')
                {
                    consume();
                }
                if (consume() == '\n')
                    m_line += 1;
            }
            else
            {
                tokens.push_back({.type = TokenType::DIVIDE});
            }
        }
        else if (peek() == '&')
        {
            consume();
            if (peek() == '&') // &&
            {
                consume();
                tokens.push_back({.type = TokenType::AND});
            }
            else // &
            {
                tokens.push_back({.type = TokenType::BIT_AND});
            }
        }
        else if (peek() == '|')
        {
            consume();
            if (peek() == '|') // ||
            {
                consume();
                tokens.push_back({.type = TokenType::OR});
            }
            else // |
            {
                tokens.push_back({.type = TokenType::BIT_OR});
            }
        }
        else if (peek() == '!')
        {
            consume();
            if (peek() == '=') // !=
            {
                consume();
                tokens.push_back({.type = TokenType::NEQUALS});
            }
            else // !
            {
                tokens.push_back({.type = TokenType::NOT});
            }
        }
        else if (peek() == '>')
        {
            consume();
            if (peek() == '=') // >=
            {
                consume();
                tokens.push_back({.type = TokenType::GTEQ});
            }
            else // >
            {
                tokens.push_back({.type = TokenType::GT});
            }
        }
        else if (peek() == '<')
        {
            consume();
            if (peek() == '=') // <=
            {
                consume();
                tokens.push_back({.type = TokenType::LTEQ});
            }
            else // <
            {
                tokens.push_back({.type = TokenType::LT});
            }
        }
        else if (peek() == ';')
        {
            consume();
            tokens.push_back({.type = TokenType::SEMICOLON});
        }
        else if (peek() == ',')
        {
            consume();
            tokens.push_back({.type = TokenType::COMMA});
        }
        else if (peek() == '(')
        {
            consume();
            tokens.push_back({.type = TokenType::LPAREN});
        }
        else if (peek() == ')')
        {
            consume();
            tokens.push_back({.type = TokenType::RPAREN});
        }
        else if (peek() == '{')
        {
            consume();
            tokens.push_back({.type = TokenType::LCURLY});
        }
        else if (peek() == '}')
        {
            consume();
            tokens.push_back({.type = TokenType::RCURLY});
        }
        else if (peek() == '[')
        {
            consume();
            tokens.push_back({.type = TokenType::LSQUARE});
        }
        else if (peek() == ']')
        {
            consume();
            tokens.push_back({.type = TokenType::RSQUARE});
        }
        // if current char is whitespace consume it
        else if (isspace(peek()))
        {
            if (consume() == '\n')

                m_line += 1;
        }
        else
        {
            cerr << "Error parsing input code at position " << m_position << endl;
            exit(EXIT_FAILURE);
        }
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