%{
#include <iostream>
using namespace std;

int lineNum = 1;
extern char* yytext; // The lexeme of the current token.
extern int yylex();
void yyerror(char *msg);
%}

%require "3.2"

%token INDENTIFIER // An identifier. Starting with a letter or underscore, followed by letters, numbers or underscores.
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
}

%type <name> INDENTIFIER;
%type <value> NUMBER;
%type <character> CHARACTER;
%type <text> STRING;
%%

program: declaration_list
;

%%

void yyerror(char *msg) {
	cerr << "Syntax error on line " << lineNum << " : " << msg << endl;
    cerr << "Last token was \"" << yytext << "\"" << endl;
	exit(1);
}