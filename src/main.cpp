#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "type.h"
#include "parser.tab.hpp"

using namespace std;

void compileFile();

int main(int argc, char **argv)
{
    compileFile();
    return 0;
}

void compileFile()
{
    yyparse();
    return;
}