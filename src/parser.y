%{
#include <iostream>
extern int yylex();
void yyerror(char *msg);
using namespace std;
%}

%union {
	int i;
}

%token <i> NUM
%type <i> E

%%

S : E { cout << "Result " << $1 << endl; }
;

E: NUM
    | E '+' E { $$ = $1 + $3; }
    | E '-' E { $$ = $1 - $3; }
    | E '*' E { $$ = $1 * $3; }
    | E '/' E { $$ = $1 / $3; }
    ;

%%

void yyerror(char *msg) {
	cerr << "Error: " << msg << endl;
	exit(1);
}