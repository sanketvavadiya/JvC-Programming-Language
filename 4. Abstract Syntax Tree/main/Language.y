%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "Language.h"
%}

%union {
  int i_val;
  float f_val;
  double d_val;
  char c_val;
  char b_val;
  char* str_val;
  char *identifier;
  struct ValueNode *value_node;
  struct DeclarationList *declaration_list;
  struct ExpressionStatement *expression_statement;
  struct DeclarationStatement *declaration_statement;
  struct AssignmentStatement *assignment_statement;
  struct Statement *statement;
  struct IfStatement *if_statement;
  struct WhileStatement *while_statement;
  struct ForStatement *for_statement;
  struct StatementSet *statement_set;
}

%token<i_val> intval
%token<f_val> floatval
%token<d_val> doubleval
%token<c_val> charval
%token<str_val> stringval
%token<identifier> id

%token intdt floatdt doubledt chardt stringdt booleandt
%token plus minus multiplication division exclamation pow1 modulo
%token increment decrement logicalor logicaland
%token equal openbracket closebracket opencurly closecurly
%token gteq gt lt lteq eqeq noteq
%token questionmark colon leftshift rightshift and or xor
%token newline print comma end semicolon
%token true false
%token mainkeyword returnkeyword ifkeyword elifkeyword elsekeyword forkeyword whilekeyword continuekeyword switchkeyword casekeyword breakkeyword defaultkeyword

%type <c_val> BOOLEAN_VAL
%type <i_val> DATATYPE
%type <value_node> VALUE
%type <expression_statement> VALUE_or_ID ARITHMETIC_EX ARITHMETIC_1 ARITHMETIC_2 BRACKETS SHIFTS RELATIONAL_EXP_1 RELATIONAL_EXP_2 BITWISE_OPERATIONS LOGICAL TERNARY EXPRESSION_ST
%type <declaration_list> ID LIST
%type <declaration_statement> DECLARATION_ST
%type <assignment_statement> ASSIGNMENT_ST
%type <statement> STATEMENTS EXP_ASGN_ST_EPS EXP_ASGN_ST
%type <if_statement> IF_CONSTRUCT IF_BLOCK ELIF_BLOCKS
%type <while_statement> WHILE_LOOP
%type <for_statement> FOR_LOOP
%type <statement_set> STATEMENT_SET OPTIONAL_BLOCKS ELSE_BLOCK

%%

PROGRAM : opencurly OPTIONAL_NEWLINE STATEMENT_SET OPTIONAL_NEWLINE closecurly {$3 = reverseStatements($3); /*printStatementSetNode($3, 0);*/ executeProgram($3); showVariables(); exit(0);}
		;

STATEMENT_SET : /* epsilon */                     	 {$$ = NULL;}
			        | STATEMENT_SET STATEMENTS OPTIONAL_NEWLINE 	{$$ = makeStatementSetNode(STATEMENT, $2, $1);}
              | STATEMENT_SET IF_CONSTRUCT OPTIONAL_NEWLINE 		 	 {$$ = makeStatementSetNode(IFSTATEMENT, $2, $1);}
              | STATEMENT_SET WHILE_LOOP OPTIONAL_NEWLINE 			 {$$ = makeStatementSetNode(WHILESTATEMENT, $2, $1);}
              | STATEMENT_SET FOR_LOOP OPTIONAL_NEWLINE			{$$ = makeStatementSetNode(FORSTATEMENT, $2, $1);}
              ;

OPTIONAL_NEWLINE : /* epsilon */
                 | OPTIONAL_NEWLINE newline {line++;}
                 ;

STATEMENTS : EXPRESSION_ST				{$$ = makeStatementNode($1, EXPRESSION);}
		       | DECLARATION_ST 			{$$ = makeStatementNode($1, DECLARATION);}
		       | ASSIGNMENT_ST 				{$$ = makeStatementNode($1, ASSIGNMENT);}
           ;

EXPRESSION_ST : TERNARY {$$ = $1;}
			  ;

DECLARATION_ST : DATATYPE LIST {$$ = makeDeclarationStatementNode($1, $2);}

DATATYPE : intdt      {$$ = INTEGER;}
         | floatdt    {$$ = FLOAT;}
         | doubledt   {$$ = DOUBLE;}
         | chardt     {$$ = CHARACTER;}
         | stringdt   {$$ = STRING;}
         | booleandt  {$$ = BOOLEAN;}
         ;

LIST : ID         	  {$$ = $1;}
     | ID comma LIST  {$1->next=$3; $$ = $1;}
     ;

ID : id       		  {$$ = makeDeclarationListNode($1, NULL);}
   | id equal EXPRESSION_ST {$$ = makeDeclarationListNode($1, $3);}
   ;

