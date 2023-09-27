#pragma once

enum ExpressionType { CONSTANT, IDENTIFIER, OPERATION };

class Expression {
public:
  Expression(const ExpressionType type, const std::string value);
  Expression(const TokenType operation, const Expression left,
             const Expression right);

private:
};