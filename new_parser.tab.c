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
#line 1 "new_parser.y"

#include "symbol_table.hpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include<algorithm>
#include <vector>
#include <map>
#include<deque>

extern FILE *yyin; 
FILE* fout_token;
FILE* fout_translated;
void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char* yytext;
string translateLineArr(string linearr);

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

deque <string> collection;
// string datatypeTranslation(string dtype);
string assignOpTranslation(string op);
string assignTranslation(string assignText,string memText);
string centerTranslation(string center);


int ret_flag = 0;
int ret_fig_flag = 0;
int is_member = 0;
int isArray = 0;
int is_fig = 0;
int is_decl_stmt = 0;


string scale = "1";
string center = "Point(0, 0, false)";

enum eletype ret_type = UNDEF;

vector<ParamList> paramslist;
STentry typelist;
vector<types> params;
vector<types> construct_params;
vector<ParamList> func_paramlist;

string totalProgram;


#line 139 "new_parser.tab.c"

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
#ifndef YY_YY_NEW_PARSER_TAB_H_INCLUDED
# define YY_YY_NEW_PARSER_TAB_H_INCLUDED
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
    MAIN = 286,
    TRICONSTRUCT = 287,
    CIRCLECONSTRUCT = 288,
    PARACONSTRUCT = 289,
    REGPOLYCONSTRUCT = 290,
    NOT = 291,
    AND = 292,
    OR = 293,
    SCALE = 294,
    CENTER = 295,
    NEG = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 72 "new_parser.y"


    struct {
       union {
              char* name; 
              int count;
              enum eletype eletype;  
              vector<char*>* nameList;
              vector<int>* dimList;
              struct {
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
              
              vector<cntAndType>* dimCount;

              bool stopAdvanceFound; // true for a non-nullified stop/advance
       };

       string* text;
       
    } main;
    

#line 269 "new_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NEW_PARSER_TAB_H_INCLUDED  */



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
#define YYLAST   986

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


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
       2,     2,     2,     2,     2,     2,     2,    47,     2,     2,
      50,    51,    45,    43,    52,    44,    57,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,     2,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    58,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   195,   196,   211,   223,   223,   223,   252,
     252,   252,   278,   279,   282,   283,   286,   297,   315,   315,
     334,   342,   352,   353,   354,   355,   356,   357,   358,   359,
     362,   368,   371,   371,   380,   389,   390,   394,   396,   397,
     398,   401,   402,   406,   407,   410,   411,   414,   415,   418,
     419,   420,   421,   424,   425,   428,   439,   452,   464,   480,
     481,   485,   487,   490,   491,   494,   495,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   532,   533,   537,   538,   539,
     540,   544,   545,   548,   556,   564,   572,   580,   588,   603,
     613,   614,   617,   618,   622,   623,   624,   627,   637,   651,
     659,   668,   677,   688,   689,   692,   701,   704,   718,   732,
     745,   759,   764,   777,   787,   796,   797,   798,   803,   817,
     826,   838,   839,   842,   842,   875,   876,   879,   880,   885,
     893,   900,   907,   916,   923,   935,   936,   939,   939,   946,
     946,   953,   956,   957,   960,   967
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
  "SUB_ASSIGN_OP", "EQUAL", "STRING_TOKEN", "ENDLINE", "ID", "MAIN",
  "TRICONSTRUCT", "CIRCLECONSTRUCT", "PARACONSTRUCT", "REGPOLYCONSTRUCT",
  "NOT", "AND", "OR", "SCALE", "CENTER", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "NEG", "'^'", "'('", "')'", "','", "'{'", "'}'", "'['",
  "']'", "'.'", "'|'", "$accept", "program", "func", "fig", "construct",
  "constructor", "arg_list", "list1", "argument", "params", "param_list",
  "construct_param_list", "param_list_opt", "point", "angle", "expression",
  "member_access", "assign", "func_call", "id_list", "mult_elements",
  "arr1d_in_list", "const_expr", "check_arr", "dim", "arr_assign",
  "comma_arr_assign", "decl_token", "decl_assign", "decl_stmt", "ret_var",
  "return_stmt", "optional_arg", "valid_arg", "arr_access", "memb_access",
  "empty_space", "inside_norm", "vertex", "line_op", "lineArr", "stmt",
  "assign_stmt", "cond_stmt", "stmt_list", "stmt_block", "stmt_block_for",
  "elif_stmt", "break_stmt", "loop", "for_loop_decl", "for_loop",
  "while_loop", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", YY_NULLPTR
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
     295,    60,    62,    43,    45,    42,    47,    37,   296,    94,
      40,    41,    44,   123,   125,    91,    93,    46,   124
};
# endif