ASSIGNMENT_ST : id equal EXPRESSION_ST 				{$$ = makeAssignmentStatementNode($1, "=", $3);}
              | id plus equal EXPRESSION_ST 			{$$ = makeAssignmentStatementNode($1, "+=", $4);}
              | id minus equal EXPRESSION_ST 			{$$ = makeAssignmentStatementNode($1, "-=", $4);}
              | id multiplication equal EXPRESSION_ST {$$ = makeAssignmentStatementNode($1, "*=", $4);}
              | id division equal EXPRESSION_ST 		{$$ = makeAssignmentStatementNode($1, "/=", $4);}
              | id modulo equal EXPRESSION_ST 		{$$ = makeAssignmentStatementNode($1, "%=", $4);}
              ;

IF_CONSTRUCT : IF_BLOCK OPTIONAL_BLOCKS {scope++; $$ = makeIfStatementNode($1, $2, 2); scope--;}
			 ;

IF_BLOCK : ifkeyword openbracket EXPRESSION_ST closebracket OPTIONAL_NEWLINE
		   opencurly OPTIONAL_NEWLINE
		   	STATEMENT_SET
		   closecurly OPTIONAL_NEWLINE {$8 = reverseStatements($8); $$ = makeIfStatementNode($3, $8, 1);}
		 ;

OPTIONAL_BLOCKS : ELIF_BLOCKS ELSE_BLOCK {$$ = makeIfStatementNode($1, $2, 3);}
				;

ELIF_BLOCKS : /* epsilon */ {$$ = NULL;}
			| ELIF_BLOCKS elifkeyword openbracket EXPRESSION_ST closebracket OPTIONAL_NEWLINE
              opencurly OPTIONAL_NEWLINE
              	STATEMENT_SET
              closecurly OPTIONAL_NEWLINE  {$9 = reverseStatements($9); $$ = makeElseifStatementNode($1, $4, $9);}
           ;

ELSE_BLOCK : /* epsilon */ {$$ = NULL;}
		   | elsekeyword OPTIONAL_NEWLINE
			 opencurly OPTIONAL_NEWLINE
			 	STATEMENT_SET
			 closecurly newline {$$ = reverseStatements($5); line++;}
		   ;

WHILE_LOOP : whilekeyword openbracket EXPRESSION_ST closebracket OPTIONAL_NEWLINE
			 opencurly OPTIONAL_NEWLINE
			 	STATEMENT_SET
			 closecurly newline {scope++; $8 = reverseStatements($8); $$ = makeWhileStatementNode($3, $8); scope--; line++;}
			;

FOR_LOOP : forkeyword openbracket EXP_ASGN_ST_EPS semicolon EXP_ASGN_ST semicolon EXP_ASGN_ST closebracket OPTIONAL_NEWLINE
			opencurly OPTIONAL_NEWLINE
				STATEMENT_SET
			closecurly newline {scope++; $12 = reverseStatements($12); $$ = makeForStatementNode($3, $5, $7, $12); scope--; line++;}
		 ;

EXP_ASGN_ST_EPS : /* epsilon */ 	{$$ = NULL;}
				| EXPRESSION_ST				{$$ = makeStatementNode($1, EXPRESSION);}
				| DECLARATION_ST 			{$$ = makeStatementNode($1, DECLARATION);}
				| ASSIGNMENT_ST 				{$$ = makeStatementNode($1, ASSIGNMENT);}
				;

EXP_ASGN_ST : /* epsilon */	{$$ = NULL;}
		    | EXPRESSION_ST {$$ = makeStatementNode($1, EXPRESSION);}
		    | ASSIGNMENT_ST {$$ = makeStatementNode($1, ASSIGNMENT);}
		    ;

TERNARY : LOGICAL questionmark LOGICAL colon LOGICAL {$$ = makeTernaryExpressionNode($1, $3, $5);}
        | LOGICAL                                    {$$ = $1;}
        ;

LOGICAL : LOGICAL logicalor BITWISE_OPERATIONS                {$$ = makeBinaryExpressionNode($1, "||", $3);}
        | LOGICAL logicaland BITWISE_OPERATIONS               {$$ = makeBinaryExpressionNode($1, "&&", $3);}
        | BITWISE_OPERATIONS                                  {$$ = $1;}
        ;

BITWISE_OPERATIONS : BITWISE_OPERATIONS or RELATIONAL_EXP_1     {$$ = makeBinaryExpressionNode($1, "|", $3);}
                   | BITWISE_OPERATIONS xor RELATIONAL_EXP_1    {$$ = makeBinaryExpressionNode($1, "^", $3);}
                   | BITWISE_OPERATIONS and RELATIONAL_EXP_1    {$$ = makeBinaryExpressionNode($1, "&", $3);}
                   | RELATIONAL_EXP_1                           {$$ = $1;}
                   ;

