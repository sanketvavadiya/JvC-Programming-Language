%{
    void yyerror(char *s);
    #include <stdio.h>
    #include <stdlib.h>
    int symbols[52];
    int symbolVal(char symbol);
    void updateSymbolVal(char symbol,int val);  
%}
%union {int num;char id;}
%start line
%token show
%token <num> number
%token <id> identifier
%type <num> line exp term
%type <id> assignment

%%
line    : assignment ';'        {;}
        | show exp ';'          {printf("showing : %d\n",$2);}
        | line assignment ';'   {;}
        | line show exp ';'     {printf("showing : %d\n",$3);}
        ;

assignment: identifier '=' exp  {updateSymbolVal($1,$3);}
        ;

exp     : term                  {$$ = $1;}
        | exp '+' term          {$$ = $1 + $3;}
        | exp '-' term          {$$ = $1 - $3;}
        | exp '*' term          {$$ = $1 * $3;}
        | exp '/' term          {$$ = $1 / $3;}
        ;

term    : number                {$$ = $1;}
        | identifier            {$$ = symbolVal($1);}
        ;
%%
int computerSymbolIndex(char token)
{
    int idx=-1;
    if(islower(token))
    {
        idx=token-'a'+26;
    }
    else if(isupper(token))
    {
        idx = token - 'A';
    }
    return idx;
}
int symbolVal(char symbol)
{
    int bucket = computerSymbolIndex(symbol);
    return symbols[bucket];
}
void updateSymbolVal(char symbol,int val)
{
    int bucket = computerSymbolIndex(symbol);
    symbols[bucket] = val;
}
int main (void) {
    printf("Created By BoxWeb Inc\n");
    int i;
    for(i=0;i<52;i++)
    {
        symbols[i]=0;
    }
    return yyparse();
}
void yyerror (char *s) {printf("-%s at %s !\n",s );}