#define YYPACT_NINF (-199)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -199,   358,  -199,  -199,  -199,  -199,   -32,    -8,    13,   478,
      20,    37,    17,    11,     8,    40,    43,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,   520,    17,   520,   520,  -199,  -199,
      52,    21,  -199,  -199,   861,    10,  -199,  -199,  -199,    42,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,    58,   520,
     -17,   520,  -199,    71,   895,    93,  -199,  -199,   520,  -199,
    -199,   116,    90,   106,   108,  -199,  -199,   -11,   -12,    87,
    -199,    17,    94,   549,  -199,   436,    -9,   520,   520,   520,
     520,   520,  -199,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,  -199,   520,   520,   520,   520,  -199,    96,
     117,  -199,   693,    92,   127,   125,   735,  -199,   633,  -199,
      17,  -199,  -199,   107,   478,   121,   129,   103,  -199,  -199,
     131,   520,    17,  -199,   520,  -199,  -199,     3,   895,  -199,
    -199,    56,   536,   908,   139,   763,   374,   937,   139,   139,
      56,    56,    94,    94,    94,    94,   895,   895,   895,   895,
     478,  -199,   245,  -199,   520,   134,   140,  -199,  -199,   119,
     124,   513,  -199,   895,  -199,  -199,  -199,  -199,    24,    24,
     120,    84,     9,    24,   -11,   389,   -21,   591,  -199,   478,
     135,   142,  -199,    87,  -199,  -199,   147,   895,   133,   167,
     520,   147,   181,   181,   178,   157,   646,    61,   404,    24,
     103,    24,    24,    24,    24,    24,    24,  -199,   176,  -199,
       1,     1,   154,   182,  -199,  -199,  -199,   207,  -199,   185,
    -199,   478,  -199,  -199,   186,   520,   520,   895,  -199,   184,
    -199,   164,  -199,  -199,   520,  -199,   520,  -199,    61,    61,
     169,   169,   169,   169,   895,   170,   165,  -199,    63,  -199,
    -199,    17,    17,  -199,   168,   188,   172,  -199,    44,   177,
     895,   179,   180,   181,   189,   680,   147,   895,   520,  -199,
     168,  -199,  -199,  -199,  -199,  -199,  -199,   187,  -199,   110,
    -199,  -199,  -199,  -199,  -199,   192,  -199,   895,  -199,   520,
     147,   193,  -199,    -7,   147,   147,   200,   777,   215,   520,
     147,  -199,  -199,  -199,  -199,   520,  -199,  -199,   819,   218,
     310,   895,   147,  -199,  -199,  -199,   222,   147,  -199,   224,
    -199
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    32,     1,    89,    90,    88,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,    91,    27,   142,
      49,    50,    51,    52,     0,     0,     0,     0,     2,     3,
       0,     0,    93,    94,     0,    86,    92,    24,    26,   138,
       4,    25,    22,    28,    29,    23,   155,   156,     0,     0,
     157,     0,    38,     0,    39,     0,    36,    35,     0,    62,
      61,     0,    96,     0,     0,    18,    76,   111,     0,   140,
      78,     0,    75,     0,    42,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,    81,     0,
       0,    31,     0,     0,     0,     0,     0,    37,     0,    74,
       0,     9,     6,     0,     0,     0,   106,   114,   109,   101,
       0,     0,     0,    87,     0,    48,    53,     0,    54,    58,
     102,    67,    72,    73,    82,    85,    79,    80,    83,    84,
      65,    66,    68,    69,    70,    71,    98,    99,   100,    97,
     146,   142,    32,   148,   163,     0,     0,   148,    95,     0,
       0,     0,   112,   113,   110,   136,   137,   135,     0,     0,
     115,     0,     0,     0,   111,     0,     0,     0,    47,     0,
     145,     0,    56,   139,    33,    30,    32,   162,     0,     0,
       0,    32,    13,    13,     0,     0,     0,   133,     0,     0,
     116,     0,     0,     0,     0,     0,     0,   118,   124,   107,
       0,   108,     0,   104,   105,   141,    64,     0,    60,     0,
      57,     0,   144,   147,     0,   163,     0,   160,   165,     0,
      10,    12,    15,     7,     0,   148,     0,   134,   127,   128,
     129,   130,   131,   132,   126,   123,     0,   122,     0,    43,
      44,     0,     0,   117,     0,     0,     0,    55,   149,     0,
     158,    17,     0,     0,     0,     0,    32,    20,     0,   119,
       0,   120,    46,    45,   103,    63,    59,     0,   148,   152,
     148,    16,   148,    14,   148,     0,    19,   125,   121,     0,
      32,     0,   148,     0,    32,    32,     0,     0,     0,     0,
      32,    31,   164,    11,     8,     0,   148,   150,     0,     0,
      32,    21,    32,   148,   151,    34,     0,    32,   153,     0,
     154
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,  -199,  -199,  -199,     0,     2,    65,  -199,   -27,  -199,
    -199,  -199,  -199,    -6,  -199,    -1,   -10,  -199,  -199,   223,
    -199,  -199,   256,  -163,    98,  -198,  -199,  -199,    88,  -199,
    -199,  -199,    38,  -146,   113,  -199,  -143,  -199,   -13,    59,
    -199,   268,  -199,  -199,   -30,  -122,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    28,    29,   126,    53,   230,   231,   232,   195,
     180,   127,   181,    32,    33,   128,    35,    98,    36,    68,
     245,   246,   171,   116,   117,   209,   248,   164,   118,    37,
      55,    38,   188,   129,    69,    39,   186,    61,    62,   251,
     211,   185,    41,    42,   152,    43,   302,   279,    44,    45,
     103,    46,    47,   160,   264,   159,   262,   113,    48,    99,
     104,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    30,    60,    31,   182,    66,    59,   249,    54,    52,
     247,   213,    71,  -159,   191,    60,   114,   119,    49,    59,
     130,   216,   223,    70,    63,    72,    73,   165,   166,   167,
      93,   217,    64,   220,    94,    95,    96,    97,    65,    19,
     120,  -161,    50,   120,   115,   250,   301,    19,   102,    56,
     106,    67,   277,   278,   178,   179,   274,   108,   122,    58,
    -143,    60,   208,    51,   224,    59,    57,    58,   168,   228,
      19,    75,   288,    67,   169,   257,   131,   132,   133,   134,
     135,    74,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   266,   146,   147,   148,   149,   158,   281,   100,
      60,    89,    90,    91,    59,    92,   203,   204,   205,   176,
     206,   101,    60,   163,   162,   270,    59,   271,   291,   292,
     175,    75,   107,   177,   165,   166,   167,   201,   202,   203,
     204,   205,   109,   206,   110,   290,   111,   293,   112,   294,
     207,   295,   121,    92,   286,    77,   150,   151,   155,   300,
     154,    34,    30,   187,    31,   156,   172,   161,   173,   210,
     196,   174,    60,   312,   189,   168,    59,   190,   298,   192,
     317,   169,   303,   304,   193,   199,   223,   170,   309,     3,
       4,     5,    87,    88,    89,    90,    91,   221,    92,   227,
     316,   225,    12,   222,   226,   319,    15,   201,   202,   203,
     204,   205,   229,   206,    17,   234,    19,   244,   235,   254,
     253,   255,    24,   256,   261,   258,   263,    25,   206,   269,
      26,   208,   268,   276,   187,   260,    27,   305,   280,   208,
     275,   282,   296,   265,   115,   267,   283,   289,   272,   273,
     284,    60,    60,   299,   307,    59,    59,   314,     3,     4,
       5,   318,     6,   320,    76,     7,     8,     9,   233,    10,
      11,    12,   214,   259,   183,    15,    16,   287,   200,    40,
     252,   310,     0,    17,    18,    19,     0,    20,    21,    22,
      23,    24,     0,     0,     0,     0,    25,     0,   297,    26,
       0,     0,     0,     0,     0,    27,     0,     0,   308,   184,
       0,     0,     0,     0,   311,     0,     0,     0,     0,    34,
      30,     0,    31,     3,     4,     5,     0,     6,     0,     0,
       7,     8,     9,     0,    10,    11,    12,     0,     0,     0,
      15,    16,     0,     0,     0,     0,     0,     0,    17,    18,
      19,     0,    20,    21,    22,    23,    24,     0,     0,     0,
       0,    25,     0,     0,    26,     0,     0,     0,     2,     0,
      27,     3,     4,     5,   315,     6,     0,     0,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,    16,
      77,     0,     0,     0,     0,     0,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    77,    80,    81,     0,    25,
       0,     0,    26,     0,     0,    78,    79,     0,    27,     0,
       0,    80,    81,     0,     0,    85,    86,    87,    88,    89,
      90,    91,     0,    92,   197,   198,    83,    84,     0,   212,
      85,    86,    87,    88,    89,    90,    91,     0,    92,     3,
       4,     5,     0,     0,     0,   215,     0,   201,   202,   203,
     204,   205,    12,   206,     0,   237,    15,   238,   239,   240,
     241,   242,   243,     0,    17,     0,    19,     0,    20,    21,
      22,    23,    24,     0,     0,     0,     0,    25,     0,     0,
      26,     3,     4,     5,     0,     0,    27,   125,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,    17,     0,    19,     0,
      20,    21,    22,    23,    24,     0,     3,     4,     5,    25,
       0,     0,    26,     3,     4,     5,     0,     0,    27,    12,
       0,     0,     0,    15,     0,     0,    12,     0,     0,     0,
      15,    17,    77,    19,     0,     0,     0,     0,    17,    24,
      19,     0,   194,     0,    25,    77,    24,    26,    80,    81,
       0,    25,     0,    27,    26,    78,    79,     0,     0,     0,
      27,    80,    81,    83,    84,     0,     0,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    83,    84,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    77,    92,     0,
     123,   124,     0,     0,     0,     0,     0,    78,    79,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    77,
      92,     0,   218,   219,     0,     0,     0,     0,     0,    78,
      79,     0,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,    78,    79,     0,     0,     0,     0,    80,    81,
      83,    84,     0,     0,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    83,    84,   124,    77,    85,    86,    87,
      88,    89,    90,    91,     0,    92,    78,    79,   236,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,    78,
      79,     0,     0,     0,     0,    80,    81,    83,    84,     0,
       0,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      83,    84,   285,     0,    85,    86,    87,    88,    89,    90,
      91,    77,    92,     0,   153,     0,     0,     0,     0,     0,
       0,    78,    79,     0,     0,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
       0,     0,    83,    84,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    77,    92,    80,   157,     0,     0,     0,
       0,     0,     0,    78,    79,     0,     0,     0,     0,    80,
      81,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,     0,    92,     0,    83,    84,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    77,    92,     0,   306,     0,
       0,     0,     0,     0,     0,    78,    79,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    77,    92,     0,
     313,     0,     0,     0,     0,     0,     0,    78,    79,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,    77,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    78,    79,     0,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      80,    81,    83,    84,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    77,    92,    83,    84,     0,     0,    85,
      86,    87,    88,    89,    90,    91,     0,    92,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,     0,    92
};

