%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}
identifier 		 	[a-zA-Z_][a-zA-Z0-9_]*
digit				[0-9]
int 				{digit}+
float				{digit}*"."{digit}{1,7}
double 				{digit}*"."{digit}{8,}
char				['].[']
string 				["].*["]
boolean 			true|false
multilinecomment 	"/*"([^*]|[*][^/])*"*/"

%%
"int"				{return DT_INT;}
"float"				{return DT_FLOAT;}
"double"			{return DT_DOUBLE;}
"char"				{return DT_CHARACTER;}
"boolean"			{return DT_BOOLEAN;}
"string"			{return DT_STRING;}
"void"				{return DT_VOID;}

"main"				{return MAIN;}
"return"			{return RETURN;}

"if"				{return IF;}
"elif"				{return ELIF;}
"else"				{return ELSE;}
"for"				{return FOR;}
"while"				{return WHILE;}
"continue"			{return CONTINUE;}
"switch"			{return SWITCH;}
"case"				{return CASE;}
"break"				{return BREAK;}
"default"			{return DEFAULT;}

{int}				{yylval = atoi(yytext); return INT_VAL;}
{float}				{yylval = (float)atof(yytext); return FLOAT_VAL;}
{double}			{yylval = atof(yytext); return DOUBLE_VAL;}
{char}				{return CHAR_VAL;}
{string}			{return STRING_VAL;}
{boolean}			{return BOOLEAN_VAL;}

{identifier}		{return IDENTIFIER;}
{multilinecomment}	{return MULTILINE_COMMENT;}

"+"					{return PLUS;}
"-"					{return MINUS;}
"*"					{return MULTIPLICATION;}
"/"					{return DIVISION;}
"%"					{return PERCENTAGE;}
"!"					{return EXCLAMATION;}
"**" 				{return POW;}
"//"				{return MODULO;}
"++"				{return INCREMENT;}
"--"				{return DECREMENT;}
";"					{return SEMICOLON;}
"="					{return EQUAL_TO;}
"("					{return OPEN_BRACKET;}
")"					{return CLOSE_BRACKET;}
"{"					{return OPEN_CURLY;}
"}"					{return CLOSE_CURLY;}
","					{return COMMA;}

">="				{return GT_EQ;}
">"					{return GT;}
"<="				{return LT_EQ;}
"<"					{return LT;}
"=="				{return EQ_EQ;}
"!="				{return NOT_EQ;}

"?"					{return QUESTION_MARK;}
":"					{return COLON;}

"<<"				{return LEFT_SHIFT;}
">>"				{return RIGHT_SHIFT;}
"&"					{return AND;}
"|"					{return OR;}
"^"					{return XOR;}

"+="				{return PLUS_EQ;}
"-="				{return MINUS_EQ;}
"*="				{return MULTIPLICATION_EQ;}
"/="				{return DIVISION_EQ;}

"<==>"				{return SWAP;}

"#"					{return SINGLELINE_COMMENT;}

[\n]				{return NEW_LINE;}

%%

int yywrap(void)
{
	return 0;
}
int yyerror(char *errormsg)
{
	fprintf(stderr,"%s\n", errormsg);
	exit(1);
}