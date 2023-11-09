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
#include <math.h>
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




/*     ONLY FOR  DEBUGGING    */
template < typename T >
void print(vector<T>& v){

    for (int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    
    cout << "\n";
}

extern int yydebug;

#define YYDEBUG 1
/*     ONLY FOR  DEBUGGING    */


int ret_flag = 0;
int ret_fig_flag = 0;

enum eletype ret_type = UNDEF;

std::vector<ParamList> paramslist;


#line 117 "parser.tab.c"

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
    BOOLEAN = 259,
    FLOATS = 260,
    LINE_OP = 261,
    IF = 262,
    ELIF = 263,
    ELSE = 264,
    FOR = 265,
    WHILE = 266,
    RETURN = 267,
    VOID = 268,
    CONTINUE = 269,
    BREAK = 270,
    PARALLEL = 271,
    PERPENDICULAR = 272,
    FUNC = 273,
    FIG = 274,
    UNARY = 275,
    DATATYPE = 276,
    CMP_OP = 277,
    EQ_CMP_OP = 278,
    ASSIGN_OP = 279,
    SUM_ASSIGN_OP = 280,
    SUB_ASSIGN_OP = 281,
    EQUAL = 282,
    STRING_TOKEN = 283,
    ENDLINE = 284,
    ID = 285,
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
#line 50 "parser.y"

    char* name; 
    enum eletype eletype;  
    vector<char*>* nameList;
    vector<int>* dimList;
    struct ConstExp {
       enum eletype eletype;  
       union {
              int i;
              double d;
       };
    } constExp;
    struct {
       int count;
       enum eletype eletype;  
    } countAndType;
    struct {
       vector<int>* dimList;
       enum eletype eletype;  
    } listAndType;
    
    

#line 234 "parser.tab.c"

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
#define YYLAST   1264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  330

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
       0,   137,   137,   138,   139,   140,   148,   148,   166,   166,
     183,   183,   185,   185,   187,   202,   202,   206,   206,   207,
     208,   209,   209,   212,   212,   212,   212,   212,   212,   212,
     214,   215,   218,   218,   221,   221,   221,   221,   221,   221,
     221,   221,   223,   223,   225,   225,   227,   227,   230,   232,
     232,   232,   235,   236,   239,   240,   243,   244,   245,   246,
     249,   250,   253,   254,   257,   258,   262,   263,   267,   268,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     303,   304,   305,   306,   312,   313,   316,   317,   318,   319,
     320,   321,   324,   325,   328,   329,   333,   334,   335,   340,
     348,   359,   360,   363,   364,   367,   368,   371,   372,   380,
     393,   405,   417,   428,   431,   443,   450,   457,   458,   459,
     463,   464,   467,   467,   469,   469,   472,   472,   476,   476,
     477,   477,   477,   477,   477,   477,   479,   480,   481,   482,
     485,   486,   491,   491,   492,   492,   493,   493,   496,   496,
     496,   496,   496,   497,   497,   498,   500,   500
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGERS", "BOOLEAN", "FLOATS",
  "LINE_OP", "IF", "ELIF", "ELSE", "FOR", "WHILE", "RETURN", "VOID",
  "CONTINUE", "BREAK", "PARALLEL", "PERPENDICULAR", "FUNC", "FIG", "UNARY",
  "DATATYPE", "CMP_OP", "EQ_CMP_OP", "ASSIGN_OP", "SUM_ASSIGN_OP",
  "SUB_ASSIGN_OP", "EQUAL", "STRING_TOKEN", "ENDLINE", "ID",
  "TRICONSTRUCT", "CIRCLECONSTRUCT", "PARACONSTRUCT", "REGPOLYCONSTRUCT",
  "NOT", "AND", "OR", "SCALE", "CENTER", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "NEG", "'^'", "'('", "')'", "'{'", "'}'", "','", "'['",
  "']'", "'.'", "'|'", "$accept", "construct", "assign_stmt",
  "constructor", "point", "angle", "expression", "member_access", "assign",
  "id_list", "mult_elements", "arr1d_in_list", "const_expr", "check_arr",
  "dim", "arr_assign", "comma_arr_assign", "decl_token", "decl_assign",
  "cond_stmt", "ret_var", "optional_arg", "valid_arg", "program", "func",
  "$@1", "$@2", "arg_list", "list1", "argument", "func_body", "fig", "$@3",
  "params", "fig_body", "stmt", "stmt_list", "stmt_block", "$@4",
  "stmt_loop", "break_stmt", "stmt_loop_list", "stmt_loop_block", "$@5",
  "return_stmt", "param_list", "vertex", "decl_stmt", "arr_access",
  "func_call", "empty_space", "stmt_list1", "stmt_block1", "$@6", "$@7",
  "$@8", "$@9", "elif_stmt", "stmt_loop_list1", "stmt_loop_block1", "loop",
  "for_loop_decl", "$@10", "$@11", "for_loop", "while_loop", "$@12", YY_NULLPTR
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

#define YYPACT_NINF (-284)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -284,   193,  -284,  -284,  -284,  -284,   -35,   -24,   -19,   848,
     910,    24,    12,    16,    22,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,   910,    61,   910,   910,    70,  -284,    72,  -284,
    -284,  1090,   499,  -284,  -284,  -284,  -284,  -284,    39,  -284,
    -284,  -284,  -284,  -284,  -284,   910,   -25,   910,  -284,    52,
    1123,    76,  1156,    78,    81,  -284,    57,   -20,   -18,    65,
    -284,  -284,   910,  -284,    61,    74,   550,  -284,   642,   -12,
     910,   910,   910,   910,   910,  -284,   910,   910,   910,   910,
     910,   910,   910,   910,   910,   910,  -284,   910,   910,   910,
     910,   683,    97,  -284,  -284,   926,    73,   126,   129,   967,
    -284,   620,  -284,  -284,    93,   848,   121,   134,   109,  -284,
    -284,   135,   910,   713,    61,  -284,   910,  -284,  -284,  1123,
    -284,   -41,  -284,    95,  1216,  1189,   139,   994,  1201,   698,
     139,   139,    95,    95,    74,    74,    74,    74,  1123,  1123,
    1123,  1123,  -284,   -10,  -284,   364,  -284,   910,   136,   141,
    -284,   120,   124,   882,  -284,  1123,  -284,  -284,  -284,  -284,
     128,   128,   125,   515,   123,   128,   -20,   112,   -22,   591,
    -284,   848,  -284,    65,  -284,  -284,   146,   107,  1123,   131,
     151,   910,  -284,   168,   168,   164,   746,   144,   186,   652,
     128,   109,   128,   128,   128,   128,   128,   128,  -284,   534,
    -284,   574,   165,  -284,  -284,  -284,   191,  -284,   171,  -284,
    -284,   150,   155,   153,  -284,   142,   910,   910,  1123,    -3,
    -284,   180,   166,   162,  -284,   169,   910,   910,  -284,  -284,
     186,   186,   172,   172,   172,   172,  1123,   176,   183,  -284,
      84,  -284,   123,   196,   189,   826,   188,   910,  -284,   192,
    -284,   194,  1123,   244,   199,  -284,   168,  -284,   779,  1123,
      -2,   910,  -284,  -284,   123,  -284,  -284,  -284,  -284,   398,
    -284,  1008,   910,  -284,  -284,   214,   216,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,   206,  -284,  -284,   287,  -284,  -284,
      -1,  -284,     0,   211,  -284,  1123,  -284,  -284,  -284,   232,
    -284,  1049,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
     235,   432,   237,  -284,  -284,  -284,   330,   466,   500,   910,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  1123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    32,     1,    94,    95,    93,     0,     0,     0,    51,
       0,     0,     0,     0,     0,    96,    28,   143,    56,    57,
      58,    59,     0,     0,     0,     0,     0,    26,     0,    98,
      99,     0,    91,    23,     2,     3,     4,    29,     0,    27,
      25,    97,    24,   166,   167,     0,   168,     0,    49,     0,
      50,     0,     0,     0,     0,    17,    81,   113,     0,   141,
      83,    66,     0,    67,     0,    80,     0,    53,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    86,    31,     0,     0,     0,     0,     0,
      48,    79,     8,     6,     0,     0,     0,   109,   116,   111,
     104,     0,     0,     0,     0,    92,     0,    55,    60,    61,
      63,     0,   105,    76,    77,    78,    87,    90,    84,    85,
      88,    89,    70,    71,    72,    73,    74,    75,   101,   102,
     103,   100,   145,     0,   143,    32,   147,   174,     0,     0,
     176,     0,     0,     0,   114,   115,   112,   138,   139,   137,
       0,     0,   117,     0,     0,     0,   113,     0,     0,     0,
      54,     0,   144,   140,    33,    30,   150,   156,   173,     0,
       0,     0,   147,    11,    11,     0,     0,     0,   135,     0,
       0,   118,     0,     0,     0,     0,     0,     0,   120,   126,
     110,     0,   107,   108,   142,    69,     0,    65,     0,    62,
     146,     0,     0,     0,   147,   159,   174,     0,   171,     0,
     177,     0,     0,    10,    13,     0,     0,     0,   147,   136,
     129,   130,   131,   132,   133,   134,   128,   125,     0,   124,
       0,   119,     0,     0,     0,    32,     0,     0,   157,     0,
     147,     0,   169,    46,     0,   147,     0,   147,     0,    19,
       0,     0,   121,   122,     0,   106,    68,    64,   149,    32,
     154,     0,     0,   158,   147,     0,     0,    40,   165,    37,
      34,   163,    39,    41,     0,    38,    36,    46,    35,    14,
       0,    12,     0,     0,    22,   127,   123,   151,   148,     0,
     147,     0,   175,    43,    42,    45,   164,   162,    16,    16,
       0,    32,     0,   155,   160,   147,    46,    32,    32,     0,
      18,    21,   152,   161,    47,    44,     9,    15,     7,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -284,     9,  -232,    15,   -17,  -284,    -9,   254,  -284,   240,
    -284,  -284,   611,  -156,   118,  -155,  -284,  -284,   103,  -231,
    -284,    55,   110,  -284,  -284,  -284,  -284,    98,  -284,    27,
     -23,  -284,  -284,  -284,  -284,     1,  -284,  -284,  -284,  -283,
    -284,  -284,  -284,  -284,  -230,   197,   -56,  -199,   145,  -284,
    -162,  -284,  -211,  -284,  -284,  -284,  -284,  -284,  -284,    11,
    -193,  -284,  -284,  -284,  -284,  -284,  -284
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    29,    30,    31,    32,    93,    58,
     237,   238,   163,   107,   108,   200,   240,   156,   109,    33,
      51,   179,   120,     1,    34,   152,   151,   222,   223,   224,
     317,    35,   104,   187,   311,   327,   145,    37,    38,   281,
     282,   316,   283,   284,    39,   121,    64,    40,    59,    41,
     176,   269,   177,   211,   312,   212,   299,   215,   287,   220,
      42,    96,    97,    98,    43,    44,   182
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    52,    36,   248,   307,  -170,    63,   105,   114,   170,
     202,   110,   171,    60,    45,    65,    66,   122,    48,   205,
     219,   279,   280,   285,    49,    46,   210,   210,   210,   210,
      47,   206,  -172,   325,   106,   111,    95,    53,    99,   273,
     172,   111,    55,   171,   239,    54,    17,    63,   253,   294,
     308,   309,    57,   113,   286,   279,   280,   285,   168,   119,
     288,   123,   124,   125,   126,   127,   260,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   118,   138,   139,
     140,   141,   119,    49,   279,   280,   285,   265,   286,   314,
      94,    61,   124,   290,   288,   292,   155,    63,   289,    67,
     118,    68,    57,   167,   323,   100,    49,   169,   102,   296,
      62,   103,   219,    92,   154,   213,   214,   286,    70,   112,
      49,    68,    85,   288,   157,   158,   159,   144,    71,    72,
     147,   157,   158,   159,    73,    74,   263,   264,   178,    82,
      83,    84,   153,    85,   186,    70,   175,   148,    76,    77,
     249,   250,    78,    79,    80,    81,    82,    83,    84,   149,
      85,   164,   119,   165,   160,   166,   180,   204,   181,   183,
     161,   160,   218,   184,   199,   210,   162,   161,   217,   190,
     118,    80,    81,    82,    83,    84,    49,    85,   216,   221,
     236,   226,   242,     2,   228,   243,     3,     4,     5,   244,
       6,   245,   247,     7,     8,     9,   246,   178,   252,    10,
     254,    11,    12,    13,    14,   256,   255,   258,   259,   257,
     197,    15,    16,    17,    18,    19,    20,    21,    22,   261,
     194,   195,   196,    23,   197,   262,    24,   266,   271,   267,
     270,   272,    25,   303,   274,   304,   268,     3,     4,     5,
     310,     6,   295,   106,     7,     8,     9,   305,   275,   276,
      10,   313,   319,   301,    13,    14,   322,    56,    69,   203,
     298,   251,    15,   277,    17,    18,    19,    20,    21,    22,
     191,   209,   225,   291,    23,   302,   318,    24,   143,   173,
       3,     4,     5,    25,     6,     0,   278,     7,     8,     9,
       0,   275,   276,    10,     0,     0,     0,    13,    14,     0,
     329,     0,   321,     0,     0,    15,   277,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     3,     4,     5,    25,     6,     0,   306,
       7,     8,     9,     0,   275,   276,    10,     0,     0,     0,
      13,    14,     0,     0,     0,     0,     0,     0,    15,   277,
      17,    18,    19,    20,    21,    22,     0,     3,     4,     5,
      23,     6,     0,    24,     7,     8,     9,     0,     0,    25,
      10,     0,   324,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     3,     4,     5,    23,     6,     0,    24,     7,     8,
       9,     0,     0,    25,    10,     0,   174,     0,    13,    14,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     3,     4,     5,    23,     6,
       0,    24,     7,     8,     9,     0,     0,    25,    10,     0,
     297,     0,    13,    14,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     3,
       4,     5,    23,     6,     0,    24,     7,     8,     9,     0,
       0,    25,    10,     0,   320,     0,    13,    14,     0,     0,
       0,     0,     0,     0,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     3,     4,     5,    23,     6,     0,    24,
       7,     8,     9,     0,     0,    25,    10,     0,   326,    86,
      13,    14,     0,    87,    88,    89,    90,     0,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     3,     4,     5,
      23,     0,     0,    24,     0,     0,     0,     0,    91,    25,
      10,     0,   328,     0,    13,    92,    70,   192,   193,   194,
     195,   196,    15,   197,    17,     0,    71,    72,     0,    22,
     198,     0,    73,    74,    23,     0,     0,    24,     0,     0,
       0,     0,     0,    25,     0,   199,    76,    77,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    70,    85,     0,
     115,     0,     0,   116,     0,     0,     0,    71,    72,     0,
       0,     0,     0,    73,    74,     0,   192,   193,   194,   195,
     196,     0,   197,     3,     4,     5,     0,    76,    77,   241,
       0,    78,    79,    80,    81,    82,    83,    84,     0,    85,
      13,   207,     0,     0,   208,     3,     4,     5,    15,     0,
      17,     0,     0,     0,     0,    22,     0,     0,    10,     0,
      23,     0,    13,    24,     0,     0,     0,     0,     0,    25,
      15,     0,    17,    18,    19,    20,    21,    22,     0,     0,
       0,     0,    23,     0,     0,    24,     3,     4,     5,     0,
       0,    25,   117,     0,   192,   193,   194,   195,   196,    10,
     197,     0,   229,    13,    70,     0,     0,     0,     0,     0,
       0,    15,     0,    17,    18,    19,    20,    21,    22,    70,
      73,    74,     0,    23,     0,     0,    24,     0,     0,    71,
      72,     0,    25,   142,    76,    73,    74,     0,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,     0,    76,
      77,     0,    70,    78,    79,    80,    81,    82,    83,    84,
       0,    85,    71,    72,     0,     0,   116,     0,    73,    74,
       0,   188,   189,     0,     0,     0,   201,     0,     0,     0,
       0,     0,    76,    77,     0,    70,    78,    79,    80,    81,
      82,    83,    84,     0,    85,    71,    72,     0,     0,   227,
       0,    73,    74,   230,   231,   232,   233,   234,   235,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,     3,
       4,     5,   293,     6,     0,     0,     7,     8,     9,     0,
       0,     0,    10,     0,     0,     0,    13,    14,     0,     0,
       0,     3,     4,     5,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,    10,     0,    23,     0,    13,    24,
       0,     0,     0,     0,     0,    25,    15,     0,    17,    18,
      19,    20,    21,    22,     0,     3,     4,     5,    23,     0,
       0,    24,     0,     0,     0,     0,     0,    25,    10,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
      15,     0,    17,     3,     4,     5,     0,    22,     0,     0,
     185,     0,    23,     0,     0,    24,    10,     0,     0,     0,
      13,    25,    70,     0,     0,     0,     0,     0,    15,     0,
      17,     0,    71,    72,     0,    22,     0,     0,    73,    74,
      23,     0,     0,    24,     0,     0,     0,     0,     0,    25,
       0,     0,    76,    77,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    70,    85,     0,   146,     0,     0,     0,
       0,     0,     0,    71,    72,     0,     0,     0,     0,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,    76,    77,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    70,    85,    73,   150,     0,     0,
       0,     0,     0,     0,    71,    72,     0,     0,     0,     0,
      73,    74,     0,     0,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    76,    77,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    70,    85,     0,   300,     0,
       0,     0,     0,     0,     0,    71,    72,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    70,    85,     0,   315,
       0,     0,     0,     0,     0,     0,    71,    72,     0,     0,
       0,     0,    73,    74,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,    76,    77,     0,    70,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    71,
      72,     0,     0,     0,     0,    73,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
      77,     0,    70,    78,    79,    80,    81,    82,    83,    84,
       0,    85,   101,    72,     0,     0,     0,     0,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,     0,    70,    78,    79,    80,    81,
      82,    83,    84,     0,    85,    71,     0,    70,     0,     0,
       0,    73,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    73,    74,    76,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    73,    74,
       0,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,     0,    76,    77,     0,     0,    78,    79,    80,    81,
      82,    83,    84,     0,    85
};

