/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "symbol_table.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

extern FILE *yyin; 
FILE* fout_token;
void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char* yytext;

using namespace std;

enum eletype sumTypeCheck(enum eletype E1, enum eletype E2);
enum eletype arithTypeCheck(enum eletype E1, enum eletype E2);
enum eletype pointCheck (enum eletype x, enum eletype y);
bool arithCompatible(enum eletype e);
void semanticError(const char* s);


#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGERS = 258,
    LINE_OP = 259,
    IF = 260,
    ELIF = 261,
    ELSE = 262,
    FOR = 263,
    WHILE = 264,
    RETURN = 265,
    VOID = 266,
    CONTINUE = 267,
    BREAK = 268,
    PARALLEL = 269,
    PERPENDICULAR = 270,
    BOOLEAN = 271,
    FUNC = 272,
    FIG = 273,
    UNARY = 274,
    DATATYPE = 275,
    CMP_OP = 276,
    EQ_CMP_OP = 277,
    ASSIGN_OP = 278,
    EQUAL = 279,
    STRING_TOKEN = 280,
    ENDLINE = 281,
    ID = 282,
    FLOATS = 283,
    TRICONSTRUCT = 284,
    CIRCLECONSTRUCT = 285,
    PARACONSTRUCT = 286,
    REGPOLYCONSTRUCT = 287,
    NOT = 288,
    AND = 289,
    OR = 290,
    SCALE = 291,
    CENTER = 292
  };
#endif
/* Tokens.  */
#define INTEGERS 258
#define LINE_OP 259
#define IF 260
#define ELIF 261
#define ELSE 262
#define FOR 263
#define WHILE 264
#define RETURN 265
#define VOID 266
#define CONTINUE 267
#define BREAK 268
#define PARALLEL 269
#define PERPENDICULAR 270
#define BOOLEAN 271
#define FUNC 272
#define FIG 273
#define UNARY 274
#define DATATYPE 275
#define CMP_OP 276
#define EQ_CMP_OP 277
#define ASSIGN_OP 278
#define EQUAL 279
#define STRING_TOKEN 280
#define ENDLINE 281
#define ID 282
#define FLOATS 283
#define TRICONSTRUCT 284
#define CIRCLECONSTRUCT 285
#define PARACONSTRUCT 286
#define REGPOLYCONSTRUCT 287
#define NOT 288
#define AND 289
#define OR 290
#define SCALE 291
#define CENTER 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

    char* name; 
    enum eletype eletype;  

#line 227 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  272

