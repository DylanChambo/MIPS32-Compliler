#include "../lib/catch.hpp"
#include "../include/lexer.hpp"
#include <fstream>

vector<Token> expectedTokens = {
        Token{.type = TokenType::INT},
        Token{.type = TokenType::IDENTIFIER, .value = "main"},
        Token{.type = TokenType::LPAREN},
        Token{.type = TokenType::RPAREN},
        Token{.type = TokenType::LCURLY},
        Token{.type = TokenType::INT},
        Token{.type = TokenType::IDENTIFIER, .value = "x"},
        Token{.type = TokenType::ASSIGN},
        Token{.type = TokenType::NUMBER, .value = "0"},
        Token{.type = TokenType::SEMICOLON},
        Token{.type = TokenType::IF},
        Token{.type = TokenType::LPAREN},
        Token{.type = TokenType::IDENTIFIER, .value = "x"},
        Token{.type = TokenType::GT},
        Token{.type = TokenType::NUMBER, .value = "0"},
        Token{.type = TokenType::RPAREN},
        Token{.type = TokenType::LCURLY},
        Token{.type = TokenType::IDENTIFIER, .value = "x"},
        Token{.type = TokenType::ASSIGN},
        Token{.type = TokenType::IDENTIFIER, .value = "x"},
        Token{.type = TokenType::MINUS},
        Token{.type = TokenType::NUMBER,.value = "1"},
        Token{.type = TokenType::SEMICOLON},
        Token{.type = TokenType::RCURLY},
        Token{.type = TokenType::RETURN},
        Token{.type = TokenType::NUMBER, .value = "0"},
        Token{.type = TokenType::SEMICOLON},
        Token{.type = TokenType::RCURLY}
        };

TEST_CASE("Test Lexer Read File", "")
{
    ifstream inputFile("./test/test_files/test1.c");
    std::string contents;
    getline(inputFile, contents, '\0');

    Lexer *lexer = new Lexer(contents);
    vector<Token> tokens = lexer->tokenize();
    // Expected Result

    REQUIRE(tokens.size() == expectedTokens.size());
    REQUIRE(tokens == expectedTokens); 
}

TEST_CASE("Test Comments Ignored", "")
{
    ifstream inputFile("./test/test_files/test1-comments.c");
    std::string contents;
    getline(inputFile, contents, '\0');

    Lexer *lexer = new Lexer(contents);
    vector<Token> tokens = lexer->tokenize();

    REQUIRE(tokens.size() == expectedTokens.size());
    REQUIRE(tokens == expectedTokens);
}
