#include "program.hpp"

Program::Program() {}

Program::Program(vector<Declaration> declarations) {
  m_declarations = declarations;
}

vector<Declaration> Program::declarations() { return m_declarations; }

void Program::addDeclaration(Declaration declaration) {
  m_declarations.push_back(declaration);
}

void Program::print() {
  for (auto declaration : m_declarations) {
    declaration.print();
  }
}