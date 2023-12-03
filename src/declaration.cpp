#include "declaration.hpp"
#include <iostream>

// Basic Declaration
Declaration::Declaration(string name, Type type) {
  m_name = name;
  m_type = Type::INT;
}
string Declaration::name() { return m_name; }
void Declaration::name(string name) { m_name = name; }
Type Declaration::type() { return m_type; }
void Declaration::type(Type type) { m_type = type; }

// Function Declaration
FunctionDeclaration::FunctionDeclaration(string name, Type type,
                                         vector<Declaration> parameters,
                                         Block block)
    : Declaration(name, type) {

  m_parameters = parameters;
  m_block = block;
}

FunctionDeclaration::FunctionDeclaration(Declaration d,
                                         vector<Declaration> parameters,
                                         Block block)
    : Declaration(d.name(), d.type()) {
  m_parameters = parameters;
  m_block = block;
}

void FunctionDeclaration::block(Block block) { m_block = block; }

void FunctionDeclaration::print() {
  cout << "Function: " << name() << endl;
  cout << "  Parameters: " << endl;
  for (auto parameter : m_parameters) {
    parameter.print();
  }
  cout << "  Block: " << endl;
  m_block.print();
}

// Variable Declaration
VariableDeclaration::VariableDeclaration(string name, Type type,
                                         Expression expression)
    : Declaration(name, type) {
  m_expression = expression;
}

VariableDeclaration::VariableDeclaration(Declaration d, Expression expression)
    : Declaration(d.name(), d.type()) {
  m_expression = expression;
}

void VariableDeclaration::print() {
  cout << "Variable: " << name() << endl;
  cout << "  Expression: " << endl;
  m_expression.print();
}