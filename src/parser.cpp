#include "parser.hpp"

Parser::Parser(vector<Token> tokens)
{
    this->tokens = tokens;
}

/*
PROGRAM
|-GLOBAL VARS
|-FUNCTIONS
  |-FUNCITON VARS
  |-STATEMENTS

*/

