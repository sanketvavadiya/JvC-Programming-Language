%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <string.h>
	#include "myLib.h"
	
	// CONSTANTS FOR DATATYPE
	#define INTEGER 1
	#define FLOAT 2
	#define DOUBLE 3
	#define CHARACTER 4
	#define BOOLEAN 5
	#define STRING 6
%}
%union {
	int i_val;
	float f_val;
	double d_val;
	char c_val;
	char b_val;
	char* str_val;
	char *sym_name;
	struct DatatypeAndValue* datatype_and_value_node;
	struct SymbolTable *symbol_table;
}

%token<i_val> intval
%token<f_val> floatval
%token<d_val> doubleval
%token<c_val> charval
%token<str_val> stringval
%token<sym_name> id

%token intdt floatdt doubledt chardt stringdt booleandt
%token plus minus multiplication division exclamation pow1 modulo
%token increment decrement logicalor logicaland
%token equal openbracket closebracket
%token gteq gt lt lteq eqeq noteq
%token questionmark colon leftshift rightshift and or xor
%token newline print comma
%token true false

%type <datatype_and_value_node> VALUE VALUE_or_ID ARITHMETIC_EX ARITHMETIC_1 ARITHMETIC_2 BRACKETS SHIFTS RELATIONAL_EXP_1 RELATIONAL_EXP_2 BITWISE_OPERATIONS LOGICAL TERNARY
%type <symbol_table> ID LIST DECLARATION
%type <c_val> BOOLEAN_VAL
%type <i_val> DATATYPE

%%

SS : SS S | S ;

S : E newline {line++;};

E : DECLARATION 
  | ASSIGNMENTSTATEMENT
  | print       {printAll();}
  | print id  	{printId($2);}
  ;

DECLARATION : DATATYPE LIST {$$ = insertAll($1, $2);}

DATATYPE : intdt 	  {$$ = INTEGER;}
		 | floatdt 	  {$$ = FLOAT;}
		 | doubledt   {$$ = DOUBLE;}
		 | chardt  	  {$$ = CHARACTER;}
		 | stringdt   {$$ = STRING;}
		 | booleandt  {$$ = BOOLEAN;}
		 ;

LIST : ID 				{$$ = $1;}
	 | ID comma LIST	{$1->next=$3; $$ = $1;}

ID : id 		  {$$ = makeSymbolNodeWithoutDatatype($1, NULL);}
   | id equal TERNARY {$$ = makeSymbolNodeWithoutDatatype($1, $3);}

ASSIGNMENTSTATEMENT : id equal TERNARY {assignNewValue($1, $3);}
					| id plus equal TERNARY {assignPlusEqual($1, $4);}
					| id minus equal TERNARY {assignMinusEqual($1, $4);}
					| id multiplication equal TERNARY {assignMultiplicationEqual($1, $4);}
					| id division equal TERNARY {assignDivisionEqual($1, $4);}
					| id modulo equal TERNARY {assignModuloEqual($1, $4);}
					;

TERNARY : LOGICAL questionmark LOGICAL colon LOGICAL {$$ = ternary($1, $3, $5);}
        | LOGICAL                                     {$$ = $1;}
        ;

LOGICAL : LOGICAL logicalor BITWISE_OPERATIONS                {$$ = logicalOR($1, $3);}
        | LOGICAL logicaland BITWISE_OPERATIONS               {$$ = logicalAND($1, $3);}
        | BITWISE_OPERATIONS                                  {$$ = $1;}
        ;   

BITWISE_OPERATIONS : BITWISE_OPERATIONS or RELATIONAL_EXP_1     {$$ = binaryOR($1, $3);}
                   | BITWISE_OPERATIONS xor RELATIONAL_EXP_1    {$$ = binaryXOR($1, $3);}
                   | BITWISE_OPERATIONS and RELATIONAL_EXP_1    {$$ = binaryAND($1, $3);}
                   | RELATIONAL_EXP_1                           {$$ = $1;}
                   ;   

