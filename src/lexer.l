%{
#include <iostream>
#include <cstdlib>
#include "parser.tab.hpp" // Include the Bison-generated header
using namespace std;
%}

%%

[0-9]+              { yylval.i = atoi(yytext); return NUM; }
[-+()*/]            {return yytext[0];}
[ \t\n\v\n]          { ; }

%%