RELATIONAL_EXP_1 : RELATIONAL_EXP_1 gteq RELATIONAL_EXP_2   {$$ = makeBinaryExpressionNode($1, ">=", $3);}
                 | RELATIONAL_EXP_1 gt RELATIONAL_EXP_2     {$$ = makeBinaryExpressionNode($1, ">", $3);}
                 | RELATIONAL_EXP_1 lteq RELATIONAL_EXP_2   {$$ = makeBinaryExpressionNode($1, "<=", $3);}
                 | RELATIONAL_EXP_1 lt RELATIONAL_EXP_2     {$$ = makeBinaryExpressionNode($1, "<", $3);}
                 | RELATIONAL_EXP_2                         {$$ = $1;}
                 ;

RELATIONAL_EXP_2 : RELATIONAL_EXP_2 eqeq SHIFTS     {$$ = makeBinaryExpressionNode($1, "==", $3);}
                 | RELATIONAL_EXP_2 noteq SHIFTS    {$$ = makeBinaryExpressionNode($1, "!=", $3);}
                 | SHIFTS                           {$$ = $1;}
                 ;

SHIFTS : SHIFTS rightshift ARITHMETIC_EX       	{$$ = makeBinaryExpressionNode($1, ">>", $3);}
       | SHIFTS leftshift ARITHMETIC_EX        	{$$ = makeBinaryExpressionNode($1, "<<", $3);}
       | ARITHMETIC_EX                          {$$ = $1;}
       ;

ARITHMETIC_EX : ARITHMETIC_EX minus ARITHMETIC_1        {$$ = makeBinaryExpressionNode($1, "-", $3);}
              | ARITHMETIC_EX plus ARITHMETIC_1         {$$ = makeBinaryExpressionNode($1, "+", $3);}
              | ARITHMETIC_1                            {$$ = $1;}
              ;

ARITHMETIC_1 : ARITHMETIC_1 multiplication ARITHMETIC_2     {$$ = makeBinaryExpressionNode($1, "*", $3);}
             | ARITHMETIC_1 division ARITHMETIC_2           {$$ = makeBinaryExpressionNode($1, "/", $3);}
             | ARITHMETIC_1 modulo ARITHMETIC_2             {$$ = makeBinaryExpressionNode($1, "%", $3);}
             | plus ARITHMETIC_EX                           {$$ = makeUnaryExpressionNode("+", '1', $2);}
             | minus ARITHMETIC_EX                          {$$ = makeUnaryExpressionNode("-", '1', $2);}
             | increment VALUE_or_ID                       	{$$ = makeUnaryExpressionNode("++", '1', $2);}
             | decrement VALUE_or_ID                      	{$$ = makeUnaryExpressionNode("--", '1', $2);}
             | ARITHMETIC_2                                 {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 exclamation     	{$$ = makeUnaryExpressionNode("!", '0', $1);}
             | BRACKETS pow1 ARITHMETIC_2    	{$$ = makeBinaryExpressionNode($1, "**", $3);}
             | VALUE_or_ID increment            {$$ = makeUnaryExpressionNode("++", '0', $1);}
             | VALUE_or_ID decrement            {$$ = makeUnaryExpressionNode("--", '0', $1);}
             | BRACKETS                     	{$$ = $1;}
             ;

BRACKETS : openbracket ARITHMETIC_EX closebracket     {$$ = $2;}
         | VALUE_or_ID                                {$$ = $1;}
         ;

VALUE_or_ID : id        {$$ = makeExpressionStatementNode($1, NULL);}
            | VALUE     {$$ = makeExpressionStatementNode(NULL, $1);}
            ;

VALUE : intval  { Value *input_value = (Value*) malloc(sizeof(Value)); 
        input_value->i_val = $1; 
        $$ = makeValueNode(INTEGER, input_value);}
      | floatval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->f_val = $1; 
          $$ = makeValueNode(FLOAT, input_value);}
      | doubleval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->d_val = $1; 
          $$ = makeValueNode(DOUBLE, input_value);}
      | charval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->c_val = $1; 
          $$ = makeValueNode(CHARACTER, input_value);}
      | BOOLEAN_VAL { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->b_val = $1; 
          $$ = makeValueNode(BOOLEAN, input_value);}
      | stringval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->str_val = $1; 
          $$ = makeValueNode(STRING, input_value);}
      ;

BOOLEAN_VAL : true  {$$ = '1';}
            | false {$$ = '0';}
            ;

%%
int main() {
	yyparse();
	return 0;
}