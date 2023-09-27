#pragma once

#include <string>
#include <vector>
using namespace std;

enum Type { INT, VOID };

class Declaration {
private:
  string m_name;
  Type m_type;

public:
  Declaration(){}; // default constructor
  Declaration(string name, Type type);
  string name();
  void name(string name);
  Type type();
  void type(Type type);
};

class FunctionDeclaration : public Declaration {
private:
  vector<Declaration> m_parameters;

public:
  FunctionDeclaration(string name, Type type, vector<Declaration> parameters,
                      Block block = {});
  FunctionDeclaration(Declaration d, vector<Declaration> parameters,
                      Block block = {});
};

class VariableDeclaration : public Declaration {
private:
  Expression m_expression;

public:
  VariableDeclaration(string name, Type type, Expression expression);
  VariableDeclaration(Declaration d, Expression expression);
};