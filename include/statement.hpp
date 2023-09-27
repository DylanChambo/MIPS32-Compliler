#include "declaration.hpp"
#include <vector>

enum StatementType {
  IF,
  IF_ELSE,
  ASSIGNMENT,
  RETURN,
  WHILE,
  FOR,
  FUNCTION_CALL
};

class Statement {
private:
  StatementType m_type;

public:
  Statement(){};
  Statement(StatementType type);
  StatementType type();
  void type(StatementType type);
};

class IfStatement : public Statement {
private:
  Expression m_condition;
  Block m_block;

public:
  IfStatement(Expression condition, Block block);
};

class IfElseStatement : public Statement {};

class AssignmentStatement : public Statement {
private:
  Expression m_expression;
  string m_identifier;

public:
  AssignmentStatement(string identifier, Expression expression);
  string identifier();
  void identifier(string identifier);
  Expression expression();
  void expression(Expression expression);
};

class ReturnStatement : public Statement {
private:
  Expression m_expression;

public:
  ReturnStatement(Expression expression);
  Expression expression();
  void expression(Expression expression);
};

class WhileStatement : public Statement {};
class ForStatement : public Statement {};
class FunctionCallStatement : public Statement {};