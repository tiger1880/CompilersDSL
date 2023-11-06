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
    CONSTRUCTOR = 284,
    NOT = 285,
    AND = 286,
    OR = 287,
    SCALE = 288,
    CENTER = 289
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
#define CONSTRUCTOR 284
#define NOT 285
#define AND 286
#define OR 287
#define SCALE 288
#define CENTER 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

    char* name; 
    enum eletype eletype;  

#line 221 "y.tab.c"

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
#define YYLAST   1150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


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
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
      43,    44,    39,    37,    47,    38,    50,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,     2,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    51,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    91,    91,    91,    94,    94,    95,    98,
      98,   100,   100,   102,   104,   104,   107,   108,   109,   110,
     110,   113,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   115,   115,   117,   117,   119,   121,
     121,   121,   123,   125,   126,   129,   129,   130,   130,   130,
     132,   132,   133,   133,   135,   135,   136,   136,   137,   137,
     138,   138,   140,   140,   142,   142,   144,   144,   146,   147,
     150,   150,   152,   153,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   185,   188,   189,   192,   192,   194,
     194,   197,   197,   201,   201,   202,   202,   204,   205,   206,
     207,   210,   211,   216,   216,   217,   217,   219,   219,   221,
     221,   221,   222,   222,   223,   225
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
  "ENDLINE", "ID", "FLOATS", "CONSTRUCTOR", "NOT", "AND", "OR", "SCALE",
  "CENTER", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'('",
  "')'", "'{'", "'}'", "','", "'['", "']'", "'.'", "'|'", "$accept",
  "program", "func", "$@1", "arg_list", "list1", "argument", "func_body",
  "fig", "params", "fig_body", "stmt", "stmt_loop", "break_stmt",
  "assign_stmt", "return_stmt", "ret_var", "decl_stmt", "ID_LIST",
  "decl_assign", "decl_token", "dim", "check_arr", "arr_assign",
  "comma_arr_assign", "arr1d_in_list", "mult_elements", "construct",
  "valid_arg", "param_list", "point", "vertex", "angle", "expression",
  "id_list", "arr_access", "func_call", "empty_space", "stmt_list",
  "stmt_block", "cond_stmt", "elif_stmt", "stmt_loop_list",
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
     285,   286,   287,   288,   289,    60,    62,    43,    45,    42,
      47,    37,    94,    40,    41,   123,   125,    44,    91,    93,
      46,   124
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
    -179,   218,  -179,  -179,   -16,   -10,    40,   853,   890,  -179,
      10,     4,   890,    16,  -179,  -179,  -179,  -179,    49,   890,
      34,   890,   890,  -179,  -179,  -179,  -179,  -179,  -179,    75,
    -179,  -179,   925,    -5,  -179,  -179,  -179,  -179,  -179,   890,
       9,   890,    88,  -179,   954,   983,    76,    96,    84,   120,
    -179,     0,   107,    81,  -179,  -179,   890,  -179,    34,   131,
     466,  -179,   890,   890,   890,  -179,   890,   890,  -179,   890,
     890,   890,   890,   890,   890,   890,   890,   890,   890,   890,
     890,   678,   133,   705,   134,   150,   128,   744,  -179,   907,
     135,  -179,   870,    51,  -179,   154,   890,  -179,  -179,  -179,
     -19,   954,   544,    34,  -179,   890,   131,  1036,  1012,   492,
    1108,  1084,  1060,   492,   492,   131,   131,    -2,    -2,    -2,
     163,   954,   954,  -179,    91,  -179,  -179,   159,   890,   890,
    -179,   164,   144,   165,   147,   573,   632,    77,  -179,  -179,
    -179,   127,  -179,   853,   -12,   505,  -179,   107,    -6,   138,
     890,   954,   954,   137,    68,  -179,   167,   151,   149,  -179,
     164,   890,  -179,   890,   655,  -179,  -179,  -179,   954,  -179,
     171,    51,  -179,  -179,  -179,   181,  -179,   174,  -179,   324,
     157,  -179,   145,   954,   890,   254,  -179,  -179,   164,   160,
     602,    92,   954,  -179,    41,   155,   168,   954,  -179,  -179,
     178,   172,   191,  -179,   355,   890,  -179,   176,  -179,   185,
     196,   199,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
     293,  -179,   182,   102,  -179,  -179,   205,  -179,  -179,   188,
    -179,   890,  -179,  -179,  -179,   214,  -179,   783,   890,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,   108,   217,   386,  -179,
     954,  -179,  -179,   822,  -179,   417,  -179,   890,  -179,  -179,
    -179,  -179,  -179,  -179,   448,   954,  -179,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     1,    98,     0,     0,     0,    41,     0,   100,
       0,     0,     0,     0,    99,    26,   108,    97,     0,     0,
       0,     0,     0,     2,     3,     4,    24,    25,    23,     0,
     102,   103,     0,    96,   101,    21,    22,   127,   128,     0,
     131,     0,     0,    39,    40,     0,     0,     0,     0,    85,
      53,     0,   106,     0,    87,    70,     0,    71,     0,    84,
       0,    37,     0,     0,     0,    86,     0,     0,    36,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    83,
       0,     6,     0,    46,    42,     0,     0,    63,    64,    67,
       0,    65,     0,     0,   104,     0,    80,    81,    82,    92,
      95,    88,    89,    93,    94,    74,    75,    76,    77,    78,
      79,    91,    90,   110,     0,   108,   112,     0,     0,   133,
     112,    10,     0,     0,     0,     0,     0,     0,    44,    52,
      53,     0,    62,     0,     0,     0,   109,   105,     0,   117,
       0,   130,   132,     0,     0,   135,     0,     0,     9,    12,
      10,     0,   112,     0,    59,    45,    47,    48,    49,    51,
       0,    46,   107,    66,    73,     0,    69,     0,   111,     0,
       0,   112,   120,   129,   133,     0,    53,   112,     0,     0,
       0,     0,    17,    57,     0,     0,    58,    61,    50,    43,
       0,     0,     0,   114,     0,     0,   118,     0,   112,     0,
       0,     0,    33,   126,   124,    32,    30,    31,    29,    27,
       0,    28,    13,     0,    11,   112,     0,    20,    55,     0,
      54,     0,    72,    68,   116,     0,   113,     0,     0,   119,
     112,    35,    34,   125,   123,    15,     0,     0,     0,    56,
      60,   115,   112,     0,   134,     0,    15,     0,    16,    19,
     121,   112,     8,    14,     0,    18,   122,     7
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,  -179,  -179,    82,  -179,    63,    -4,  -179,  -179,
    -179,     1,    35,  -179,  -178,  -176,  -179,  -172,  -179,    83,
    -179,  -179,  -134,  -153,  -179,  -179,  -179,    -3,   115,   179,
     -17,   -50,  -179,    -7,  -179,   140,  -179,  -108,  -179,  -171,
    -169,  -179,  -179,    29,  -162,  -179,    87,  -179,  -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    23,   132,   157,   158,   159,   255,    24,   134,
     248,   263,   214,   215,    26,    27,    42,    28,    51,   138,
     165,   139,    93,   166,   194,   195,   196,    29,    99,   100,
      30,    58,    31,    32,    33,    52,    34,   148,   204,   149,
      35,   182,   220,   155,    36,    86,   153,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    45,    25,    57,    43,    49,   171,   216,   103,   217,
     206,   193,    54,   218,    59,    60,   219,    65,    79,    80,
     178,    46,   154,   221,   174,   142,    94,    39,   143,    84,
      47,    48,    83,    40,    87,   175,    85,   239,    81,   179,
      78,    57,   216,    50,   217,    82,   101,    95,   218,   102,
      98,   219,   222,   144,   191,   106,   107,   108,   221,   109,
     110,    55,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   101,   136,   249,    56,    98,   223,
       3,   260,   107,    41,     3,   135,    57,   228,   229,   141,
     266,     8,    53,     9,   178,     8,    12,     9,   145,   137,
      12,    61,    14,    90,    16,    17,    14,    19,    16,    17,
      18,    19,    20,   185,    88,    21,    20,   246,   178,    21,
      22,   151,   152,    91,    22,    97,   169,    92,   178,   168,
     170,    62,   154,   167,   178,   146,   101,   227,   143,    -1,
      98,    63,    64,   183,   180,   181,    65,   245,    66,    67,
      65,   207,   208,   256,   190,    96,   192,   197,    69,    70,
     125,   127,    71,    72,    73,    74,    75,    76,    77,    78,
      75,    76,    77,    78,   128,    62,   172,   152,   131,   129,
     203,   140,    65,   150,   156,    63,    64,   160,   184,   161,
      65,   162,    66,    67,   186,   187,   188,   200,   237,   201,
     205,   230,    69,    70,   225,   236,    71,    72,    73,    74,
      75,    76,    77,    78,   232,   231,   233,   234,     2,   238,
     198,     3,   241,     4,   250,   242,     5,     6,     7,   240,
     137,   253,     8,   164,     9,    10,    11,    12,    13,   247,
     251,   257,   189,    14,    15,    16,    17,    18,    19,   259,
     265,   224,   264,    20,   199,   244,    21,     3,   173,     4,
     124,    22,     5,     6,     7,   147,   210,   211,     8,   254,
       9,   209,     0,    12,    13,     0,     0,     0,     0,    14,
     212,    16,    17,    18,    19,     0,     0,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     3,    22,     4,     0,
     213,     5,     6,     7,     0,   210,   211,     8,     0,     9,
       0,     0,    12,    13,     0,     0,     0,     0,    14,   212,
      16,    17,    18,    19,     0,     0,     0,     3,    20,     4,
       0,    21,     5,     6,     7,     0,    22,     0,     8,   243,
       9,     0,     0,    12,    13,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     3,    20,
       4,     0,    21,     5,     6,     7,     0,    22,     0,     8,
     202,     9,     0,     0,    12,    13,     0,     0,     0,     0,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     3,
      20,     4,     0,    21,     5,     6,     7,     0,    22,     0,
       8,   235,     9,     0,     0,    12,    13,     0,     0,     0,
       0,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       3,    20,     4,     0,    21,     5,     6,     7,     0,    22,
       0,     8,   258,     9,     0,     0,    12,    13,     0,     0,
       0,     0,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     3,    20,     4,     0,    21,     5,     6,     7,     0,
      22,     0,     8,   262,     9,     0,     0,    12,    13,     0,
      62,     0,     0,    14,    15,    16,    17,    18,    19,     0,
      63,    64,     0,    20,     0,    65,    21,    66,    67,     0,
       0,    22,     0,     0,   267,     0,    62,    69,    70,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    62,
     104,    65,     0,   105,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,    65,     0,    66,    67,     0,    73,
      74,    75,    76,    77,    78,     0,    69,    70,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    62,   176,
       0,     0,   177,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,    65,     0,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    62,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    63,    64,     0,
       0,   105,    65,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    62,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    63,    64,     0,     0,
     163,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,     3,     0,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     8,     0,     9,   226,
       0,    12,     0,     0,     0,     0,     0,    14,     3,    16,
      17,    18,    19,     0,     0,     0,     0,    20,     0,     8,
      21,     9,     0,     0,    12,    22,     0,   164,     0,     0,
      14,     3,    16,    17,     0,    19,     0,     0,     0,     0,
      20,     0,     8,    21,     9,     0,     0,    12,    22,     0,
     164,     0,     0,    14,     0,    16,    17,    18,    19,    62,
       0,     0,     0,    20,     0,     0,    21,     0,     0,    63,
      64,    22,   123,     0,    65,     0,    66,    67,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    62,   126,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,    65,     0,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    62,   130,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,     0,
       0,     0,    65,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    62,   252,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
       0,    65,     0,    66,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,     0,     3,    71,    72,    73,
      74,    75,    76,    77,    78,     0,   261,     8,     0,     9,
       0,     0,    12,     3,     0,     0,     0,     0,    14,     0,
      16,    17,    18,    19,     8,     0,     9,     0,    20,    12,
       0,    21,     0,     3,     0,    14,    22,    16,    17,     0,
      19,     0,     0,   133,     8,    20,     9,     0,    21,    12,
       3,     0,     0,    22,     0,    14,     0,    16,    17,     0,
      19,     0,     0,     9,     0,    20,    12,     0,    21,    62,
       0,     0,    14,    22,    16,    17,     0,    19,     0,    63,
      64,     0,    20,     0,    65,    21,    66,    67,     0,     0,
      22,    68,     0,     0,     0,     0,    69,    70,    62,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    63,    64,
       0,     0,     0,    65,     0,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    62,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    89,    64,     0,
       0,     0,    65,     0,    66,    67,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    62,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    63,     0,     0,     0,
       0,    65,     0,    66,    67,     0,     0,     0,     0,     0,
      62,     0,     0,    69,    70,     0,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    65,     0,    66,    67,     0,
       0,     0,     0,     0,    62,     0,     0,    69,    70,     0,
       0,    71,    72,    73,    74,    75,    76,    77,    78,    65,
       0,    66,    67,     0,     0,     0,     0,     0,    62,     0,
       0,    69,     0,     0,     0,    71,    72,    73,    74,    75,
      76,    77,    78,    65,     0,    66,    67,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,    71,
      72,    73,    74,    75,    76,    77,    78,    65,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,    76,    77,
      78
};

