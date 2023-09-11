%code requires
{
#include "type.h"
}

%{

#include <iostream>
#include <string>
using namespace std;

int lineNum = 1;
extern char* yytext; // The lexeme of the current token.
extern int yylex();
void yyerror(string msg);
%}

%require "3.2"

%token IDENTIFIER // An identifier. Starting with a letter or underscore, followed by letters, numbers or underscores.
%token NUMBER // A number. A sequence of digits.
%token STRING // A string. A sequence of characters surrounded by double quotes.
%token CHARACTER // A character. A single character surrounded by single quotes.

// Keywords
%token INT
%token VOID
%token CHAR
%token IF
%token ELSE
%token WHILE
%token RETURN

// Boolean Operators
%token AND
%token OR

// Brackets
%token LBRACE   /* { */
%token RBRACE   /* } */    
%token LPAR     /* ( */
%token RPAR     /* ) */
%token LBRACK   /* [ */
%token RBRACK   /* ] */

// Seperators
%token SEMICOLON    /* ; */
%token COMMA        /* , */

// Arithmetic Operators
%token PLUS     /* + */
%token MINUS    /* - */
%token TIMES    /* * */
%token DIVIDE   /* / */

// Relational Operators
%token ASSIGN   /* = */
%token EQ       /* == */
%token NEQ      /* != */

// Logical Operators 
%token NOT      /* ! */
%token LT       /* < */
%token LTEQ      /* <= */
%token GT       /* > */
%token GTEQ      /* >= */

%union {
	char* name;
	int value;
	char character;
	char* text;
	int location;
    Type* type;
    Dimensions* dimensions;
}

%type <name> IDENTIFIER;
%type <value> NUMBER;
%type <character> CHARACTER;
%type <text> STRING;
%type <type> baseType type;
%type <dimensions> dimensionsList;

%%

type : baseType { $$ = $1; }
     | baseType dimensionsList { $1->setDimensions($2); $$ = $1; }

baseType : INT { $$ = new Type(TYPE_INT); };
         | CHAR { $$ = new Type(TYPE_CHAR); };
         ;

dimensionsList: dimensionsList LBRACK NUMBER RBRACK { $1->addDimension($3); $$ = $1; };
              | %empty { $$ = new Dimensions(); };

%%

void yyerror(string msg) {
	cerr << "Syntax error on line " << lineNum << " : " << msg << endl;
    cerr << "Last token was \"" << yytext << "\"" << endl;
	exit(1);
}