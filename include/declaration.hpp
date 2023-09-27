#pragma once

#include <string>
#include <vector>
using namespace std;

enum Type { INT, VOID };

class Declaration {
private:
  string m_name;
  Type m_type;

protected:
  bool m_is_function = false;

public:
  Declaration(){}; // default constructor
  Declaration(string name, Type type);
  string name();
  void name(string name);
  Type type();
  void type(Type type);
  bool is_function();
};

class FunctionDeclaration : public Declaration {
private:
  vector<Declaration> m_parameters;

public:
  FunctionDeclaration(string name, Type type, vector<Declaration> parameters);
  FunctionDeclaration(Declaration d, vector<Declaration> parameters);
};

// class VariableDeclaration : public Declaration {
// private:
//   Expression m_expression;

// public:
//   FunctionDeclaration(string name, Type type, Expression expression);
//   FunctionDeclaration(Declaration d, Expression expression);
// };