#include "declaration.hpp"

Declaration::Declaration(string name, Type type) {
  m_name = name;
  m_type = Type::INT;
}
string Declaration::name() { return m_name; }
void Declaration::name(string name) { m_name = name; }
Type Declaration::type() { return m_type; }
void Declaration::type(Type type) { m_type = type; }

FunctionDeclaration::FunctionDeclaration(string name, Type type,
                                         vector<Declaration> parameters)
    : Declaration(name, type) {

  m_parameters = parameters;
}

FunctionDeclaration::FunctionDeclaration(Declaration d,
                                         vector<Declaration> parameters)
    : Declaration(d.name(), d.type()) {
  m_parameters = parameters;
}