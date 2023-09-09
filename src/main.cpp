#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "parser.tab.hpp"

using namespace std;

void compileFile();

int main(int argc, char **argv)
{
    yyparse();
    compileFile();
    return 0;
}

void compileFile()
{
    string inputCode = "int main() { if (x > 0) { x = x - 1; } return 0; }";
    return;
}