/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     intval = 258,
     floatval = 259,
     doubleval = 260,
     charval = 261,
     stringval = 262,
     id = 263,
     intdt = 264,
     floatdt = 265,
     doubledt = 266,
     chardt = 267,
     stringdt = 268,
     booleandt = 269,
     plus = 270,
     minus = 271,
     multiplication = 272,
     division = 273,
     exclamation = 274,
     pow1 = 275,
     modulo = 276,
     increment = 277,
     decrement = 278,
     logicalor = 279,
     logicaland = 280,
     equal = 281,
     openbracket = 282,
     closebracket = 283,
     gteq = 284,
     gt = 285,
     lt = 286,
     lteq = 287,
     eqeq = 288,
     noteq = 289,
     questionmark = 290,
     colon = 291,
     leftshift = 292,
     rightshift = 293,
     and = 294,
     or = 295,
     xor = 296,
     newline = 297,
     print = 298,
     comma = 299,
     true = 300,
     false = 301
   };
#endif
/* Tokens.  */
#define intval 258
#define floatval 259
#define doubleval 260
#define charval 261
#define stringval 262
#define id 263
#define intdt 264
#define floatdt 265
#define doubledt 266
#define chardt 267
#define stringdt 268
#define booleandt 269
#define plus 270
#define minus 271
#define multiplication 272
#define division 273
#define exclamation 274
#define pow1 275
#define modulo 276
#define increment 277
#define decrement 278
#define logicalor 279
#define logicaland 280
#define equal 281
#define openbracket 282
#define closebracket 283
#define gteq 284
#define gt 285
#define lt 286
#define lteq 287
#define eqeq 288
#define noteq 289
#define questionmark 290
#define colon 291
#define leftshift 292
#define rightshift 293
#define and 294
#define or 295
#define xor 296
#define newline 297
#define print 298
#define comma 299
#define true 300
#define false 301



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 16 "TempSysmbolTable.y"

	int i_val;
	float f_val;
	double d_val;
	char c_val;
	char b_val;
	char* str_val;
	char *sym_name;
	struct DatatypeAndValue* datatype_and_value_node;
	struct SymbolTable *symbol_table;


/* Line 2058 of yacc.c  */
#line 162 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
