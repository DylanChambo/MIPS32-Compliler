#include "lexer.hpp"
#include "parser.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void compileFile(string filename);

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <filename>" << endl;
    return EXIT_FAILURE;
  }

  compileFile(argv[1]);

  return 0;
}

void compileFile(string filename) {
  // Read the file into memory
  ifstream inputFile(filename);
  std::string contents;
  getline(inputFile, contents, '\0');

  Lexer *lexer = new Lexer(contents);
  vector<Token> tokens = lexer->tokenize();

  // Print the tokens
  // for (const Token &token : tokens) {
  //   switch (token.type) { TOKEN_TYPE_LIST(TOKEN_TYPE_ENUM_CASE) }
  //   if (token.value != "")
  //     cout << ", Value: " << token.value;
  //   cout << endl;
  // }

  Program expected_output = {vector<Declaration>{FunctionDeclaration(
      "main", Type::INT, vector<Declaration>{},
      Block(vector<Declaration>{VariableDeclaration("x", Type::INT,
                                                    Constant("0"))},
            vector<Statement>{
                IfStatement(
                    Operation(TokenType::GT, Identifier("x"), Constant("0")),
                    Block({},
                          vector<Statement>{AssignmentStatement(
                              "x", Operation(TokenType::MINUS, Identifier("x"),
                                             Constant("1")))})),
                ReturnStatement(Constant("0"))}))}};
  expected_output.print();
}