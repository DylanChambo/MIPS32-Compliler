#pragma once

#include "lexer.hpp"

enum ExpressionType { CONSTANT, IDENTIFIER, OPERATION };

class Expression {
protected:
  ExpressionType m_type;

public:
  Expression();
  ExpressionType type();
  void type(ExpressionType type);
  virtual void print();
};

class Identifier : public Expression {
private:
  std::string m_value;

public:
  Identifier(const std::string value);
  void print();
};

class Constant : public Expression {
private:
  std::string m_value;

public:
  Constant(const std::string value);
  void print();
};

class Operation : public Expression {
private:
  TokenType m_operation;
  Expression m_left;
  Expression m_right;

public:
  Operation(const TokenType operation, const Expression left,
            const Expression right);
  void print();
};