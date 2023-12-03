#pragma once

#include <vector>

#include "declaration.hpp"
#include "expression.hpp"
#include "lexer.hpp"
#include "program.hpp"


using namespace std;

class Parser {
private:
  vector<Token> m_tokens;
  size_t m_index = 0;

public:
  Parser(vector<Token> tokens);
  Program parse();

private:
  Declaration parse_declaration();
  Expression Parser::parse_expression();
  Token peek(int offset = 0);
  Token consume();
  Token try_consume();
};