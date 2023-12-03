#include "block.hpp"
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
protected:
  StatementType m_type;

public:
  Statement(){};
  Statement(StatementType type);
  StatementType type();
  void type(StatementType type);
  virtual void print();
};

/*
IfStatement
  - Expression condition
  - Block block
*/
class IfStatement : public Statement {
private:
  Expression m_condition;
  Block m_block;

public:
  IfStatement(Expression condition, Block block);
  void print();
};

/*
IfElseStatement
  - Expression condition
  - Block ifBlock
  - Block elseBlock
*/
class IfElseStatement : public Statement {
private:
  Expression m_condition;
  Block m_ifBlock;
  Block m_elseBlock;

public:
  IfElseStatement(Expression condition, Block ifBlock, Block elseBlock);
  void print();
};

/*
AssignmentStatement
  - string identifier
  - Expression expression
*/
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
  void print();
};

/*
ReturnStatement
  - Expression returnValue
*/
class ReturnStatement : public Statement {
private:
  Expression m_returnValue;

public:
  ReturnStatement(Expression expression);
  Expression returnValue();
  void returnValue(Expression expression);
  void print();
};

/*
WhileStatement
  - Expression condition
  - Block block
*/
class WhileStatement : public Statement {
private:
  Expression m_condition;
  Block m_block;

public:
  WhileStatement(Expression condition, Block block);
  void print();
};

/*
ForStatement
  - AssignmentStatement initialization
  - Expression condition
  - AssignmentStatement increment
  - Block block
*/
class ForStatement : public Statement {
private:
  AssignmentStatement m_initialization;
  Expression m_condition;
  AssignmentStatement m_increment;
  Block m_block;

public:
  ForStatement(AssignmentStatement initialization, Expression condition,
               AssignmentStatement increment, Block block);
  void print();
};

/*
FunctionCallStatement
  - string identifier
  - vector<Expression> arguments
*/
class FunctionCallStatement : public Statement {
private:
  string m_identifier;
  vector<Expression> m_arguments;

public:
  FunctionCallStatement(string identifier, vector<Expression> arguments);
  void print();
};