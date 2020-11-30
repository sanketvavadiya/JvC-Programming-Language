%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}

%%

[s|S][h|H][o|O][w|W]               {return show;}
[a-zA-z]*                          {yylval.id=yytext[0]; return identifier;}
[0-9]+                             {yylval.num=atoi(yytext); return number;}
[\-\+\=\;\*\/]                     {return yytext[0];}

%%
int yywrap (void) {return 1;}