static const yytype_int16 yycheck[] =
{
       1,     1,    12,     1,   150,    15,    12,     6,     9,     9,
     208,   174,    25,    30,   157,    25,    27,    29,    50,    25,
      29,    42,    29,    24,    13,    26,    27,     3,     4,     5,
      20,    52,    21,   179,    24,    25,    26,    27,    30,    30,
      52,    58,    50,    52,    55,    44,    53,    30,    49,    29,
      51,    30,     8,     9,    51,    52,   254,    58,    71,    50,
      50,    71,    53,    50,   186,    71,    29,    50,    44,   191,
      30,    50,   270,    30,    50,   221,    77,    78,    79,    80,
      81,    29,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   235,    94,    95,    96,    97,   110,   261,    57,
     110,    45,    46,    47,   110,    49,    45,    46,    47,   122,
      49,    53,   122,   114,   114,    52,   122,    54,     8,     9,
     121,    50,    29,   124,     3,     4,     5,    43,    44,    45,
      46,    47,    16,    49,    44,   278,    30,   280,    30,   282,
      56,   284,    55,    49,   266,     6,    50,    30,    21,   292,
      58,   152,   152,   154,   152,    30,    27,    50,    55,   172,
     161,    30,   172,   306,    30,    44,   172,    27,   290,    50,
     313,    50,   294,   295,    50,    55,    29,    56,   300,     3,
       4,     5,    43,    44,    45,    46,    47,    52,    49,   190,
     312,    58,    16,    51,    27,   317,    20,    43,    44,    45,
      46,    47,    21,    49,    28,    27,    30,   208,    51,    27,
      56,     4,    36,    28,    30,    29,    52,    41,    49,    54,
      44,    53,    52,    51,   225,   226,    50,    27,    51,    53,
      42,    51,    40,   234,    55,   236,   263,    50,   251,   252,
      51,   251,   252,    50,    29,   251,   252,    29,     3,     4,
       5,    29,     7,    29,    31,    10,    11,    12,   193,    14,
      15,    16,   174,   225,   151,    20,    21,   268,   170,     1,
     211,   301,    -1,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,   289,    44,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,   299,    54,
      -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,   310,
     310,    -1,   310,     3,     4,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,    14,    15,    16,    -1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    44,    -1,    -1,    -1,     0,    -1,
      50,     3,     4,     5,    54,     7,    -1,    -1,    10,    11,
      12,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
       6,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,     6,    22,    23,    -1,    41,
      -1,    -1,    44,    -1,    -1,    16,    17,    -1,    50,    -1,
      -1,    22,    23,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,   168,   169,    37,    38,    -1,   173,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     3,
       4,     5,    -1,    -1,    -1,    56,    -1,    43,    44,    45,
      46,    47,    16,    49,    -1,    51,    20,   201,   202,   203,
     204,   205,   206,    -1,    28,    -1,    30,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      44,     3,     4,     5,    -1,    -1,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,
      32,    33,    34,    35,    36,    -1,     3,     4,     5,    41,
      -1,    -1,    44,     3,     4,     5,    -1,    -1,    50,    16,
      -1,    -1,    -1,    20,    -1,    -1,    16,    -1,    -1,    -1,
      20,    28,     6,    30,    -1,    -1,    -1,    -1,    28,    36,
      30,    -1,    39,    -1,    41,     6,    36,    44,    22,    23,
      -1,    41,    -1,    50,    44,    16,    17,    -1,    -1,    -1,
      50,    22,    23,    37,    38,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    37,    38,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,     6,    49,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,     6,
      49,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,     6,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      37,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    37,    38,    52,     6,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    16,    17,    52,     6,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    37,    38,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      37,    38,    52,    -1,    41,    42,    43,    44,    45,    46,
      47,     6,    49,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,     6,    49,    22,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    37,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,     6,    49,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,     6,    49,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,     6,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    16,    17,    -1,     6,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,     6,    49,    37,    38,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,     0,     3,     4,     5,     7,    10,    11,    12,
      14,    15,    16,    18,    19,    20,    21,    28,    29,    30,
      32,    33,    34,    35,    36,    41,    44,    50,    61,    62,
      63,    64,    72,    73,    74,    75,    77,    88,    90,    94,
     100,   101,   102,   104,   107,   108,   110,   111,   117,    50,
      50,    50,    63,    64,    74,    89,    29,    29,    50,    72,
      75,    96,    97,    13,    21,    30,    75,    30,    78,    93,
      74,    97,    74,    74,    29,    50,    78,     6,    16,    17,
      22,    23,    29,    37,    38,    41,    42,    43,    44,    45,
      46,    47,    49,    20,    24,    25,    26,    27,    76,   118,
      57,    53,    74,   109,   119,   120,    74,    29,    74,    16,
      44,    30,    30,   116,    27,    55,    82,    83,    87,    29,
      52,    55,    97,    51,    52,    51,    63,    70,    74,    92,
      29,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      50,    30,   103,    51,    58,    21,    30,    51,    97,   114,
     112,    50,    63,    74,    86,     3,     4,     5,    44,    50,
      56,    81,    27,    55,    30,    74,    97,    74,    51,    52,
      69,    71,    92,    93,    54,   100,    95,    74,    91,    30,
      27,    95,    50,    50,    39,    68,    74,    81,    81,    55,
      83,    43,    44,    45,    46,    47,    49,    56,    53,    84,
      97,    99,    81,    82,    87,    56,    42,    52,    51,    52,
      92,    52,    51,    29,   104,    58,    27,    74,   104,    21,
      65,    66,    67,    65,    27,    51,    52,    51,    81,    81,
      81,    81,    81,    81,    74,    79,    80,    84,    85,     6,
      44,    98,    98,    56,    27,     4,    28,    92,    29,    91,
      74,    30,   115,    52,   113,    74,    95,    74,    52,    54,
      52,    54,    97,    97,    84,    42,    51,     8,     9,   106,
      51,    82,    51,    67,    51,    52,   104,    74,    84,    50,
      95,     8,     9,    95,    95,    95,    40,    74,   104,    50,
      95,    53,   105,   104,   104,    27,    51,    29,    74,   104,
     103,    74,    95,    51,    29,    54,   104,    95,    29,   104,
      29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    60,    60,   112,   113,    61,   114,
     115,    61,    65,    65,    66,    66,    67,    67,   116,    62,
      68,    68,   100,   100,   100,   100,   100,   100,   100,   100,
     103,   103,   117,   104,   105,   107,   107,    90,    89,    89,
      89,   101,   101,    98,    98,    99,    99,    63,    63,    64,
      64,    64,    64,    92,    92,    69,    69,    70,    70,    72,
      72,    97,    97,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    96,    96,    76,    76,    76,
      76,    88,    88,    78,    78,    78,    78,    78,    78,    78,
      87,    87,    86,    86,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    80,    80,    79,    79,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    75,    94,
      94,    93,    93,   118,    77,    71,    71,    95,    95,   102,
     102,   102,   102,   106,   106,   108,   108,   119,   109,   120,
     109,   109,    91,    91,   110,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     0,     0,    10,     0,
       0,    10,     1,     0,     3,     1,     3,     2,     0,     8,
       3,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     0,     4,     3,     2,     2,     3,     1,     1,
       0,     2,     2,     1,     1,     3,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     7,
       5,     1,     1,     7,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     2,     3,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     2,     2,
       2,     3,     3,     6,     4,     4,     2,     4,     4,     2,
       2,     0,     1,     1,     1,     2,     3,     4,     3,     3,
       3,     3,     1,     1,     0,     3,     1,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     1,     1,     4,
       2,     4,     0,     0,     5,     1,     0,     2,     0,     7,
      11,    12,     8,     7,     8,     1,     1,     0,     5,     0,
       4,     0,     1,     0,    10,     6
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
  case 2:
#line 194 "new_parser.y"
                      {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;totalProgram = *(yyval.main).text;}
#line 1810 "new_parser.tab.c"
    break;

  case 3:
#line 195 "new_parser.y"
                     {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text; totalProgram = *(yyval.main).text;}
#line 1816 "new_parser.tab.c"
    break;

  case 4:
#line 196 "new_parser.y"
                       {
              (yyval.main).text = new string;
              if ((yyvsp[0].main).stopAdvanceFound) 
                     semanticError("stop/advance cannot be outside the loop");
              if(is_decl_stmt) {
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
                     is_decl_stmt = 0;
              }
              else {
                     collection.push_back(*(yyvsp[0].main).text);
                     *(yyval.main).text = *(yyvsp[-1].main).text;
              }
              totalProgram = *(yyval.main).text;
              
              }
#line 1836 "new_parser.tab.c"
    break;

  case 5:
#line 211 "new_parser.y"
                     {
              if(ret_flag) {
                     cerr << "Error: Return statement not allowed outside function" << endl;
              }
              (yyval.main).text = new string;
              *(yyval.main).text = "";
              totalProgram = *(yyval.main).text;
         }
#line 1849 "new_parser.tab.c"
    break;

  case 6:
#line 223 "new_parser.y"
                         { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype); addSymTabPtr(); }