static const yytype_int16 yycheck[] =
{
       9,    10,     1,   214,   287,    30,    23,    27,    64,    50,
     166,    29,    53,    22,    49,    24,    25,    29,     9,    41,
     182,   253,   253,   253,     9,    49,    29,    29,    29,    29,
      49,    53,    57,   316,    54,    53,    45,    13,    47,   250,
      50,    53,    30,    53,   199,    21,    30,    64,    51,    51,
      51,    51,    30,    62,   253,   287,   287,   287,   114,    68,
     253,    70,    71,    72,    73,    74,   228,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    68,    87,    88,
      89,    90,    91,    68,   316,   316,   316,   242,   287,   300,
      51,    30,   101,   255,   287,   257,   105,   114,   254,    29,
      91,    49,    30,   112,   315,    29,    91,   116,    30,   264,
      49,    30,   274,    56,   105,     8,     9,   316,     6,    54,
     105,    49,    48,   316,     3,     4,     5,    30,    16,    17,
      57,     3,     4,     5,    22,    23,    52,    53,   147,    44,
      45,    46,    49,    48,   153,     6,   145,    21,    36,    37,
       8,     9,    40,    41,    42,    43,    44,    45,    46,    30,
      48,    27,   171,    54,    43,    30,    30,    55,    27,    49,
      49,    43,   181,    49,    51,    29,    55,    49,    27,    54,
     171,    42,    43,    44,    45,    46,   171,    48,    57,    21,
     199,    27,    27,     0,    50,     4,     3,     4,     5,    28,
       7,    51,    49,    10,    11,    12,    51,   216,   217,    16,
      30,    18,    19,    20,    21,    53,    50,   226,   227,    50,
      48,    28,    29,    30,    31,    32,    33,    34,    35,    53,
      44,    45,    46,    40,    48,    52,    43,    41,   247,    50,
      52,    49,    49,    29,    50,    29,   245,     3,     4,     5,
      39,     7,   261,    54,    10,    11,    12,    51,    14,    15,
      16,    29,    27,   272,    20,    21,    29,    13,    28,   166,
     269,   216,    28,    29,    30,    31,    32,    33,    34,    35,
     162,   171,   184,   256,    40,   274,   309,    43,    91,   144,
       3,     4,     5,    49,     7,    -1,    52,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    21,    -1,
     319,    -1,   311,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,     3,     4,     5,    49,     7,    -1,    52,
      10,    11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,     3,     4,     5,
      40,     7,    -1,    43,    10,    11,    12,    -1,    -1,    49,
      16,    -1,    52,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,     3,     4,     5,    40,     7,    -1,    43,    10,    11,
      12,    -1,    -1,    49,    16,    -1,    52,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,     3,     4,     5,    40,     7,
      -1,    43,    10,    11,    12,    -1,    -1,    49,    16,    -1,
      52,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,     3,
       4,     5,    40,     7,    -1,    43,    10,    11,    12,    -1,
      -1,    49,    16,    -1,    52,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,     3,     4,     5,    40,     7,    -1,    43,
      10,    11,    12,    -1,    -1,    49,    16,    -1,    52,    20,
      20,    21,    -1,    24,    25,    26,    27,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,     3,     4,     5,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    49,    49,
      16,    -1,    52,    -1,    20,    56,     6,    42,    43,    44,
      45,    46,    28,    48,    30,    -1,    16,    17,    -1,    35,
      55,    -1,    22,    23,    40,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,     6,    48,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    42,    43,    44,    45,
      46,    -1,    48,     3,     4,     5,    -1,    36,    37,    55,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      20,    50,    -1,    -1,    53,     3,     4,     5,    28,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    -1,    16,    -1,
      40,    -1,    20,    43,    -1,    -1,    -1,    -1,    -1,    49,
      28,    -1,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,    -1,
      -1,    49,    50,    -1,    42,    43,    44,    45,    46,    16,
      48,    -1,    50,    20,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,     6,
      22,    23,    -1,    40,    -1,    -1,    43,    -1,    -1,    16,
      17,    -1,    49,    50,    36,    22,    23,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    -1,    36,
      37,    -1,     6,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    16,    17,    -1,    -1,    53,    -1,    22,    23,
      -1,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,     6,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    16,    17,    -1,    -1,    53,
      -1,    22,    23,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    -1,     3,
       4,     5,    53,     7,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,     3,     4,     5,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    16,    -1,    40,    -1,    20,    43,
      -1,    -1,    -1,    -1,    -1,    49,    28,    -1,    30,    31,
      32,    33,    34,    35,    -1,     3,     4,     5,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    16,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,     3,     4,     5,    -1,    35,    -1,    -1,
      38,    -1,    40,    -1,    -1,    43,    16,    -1,    -1,    -1,
      20,    49,     6,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    16,    17,    -1,    35,    -1,    -1,    22,    23,
      40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,     6,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,     6,    48,    22,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,     6,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,     6,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,     6,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,     6,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,     6,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    16,    -1,     6,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    22,    23,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    22,    23,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    81,     0,     3,     4,     5,     7,    10,    11,    12,
      16,    18,    19,    20,    21,    28,    29,    30,    31,    32,
      33,    34,    35,    40,    43,    49,    59,    60,    61,    62,
      63,    64,    65,    77,    82,    89,    93,    95,    96,   102,
     105,   107,   118,   122,   123,    49,    49,    49,    59,    61,
      64,    78,    64,    13,    21,    30,    65,    30,    67,   106,
      64,    30,    49,    62,   104,    64,    64,    29,    49,    67,
       6,    16,    17,    22,    23,    29,    36,    37,    40,    41,
      42,    43,    44,    45,    46,    48,    20,    24,    25,    26,
      27,    49,    56,    66,    51,    64,   119,   120,   121,    64,
      29,    16,    30,    30,    90,    27,    54,    71,    72,    76,
      29,    53,    54,    64,   104,    50,    53,    50,    59,    64,
      80,   103,    29,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    50,   103,    30,    94,    50,    57,    21,    30,
      50,    84,    83,    49,    59,    64,    75,     3,     4,     5,
      43,    49,    55,    70,    27,    54,    30,    64,   104,    64,
      50,    53,    50,   106,    52,    93,   108,   110,    64,    79,
      30,    27,   124,    49,    49,    38,    64,    91,    70,    70,
      54,    72,    42,    43,    44,    45,    46,    48,    55,    51,
      73,    70,    71,    76,    55,    41,    53,    50,    53,    80,
      29,   111,   113,     8,     9,   115,    57,    27,    64,   108,
     117,    21,    85,    86,    87,    85,    27,    53,    50,    50,
      70,    70,    70,    70,    70,    70,    64,    68,    69,    73,
      74,    55,    27,     4,    28,    51,    51,    49,   110,     8,
       9,    79,    64,    51,    30,    50,    53,    50,    64,    64,
     108,    53,    52,    52,    53,    73,    41,    50,    93,   109,
      52,    64,    49,   110,    50,    14,    15,    29,    52,    60,
      77,    97,    98,   100,   101,   102,   105,   116,   118,    71,
     108,    87,   108,    53,    51,    64,    73,    52,    93,   114,
      50,    64,   117,    29,    29,    51,    52,    97,    51,    51,
      39,    92,   112,    29,   110,    50,    99,    88,    88,    27,
      52,    93,    29,   110,    52,    97,    52,    93,    52,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    81,    81,    81,    81,    83,    82,    84,    82,
      85,    85,    86,    86,    87,    88,    88,    90,    89,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    96,    95,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,   101,   100,   102,    78,
      78,    78,    60,    60,    59,    59,    61,    61,    61,    61,
      80,    80,   103,   103,    62,    62,   104,   104,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      66,    66,    66,    66,   105,   105,    67,    67,    67,    67,
      67,    67,    76,    76,    75,    75,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    69,    69,    68,    68,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      65,    65,   106,   106,   107,   107,   108,   108,   109,   109,
     111,   112,   110,   113,   114,   110,    77,    77,    77,    77,
     115,   115,   116,   116,   117,   117,   118,   118,   120,   119,
     121,   119,   119,    79,    79,   122,   124,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     0,    11,     0,    11,
       1,     0,     3,     1,     3,     2,     0,     0,    10,     3,
       7,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     0,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     0,     0,     4,     3,     1,
       1,     0,     2,     2,     4,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     7,     5,     1,     1,     7,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     3,     3,     2,     3,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     6,     4,     4,     2,
       4,     2,     2,     0,     1,     1,     1,     2,     3,     4,
       3,     3,     3,     3,     1,     1,     0,     3,     1,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       4,     2,     4,     0,     4,     3,     2,     0,     2,     1,
       0,     0,     7,     0,     0,     6,     5,     7,     8,     6,
       5,     6,     2,     1,     4,     3,     1,     1,     0,     5,
       0,     4,     0,     1,     0,     9,     0,     6
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
#line 140 "parser.y"
                     {
              if(ret_flag) {
                     cerr<<"Error: Return statement not allowed outside function"<<endl;
              }
         }
#line 1838 "parser.tab.c"
    break;

  case 6:
#line 148 "parser.y"
                         { addSymTabPtr(); }
#line 1844 "parser.tab.c"
    break;

  case 7:
#line 148 "parser.y"
                                                                                             {
              insertType((yyvsp[-8].name), Func, (yyvsp[-9].eletype));  
              if(paramslist.size()>0) {
                     addParamList((yyvsp[-8].name),paramslist);
                     paramslist.clear();
              }
              printSymbolTable();
              
              if(ret_flag==0) {
                     cerr<<"Error: Semantic error no return statement"<<endl;
              }
              else if((yyvsp[-9].eletype)!=ret_type) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              
              ret_flag = 0;
              delSymTabPtr();
       }
#line 1867 "parser.tab.c"
    break;

  case 8:
#line 166 "parser.y"
                       { addSymTabPtr(); }
#line 1873 "parser.tab.c"
    break;

  case 9:
#line 166 "parser.y"
                                                                                          {
              insertType((yyvsp[-8].name), Func, (yyvsp[-9].eletype));  
              if(paramslist.size()>0) {
                     addParamList((yyvsp[-8].name),paramslist);
                     paramslist.clear();
              }
              paramslist.clear();
              printSymbolTable();
              
              if(ret_type!=UNDEF && ret_type!=Void) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0; 
              delSymTabPtr();
       }
#line 1893 "parser.tab.c"
    break;

  case 14:
#line 187 "parser.y"
                                 {
       ParamList param;
       param.Eletype = (yyvsp[-2].eletype);
       param.name = (yyvsp[-1].name);
       param.dim = *(yyvsp[0].dimList);
       if(param.dim.size()==0) {
              param.Type = Var;
       }
       else {
              param.Type = Array;
       }
       paramslist.push_back(param);
       
}
#line 1912 "parser.tab.c"
    break;

  case 17:
#line 206 "parser.y"
            { addSymTabPtr(); }
#line 1918 "parser.tab.c"
    break;

  case 18:
#line 206 "parser.y"
                                                                           { if (ret_fig_flag == 1)  semanticError("Error: Return statement is not allowed in figures."); ret_fig_flag =0; delSymTabPtr(); }
#line 1924 "parser.tab.c"
    break;

  case 19:
#line 207 "parser.y"
                                   { if(!(arithCompatible((yyvsp[-2].eletype)) && (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
#line 1930 "parser.tab.c"
    break;

  case 20:
#line 208 "parser.y"
                                                            { if(!(arithCompatible((yyvsp[-4].eletype)) && (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
#line 1936 "parser.tab.c"
    break;

  case 32:
#line 218 "parser.y"
            { addSymTabPtr(); }
#line 1942 "parser.tab.c"
    break;

  case 33:
#line 218 "parser.y"
                                                   { delSymTabPtr(); }
#line 1948 "parser.tab.c"
    break;

  case 46:
#line 227 "parser.y"
                  { addSymTabPtr(); }
#line 1954 "parser.tab.c"
    break;

  case 47:
#line 227 "parser.y"
                                                              { delSymTabPtr(); }
#line 1960 "parser.tab.c"
    break;

  case 48:
#line 230 "parser.y"
                                     {ret_type = (yyvsp[-1].eletype); ret_flag = 1; ret_fig_flag = 1;}
#line 1966 "parser.tab.c"
    break;

  case 49:
#line 232 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1972 "parser.tab.c"
    break;

  case 50:
#line 232 "parser.y"
                                            {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1978 "parser.tab.c"
    break;

  case 51:
#line 232 "parser.y"
                                                         {(yyval.eletype) = Void;}
#line 1984 "parser.tab.c"
    break;

  case 52:
#line 235 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1990 "parser.tab.c"
    break;

  case 53:
#line 236 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1996 "parser.tab.c"
    break;

  case 54:
#line 239 "parser.y"
                                            {(yyval.eletype) = (yyvsp[-3].eletype);}
#line 2002 "parser.tab.c"
    break;

  case 55:
#line 240 "parser.y"
                                {(yyval.eletype) = (yyvsp[-2].eletype);}
#line 2008 "parser.tab.c"
    break;

  case 56:
#line 243 "parser.y"
                           { (yyval.eletype) = (yyvsp[0].eletype);}
#line 2014 "parser.tab.c"
    break;

  case 57:
#line 244 "parser.y"
                              { (yyval.eletype) = (yyvsp[0].eletype);}
#line 2020 "parser.tab.c"
    break;

  case 58:
#line 245 "parser.y"
                            { (yyval.eletype) = (yyvsp[0].eletype);}
#line 2026 "parser.tab.c"
    break;

  case 59:
#line 246 "parser.y"
                               { (yyval.eletype) = (yyvsp[0].eletype);}
#line 2032 "parser.tab.c"
    break;

  case 60:
#line 249 "parser.y"
                     {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2038 "parser.tab.c"
    break;

  case 61:
#line 250 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2044 "parser.tab.c"
    break;

  case 64:
#line 257 "parser.y"
                                                            {  (yyval.eletype) = pointCheck((yyvsp[-5].eletype), (yyvsp[-3].eletype)); }
#line 2050 "parser.tab.c"
    break;

  case 65:
#line 258 "parser.y"
                                               {  (yyval.eletype) = pointCheck((yyvsp[-3].eletype), (yyvsp[-1].eletype)); }
#line 2056 "parser.tab.c"
    break;

  case 66:
#line 262 "parser.y"
           { if (checkEletype((yyvsp[0].name)) != POINT) semanticError("Error: vertex has to be a point");}
#line 2062 "parser.tab.c"
    break;

  case 68:
#line 267 "parser.y"
                                                  {(yyval.eletype) = REAL;}
#line 2068 "parser.tab.c"
    break;

  case 69:
#line 268 "parser.y"
                                      {(yyval.eletype) = REAL;}
#line 2074 "parser.tab.c"
    break;

  case 70:
#line 271 "parser.y"
                                        {(yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)); }
#line 2080 "parser.tab.c"
    break;

  case 71:
#line 272 "parser.y"
                                        {(yyval.eletype) = diffTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 2086 "parser.tab.c"
    break;

  case 72:
#line 273 "parser.y"
                                        {(yyval.eletype) = mulTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 2092 "parser.tab.c"
    break;

  case 73:
#line 274 "parser.y"
                                        {(yyval.eletype) = mulTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 2098 "parser.tab.c"
    break;

  case 74:
#line 275 "parser.y"
                                        {if ((yyvsp[-2].eletype) != INT || (yyvsp[0].eletype) != INT) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = INT;}
#line 2104 "parser.tab.c"
    break;

  case 75:
#line 276 "parser.y"
                                        {(yyval.eletype) = mulTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 2110 "parser.tab.c"
    break;

  case 76:
#line 277 "parser.y"
                                            {if(((yyvsp[-2].eletype) == POINT || (yyvsp[-2].eletype) == LINEARR) && (yyvsp[0].eletype) == POINT) (yyval.eletype) = LINEARR ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 2116 "parser.tab.c"
    break;

  case 77:
#line 278 "parser.y"
                                             {if(((yyvsp[-2].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR) && ((yyvsp[0].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR)) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 2122 "parser.tab.c"
    break;

  case 78:
#line 279 "parser.y"
                                                   {if(((yyvsp[-2].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR) && ((yyvsp[0].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR)) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
#line 2128 "parser.tab.c"
    break;

  case 79:
#line 280 "parser.y"
                                            {if ((yyvsp[-1].eletype) != POINT) semanticError("Error: Semantic error incompatible datatype") ; (yyval.eletype) = REAL; }
#line 2134 "parser.tab.c"
    break;

  case 80:
#line 281 "parser.y"
                                       {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2140 "parser.tab.c"
    break;

  case 81:
#line 282 "parser.y"
                                  {if(!((yyvsp[0].eletype) == INT || (yyvsp[0].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);  }
#line 2146 "parser.tab.c"
    break;

  case 82:
#line 283 "parser.y"
                                  {if(!((yyvsp[-1].eletype) == INT || (yyvsp[-1].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);  }
#line 2152 "parser.tab.c"
    break;

  case 83:
#line 284 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2158 "parser.tab.c"
    break;

  case 84:
#line 285 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2164 "parser.tab.c"
    break;

  case 85:
#line 286 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2170 "parser.tab.c"
    break;

  case 86:
#line 287 "parser.y"
                                    {if(!((yyvsp[0].eletype) == POINT && (yyvsp[-1].eletype) == POINT)||((yyvsp[0].eletype) == LABEL && (yyvsp[-1].eletype) == LABEL || arithCompatible((yyvsp[-1].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);}
#line 2176 "parser.tab.c"
    break;

  case 87:
#line 288 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2182 "parser.tab.c"
    break;

  case 88:
#line 289 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2188 "parser.tab.c"
    break;

  case 89:
#line 290 "parser.y"
                                         {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2194 "parser.tab.c"
    break;

  case 90:
#line 291 "parser.y"
                                              {if(!((arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) || ((yyvsp[-2].eletype) == (yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2200 "parser.tab.c"
    break;

  case 91:
#line 292 "parser.y"
                            {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2206 "parser.tab.c"
    break;

  case 92:
#line 293 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 2212 "parser.tab.c"
    break;

  case 93:
#line 294 "parser.y"
                     {(yyval.eletype) = (yyvsp[0].constExp).eletype;}
#line 2218 "parser.tab.c"
    break;

  case 94:
#line 295 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].constExp).eletype;}
#line 2224 "parser.tab.c"
    break;

  case 95:
#line 296 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].constExp).eletype;}
#line 2230 "parser.tab.c"
    break;

  case 96:
#line 297 "parser.y"
                           {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2236 "parser.tab.c"
    break;

  case 98:
#line 299 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2242 "parser.tab.c"
    break;

  case 99:
#line 300 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2248 "parser.tab.c"
    break;

  case 101:
#line 304 "parser.y"
                                {if(!(arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2254 "parser.tab.c"
    break;

  case 102:
#line 305 "parser.y"
                                    {if(!(arithCompatible((yyvsp[0].eletype)) || (yyvsp[0].eletype) == LABEL || (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2260 "parser.tab.c"
    break;

  case 103:
#line 306 "parser.y"
                                  {if(!(arithCompatible((yyvsp[0].eletype)) || (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);}
#line 2266 "parser.tab.c"
    break;

  case 104:
#line 312 "parser.y"
                                     {typeUpdate((yyvsp[-1].nameList), (yyvsp[-2].eletype));}
#line 2272 "parser.tab.c"
    break;

  case 105:
#line 313 "parser.y"
                                        {typeUpdate((yyvsp[-1].nameList), (yyvsp[-2].eletype));}
#line 2278 "parser.tab.c"
    break;

  case 106:
#line 316 "parser.y"
                                                   {(yyval.nameList) = (yyvsp[-5].nameList);(yyval.nameList)->push_back((yyvsp[-3].name));compareAndInsertArray((yyvsp[-3].name), (yyvsp[-2].dimList), (yyvsp[0].listAndType).eletype, (yyvsp[0].listAndType).dimList);}
#line 2284 "parser.tab.c"
    break;

  case 107:
#line 317 "parser.y"
                                   {(yyval.nameList) = (yyvsp[-3].nameList);(yyval.nameList)->push_back((yyvsp[-1].name));insertArray((yyvsp[-1].name), (yyvsp[0].dimList));}
#line 2290 "parser.tab.c"
    break;

  case 108:
#line 318 "parser.y"
                                    {(yyval.nameList) = (yyvsp[-3].nameList);(yyval.nameList)->push_back((yyvsp[-1].name));insertType((yyvsp[-1].name), Var, (yyvsp[0].eletype));}
#line 2296 "parser.tab.c"
    break;

  case 109:
#line 319 "parser.y"
                       {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-1].name));insertArray((yyvsp[-1].name), (yyvsp[0].dimList));}
#line 2302 "parser.tab.c"
    break;

  case 110:
#line 320 "parser.y"
                                       {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-3].name));compareAndInsertArray((yyvsp[-3].name), (yyvsp[-2].dimList), (yyvsp[0].listAndType).eletype, (yyvsp[0].listAndType).dimList);}
#line 2308 "parser.tab.c"
    break;

  case 111:
#line 321 "parser.y"
                        {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-1].name));insertType((yyvsp[-1].name), Var, (yyvsp[0].eletype));}
#line 2314 "parser.tab.c"
    break;

  case 112:
#line 324 "parser.y"
                              {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2320 "parser.tab.c"
    break;

  case 113:
#line 325 "parser.y"
                      {(yyval.eletype) = UNDEF;}
#line 2326 "parser.tab.c"
    break;

  case 114:
#line 328 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2332 "parser.tab.c"
    break;

  case 115:
#line 329 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2338 "parser.tab.c"
    break;

  case 116:
#line 333 "parser.y"
               {(yyval.dimList) = (yyvsp[0].dimList);}
#line 2344 "parser.tab.c"
    break;

  case 117:
#line 334 "parser.y"
                  {(yyval.dimList) = new vector<int>;(yyval.dimList)->push_back(-1);}
#line 2350 "parser.tab.c"
    break;

  case 118:
#line 335 "parser.y"
                      {(yyval.dimList) = new vector<int>;addFrontAndCopy((yyval.dimList), (yyvsp[0].dimList), -1);delete (yyvsp[0].dimList);}
#line 2356 "parser.tab.c"
    break;

  case 119:
#line 340 "parser.y"
                             {(yyval.dimList) = (yyvsp[-3].dimList);
                              
                            if ((yyvsp[-1].constExp).eletype == REAL)
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).d);
                            else              
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).i);
                            
                            }
#line 2369 "parser.tab.c"
    break;

  case 120:
#line 348 "parser.y"
                         {(yyval.dimList) = new vector<int>; 

                            if ((yyvsp[-1].constExp).eletype == REAL)
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).d);
                            else              
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).i);
                         }
#line 2381 "parser.tab.c"
    break;

  case 121:
#line 359 "parser.y"
                                   {(yyval.listAndType).dimList = new vector<int>; (yyval.listAndType).dimList->push_back((yyvsp[-1].countAndType).count); (yyval.listAndType).eletype = (yyvsp[-1].countAndType).eletype;print(*((yyval.listAndType).dimList));}
#line 2387 "parser.tab.c"
    break;

  case 122:
#line 360 "parser.y"
                                      {(yyval.listAndType).dimList = (yyvsp[-1].listAndType).dimList;print(*((yyval.listAndType).dimList));(yyval.listAndType).eletype = (yyvsp[-1].listAndType).eletype;}
#line 2393 "parser.tab.c"
    break;

  case 123:
#line 363 "parser.y"
                                                   {updateMaxDim((yyvsp[-2].listAndType).dimList, (yyvsp[0].listAndType).dimList); delete (yyvsp[0].listAndType).dimList;(yyval.listAndType).dimList = (yyvsp[-2].listAndType).dimList;if (!coercible((yyvsp[-2].listAndType).eletype, (yyvsp[0].listAndType).eletype)) semanticError("arrays should be initialized with same datatype");else (yyval.listAndType).eletype = (yyvsp[-2].listAndType).eletype;}
#line 2399 "parser.tab.c"
    break;

  case 124:
#line 364 "parser.y"
                             {(yyval.listAndType).dimList = new vector<int>; addFrontAndCopy((yyval.listAndType).dimList, (yyvsp[0].listAndType).dimList, 1);delete (yyvsp[0].listAndType).dimList;(yyval.listAndType).eletype = (yyvsp[0].listAndType).eletype;}
#line 2405 "parser.tab.c"
    break;

  case 125:
#line 367 "parser.y"
                             {(yyval.countAndType).count = (yyvsp[0].countAndType).count;(yyval.countAndType).eletype = (yyvsp[0].countAndType).eletype;}
#line 2411 "parser.tab.c"
    break;

  case 126:
#line 368 "parser.y"
                           {(yyval.countAndType).count = 0;(yyval.countAndType).eletype = UNDEF;}
#line 2417 "parser.tab.c"
    break;

  case 127:
#line 371 "parser.y"
                                              {(yyval.countAndType).count = (yyvsp[-2].countAndType).count + 1; if (!coercible((yyvsp[-2].countAndType).eletype, (yyvsp[0].eletype))) semanticError("arrays should be initialized with same datatype");else (yyval.countAndType).eletype = (yyvsp[0].eletype);}
#line 2423 "parser.tab.c"
    break;

  case 128:
#line 372 "parser.y"
                           {(yyval.countAndType).count = 1;(yyval.countAndType).eletype = (yyvsp[0].eletype);}
#line 2429 "parser.tab.c"
    break;

  case 129:
#line 380 "parser.y"
                                      {(yyval.constExp).eletype = sumTypeCheck((yyvsp[-2].constExp).eletype, (yyvsp[0].constExp).eletype);

                                          if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d + (yyvsp[0].constExp).d;
                                          else if ((yyvsp[-2].constExp).eletype == INT && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).i + (yyvsp[0].constExp).d;  
                                          else if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == INT)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d + (yyvsp[0].constExp).i;
                                          else 
                                                 (yyval.constExp).i = (yyvsp[-2].constExp).i + (yyvsp[0].constExp).i;                           
                                          

                                      }
#line 2447 "parser.tab.c"
    break;

  case 130:
#line 393 "parser.y"
                                   {(yyval.constExp).eletype = diffTypeCheck((yyvsp[-2].constExp).eletype, (yyvsp[0].constExp).eletype);

                                          if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d - (yyvsp[0].constExp).d;
                                          else if ((yyvsp[-2].constExp).eletype == INT && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).i - (yyvsp[0].constExp).d;  
                                          else if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == INT)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d - (yyvsp[0].constExp).i;
                                          else
                                                 (yyval.constExp).i = (yyvsp[-2].constExp).i - (yyvsp[0].constExp).i;
                                   
                                   }
#line 2464 "parser.tab.c"
    break;

  case 131:
#line 405 "parser.y"
                                   {(yyval.constExp).eletype = mulTypeCheck((yyvsp[-2].constExp).eletype, (yyvsp[0].constExp).eletype);

                                          if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d * (yyvsp[0].constExp).d;
                                          else if ((yyvsp[-2].constExp).eletype == INT && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).i * (yyvsp[0].constExp).d;  
                                          else if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == INT)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d * (yyvsp[0].constExp).i;
                                          else
                                                 (yyval.constExp).i = (yyvsp[-2].constExp).i * (yyvsp[0].constExp).i;
                                          
                                   }
#line 2481 "parser.tab.c"
    break;

  case 132:
#line 417 "parser.y"
                                   {(yyval.constExp).eletype = mulTypeCheck((yyvsp[-2].constExp).eletype, (yyvsp[0].constExp).eletype);

                                          if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d / (yyvsp[0].constExp).d;
                                          else if ((yyvsp[-2].constExp).eletype == INT && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).i / (yyvsp[0].constExp).d;  
                                          else if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == INT)
                                                 (yyval.constExp).d = (yyvsp[-2].constExp).d / (yyvsp[0].constExp).i;
                                          else
                                                 (yyval.constExp).i = (yyvsp[-2].constExp).i / (yyvsp[0].constExp).i;
                                   }
#line 2497 "parser.tab.c"
    break;

  case 133:
#line 428 "parser.y"
                                   {if ((yyvsp[-2].constExp).eletype != INT || (yyvsp[0].constExp).eletype != INT) semanticError("Error: Semantic error incompatible datatype");(yyval.constExp).eletype = INT;
                                          (yyval.constExp).i = (yyvsp[-2].constExp).i % (yyvsp[0].constExp).i;
                                   }
#line 2505 "parser.tab.c"
    break;

  case 134:
#line 431 "parser.y"
                                   {(yyval.constExp).eletype = mulTypeCheck((yyvsp[-2].constExp).eletype, (yyvsp[0].constExp).eletype);

                                          if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = pow((yyvsp[-2].constExp).d, (yyvsp[0].constExp).d);
                                          else if ((yyvsp[-2].constExp).eletype == INT && (yyvsp[0].constExp).eletype == REAL)
                                                 (yyval.constExp).d = pow((yyvsp[-2].constExp).i, (yyvsp[0].constExp).d);  
                                          else if ((yyvsp[-2].constExp).eletype == REAL && (yyvsp[0].constExp).eletype == INT)
                                                 (yyval.constExp).d = pow((yyvsp[-2].constExp).d, (yyvsp[0].constExp).i);
                                          else
                                                 (yyval.constExp).i = pow((yyvsp[-2].constExp).i, (yyvsp[0].constExp).i);

                                   }
#line 2522 "parser.tab.c"
    break;

  case 135:
#line 443 "parser.y"
                        {if (!arithCompatible((yyvsp[0].constExp).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.constExp).eletype = (yyvsp[0].constExp).eletype;

                            if ((yyval.constExp).eletype == REAL) 
                                   (yyval.constExp).d = -(yyvsp[0].constExp).d; 
                            else 
                                   (yyval.constExp).i = -(yyvsp[0].constExp).i;
                        }
#line 2534 "parser.tab.c"
    break;

  case 136:
#line 450 "parser.y"
                            {
                                   (yyval.constExp).eletype = (yyvsp[-1].constExp).eletype;
                                   if ((yyval.constExp).eletype == REAL) 
                                          (yyval.constExp).d = (yyvsp[-1].constExp).d; 
                                   else 
                                          (yyval.constExp).i = (yyvsp[-1].constExp).i;
                            }
#line 2546 "parser.tab.c"
    break;

  case 137:
#line 457 "parser.y"
                {(yyval.constExp).eletype = (yyvsp[0].constExp).eletype;(yyval.constExp).d = (yyvsp[0].constExp).d;}
#line 2552 "parser.tab.c"
    break;

  case 138:
#line 458 "parser.y"
                  {(yyval.constExp).eletype = (yyvsp[0].constExp).eletype;(yyval.constExp).i = (yyvsp[0].constExp).i;}
#line 2558 "parser.tab.c"
    break;

  case 139:
#line 459 "parser.y"
                 {(yyval.constExp).eletype = INT;(yyval.constExp).i = (yyvsp[0].constExp).i;}
#line 2564 "parser.tab.c"
    break;

  case 150:
#line 477 "parser.y"
                         { addSymTabPtr(); }
#line 2570 "parser.tab.c"
    break;

  case 151:
#line 477 "parser.y"
                                                                { delSymTabPtr(); }
#line 2576 "parser.tab.c"
    break;

  case 153:
#line 477 "parser.y"
                                                                                                          {addSymTabPtr();}
#line 2582 "parser.tab.c"
    break;

  case 154:
#line 477 "parser.y"
                                                                                                                                    {delSymTabPtr(); }
#line 2588 "parser.tab.c"
    break;

  case 156:
#line 479 "parser.y"
                                              {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2594 "parser.tab.c"
    break;

  case 157:
#line 480 "parser.y"
                                                                {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2600 "parser.tab.c"
    break;

  case 158:
#line 481 "parser.y"
                                                                         {if(!(arithCompatible((yyvsp[-5].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2606 "parser.tab.c"
    break;

  case 159:
#line 482 "parser.y"
                                                        {if(!(arithCompatible((yyvsp[-3].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2612 "parser.tab.c"
    break;

  case 160:
#line 485 "parser.y"
                                                 {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2618 "parser.tab.c"
    break;

  case 161:
#line 486 "parser.y"
                                                          {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2624 "parser.tab.c"
    break;

  case 164:
#line 492 "parser.y"
                                                       {delSymTabPtr();}
#line 2630 "parser.tab.c"
    break;

  case 165:
#line 492 "parser.y"
                                                                                                {delSymTabPtr(); }
#line 2636 "parser.tab.c"
    break;

  case 168:
#line 496 "parser.y"
                { addSymTabPtr(); }
#line 2642 "parser.tab.c"
    break;

  case 170:
#line 496 "parser.y"
                                                                   { addSymTabPtr(); }
#line 2648 "parser.tab.c"
    break;

  case 172:
#line 496 "parser.y"
                                                                                                             { addSymTabPtr(); }
#line 2654 "parser.tab.c"
    break;

  case 173:
#line 497 "parser.y"
                         {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2660 "parser.tab.c"
    break;

  case 174:
#line 497 "parser.y"
                                      {(yyval.eletype) = BOOL;}
#line 2666 "parser.tab.c"
    break;

  case 175:
#line 498 "parser.y"
                                                                                        {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype11"); cout<<"k";}
#line 2672 "parser.tab.c"
    break;

  case 176:
#line 500 "parser.y"
                                      { addSymTabPtr(); }
#line 2678 "parser.tab.c"
    break;


#line 2682 "parser.tab.c"

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
#line 503 "parser.y"


/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}




int main(int argc, char*argv[])
{    

    /* yydebug = 1; */
    if (argc < 2){

        fprintf(stderr, "Please provide the input file\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", argv[1]);
      exit(1);
    }
    yyin = fp;

    /* For testing Lexer */
    const char* tokenFilename = "seq_token.txt";
    fout_token = fopen(tokenFilename, "w");

    if (fout_token == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", tokenFilename);
      exit(1);
    }

    insertConstructTab();

    return yyparse();
} 
