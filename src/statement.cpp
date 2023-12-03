#include "statement.hpp"
#include <iostream>

// IfStatement

IfStatement::IfStatement(Expression condition, Block block) {
  m_type = StatementType::IF;
  m_condition = condition;
  m_block = block;
}

void IfStatement::print() {
  cout << "If " << endl;
  m_condition.print();
  m_block.print();
}

// IfElseStatement

IfElseStatement::IfElseStatement(Expression condition, Block ifBlock,
                                 Block elseBlock) {
  m_type = StatementType::IF_ELSE;
  m_condition = condition;
  m_ifBlock = ifBlock;
  m_elseBlock = elseBlock;
}

void IfElseStatement::print() {
  cout << "If " << endl;
  m_condition.print();
  m_ifBlock.print();
  cout << "Else " << endl;
  m_elseBlock.print();
}

// AssignmentStatement

AssignmentStatement::AssignmentStatement(const std::string identifier,
                                         Expression expression) {
  m_type = StatementType::ASSIGNMENT;
  m_identifier = identifier;
  m_expression = expression;
}

void AssignmentStatement::print() {
  cout << "Assignment " << m_identifier << endl;
  m_expression.print();
}

// ReturnStatement

ReturnStatement::ReturnStatement(Expression expression) {
  m_type = StatementType::RETURN;
  m_returnValue = expression;
}

void ReturnStatement::print() {
  cout << "Return " << endl;
  m_returnValue.print();
}

// WhileStatement

WhileStatement::WhileStatement(Expression condition, Block block) {
  m_type = StatementType::WHILE;
  m_condition = condition;
  m_block = block;
}

void WhileStatement::print() {
  cout << "While " << endl;
  m_condition.print();
  m_block.print();
}

// ForStatement

ForStatement::ForStatement(AssignmentStatement initialization,
                           Expression condition, AssignmentStatement increment,
                           Block block) {
  m_type = StatementType::FOR;
  m_initialization = initialization;
  m_condition = condition;
  m_increment = increment;
  m_block = block;
}

void ForStatement::print() {
  cout << "For " << endl;
  m_initialization.print();
  m_condition.print();
  m_increment.print();
  m_block.print();
}

// FunctionCallStatement

FunctionCallStatement::FunctionCallStatement(
    const std::string identifier, std::vector<Expression> arguments) {
  m_type = StatementType::FUNCTION_CALL;
  m_identifier = identifier;
  m_arguments = arguments;
}

void FunctionCallStatement::print() {
  cout << "FunctionCall " << m_identifier << endl;
  for (auto &argument : m_arguments) {
    argument.print();
  }
}
