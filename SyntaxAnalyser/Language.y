%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
%}
%token IDENTIFIER
%token DT_INT DT_FLOAT DT_DOUBLE DT_CHARACTER DT_BOOLEAN DT_STRING DT_VOID
%token INT_VAL FLOAT_VAL DOUBLE_VAL BOOLEAN_VAL CHAR_VAL STRING_VAL
%token PLUS MINUS MULTIPLICATION DIVISION PERCENTAGE POW MODULO EQUAL_TO
%token EXCLAMATION INCREMENT DECREMENT
%token SEMICOLON COMMA NEW_LINE SINGLELINE_COMMENT MULTILINE_COMMENT
%token OPEN_BRACKET CLOSE_BRACKET OPEN_CURLY CLOSE_CURLY
%token IF ELIF ELSE FOR WHILE SWITCH CASE DEFAULT
%token GT_EQ GT LT_EQ LT EQ_EQ NOT_EQ
%token PLUS_EQ MINUS_EQ MULTIPLICATION_EQ DIVISION_EQ
%token LEFT_SHIFT RIGHT_SHIFT AND OR XOR
%token QUESTION_MARK COLON
%token SWAP MAIN RETURN CONTINUE BREAK

%%
PROGRAM : DATATYPE MAIN OPEN_BRACKET CLOSE_BRACKET OPTIONAL_NEWLINE
		  OPEN_CURLY OPTIONAL_NEWLINE
		  	SS
		  CLOSE_CURLY {printf("------MAIN PROGRAM ------\n"); exit(0);};

SS : SS S | S | /*EPSILON*/ ;

S : E NEW_LINE	| OPTIONAL_NEWLINE
  ;

E : DECLARATION						{printf("declaration\n");}
  | CONDITIONAL_ST					{printf("coditional\n");}
  | LOOPS							{printf("loop\n");}
  | TERNARY							/*{printf("ans: %d\n", $1);}*/
  | SWAPPING 						{printf("swapping\n");}
  | RETURN_ST						{printf("return\n");}
  | SINGLELINE_COMMENT IDENTIFIER	{printf("single line comment\n");}
  | MULTILINE_COMMENT				{printf("multiline comment\n");}
  | ASSIGNMENT 						{printf("assignment\n");}
  | CONTINUE 						{printf("continue\n");}
  | BREAK 							{printf("break\n");}
  ;

DECLARATION : DATATYPE LIST ;

CONDITIONAL_ST : IF_BLOCK OPTIONAL_BLOCK | SWITCH_CASES; 

IF_BLOCK : IF OPEN_BRACKET EXP CLOSE_BRACKET OPTIONAL_NEWLINE 
		   OPEN_CURLY OPTIONAL_NEWLINE 
				SS OPTIONAL_NEWLINE
		   CLOSE_CURLY OPTIONAL_NEWLINE
		   ;

OPTIONAL_BLOCK : ELIF_BLOCKS ELSE_BLOCK ;

ELIF_BLOCKS : ELIF_BLOCK ;

ELIF_BLOCK : /* EPSILON */
		   | ELIF OPEN_BRACKET EXP CLOSE_BRACKET OPTIONAL_NEWLINE 
			 OPEN_CURLY OPTIONAL_NEWLINE 
			 	SS OPTIONAL_NEWLINE
		   	 CLOSE_CURLY OPTIONAL_NEWLINE ELIF_BLOCKS	{printf("elif complete\n");}
		   	 ;

ELSE_BLOCK : /* EPSILON */ 
		   | ELSE OPTIONAL_NEWLINE 
	   		 OPEN_CURLY OPTIONAL_NEWLINE 
		  		SS OPTIONAL_NEWLINE
	   		 CLOSE_CURLY	{printf("else complete\n");}
	   		;

SWITCH_CASES : SWITCH_ST SWITCH_BLOCK;

SWITCH_ST : SWITCH OPEN_BRACKET EXP CLOSE_BRACKET ;

SWITCH_BLOCK : OPTIONAL_NEWLINE OPEN_CURLY OPTIONAL_NEWLINE
					CASES_DEFAULT_BLOCK OPTIONAL_NEWLINE
				CLOSE_CURLY

CASES_DEFAULT_BLOCK : DEFAULT_LAST | /* DEFAULT_BETWEEN */ | DEFAULT_FIRST  ;

DEFAULT_FIRST : DEFAULT_BLOCK CASE_BLOCKS ;

DEFAULT_LAST : CASE_BLOCKS DEFAULT_BLOCK ;

CASE_BLOCKS : CASE EXP COLON OPTIONAL_NEWLINE
				CASE_STS OPTIONAL_NEWLINE
				BREAK_ST OPTIONAL_NEWLINE
			  CASE_BLOCKS
			| /* EPSILON */
			;

DEFAULT_BLOCK : /* EPSILON */
			  | DEFAULT COLON OPTIONAL_NEWLINE
			    	CASE_STS OPTIONAL_NEWLINE
			    	BREAK_ST OPTIONAL_NEWLINE
			  ;

CASE_STS : SS ;

BREAK_ST : BREAK | ;			  			

LOOPS : FOR_LOOP {printf("for complete\n");} | WHILE_LOOP {printf("while complete\n");};

