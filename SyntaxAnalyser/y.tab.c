/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "Language.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>

/* Line 371 of yacc.c  */
#line 74 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 272 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNRULES -- Number of states.  */
#define YYNSTATES  243

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    13,    16,    18,    19,    22,    24,    26,
      28,    30,    32,    34,    36,    39,    41,    43,    45,    47,
      50,    53,    55,    67,    70,    72,    73,    86,    87,    95,
      98,   103,   110,   112,   113,   115,   118,   121,   131,   132,
     133,   141,   143,   145,   146,   148,   150,   165,   176,   178,
     180,   182,   183,   185,   187,   189,   190,   194,   198,   202,
     206,   210,   212,   214,   215,   217,   219,   221,   223,   225,
     227,   229,   231,   235,   239,   245,   251,   253,   257,   261,
     263,   267,   271,   275,   277,   281,   285,   289,   293,   295,
     299,   303,   305,   309,   313,   315,   319,   323,   325,   329,
     333,   337,   341,   344,   347,   350,   353,   355,   358,   362,
     365,   368,   370,   374,   376,   380,   383,   385,   387,   389,
     391,   393,   395,   397
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    98,    63,    33,    34,    97,    35,    97,
      69,    36,    -1,    69,    70,    -1,    70,    -1,    -1,    71,
      30,    -1,    97,    -1,    72,    -1,    73,    -1,    89,    -1,
     100,    -1,   110,    -1,   111,    -1,    31,     3,    -1,    32,
      -1,    95,    -1,    65,    -1,    66,    -1,    98,    99,    -1,
      74,    75,    -1,    79,    -1,    37,    33,    96,    34,    97,
      35,    97,    69,    97,    36,    97,    -1,    76,    78,    -1,
      77,    -1,    -1,    38,    33,    96,    34,    97,    35,    97,
      69,    97,    36,    97,    76,    -1,    -1,    39,    97,    35,
      97,    69,    97,    36,    -1,    80,    81,    -1,    42,    33,
      96,    34,    -1,    97,    35,    97,    82,    97,    36,    -1,
      84,    -1,    -1,    83,    -1,    86,    85,    -1,    85,    86,
      -1,    43,    96,    61,    97,    87,    97,    88,    97,    85,
      -1,    -1,    -1,    44,    61,    97,    87,    97,    88,    97,
      -1,    69,    -1,    66,    -1,    -1,    90,    -1,    91,    -1,
      40,    33,    92,    28,    93,    28,    94,    34,    97,    35,
      97,    69,    97,    36,    -1,    41,    33,    93,    34,    97,
      35,    97,    69,    97,    36,    -1,   100,    -1,    72,    -1,
      95,    -1,    -1,    96,    -1,   100,    -1,    95,    -1,    -1,
       3,    24,    96,    -1,     3,    51,    96,    -1,     3,    52,
      96,    -1,     3,    53,    96,    -1,     3,    54,    96,    -1,
     100,    -1,    30,    -1,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,     3,
      -1,     3,    29,    99,    -1,     3,    24,   100,    -1,     3,
      24,   100,    29,    99,    -1,   101,    60,   101,    61,   101,
      -1,   101,    -1,   101,    58,   102,    -1,   101,    57,   102,
      -1,   102,    -1,   102,    58,   103,    -1,   102,    59,   103,
      -1,   102,    57,   103,    -1,   103,    -1,   103,    45,   104,
      -1,   103,    46,   104,    -1,   103,    47,   104,    -1,   103,
      48,   104,    -1,   104,    -1,   104,    49,   105,    -1,   104,
      50,   105,    -1,   105,    -1,   105,    56,   106,    -1,   105,
      55,   106,    -1,   106,    -1,   106,    18,   107,    -1,   106,
      17,   107,    -1,   107,    -1,   107,    19,   108,    -1,   107,
      20,   108,    -1,   107,    23,   108,    -1,   107,    21,   108,
      -1,    17,   113,    -1,    18,   113,    -1,    26,   113,    -1,
      27,   113,    -1,   108,    -1,   108,    25,    -1,   109,    22,
     108,    -1,   113,    26,    -1,   113,    27,    -1,   109,    -1,
      33,    71,    34,    -1,   113,    -1,   113,    62,   113,    -1,
      64,   112,    -1,   100,    -1,    11,    -1,    12,    -1,    13,
      -1,    15,    -1,    14,    -1,    16,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    21,    21,    26,    26,    26,    28,    28,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    44,
      46,    46,    48,    54,    56,    58,    59,    65,    66,    72,
      74,    76,    80,    80,    80,    82,    84,    86,    90,    93,
      94,    99,   101,   101,   103,   103,   105,   110,   115,   115,
     115,   115,   117,   119,   119,   119,   121,   122,   123,   124,
     125,   128,   130,   130,   132,   133,   134,   135,   136,   137,
     138,   141,   142,   143,   144,   147,   148,   151,   152,   153,
     156,   157,   158,   159,   162,   163,   164,   165,   166,   169,
     170,   171,   173,   174,   175,   178,   179,   180,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   194,   195,   196,
     197,   198,   201,   202,   205,   207,   209,   211,   212,   213,
     214,   215,   216,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DT_INT", "DT_FLOAT",
  "DT_DOUBLE", "DT_CHARACTER", "DT_BOOLEAN", "DT_STRING", "DT_VOID",
  "INT_VAL", "FLOAT_VAL", "DOUBLE_VAL", "BOOLEAN_VAL", "CHAR_VAL",
  "STRING_VAL", "PLUS", "MINUS", "MULTIPLICATION", "DIVISION",
  "PERCENTAGE", "POW", "MODULO", "EQUAL_TO", "EXCLAMATION", "INCREMENT",
  "DECREMENT", "SEMICOLON", "COMMA", "NEW_LINE", "SINGLELINE_COMMENT",
  "MULTILINE_COMMENT", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_CURLY",
  "CLOSE_CURLY", "IF", "ELIF", "ELSE", "FOR", "WHILE", "SWITCH", "CASE",
  "DEFAULT", "GT_EQ", "GT", "LT_EQ", "LT", "EQ_EQ", "NOT_EQ", "PLUS_EQ",
  "MINUS_EQ", "MULTIPLICATION_EQ", "DIVISION_EQ", "LEFT_SHIFT",
  "RIGHT_SHIFT", "AND", "OR", "XOR", "QUESTION_MARK", "COLON", "SWAP",
  "MAIN", "RETURN", "CONTINUE", "BREAK", "$accept", "PROGRAM", "SS", "S",
  "E", "DECLARATION", "CONDITIONAL_ST", "IF_BLOCK", "OPTIONAL_BLOCK",
  "ELIF_BLOCKS", "ELIF_BLOCK", "ELSE_BLOCK", "SWITCH_CASES", "SWITCH_ST",
  "SWITCH_BLOCK", "CASES_DEFAULT_BLOCK", "DEFAULT_FIRST", "DEFAULT_LAST",
  "CASE_BLOCKS", "DEFAULT_BLOCK", "CASE_STS", "BREAK_ST", "LOOPS",
  "FOR_LOOP", "WHILE_LOOP", "OPTIONAL_INITIALIZATION", "CONDITION",
  "OPTIONAL_INCDEC", "ASSIGNMENT", "EXP", "OPTIONAL_NEWLINE", "DATATYPE",
  "LIST", "TERNARY", "LOGICAL", "BITWISE_OPERATIONS", "RELATIONAL_EXP_1",
  "RELATIONAL_EXP_2", "SHIFTS", "ARITHMETIC_EX", "ARITHMETIC_1",
  "ARITHMETIC_2", "BRACKETS", "SWAPPING", "RETURN_ST", "OPTIONAL_EXP",
  "VALUE", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      73,    73,    74,    75,    76,    77,    77,    78,    78,    79,
      80,    81,    82,    82,    82,    83,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    89,    90,    91,    92,    92,
      92,    92,    93,    94,    94,    94,    95,    95,    95,    95,
      95,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   109,   109,   110,   111,   112,   113,   113,   113,
     113,   113,   113,   113
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     2,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     1,    11,     2,     1,     0,    12,     0,     7,     2,
       4,     6,     1,     0,     1,     2,     2,     9,     0,     0,
       7,     1,     1,     0,     1,     1,    14,    10,     1,     1,
       1,     0,     1,     1,     1,     0,     3,     3,     3,     3,
       3,     1,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     5,     5,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     2,     2,     2,     2,     1,     2,     3,     2,
       2,     1,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       1,     0,     0,    63,    62,     0,    63,     5,   123,   117,
     118,   119,   121,   120,   122,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       4,     0,     8,     9,    25,    21,    63,    10,    44,    45,
      16,     7,     0,    11,    76,    79,    83,    88,    91,    94,
      97,   106,   111,    12,    13,   113,     0,     0,     0,     0,
       0,   123,   102,   103,   104,   105,    14,     0,     0,    51,
       0,     0,   116,   115,   113,     2,     3,     6,     0,    20,
      27,    24,    29,     0,    71,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,   109,   110,
       0,    56,    61,    57,    58,    59,    60,   112,     0,    49,
       0,    50,    48,     0,    52,     0,     0,    63,    23,    63,
       0,     0,    78,    77,     0,    82,    80,    81,    84,    85,
      86,    87,    89,    90,    93,    92,    96,    95,    98,    99,
     101,   100,   108,   114,    63,     0,    63,    30,     0,     0,
      33,    73,    72,     0,     0,     0,     0,    63,    63,     0,
       0,    63,    34,    32,    39,    38,     0,    75,    63,    55,
      63,     0,     5,     0,    63,     0,    36,    35,    74,     5,
       0,    54,    53,     5,    63,    63,    63,     5,    31,    63,
      63,    63,     5,     7,     5,    41,    63,     7,     0,     7,
      63,    28,    63,    43,    63,    63,    47,     7,    43,    42,
      63,    22,     5,    63,    63,    40,    63,    25,    38,     7,
      26,    37,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,   215,    40,    41,    42,    43,    44,    89,    90,
      91,   138,    45,    46,    92,   181,   182,   183,   184,   185,
     216,   230,    47,    48,    49,   130,   133,   200,    50,   134,
      51,    52,    95,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    83,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -176
