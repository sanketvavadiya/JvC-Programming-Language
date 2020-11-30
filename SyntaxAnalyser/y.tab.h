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
     IDENTIFIER = 258,
     DT_INT = 259,
     DT_FLOAT = 260,
     DT_DOUBLE = 261,
     DT_CHARACTER = 262,
     DT_BOOLEAN = 263,
     DT_STRING = 264,
     DT_VOID = 265,
     INT_VAL = 266,
     FLOAT_VAL = 267,
     DOUBLE_VAL = 268,
     BOOLEAN_VAL = 269,
     CHAR_VAL = 270,
     STRING_VAL = 271,
     PLUS = 272,
     MINUS = 273,
     MULTIPLICATION = 274,
     DIVISION = 275,
     PERCENTAGE = 276,
     POW = 277,
     MODULO = 278,
     EQUAL_TO = 279,
     EXCLAMATION = 280,
     INCREMENT = 281,
     DECREMENT = 282,
     SEMICOLON = 283,
     COMMA = 284,
     NEW_LINE = 285,
     SINGLELINE_COMMENT = 286,
     MULTILINE_COMMENT = 287,
     OPEN_BRACKET = 288,
     CLOSE_BRACKET = 289,
     OPEN_CURLY = 290,
     CLOSE_CURLY = 291,
     IF = 292,
     ELIF = 293,
     ELSE = 294,
     FOR = 295,
     WHILE = 296,
     SWITCH = 297,
     CASE = 298,
     DEFAULT = 299,
     GT_EQ = 300,
     GT = 301,
     LT_EQ = 302,
     LT = 303,
     EQ_EQ = 304,
     NOT_EQ = 305,
     PLUS_EQ = 306,
     MINUS_EQ = 307,
     MULTIPLICATION_EQ = 308,
     DIVISION_EQ = 309,
     LEFT_SHIFT = 310,
     RIGHT_SHIFT = 311,
     AND = 312,
     OR = 313,
     XOR = 314,
     QUESTION_MARK = 315,
     COLON = 316,
     SWAP = 317,
     MAIN = 318,
     RETURN = 319,
     CONTINUE = 320,
     BREAK = 321
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DT_INT 259
#define DT_FLOAT 260
#define DT_DOUBLE 261
#define DT_CHARACTER 262
#define DT_BOOLEAN 263
#define DT_STRING 264
#define DT_VOID 265
#define INT_VAL 266
#define FLOAT_VAL 267
#define DOUBLE_VAL 268
#define BOOLEAN_VAL 269
#define CHAR_VAL 270
#define STRING_VAL 271
#define PLUS 272
#define MINUS 273
#define MULTIPLICATION 274
#define DIVISION 275
#define PERCENTAGE 276
#define POW 277
#define MODULO 278
#define EQUAL_TO 279
#define EXCLAMATION 280
#define INCREMENT 281
#define DECREMENT 282
#define SEMICOLON 283
#define COMMA 284
#define NEW_LINE 285
#define SINGLELINE_COMMENT 286
#define MULTILINE_COMMENT 287
#define OPEN_BRACKET 288
#define CLOSE_BRACKET 289
#define OPEN_CURLY 290
#define CLOSE_CURLY 291
#define IF 292
#define ELIF 293
#define ELSE 294
#define FOR 295
#define WHILE 296
#define SWITCH 297
#define CASE 298
#define DEFAULT 299
#define GT_EQ 300
#define GT 301
#define LT_EQ 302
#define LT 303
#define EQ_EQ 304
#define NOT_EQ 305
#define PLUS_EQ 306
#define MINUS_EQ 307
#define MULTIPLICATION_EQ 308
#define DIVISION_EQ 309
#define LEFT_SHIFT 310
#define RIGHT_SHIFT 311
#define AND 312
#define OR 313
#define XOR 314
#define QUESTION_MARK 315
#define COLON 316
#define SWAP 317
#define MAIN 318
#define RETURN 319
#define CONTINUE 320
#define BREAK 321



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
