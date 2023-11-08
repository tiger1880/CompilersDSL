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
bool arithCompatible(int e);
void semanticError(const char* s);
void typeUpdate(vector<char*>* v, enum eletype t);
void insert(char* name, vector<int>* dim, enum eletype t);
bool coercible(int t1, int t2);

int ret_flag = 0;
int ret_fig_flag = 0;

enum eletype ret_type = UNDEF;


#line 104 "parser.tab.c"

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
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    SUM_ASSIGN_OP = 279,
    SUB_ASSIGN_OP = 280,
    EQUAL = 281,
    STRING_TOKEN = 282,
    ENDLINE = 283,
    ID = 284,
    FLOATS = 285,
    TRICONSTRUCT = 286,
    CIRCLECONSTRUCT = 287,
    PARACONSTRUCT = 288,
    REGPOLYCONSTRUCT = 289,
    NOT = 290,
    AND = 291,
    OR = 292,
    SCALE = 293,
    CENTER = 294,
    NEG = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "parser.y"

    char* name; 
    enum eletype eletype;  
    vector<char*>* nameList;
    vector<int>* dimList;

#line 204 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#define YYLAST   1319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  281

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,    46,     2,     2,
      49,    50,    44,    42,    53,    43,    56,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,     2,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    57,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   111,   111,   111,   116,   127,   137,   137,
     139,   139,   141,   143,   143,   146,   147,   148,   149,   149,
     152,   152,   152,   152,   152,   152,   153,   153,   153,   153,
     153,   153,   153,   155,   155,   157,   157,   159,   161,   161,
     161,   163,   165,   166,   169,   170,   174,   175,   176,   180,
     181,   184,   185,   186,   187,   190,   190,   191,   191,   192,
     192,   193,   193,   195,   195,   196,   196,   196,   196,   198,
     198,   200,   200,   202,   203,   206,   206,   208,   209,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   244,
     245,   246,   247,   249,   250,   253,   253,   255,   255,   258,
     258,   262,   262,   263,   263,   265,   266,   267,   268,   271,
     272,   277,   277,   278,   278,   280,   280,   282,   282,   282,
     283,   283,   284,   286
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
  "DATATYPE", "CMP_OP", "EQ_CMP_OP", "ASSIGN_OP", "SUM_ASSIGN_OP",
  "SUB_ASSIGN_OP", "EQUAL", "STRING_TOKEN", "ENDLINE", "ID", "FLOATS",
  "TRICONSTRUCT", "CIRCLECONSTRUCT", "PARACONSTRUCT", "REGPOLYCONSTRUCT",
  "NOT", "AND", "OR", "SCALE", "CENTER", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "NEG", "'^'", "'('", "')'", "'{'", "'}'", "','", "'['",
  "']'", "'.'", "'|'", "$accept", "program", "func", "arg_list", "list1",
  "argument", "func_body", "fig", "params", "fig_body", "stmt",
  "stmt_loop", "break_stmt", "assign_stmt", "return_stmt", "ret_var",
  "decl_stmt", "ID_LIST", "decl_assign", "decl_token", "dim", "check_arr",
  "arr_assign", "comma_arr_assign", "arr1d_in_list", "mult_elements",
  "construct", "constructor", "valid_arg", "param_list", "point", "vertex",
  "angle", "expression", "assign", "id_list", "arr_access", "func_call",
  "empty_space", "stmt_list", "stmt_block", "cond_stmt", "elif_stmt",
  "stmt_loop_list", "stmt_loop_block", "loop", "for_loop_decl",
  "optional_arg", "for_loop", "while_loop", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      60,    62,    43,    45,    42,    47,    37,   295,    94,    40,
      41,   123,   125,    44,    91,    93,    46,   124
};
# endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -192,   300,  -192,  -192,   -33,    -9,    61,  1107,  1148,  -192,
      14,     0,  1148,    13,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  1148,    65,  1148,  1148,  -192,  -192,  -192,  -192,
    -192,  -192,    85,    78,  -192,  -192,  1188,   -12,  -192,  -192,
    -192,  -192,  -192,  1148,    80,  1148,    94,  -192,  1223,  1236,
     100,   102,    81,   116,    83,    -8,    86,  -192,  -192,  1148,
    -192,    65,     9,   644,  -192,   886,  1148,  1148,  1148,  -192,
    1148,  1148,  -192,  1148,  1148,  1148,  1148,  1148,  1148,  1148,
    1148,  1148,  1148,  1148,  1148,  1148,  1148,   911,   112,  -192,
     943,   119,   125,    88,   986,  -192,  1155,   104,   107,  1130,
     109,   103,   133,  -192,   136,  1148,   730,    65,  -192,  1148,
    -192,  -192,  -192,   -27,  1223,   -13,   674,  1271,     5,   142,
     237,   717,     5,     5,   -13,   -13,     9,     9,     9,     9,
    1223,  1223,  1223,  1223,  -192,    53,  -192,  -192,   141,  1148,
    1148,  -192,   152,   152,   148,   126,   765,   108,   156,  1148,
     835,  -192,    83,   206,   -14,   687,  -192,  1107,  -192,    86,
      60,    98,  1148,  1223,  1223,   122,    67,  -192,   151,   131,
     150,  -192,   139,  1148,  -192,  1148,  1148,   103,  -192,   251,
     858,  -192,  -192,  -192,  1223,   133,  -192,  -192,   179,  -192,
     178,  -192,  -192,   432,   157,  -192,   101,  1223,  1148,   342,
      83,  -192,   152,  -192,   800,    68,  1223,  -192,  -192,    63,
     155,   160,  1223,  -192,   167,   159,   186,  -192,   477,  1148,
    -192,   166,  -192,   168,   188,   189,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,   387,  -192,  -192,    69,  -192,    73,
     183,  -192,  -192,   172,  -192,  1148,  -192,  -192,  -192,   196,
    -192,  1029,  1148,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,   200,   522,  -192,  1223,  -192,  -192,  1072,  -192,   567,
     612,  1148,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  1223,
    -192
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     1,   102,     0,     0,     0,    40,     0,   104,
       0,     0,     0,     0,   103,    25,   116,   101,    65,    66,
      67,    68,     0,     0,     0,     0,     2,     3,     4,    23,
      24,    22,     0,     0,   106,   107,     0,   100,   105,    20,
      21,   135,   136,     0,   139,     0,     0,    38,    39,     0,
       0,     0,     0,    90,    54,     0,   114,    92,    75,     0,
      76,     0,    89,     0,    36,     0,     0,     0,     0,    91,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,     0,    37,    88,     0,     0,     0,
       0,    51,    45,    41,     0,     0,     0,     0,   108,     0,
      64,    69,    72,     0,    70,    85,    86,    87,    96,    99,
      93,    94,    97,    98,    79,    80,    81,    82,    83,    84,
     110,   111,   112,   109,   118,     0,   116,   120,     0,     0,
     141,   120,     9,     9,     0,     0,     0,    52,     0,     0,
       0,    43,    54,     0,     0,     0,    63,     0,   117,   113,
       0,   125,     0,   138,   140,     0,     0,   143,     0,     0,
       8,    11,     0,     0,   120,     0,     0,    53,    50,     0,
      60,    44,    46,    47,    48,    45,   115,    78,     0,    74,
       0,    71,   119,     0,     0,   120,   128,   137,   141,     0,
      54,   120,     0,   120,     0,     0,    16,    49,    58,     0,
       0,    59,    62,    42,     0,     0,     0,   122,     0,     0,
     126,     0,   120,     0,     0,     0,    32,   134,   132,    31,
      29,    30,    28,    26,     0,    27,    12,     0,    10,     0,
       0,    19,    56,     0,    55,     0,    77,    73,   124,     0,
     121,     0,     0,   127,   120,    34,    33,   133,   131,    14,
      14,     0,     0,    57,    61,   123,   120,     0,   142,     0,
       0,     0,    15,    18,   129,   120,     7,    13,     6,    17,
     130
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,    87,  -192,    27,   -29,  -192,  -192,  -192,
       1,    -2,  -192,  -191,  -169,  -192,  -117,  -192,    48,  -192,
      89,  -145,  -158,  -192,  -192,  -192,    -3,  -192,    77,   153,
     -20,   -51,  -192,    -7,  -192,  -192,    99,  -192,  -120,  -192,
    -176,  -113,  -192,  -192,   -17,  -108,  -192,    41,  -192,  -192
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   169,   170,   171,   269,    27,   145,   262,
     277,   228,   229,    29,    30,    46,    31,    55,   151,   181,
     101,   102,   182,   209,   210,   211,    32,    33,   112,   113,
      34,    61,    35,    36,    89,    37,    56,    38,   160,   218,
     161,    39,   196,   234,   167,    40,    93,   165,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    49,    28,    60,    47,    53,    69,   185,   230,    66,
     107,    83,    84,    85,    86,    57,    43,    62,    63,   220,
     103,   166,   208,   156,    69,    50,   157,   187,    69,    52,
     231,    79,    80,    81,    51,    82,    90,    87,    94,   188,
      44,    60,    54,   230,    88,   104,   253,    77,    78,    79,
      80,    81,   106,    82,   205,   236,   154,    82,   114,   115,
     116,   117,   111,   118,   119,   231,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     114,   237,   232,   239,   111,   263,   233,    60,   192,   116,
     274,   235,   146,   148,    58,   192,   192,   192,   153,   280,
      91,   192,   155,   158,   194,   195,   157,   221,   222,    92,
      45,   193,     3,    64,    59,   242,   243,   232,   199,   241,
     259,   233,    95,     8,   260,     9,   235,    65,    12,    97,
      99,    98,   163,   164,   166,    -1,    14,   100,    16,    17,
     105,   136,   179,   184,    22,   140,    66,   183,   138,    23,
     114,   139,    24,   142,   111,   197,   143,   149,    25,   150,
      66,    69,   176,    70,   147,   152,   204,   162,   206,   148,
      67,    68,   168,   212,   173,    69,   174,    70,    71,   198,
     200,   201,    75,    76,    77,    78,    79,    80,    81,   203,
      82,   164,    73,    74,   217,   214,    75,    76,    77,    78,
      79,    80,    81,   202,    82,   215,   219,   244,   246,   247,
      66,   178,   251,   245,   248,   252,   255,   256,   254,   250,
      67,    68,   261,   180,   265,    69,   271,    70,    71,   238,
     172,   270,   258,   213,   191,   159,   177,   268,   264,   223,
     135,    66,    73,    74,     0,   267,    75,    76,    77,    78,
      79,    80,    81,     0,    82,    66,    69,     0,    70,    71,
       0,   186,     0,   273,   279,    67,    68,     0,     0,     0,
      69,     0,    70,    71,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,     0,    82,     0,    73,    74,     0,
       0,    75,    76,    77,    78,    79,    80,    81,     0,    82,
       2,     0,     0,     3,     0,     4,   207,     0,     5,     6,
       7,     0,     0,     0,     8,     0,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     0,
      23,     0,     0,    24,     0,     3,     0,     4,     0,    25,
       5,     6,     7,     0,   224,   225,     8,     0,     9,     0,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    14,
     226,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,    23,     0,     0,    24,     0,     0,     0,     0,
       3,    25,     4,     0,   227,     5,     6,     7,     0,   224,
     225,     8,     0,     9,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,    14,   226,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     0,     0,     3,    25,     4,     0,   257,
       5,     6,     7,     0,     0,     0,     8,     0,     9,     0,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,    23,     0,     0,    24,     0,     0,     0,     0,
       3,    25,     4,     0,   216,     5,     6,     7,     0,     0,
       0,     8,     0,     9,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     0,     0,     3,    25,     4,     0,   249,
       5,     6,     7,     0,     0,     0,     8,     0,     9,     0,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,    23,     0,     0,    24,     0,     0,     0,     0,
       3,    25,     4,     0,   272,     5,     6,     7,     0,     0,
       0,     8,     0,     9,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     0,     0,     3,    25,     4,     0,   276,
       5,     6,     7,     0,     0,     0,     8,     0,     9,     0,
       0,    12,    13,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    66,     0,
       0,     0,    23,     0,     0,    24,     0,     0,    67,    68,
       0,    25,     0,    69,   278,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
      73,    74,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    66,    82,    69,   108,    70,    71,   109,     0,     0,
       0,    67,    68,     0,     0,     0,    69,     0,    70,    71,
      73,    74,     0,     0,    75,    76,    77,    78,    79,    80,
      81,    66,    82,    73,    74,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    66,    82,    69,   189,    70,    71,
     190,     0,     0,     0,    67,    68,     0,     0,     0,    69,
       0,    70,    71,    73,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,     0,    82,    73,    74,     0,    66,
      75,    76,    77,    78,    79,    80,    81,     0,    82,    67,
      68,     0,     0,   109,    69,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,     0,    66,    75,    76,    77,    78,    79,
      80,    81,     0,    82,    67,    68,     0,     0,   175,    69,
       0,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    74,     3,     0,
      75,    76,    77,    78,    79,    80,    81,     0,    82,     8,
       0,     9,     0,   240,    12,     0,     0,     0,     0,     0,
       0,     3,    14,     0,    16,    17,    18,    19,    20,    21,
      22,     0,     8,     0,     9,    23,     0,    12,    24,     0,
       0,     0,     0,     0,    25,    14,   180,    16,    17,     3,
       0,     0,     0,    22,     0,     0,     0,     0,    23,     0,
       8,    24,     9,     0,     0,    12,     0,    25,     0,   180,
       0,     0,     0,    14,     3,    16,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     8,    23,     9,     0,    24,
      12,     0,     0,     0,     0,    25,   110,     0,    14,     0,
      16,    17,    18,    19,    20,    21,    22,    66,     0,     0,
       0,    23,     0,     0,    24,     0,     0,    67,    68,     0,
      25,   134,    69,     0,    70,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      66,    82,     0,   137,     0,     0,     0,     0,     0,     0,
      67,    68,     0,     0,     0,    69,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    73,    74,     0,     0,    75,    76,    77,    78,
      79,    80,    81,    66,    82,     0,   141,     0,     0,     0,
       0,     0,     0,    67,    68,     0,     0,     0,    69,     0,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    66,    82,     0,   266,
       0,     0,     0,     0,     0,     0,    67,    68,     0,     0,
       0,    69,     0,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
       3,     0,    75,    76,    77,    78,    79,    80,    81,     0,
      82,     8,   275,     9,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     3,    14,     0,    16,    17,    18,    19,
      20,    21,    22,     0,     8,     0,     9,    23,     0,    12,
      24,     3,     0,     0,     0,     0,    25,    14,     3,    16,
      17,     0,     8,     0,     9,    22,     0,    12,   144,     0,
      23,     9,     0,    24,    12,    14,     0,    16,    17,    25,
       0,     0,    14,    22,    16,    17,     0,     0,    23,     0,
      22,    24,    66,     0,     0,    23,     0,    25,    24,     0,
       0,     0,    67,    68,    25,     0,     0,    69,     0,    70,
      71,     0,     0,     0,     0,     0,    72,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,    66,    75,    76,
      77,    78,    79,    80,    81,     0,    82,    67,    68,     0,
      66,     0,    69,     0,    70,    71,     0,     0,     0,     0,
      96,    68,     0,     0,     0,    69,     0,    70,    71,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
       0,    82,    73,    74,     0,    66,    75,    76,    77,    78,
      79,    80,    81,     0,    82,    67,     0,     0,     0,     0,
      69,     0,    70,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,    75,    76,    77,    78,    79,    80,    81,     0,    82
};