#define YYUNDEFTOK  2
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      46,    47,    42,    40,    50,    41,    53,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,     2,    39,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,    54,    49,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    96,    96,    96,    99,    99,   100,   103,
     103,   105,   105,   107,   109,   109,   112,   113,   114,   115,
     115,   118,   118,   118,   118,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   122,   122,   124,   126,
     126,   126,   128,   130,   131,   134,   134,   135,   135,   135,
     137,   137,   138,   138,   140,   140,   141,   141,   142,   142,
     143,   143,   145,   145,   146,   146,   146,   146,   148,   148,
     150,   150,   152,   153,   156,   156,   158,   159,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   195,
     196,   199,   199,   201,   201,   204,   204,   208,   208,   209,
     209,   211,   212,   213,   214,   217,   218,   223,   223,   224,
     224,   226,   226,   228,   228,   228,   229,   229,   230,   232
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGERS", "LINE_OP", "IF", "ELIF",
  "ELSE", "FOR", "WHILE", "RETURN", "VOID", "CONTINUE", "BREAK",
  "PARALLEL", "PERPENDICULAR", "BOOLEAN", "FUNC", "FIG", "UNARY",
  "DATATYPE", "CMP_OP", "EQ_CMP_OP", "ASSIGN_OP", "EQUAL", "STRING_TOKEN",
  "ENDLINE", "ID", "FLOATS", "TRICONSTRUCT", "CIRCLECONSTRUCT",
  "PARACONSTRUCT", "REGPOLYCONSTRUCT", "NOT", "AND", "OR", "SCALE",
  "CENTER", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('",
  "')'", "'{'", "'}'", "','", "'['", "']'", "'.'", "'|'", "$accept",
  "program", "func", "$@1", "arg_list", "list1", "argument", "func_body",
  "fig", "params", "fig_body", "stmt", "stmt_loop", "break_stmt",
  "assign_stmt", "return_stmt", "ret_var", "decl_stmt", "ID_LIST",
  "decl_assign", "decl_token", "dim", "check_arr", "arr_assign",
  "comma_arr_assign", "arr1d_in_list", "mult_elements", "construct",
  "constructor", "valid_arg", "param_list", "point", "vertex", "angle",
  "expression", "id_list", "arr_access", "func_call", "empty_space",
  "stmt_list", "stmt_block", "cond_stmt", "elif_stmt", "stmt_loop_list",
  "stmt_loop_block", "loop", "for_loop_decl", "optional_arg", "for_loop",
  "while_loop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    60,    62,
      43,    45,    42,    47,    37,    94,    40,    41,   123,   125,
      44,    91,    93,    46,   124
};
# endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -179,   247,  -179,  -179,    10,    38,    50,   982,  1028,  -179,
      11,    16,  1028,    67,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  1028,    -4,  1028,  1028,  -179,  -179,  -179,  -179,
    -179,  -179,     3,    66,  -179,  -179,  1071,     4,  -179,  -179,
    -179,  -179,  -179,  1028,    72,  1028,    78,  -179,  1103,  1135,
      88,    89,    74,   102,  -179,    -5,    73,  -179,  -179,  1028,
    -179,    -4,   -10,   531,  -179,   769,  1028,  1028,  1028,  -179,
    1028,  1028,  -179,  1028,  1028,  1028,  1028,  1028,  1028,  1028,
    1028,  1028,  1028,  1028,  1028,   792,    96,   822,   100,   105,
      81,   864,  -179,  1043,    86,  -179,  1002,     2,  -179,   111,
    1028,   615,    -4,  -179,  1028,  -179,  -179,  -179,    48,  1103,
     -10,  1194,  1167,   515,   808,   135,  1221,   515,   515,   -10,
     -10,    -6,    -6,    -6,   121,  1103,  1103,  -179,    64,  -179,
    -179,   119,  1028,  1028,  -179,   125,   104,   124,   106,   647,
     712,   103,  -179,  -179,  -179,   148,    -9,   573,  -179,   982,
    -179,    73,    54,    18,  1028,  1103,  1103,    97,    57,  -179,
     132,   117,   115,  -179,   125,  1028,  -179,  1028,   743,  -179,
    -179,  -179,  1103,  -179,   199,     2,  -179,  -179,   150,  -179,
     143,  -179,  -179,   362,   126,  -179,    94,  1103,  1028,   286,
    -179,  -179,   125,   138,   679,    61,  1103,  -179,    58,   122,
     144,  1103,  -179,  -179,   156,   149,   171,  -179,   396,  1028,
    -179,   152,  -179,   154,   173,   178,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,   328,  -179,   155,    62,  -179,  -179,
     168,  -179,  -179,   159,  -179,  1028,  -179,  -179,  -179,   182,
    -179,   906,  1028,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
      65,   186,   430,  -179,  1103,  -179,  -179,   948,  -179,   464,
    -179,  1028,  -179,  -179,  -179,  -179,  -179,  -179,   498,  1103,
    -179,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     1,   102,     0,     0,     0,    41,     0,   104,
       0,     0,     0,     0,   103,    26,   112,   101,    64,    65,
      66,    67,     0,     0,     0,     0,     2,     3,     4,    24,
      25,    23,     0,     0,   106,   107,     0,   100,   105,    21,
      22,   131,   132,     0,   135,     0,     0,    39,    40,     0,
       0,     0,     0,    89,    53,     0,   110,    91,    74,     0,
      75,     0,    88,     0,    37,     0,     0,     0,     0,    90,
       0,     0,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    87,     0,     6,     0,    46,    42,     0,
       0,     0,     0,   108,     0,    63,    68,    71,     0,    69,
      84,    85,    86,    96,    99,    92,    93,    97,    98,    78,
      79,    80,    81,    82,    83,    95,    94,   114,     0,   112,
     116,     0,     0,   137,   116,    10,     0,     0,     0,     0,
       0,     0,    44,    52,    53,     0,     0,     0,    62,     0,
     113,   109,     0,   121,     0,   134,   136,     0,     0,   139,
       0,     0,     9,    12,    10,     0,   116,     0,    59,    45,
      47,    48,    49,    51,     0,    46,   111,    77,     0,    73,
       0,    70,   115,     0,     0,   116,   124,   133,   137,     0,
      53,   116,     0,     0,     0,     0,    17,    57,     0,     0,
      58,    61,    50,    43,     0,     0,     0,   118,     0,     0,
     122,     0,   116,     0,     0,     0,    33,   130,   128,    32,
      30,    31,    29,    27,     0,    28,    13,     0,    11,   116,
       0,    20,    55,     0,    54,     0,    76,    72,   120,     0,
     117,     0,     0,   123,   116,    35,    34,   129,   127,    15,
       0,     0,     0,    56,    60,   119,   116,     0,   138,     0,
      15,     0,    16,    19,   125,   116,     8,    14,     0,    18,
     126,     7
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -179,    47,  -179,    20,   -45,  -179,  -179,
    -179,     1,    -8,  -179,  -178,  -177,  -179,  -173,  -179,    42,
    -179,  -179,  -141,  -154,  -179,  -179,  -179,    -3,  -179,    70,
     137,   -17,   -54,  -179,    -7,  -179,    95,  -179,  -126,  -179,
    -175,  -170,  -179,  -179,   -21,  -169,  -179,    37,  -179,  -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   136,   161,   162,   163,   259,    27,   138,
     252,   267,   218,   219,    29,    30,    46,    31,    55,   142,
     169,   143,    97,   170,   198,   199,   200,    32,    33,   107,
     108,    34,    61,    35,    36,    37,    56,    38,   152,   208,
     153,    39,   186,   224,   159,    40,    90,   157,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    49,    28,   175,    47,    53,    60,   102,   158,    69,
     210,   220,   221,    69,   197,    57,   222,    62,    63,   223,
     225,    98,    50,    58,   184,   185,   140,    83,    84,    64,
     177,    51,    79,    80,    81,    82,    87,   243,    91,    82,
     195,   178,    59,    52,    60,    99,   220,   221,   146,   226,
      85,   222,   101,   141,   223,   225,    43,    86,   109,   110,
     111,   112,   106,   113,   114,   227,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   109,   253,
     182,   264,   106,   182,    44,    60,   111,   182,   182,   139,
     270,   182,    88,   145,    54,   148,    45,   147,   149,    89,
     211,   212,   183,   250,    92,   189,     3,   232,   233,   231,
     249,   150,    65,   260,   149,    94,    95,     8,   158,     9,
      96,    -1,    12,   129,   100,   155,   156,   131,    14,   132,
      16,    17,   135,   172,   174,   133,    22,   171,   144,    66,
      69,    23,   109,   154,    24,   160,   106,   187,   165,    25,
     164,   188,    66,   166,    69,   173,    70,    71,   194,   190,
     196,   201,    67,    68,   191,   192,   204,    69,   205,    70,
      71,   234,   209,    75,    76,    77,    78,    79,    80,    81,
      82,   156,    73,    74,   207,   229,    75,    76,    77,    78,
      79,    80,    81,    82,   235,   236,   237,   238,   242,   245,
     176,   244,   241,    66,   246,   251,   141,   168,   255,   240,
     261,   193,   228,    67,    68,   268,   248,   203,    69,   181,
      70,    71,   128,   258,   151,   213,     0,     0,   254,     0,
       0,     0,     0,    73,    74,   257,     0,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     2,     0,     0,
       3,   202,     4,   263,   269,     5,     6,     7,     0,     0,
       0,     8,     0,     9,    10,    11,    12,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     0,     0,     0,     0,    23,     0,     0,    24,     3,
       0,     4,     0,    25,     5,     6,     7,     0,   214,   215,
       8,     0,     9,     0,     0,    12,    13,     0,     0,     0,
       0,    14,   216,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,    23,     0,     0,    24,     0,     0,
       0,     3,    25,     4,     0,   217,     5,     6,     7,     0,
     214,   215,     8,     0,     9,     0,     0,    12,    13,     0,
       0,     0,     0,    14,   216,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     3,    23,     4,     0,    24,
       5,     6,     7,     0,    25,     0,     8,   247,     9,     0,
       0,    12,    13,     0,     0,     0,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     3,
      23,     4,     0,    24,     5,     6,     7,     0,    25,     0,
       8,   206,     9,     0,     0,    12,    13,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     3,    23,     4,     0,    24,     5,     6,
       7,     0,    25,     0,     8,   239,     9,     0,     0,    12,
      13,     0,     0,     0,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     3,    23,     4,
       0,    24,     5,     6,     7,     0,    25,     0,     8,   262,
       9,     0,     0,    12,    13,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     3,    23,     4,     0,    24,     5,     6,     7,     0,
      25,     0,     8,   266,     9,     0,     0,    12,    13,    66,
       0,     0,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,    69,    66,    23,     0,     0,    24,
       0,     0,     0,     0,    25,    67,    68,   271,     0,     0,
      69,     0,    70,    71,     0,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    66,   103,     0,
       0,   104,     0,     0,     0,     0,     0,    67,    68,     0,
       0,     0,    69,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    66,
     179,     0,     0,   180,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,    69,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    66,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    67,    68,     0,     0,   104,    69,     0,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    66,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    67,    68,     0,     0,   167,    69,     0,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     3,     0,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     8,     0,     9,   230,
       0,    12,     0,     0,     0,     0,     0,    14,     0,    16,
      17,    18,    19,    20,    21,    22,     3,     0,     0,     0,
      23,     0,     0,    24,     0,     0,     0,     8,    25,     9,
     168,     0,    12,     0,     0,     0,     0,     0,    14,     0,
      16,    17,     3,     0,     0,     0,    22,     0,     0,     0,
       0,    23,     0,     8,    24,     9,     0,     0,    12,    25,
       0,   168,     0,     0,    14,     3,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     8,    23,     9,     0,
      24,    12,    66,     0,     0,    25,   105,    14,     0,    16,
      17,    18,    19,    20,    21,    22,    66,    69,     0,    70,
      23,     0,     0,    24,     0,     0,    67,    68,    25,   127,
       0,    69,     0,    70,    71,     0,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,    73,    74,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    82,    66,   130,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    68,
       0,     0,     0,    69,     0,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      66,   134,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,     0,     0,     0,    69,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    82,    66,   256,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,     0,    69,     0,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,     0,     3,    75,    76,    77,    78,
      79,    80,    81,    82,     0,   265,     8,     0,     9,     0,
       0,    12,     0,     0,     0,     3,     0,    14,     0,    16,
      17,    18,    19,    20,    21,    22,     8,     0,     9,     0,
      23,    12,     0,    24,     0,     0,     0,    14,    25,    16,
      17,     3,     0,     0,     0,    22,     0,     0,   137,     0,
      23,     0,     8,    24,     9,     0,     3,    12,    25,     0,
       0,     0,     0,    14,     0,    16,    17,     0,     0,     9,
       0,    22,    12,     0,     0,     0,    23,     0,    14,    24,
      16,    17,     0,     0,    25,    66,    22,     0,     0,     0,
       0,    23,     0,     0,    24,    67,    68,     0,     0,    25,
      69,     0,    70,    71,     0,     0,     0,    72,     0,     0,
       0,     0,     0,     0,     0,    73,    74,    66,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    67,    68,     0,
       0,     0,    69,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,    66,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    93,
      68,     0,     0,     0,    69,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    66,     0,    75,    76,    77,    78,    79,    80,    81,
      82,    67,     0,     0,     0,     0,    69,     0,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       0,    73,    74,     0,     0,    75,    76,    77,    78,    79,
      80,    81,    82,    69,     0,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    66,     0,     0,    73,    74,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      69,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       7,     8,     1,   144,     7,    12,    23,    61,   134,    19,
     185,   189,   189,    19,   168,    22,   189,    24,    25,   189,
     189,    26,    11,    27,     6,     7,    24,    23,    24,    26,
      39,    20,    42,    43,    44,    45,    43,   212,    45,    45,
     166,    50,    46,    27,    61,    50,   224,   224,   102,   190,
      46,   224,    59,    51,   224,   224,    46,    53,    65,    66,
      67,    68,    65,    70,    71,   191,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   233,
      26,   256,    85,    26,    46,   102,    93,    26,    26,    96,
     265,    26,    20,   100,    27,    47,    46,   104,    50,    27,
       6,     7,    48,   229,    26,    48,     3,    49,    50,    48,
      48,    47,    46,    48,    50,    27,    27,    14,   244,    16,
      46,    19,    19,    27,    51,   132,   133,    27,    25,    24,
      27,    28,    46,   140,   141,    54,    33,   140,    27,     4,
      19,    38,   149,    24,    41,    20,   149,   154,    24,    46,
      46,    54,     4,    47,    19,    52,    21,    22,   165,    27,
     167,   168,    14,    15,    47,    50,    16,    19,    25,    21,
      22,    49,    46,    38,    39,    40,    41,    42,    43,    44,
      45,   188,    34,    35,   183,    47,    38,    39,    40,    41,
      42,    43,    44,    45,    50,    39,    47,    26,    46,    26,
      52,    47,   209,     4,    26,    37,    51,    48,    26,   208,
      24,   164,   192,    14,    15,   260,   224,   175,    19,   149,
      21,    22,    85,   244,   129,   188,    -1,    -1,   235,    -1,
      -1,    -1,    -1,    34,    35,   242,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,     0,    -1,    -1,
       3,    52,     5,   252,   261,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,     3,
      -1,     5,    -1,    46,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    -1,    -1,
      -1,     3,    46,     5,    -1,    49,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,     3,    38,     5,    -1,    41,
       8,     9,    10,    -1,    46,    -1,    14,    49,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,     3,
      38,     5,    -1,    41,     8,     9,    10,    -1,    46,    -1,
      14,    49,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,     3,    38,     5,    -1,    41,     8,     9,
      10,    -1,    46,    -1,    14,    49,    16,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,     3,    38,     5,
      -1,    41,     8,     9,    10,    -1,    46,    -1,    14,    49,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,     3,    38,     5,    -1,    41,     8,     9,    10,    -1,
      46,    -1,    14,    49,    16,    -1,    -1,    19,    20,     4,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    19,     4,    38,    -1,    -1,    41,
      -1,    -1,    -1,    -1,    46,    14,    15,    49,    -1,    -1,
      19,    -1,    21,    22,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,     4,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,     4,
      47,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,     4,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    14,    15,    -1,    -1,    50,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,     4,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    14,    15,    -1,    -1,    50,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,     3,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    14,    -1,    16,    50,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,     3,    -1,    -1,    -1,
      38,    -1,    -1,    41,    -1,    -1,    -1,    14,    46,    16,
      48,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,     3,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,    14,    41,    16,    -1,    -1,    19,    46,
      -1,    48,    -1,    -1,    25,     3,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    14,    38,    16,    -1,
      41,    19,     4,    -1,    -1,    46,    47,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,     4,    19,    -1,    21,
      38,    -1,    -1,    41,    -1,    -1,    14,    15,    46,    47,
      -1,    19,    -1,    21,    22,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    34,    35,    -1,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,     4,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
       4,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,     4,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,     3,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    47,    14,    -1,    16,    -1,
      -1,    19,    -1,    -1,    -1,     3,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    14,    -1,    16,    -1,
      38,    19,    -1,    41,    -1,    -1,    -1,    25,    46,    27,
      28,     3,    -1,    -1,    -1,    33,    -1,    -1,    36,    -1,
      38,    -1,    14,    41,    16,    -1,     3,    19,    46,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,    16,
      -1,    33,    19,    -1,    -1,    -1,    38,    -1,    25,    41,
      27,    28,    -1,    -1,    46,     4,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    14,    15,    -1,    -1,    46,
      19,    -1,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,     4,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    14,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,     4,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,     4,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    34,    35,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    56,     0,     3,     5,     8,     9,    10,    14,    16,
      17,    18,    19,    20,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    38,    41,    46,    57,    63,    66,    69,
      70,    72,    82,    83,    86,    88,    89,    90,    92,    96,
     100,   103,   104,    46,    46,    46,    71,    82,    89,    89,
      11,    20,    27,    89,    27,    73,    91,    89,    27,    46,
      86,    87,    89,    89,    26,    46,     4,    14,    15,    19,
      21,    22,    26,    34,    35,    38,    39,    40,    41,    42,
      43,    44,    45,    23,    24,    46,    53,    89,    20,    27,
     101,    89,    26,    14,    27,    27,    46,    77,    26,    50,
      51,    89,    87,    47,    50,    47,    82,    84,    85,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    47,    85,    27,
      47,    27,    24,    54,    47,    46,    58,    36,    64,    89,
      24,    51,    74,    76,    27,    89,    87,    89,    47,    50,
      47,    91,    93,    95,    24,    89,    89,   102,    93,    99,
      20,    59,    60,    61,    46,    24,    47,    50,    48,    75,
      78,    82,    89,    52,    89,    77,    52,    39,    50,    47,
      50,    84,    26,    48,     6,     7,    97,    89,    54,    48,
      27,    47,    50,    59,    89,    93,    89,    78,    79,    80,
      81,    89,    52,    74,    16,    25,    49,    66,    94,    46,
      95,     6,     7,   102,    12,    13,    26,    49,    67,    68,
      69,    70,    72,    96,    98,   100,    77,    93,    61,    47,
      50,    48,    49,    50,    49,    50,    39,    47,    26,    49,
      66,    89,    46,    95,    47,    26,    26,    49,    67,    48,
      93,    37,    65,    78,    89,    26,    47,    89,    99,    62,
      48,    24,    49,    66,    95,    47,    49,    66,    62,    89,
      95,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    58,    57,    57,    59,
      59,    60,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    70,    71,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   102,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     0,    11,    10,     1,
       0,     3,     1,     3,     2,     0,     9,     3,     7,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     3,     1,
       1,     0,     3,     5,     3,     2,     0,     1,     1,     1,
       3,     2,     2,     0,     3,     3,     3,     1,     1,     0,
       3,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     7,     5,     1,     1,     7,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       2,     4,     0,     4,     3,     2,     0,     2,     1,     5,
       4,     5,     7,     8,     6,     5,     6,     2,     1,     4,
       3,     1,     1,     4,     3,     0,     1,     0,     9,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6:
