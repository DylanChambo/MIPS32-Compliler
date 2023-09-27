#pragma once

#include "declaration.hpp"
#include "statement.hpp"
#include <vector>

class Block {
private:
  vector<Declaration> m_declarations;
  vector<Statement> m_statements;

public:
  Block();
  Block(vector<Declaration> declarations, vector<Statement> statements);
  vector<Declaration> declarations();
  void addDeclaration(Declaration declaration);
  vector<Statement> statements();
  void addStatement(Statement statement);
};