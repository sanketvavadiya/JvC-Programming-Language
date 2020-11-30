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
     NUMBER = 258,
     PLUS = 259,
     MINUS = 260,
     MULTIPLICATION = 261,
     DIVISION = 262,
     PERCENTAGE = 263,
     POW = 264,
     MODULO = 265,
     EQUAL_TO = 266,
     INCREMENT = 267,
     DECREMENT = 268,
     EXCLAMATION = 269,
     AND = 270,
     OR = 271,
     XOR = 272,
     LEFT_SHIFT = 273,
     RIGHT_SHIFT = 274,
     GT_EQ = 275,
     GT = 276,
     LT_EQ = 277,
     LT = 278,
     SEMICOLON = 279,
     COMMA = 280,
     OPEN_BRACKET = 281,
     CLOSE_BRACKET = 282,
     NEWLINE = 283,
     QUESTION_MARK = 284,
     COLON = 285
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define PLUS 259
#define MINUS 260
#define MULTIPLICATION 261
#define DIVISION 262
#define PERCENTAGE 263
#define POW 264
#define MODULO 265
#define EQUAL_TO 266
#define INCREMENT 267
#define DECREMENT 268
#define EXCLAMATION 269
#define AND 270
#define OR 271
#define XOR 272
#define LEFT_SHIFT 273
#define RIGHT_SHIFT 274
#define GT_EQ 275
#define GT 276
#define LT_EQ 277
#define LT 278
#define SEMICOLON 279
#define COMMA 280
#define OPEN_BRACKET 281
#define CLOSE_BRACKET 282
#define NEWLINE 283
#define QUESTION_MARK 284
#define COLON 285



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
