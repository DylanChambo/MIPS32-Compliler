#include "expression.hpp"
#include <iostream>

// Expression
Expression::Expression() {}
ExpressionType Expression::type() { return m_type; }
void Expression::type(ExpressionType type) { m_type = type; }

// Identifier
Identifier::Identifier(const std::string value) {
  m_type = IDENTIFIER;
  m_value = value;
}

void Identifier::print() { cout << m_value; }

// Constant
Constant::Constant(const std::string value) {
  m_type = CONSTANT;
  m_value = value;
}
void Constant::print() { cout << m_value; }

// Operation
Operation::Operation(const TokenType operation, const Expression left,
                     const Expression right) {
  m_type = OPERATION;
  m_operation = operation;
  m_left = left;
  m_right = right;
}

void Operation::print() {
  cout << "(";
  m_left.print();
  cout << " ";
  switch (m_operation) { TOKEN_TYPE_LIST(TOKEN_TYPE_ENUM_CASE) }
  cout << " ";
  m_right.print();
  cout << ")";
}