static const yytype_int16 yycheck[] =
{
       7,     8,     1,    23,     7,    12,    19,   152,   199,     4,
      61,    23,    24,    25,    26,    22,    49,    24,    25,   195,
      28,   141,   180,    50,    19,    11,    53,    41,    19,    29,
     199,    44,    45,    46,    20,    48,    43,    49,    45,    53,
      49,    61,    29,   234,    56,    53,   222,    42,    43,    44,
      45,    46,    59,    48,   174,   200,   107,    48,    65,    66,
      67,    68,    65,    70,    71,   234,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   201,   199,   203,    87,   243,   199,   107,    28,    96,
     266,   199,    99,   100,    29,    28,    28,    28,   105,   275,
      20,    28,   109,    50,     6,     7,    53,     6,     7,    29,
      49,    51,     3,    28,    49,    52,    53,   234,    51,    51,
      51,   234,    28,    14,    51,    16,   234,    49,    19,    29,
      49,    29,   139,   140,   254,    19,    27,    54,    29,    30,
      54,    29,   149,   150,    35,    57,     4,   150,    29,    40,
     157,    26,    43,    49,   157,   162,    49,    54,    49,    26,
       4,    19,    54,    21,    55,    29,   173,    26,   175,   176,
      14,    15,    20,   180,    26,    19,    50,    21,    22,    57,
      29,    50,    40,    41,    42,    43,    44,    45,    46,    50,
      48,   198,    36,    37,   193,    16,    40,    41,    42,    43,
      44,    45,    46,    53,    48,    27,    49,    52,    41,    50,
       4,    55,   219,    53,    28,    49,    28,    28,    50,   218,
      14,    15,    39,    51,    28,    19,    26,    21,    22,   202,
     143,   260,   234,   185,   157,   136,   147,   254,   245,   198,
      87,     4,    36,    37,    -1,   252,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,     4,    19,    -1,    21,    22,
      -1,    55,    -1,   262,   271,    14,    15,    -1,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
       0,    -1,    -1,     3,    -1,     5,    55,    -1,     8,     9,
      10,    -1,    -1,    -1,    14,    -1,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      40,    -1,    -1,    43,    -1,     3,    -1,     5,    -1,    49,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
       3,    49,     5,    -1,    52,     8,     9,    10,    -1,    12,
      13,    14,    -1,    16,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,     3,    49,     5,    -1,    52,
       8,     9,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
       3,    49,     5,    -1,    52,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,     3,    49,     5,    -1,    52,
       8,     9,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,
       3,    49,     5,    -1,    52,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    -1,    -1,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,     3,    49,     5,    -1,    52,
       8,     9,    10,    -1,    -1,    -1,    14,    -1,    16,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     4,    -1,
      -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    14,    15,
      -1,    49,    -1,    19,    52,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     4,    48,    19,    50,    21,    22,    53,    -1,    -1,
      -1,    14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     4,    48,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,     4,    48,    19,    50,    21,    22,
      53,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    19,
      -1,    21,    22,    36,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    36,    37,    -1,     4,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    14,
      15,    -1,    -1,    53,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,     4,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    14,    15,    -1,    -1,    53,    19,
      -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,     3,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    14,
      -1,    16,    -1,    53,    19,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    -1,    14,    -1,    16,    40,    -1,    19,    43,    -1,
      -1,    -1,    -1,    -1,    49,    27,    51,    29,    30,     3,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,
      14,    43,    16,    -1,    -1,    19,    -1,    49,    -1,    51,
      -1,    -1,    -1,    27,     3,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    14,    40,    16,    -1,    43,
      19,    -1,    -1,    -1,    -1,    49,    50,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,     4,    -1,    -1,
      -1,    40,    -1,    -1,    43,    -1,    -1,    14,    15,    -1,
      49,    50,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
       4,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,     4,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,     4,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
       3,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    14,    50,    16,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    -1,    14,    -1,    16,    40,    -1,    19,
      43,     3,    -1,    -1,    -1,    -1,    49,    27,     3,    29,
      30,    -1,    14,    -1,    16,    35,    -1,    19,    38,    -1,
      40,    16,    -1,    43,    19,    27,    -1,    29,    30,    49,
      -1,    -1,    27,    35,    29,    30,    -1,    -1,    40,    -1,
      35,    43,     4,    -1,    -1,    40,    -1,    49,    43,    -1,
      -1,    -1,    14,    15,    49,    -1,    -1,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,     4,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    14,    15,    -1,
       4,    -1,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    36,    37,    -1,     4,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    14,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     3,     5,     8,     9,    10,    14,    16,
      17,    18,    19,    20,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    40,    43,    49,    60,    65,    68,    71,
      72,    74,    84,    85,    88,    90,    91,    93,    95,    99,
     103,   106,   107,    49,    49,    49,    73,    84,    91,    91,
      11,    20,    29,    91,    29,    75,    94,    91,    29,    49,
      88,    89,    91,    91,    28,    49,     4,    14,    15,    19,
      21,    22,    28,    36,    37,    40,    41,    42,    43,    44,
      45,    46,    48,    23,    24,    25,    26,    49,    56,    92,
      91,    20,    29,   104,    91,    28,    14,    29,    29,    49,
      54,    78,    79,    28,    53,    54,    91,    89,    50,    53,
      50,    84,    86,    87,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    50,    87,    29,    50,    29,    26,
      57,    50,    49,    49,    38,    66,    91,    55,    91,    54,
      26,    76,    29,    91,    89,    91,    50,    53,    50,    94,
      96,    98,    26,    91,    91,   105,    96,   102,    20,    61,
      62,    63,    61,    26,    50,    53,    54,    78,    55,    91,
      51,    77,    80,    84,    91,    79,    55,    41,    53,    50,
      53,    86,    28,    51,     6,     7,   100,    91,    57,    51,
      29,    50,    53,    50,    91,    96,    91,    55,    80,    81,
      82,    83,    91,    76,    16,    27,    52,    68,    97,    49,
      98,     6,     7,   105,    12,    13,    28,    52,    69,    70,
      71,    72,    74,    99,   101,   103,    79,    96,    63,    96,
      53,    51,    52,    53,    52,    53,    41,    50,    28,    52,
      68,    91,    49,    98,    50,    28,    28,    52,    69,    51,
      51,    39,    67,    80,    91,    28,    50,    91,   102,    64,
      64,    26,    52,    68,    98,    50,    52,    68,    52,    91,
      98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    64,    64,    65,    66,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    72,    73,    73,
      73,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    79,    79,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   104,
     105,   105,   106,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,    10,    10,     1,     0,
       3,     1,     3,     2,     0,     9,     3,     7,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     3,     1,     1,
       0,     3,     5,     3,     2,     0,     1,     1,     1,     4,
       3,     1,     2,     3,     0,     3,     3,     3,     1,     1,
       0,     3,     1,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     7,     5,     1,     1,     7,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       2,     2,     2,     4,     2,     4,     0,     4,     3,     2,
       0,     2,     1,     5,     4,     5,     7,     8,     6,     5,
       6,     2,     1,     4,     3,     1,     1,     4,     3,     0,
       1,     0,     9,     5
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
  case 5:
#line 111 "parser.y"
                                                     {if(ret_flag) {
       cerr<<"Error: Return statement not allowed outside function"<<endl;
}}
#line 1789 "parser.tab.c"
    break;

  case 6:
#line 116 "parser.y"
                                                                         {
              insertType((yyvsp[-7].name), Func, (yyvsp[-8].eletype));  
              printSymbolTable();
              if(ret_flag==0) {
                     cerr<<"Error: Semantic error no return statement"<<endl;
              }
              else if((yyvsp[-8].eletype)!=ret_type) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0;
       }
#line 1805 "parser.tab.c"
    break;

  case 7:
#line 127 "parser.y"
                                                                      {
              insertType((yyvsp[-7].name), Func, (yyvsp[-8].eletype));  
              printSymbolTable();
              if(ret_type!=UNDEF && ret_type!=Void) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0; 
       }
#line 1818 "parser.tab.c"
    break;

  case 15:
#line 146 "parser.y"
                                                       { if (ret_fig_flag == 1)  semanticError("Error: Return statement is not allowed in figures."); ret_fig_flag =0; }
#line 1824 "parser.tab.c"
    break;

  case 16:
#line 147 "parser.y"
                                   { if(!(arithCompatible((yyvsp[-2].eletype)) && (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
#line 1830 "parser.tab.c"
    break;

  case 17:
#line 148 "parser.y"
                                                            { if(!((yyvsp[-4].eletype) == REAL && (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
#line 1836 "parser.tab.c"
    break;

  case 36:
#line 157 "parser.y"
                                                     {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1842 "parser.tab.c"
    break;

  case 37:
#line 159 "parser.y"
                                     {ret_type = (yyvsp[-1].eletype); ret_flag = 1; ret_fig_flag = 1;}
#line 1848 "parser.tab.c"
    break;

  case 38:
#line 161 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1854 "parser.tab.c"
    break;

  case 39:
#line 161 "parser.y"
                                            {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1860 "parser.tab.c"
    break;

  case 40:
#line 161 "parser.y"
                                                         {(yyval.eletype) = Void;}
#line 1866 "parser.tab.c"
    break;

  case 41:
#line 163 "parser.y"
                                     {typeUpdate((yyvsp[-1].nameList), (yyvsp[-2].eletype));}
#line 1872 "parser.tab.c"
    break;

  case 42:
#line 165 "parser.y"
                                              {(yyval.nameList) = (yyvsp[-4].nameList);(yyval.nameList)->push_back((yyvsp[-2].name));insert((yyvsp[-2].name), (yyvsp[-1].dimList), (yyvsp[0].eletype));}
#line 1878 "parser.tab.c"
    break;

  case 43:
#line 166 "parser.y"
                                  {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-2].name));insert((yyvsp[-2].name), (yyvsp[-1].dimList), (yyvsp[0].eletype));}
#line 1884 "parser.tab.c"
    break;

  case 44:
#line 169 "parser.y"
                               {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1890 "parser.tab.c"
    break;

  case 45:
#line 170 "parser.y"
                      {(yyval.eletype) = UNDEF;}
#line 1896 "parser.tab.c"
    break;

  case 46:
#line 174 "parser.y"
                    {(yyval.eletype) = UNDEF;}
#line 1902 "parser.tab.c"
    break;

  case 47:
#line 175 "parser.y"
                    {(yyval.eletype) = UNDEF;}
#line 1908 "parser.tab.c"
    break;

  case 48:
#line 176 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1914 "parser.tab.c"
    break;

  case 49:
#line 180 "parser.y"
                             {(yyval.dimList) = (yyvsp[-3].dimList);}
#line 1920 "parser.tab.c"
    break;

  case 50:
#line 181 "parser.y"
                         {(yyval.dimList) = new vector<int>; (yyval.dimList)->push_back(1);}
#line 1926 "parser.tab.c"
    break;

  case 51:
#line 184 "parser.y"
               {(yyval.dimList) = (yyvsp[0].dimList);}
#line 1932 "parser.tab.c"
    break;

  case 54:
#line 187 "parser.y"
                       {(yyval.dimList) = new vector<int>;}
#line 1938 "parser.tab.c"
    break;

  case 63:
#line 195 "parser.y"
                                            { (yyval.eletype) = (yyvsp[-3].eletype);}
#line 1944 "parser.tab.c"
    break;

  case 64:
#line 195 "parser.y"
                                                                              { (yyval.eletype) = (yyvsp[-2].eletype);}
#line 1950 "parser.tab.c"
    break;

  case 65:
#line 196 "parser.y"
                           { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1956 "parser.tab.c"
    break;

  case 66:
#line 196 "parser.y"
                                                         { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1962 "parser.tab.c"
    break;

  case 67:
#line 196 "parser.y"
                                                                                     { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1968 "parser.tab.c"
    break;

  case 68:
#line 196 "parser.y"
                                                                                                                    { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1974 "parser.tab.c"
    break;

  case 73:
#line 202 "parser.y"
                                                            {  (yyval.eletype) = pointCheck((yyvsp[-5].eletype), (yyvsp[-3].eletype)); }
#line 1980 "parser.tab.c"
    break;

  case 74:
#line 203 "parser.y"
                                               {  (yyval.eletype) = pointCheck((yyvsp[-3].eletype), (yyvsp[-1].eletype)); }
#line 1986 "parser.tab.c"
    break;

  case 77:
#line 208 "parser.y"
                                                  {(yyval.eletype) = REAL;}
#line 1992 "parser.tab.c"
    break;

  case 78:
#line 209 "parser.y"
                                      {(yyval.eletype) = REAL;}
#line 1998 "parser.tab.c"
    break;

  case 79:
#line 212 "parser.y"
                                        {(yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)); }
#line 2004 "parser.tab.c"
    break;

  case 80:
#line 213 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 2010 "parser.tab.c"
    break;

  case 81:
#line 214 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 2016 "parser.tab.c"
    break;

  case 82:
#line 215 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 2022 "parser.tab.c"
    break;

  case 83:
#line 216 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 2028 "parser.tab.c"
    break;

  case 84:
#line 217 "parser.y"
                                        {if((yyvsp[-2].eletype) == LABEL ||(yyvsp[0].eletype) == LABEL||(yyvsp[-2].eletype) == POINT || (yyvsp[0].eletype) == POINT) semanticError("Error: Semantic error incompatible datatype") ;  (yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)) ;}
#line 2034 "parser.tab.c"
    break;

  case 85:
#line 218 "parser.y"
                                            {if(((yyvsp[-2].eletype) == POINT || (yyvsp[-2].eletype) == LINEARR) && (yyvsp[0].eletype) == POINT) (yyval.eletype) = LINEARR ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 2040 "parser.tab.c"
    break;

  case 86:
#line 219 "parser.y"
                                             {if(((yyvsp[-2].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR) && ((yyvsp[0].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR)) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 2046 "parser.tab.c"
    break;

  case 87:
#line 220 "parser.y"
                                                   {if(((yyvsp[-2].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR) && ((yyvsp[0].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR)) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
#line 2052 "parser.tab.c"
    break;

  case 88:
#line 221 "parser.y"
                                            {if ((yyvsp[-1].eletype) != POINT) semanticError("Error: Semantic error incompatible datatype") ; (yyval.eletype) = REAL; }
#line 2058 "parser.tab.c"
    break;

  case 89:
#line 222 "parser.y"
                                       {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2064 "parser.tab.c"
    break;

  case 90:
#line 223 "parser.y"
                               {if(!((yyvsp[0].eletype) == INT || (yyvsp[0].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);  }
#line 2070 "parser.tab.c"
    break;

  case 91:
#line 224 "parser.y"
                               {if(!((yyvsp[-1].eletype) == INT || (yyvsp[-1].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);  }
#line 2076 "parser.tab.c"
    break;

  case 92:
#line 225 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);}
#line 2082 "parser.tab.c"
    break;

  case 93:
#line 226 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2088 "parser.tab.c"
    break;

  case 94:
#line 227 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2094 "parser.tab.c"
    break;

  case 95:
#line 228 "parser.y"
                              {if(!((yyvsp[0].eletype) == POINT && (yyvsp[-1].eletype) == POINT)||((yyvsp[0].eletype) == LABEL && (yyvsp[-1].eletype) == LABEL || arithCompatible((yyvsp[-1].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);}
#line 2100 "parser.tab.c"
    break;

  case 96:
#line 229 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2106 "parser.tab.c"
    break;

  case 97:
#line 230 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2112 "parser.tab.c"
    break;

  case 98:
#line 231 "parser.y"
                                         {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2118 "parser.tab.c"
    break;

  case 99:
#line 232 "parser.y"
                                              {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype) == (yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2124 "parser.tab.c"
    break;

  case 100:
#line 233 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2130 "parser.tab.c"
    break;

  case 101:
#line 234 "parser.y"
                     {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2136 "parser.tab.c"
    break;

  case 102:
#line 235 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2142 "parser.tab.c"
    break;

  case 103:
#line 236 "parser.y"
                           {(yyval.eletype) = (yyvsp[0].eletype);  cout<< (yyval.eletype);}
#line 2148 "parser.tab.c"
    break;

  case 104:
#line 237 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2154 "parser.tab.c"
    break;

  case 106:
#line 239 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2160 "parser.tab.c"
    break;

  case 107:
#line 240 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2166 "parser.tab.c"
    break;

  case 108:
#line 241 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 2172 "parser.tab.c"
    break;

  case 110:
#line 245 "parser.y"
                                {if(!(arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2178 "parser.tab.c"
    break;

  case 111:
#line 246 "parser.y"
                                    {if(!(arithCompatible((yyvsp[0].eletype)) || (yyvsp[0].eletype) == LABEL || (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2184 "parser.tab.c"
    break;

  case 112:
#line 247 "parser.y"
                                  {if(!(arithCompatible((yyvsp[0].eletype)) || (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);}
#line 2190 "parser.tab.c"
    break;

  case 125:
#line 265 "parser.y"
                                             {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2196 "parser.tab.c"
    break;

  case 126:
#line 266 "parser.y"
                                                              {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2202 "parser.tab.c"
    break;

  case 127:
#line 267 "parser.y"
                                                                       {if(!(arithCompatible((yyvsp[-5].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2208 "parser.tab.c"
    break;

  case 128:
#line 268 "parser.y"
                                                       {if(!(arithCompatible((yyvsp[-3].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2214 "parser.tab.c"
    break;

  case 129:
#line 271 "parser.y"
                                                {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2220 "parser.tab.c"
    break;

  case 130:
#line 272 "parser.y"
                                                         {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2226 "parser.tab.c"
    break;

  case 140:
#line 283 "parser.y"
                         {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2232 "parser.tab.c"
    break;

  case 141:
#line 283 "parser.y"
                                      {(yyval.eletype) = BOOL;}
#line 2238 "parser.tab.c"
    break;

  case 142:
#line 284 "parser.y"
                                                                                       {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype11"); cout<<"k";}
#line 2244 "parser.tab.c"
    break;


#line 2248 "parser.tab.c"

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
#line 289 "parser.y"


/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

void semanticError(const char* s){
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
              cerr << "Error: Semantic error incompatible datatypes+\n";
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

// check int change 
bool arithCompatible(int e){

       if (e == REAL || e == BOOL || e == INT || e == ANGLE) 
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

bool coercible(int t1, int t2){
       
       if (arithCompatible(t1) && arithCompatible(t2))
              return true;

       if (t1 == t2)
              return true;

       /* 
              POINT
              LABEL
              LINE
              CIRCLE
              TRI
              PARA
              REGPOLY 
       */

       return false;      

}

void typeUpdate(vector<char*>* v, enum eletype t){

       for (int i = 0;i < v->size();i++){

              int prevType = checkEletype(v->at(i));
              
              if (prevType == UNDEF)
              {
                     updateType(v->at(i), t);
              }
              else if (!coercible(prevType, t))
              {
                     cerr << "Error: " << "types don't match in declaration and initialisation\n";
                     exit(1);
                     // error recovery
              }
              
              free(v->at(i));
       }

       delete v;

       printSymbolTable();

       return;
}

void insert(char* name, vector<int>* dim, enum eletype t){

       if (dim->size() == 0)
              insertType(name, Var, t);
       else {
              insertType(name, Array, t);
              addDimList(name, *dim); 
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
