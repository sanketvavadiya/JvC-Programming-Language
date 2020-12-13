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
string		["][^"]*["]

identifier	[a-zA-Z_][a-zA-Z0-9_]*
%%
"int"						{return intdt;}
"float"						{return floatdt;}
"double"					{return doubledt;}
"char"						{return chardt;}
"string"					{return	stringdt;}
"boolean"					{return booleandt;}
"print"						{return print;}
"end"						{return end;}
"false"			{yylval.b_val='0'; return false;}
"true"			{yylval.b_val='1'; return true;}

{int}			{yylval.i_val = atoi(yytext);return intval;}
{float}			{yylval.f_val = (float)atof(yytext); return floatval;}
{double}		{yylval.d_val = atof(yytext); return doubleval;}
{char}			{yylval.c_val = yytext[1]; return charval;}
{string}		{char* str = strdup(yytext);int n = strlen(yytext); str[n-1] = '\0'; yylval.str_val = str+1;return stringval;}

{identifier}				{yylval.identifier = strdup(yytext); return id;}

"+"					{return plus;}
"-"					{return minus;}
"*"					{return multiplication;}
"/"					{return division;}
"%"					{return modulo;}
"!"					{return exclamation;}
"**" 				{return pow1;}
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