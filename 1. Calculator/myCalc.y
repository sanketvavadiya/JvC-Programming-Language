%{
	#include <stdio.h>
%}

%token NUMBER 
%token PLUS MINUS MULTIPLICATION DIVISION PERCENTAGE POW MODULO EQUAL_TO
%token INCREMENT DECREMENT EXCLAMATION
%token AND OR XOR LEFT_SHIFT RIGHT_SHIFT 
%token GT_EQ GT LT_EQ LT
%token SEMICOLON COMMA OPEN_BRACKET CLOSE_BRACKET NEWLINE QUESTION_MARK COLON 

%%

SS : SS S | S
   ;

S : E NEWLINE 	{printf ("Answer is: %d\n",$$);}

E : TERNARY {printf("E: %d\n", $$);}
  ;

TERNARY : LOGICAL QUESTION_MARK LOGICAL COLON LOGICAL {$$ = $1 ? $3 : $5; printf("t:%d\n",$1);}
        | LOGICAL                                     {$$ = $1;}
        ;

LOGICAL : LOGICAL OR BITWISE_OPERATIONS                {$$ = $1 || $3;}
        | LOGICAL AND BITWISE_OPERATIONS               {$$ = $1 && $3;}
        | BITWISE_OPERATIONS                           {$$ = $1;}
        ;        

BITWISE_OPERATIONS : BITWISE_OPERATIONS OR RELATIONAL_EXP            {$$ = $1 | $3;}
                   | BITWISE_OPERATIONS XOR RELATIONAL_EXP           {$$ = $1 ^ $3;}
                   | BITWISE_OPERATIONS AND RELATIONAL_EXP           {$$ = $1 & $3;}
                   | RELATIONAL_EXP                                  {$$ = $1;}
                   ;

RELATIONAL_EXP : RELATIONAL_EXP GT_EQ SHIFTS                 {$$ = $1 >= $3;}
               | RELATIONAL_EXP GT SHIFTS                    {$$ = $1 > $3;}
               | RELATIONAL_EXP LT_EQ SHIFTS                 {$$ = $1 <= $3;}
               | RELATIONAL_EXP LT SHIFTS                    {$$ = $1 < $3;}
               | SHIFTS                                      {$$ = $1;}
               ;

SHIFTS : SHIFTS RIGHT_SHIFT ARITHMETIC_EX       {$$ = $1 >> $3;}
       | SHIFTS LEFT_SHIFT ARITHMETIC_EX        {$$ = $1 << $3;}
       | ARITHMETIC_EX                          {$$ = $1;}
       ;

ARITHMETIC_EX : ARITHMETIC_EX MINUS ARITHMETIC_1        {$$ = $1 - $3;}
              | ARITHMETIC_EX PLUS ARITHMETIC_1         {$$ = $1 + $3;}
              | ARITHMETIC_1                            {$$ = $1;}
           ;

ARITHMETIC_1 : ARITHMETIC_1 MULTIPLICATION ARITHMETIC_2     {$$ = $1*$3;}
             | ARITHMETIC_1 DIVISION ARITHMETIC_2           {$$ = $1/$3;}
             | ARITHMETIC_1 MODULO ARITHMETIC_2             {$$ = $1%$3;}
             | ARITHMETIC_1 PERCENTAGE ARITHMETIC_2         {$$ = $1*$3/100;}
             | PLUS NUMBER                                  {$$ = $2;}
             | MINUS NUMBER                                 {$$ = -$2;}
             | INCREMENT NUMBER                             {$$ = $2+1;}
             | DECREMENT NUMBER                             {$$ = $2-1;}
             | ARITHMETIC_2		                              {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 EXCLAMATION 	{$$ = $1; while($1-- > 1) $$ *= $1;}
             | BRACKETS POW ARITHMETIC_2  {$$ = $1; while($3-- > 1) {$$ *= $1;}}
             | NUMBER INCREMENT           {$$ = $1+1;}
             | NUMBER DECREMENT           {$$ = $1-1;}
             | BRACKETS 		              {$$ = $1;}
             ;

BRACKETS : OPEN_BRACKET E CLOSE_BRACKET   {$$ = $2;}
         | ID 		                        {$$ = $1;}
         ;        

ID : NUMBER {$$ = $1;} ;

%%
//Driver Code to Accept user input
int main()
{
  yyparse();
  return 0;
}