static const yytype_int16 yycheck[] =
{
       7,     8,     1,    20,     7,    12,   140,   185,    58,   185,
     181,   164,    19,   185,    21,    22,   185,    19,    23,    24,
      26,    11,   130,   185,    36,    44,    26,    43,    47,    20,
      20,    27,    39,    43,    41,    47,    27,   208,    43,    45,
      42,    58,   220,    27,   220,    50,    53,    47,   220,    56,
      53,   220,   186,   103,   162,    62,    63,    64,   220,    66,
      67,    27,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    24,   229,    43,    81,   187,
       3,   252,    89,    43,     3,    92,   103,    46,    47,    96,
     261,    14,    43,    16,    26,    14,    19,    16,   105,    48,
      19,    26,    25,    27,    27,    28,    25,    30,    27,    28,
      29,    30,    35,    45,    26,    38,    35,   225,    26,    38,
      43,   128,   129,    27,    43,    44,    49,    43,    26,   136,
     137,     4,   240,   136,    26,    44,   143,    45,    47,    19,
     143,    14,    15,   150,     6,     7,    19,    45,    21,    22,
      19,     6,     7,    45,   161,    48,   163,   164,    31,    32,
      27,    27,    35,    36,    37,    38,    39,    40,    41,    42,
      39,    40,    41,    42,    24,     4,    49,   184,    43,    51,
     179,    27,    19,    24,    20,    14,    15,    43,    51,    24,
      19,    44,    21,    22,    27,    44,    47,    16,   205,    25,
      43,    46,    31,    32,    44,   204,    35,    36,    37,    38,
      39,    40,    41,    42,    36,    47,    44,    26,     0,    43,
      49,     3,    26,     5,   231,    26,     8,     9,    10,    44,
      48,   238,    14,    45,    16,    17,    18,    19,    20,    34,
      26,    24,   160,    25,    26,    27,    28,    29,    30,   248,
     257,   188,   256,    35,   171,   220,    38,     3,   143,     5,
      81,    43,     8,     9,    10,   125,    12,    13,    14,   240,
      16,   184,    -1,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,     3,    43,     5,    -1,
      46,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,     3,    35,     5,
      -1,    38,     8,     9,    10,    -1,    43,    -1,    14,    46,
      16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,     3,    35,
       5,    -1,    38,     8,     9,    10,    -1,    43,    -1,    14,
      46,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,     3,
      35,     5,    -1,    38,     8,     9,    10,    -1,    43,    -1,
      14,    46,    16,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
       3,    35,     5,    -1,    38,     8,     9,    10,    -1,    43,
      -1,    14,    46,    16,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,     3,    35,     5,    -1,    38,     8,     9,    10,    -1,
      43,    -1,    14,    46,    16,    -1,    -1,    19,    20,    -1,
       4,    -1,    -1,    25,    26,    27,    28,    29,    30,    -1,
      14,    15,    -1,    35,    -1,    19,    38,    21,    22,    -1,
      -1,    43,    -1,    -1,    46,    -1,     4,    31,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,     4,
      44,    19,    -1,    47,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,    37,
      38,    39,    40,    41,    42,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,     4,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     4,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    14,    15,    -1,
      -1,    47,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,     4,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    14,    15,    -1,    -1,
      47,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,     3,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    14,    -1,    16,    47,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    25,     3,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    -1,    14,
      38,    16,    -1,    -1,    19,    43,    -1,    45,    -1,    -1,
      25,     3,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    14,    38,    16,    -1,    -1,    19,    43,    -1,
      45,    -1,    -1,    25,    -1,    27,    28,    29,    30,     4,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    14,
      15,    43,    44,    -1,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,     4,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,     4,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,     4,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,     3,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    44,    14,    -1,    16,
      -1,    -1,    19,     3,    -1,    -1,    -1,    -1,    25,    -1,
      27,    28,    29,    30,    14,    -1,    16,    -1,    35,    19,
      -1,    38,    -1,     3,    -1,    25,    43,    27,    28,    -1,
      30,    -1,    -1,    33,    14,    35,    16,    -1,    38,    19,
       3,    -1,    -1,    43,    -1,    25,    -1,    27,    28,    -1,
      30,    -1,    -1,    16,    -1,    35,    19,    -1,    38,     4,
      -1,    -1,    25,    43,    27,    28,    -1,    30,    -1,    14,
      15,    -1,    35,    -1,    19,    38,    21,    22,    -1,    -1,
      43,    26,    -1,    -1,    -1,    -1,    31,    32,     4,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,     4,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    14,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,     4,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    14,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    31,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    31,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    19,    -1,    21,    22,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    19,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,     0,     3,     5,     8,     9,    10,    14,    16,
      17,    18,    19,    20,    25,    26,    27,    28,    29,    30,
      35,    38,    43,    54,    60,    63,    66,    67,    69,    79,
      82,    84,    85,    86,    88,    92,    96,    99,   100,    43,
      43,    43,    68,    79,    85,    85,    11,    20,    27,    85,
      27,    70,    87,    43,    85,    27,    43,    82,    83,    85,
      85,    26,     4,    14,    15,    19,    21,    22,    26,    31,
      32,    35,    36,    37,    38,    39,    40,    41,    42,    23,
      24,    43,    50,    85,    20,    27,    97,    85,    26,    14,
      27,    27,    43,    74,    26,    47,    48,    44,    79,    80,
      81,    85,    85,    83,    44,    47,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    44,    81,    27,    44,    27,    24,    51,
      44,    43,    55,    33,    61,    85,    24,    48,    71,    73,
      27,    85,    44,    47,    83,    85,    44,    87,    89,    91,
      24,    85,    85,    98,    89,    95,    20,    56,    57,    58,
      43,    24,    44,    47,    45,    72,    75,    79,    85,    49,
      85,    74,    49,    80,    36,    47,    44,    47,    26,    45,
       6,     7,    93,    85,    51,    45,    27,    44,    47,    56,
      85,    89,    85,    75,    76,    77,    78,    85,    49,    71,
      16,    25,    46,    63,    90,    43,    91,     6,     7,    98,
      12,    13,    26,    46,    64,    65,    66,    67,    69,    92,
      94,    96,    74,    89,    58,    44,    47,    45,    46,    47,
      46,    47,    36,    44,    26,    46,    63,    85,    43,    91,
      44,    26,    26,    46,    64,    45,    89,    34,    62,    75,
      85,    26,    44,    85,    95,    59,    45,    24,    46,    63,
      91,    44,    46,    63,    59,    85,    91,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    55,    54,    54,    56,
      56,    57,    57,    58,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    67,    68,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    97,    98,    98,    99,   100
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
       3,     1,     4,     3,     1,     1,     3,     1,     7,     5,
       1,     1,     7,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     2,     4,     0,     4,
       3,     2,     0,     2,     1,     5,     4,     5,     7,     8,
       6,     5,     6,     2,     1,     4,     3,     1,     1,     4,
       3,     0,     1,     0,     9,     5
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
#line 94 "parser.y"
                          { insertType((yyvsp[0].name), Func, (yyvsp[-1].eletype));  printSymbolTable();}
#line 1761 "y.tab.c"
    break;

  case 68:
#line 146 "parser.y"
                                                            {  (yyval.eletype) = pointCheck((yyvsp[-5].eletype), (yyvsp[-3].eletype)); }
#line 1767 "y.tab.c"
    break;

  case 69:
#line 147 "parser.y"
                                               {  (yyval.eletype) = pointCheck((yyvsp[-3].eletype), (yyvsp[-1].eletype)); }
#line 1773 "y.tab.c"
    break;

  case 72:
#line 152 "parser.y"
                                                  {(yyval.eletype) = REAL;}
#line 1779 "y.tab.c"
    break;

  case 73:
#line 153 "parser.y"
                                      {(yyval.eletype) = REAL;}
#line 1785 "y.tab.c"
    break;

  case 74:
#line 156 "parser.y"
                                       {(yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)); cout << (yyval.eletype) << "\n";}
