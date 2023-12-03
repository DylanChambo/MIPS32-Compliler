#include "parser.hpp"
#include "declaration.hpp"
#include "program.hpp"
#include <iostream>

Parser::Parser(vector<Token> tokens) { m_tokens = tokens; }

Program Parser::parse() {
  Program program;
  while (peek().type == TokenType::NONE) {
    Declaration declaration = parse_declaration();
    if (declaration.name() != "") {
      program.addDeclaration(declaration);
    } else {
      cerr << "Invalid declaration" << endl;
      exit(EXIT_FAILURE);
    }
  }
}

/*
Parse Declaration
Eg:
int a;
int a = 0;
int a();
int a(int b, int c);
int a() { return 0; }
void b() {}
*/
Declaration Parser::parse_declaration() {
  Declaration declaration;
  // Get Type
  switch (peek().type) {
  case TokenType::INT:
    declaration.type(Type::INT);
  case TokenType::VOID:
    declaration.type(Type::VOID);
  default:
    return {};
  }
  consume();
  // Get identifier name
  if (peek().type != TokenType::IDENTIFIER) {
    return {};
  }
  declaration.name(consume().value);

  // Check for `int a;`
  if (peek().type == TokenType::SEMICOLON) {
    consume();
    return declaration;
  }

  // Check for `int a = 0;`
  if (peek().type == TokenType::ASSIGN) {
    consume();
    // TODO: Parse expression

    if (peek().type != TokenType::SEMICOLON) {
      return {};
    }
    consume();
    return declaration;
  }

  // Check for Function Declaration`
  if (peek().type == TokenType::LPAREN) {
    consume();
    // TODO: Parse parameters

    if (peek().type != TokenType::RPAREN) {
      return {};
    }
    consume();
    // Just Declaration
    if (peek().type == TokenType::SEMICOLON) {
      consume();
      return declaration;
    }

    // Declaration and Definition
    if (peek().type != TokenType::LCURLY) {
      return {};
    }
    consume();
    // Todo: Parse block

    if (peek().type != TokenType::RCURLY) {
      return {};
    }
    return declaration;
  }
}

Expression Parser::parse_expression() { return {}; }

Token Parser::peek(int offset) {
  if (m_index + offset >= m_tokens.size()) {
    return {};
  }
  return m_tokens[m_index + offset];
}

Token Parser::consume() {}

Token Parser::try_consume() {}