static const yytype_int16 yypact[] =
{
      64,  -176,  -176,  -176,  -176,  -176,  -176,  -176,    18,   -24,
    -176,    27,    42,    68,  -176,    65,    68,   298,    13,  -176,
    -176,  -176,  -176,  -176,  -176,    16,    16,    16,    16,   120,
    -176,   339,    74,    92,    96,   111,   119,  -176,  -176,   257,
    -176,   133,  -176,  -176,   112,  -176,    68,  -176,  -176,  -176,
    -176,  -176,   164,  -176,    52,    57,    58,   -27,   -14,    35,
      15,   144,   149,  -176,  -176,    -1,   119,   119,   119,   119,
     119,  -176,  -176,  -176,  -176,  -176,  -176,   148,   119,    75,
     119,   119,  -176,  -176,   101,  -176,  -176,  -176,   145,  -176,
     155,  -176,  -176,   153,    -8,  -176,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   146,   146,   146,   146,  -176,   146,  -176,  -176,
      16,  -176,  -176,  -176,  -176,  -176,  -176,  -176,   161,  -176,
     172,  -176,  -176,   168,  -176,   170,   119,    68,  -176,    68,
     119,   164,    57,    57,   -46,    58,    58,    58,   -27,   -27,
     -27,   -27,   -14,   -14,    35,    35,    15,    15,   144,   144,
     144,   144,   144,  -176,    68,   119,    68,  -176,   171,   173,
     104,   184,  -176,   119,   179,   188,   183,    68,    68,   119,
     163,    68,  -176,  -176,   181,   186,   164,    97,    68,   374,
      68,   192,   298,   175,    68,   195,  -176,  -176,  -176,   298,
     199,  -176,  -176,   298,    68,   298,    68,   298,  -176,   298,
      68,   298,   298,   204,   298,   298,    68,   205,   207,   208,
     298,  -176,    68,   180,    68,    68,  -176,   209,   180,  -176,
      68,  -176,   298,    68,    68,  -176,   298,   112,   186,   211,
    -176,  -176,  -176
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,     7,   -35,   217,   174,  -176,  -176,  -176,    12,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -175,    66,
      37,    24,  -176,  -176,  -176,  -176,    89,  -176,   -78,   -61,
     -13,   256,  -127,   -23,   -96,    76,    20,    36,    77,    78,
      79,   -18,  -176,  -176,  -176,  -176,    23
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      15,   131,   144,    17,    86,   121,   123,   124,   125,   126,
     197,    96,    97,    82,   172,   173,   140,   128,    10,    71,
     135,   141,   106,   107,    39,   118,   119,    19,    20,    21,
      22,    23,    24,    93,   112,   113,   114,    66,   115,    11,
      65,   108,   109,   122,   122,   122,   122,   122,    72,    73,
      74,    75,   110,   111,    65,   122,   132,   122,   122,   198,
      12,   120,    65,   241,    67,    68,    69,    70,     1,     2,
       3,     4,     5,     6,     7,   168,    13,   187,    18,     1,
       2,     3,     4,     5,     6,     7,    19,    20,    21,    22,
      23,    24,    25,    26,   158,   159,   160,   161,    14,   162,
      16,    27,    28,   102,   103,   104,   105,    78,    31,    96,
      97,   201,    98,   122,    99,   100,   101,   171,   193,   145,
     146,   147,    71,    76,   169,    79,   170,   118,   119,    80,
      19,    20,    21,    22,    23,    24,    25,    26,   148,   149,
     150,   151,   122,   163,    81,    27,    28,   179,   180,    71,
      88,   174,    31,   176,    96,    97,   122,    19,    20,    21,
      22,    23,    24,    87,   191,   192,   202,    94,   195,   116,
      86,   117,   142,   143,    86,   199,    86,   203,   136,    31,
      86,   207,   127,   152,   153,    86,   154,   155,   139,   156,
     157,   212,   213,   214,   137,   164,   217,   218,   219,   205,
     165,    86,   166,   223,   167,   177,   209,   227,   178,   228,
     211,   231,   232,   186,   188,    65,   189,   235,   190,   220,
     237,   238,    65,   239,   194,   180,    65,   204,    65,   179,
      65,   208,    65,   210,    65,    65,   206,    65,    65,   236,
     221,   224,   225,    65,   226,   233,   229,   242,    77,   240,
     196,   222,   234,   129,   175,    65,     9,     0,     0,    65,
      18,     1,     2,     3,     4,     5,     6,     7,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,    27,    28,     0,     0,    14,    29,    30,
      31,     0,     0,    85,    32,     0,     0,    33,    34,    35,
       0,    18,     1,     2,     3,     4,     5,     6,     7,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,    36,    37,    38,    27,    28,     0,     0,    14,    29,
      30,    31,     0,     0,     0,    32,     0,     0,    33,    34,
      35,     0,    18,     1,     2,     3,     4,     5,     6,     7,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,    36,    37,    38,    27,    28,     0,     0,     0,
      29,    30,    31,     0,     0,     0,    32,    18,     0,    33,
      34,    35,     0,     0,     0,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    36,    37,    38,     0,    31
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      13,    79,    98,    16,    39,    66,    67,    68,    69,    70,
     185,    57,    58,    36,   141,    61,    24,    78,     0,     3,
      81,    29,    49,    50,    17,    26,    27,    11,    12,    13,
      14,    15,    16,    46,    19,    20,    21,    24,    23,    63,
      17,    55,    56,    66,    67,    68,    69,    70,    25,    26,
      27,    28,    17,    18,    31,    78,    79,    80,    81,   186,
      33,    62,    39,   238,    51,    52,    53,    54,     4,     5,
       6,     7,     8,     9,    10,   136,    34,   173,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   112,   113,   114,   115,    30,   117,
      35,    26,    27,    45,    46,    47,    48,    33,    33,    57,
      58,   189,    60,   136,    57,    58,    59,   140,   179,    99,
     100,   101,     3,     3,   137,    33,   139,    26,    27,    33,
      11,    12,    13,    14,    15,    16,    17,    18,   102,   103,
     104,   105,   165,   120,    33,    26,    27,    43,    44,     3,
      38,   164,    33,   166,    57,    58,   179,    11,    12,    13,
      14,    15,    16,    30,   177,   178,   189,     3,   181,    25,
     205,    22,    96,    97,   209,   188,   211,   190,    33,    33,
     215,   194,    34,   106,   107,   220,   108,   109,    35,   110,
     111,   204,   205,   206,    39,    34,   209,   210,   211,   192,
      28,   236,    34,   216,    34,    34,   199,   220,    35,   222,
     203,   224,   225,    29,    35,   192,    28,   230,    35,   212,
     233,   234,   199,   236,    61,    44,   203,    35,   205,    43,
     207,    36,   209,    34,   211,   212,    61,   214,   215,   232,
      36,    36,    35,   220,    36,    36,    66,    36,    31,   237,
     184,   214,   228,    79,   165,   232,     0,    -1,    -1,   236,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    64,    65,    66,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,
      42,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    64,    65,    66,    26,    27,    -1,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    37,     3,    -1,    40,
      41,    42,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    64,    65,    66,    -1,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    68,    98,
       0,    63,    33,    34,    30,    97,    35,    97,     3,    11,
      12,    13,    14,    15,    16,    17,    18,    26,    27,    31,
      32,    33,    37,    40,    41,    42,    64,    65,    66,    69,
      70,    71,    72,    73,    74,    79,    80,    89,    90,    91,
      95,    97,    98,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   113,    24,    51,    52,    53,
      54,     3,   113,   113,   113,   113,     3,    71,    33,    33,
      33,    33,   100,   112,   113,    36,    70,    30,    38,    75,
      76,    77,    81,    97,     3,    99,    57,    58,    60,    57,
      58,    59,    45,    46,    47,    48,    49,    50,    55,    56,
      17,    18,    19,    20,    21,    23,    25,    22,    26,    27,
      62,    96,   100,    96,    96,    96,    96,    34,    96,    72,
      92,    95,   100,    93,    96,    96,    33,    39,    78,    35,
      24,    29,   102,   102,   101,   103,   103,   103,   104,   104,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   113,    34,    28,    34,    34,    96,    97,
      97,   100,    99,    61,    97,    93,    97,    34,    35,    43,
      44,    82,    83,    84,    85,    86,    29,   101,    35,    28,
      35,    97,    97,    96,    61,    97,    86,    85,    99,    97,
      94,    95,   100,    97,    35,    69,    61,    97,    36,    69,
      34,    69,    97,    97,    97,    69,    87,    97,    97,    97,
      69,    36,    87,    97,    36,    35,    36,    97,    97,    66,
      88,    97,    97,    36,    88,    97,    69,    97,    97,    97,
      76,    85,    36
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 24 "Language.y"
    {printf("------MAIN PROGRAM ------\n"); exit(0);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 31 "Language.y"
    {printf("declaration\n");}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 32 "Language.y"
    {printf("coditional\n");}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 33 "Language.y"
    {printf("loop\n");}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 35 "Language.y"
    {printf("swapping\n");}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 36 "Language.y"
    {printf("return\n");}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 37 "Language.y"
    {printf("single line comment\n");}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 38 "Language.y"
    {printf("multiline comment\n");}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 39 "Language.y"
    {printf("assignment\n");}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 40 "Language.y"
    {printf("continue\n");}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 41 "Language.y"
    {printf("break\n");}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 62 "Language.y"
    {printf("elif complete\n");}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 69 "Language.y"
    {printf("else complete\n");}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 103 "Language.y"
    {printf("for complete\n");}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 103 "Language.y"
    {printf("while complete\n");}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 147 "Language.y"
    {(yyval) = (yyvsp[(1) - (5)]) ? (yyvsp[(3) - (5)]) : (yyvsp[(5) - (5)]); printf("t:%d\n",(yyvsp[(1) - (5)]));}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 148 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 151 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) || (yyvsp[(3) - (3)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 152 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) && (yyvsp[(3) - (3)]);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 153 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 156 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) | (yyvsp[(3) - (3)]);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 157 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) ^ (yyvsp[(3) - (3)]);}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 158 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) & (yyvsp[(3) - (3)]);}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 159 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 162 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) >= (yyvsp[(3) - (3)]);}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 163 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) > (yyvsp[(3) - (3)]);}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 164 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) <= (yyvsp[(3) - (3)]);}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 165 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) < (yyvsp[(3) - (3)]);}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 166 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 169 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)])==(yyvsp[(3) - (3)]);}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 170 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)])!=(yyvsp[(3) - (3)]);}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 171 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 173 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) >> (yyvsp[(3) - (3)]);}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 174 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) << (yyvsp[(3) - (3)]);}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 175 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 178 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) - (yyvsp[(3) - (3)]);}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 179 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]) + (yyvsp[(3) - (3)]);}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 180 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 183 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)])*(yyvsp[(3) - (3)]);}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 184 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)])/(yyvsp[(3) - (3)]);}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 185 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)])%(yyvsp[(3) - (3)]);}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 186 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)])*(yyvsp[(3) - (3)])/100;}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 187 "Language.y"
    {(yyval) = (yyvsp[(2) - (2)]);}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 188 "Language.y"
    {(yyval) = -(yyvsp[(2) - (2)]);}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 189 "Language.y"
    {(yyval) = (yyvsp[(2) - (2)])+1;}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 190 "Language.y"
    {(yyval) = (yyvsp[(2) - (2)])-1;}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 191 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 194 "Language.y"
    {(yyval) = (yyvsp[(1) - (2)]); while((yyvsp[(1) - (2)])-- > 1) (yyval) *= (yyvsp[(1) - (2)]);}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 195 "Language.y"
    {(yyval) = (yyvsp[(1) - (3)]); while((yyvsp[(3) - (3)])-- > 1) {(yyval) *= (yyvsp[(1) - (3)]);}}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 196 "Language.y"
    {(yyval) = (yyvsp[(1) - (2)])+1;}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 197 "Language.y"
    {(yyval) = (yyvsp[(1) - (2)])-1;}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 198 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 201 "Language.y"
    {(yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 202 "Language.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;


/* Line 1792 of yacc.c  */
#line 2051 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 220 "Language.y"

int main()
{
	yyparse();
	return 0;
}