FOR_LOOP : FOR OPEN_BRACKET OPTIONAL_INITIALIZATION SEMICOLON CONDITION SEMICOLON OPTIONAL_INCDEC CLOSE_BRACKET OPTIONAL_NEWLINE 
		   OPEN_CURLY OPTIONAL_NEWLINE
		   		SS OPTIONAL_NEWLINE
		   	CLOSE_CURLY ;

WHILE_LOOP : WHILE OPEN_BRACKET CONDITION CLOSE_BRACKET OPTIONAL_NEWLINE
			 OPEN_CURLY OPTIONAL_NEWLINE
		   		SS OPTIONAL_NEWLINE
		   	CLOSE_CURLY ;

OPTIONAL_INITIALIZATION : TERNARY | DECLARATION | ASSIGNMENT | /* EPSILON */ ;

CONDITION : EXP

OPTIONAL_INCDEC : TERNARY | ASSIGNMENT | /* EPSILON */ ;

ASSIGNMENT : IDENTIFIER EQUAL_TO EXP 
		   | IDENTIFIER PLUS_EQ EXP
		   | IDENTIFIER MINUS_EQ EXP
		   | IDENTIFIER MULTIPLICATION_EQ EXP
		   | IDENTIFIER DIVISION_EQ EXP
		   ;

EXP : TERNARY ;

OPTIONAL_NEWLINE : NEW_LINE | /*ESPILON*/ ;

DATATYPE : DT_INT
		 | DT_FLOAT
		 | DT_DOUBLE
		 | DT_CHARACTER
		 | DT_BOOLEAN
		 | DT_STRING
		 | DT_VOID
		 ;

LIST : IDENTIFIER 
	 | IDENTIFIER COMMA LIST
	 | IDENTIFIER EQUAL_TO TERNARY 
	 | IDENTIFIER EQUAL_TO TERNARY COMMA LIST
	 ;

TERNARY : LOGICAL QUESTION_MARK LOGICAL COLON LOGICAL {$$ = $1 ? $3 : $5; printf("t:%d\n",$1);}
        | LOGICAL                                     {$$ = $1;}
        ;

LOGICAL : LOGICAL OR BITWISE_OPERATIONS                {$$ = $1 || $3;}
        | LOGICAL AND BITWISE_OPERATIONS               {$$ = $1 && $3;}
        | BITWISE_OPERATIONS                           {$$ = $1;}
        ;        

BITWISE_OPERATIONS : BITWISE_OPERATIONS OR RELATIONAL_EXP_1            {$$ = $1 | $3;}
                   | BITWISE_OPERATIONS XOR RELATIONAL_EXP_1           {$$ = $1 ^ $3;}
                   | BITWISE_OPERATIONS AND RELATIONAL_EXP_1           {$$ = $1 & $3;}
                   | RELATIONAL_EXP_1                                  {$$ = $1;}
                   ;

RELATIONAL_EXP_1 : RELATIONAL_EXP_1 GT_EQ RELATIONAL_EXP_2                 {$$ = $1 >= $3;}
              	 | RELATIONAL_EXP_1 GT RELATIONAL_EXP_2                    {$$ = $1 > $3;}
               	 | RELATIONAL_EXP_1 LT_EQ RELATIONAL_EXP_2                 {$$ = $1 <= $3;}
               	 | RELATIONAL_EXP_1 LT RELATIONAL_EXP_2                    {$$ = $1 < $3;}
               	 | RELATIONAL_EXP_2                              	 	   {$$ = $1;}
               	 ;

RELATIONAL_EXP_2 : RELATIONAL_EXP_2 EQ_EQ SHIFTS 	{$$ = $1==$3;}
				 | RELATIONAL_EXP_2 NOT_EQ SHIFTS 	{$$ = $1!=$3;}
				 | SHIFTS 						  	{$$ = $1;}

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
             | PLUS VALUE                                   {$$ = $2;}
             | MINUS VALUE                                  {$$ = -$2;}
             | INCREMENT VALUE                              {$$ = $2+1;}
             | DECREMENT VALUE                              {$$ = $2-1;}
             | ARITHMETIC_2		                            {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 EXCLAMATION 	{$$ = $1; while($1-- > 1) $$ *= $1;}
             | BRACKETS POW ARITHMETIC_2  	{$$ = $1; while($3-- > 1) {$$ *= $1;}}
             | VALUE INCREMENT           	{$$ = $1+1;}
             | VALUE DECREMENT           	{$$ = $1-1;}
             | BRACKETS 		            {$$ = $1;}
             ;

BRACKETS : OPEN_BRACKET E CLOSE_BRACKET   		{$$ = $2;}
         | VALUE 		                        {$$ = $1;}
         ;

SWAPPING : VALUE SWAP VALUE ;

RETURN_ST : RETURN OPTIONAL_EXP

OPTIONAL_EXP : TERNARY

VALUE : INT_VAL
	  | FLOAT_VAL
	  | DOUBLE_VAL
	  | CHAR_VAL
	  | BOOLEAN_VAL
	  | STRING_VAL
	  | IDENTIFIER
	  ;

%%
int main()
{
	yyparse();
	return 0;
}
