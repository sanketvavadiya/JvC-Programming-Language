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
boolean 			"true"|"false"
multilinecomment 	"/*"([^*]|[*][^/])*"*/"

%%
"int"				{return intdt;}
"float"				{return floatdt;}
"double"			{return doubledt;}
"char"				{return chardt;}
"boolean"			{return booleandt;}
"string"			{return stringdt;}
"void"				{return voiddt;}

"main"				{return mainkeyword;}
"return"			{return returnkeyword;}

"if"				{return ifkeyword;}
"elif"				{return elifkeyword;}
"else"				{return elsekeyword;}
"for"				{return forkeyword;}
"while"				{return whilekeyword;}
"continue"			{return continuekeyword;}
"switch"			{return switchkeyword;}
"case"				{return casekeyword;}
"break"				{return breakkeyword;}
"default"			{return defaultkeyword;}

{int}				{yylval = atoi(yytext); return intval;}
{float}				{yylval = (float)atof(yytext); return floatval;}
{double}			{yylval = atof(yytext); return doubleval;}
{char}				{return charval;}
{string}			{return stringval;}
{boolean}			{return booleanval;}

{identifier}		{return id;}
{multilinecomment}	{return multilinecomment;}

"+"					{return plus;}
"-"					{return minus;}
"*"					{return multiplication;}
"/"					{return division;}
"%"					{return percentage;}
"!"					{return exclamation;}
"**" 				{return pow1;}
"//"				{return modulo;}
"++"				{return increment;}
"--"				{return decrement;}
";"					{return semicolon;}
"="					{return equal;}
"("					{return openbracket;}
")"					{return closebracket;}
"{"					{return opencurly;}
"}"					{return closecurly;}
","					{return comma;}

">="				{return gteq;}
">"					{return gt;}
"<="				{return lteq;}
"<"					{return lt;}
"=="				{return eqeq;}
"!="				{return noteq;}

"?"					{return questionmark;}
":"					{return colon;}

"||"				{return logicalor;}
"&&"				{return logicaland;}

"<<"				{return leftshift;}
">>"				{return rightshift;}
"&"					{return and;}
"|"					{return or;}
"^"					{return xor;}

"+="				{return pluseq;}
"-="				{return minuseq;}
"*="				{return minuseq;}
"/="				{return divisioneq;}

"<==>"				{return swap;}

"#"					{return singlelinecomment;}

[\n]				{return newline;}

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