#line 1855 "new_parser.tab.c"
    break;

  case 7:
#line 223 "new_parser.y"
                                                                                                 {
                     if(paramslist.size()>0) {
                            addParamList((yyvsp[-3].main).name,paramslist);
                            insertParams(paramslist);
                            paramslist.clear();
                     }
              }
#line 1867 "new_parser.tab.c"
    break;

  case 8:
#line 230 "new_parser.y"
                                         {
                     
                     if (ret_flag == 0) {
                            cerr<<"Error: Semantic error no return statement"<<endl;
                     }
                     else if ((yyvsp[-8].main).eletype != ret_type) {
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     
                     ret_flag = 0;
                     ret_fig_flag = 0;
                     ret_type = UNDEF;

                     if ((yyvsp[0].main).stopAdvanceFound){
                            semanticError("stop/advance cannot be outside the loop");
                     }

                     delete (yyvsp[-7].main).name;
                     delSymTabPtr();
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-8].main).text + *(yyvsp[-7].main).text + "(" + *((yyvsp[-4].main).text) + ")" +  *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
              }
#line 1894 "new_parser.tab.c"
    break;

  case 9:
#line 252 "new_parser.y"
                              { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype);  addSymTabPtr(); }
#line 1900 "new_parser.tab.c"
    break;

  case 10:
