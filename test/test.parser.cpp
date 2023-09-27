#include "../include/block.hpp"
#include "../include/declaration.hpp"
#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include "../lib/catch.hpp"
#include <fstream>

TEST_CASE("Test Lexer Read File", "") {
  ifstream inputFile("./test/test_files/test1.c");
  std::string contents;
  getline(inputFile, contents, '\0');

  Lexer lexer(contents);
  vector<Token> tokens = lexer.tokenize();

  Parser parser(tokens);
  Program program = parser.parse();

  Program expected_output = {vector<Declaration>{FunctionDeclaration(
      "main", Type::INT, vector<Declaration>{},
      Block(
          vector<Declaration>{VariableDeclaration(
              "x", Type::INT, Expression(ExpressionType::CONSTANT, "0"))},
          vector<Statement>{
              IfStatement(
                  Expression(TokenType::GT,
                             Expression(ExpressionType::IDENTIFIER, "x"),
                             Expression(ExpressionType::CONSTANT, "0")),
                  Block({},
                        vector<Statement>{AssignmentStatement(
                            "x",
                            Expression(
                                TokenType::MINUS,
                                Expression(ExpressionType::IDENTIFIER, "x"),
                                Expression(ExpressionType::CONSTANT, "1")))})),
              ReturnStatement(Expression(ExpressionType::CONSTANT, "0"))}))}};

  REQUIRE(program.declarations.size() == 2);
}