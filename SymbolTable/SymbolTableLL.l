%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}
digit		[0-9]
int 		{digit}+
float		{digit}*"."{digit}{1,7}
double 		{digit}*"."{digit}{8,}
char		"'"[a-zA-Z0-9_]"'"
string		"\""[a-zA-Z0-9_]+"\""

identifier	[a-zA-Z_][a-zA-Z0-9_]*
%%
"int"						{return intdt;}
"float"						{return floatdt;}
"double"					{return doubledt;}
"char"						{return chardt;}
"string"					{return	stringdt;}
"boolean"					{return booleandt;}
"print"						{return print;}
[f|F][a|A][l|L][s|S][e|E]	{yylval=strdup(yytext); return false;}
[t|T][r|R][u|U][e|E]		{yylval=strdup(yytext); return true;}

{int}			{yylval=atoi(yytext); return intval;}
{float}			{float f = (float)atof(yytext); printf("%f\n", f); yylval=f; return floatval;}
{double}		{yylval=atof(yytext); return doubleval;}
{char}			{yylval=strdup(yytext); return charval;}
{string}		{yylval=strdup(yytext); return stringval;}

{identifier}	{yylval=strdup(yytext); return id;}

"+"					{return plus;}
"-"					{return minus;}
"*"					{return multiplication;}
"/"					{return division;}
"%"					{return percentage;}
"!"					{return exclamation;}
"**" 				{return pow;}
"//"				{return modulo;}
"++"				{return increment;}
"--"				{return decrement;}
"="					{return equal;}
"("					{return openbracket;}
")"					{return closebracket;}
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

[\n]				{return newline;}
%%
int yywrap (void) {return 1;}
int yyerror(char *errormsg)
{
	fprintf(stderr,"%s\n", errormsg);
	exit(1);
}