#line 252 "new_parser.y"
                                                                                                       {if(paramslist.size()>0) {
                     addParamList((yyvsp[-3].main).name,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
#line 1910 "new_parser.tab.c"
    break;

  case 11:
#line 257 "new_parser.y"
                                         {
                     paramslist.clear();
                     
                     if(ret_type!=UNDEF && ret_type!=Void) {
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     ret_flag = 0; 
                     ret_fig_flag = 0;
                     ret_type = UNDEF;

                     if ((yyvsp[0].main).stopAdvanceFound){
                            semanticError("stop/advance cannot be outside the loop");
                     }

                     delete (yyvsp[-7].main).name;
                     delSymTabPtr();
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-8].main).text + *(yyvsp[-7].main).text + "(" + *((yyvsp[-4].main).text) + ")" + *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
              }
#line 1934 "new_parser.tab.c"
    break;

  case 12:
#line 278 "new_parser.y"
                 {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 1940 "new_parser.tab.c"
    break;

  case 13:
#line 279 "new_parser.y"
                       {(yyval.main).text = new string;*(yyval.main).text = "";}
#line 1946 "new_parser.tab.c"
    break;

  case 14:
#line 282 "new_parser.y"
                          {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text;}
#line 1952 "new_parser.tab.c"
    break;

  case 15:
#line 283 "new_parser.y"
                  {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 1958 "new_parser.tab.c"
    break;

  case 16:
#line 286 "new_parser.y"
                                 {
              ParamList param;
              param.Eletype = (yyvsp[-2].main).eletype;
              param.name = (yyvsp[-1].main).name;
              param.dim = *(yyvsp[0].main).dimList;
              param.Type = Array;
              paramslist.push_back(param);
              delete (yyvsp[-1].main).name;
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 1974 "new_parser.tab.c"
    break;

  case 17:
#line 297 "new_parser.y"
                     {
              ParamList param;
              param.Eletype = (yyvsp[-1].main).eletype;
              param.name = (yyvsp[0].main).name;
              vector<int> dim;
              param.dim = dim;
              param.Type = Var;
              paramslist.push_back(param);
              delete (yyvsp[0].main).name;
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;

       }
#line 1992 "new_parser.tab.c"
    break;

  case 18:
#line 315 "new_parser.y"
            {insertType((yyvsp[0].main).name, Fig, UNDEF); addSymTabPtr();}
#line 1998 "new_parser.tab.c"
    break;

  case 19:
#line 315 "new_parser.y"
                                                                                                       { 
                                                        if (ret_fig_flag == 1)  
                                                               semanticError("Error: Return statement is not allowed in figures."); 
                                                        ret_fig_flag = 0;
                                                        

                                                        if ((yyvsp[0].main).stopAdvanceFound)
                                                               semanticError("stop/advance cannot be outside the loop");

                                                        delSymTabPtr();
                                                        delete (yyvsp[-6].main).name;
                                                        (yyval.main).text = new string;
                                                        *(yyval.main).text = "void " + *(yyvsp[-6].main).text + "(" + *(yyvsp[-3].main).text + ")" + *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
                                                        
                                                        // reset scale and center
                                                        scale = "1.0";
                                                        center = "Point(0, 0, false)";
                                                 }
#line 2021 "new_parser.tab.c"
    break;

  case 20:
#line 334 "new_parser.y"
                                   { 
              if(!(arithCompatible((yyvsp[-2].main).eletype) && (yyvsp[0].main).eletype == POINT)) 
                     semanticError("Error: Semantic error incompatible datatype..") ;
              scale = *(yyvsp[-2].main).text;
              center = centerTranslation(*(yyvsp[0].main).text);
              (yyval.main).text = new string;
              *(yyval.main).text = "double scale = " + *(yyvsp[-2].main).text + " , Point center = " + *(yyvsp[0].main).text; 
       }
#line 2034 "new_parser.tab.c"
    break;

  case 21:
#line 342 "new_parser.y"
                                                            { 
              if(!(arithCompatible((yyvsp[-4].main).eletype) && (yyvsp[0].main).eletype == POINT)) 
                     semanticError("Error: Semantic error incompatible datatype") ;
              scale = *(yyvsp[-4].main).text;
              center = centerTranslation(*(yyvsp[-4].main).text);
              (yyval.main).text = new string;
              *(yyval.main).text = "double scale = " + *(yyvsp[-4].main).text + " , Point center = " + *(yyvsp[0].main).text;
       }
#line 2047 "new_parser.tab.c"
    break;

  case 22:
#line 352 "new_parser.y"
                 {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2053 "new_parser.tab.c"
    break;

  case 23:
#line 353 "new_parser.y"
                {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2059 "new_parser.tab.c"
    break;

  case 24:
#line 354 "new_parser.y"
                 {(yyval.main).stopAdvanceFound = false;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text; is_decl_stmt = 1;}
#line 2065 "new_parser.tab.c"
    break;

  case 25:
#line 355 "new_parser.y"
                   {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2071 "new_parser.tab.c"
    break;

  case 26:
#line 356 "new_parser.y"
                   {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2077 "new_parser.tab.c"
    break;

  case 27:
#line 357 "new_parser.y"
                  {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2083 "new_parser.tab.c"
    break;

  case 28:
#line 358 "new_parser.y"
                  {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2089 "new_parser.tab.c"
    break;

  case 29:
#line 359 "new_parser.y"
                  {(yyval.main).stopAdvanceFound = true; (yyval.main).text = new string;*(yyval.main).text= *(yyvsp[0].main).text ;}
#line 2095 "new_parser.tab.c"
    break;

  case 30:
#line 363 "new_parser.y"
       {
              (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound || (yyvsp[0].main).stopAdvanceFound;
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2105 "new_parser.tab.c"
    break;

  case 31:
#line 368 "new_parser.y"
                      {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2111 "new_parser.tab.c"
    break;

  case 32:
#line 371 "new_parser.y"
            { addSymTabPtr(); }
#line 2117 "new_parser.tab.c"
    break;

  case 33:
#line 372 "new_parser.y"
              { 
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     delSymTabPtr(); 
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}" ;
              }
#line 2128 "new_parser.tab.c"
    break;

  case 34:
#line 381 "new_parser.y"
              { 
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound; 
                     delSymTabPtr(); 
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}" ;
              }
#line 2139 "new_parser.tab.c"
    break;

  case 35:
#line 389 "new_parser.y"
                            {(yyval.main).text = new string;*(yyval.main).text = "break;\n";}
#line 2145 "new_parser.tab.c"
    break;

  case 36:
#line 390 "new_parser.y"
                              { (yyval.main).text = new string;*(yyval.main).text = "continue;\n";}
#line 2151 "new_parser.tab.c"
    break;

  case 37:
#line 394 "new_parser.y"
                                     {ret_type = (yyvsp[-1].main).eletype; ret_flag = 1; ret_fig_flag = 1; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";"; }
#line 2157 "new_parser.tab.c"
    break;

  case 38:
#line 396 "new_parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text; }
#line 2163 "new_parser.tab.c"
    break;

  case 39:
#line 397 "new_parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2169 "new_parser.tab.c"
    break;

  case 40:
#line 398 "new_parser.y"
                     {(yyval.main).eletype = Void; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2175 "new_parser.tab.c"
    break;

  case 41:
#line 401 "new_parser.y"
                                 {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + ";";}
#line 2181 "new_parser.tab.c"
    break;

  case 42:
#line 402 "new_parser.y"
                                 {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + ";";}
#line 2187 "new_parser.tab.c"
    break;

  case 43:
#line 406 "new_parser.y"
                 {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2193 "new_parser.tab.c"
    break;

  case 44:
#line 407 "new_parser.y"
                 {(yyval.main).text = new string; *(yyval.main).text = "-";}
#line 2199 "new_parser.tab.c"
    break;

  case 45:
#line 410 "new_parser.y"
                                {(yyval.main).count = (yyval.main).count + 1;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[-2].main).text + "|" + *(yyvsp[-1].main).text + "|" + *(yyvsp[0].main).text;}
#line 2205 "new_parser.tab.c"
    break;

  case 46:
#line 411 "new_parser.y"
                               {(yyval.main).count = 1;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "|" + *(yyvsp[-1].main).text + "|" + *(yyvsp[0].main).text;}
#line 2211 "new_parser.tab.c"
    break;

  case 47:
#line 414 "new_parser.y"
                                                      {(yyval.main).eletype = (yyvsp[-3].main).eletype; construct_params.clear(); (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-3].main).text + "(" + *(yyvsp[-1].main).text + "," + scale + "," + center + ")" ;}
#line 2217 "new_parser.tab.c"
    break;

  case 48:
#line 415 "new_parser.y"
                                {(yyval.main).eletype = (yyvsp[-2].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "(" + scale + "," + center + ")" ;}
#line 2223 "new_parser.tab.c"
    break;

  case 49:
#line 418 "new_parser.y"
                           { (yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2229 "new_parser.tab.c"
    break;

  case 50:
#line 419 "new_parser.y"
                              { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2235 "new_parser.tab.c"
    break;

  case 51:
#line 420 "new_parser.y"
                            { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2241 "new_parser.tab.c"
    break;

  case 52:
#line 421 "new_parser.y"
                               { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2247 "new_parser.tab.c"
    break;

  case 53:
#line 424 "new_parser.y"
                     {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2253 "new_parser.tab.c"
    break;

  case 54:
#line 425 "new_parser.y"
                      {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2259 "new_parser.tab.c"
    break;

  case 55:
#line 428 "new_parser.y"
                                     {
              if(is_member) {
                  params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
              *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text;
          }
#line 2275 "new_parser.tab.c"
    break;

  case 56:
#line 439 "new_parser.y"
                      {
              if(is_member) {
                     params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                     is_member = 0;
              }
              else {
                     vector<int> dim;
                     params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
              *(yyval.main).text = *(yyvsp[0].main).text;
          }
#line 2291 "new_parser.tab.c"
    break;

  case 57:
#line 452 "new_parser.y"
                                                         {
              if(is_member) {
                  construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text;
          }
#line 2308 "new_parser.tab.c"
    break;

  case 58:
#line 464 "new_parser.y"
                      {
              if(is_member) {
                     construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                    is_member = 0;
                    
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[0].main).text;
          }
#line 2326 "new_parser.tab.c"
    break;

  case 59:
#line 480 "new_parser.y"
                                                            { (yyval.main).eletype = pointCheck((yyvsp[-5].main).eletype, (yyvsp[-3].main).eletype); (yyval.main).text = new string; *(yyval.main).text = "Point(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")"; }
#line 2332 "new_parser.tab.c"
    break;

  case 60:
#line 481 "new_parser.y"
                                               { (yyval.main).eletype = pointCheck((yyvsp[-3].main).eletype, (yyvsp[-1].main).eletype);(yyval.main).text = new string;*(yyval.main).text = "Point(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text +  ")";}
#line 2338 "new_parser.tab.c"
    break;

  case 61:
#line 485 "new_parser.y"
                      { if ((yyvsp[0].main).eletype != POINT) semanticError("Error: vertex has to be a point"); (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 2344 "new_parser.tab.c"
    break;

  case 62:
#line 487 "new_parser.y"
                      { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 2350 "new_parser.tab.c"
    break;

  case 63:
#line 490 "new_parser.y"
                                                  {(yyval.main).eletype = ANGLE; (yyval.main).text = new string; *(yyval.main).text = "angleBetweenPoints(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-4].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")";}
#line 2356 "new_parser.tab.c"
    break;

  case 64:
#line 491 "new_parser.y"
                                      {(yyval.main).eletype = ANGLE; (yyval.main).text = new string; *(yyval.main).text = "angleBetweenPoints(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-2].main).text + "," + *(yyvsp[-1].main).text + ")";}
#line 2362 "new_parser.tab.c"
    break;

  case 65:
#line 494 "new_parser.y"
                                        {  (yyval.main).eletype = sumTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text;}
#line 2368 "new_parser.tab.c"
    break;

  case 66:
#line 495 "new_parser.y"
                                        {  (yyval.main).eletype = diffTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string;
                                            if ((yyval.main).eletype == LINE)
                                                 *(yyval.main).text = "Line(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")";
                                            else 
                                                 *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text;
                                         }
#line 2379 "new_parser.tab.c"
    break;

  case 67:
#line 501 "new_parser.y"
                                            {if ((yyvsp[-2].main).eletype != POINT || (yyvsp[0].main).eletype != POINT) semanticError("Incompatible datatypes\n");(yyval.main).eletype = LINE;(yyval.main).text = new string; *(yyval.main).text = "Line(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")";}
#line 2385 "new_parser.tab.c"
    break;

  case 68:
#line 502 "new_parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "*" + *(yyvsp[0].main).text;}
#line 2391 "new_parser.tab.c"
    break;

  case 69:
#line 503 "new_parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[-2].main).text + "/" + *(yyvsp[0].main).text;}
#line 2397 "new_parser.tab.c"
    break;

  case 70:
#line 504 "new_parser.y"
                                        { if ((yyvsp[-2].main).eletype != INT || (yyvsp[0].main).eletype != INT) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = INT; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text;}
#line 2403 "new_parser.tab.c"
    break;

  case 71:
#line 505 "new_parser.y"
                                        { (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string;*(yyval.main).text = "pow(" + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + ")";}
#line 2409 "new_parser.tab.c"
    break;

  case 72:
#line 506 "new_parser.y"
                                             { (yyval.main).eletype = parallelCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string;*(yyval.main).text = "isParallel(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")" ; }
#line 2415 "new_parser.tab.c"
    break;

  case 73:
#line 507 "new_parser.y"
                                                   {(yyval.main).eletype = perpendicularCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); (yyval.main).text = new string; *(yyval.main).text = "isPerpendicular(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")" ;}
#line 2421 "new_parser.tab.c"
    break;

  case 74:
#line 508 "new_parser.y"
                                             { (yyval.main).eletype = REAL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text;}
#line 2427 "new_parser.tab.c"
    break;

  case 75:
#line 509 "new_parser.y"
                                       {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = "-" + *(yyvsp[0].main).text;}
#line 2433 "new_parser.tab.c"
    break;

  case 76:
#line 510 "new_parser.y"
                                  {if(!((yyvsp[0].main).eletype == INT || (yyvsp[0].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2439 "new_parser.tab.c"
    break;

  case 77:
#line 511 "new_parser.y"
                                  {if(!((yyvsp[-1].main).eletype == INT || (yyvsp[-1].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2445 "new_parser.tab.c"
    break;

  case 78:
#line 512 "new_parser.y"
                             {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;(yyval.main).text = new string;*(yyval.main).text = "!" + *(yyvsp[-1].main).text;}
#line 2451 "new_parser.tab.c"
    break;

  case 79:
#line 513 "new_parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "&&" + *(yyvsp[0].main).text; }
#line 2457 "new_parser.tab.c"
    break;

  case 80:
#line 514 "new_parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "||" + *(yyvsp[0].main).text; }
#line 2463 "new_parser.tab.c"
    break;

  case 81:
#line 515 "new_parser.y"
                                         {if (!(((yyvsp[-1].main).eletype == (yyvsp[0].main).eletype) || coercible((yyvsp[-1].main).eletype, (yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = assignTranslation(*(yyvsp[0].main).text,*(yyvsp[-1].main).text);}
#line 2469 "new_parser.tab.c"
    break;

  case 82:
#line 516 "new_parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2475 "new_parser.tab.c"
    break;

  case 83:
#line 517 "new_parser.y"
                                        { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "<" + *(yyvsp[0].main).text; }
#line 2481 "new_parser.tab.c"
    break;

  case 84:
#line 518 "new_parser.y"
                                         { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + ">" + *(yyvsp[0].main).text; }
#line 2487 "new_parser.tab.c"
    break;

  case 85:
#line 519 "new_parser.y"
                                              {if(!((arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) || ((yyvsp[-2].main).eletype == (yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2493 "new_parser.tab.c"
    break;

  case 86:
#line 520 "new_parser.y"
                            {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2499 "new_parser.tab.c"
    break;

  case 87:
#line 521 "new_parser.y"
                                 {(yyval.main).eletype = (yyvsp[-1].main).eletype; (yyval.main).text = new string;*(yyval.main).text = "(" + *(yyvsp[-1].main).text + ")";}
#line 2505 "new_parser.tab.c"
    break;

  case 88:
#line 522 "new_parser.y"
                     {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2511 "new_parser.tab.c"
    break;

  case 89:
#line 523 "new_parser.y"
                       {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2517 "new_parser.tab.c"
    break;

  case 90:
#line 524 "new_parser.y"
                      { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2523 "new_parser.tab.c"
    break;

  case 91:
#line 525 "new_parser.y"
                           { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2529 "new_parser.tab.c"
    break;

  case 92:
#line 526 "new_parser.y"
                        {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2535 "new_parser.tab.c"
    break;

  case 93:
#line 527 "new_parser.y"
                    { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2541 "new_parser.tab.c"
    break;

  case 94:
#line 528 "new_parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2547 "new_parser.tab.c"
    break;

  case 95:
#line 532 "new_parser.y"
                                { (yyval.main).text = new string;*(yyval.main).text = "norm( " + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + " )";}
#line 2553 "new_parser.tab.c"
    break;

  case 96:
#line 533 "new_parser.y"
                        { (yyval.main).text = new string;*(yyval.main).text = "norm( " + *(yyvsp[0].main).text + " )";}
#line 2559 "new_parser.tab.c"
    break;

  case 97:
#line 537 "new_parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = "=" + *(yyvsp[0].main).text;}
#line 2565 "new_parser.tab.c"
    break;

  case 98:
#line 538 "new_parser.y"
                                {if(!(arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = assignOpTranslation(*(yyvsp[-1].main).text) + *(yyvsp[0].main).text;}
#line 2571 "new_parser.tab.c"
    break;

  case 99:
#line 539 "new_parser.y"
                                    {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == LABEL || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = "+=" + *(yyvsp[0].main).text;}
#line 2577 "new_parser.tab.c"
    break;

  case 100:
#line 540 "new_parser.y"
                                  {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = "-=" + *(yyvsp[0].main).text;}
#line 2583 "new_parser.tab.c"
    break;

  case 101:
#line 544 "new_parser.y"
                                     {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";"; }
#line 2589 "new_parser.tab.c"
    break;

  case 102:
#line 545 "new_parser.y"
                                        {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";";}
#line 2595 "new_parser.tab.c"
    break;

  case 103:
#line 549 "new_parser.y"
       {
              (yyval.main).nameList = (yyvsp[-5].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);
              compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text  + *(yyvsp[0].main).text;
       }
#line 2607 "new_parser.tab.c"
    break;

  case 104:
#line 557 "new_parser.y"
       {
              (yyval.main).nameList = (yyvsp[-3].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2619 "new_parser.tab.c"
    break;

  case 105:
#line 565 "new_parser.y"
       {
              (yyval.main).nameList = (yyvsp[-3].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2631 "new_parser.tab.c"
    break;

  case 106:
#line 573 "new_parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2643 "new_parser.tab.c"
    break;

  case 107:
#line 581 "new_parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);
              compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2655 "new_parser.tab.c"
    break;

  case 108:
#line 588 "new_parser.y"
                                    {

              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);

              if ((yyvsp[-2].main).dimList->size() != 1){
                     semanticError("Dimensions of linearr don't match");
              }

              compareAndInsertLineArr((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).count);

              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text  + "=" + translateLineArr(*(yyvsp[0].main).text);

       }
#line 2675 "new_parser.tab.c"
    break;

  case 109:
#line 604 "new_parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2687 "new_parser.tab.c"
    break;

  case 110:
#line 613 "new_parser.y"
                              {(yyval.main).eletype = (yyvsp[0].main).eletype ; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text; }
#line 2693 "new_parser.tab.c"
    break;

  case 111:
#line 614 "new_parser.y"
                      {(yyval.main).eletype = UNDEF; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2699 "new_parser.tab.c"
    break;

  case 112:
#line 617 "new_parser.y"
                       {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2705 "new_parser.tab.c"
    break;

  case 113:
#line 618 "new_parser.y"
                       {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2711 "new_parser.tab.c"
    break;

  case 114:
#line 622 "new_parser.y"
               {(yyval.main).dimList = (yyvsp[0].main).dimList; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2717 "new_parser.tab.c"
    break;

  case 115:
#line 623 "new_parser.y"
                   {(yyval.main).dimList = new vector<int>;(yyval.main).dimList->push_back(-1); (yyval.main).text = new string;*(yyval.main).text = "[]";}
#line 2723 "new_parser.tab.c"
    break;

  case 116:
#line 624 "new_parser.y"
                       {(yyval.main).dimList = new vector<int>;addFrontAndCopy((yyval.main).dimList, (yyvsp[0].main).dimList, -1);delete (yyvsp[0].main).dimList; (yyval.main).text = new string;*(yyval.main).text = "[]" + *(yyvsp[0].main).text; }
#line 2729 "new_parser.tab.c"
    break;

  case 117:
#line 627 "new_parser.y"
                             {(yyval.main).dimList = (yyvsp[-3].main).dimList;
                              
                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);
                            (yyval.main).text = new string;
                            *(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";
                            
                            }
#line 2744 "new_parser.tab.c"
    break;

  case 118:
#line 637 "new_parser.y"
                         {(yyval.main).dimList = new vector<int>; 

                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);

                            (yyval.main).text = new string;
                            *(yyval.main).text =  "[" + *(yyvsp[-1].main).text + "]";
                         }
#line 2759 "new_parser.tab.c"
    break;

  case 119:
#line 652 "new_parser.y"
              {
                     (yyval.main).listAndType.dimList = new vector<int>; 
                     (yyval.main).listAndType.dimList->push_back((yyvsp[-1].main).countAndType.count); 
                     (yyval.main).listAndType.eletype = (yyvsp[-1].main).countAndType.eletype; 
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}";
              }
#line 2771 "new_parser.tab.c"
    break;

  case 120:
#line 660 "new_parser.y"
              {
                     (yyval.main).listAndType.dimList = (yyvsp[-1].main).listAndType.dimList;
                     (yyval.main).listAndType.eletype = (yyvsp[-1].main).listAndType.eletype;
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}";
              }
#line 2782 "new_parser.tab.c"
    break;

  case 121:
#line 669 "new_parser.y"
              {
                     updateMaxDim((yyvsp[-2].main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList); 
                     delete (yyvsp[0].main).listAndType.dimList;(yyval.main).listAndType.dimList = (yyvsp[-2].main).listAndType.dimList;
                     if (!coercible((yyvsp[-2].main).listAndType.eletype, (yyvsp[0].main).listAndType.eletype)) semanticError("arrays should be initialized with same datatype");
                     else (yyval.main).listAndType.eletype = (yyvsp[-2].main).listAndType.eletype;
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text ;
              }
#line 2795 "new_parser.tab.c"
    break;

  case 122:
#line 678 "new_parser.y"
              {
                     (yyval.main).listAndType.dimList = new vector<int>; 
                     addFrontAndCopy((yyval.main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList, 1);
                     delete (yyvsp[0].main).listAndType.dimList;
                     (yyval.main).listAndType.eletype = (yyvsp[0].main).listAndType.eletype;
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[0].main).text;
              }
#line 2808 "new_parser.tab.c"
    break;

  case 123:
#line 688 "new_parser.y"
                             {(yyval.main).countAndType.count = (yyvsp[0].main).countAndType.count;(yyval.main).eletype = (yyvsp[0].main).countAndType.eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2814 "new_parser.tab.c"
    break;

  case 124:
#line 689 "new_parser.y"
                           {(yyval.main).countAndType.count = 0;(yyval.main).eletype = UNDEF; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2820 "new_parser.tab.c"
    break;

  case 125:
#line 693 "new_parser.y"
              {
                     (yyval.main).count = (yyvsp[-2].main).countAndType.count + 1; 
                     if (!coercible((yyvsp[-2].main).countAndType.eletype, (yyvsp[0].main).eletype)) semanticError("arrays should be initialized with same datatype");
                     else (yyval.main).countAndType.eletype = (yyvsp[0].main).eletype;
                      
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text ;
              }
#line 2833 "new_parser.tab.c"
    break;

  case 126:
#line 701 "new_parser.y"
                           {(yyval.main).countAndType.count = 1;(yyval.main).countAndType.eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2839 "new_parser.tab.c"
    break;

  case 127:
#line 704 "new_parser.y"
                                      {(yyval.main).constExp.eletype = sumTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d + (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i + (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d + (yyvsp[0].main).constExp.i;
                                          else 
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i + (yyvsp[0].main).constExp.i;      

                                          (yyval.main).text = new string;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text  ;                     
                                      }
#line 2858 "new_parser.tab.c"
    break;

  case 128:
#line 718 "new_parser.y"
                                   {(yyval.main).constExp.eletype = diffTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d - (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i - (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d - (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i - (yyvsp[0].main).constExp.i;
                                          
                                          (yyval.main).text = new string;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text  ;
                                   }
#line 2877 "new_parser.tab.c"
    break;

  case 129:
#line 732 "new_parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d * (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i * (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d * (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i * (yyvsp[0].main).constExp.i;
                                          (yyval.main).text = new string;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "*" + *(yyvsp[0].main).text  ;     
                                   }
#line 2895 "new_parser.tab.c"
    break;

  case 130:
#line 745 "new_parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d / (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i / (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d / (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i / (yyvsp[0].main).constExp.i;

                                          (yyval.main).text = new string;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "/" + *(yyvsp[0].main).text  ;
                                   }
#line 2914 "new_parser.tab.c"
    break;

  case 131:
#line 759 "new_parser.y"
                                   {if ((yyvsp[-2].main).constExp.eletype != INT || (yyvsp[0].main).constExp.eletype != INT) semanticError("Error: Semantic error incompatible datatype");(yyval.main).constExp.eletype = INT;
                                          (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i % (yyvsp[0].main).constExp.i;
                                          (yyval.main).text = new string;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text  ;
                                   }
#line 2924 "new_parser.tab.c"
    break;

  case 132:
#line 764 "new_parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.d, (yyvsp[0].main).constExp.d);
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.i, (yyvsp[0].main).constExp.d);  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.d, (yyvsp[0].main).constExp.i);
                                          else
                                                 (yyval.main).constExp.i = pow((yyvsp[-2].main).constExp.i, (yyvsp[0].main).constExp.i);
                                          (yyval.main).text = new string;
                                          *(yyval.main).text = "pow(" + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + ")" ;
                                   }
#line 2942 "new_parser.tab.c"
    break;

  case 133:
#line 777 "new_parser.y"
                        {   
                            if (!arithCompatible((yyvsp[0].main).constExp.eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).constExp.eletype = (yyvsp[0].main).constExp.eletype;

                            if ((yyval.main).constExp.eletype == REAL) 
                                   (yyval.main).constExp.d = -(yyvsp[0].main).constExp.d; 
                            else 
                                   (yyval.main).constExp.i = -(yyvsp[0].main).constExp.i;
                            (yyval.main).text = new string;
                            *(yyval.main).text = "-" + *(yyvsp[0].main).text ;
                        }
#line 2957 "new_parser.tab.c"
    break;

  case 134:
#line 787 "new_parser.y"
                            {      
                                   (yyval.main).constExp.eletype = (yyvsp[-1].main).constExp.eletype;
                                   if ((yyval.main).constExp.eletype == REAL) 
                                          (yyval.main).constExp.d = (yyvsp[-1].main).constExp.d; 
                                   else 
                                          (yyval.main).constExp.i = (yyvsp[-1].main).constExp.i;
                                   (yyval.main).text = new string;
                                   *(yyval.main).text = "(" + *(yyvsp[-1].main).text  + ")";
                            }
#line 2971 "new_parser.tab.c"
    break;

  case 135:
#line 796 "new_parser.y"
                { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;(yyval.main).constExp.d = (yyvsp[0].main).constExp.d;}
#line 2977 "new_parser.tab.c"
    break;

  case 136:
#line 797 "new_parser.y"
                  { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype; (yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2983 "new_parser.tab.c"
    break;

  case 137:
#line 798 "new_parser.y"
                 { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = INT; (yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2989 "new_parser.tab.c"
    break;

  case 138:
#line 803 "new_parser.y"
                            {
              if((yyvsp[0].main).dimCount->empty()) {
                     exit(1);
              }
              typelist = returnType(*(yyvsp[0].main).dimCount);
              (yyval.main).eletype = typelist.Eletype;
              for (int i = 0;i < (yyvsp[0].main).dimCount->size();i++){
                     delete ((yyvsp[0].main).dimCount->at(i)).name ;
              }
              is_member = 1;
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[0].main).text;
       }
#line 3007 "new_parser.tab.c"
    break;

  case 139:
#line 817 "new_parser.y"
                                            {
                     (yyval.main).dimCount = (yyvsp[-3].main).dimCount; 
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});
                     }
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-3].main).text + "." + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3021 "new_parser.tab.c"
    break;

  case 140:
#line 826 "new_parser.y"
                              {
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     (yyval.main).dimCount = new vector<cntAndType> ;   //free?
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});  
                     } 
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;    
              }
#line 3035 "new_parser.tab.c"
    break;

  case 141:
#line 838 "new_parser.y"
                                          {(yyval.main).count = (yyvsp[-3].main).count; (yyval.main).count = (yyval.main).count + 1; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";}
#line 3041 "new_parser.tab.c"
    break;

  case 142:
#line 839 "new_parser.y"
                        {(yyval.main).count = 0; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 3047 "new_parser.tab.c"
    break;

  case 143:
#line 842 "new_parser.y"
                          {

              if (typelist.Type == Fig){
                     is_fig = 1;
              }
              else {
                     if (typelist.Type != Func) 
                            semanticError("Error: Identifier is not a function"); 
                     func_paramlist = typelist.paramList;
              }
              is_member = 0;
       }
#line 3064 "new_parser.tab.c"
    break;

  case 144:
#line 854 "new_parser.y"
                              {

              if (is_fig){
                     figArgumentChecking(params);
                     params.clear();
                     (yyval.main).eletype = UNDEF;
              }
              else {

                     argumentTypeChecking(func_paramlist, params);
                     params.clear();

                     (yyval.main).eletype = (yyvsp[-4].main).eletype;              
              }

              is_fig = 0;
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-4].main).text + "(" + *(yyvsp[-1].main).text + ")";
       }
#line 3088 "new_parser.tab.c"
    break;

  case 145:
#line 875 "new_parser.y"
                            {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 3094 "new_parser.tab.c"
    break;

  case 146:
#line 876 "new_parser.y"
                             {(yyval.main).text = new string;*(yyval.main).text = "";}
#line 3100 "new_parser.tab.c"
    break;

  case 147:
#line 879 "new_parser.y"
                                  { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;}
#line 3106 "new_parser.tab.c"
    break;

  case 148:
#line 880 "new_parser.y"
                                  { (yyval.main).text = new string;*(yyval.main).text = "";}
#line 3112 "new_parser.tab.c"
    break;

  case 149:
#line 886 "new_parser.y"
              {     
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if (!(arithCompatible((yyvsp[-4].main).eletype))) 
                            semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-6].main).text + "(" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
              }
#line 3124 "new_parser.tab.c"
    break;

  case 150:
#line 894 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-5].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-8].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-10].main).text + "(" + *(yyvsp[-8].main).text + ")" + *(yyvsp[-6].main).text + *(yyvsp[-5].main).text + *(yyvsp[-4].main).text + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3135 "new_parser.tab.c"
    break;

  case 151:
#line 901 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-6].main).stopAdvanceFound||(yyvsp[-4].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-9].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-11].main).text + "(" + *(yyvsp[-9].main).text + ")" + *(yyvsp[-7].main).text + *(yyvsp[-6].main).text + *(yyvsp[-5].main).text + *(yyvsp[-4].main).text + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3146 "new_parser.tab.c"
    break;

  case 152:
#line 908 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-2].main).stopAdvanceFound||(yyvsp[0].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-5].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-7].main).text + "(" + *(yyvsp[-5].main).text + ")" + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3157 "new_parser.tab.c"
    break;

  case 153:
#line 917 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = "else if (" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3168 "new_parser.tab.c"
    break;

  case 154:
#line 924 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-7].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-7].main).text + "else if (" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3179 "new_parser.tab.c"
    break;

  case 155:
#line 935 "new_parser.y"
                     { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 3185 "new_parser.tab.c"
    break;

  case 156:
#line 936 "new_parser.y"
                     { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 3191 "new_parser.tab.c"
    break;

  case 157:
#line 939 "new_parser.y"
                { addSymTabPtr(); }
#line 3197 "new_parser.tab.c"
    break;

  case 158:
#line 940 "new_parser.y"
              {
                     insertType((yyvsp[-2].main).name, Var, (yyvsp[-3].main).eletype);
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
                     delete (yyvsp[-2].main).name;
              }
#line 3208 "new_parser.tab.c"
    break;

  case 159:
#line 946 "new_parser.y"
                { addSymTabPtr(); }
#line 3214 "new_parser.tab.c"
    break;

  case 160:
#line 948 "new_parser.y"
              { 
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
                     delete (yyvsp[-2].main).name; 
              }
#line 3224 "new_parser.tab.c"
    break;

  case 161:
#line 953 "new_parser.y"
                { addSymTabPtr(); (yyval.main).text = new string;*(yyval.main).text = "";}
#line 3230 "new_parser.tab.c"
    break;

  case 162:
#line 956 "new_parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 3236 "new_parser.tab.c"
    break;

  case 163:
#line 957 "new_parser.y"
                          {(yyval.main).eletype = UNDEF;(yyval.main).text = new string;*(yyval.main).text = "";}
#line 3242 "new_parser.tab.c"
    break;

  case 164:
#line 961 "new_parser.y"
              { 
                     if(!(arithCompatible((yyvsp[-5].main).eletype)) && (yyvsp[-5].main).eletype != UNDEF) semanticError("Error: Semantic error incompatible datatype11");
                     (yyval.main).text = new string;
                     *(yyval.main).text = "for (" + *(yyvsp[-7].main).text + ";" + *(yyvsp[-5].main).text + ";" + *(yyvsp[-3].main).text + ")" + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3252 "new_parser.tab.c"
    break;

  case 165:
#line 967 "new_parser.y"
                                                              {(yyval.main).text = new string;*(yyval.main).text = "while (" + *(yyvsp[-3].main).text + ")" + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 3258 "new_parser.tab.c"
    break;


#line 3262 "new_parser.tab.c"

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
#line 971 "new_parser.y"


/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

/* string function_translation(string text) {
       return "true";
}

string fig_translation(string text) {
       return "true";
} */

string assignOpTranslation(string op) {

       string translatedOp;
       if(op=="*:=") {
              translatedOp = "*=";
       }
       else if(op=="/:=") {
              translatedOp = "/=";
       }
       else if(op=="%:=") {
              translatedOp = "%=";
       }
       else if(op=="^:=") {
              translatedOp = "^=";   //change this later
       }

       return op;

}

string assignTranslation(string assignText,string memText) {
       string translation;
       if(assignText.substr(0,2)=="^=") {
              string expr = assignText.substr(2,assignText.size()-2);
              translation = memText + " = pow(" + memText + "," + expr + ")";
       }
       else {
              translation = memText + assignText;
       }
       return translation;
}

string convertLineOp(string s){

       if (s == "-")
              return "SEGMENT";
       else if (s == "->")
              return "RAY";
       else if (s == "<->")
              return "LINE";
       
       return "";

}

string translateLineArr(string linearr){

       int prevIndex = 0;

       vector<string> args;

       for (int i = 0;i < linearr.size();i++){

              if (linearr[i] == '|'){

                     args.push_back(linearr.substr(prevIndex, i-prevIndex));
                     prevIndex = i+1;
              }
       }

       args.push_back(linearr.substr(prevIndex));


       string output = "{ ";

       for (int i = 0;i+2 < args.size();i+=2){

              output = output + "Line(" + args[i] + ", " + args[i+2] + ", " + convertLineOp(args[i+1]) + "), ";
       }

       output[output.size()-2] = ' ';

       output = output + "}";

       return output;
}

/*
string datatypeTranslation(string dtype) {

       string type;

       if (dtype == "real") {
              type = "double";
       }
       else if (dtype == "angle") {
              type = "double";
       }
       else if (dtype == "label") {
              type = "string";
       }
       else {
              type = dtype;
       }

       return type;
       
}
*/

string centerTranslation(string center) {
       string translatedCenter;
       if(center[0]=='(') {
              int idx = center.find(',');
              if(idx!=string::npos) {
                     string x = center.substr(1,idx-1);
                     string y = center.substr(idx+1,center.size()-idx-1);
                     translatedCenter = "Point(" + x + "," + y + ", false)";
              }
       }
       else {
              string x = center + ".x";
              string y = center + ".y";
              translatedCenter = "Point(" + x + "," + y + ", false)";
       }

       return translatedCenter;
}


int main(int argc, char*argv[])
{    

    yydebug = 1;

    if (argc < 2){

        fprintf(stderr, "Please provide the input file\n");
        exit(1);
    }
    /* Appending \n */ 
    FILE* a = fopen(argv[1], "a");
       
    if (a == NULL)
    {
       fprintf(stderr, "%s file could not be opened\n", argv[1]);
       fclose(a);
       exit(1);
    }

    fprintf(a, "\n");

    fclose(a);


    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", argv[1]);
      fclose(fp);
      exit(1);
    }

    yyin = fp;

    /* For testing Lexer */
    const char* tokenFilename = "seq_token.txt";
    fout_token = fopen(tokenFilename, "w");

    if (fout_token == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", tokenFilename);
      fclose(fout_token);
      exit(1);
    }

    
    /*For translation */

    const char* translatedFilename = "translated.cpp";
    fout_translated = fopen(translatedFilename, "w");

    if (fout_translated == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", translatedFilename);
      exit(1);
    }

    fprintf(fout_translated,"#include<iostream>\n");
    fprintf(fout_translated,"#include<vector>\n");
    fprintf(fout_translated,"#include<GL/glut.h>\n");
    fprintf(fout_translated,"#include<string>\n");
    fprintf(fout_translated,"#include<cstdlib>\n");
    fprintf(fout_translated,"#include<cmath>\n");
    fprintf(fout_translated,"#include<deque>\n");
    fprintf(fout_translated,"#include \"standard_lib.hpp\" \n\n\n");
    

    insertConstructTab();

    int x = yyparse();
    

    fprintf(fout_translated, "%s", totalProgram.c_str());

    fprintf(fout_translated, "\n\nint main(){\n");

    for (int i = 0;i < collection.size();i++)
       fprintf(fout_translated, "%s", collection[i].c_str());
    
    

    fprintf(fout_translated, "\n return 0;\n}\n");


    fclose(fp);
    fclose(fout_token);
    fclose(fout_translated);
    
    return x;
} 
