#pragma once

#include "declaration.hpp"
#include <vector>

class Program {
private:
  vector<Declaration> m_declarations;

public:
  Program();
  Program(vector<Declaration> declarations);
  vector<Declaration> declarations();
  void addDeclaration(Declaration declaration);
  void print();
};