%{
#include <iostream>
#include <cstdlib>
#include "parser.tab.hpp" // Include the Bison-generated header
using namespace std;
extern int lineNum;
%}

alphaUnderscore [A-Za-z_]
digit [0-9]
alphanumUnderscore [A-Za-z0-9_]

%%
[ \t]   break;    /* ignore whitespace, don't generate tokens */

"//".*"\n"  ++lineNum; /* Ignore comment and everything until end of line; increment lineno variable */

"\n"    ++lineNum; /* increment lineno variable (which is declared in the parser file) */

'\\n' {
	yylval.character = '\n';
	return CHARACTER;
}

'\\t' {
	yylval.character = '\t';
	return CHARACTER;
}

'\\0' {
	yylval.character = '\0';
	return CHARACTER;
}

'[^']' {
    yylval.character = yytext[1];
    return CHARACTER;
}

"int"    return INT;
"void"   return VOID;
"char"   return CHAR;
"if"     return IF;
"else"   return ELSE;
"return" return RETURN;
"while"  return WHILE;

"&&" return AND;
"||" return OR;

"(" return LPAR;
")" return RPAR;
"[" return LBRACK;
"]" return RBRACK;
"{" return LBRACE;
"}" return RBRACE;

";" return SEMICOLON;
"," return COMMA;

"+" return PLUS;
"-" return MINUS;
"*" return TIMES;
"/" return DIVIDE;

"=" return ASSIGN;
"==" return EQ;
"!=" return NEQ;

"!" return NOT;
">" return GT;
"<" return LT;
"<=" return LTEQ;
">=" return GTEQ;

{alphaUnderscore}{alphanumUnderscore}*   {
	yylval.name	= strdup(yytext);
	return IDENTIFIER;
}

{digit}+ {
	yylval.value = atoi(yytext);
	return NUMBER;
}

.  {
	// yytext represents the current characters being lexed
	cerr << "Illegal character with code " << *yytext << " on line #" << lineNum << endl;
	exit(1);
}

%%