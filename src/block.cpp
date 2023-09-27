#include "block.hpp"

Block::Block() {
  m_declarations = {};
  m_statements = {};
}
Block::Block(vector<Declaration> declarations, vector<Statement> statements) {
  m_declarations = declarations;
  m_statements = statements;
}

vector<Declaration> Block::declarations() { return m_declarations; }
void Block::addDeclaration(Declaration declaration) {
  m_declarations.push_back(declaration);
}

vector<Statement> Block::statements() { return m_statements; }
void Block::addStatement(Statement statement) {
  m_statements.push_back(statement);
}