#line 99 "parser.y"
                          { insertType((yyvsp[0].name), Func, (yyvsp[-1].eletype));  printSymbolTable();}
#line 1794 "y.tab.c"
    break;

  case 72:
#line 152 "parser.y"
                                                            {  (yyval.eletype) = pointCheck((yyvsp[-5].eletype), (yyvsp[-3].eletype)); }
#line 1800 "y.tab.c"
    break;

  case 73:
#line 153 "parser.y"
                                               {  (yyval.eletype) = pointCheck((yyvsp[-3].eletype), (yyvsp[-1].eletype)); }
#line 1806 "y.tab.c"
    break;

  case 76:
#line 158 "parser.y"
                                                  {(yyval.eletype) = REAL;}
#line 1812 "y.tab.c"
    break;

  case 77:
#line 159 "parser.y"
                                      {(yyval.eletype) = REAL;}
#line 1818 "y.tab.c"
    break;

  case 78:
#line 162 "parser.y"
                                        {(yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)); }
#line 1824 "y.tab.c"
    break;

  case 79:
#line 163 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1830 "y.tab.c"
    break;

  case 80:
#line 164 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1836 "y.tab.c"
    break;

  case 81:
#line 165 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1842 "y.tab.c"
    break;

  case 82:
#line 166 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1848 "y.tab.c"
    break;

  case 83:
