%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
%}
%token id
%token intdt floatdt doubledt chardt booleandt stringdt voiddt
%token intval floatval doubleval booleanval charval stringval
%token plus minus multiplication division percentage pow1 modulo equal
%token exclamation increment decrement
%token semicolon comma newline singlelinecomment multilinecomment
%token openbracket closebracket opencurly closecurly
%token ifkeyword elifkeyword elsekeyword forkeyword whilekeyword switchkeyword casekeyword defaultkeyword
%token gteq gt lteq lt eqeq noteq
%token pluseq minuseq multiplicationeq divisioneq
%token leftshift rightshift and or xor logicalor logicaland
%token questionmark colon
%token swap mainkeyword returnkeyword continuekeyword breakkeyword

%%
PROGRAM : DATATYPE mainkeyword openbracket closebracket OPTIONAL_NEWLINE
		  opencurly OPTIONAL_NEWLINE
		  	SS
		  closecurly {printf("------MAIN PROGRAM ------\n"); exit(0);};

SS : SS S | S | /*EPSILON*/ ;

S : E newline	| OPTIONAL_NEWLINE
  ;

E : DECLARATION						{printf("declaration\n");}
  | CONDITIONAL_ST					{printf("coditional\n");}
  | LOOPS							{printf("loop\n");}
  | TERNARY							/*{printf("ans: %d\n", $1);}*/
  | SWAPPING 						{printf("swapping\n");}
  | RETURN_ST						{printf("return\n");}
  | ASSIGNMENT 						{printf("assignment\n");}
  | continuekeyword 						{printf("continue\n");}
  | breakkeyword 							{printf("break\n");}
  ;

DECLARATION : DATATYPE LIST ;

CONDITIONAL_ST : IF_BLOCK OPTIONAL_BLOCK | SWITCH_CASES; 

IF_BLOCK : ifkeyword openbracket EXP closebracket OPTIONAL_NEWLINE 
		   opencurly OPTIONAL_NEWLINE 
				SS OPTIONAL_NEWLINE
		   closecurly OPTIONAL_NEWLINE
		   ;

OPTIONAL_BLOCK : ELIF_BLOCKS ELSE_BLOCK ;

ELIF_BLOCKS : ELIF_BLOCK ;

ELIF_BLOCK : /* EPSILON */
		   | elifkeyword openbracket EXP closebracket OPTIONAL_NEWLINE 
			 opencurly OPTIONAL_NEWLINE 
			 	SS OPTIONAL_NEWLINE
		   	 closecurly OPTIONAL_NEWLINE ELIF_BLOCKS	{printf("elif complete\n");}
		   	 ;

ELSE_BLOCK : /* EPSILON */ 
		   | elsekeyword OPTIONAL_NEWLINE 
	   		 opencurly OPTIONAL_NEWLINE 
		  		SS OPTIONAL_NEWLINE
	   		 closecurly	{printf("else complete\n");}
	   		;

SWITCH_CASES : SWITCH_ST SWITCH_BLOCK;

SWITCH_ST : switchkeyword openbracket EXP closebracket ;

SWITCH_BLOCK : OPTIONAL_NEWLINE opencurly OPTIONAL_NEWLINE
					CASES_DEFAULT_BLOCK OPTIONAL_NEWLINE
				closecurly

CASES_DEFAULT_BLOCK : DEFAULT_LAST | /* DEFAULT_BETWEEN */ | DEFAULT_FIRST  ;

DEFAULT_FIRST : DEFAULT_BLOCK CASE_BLOCKS ;

DEFAULT_LAST : CASE_BLOCKS DEFAULT_BLOCK ;

CASE_BLOCKS : casekeyword EXP colon OPTIONAL_NEWLINE
				CASE_STS OPTIONAL_NEWLINE
				BREAK_ST OPTIONAL_NEWLINE
			  CASE_BLOCKS
			| /* EPSILON */
			;

DEFAULT_BLOCK : /* EPSILON */
			  | defaultkeyword colon OPTIONAL_NEWLINE
			    	CASE_STS OPTIONAL_NEWLINE
			    	BREAK_ST OPTIONAL_NEWLINE
			  ;

CASE_STS : SS ;

BREAK_ST : breakkeyword | ;			  			

LOOPS : FOR_LOOP {printf("for complete\n");} | WHILE_LOOP {printf("while complete\n");};

FOR_LOOP : forkeyword openbracket OPTIONAL_INITIALIZATION semicolon CONDITION semicolon OPTIONAL_INCDEC closebracket OPTIONAL_NEWLINE 
		   opencurly OPTIONAL_NEWLINE
		   		SS OPTIONAL_NEWLINE
		   	closecurly ;

WHILE_LOOP : whilekeyword openbracket CONDITION closebracket OPTIONAL_NEWLINE
			 opencurly OPTIONAL_NEWLINE
		   		SS OPTIONAL_NEWLINE
		   	closecurly ;

