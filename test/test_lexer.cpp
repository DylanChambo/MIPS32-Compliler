#include "../lib/catch.hpp"
#include "../include/lexer.h"
#include <fstream>

TEST_CASE("Test Lexer Read File", "")
{
    ifstream inputFile("./test/test_files/test1.c");
    std::string contents;
    getline(inputFile, contents, '\0');

    Lexer *lexer = new Lexer(contents);
    vector<Token> tokens = lexer->tokenize();

    REQUIRE(tokens.size() == 28);
}

TEST_CASE("Test Comments Ignored", "")
{
    ifstream inputFile("./test/test_files/test2.c");
    std::string contents;
    getline(inputFile, contents, '\0');

    Lexer *lexer = new Lexer(contents);
    vector<Token> tokens = lexer->tokenize();

    REQUIRE(tokens.size() == 28);
}
