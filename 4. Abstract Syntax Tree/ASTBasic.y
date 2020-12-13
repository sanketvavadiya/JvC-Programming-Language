%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <string.h>
  #include "ASTBasic.h"
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
  struct Expression *expression;
  struct AssignmentExpression *assignment_expression;
  struct DeclarationExpression *declaration_expression;
  struct ExpressionStatement *expression_statement;
  struct DeclarationList *declaration_list;
  struct Statement *statement;
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
%token equal openbracket closebracket
%token gteq gt lt lteq eqeq noteq
%token questionmark colon leftshift rightshift and or xor
%token newline print comma
%token true false
%token end

%type <c_val> BOOLEAN_VAL
%type <i_val> DATATYPE
%type <value_node> VALUE
%type <expression> VALUE_or_ID ARITHMETIC_EX ARITHMETIC_1 ARITHMETIC_2 BRACKETS SHIFTS RELATIONAL_EXP_1 RELATIONAL_EXP_2 BITWISE_OPERATIONS LOGICAL TERNARY
%type <assignment_expression> ASSIGNMENT_EXP
%type <declaration_expression> DECLARATION_EXP
%type <expression_statement> EXPRESSION_ST
%type <declaration_list> ID LIST
%type <statement> STATEMENT_SET

%%

PROGRAM : STATEMENT_SET ;

STATEMENT_SET : /* epsilon */                     {$$ = NULL;}
              | STATEMENT_SET EXPRESSION_ST newline  {$$ = makeStatementNode(EXPRESSION, $2); line++;}
              | OPTIONAL_NEWLINE STATEMENT_SET    {$$ = NULL;}
              | STATEMENT_SET end newline         {$$=NULL; printAST(); line++;}
              ;

OPTIONAL_NEWLINE : /* epsilon */
                 | OPTIONAL_NEWLINE newline {line++;}
                 ;

EXPRESSION_ST : ASSIGNMENT_EXP   {$$ = makeExpressionStatementNode(ASSIGNMENT, $1);}
              | DECLARATION_EXP {$$ = makeExpressionStatementNode(DECLARATION, $1);}
              ;

DECLARATION_EXP : DATATYPE LIST {$$ = makeDeclarationNode($1, $2);}

DATATYPE : intdt    {$$ = INTEGER;}
         | floatdt    {$$ = FLOAT;}
         | doubledt   {$$ = DOUBLE;}
         | chardt     {$$ = CHARACTER;}
         | stringdt   {$$ = STRING;}
         | booleandt  {$$ = BOOLEAN;}
         ;

LIST : ID         {$$ = $1;}
     | ID comma LIST  {$1->next=$3; $$ = $1;}

ID : id       {$$ = makeDeclarationListNode($1, NULL);}
   | id equal TERNARY {$$ = makeDeclarationListNode($1, $3);}              

ASSIGNMENT_EXP : id equal TERNARY {$$ = makeAssignmentNode($1, "=", $3);}
              | id plus equal TERNARY {$$ = makeAssignmentNode($1, "+=", $4);}
              | id minus equal TERNARY {$$ = makeAssignmentNode($1, "-=", $4);}
              | id multiplication equal TERNARY {$$ = makeAssignmentNode($1, "*=", $4);}
              | id division equal TERNARY {$$ = makeAssignmentNode($1, "/=", $4);}
              | id modulo equal TERNARY {$$ = makeAssignmentNode($1, "%=", $4);}
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

SHIFTS : SHIFTS rightshift ARITHMETIC_EX       {$$ = makeBinaryExpressionNode($1, ">>", $3);}
       | SHIFTS leftshift ARITHMETIC_EX        {$$ = makeBinaryExpressionNode($1, "<<", $3);}
       | ARITHMETIC_EX                          {$$ = $1;}
       ;

ARITHMETIC_EX : ARITHMETIC_EX minus ARITHMETIC_1        {$$ = makeBinaryExpressionNode($1, "-", $3);}
              | ARITHMETIC_EX plus ARITHMETIC_1         {$$ = makeBinaryExpressionNode($1, "+", $3);}
              | ARITHMETIC_1                            {$$ = $1;}
              ;

ARITHMETIC_1 : ARITHMETIC_1 multiplication ARITHMETIC_2     {$$ = makeBinaryExpressionNode($1, "*", $3);}
             | ARITHMETIC_1 division ARITHMETIC_2           {$$ = makeBinaryExpressionNode($1, "/", $3);}
             | ARITHMETIC_1 modulo ARITHMETIC_2             {$$ = makeBinaryExpressionNode($1, "%", $3);}
             | plus ARITHMETIC_EX                            {$$ = makeUnaryExpressionNode("+", '1', $2);}
             | minus ARITHMETIC_EX                           {$$ = makeUnaryExpressionNode("-", '1', $2);}
             | increment VALUE_or_ID                       {$$ = makeUnaryExpressionNode("++", '1', $2);}
             | decrement VALUE_or_ID                       {$$ = makeUnaryExpressionNode("--", '1', $2);}
             | ARITHMETIC_2                                 {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 exclamation     {$$ = makeUnaryExpressionNode("!", '0', $1);}
             | BRACKETS pow1 ARITHMETIC_2    {$$ = makeBinaryExpressionNode($1, "pow", $3);}
             | VALUE_or_ID increment              {$$ = makeUnaryExpressionNode("++", '0', $1);}
             | VALUE_or_ID decrement              {$$ = makeUnaryExpressionNode("--", '0', $1);}
             | BRACKETS                     {$$ = $1;}
             ;

BRACKETS : openbracket ARITHMETIC_EX closebracket     {$$ = $2;}
         | VALUE_or_ID                                {$$ = $1;}
         ;

VALUE_or_ID : id        {$$ = makeExpressionNode($1, NULL);}
            | VALUE     {$$ = makeExpressionNode(NULL, $1);}
            ;

VALUE : intval  { Value *input_value = (Value*) malloc(sizeof(Value)); 
        input_value->i_val = $1; 
        $$ = makeValueNode(INTEGER, input_value);}
      | floatval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->f_val = $1; 
          $$ = makeValueNode(FLOAT, input_value);}
      | doubleval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->d_val = $1; 
          $$ = makeValueNode(DOUBLE, input_value); }
      | charval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->c_val = $1; 
          $$ = makeValueNode(CHARACTER, input_value); }
      | BOOLEAN_VAL { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->b_val = $1; 
          $$ = makeValueNode(BOOLEAN, input_value); }
      | stringval { Value *input_value = (Value*) malloc(sizeof(Value)); 
          input_value->str_val = $1; 
          $$ = makeValueNode(STRING, input_value); }
      ;

BOOLEAN_VAL : true  {$$ = '1';}
            | false {$$ = '0';}
            ;

%%
int main() {
  yyparse();
  return 0;
}