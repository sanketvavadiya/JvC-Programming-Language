%{
	#include<stdio.h>
	#include "y.tab.h"
%}
digit		[0-9]
int 		{digit}+
%%
{int}			{yylval = atoi(yytext); return NUMBER;}

"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return MULTIPLICATION;}
"/"				{return DIVISION;}
"%"				{return PERCENTAGE;}
"!"				{return EXCLAMATION;}
"**" 			{return POW;}
"//"			{return MODULO;}
"++"			{return INCREMENT;}
"--"			{return DECREMENT;}
";"				{return SEMICOLON;}
"="				{return EQUAL_TO;}
"("				{return OPEN_BRACKET;}
")"				{return CLOSE_BRACKET;}
","				{return COMMA;}

">="			{return GT_EQ;}
">"				{return GT;}
"<="			{return LT_EQ;}
"<"				{return LT;}

"?"				{return QUESTION_MARK;}
":"				{return COLON;}

"<<"			{return LEFT_SHIFT;}
">>"			{return RIGHT_SHIFT;}
"&"				{return AND;}
"|"				{return OR;}
"^"				{return XOR;}

[\n]			{return NEWLINE;}

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