RELATIONAL_EXP_1 : RELATIONAL_EXP_1 gteq RELATIONAL_EXP_2   {$$ = binaryGreaterEqual($1, $3);}
                 | RELATIONAL_EXP_1 gt RELATIONAL_EXP_2     {$$ = binaryGreaterThan($1, $3);}
                 | RELATIONAL_EXP_1 lteq RELATIONAL_EXP_2   {$$ = binaryLessEqual($1, $3);}
                 | RELATIONAL_EXP_1 lt RELATIONAL_EXP_2     {$$ = binaryLessThan($1, $3);}
                 | RELATIONAL_EXP_2                         {$$ = $1;}
                 ;

RELATIONAL_EXP_2 : RELATIONAL_EXP_2 eqeq SHIFTS     {$$ = binaryEquals($1, $3);}
                 | RELATIONAL_EXP_2 noteq SHIFTS    {$$ = binaryNotEquals($1, $3);}
                 | SHIFTS   

SHIFTS : SHIFTS rightshift ARITHMETIC_EX       {$$ = binaryRightShift($1, $3);}
       | SHIFTS leftshift ARITHMETIC_EX        {$$ = binaryLeftShift($1, $3);}
       | ARITHMETIC_EX                          {$$ = $1;}
       ;   

ARITHMETIC_EX : ARITHMETIC_EX minus ARITHMETIC_1        {$$ = binarySubtraction($1, $3);}
              | ARITHMETIC_EX plus ARITHMETIC_1         {$$ = binaryAddition($1, $3);}
              | ARITHMETIC_1                            {$$ = $1;}
           ;

ARITHMETIC_1 : ARITHMETIC_1 multiplication ARITHMETIC_2     {$$ = binaryMultiplication($1, $3);}
             | ARITHMETIC_1 division ARITHMETIC_2           {$$ = binaryDivision($1, $3);}
             | ARITHMETIC_1 modulo ARITHMETIC_2             {$$ = binaryModulo($1, $3);}
             | plus VALUE_or_ID                                   {$$ = $2;}
             | minus VALUE_or_ID                                  {$$ = unaryNegation($2);}
             | increment VALUE_or_ID                              {$$ = unaryIncrement($2);}
             | decrement VALUE_or_ID                              {$$ = unaryDecrement($2);}
             | ARITHMETIC_2                                 {$$ = $1;}
             ;

ARITHMETIC_2 : ARITHMETIC_2 exclamation     {$$ = unaryFactorial($1);}
             | BRACKETS pow1 ARITHMETIC_2    {$$ = binaryPower($1, $3);}
             | VALUE_or_ID increment              {$$ = unaryIncrement($1);}
             | VALUE_or_ID decrement              {$$ = unaryDecrement($1);}
             | BRACKETS                     {$$ = $1;}
             ;

BRACKETS : openbracket TERNARY closebracket         {$$ = $2;}
         | VALUE_or_ID                                {$$ = $1;}
         ;             

VALUE_or_ID : id 		{$$ = fetchId($1);}
			| VALUE     {$$ = $1;}

VALUE : intval	{union Value *input_value = (union Value*) malloc(sizeof(union Value)); 
				input_value->i_val = $1; 
				$$ = makeDatatypeAndValue(INTEGER, input_value);}
	  | floatval {union Value *input_value = (union Value*) malloc(sizeof(union Value)); 
				input_value->f_val = $1; 
				$$ = makeDatatypeAndValue(FLOAT, input_value);}
	  | doubleval {union Value *input_value = (union Value*) malloc(sizeof(union Value)); 
				input_value->d_val = $1; 
				$$ = makeDatatypeAndValue(DOUBLE, input_value); }
	  | charval {union Value *input_value = (union Value*) malloc(sizeof(union Value)); 
				input_value->c_val = $1; 
				$$ = makeDatatypeAndValue(CHARACTER, input_value); }
	  | BOOLEAN_VAL {union Value *input_value = (union Value*) malloc(sizeof(union Value)); 
				input_value->b_val = $1; 
				$$ = makeDatatypeAndValue(BOOLEAN, input_value); }
	  | stringval {union Value *input_value = (union Value*) malloc(sizeof(union Value)); 
				input_value->str_val = $1; 
				$$ = makeDatatypeAndValue(STRING, input_value); }
      ;

BOOLEAN_VAL : true  {$$ = '1';}
			| false {$$ = '0';}
			;
%%
int main() {
	yyparse();
	return 0;
}