#line 1791 "y.tab.c"
    break;

  case 75:
#line 157 "parser.y"
                                         {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1797 "y.tab.c"
    break;

  case 76:
#line 158 "parser.y"
                                        {(yyval.eletype) = arithTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1803 "y.tab.c"
    break;

  case 77:
#line 159 "parser.y"
                                        {(yyval.eletype) = arithTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1809 "y.tab.c"
    break;

  case 78:
#line 160 "parser.y"
                                        {(yyval.eletype) = arithTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1815 "y.tab.c"
    break;

  case 79:
#line 161 "parser.y"
                                        {(yyval.eletype) = arithTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 1821 "y.tab.c"
    break;

  case 80:
#line 162 "parser.y"
                                            {if((yyvsp[-2].eletype) == POINT && (yyvsp[0].eletype) == POINT) (yyval.eletype) = LINE ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 1827 "y.tab.c"
    break;

  case 81:
#line 163 "parser.y"
                                             {if((yyvsp[-2].eletype) == LINE && (yyvsp[0].eletype) == LINE) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 1833 "y.tab.c"
    break;

  case 82:
#line 164 "parser.y"
                                                   {if((yyvsp[-2].eletype) == LINE && (yyvsp[0].eletype) == LINE) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
#line 1839 "y.tab.c"
    break;

  case 83:
#line 165 "parser.y"
                                            {if ((yyvsp[-1].eletype) != POINT) semanticError("Error: Semantic error incompatible datatype") ; (yyval.eletype) = REAL; }
#line 1845 "y.tab.c"
    break;

  case 84:
#line 166 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 1851 "y.tab.c"
    break;

  case 85:
#line 167 "parser.y"
                               {if(!((yyvsp[0].eletype) == INT || (yyvsp[0].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);  }
#line 1857 "y.tab.c"
    break;

  case 86:
#line 168 "parser.y"
                               {if(!((yyvsp[-1].eletype) == INT || (yyvsp[-1].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);  }
#line 1863 "y.tab.c"
    break;

  case 87:
#line 169 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);}
#line 1869 "y.tab.c"
    break;

  case 88:
#line 170 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1875 "y.tab.c"
    break;

  case 89:
#line 171 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1881 "y.tab.c"
    break;

  case 92:
#line 174 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1887 "y.tab.c"
    break;

  case 93:
#line 175 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1893 "y.tab.c"
    break;

  case 94:
#line 176 "parser.y"
                                         {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)) && (yyvsp[-2].eletype)==LABEL && (yyvsp[0].eletype) == LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1899 "y.tab.c"
    break;

  case 95:
#line 177 "parser.y"
                                              {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)) && (yyvsp[-2].eletype) == LABEL && (yyvsp[0].eletype) == LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 1905 "y.tab.c"
    break;

  case 97:
#line 179 "parser.y"
                     {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1911 "y.tab.c"
    break;

  case 98:
#line 180 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1917 "y.tab.c"
    break;

  case 99:
#line 181 "parser.y"
                           {(yyval.eletype) = (yyvsp[0].eletype);  cout<< (yyval.eletype);}
#line 1923 "y.tab.c"
    break;

  case 100:
#line 182 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1929 "y.tab.c"
    break;

  case 102:
#line 184 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1935 "y.tab.c"
    break;

  case 103:
#line 185 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1941 "y.tab.c"
    break;

  case 104:
#line 185 "parser.y"
                                                               {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1947 "y.tab.c"
    break;


#line 1951 "y.tab.c"

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
#line 227 "parser.y"


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
       if (arithCompatible(x) && arithCompatible(y))
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