#line 167 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1854 "y.tab.c"
    break;

  case 84:
#line 168 "parser.y"
                                            {if((yyvsp[-2].eletype) == POINT && (yyvsp[0].eletype) == POINT) (yyval.eletype) = LINE ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 1860 "y.tab.c"
    break;

  case 85:
#line 169 "parser.y"
                                             {if((yyvsp[-2].eletype) == LINE && (yyvsp[0].eletype) == LINE) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 1866 "y.tab.c"
    break;

  case 86:
#line 170 "parser.y"
                                                   {if((yyvsp[-2].eletype) == LINE && (yyvsp[0].eletype) == LINE) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
#line 1872 "y.tab.c"
    break;

  case 87:
#line 171 "parser.y"
                                            {if ((yyvsp[-1].eletype) != POINT) semanticError("Error: Semantic error incompatible datatype") ; (yyval.eletype) = REAL; }
#line 1878 "y.tab.c"
    break;

  case 88:
#line 172 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 1884 "y.tab.c"
    break;

  case 89:
#line 173 "parser.y"
                               {if(!((yyvsp[0].eletype) == INT || (yyvsp[0].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);  }
#line 1890 "y.tab.c"
    break;

  case 90:
#line 174 "parser.y"
                               {if(!((yyvsp[-1].eletype) == INT || (yyvsp[-1].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);  }
#line 1896 "y.tab.c"
    break;

  case 91:
#line 175 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);}
#line 1902 "y.tab.c"
    break;

  case 92:
#line 176 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1908 "y.tab.c"
    break;

  case 93:
#line 177 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1914 "y.tab.c"
    break;

  case 94:
#line 178 "parser.y"
                                       {(yyvsp[-2].eletype) = (yyvsp[0].eletype); (yyval.eletype) = (yyvsp[0].eletype); }
#line 1920 "y.tab.c"
    break;

  case 96:
#line 180 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1926 "y.tab.c"
    break;

  case 97:
#line 181 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1932 "y.tab.c"
    break;

  case 98:
#line 182 "parser.y"
                                         {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1938 "y.tab.c"
    break;

  case 99:
#line 183 "parser.y"
                                              {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1944 "y.tab.c"
    break;

  case 100:
#line 184 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1950 "y.tab.c"
    break;

  case 101:
#line 185 "parser.y"
                     {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1956 "y.tab.c"
    break;

  case 102:
#line 186 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1962 "y.tab.c"
    break;

  case 103:
#line 187 "parser.y"
                           {(yyval.eletype) = (yyvsp[0].eletype);  cout<< (yyval.eletype);}
#line 1968 "y.tab.c"
    break;

  case 104:
#line 188 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1974 "y.tab.c"
    break;

  case 106:
#line 190 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1980 "y.tab.c"
    break;

  case 107:
#line 191 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1986 "y.tab.c"
    break;

  case 108:
#line 192 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1992 "y.tab.c"
    break;

  case 121:
#line 211 "parser.y"
                                             {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 1998 "y.tab.c"
    break;

  case 122:
#line 212 "parser.y"
                                                              {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2004 "y.tab.c"
    break;

  case 123:
#line 213 "parser.y"
                                                                       {if(!(arithCompatible((yyvsp[-5].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2010 "y.tab.c"
    break;

  case 124:
#line 214 "parser.y"
                                                       {if(!(arithCompatible((yyvsp[-3].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2016 "y.tab.c"
    break;

  case 125:
#line 217 "parser.y"
                                                {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2022 "y.tab.c"
    break;

  case 126:
#line 218 "parser.y"
                                                         {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2028 "y.tab.c"
    break;

  case 136:
#line 229 "parser.y"
                         {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2034 "y.tab.c"
    break;

  case 137:
#line 229 "parser.y"
                                      {(yyval.eletype) = BOOL;}
#line 2040 "y.tab.c"
    break;

  case 138:
#line 230 "parser.y"
                                                                                       {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype11"); cout<<"k";}
#line 2046 "y.tab.c"
    break;


#line 2050 "y.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 235 "parser.y"


/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

void semanticError(const char* s)
{
       cerr << s << "\n";
       exit(1);
}
  
enum eletype sumTypeCheck(enum eletype E1, enum eletype E2  ){
       if(E1 == LABEL && E2 == LABEL)
              return LABEL;
       else if(E1 == POINT && E2 == POINT)
              return POINT;
       else if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1);
       }
}

enum eletype arithTypeCheck(enum eletype E1, enum eletype E2  ){
       
       if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1);
       }
}

bool arithCompatible(enum eletype e){

       if (e == REAL || e == BOOL || e == INT)
              return true;
       return false;
}
enum eletype pointCheck (enum eletype x, enum eletype y){
       if ((x == INT || x == REAL) && (y == INT || y == REAL ))
              return POINT;
       else {
              cerr << "Error: Semantic error invalid point \n";
              exit(1);
       }
}


int main(int argc, char*argv[])
{    

    FILE *fp;
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    yyin = fp;
    return yyparse();
} 