OPTIONAL_INITIALIZATION : TERNARY | DECLARATION | ASSIGNMENT | /* EPSILON */ ;

CONDITION : EXP

OPTIONAL_INCDEC : TERNARY | ASSIGNMENT | /* EPSILON */ ;

ASSIGNMENT : id equal EXP 
		   | id pluseq EXP
		   | id minuseq EXP
		   | id multiplicationeq EXP
		   | id divisioneq EXP
		   ;

EXP : TERNARY ;

OPTIONAL_NEWLINE : newline | /*ESPILON*/ ;

DATATYPE : intdt
		 | floatdt
		 | doubledt
		 | chardt
		 | booleandt
		 | stringdt
		 | voiddt
		 ;

LIST : id 
	 | id comma LIST
	 | id equal TERNARY 
	 | id equal TERNARY comma LIST
	 ;

TERNARY : LOGICAL questionmark LOGICAL colon LOGICAL {$$ = $1 ? $3 : $5; printf("t:%d\n",$1);}
        | LOGICAL                                     {$$ = $1;}
        ;

LOGICAL : LOGICAL logicalor BITWISE_OPERATIONS                {$$ = $1 || $3;}
        | LOGICAL logicaland BITWISE_OPERATIONS               {$$ = $1 && $3;}
        | BITWISE_OPERATIONS                           {$$ = $1;}
        ;        

BITWISE_OPERATIONS : BITWISE_OPERATIONS or RELATIONAL_EXP_1            {$$ = $1 | $3;}
                   | BITWISE_OPERATIONS xor RELATIONAL_EXP_1           {$$ = $1 ^ $3;}
                   | BITWISE_OPERATIONS and RELATIONAL_EXP_1           {$$ = $1 & $3;}
                   | RELATIONAL_EXP_1                                  {$$ = $1;}
                   ;

RELATIONAL_EXP_1 : RELATIONAL_EXP_1 gteq RELATIONAL_EXP_2                 {$$ = $1 >= $3;}
              	 | RELATIONAL_EXP_1 gt RELATIONAL_EXP_2                    {$$ = $1 > $3;}
               	 | RELATIONAL_EXP_1 lteq RELATIONAL_EXP_2                 {$$ = $1 <= $3;}
               	 | RELATIONAL_EXP_1 lt RELATIONAL_EXP_2                    {$$ = $1 < $3;}
               	 | RELATIONAL_EXP_2                              	 	   {$$ = $1;}
               	 ;

RELATIONAL_EXP_2 : RELATIONAL_EXP_2 eqeq SHIFTS 	{$$ = $1==$3;}
				 | RELATIONAL_EXP_2 noteq SHIFTS 	{$$ = $1!=$3;}
				 | SHIFTS 						  	{$$ = $1;}

SHIFTS : SHIFTS rightshift ARITHMETIC_EX       {$$ = $1 >> $3;}
       | SHIFTS leftshift ARITHMETIC_EX        {$$ = $1 << $3;}
       | ARITHMETIC_EX                          {$$ = $1;}
       ;

ARITHMETIC_EX : ARITHMETIC_EX minus ARITHMETIC_1        {$$ = $1 - $3;}
              | ARITHMETIC_EX plus ARITHMETIC_1         {$$ = $1 + $3;}
              | ARITHMETIC_1                            {$$ = $1;}
           ;

ARITHMETIC_1 : ARITHMETIC_1 multiplication ARITHMETIC_2     {$$ = $1*$3;}
             | ARITHMETIC_1 division ARITHMETIC_2           {$$ = $1/$3;}
             | ARITHMETIC_1 modulo ARITHMETIC_2             {$$ = $1%$3;}
             | ARITHMETIC_1 percentage ARITHMETIC_2         {$$ = $1*$3/100;}
             | plus VALUE                                   {$$ = $2;}
             | minus VALUE                                  {$$ = -$2;}
             | increment VALUE                              {$$ = $2+1;}
             | decrement VALUE                              {$$ = $2-1;}
             | ARITHMETIC_2		                            {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 exclamation 	{$$ = $1; while($1-- > 1) $$ *= $1;}
             | BRACKETS pow1 ARITHMETIC_2  	{$$ = $1; while($3-- > 1) {$$ *= $1;}}
             | VALUE increment           	{$$ = $1+1;}
             | VALUE decrement           	{$$ = $1-1;}
             | BRACKETS 		            {$$ = $1;}
             ;

BRACKETS : openbracket E closebracket   		{$$ = $2;}
         | VALUE 		                        {$$ = $1;}
         ;

SWAPPING : VALUE swap VALUE ;

RETURN_ST : returnkeyword OPTIONAL_EXP

OPTIONAL_EXP : TERNARY

VALUE : intval
	  | floatval
	  | doubleval
	  | charval
	  | booleanval
	  | stringval
	  | id
	  ;

%%
int main()
{
	yyparse();
	return 0;
}
