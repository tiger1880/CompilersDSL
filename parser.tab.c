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

using namespace std;

/*     ONLY FOR  DEBUGGING    */
template < typename T >
void print(vector<T>& v){

    for (int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    
    cout << "\n";
}

deque <string> collection;
deque <string> fig_func;
string datatypeTranslation(string dtype);
string assignOpTranslation(string op);
string assignTranslation(string assignText,string memText);
string centerTranslation(string center);

extern int yydebug;

#define YYDEBUG 1

/* Linearr left */


int ret_flag = 0;
int ret_fig_flag = 0;
int is_member = 0;
int isArray = 0;
int is_fig = 0;
int is_decl_stmt = 0;
int global_space = 1;

int lineArrNo = 0;

string scale = "1";
string center = "Point(0,0)";

enum eletype ret_type = UNDEF;

vector<ParamList> paramslist;
STentry typelist;
vector<types> params;
vector<types> construct_params;
vector<ParamList> func_paramlist;


#line 139 "parser.tab.c"

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
#line 72 "parser.y"


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
    

#line 268 "parser.tab.c"

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
#define YYLAST   1163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  337

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
      49,    50,    44,    42,    51,    43,    56,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,     2,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    57,    53,     2,     2,     2,     2,
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
       0,   195,   195,   195,   199,   199,   203,   215,   225,   225,
     225,   254,   254,   254,   280,   281,   284,   285,   288,   299,
     317,   317,   332,   339,   348,   349,   350,   351,   352,   353,
     354,   355,   358,   363,   366,   366,   374,   382,   383,   387,
     389,   390,   391,   394,   395,   424,   425,   428,   429,   430,
     431,   434,   435,   438,   449,   462,   474,   490,   491,   495,
     497,   500,   501,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   537,   538,   542,   543,   544,   545,   549,
     550,   553,   560,   567,   574,   581,   588,   597,   598,   601,
     602,   603,   604,   608,   609,   610,   613,   623,   637,   642,
     652,   659,   667,   675,   685,   686,   689,   697,   700,   714,
     727,   740,   753,   757,   770,   779,   788,   789,   790,   794,
     795,   796,   797,   798,   800,   814,   823,   834,   835,   838,
     838,   870,   871,   874,   875,   880,   888,   894,   900,   908,
     914,   925,   926,   929,   929,   935,   935,   941,   944,   945,
     948,   954
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
  "'/'", "'%'", "NEG", "'^'", "'('", "')'", "','", "'{'", "'}'", "'['",
  "']'", "'.'", "'|'", "$accept", "program", "func", "fig", "construct",
  "constructor", "arg_list", "list1", "argument", "params", "param_list",
  "construct_param_list", "param_list_opt", "point", "angle", "expression",
  "member_access", "assign", "func_call", "id_list", "mult_elements",
  "arr1d_in_list", "const_expr", "const_expr2", "check_arr", "dim",
  "arr_assign", "comma_arr_assign", "arr_assign_line", "decl_token",
  "decl_assign", "decl_stmt", "ret_var", "return_stmt", "optional_arg",
  "valid_arg", "arr_access", "memb_access", "empty_space", "inside_norm",
  "vertex", "stmt", "assign_stmt", "cond_stmt", "stmt_list", "stmt_block",
  "stmt_block_for", "elif_stmt", "break_stmt", "loop", "for_loop_decl",
  "for_loop", "while_loop", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "$@9", "$@10", "$@11", YY_NULLPTR
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
      41,    44,   123,   125,    91,    93,    46,   124
};
# endif

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-168)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -213,   324,  -213,  -213,  -213,  -213,    -4,     5,    43,   489,
      29,    65,    13,    68,    74,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,   573,    13,   573,   573,    84,    17,  -213,  -213,
    1006,     8,  -213,  -213,  -213,    61,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,    20,   103,    71,   573,   -18,   573,
    -213,    78,  1039,    99,  -213,  -213,   573,  -213,  -213,   120,
      95,  -213,   -12,   -11,    86,  -213,    13,   100,   661,  -213,
     448,    -7,   573,   573,   573,   573,   573,  -213,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,  -213,   573,
     573,   573,   573,  -213,    92,   113,     6,  -213,   116,  -213,
    -213,   842,   106,   136,   130,   883,  -213,   743,  -213,    13,
     511,    21,   141,   117,  -213,  -213,   144,   573,    13,  -213,
     573,  -213,  -213,   -20,  1039,  -213,  -213,   175,   150,  1072,
     233,    89,  1115,  1083,   233,   233,   175,   175,   100,   100,
     100,   100,  1039,  1039,  1039,  1039,   489,  -213,   148,   151,
    -213,   367,  -213,   573,   154,   153,  -213,  -213,  -213,  -213,
    -213,  -213,   595,   623,  -213,  -213,  1039,   458,    25,  -213,
    -213,  -213,  -213,   121,   121,   131,   257,   202,   121,   -12,
     249,    46,   702,  -213,   489,   138,   149,  -213,    86,  -213,
    -213,   155,  -213,  -213,   173,  1039,   146,   188,   573,   173,
     595,   180,   271,     9,   121,   121,   121,   121,   121,   121,
       1,     1,   121,   117,  -213,   202,  1039,  -213,  -213,   429,
     190,  -213,  -213,  -213,   225,  -213,   205,  -213,   489,  -213,
     187,   191,   545,  -213,   212,   573,   573,  1039,  -213,  -213,
    -213,   180,   180,   195,   195,   195,   195,  -213,   645,  -213,
    -213,  -213,  1039,   193,   196,  -213,    12,  -213,   202,   207,
     200,  -213,   231,   231,   219,   203,   776,    93,   206,  1039,
     645,   573,  -213,   209,  -213,  -213,  -213,  -213,   228,  -213,
     208,  -213,  -213,   573,  -213,   573,   213,  -213,    98,  -213,
    1039,  -213,   210,   217,   231,   218,   809,   173,  1039,   573,
     173,   214,  -213,   -15,  -213,  -213,  -213,  -213,   230,  -213,
     924,   244,   573,   173,  -213,  -213,   173,   173,   247,  -213,
    -213,   965,   251,   414,  -213,  -213,   573,   173,  -213,  -213,
    -213,  1039,   254,   173,  -213,   258,  -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     2,     1,    87,    88,    86,     0,     0,     0,    42,
       0,     0,     0,     0,     0,    89,    29,   148,    47,    48,
      49,    50,     0,     0,     0,     0,     0,     0,    91,    92,
       0,    84,    90,    26,    28,   144,     6,    27,    24,    30,
      31,    25,   161,   162,     0,     0,     0,     0,   163,     0,
      40,     0,    41,     0,    38,    37,     0,    60,    59,     0,
      94,    74,   108,     0,   146,    76,     0,    73,     0,    44,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,    79,     0,     0,     0,     3,     0,     5,
      33,     0,     0,     0,     0,     0,    39,     0,    72,     0,
       0,     0,   104,   113,   106,    99,     0,     0,     0,    85,
       0,    46,    51,     0,    52,    56,   100,    69,    70,    71,
      80,    83,    77,    78,    81,    82,    63,    64,    65,    66,
      67,    68,    96,    97,    98,    95,   152,   148,     0,     0,
      20,    34,   154,   169,     0,     0,   154,    93,    87,    88,
      86,    89,     0,     0,   109,    91,   110,   111,   112,   107,
     137,   138,   136,     0,     0,   114,     0,     0,     0,   108,
       0,     0,     0,    45,     0,   151,     0,    54,   145,    11,
       8,     0,    35,    32,    34,   168,     0,     0,     0,    34,
       0,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   117,   125,   119,   118,   105,     0,
     102,   103,   147,    62,     0,    58,     0,    55,     0,   150,
       0,     0,     0,   153,     0,   169,     0,   166,   171,   135,
     143,   128,   129,   130,   131,   132,   133,   139,     0,   140,
     141,   142,   127,   124,     0,   123,     0,   116,     0,     0,
       0,    53,    15,    15,     0,     0,     0,   155,     0,   164,
       0,     0,   120,     0,   121,   101,    61,    57,     0,    12,
      14,    17,     9,     0,   154,     0,     0,   154,   158,   154,
     126,   122,    19,     0,     0,     0,     0,    34,    22,     0,
      34,     0,   154,     0,    18,   154,    16,   154,     0,    21,
       0,     0,     0,    34,    33,   170,    34,    34,     0,   154,
     156,     0,     0,    34,    13,    10,     0,    34,   154,   157,
      36,    23,     0,    34,   159,     0,   160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,  -213,  -213,     0,     3,    33,  -213,    14,  -213,
    -213,  -213,  -213,   -10,  -213,    -1,    -6,  -213,  -213,   261,
    -213,  -213,     4,   -90,  -174,   132,  -212,  -213,    48,  -213,
     139,  -213,  -213,  -213,    75,  -135,   162,  -213,  -140,  -213,
     -13,   319,  -213,  -213,    16,  -158,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    97,    99,   122,    51,   279,   280,   281,   265,
     185,   123,   186,    28,    29,    68,    31,    93,    32,    63,
     253,   254,   202,   203,   112,   113,   217,   256,   218,   169,
     114,    33,    53,    34,   196,   125,    64,    35,   194,    59,
      60,   193,    37,    38,   151,    39,   315,   288,    40,    41,
     102,    42,    43,    44,    45,   231,   295,   230,   293,   191,
      46,    94,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    26,    57,   255,    27,   220,    58,    61,    52,    50,
      66,   187,  -165,    57,   233,   110,   199,    58,   115,   148,
     168,    65,   126,    67,   170,   171,   172,   149,    88,   247,
     183,   184,    89,    90,    91,    92,   234,   314,    96,  -167,
     116,   238,   111,    17,   116,    47,   101,    62,   105,   227,
     248,   210,   211,   118,    48,   107,    57,  -149,    54,   240,
      58,   291,    56,   273,   173,   274,    70,   210,   211,   124,
     174,   127,   128,   129,   130,   131,   175,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   223,   142,   143,
     144,   145,    49,   261,    55,    72,   157,   224,    17,    57,
     165,   286,   287,    58,    62,   181,   301,   302,    57,   166,
     164,    75,    58,    69,   167,   176,   180,    95,   304,   182,
     250,   251,    98,   100,   170,   171,   172,    70,   106,    80,
      81,    82,    83,    84,    85,    86,   108,    87,   109,   309,
     117,   146,   311,   147,   297,   124,   150,   300,    87,   303,
      30,    26,   195,   165,    27,   322,    72,   154,   324,   325,
     155,    67,   313,   153,   173,   316,   201,   317,   177,   332,
     174,   178,    75,    76,   179,   335,   216,   201,   189,   327,
     198,   190,   219,   124,   197,   212,    78,    79,   333,   228,
      80,    81,    82,    83,    84,    85,    86,   237,    87,   229,
     249,   249,   233,   235,   232,     3,     4,     5,   241,   242,
     243,   244,   245,   246,   252,   236,   176,   258,    12,    84,
      85,    86,    13,    87,   206,   207,   208,   124,   209,   259,
      15,   266,    17,   260,   195,   269,   262,    22,   165,    72,
     263,   267,    23,   209,   271,    24,   283,   107,   276,   272,
     277,    25,   278,   284,   215,    72,   289,   216,   292,   294,
     165,   215,   299,   312,   111,    73,    74,   305,   307,   318,
     290,    75,    76,   320,   326,    82,    83,    84,    85,    86,
     329,    87,   296,   334,   298,    78,    79,   336,    71,    80,
      81,    82,    83,    84,    85,    86,   282,    87,   310,   204,
     205,   206,   207,   208,   222,   209,   275,   213,   306,   188,
     268,   321,   214,   204,   205,   206,   207,   208,   221,   209,
      36,   239,    30,    26,     2,   331,    27,     3,     4,     5,
     323,     6,     0,     0,     7,     8,     9,     0,    10,    11,
      12,     0,     0,    -4,    13,    14,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,    23,     0,     0,    24,     0,     0,
       3,     4,     5,    25,     6,     0,   -34,     7,     8,     9,
       0,    10,    11,    12,     0,     0,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,     0,    23,     0,     0,
      24,     0,     0,     0,     0,     0,    25,     3,     4,     5,
     192,     6,     0,     0,     7,     8,     9,     0,    10,    11,
      12,     0,     0,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     3,     4,     5,    23,     0,     0,    24,     0,     0,
       0,     0,     0,    25,    12,     0,     0,   330,    13,     0,
       0,   204,   205,   206,   207,   208,    15,   209,    17,    18,
      19,    20,    21,    22,   257,     0,     0,     0,    23,     0,
       0,    24,     3,     4,     5,     0,     0,    25,   121,     0,
     204,   205,   206,   207,   208,    12,   209,     0,     0,    13,
       0,     0,     0,     0,   158,   159,   160,    15,     0,    17,
      18,    19,    20,    21,    22,     0,     0,    12,     0,    23,
       0,    13,    24,     0,     0,     0,     0,     0,    25,   161,
       0,    17,    18,    19,    20,    21,    22,     0,     3,     4,
       5,    23,     0,     0,   162,     0,     0,     0,     0,     0,
     163,    12,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     0,    15,     0,    17,     3,     4,     5,     0,
      22,     0,     0,   264,     0,    23,     0,     0,    24,    12,
       0,     0,     0,    13,    25,     0,     0,     0,   158,   159,
     160,    15,     0,    17,     0,     0,     0,     0,    22,     0,
       0,    12,     0,    23,     0,    13,    24,     0,     0,     0,
       0,     0,    25,    15,     0,    17,   158,   159,   160,     0,
      22,     0,     0,     0,     0,    23,     0,     0,   162,    12,
       0,     0,     0,    13,   200,     0,     0,     0,     3,     4,
       5,   161,     0,    17,     0,     0,     0,     0,    22,     0,
       0,    12,     0,    23,     0,    13,   162,    72,     0,     0,
       0,     0,   163,   161,     0,    17,     0,    73,    74,     0,
      22,     0,     0,    75,    76,    23,     0,     0,    24,     0,
       0,     0,     0,     0,   270,     0,     0,    78,    79,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    72,    87,
       0,   119,   120,     0,     0,     0,     0,     0,    73,    74,
       0,     0,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    72,
      87,     0,   225,   226,     0,     0,     0,     0,     0,    73,
      74,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     0,    72,    80,    81,    82,    83,    84,    85,    86,
       0,    87,    73,    74,   120,     0,     0,     0,    75,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,     0,    72,    80,    81,    82,    83,
      84,    85,    86,     0,    87,    73,    74,   285,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,     0,    72,    80,
      81,    82,    83,    84,    85,    86,     0,    87,    73,    74,
     308,     0,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    72,
      87,     0,   152,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,     0,     0,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      72,    87,     0,   156,     0,     0,     0,     0,     0,     0,
      73,    74,     0,     0,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    72,    87,     0,   319,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    72,    87,     0,   328,     0,     0,     0,     0,
       0,     0,    73,    74,     0,     0,     0,     0,    75,    76,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,    78,    79,     0,    72,    80,    81,    82,    83,
      84,    85,    86,     0,    87,    73,    74,     0,     0,     0,
       0,    75,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,     0,    72,    80,
      81,    82,    83,    84,    85,    86,     0,    87,    73,    72,
       0,     0,     0,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,     0,    78,    79,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    78,
      87,    72,     0,    80,    81,    82,    83,    84,    85,    86,
       0,    87,     0,     0,     0,     0,     0,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,     0,    87
};

static const yytype_int16 yycheck[] =
{
       1,     1,    12,   215,     1,   179,    12,    13,     9,     9,
      23,   146,    30,    23,    29,    27,   156,    23,    29,    13,
     110,    22,    29,    24,     3,     4,     5,    21,    20,    28,
      50,    51,    24,    25,    26,    27,   194,    52,    18,    57,
      51,   199,    54,    30,    51,    49,    47,    30,    49,   184,
      49,    42,    43,    66,    49,    56,    66,    49,    29,    50,
      66,   273,    49,    51,    43,    53,    49,    42,    43,    70,
      49,    72,    73,    74,    75,    76,    55,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    41,    89,    90,
      91,    92,    49,   228,    29,     6,   109,    51,    30,   109,
     110,     8,     9,   109,    30,   118,     8,     9,   118,   110,
     110,    22,   118,    29,   110,   111,   117,    56,   292,   120,
     210,   211,    19,    52,     3,     4,     5,    49,    29,    40,
      41,    42,    43,    44,    45,    46,    16,    48,    43,   297,
      54,    49,   300,    30,   284,   146,    30,   287,    48,   289,
     151,   151,   153,   163,   151,   313,     6,    21,   316,   317,
      30,   162,   302,    57,    43,   305,   162,   307,    27,   327,
      49,    54,    22,    23,    30,   333,   177,   173,    30,   319,
      27,    30,   178,   184,    30,    54,    36,    37,   328,    51,
      40,    41,    42,    43,    44,    45,    46,   198,    48,    50,
     210,   211,    29,    57,    49,     3,     4,     5,   204,   205,
     206,   207,   208,   209,   215,    27,   212,    27,    16,    44,
      45,    46,    20,    48,    44,    45,    46,   228,    48,     4,
      28,   232,    30,    28,   235,   236,    49,    35,   248,     6,
      49,    29,    40,    48,    51,    43,    27,   248,    41,    53,
      50,    49,    21,    50,    52,     6,    50,   258,    30,    51,
     270,    52,    49,    49,    54,    16,    17,    50,    50,    39,
     271,    22,    23,    29,    27,    42,    43,    44,    45,    46,
      29,    48,   283,    29,   285,    36,    37,    29,    27,    40,
      41,    42,    43,    44,    45,    46,   263,    48,   299,    42,
      43,    44,    45,    46,    55,    48,   258,   175,   294,   147,
     235,   312,    55,    42,    43,    44,    45,    46,   179,    48,
       1,    50,   323,   323,     0,   326,   323,     3,     4,     5,
     314,     7,    -1,    -1,    10,    11,    12,    -1,    14,    15,
      16,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    -1,    -1,
       3,     4,     5,    49,     7,    -1,    52,    10,    11,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,     3,     4,     5,
      53,     7,    -1,    -1,    10,    11,    12,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,     3,     4,     5,    40,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    49,    16,    -1,    -1,    53,    20,    -1,
      -1,    42,    43,    44,    45,    46,    28,    48,    30,    31,
      32,    33,    34,    35,    55,    -1,    -1,    -1,    40,    -1,
      -1,    43,     3,     4,     5,    -1,    -1,    49,    50,    -1,
      42,    43,    44,    45,    46,    16,    48,    -1,    -1,    20,
      -1,    -1,    -1,    -1,     3,     4,     5,    28,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    16,    -1,    40,
      -1,    20,    43,    -1,    -1,    -1,    -1,    -1,    49,    28,
      -1,    30,    31,    32,    33,    34,    35,    -1,     3,     4,
       5,    40,    -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    -1,
      35,    -1,    -1,    38,    -1,    40,    -1,    -1,    43,    16,
      -1,    -1,    -1,    20,    49,    -1,    -1,    -1,     3,     4,
       5,    28,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    16,    -1,    40,    -1,    20,    43,    -1,    -1,    -1,
      -1,    -1,    49,    28,    -1,    30,     3,     4,     5,    -1,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    16,
      -1,    -1,    -1,    20,    49,    -1,    -1,    -1,     3,     4,
       5,    28,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    16,    -1,    40,    -1,    20,    43,     6,    -1,    -1,
      -1,    -1,    49,    28,    -1,    30,    -1,    16,    17,    -1,
      35,    -1,    -1,    22,    23,    40,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,     6,    48,
      -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,     6,
      48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,     6,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    16,    17,    51,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,     6,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    16,    17,    51,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,     6,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    16,    17,
      51,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,     6,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
       6,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     6,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,     6,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,     6,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,     6,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    16,     6,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    36,
      48,     6,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     3,     4,     5,     7,    10,    11,    12,
      14,    15,    16,    20,    21,    28,    29,    30,    31,    32,
      33,    34,    35,    40,    43,    49,    62,    63,    71,    72,
      73,    74,    76,    89,    91,    95,    99,   100,   101,   103,
     106,   107,   109,   110,   111,   112,   118,    49,    49,    49,
      62,    63,    73,    90,    29,    29,    49,    71,    74,    97,
      98,    74,    30,    77,    94,    73,    98,    73,    73,    29,
      49,    77,     6,    16,    17,    22,    23,    29,    36,    37,
      40,    41,    42,    43,    44,    45,    46,    48,    20,    24,
      25,    26,    27,    75,   119,    56,    18,    60,    19,    61,
      52,    73,   108,   120,   121,    73,    29,    73,    16,    43,
      27,    54,    82,    83,    88,    29,    51,    54,    98,    50,
      51,    50,    62,    69,    73,    93,    29,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    49,    30,    13,    21,
      30,   102,    50,    57,    21,    30,    50,    98,     3,     4,
       5,    28,    43,    49,    62,    71,    73,    80,    81,    87,
       3,     4,     5,    43,    49,    55,    80,    27,    54,    30,
      73,    98,    73,    50,    51,    68,    70,    93,    94,    30,
      30,   117,    53,    99,    96,    73,    92,    30,    27,    96,
      49,    80,    80,    81,    42,    43,    44,    45,    46,    48,
      42,    43,    54,    83,    55,    52,    73,    84,    86,    80,
      82,    88,    55,    41,    51,    50,    51,    93,    51,    50,
     115,   113,    49,    29,   103,    57,    27,    73,   103,    50,
      50,    80,    80,    80,    80,    80,    80,    28,    49,    71,
      81,    81,    73,    78,    79,    84,    85,    55,    27,     4,
      28,    93,    49,    49,    38,    67,    73,    29,    92,    73,
      49,    51,    53,    51,    53,    86,    41,    50,    21,    64,
      65,    66,    64,    27,    50,    51,     8,     9,   105,    50,
      73,    84,    30,   116,    51,   114,    73,    96,    73,    49,
      96,     8,     9,    96,    82,    50,    66,    50,    51,   103,
      73,   103,    49,    96,    52,   104,    96,    96,    39,    50,
      29,    73,   103,   102,   103,   103,    27,    96,    50,    29,
      53,    73,   103,    96,    29,   103,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,   111,    59,   112,    59,    59,    59,   113,   114,
      60,   115,   116,    60,    64,    64,    65,    65,    66,    66,
     117,    61,    67,    67,    99,    99,    99,    99,    99,    99,
      99,    99,   102,   102,   118,   103,   104,   106,   106,    91,
      90,    90,    90,   100,   100,    62,    62,    63,    63,    63,
      63,    93,    93,    68,    68,    69,    69,    71,    71,    98,
      98,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    97,    97,    75,    75,    75,    75,    89,
      89,    77,    77,    77,    77,    77,    77,    88,    88,    87,
      87,    87,    87,    82,    82,    82,    83,    83,    86,    86,
      84,    84,    85,    85,    79,    79,    78,    78,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    81,    81,    74,    95,    95,    94,    94,   119,
      76,    70,    70,    96,    96,   101,   101,   101,   101,   105,
     105,   107,   107,   120,   108,   121,   108,   108,    92,    92,
     109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     3,     2,     0,     0,     0,
      10,     0,     0,    10,     1,     0,     3,     1,     3,     2,
       0,     8,     3,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     0,     4,     3,     2,     2,     3,
       1,     1,     0,     2,     2,     4,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     7,     5,     1,
       1,     7,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     3,     3,     2,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     2,     2,     2,     3,
       3,     6,     4,     4,     2,     4,     2,     2,     0,     1,
       1,     1,     1,     1,     2,     3,     4,     3,     1,     1,
       3,     3,     3,     1,     1,     0,     3,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     4,     2,     4,     0,     0,
       5,     1,     0,     2,     0,     7,    11,    12,     8,     7,
       8,     1,     1,     0,     5,     0,     4,     0,     1,     0,
      10,     6
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
#line 195 "parser.y"
                  { global_space = 0 ;}
#line 1851 "parser.tab.c"
    break;

  case 3:
#line 195 "parser.y"
                                             { *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[0].main).text;
                         fig_func.push_back(*(yyvsp[0].main).text);
                         global_space = 1;
                     }
#line 1860 "parser.tab.c"
    break;

  case 4:
#line 199 "parser.y"
                   { global_space = 0 ;}
#line 1866 "parser.tab.c"
    break;

  case 5:
#line 199 "parser.y"
                                             {*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[0].main).text;
                       fig_func.push_back(*(yyvsp[0].main).text);
                       global_space = 1;
                     }
#line 1875 "parser.tab.c"
    break;

  case 6:
#line 203 "parser.y"
                       {
              if ((yyvsp[0].main).stopAdvanceFound) 
                     semanticError("stop/advance cannot be outside the loop");
              if(is_decl_stmt) {
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
                     is_decl_stmt = 0;
              }
              else {
                     collection.push_back(*(yyvsp[0].main).text);
              }
              
              }
#line 1892 "parser.tab.c"
    break;

  case 7:
#line 215 "parser.y"
                     {
              if(ret_flag) {
                     cerr << "Error: Return statement not allowed outside function" << endl;
              }
              *(yyval.main).text = "";
         }
#line 1903 "parser.tab.c"
    break;

  case 8:
#line 225 "parser.y"
                         { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype); addSymTabPtr(); }
#line 1909 "parser.tab.c"
    break;

  case 9:
#line 225 "parser.y"
                                                                                                 {
                     if(paramslist.size()>0) {
                            addParamList((yyvsp[-3].main).name,paramslist);
                            insertParams(paramslist);
                            paramslist.clear();
                     }
              }
#line 1921 "parser.tab.c"
    break;

  case 10:
#line 232 "parser.y"
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

                     *(yyval.main).text = datatypeTranslation(*(yyvsp[-8].main).text) + *(yyvsp[-7].main).text + "(" + *((yyvsp[-4].main).text) + ")" +  *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
              }
#line 1948 "parser.tab.c"
    break;

  case 11:
#line 254 "parser.y"
                              { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype);  addSymTabPtr(); }
#line 1954 "parser.tab.c"
    break;

  case 12:
#line 254 "parser.y"
                                                                                                       {if(paramslist.size()>0) {
                     addParamList((yyvsp[-3].main).name,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
#line 1964 "parser.tab.c"
    break;

  case 13:
#line 259 "parser.y"
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

                     *(yyval.main).text = *(yyvsp[-8].main).text + *(yyvsp[-7].main).text + "(" + *((yyvsp[-4].main).text) + ")" + *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
              }
#line 1988 "parser.tab.c"
    break;

  case 14:
#line 280 "parser.y"
                 {*(yyval.main).text = *(yyvsp[0].main).text;}
#line 1994 "parser.tab.c"
    break;

  case 15:
#line 281 "parser.y"
                       {*(yyval.main).text = "";}
#line 2000 "parser.tab.c"
    break;

  case 16:
#line 284 "parser.y"
                          {*(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text;}
#line 2006 "parser.tab.c"
    break;

  case 17:
#line 285 "parser.y"
                  {*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2012 "parser.tab.c"
    break;

  case 18:
#line 288 "parser.y"
                                 {
              ParamList param;
              param.Eletype = (yyvsp[-2].main).eletype;
              param.name = (yyvsp[-1].main).name;
              param.dim = *(yyvsp[0].main).dimList;
              param.Type = Array;
              paramslist.push_back(param);
              delete (yyvsp[-1].main).name;

              *(yyval.main).text = datatypeTranslation(*(yyvsp[-2].main).text) + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2028 "parser.tab.c"
    break;

  case 19:
#line 299 "parser.y"
                     {
              ParamList param;
              param.Eletype = (yyvsp[-1].main).eletype;
              param.name = (yyvsp[0].main).name;
              vector<int> dim;
              param.dim = dim;
              param.Type = Var;
              paramslist.push_back(param);
              delete (yyvsp[0].main).name;

              *(yyval.main).text = datatypeTranslation(*(yyvsp[-1].main).text) + *(yyvsp[0].main).text;

       }
#line 2046 "parser.tab.c"
    break;

  case 20:
#line 317 "parser.y"
            {insertType((yyvsp[0].main).name, Fig, UNDEF); addSymTabPtr();}
#line 2052 "parser.tab.c"
    break;

  case 21:
#line 317 "parser.y"
                                                                                                       { 
                                                        if (ret_fig_flag == 1)  
                                                               semanticError("Error: Return statement is not allowed in figures."); 
                                                        ret_fig_flag = 0;
                                                        

                                                        if ((yyvsp[0].main).stopAdvanceFound)
                                                               semanticError("stop/advance cannot be outside the loop");

                                                        delSymTabPtr();
                                                        delete (yyvsp[-6].main).name;

                                                        *(yyval.main).text = "void" + *(yyvsp[-6].main).text + "(" + *(yyvsp[-3].main).text + ")" + *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
                                                 }
#line 2071 "parser.tab.c"
    break;

  case 22:
#line 332 "parser.y"
                                   { 
              if(!(arithCompatible((yyvsp[-2].main).eletype) && (yyvsp[0].main).eletype == POINT)) 
                     semanticError("Error: Semantic error incompatible datatype..") ;
              scale = *(yyvsp[-2].main).text;
              center = centerTranslation(*(yyvsp[0].main).text);
              *(yyval.main).text = "double scale , Point center"; 
       }
#line 2083 "parser.tab.c"
    break;

  case 23:
#line 339 "parser.y"
                                                            { 
              if(!(arithCompatible((yyvsp[-4].main).eletype) && (yyvsp[0].main).eletype == POINT)) 
                     semanticError("Error: Semantic error incompatible datatype") ;
              scale = *(yyvsp[-4].main).text;
              center = centerTranslation(*(yyvsp[-4].main).text);
              *(yyval.main).text = "double scale , Point center" ; 
       }
#line 2095 "parser.tab.c"
    break;

  case 24:
#line 348 "parser.y"
                 {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2101 "parser.tab.c"
    break;

  case 25:
#line 349 "parser.y"
                {(yyval.main).stopAdvanceFound = false; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2107 "parser.tab.c"
    break;

  case 26:
#line 350 "parser.y"
                 {(yyval.main).stopAdvanceFound = false; *(yyval.main).text = *(yyvsp[0].main).text; is_decl_stmt = 1;}
#line 2113 "parser.tab.c"
    break;

  case 27:
#line 351 "parser.y"
                   {(yyval.main).stopAdvanceFound = false; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2119 "parser.tab.c"
    break;

  case 28:
#line 352 "parser.y"
                   {(yyval.main).stopAdvanceFound = false; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2125 "parser.tab.c"
    break;

  case 29:
#line 353 "parser.y"
                  {(yyval.main).stopAdvanceFound = false;  *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2131 "parser.tab.c"
    break;

  case 30:
#line 354 "parser.y"
                  {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2137 "parser.tab.c"
    break;

  case 31:
#line 355 "parser.y"
                  {(yyval.main).stopAdvanceFound = true; *(yyval.main).text= *(yyvsp[0].main).text ;}
#line 2143 "parser.tab.c"
    break;

  case 32:
#line 359 "parser.y"
       {
              (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound || (yyvsp[0].main).stopAdvanceFound;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2152 "parser.tab.c"
    break;

  case 33:
#line 363 "parser.y"
                      {(yyval.main).stopAdvanceFound = false; *(yyval.main).text = "";}
#line 2158 "parser.tab.c"
    break;

  case 34:
#line 366 "parser.y"
            { addSymTabPtr(); }
#line 2164 "parser.tab.c"
    break;

  case 35:
#line 367 "parser.y"
              { 
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     delSymTabPtr(); 
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}" ;
              }
#line 2174 "parser.tab.c"
    break;

  case 36:
#line 375 "parser.y"
              { 
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound; 
                     delSymTabPtr(); 
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}" ;
              }
#line 2184 "parser.tab.c"
    break;

  case 37:
#line 382 "parser.y"
                            {*(yyval.main).text = "break;";}
#line 2190 "parser.tab.c"
    break;

  case 38:
#line 383 "parser.y"
                              { *(yyval.main).text = "continue;";}
#line 2196 "parser.tab.c"
    break;

  case 39:
#line 387 "parser.y"
                                     {ret_type = (yyvsp[-1].main).eletype; ret_flag = 1; ret_fig_flag = 1; *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";"; }
#line 2202 "parser.tab.c"
    break;

  case 40:
#line 389 "parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text; }
#line 2208 "parser.tab.c"
    break;

  case 41:
#line 390 "parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2214 "parser.tab.c"
    break;

  case 42:
#line 391 "parser.y"
         {(yyval.main).eletype = Void; *(yyval.main).text = "void" ; *(yyval.main).text = "";}
#line 2220 "parser.tab.c"
    break;

  case 43:
#line 394 "parser.y"
                                 {lineArrNo = 0; *(yyval.main).text = *(yyvsp[-1].main).text + ";";}
#line 2226 "parser.tab.c"
    break;

  case 44:
#line 395 "parser.y"
                                 {lineArrNo = 0; *(yyval.main).text = *(yyvsp[-1].main).text + ";";}
#line 2232 "parser.tab.c"
    break;

  case 45:
#line 424 "parser.y"
                                                      {(yyval.main).eletype = (yyvsp[-3].main).eletype; construct_params.clear(); *(yyval.main).text = *(yyvsp[-3].main).text + "(" + *(yyvsp[-1].main).text + "," + scale + "," + center + ")" ;}
#line 2238 "parser.tab.c"
    break;

  case 46:
#line 425 "parser.y"
                                {(yyval.main).eletype = (yyvsp[-2].main).eletype; *(yyval.main).text = *(yyvsp[-2].main).text + "(" + scale + "," + center + ")" ;}
#line 2244 "parser.tab.c"
    break;

  case 47:
#line 428 "parser.y"
                           { (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2250 "parser.tab.c"
    break;

  case 48:
#line 429 "parser.y"
                              { (yyval.main).eletype = (yyvsp[0].main).eletype;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2256 "parser.tab.c"
    break;

  case 49:
#line 430 "parser.y"
                            { (yyval.main).eletype = (yyvsp[0].main).eletype;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2262 "parser.tab.c"
    break;

  case 50:
#line 431 "parser.y"
                               { (yyval.main).eletype = (yyvsp[0].main).eletype;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2268 "parser.tab.c"
    break;

  case 51:
#line 434 "parser.y"
                     {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2274 "parser.tab.c"
    break;

  case 52:
#line 435 "parser.y"
                      {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2280 "parser.tab.c"
    break;

  case 53:
#line 438 "parser.y"
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
#line 2296 "parser.tab.c"
    break;

  case 54:
#line 449 "parser.y"
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
#line 2312 "parser.tab.c"
    break;

  case 55:
#line 462 "parser.y"
                                                         {
              if(is_member) {
                  construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }

              *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text;
          }
#line 2329 "parser.tab.c"
    break;

  case 56:
#line 474 "parser.y"
                      {
              if(is_member) {
                     construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                    is_member = 0;
                    
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }

              *(yyval.main).text = *(yyvsp[0].main).text;
          }
#line 2347 "parser.tab.c"
    break;

  case 57:
#line 490 "parser.y"
                                                            { (yyval.main).eletype = pointCheck((yyvsp[-5].main).eletype, (yyvsp[-3].main).eletype);  *(yyval.main).text = "Point(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")"; }
#line 2353 "parser.tab.c"
    break;

  case 58:
#line 491 "parser.y"
                                               { (yyval.main).eletype = pointCheck((yyvsp[-3].main).eletype, (yyvsp[-1].main).eletype);*(yyval.main).text = "Point(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text +  ")";}
#line 2359 "parser.tab.c"
    break;

  case 59:
#line 495 "parser.y"
                      { if ((yyvsp[0].main).eletype != POINT) semanticError("Error: vertex has to be a point"); *(yyval.main).text = *(yyvsp[0].main).text; }
#line 2365 "parser.tab.c"
    break;

  case 60:
#line 497 "parser.y"
                      { *(yyval.main).text = *(yyvsp[0].main).text; }
#line 2371 "parser.tab.c"
    break;

  case 61:
#line 500 "parser.y"
                                                  {(yyval.main).eletype = ANGLE; *(yyval.main).text = "angleBetweenPoints(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-4].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")";}
#line 2377 "parser.tab.c"
    break;

  case 62:
#line 501 "parser.y"
                                      {(yyval.main).eletype = ANGLE; *(yyval.main).text = "angleBetweenPoints(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-2].main).text + "," + *(yyvsp[-1].main).text + ")";}
#line 2383 "parser.tab.c"
    break;

  case 63:
#line 504 "parser.y"
                                        {  (yyval.main).eletype = sumTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text;}
#line 2389 "parser.tab.c"
    break;

  case 64:
#line 505 "parser.y"
                                        {  (yyval.main).eletype = diffTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text;}
#line 2395 "parser.tab.c"
    break;

  case 65:
#line 506 "parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "*" + *(yyvsp[0].main).text;}
#line 2401 "parser.tab.c"
    break;

  case 66:
#line 507 "parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "/" + *(yyvsp[0].main).text;}
#line 2407 "parser.tab.c"
    break;

  case 67:
#line 508 "parser.y"
                                        { if ((yyvsp[-2].main).eletype != INT || (yyvsp[0].main).eletype != INT) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = INT; *(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text;}
#line 2413 "parser.tab.c"
    break;

  case 68:
#line 509 "parser.y"
                                        { (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);*(yyval.main).text = "pow(" + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + ")";}
#line 2419 "parser.tab.c"
    break;

  case 69:
#line 510 "parser.y"
                                            {  if(((yyvsp[-2].main).eletype == POINT || (yyvsp[-2].main).eletype == LINEARR) && (yyvsp[0].main).eletype == POINT) {(yyval.main).eletype = LINEARR; lineArrNo++;} else  semanticError("Error: Semantic error incompatible datatype");*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;}
#line 2425 "parser.tab.c"
    break;

  case 70:
#line 511 "parser.y"
                                             { (yyval.main).eletype = parallelCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ; }
#line 2431 "parser.tab.c"
    break;

  case 71:
#line 512 "parser.y"
                                                   {(yyval.main).eletype = perpendicularCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);  *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;}
#line 2437 "parser.tab.c"
    break;

  case 72:
#line 513 "parser.y"
                                             { (yyval.main).eletype = REAL; *(yyval.main).text = *(yyvsp[-1].main).text;}
#line 2443 "parser.tab.c"
    break;

  case 73:
#line 514 "parser.y"
                                       {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = "-" + *(yyvsp[0].main).text;}
#line 2449 "parser.tab.c"
    break;

  case 74:
#line 515 "parser.y"
                                  {if(!((yyvsp[0].main).eletype == INT || (yyvsp[0].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2455 "parser.tab.c"
    break;

  case 75:
#line 516 "parser.y"
                                  {if(!((yyvsp[-1].main).eletype == INT || (yyvsp[-1].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2461 "parser.tab.c"
    break;

  case 76:
#line 517 "parser.y"
                             {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;*(yyval.main).text = "!" + *(yyvsp[-1].main).text;}
#line 2467 "parser.tab.c"
    break;

  case 77:
#line 518 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + "&&" + *(yyvsp[0].main).text; }
#line 2473 "parser.tab.c"
    break;

  case 78:
#line 519 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + "||" + *(yyvsp[0].main).text; }
#line 2479 "parser.tab.c"
    break;

  case 79:
#line 520 "parser.y"
                                         {if (!(((yyvsp[-1].main).eletype == (yyvsp[0].main).eletype) || coercible((yyvsp[-1].main).eletype, (yyvsp[0].main).eletype) || ((yyvsp[-1].main).eletype == LINE && (yyvsp[0].main).eletype == LINEARR && lineArrNo == 1))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  *(yyval.main).text = assignTranslation(*(yyvsp[0].main).text,*(yyvsp[-1].main).text);}
#line 2485 "parser.tab.c"
    break;

  case 80:
#line 521 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2491 "parser.tab.c"
    break;

  case 81:
#line 522 "parser.y"
                                        { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + "<" + *(yyvsp[0].main).text; }
#line 2497 "parser.tab.c"
    break;

  case 82:
#line 523 "parser.y"
                                         { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + ">" + *(yyvsp[0].main).text; }
#line 2503 "parser.tab.c"
    break;

  case 83:
#line 524 "parser.y"
                                              {if(!((arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) || ((yyvsp[-2].main).eletype == (yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2509 "parser.tab.c"
    break;

  case 84:
#line 525 "parser.y"
                            {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2515 "parser.tab.c"
    break;

  case 85:
#line 526 "parser.y"
                                 {(yyval.main).eletype = (yyvsp[-1].main).eletype; *(yyval.main).text = "(" + *(yyvsp[-1].main).text + ")";}
#line 2521 "parser.tab.c"
    break;

  case 86:
#line 527 "parser.y"
                     { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2527 "parser.tab.c"
    break;

  case 87:
#line 528 "parser.y"
                       { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2533 "parser.tab.c"
    break;

  case 88:
#line 529 "parser.y"
                      { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2539 "parser.tab.c"
    break;

  case 89:
#line 530 "parser.y"
                           { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2545 "parser.tab.c"
    break;

  case 90:
#line 531 "parser.y"
                        {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2551 "parser.tab.c"
    break;

  case 91:
#line 532 "parser.y"
                    { (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2557 "parser.tab.c"
    break;

  case 92:
#line 533 "parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2563 "parser.tab.c"
    break;

  case 93:
#line 537 "parser.y"
                                { *(yyval.main).text = "norm( " + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + " )";}
#line 2569 "parser.tab.c"
    break;

  case 94:
#line 538 "parser.y"
                        { *(yyval.main).text = "norm( " + *(yyvsp[0].main).text + " )";}
#line 2575 "parser.tab.c"
    break;

  case 95:
#line 542 "parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = "=" + *(yyvsp[0].main).text;}
#line 2581 "parser.tab.c"
    break;

  case 96:
#line 543 "parser.y"
                                {if(!(arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  *(yyval.main).text = assignOpTranslation(*(yyvsp[-1].main).text) + *(yyvsp[0].main).text;}
#line 2587 "parser.tab.c"
    break;

  case 97:
#line 544 "parser.y"
                                    {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == LABEL || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  *(yyval.main).text = "+=" + *(yyvsp[0].main).text;}
#line 2593 "parser.tab.c"
    break;

  case 98:
#line 545 "parser.y"
                                  {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  *(yyval.main).text = "-=" + *(yyvsp[0].main).text;}
#line 2599 "parser.tab.c"
    break;

  case 99:
#line 549 "parser.y"
                                     {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);lineArrNo = 0; *(yyval.main).text = datatypeTranslation(*(yyvsp[-2].main).text) + *(yyvsp[-1].main).text + ";"; }
#line 2605 "parser.tab.c"
    break;

  case 100:
#line 550 "parser.y"
                                        {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);lineArrNo = 0; *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";";}
#line 2611 "parser.tab.c"
    break;

  case 101:
#line 554 "parser.y"
       {
              (yyval.main).nameList = (yyvsp[-5].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);
              compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);
              *(yyval.main).text = *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text  + *(yyvsp[0].main).text;
       }
#line 2622 "parser.tab.c"
    break;

  case 102:
#line 561 "parser.y"
       {
              (yyval.main).nameList = (yyvsp[-3].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);
              *(yyval.main).text = *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2633 "parser.tab.c"
    break;

  case 103:
#line 568 "parser.y"
       {
              (yyval.main).nameList = (yyvsp[-3].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);
              *(yyval.main).text = *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2644 "parser.tab.c"
    break;

  case 104:
#line 575 "parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2655 "parser.tab.c"
    break;

  case 105:
#line 582 "parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);
              compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);
              *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2666 "parser.tab.c"
    break;

  case 106:
#line 589 "parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2677 "parser.tab.c"
    break;

  case 107:
#line 597 "parser.y"
                              {(yyval.main).eletype = (yyvsp[0].main).eletype ; *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text; }
#line 2683 "parser.tab.c"
    break;

  case 108:
#line 598 "parser.y"
                      {(yyval.main).eletype = UNDEF; *(yyval.main).text = "";}
#line 2689 "parser.tab.c"
    break;

  case 109:
#line 601 "parser.y"
                       {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2695 "parser.tab.c"
    break;

  case 110:
#line 602 "parser.y"
                       { if(global_space)  semanticError("Error: Global variables are declared incorrectly"); (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text; }
#line 2701 "parser.tab.c"
    break;

  case 113:
#line 608 "parser.y"
               {(yyval.main).dimList = (yyvsp[0].main).dimList; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2707 "parser.tab.c"
    break;

  case 114:
#line 609 "parser.y"
                   {(yyval.main).dimList = new vector<int>;(yyval.main).dimList->push_back(-1); *(yyval.main).text = "[]";}
#line 2713 "parser.tab.c"
    break;

  case 115:
#line 610 "parser.y"
                       {(yyval.main).dimList = new vector<int>;addFrontAndCopy((yyval.main).dimList, (yyvsp[0].main).dimList, -1);delete (yyvsp[0].main).dimList; *(yyval.main).text = "[]" + *(yyvsp[0].main).text; }
#line 2719 "parser.tab.c"
    break;

  case 116:
#line 613 "parser.y"
                             {(yyval.main).dimList = (yyvsp[-3].main).dimList;
                              
                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);

                            *(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";
                            
                            }
#line 2734 "parser.tab.c"
    break;

  case 117:
#line 623 "parser.y"
                         {(yyval.main).dimList = new vector<int>; 

                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);

                            
                            *(yyval.main).text =  "[" + *(yyvsp[-1].main).text + "]";
                         }
#line 2749 "parser.tab.c"
    break;

  case 118:
#line 637 "parser.y"
                             {
                            (yyval.main).listAndType.dimList = (yyvsp[0].main).listAndType.dimList;
                            (yyval.main).listAndType.eletype = (yyvsp[0].main).listAndType.eletype;
                            *(yyval.main).text = *(yyvsp[0].main).text;
                     }
#line 2759 "parser.tab.c"
    break;

  case 119:
#line 642 "parser.y"
                             {
                            if ((yyvsp[0].main).eletype != LINEARR) 
                                   semanticError("Error: Invalid Datatypes\n");
                            (yyval.main).listAndType.dimList = new vector<int>;
                            (yyval.main).listAndType.dimList->push_back(lineArrNo);
                            lineArrNo = 0;
                            *(yyval.main).text = *(yyvsp[0].main).text;
                     }
#line 2772 "parser.tab.c"
    break;

  case 120:
#line 653 "parser.y"
              {
                     (yyval.main).listAndType.dimList = new vector<int>; 
                     (yyval.main).listAndType.dimList->push_back((yyvsp[-1].main).countAndType.count); 
                     (yyval.main).listAndType.eletype = (yyvsp[-1].main).countAndType.eletype; 
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}";
              }
#line 2783 "parser.tab.c"
    break;

  case 121:
#line 660 "parser.y"
              {
                     (yyval.main).listAndType.dimList = (yyvsp[-1].main).listAndType.dimList;
                     (yyval.main).listAndType.eletype = (yyvsp[-1].main).listAndType.eletype;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}";
              }
#line 2793 "parser.tab.c"
    break;

  case 122:
#line 668 "parser.y"
              {
                     updateMaxDim((yyvsp[-2].main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList); 
                     delete (yyvsp[0].main).listAndType.dimList;(yyval.main).listAndType.dimList = (yyvsp[-2].main).listAndType.dimList;
                     if (!coercible((yyvsp[-2].main).listAndType.eletype, (yyvsp[0].main).listAndType.eletype)) semanticError("arrays should be initialized with same datatype");
                     else (yyval.main).listAndType.eletype = (yyvsp[-2].main).listAndType.eletype;
                     *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text ;
              }
#line 2805 "parser.tab.c"
    break;

  case 123:
#line 676 "parser.y"
              {
                     (yyval.main).listAndType.dimList = new vector<int>; 
                     addFrontAndCopy((yyval.main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList, 1);
                     delete (yyvsp[0].main).listAndType.dimList;
                     (yyval.main).listAndType.eletype = (yyvsp[0].main).listAndType.eletype;
                     *(yyval.main).text = *(yyvsp[0].main).text;
              }
#line 2817 "parser.tab.c"
    break;

  case 124:
#line 685 "parser.y"
                             {(yyval.main).countAndType.count = (yyvsp[0].main).countAndType.count;(yyval.main).eletype = (yyvsp[0].main).countAndType.eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2823 "parser.tab.c"
    break;

  case 125:
#line 686 "parser.y"
                           {(yyval.main).countAndType.count = 0;(yyval.main).eletype = UNDEF; *(yyval.main).text = "";}
#line 2829 "parser.tab.c"
    break;

  case 126:
#line 690 "parser.y"
              {
                     (yyval.main).count = (yyvsp[-2].main).countAndType.count + 1; 
                     if (!coercible((yyvsp[-2].main).countAndType.eletype, (yyvsp[0].main).eletype)) semanticError("arrays should be initialized with same datatype");
                     else (yyval.main).countAndType.eletype = (yyvsp[0].main).eletype;
                     //double to int only checked at decl_stmt 
                     *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text ;
              }
#line 2841 "parser.tab.c"
    break;

  case 127:
#line 697 "parser.y"
                           {(yyval.main).countAndType.count = 1;(yyval.main).countAndType.eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2847 "parser.tab.c"
    break;

  case 128:
#line 700 "parser.y"
                                      {(yyval.main).constExp.eletype = sumTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d + (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i + (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d + (yyvsp[0].main).constExp.i;
                                          else 
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i + (yyvsp[0].main).constExp.i;      


                                          *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text  ;                     
                                      }
#line 2866 "parser.tab.c"
    break;

  case 129:
#line 714 "parser.y"
                                   {(yyval.main).constExp.eletype = diffTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d - (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i - (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d - (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i - (yyvsp[0].main).constExp.i;

                                          *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text  ;
                                   }
#line 2884 "parser.tab.c"
    break;

  case 130:
#line 727 "parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d * (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i * (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d * (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i * (yyvsp[0].main).constExp.i;
                                          
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "*" + *(yyvsp[0].main).text  ;     
                                   }
#line 2902 "parser.tab.c"
    break;

  case 131:
#line 740 "parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d / (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i / (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d / (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i / (yyvsp[0].main).constExp.i;

                                          *(yyval.main).text = *(yyvsp[-2].main).text + "/" + *(yyvsp[0].main).text  ;
                                   }
#line 2920 "parser.tab.c"
    break;

  case 132:
#line 753 "parser.y"
                                   {if ((yyvsp[-2].main).constExp.eletype != INT || (yyvsp[0].main).constExp.eletype != INT) semanticError("Error: Semantic error incompatible datatype");(yyval.main).constExp.eletype = INT;
                                          (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i % (yyvsp[0].main).constExp.i;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text  ;
                                   }
#line 2929 "parser.tab.c"
    break;

  case 133:
#line 757 "parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.d, (yyvsp[0].main).constExp.d);
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.i, (yyvsp[0].main).constExp.d);  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.d, (yyvsp[0].main).constExp.i);
                                          else
                                                 (yyval.main).constExp.i = pow((yyvsp[-2].main).constExp.i, (yyvsp[0].main).constExp.i);
                                         
                                          *(yyval.main).text = "pow(" + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + ")" ;
                                   }
#line 2947 "parser.tab.c"
    break;

  case 134:
#line 770 "parser.y"
                        {   
                            if (!arithCompatible((yyvsp[0].main).constExp.eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).constExp.eletype = (yyvsp[0].main).constExp.eletype;

                            if ((yyval.main).constExp.eletype == REAL) 
                                   (yyval.main).constExp.d = -(yyvsp[0].main).constExp.d; 
                            else 
                                   (yyval.main).constExp.i = -(yyvsp[0].main).constExp.i;
                            *(yyval.main).text = "-" + *(yyvsp[0].main).text ;
                        }
#line 2961 "parser.tab.c"
    break;

  case 135:
#line 779 "parser.y"
                            {      
                                   (yyval.main).constExp.eletype = (yyvsp[-1].main).constExp.eletype;
                                   if ((yyval.main).constExp.eletype == REAL) 
                                          (yyval.main).constExp.d = (yyvsp[-1].main).constExp.d; 
                                   else 
                                          (yyval.main).constExp.i = (yyvsp[-1].main).constExp.i;
                                  
                                   *(yyval.main).text = "(" + *(yyvsp[-1].main).text  + ")";
                            }
#line 2975 "parser.tab.c"
    break;

  case 136:
#line 788 "parser.y"
                { *(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;(yyval.main).constExp.d = (yyvsp[0].main).constExp.d;}
#line 2981 "parser.tab.c"
    break;

  case 137:
#line 789 "parser.y"
                  { *(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;(yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2987 "parser.tab.c"
    break;

  case 138:
#line 790 "parser.y"
                 { *(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = INT;(yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2993 "parser.tab.c"
    break;

  case 139:
#line 794 "parser.y"
                           { (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2999 "parser.tab.c"
    break;

  case 140:
#line 795 "parser.y"
                      { *(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 3005 "parser.tab.c"
    break;

  case 141:
#line 796 "parser.y"
                                            {(yyval.main).eletype = sumTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text;}
#line 3011 "parser.tab.c"
    break;

  case 142:
#line 797 "parser.y"
                                            {(yyval.main).eletype = diffTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text;}
#line 3017 "parser.tab.c"
    break;

  case 143:
#line 798 "parser.y"
                                    { *(yyval.main).text = "(" + *(yyvsp[-1].main).text + ")"; (yyval.main).eletype = (yyvsp[-1].main).eletype; }
#line 3023 "parser.tab.c"
    break;

  case 144:
#line 800 "parser.y"
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

              *(yyval.main).text = *(yyvsp[0].main).text;
       }
#line 3041 "parser.tab.c"
    break;

  case 145:
#line 814 "parser.y"
                                            {
                     (yyval.main).dimCount = (yyvsp[-3].main).dimCount; 
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});
                     }

                     *(yyval.main).text = *(yyvsp[-3].main).text + "." + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3055 "parser.tab.c"
    break;

  case 146:
#line 823 "parser.y"
                              {
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     (yyval.main).dimCount = new vector<cntAndType> ;   //free?
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});  
                     } 
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;    
              }
#line 3068 "parser.tab.c"
    break;

  case 147:
#line 834 "parser.y"
                                          {(yyval.main).count = (yyvsp[-3].main).count; (yyval.main).count = (yyval.main).count + 1; *(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";}
#line 3074 "parser.tab.c"
    break;

  case 148:
#line 835 "parser.y"
                        {(yyval.main).count = 0; *(yyval.main).text = "";}
#line 3080 "parser.tab.c"
    break;

  case 149:
#line 838 "parser.y"
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
#line 3097 "parser.tab.c"
    break;

  case 150:
#line 850 "parser.y"
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
              *(yyval.main).text = *(yyvsp[-4].main).text + "(" + *(yyvsp[-1].main).text + ")";
       }
#line 3120 "parser.tab.c"
    break;

  case 151:
#line 870 "parser.y"
                            {*(yyval.main).text = *(yyvsp[0].main).text;}
#line 3126 "parser.tab.c"
    break;

  case 152:
#line 871 "parser.y"
                             {*(yyval.main).text = "";}
#line 3132 "parser.tab.c"
    break;

  case 153:
#line 874 "parser.y"
                                  { *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;}
#line 3138 "parser.tab.c"
    break;

  case 154:
#line 875 "parser.y"
                                  { *(yyval.main).text = " " ;}
#line 3144 "parser.tab.c"
    break;

  case 155:
#line 881 "parser.y"
              {     
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = *(yyvsp[-6].main).text + "(" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
                     // cout << *$$.text << endl;
                     // fprintf(fout_translated, "%s", $$.text->c_str());
              }
#line 3156 "parser.tab.c"
    break;

  case 156:
#line 889 "parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-5].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-8].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = *(yyvsp[-10].main).text + "(" + *(yyvsp[-8].main).text + ")" + *(yyvsp[-6].main).text + *(yyvsp[-5].main).text + *(yyvsp[-4].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3166 "parser.tab.c"
    break;

  case 157:
#line 895 "parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-6].main).stopAdvanceFound||(yyvsp[-4].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-9].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = *(yyvsp[-11].main).text + "(" + *(yyvsp[-9].main).text + ")" + *(yyvsp[-7].main).text + *(yyvsp[-6].main).text + *(yyvsp[-5].main).text + *(yyvsp[-4].main).text + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3176 "parser.tab.c"
    break;

  case 158:
#line 901 "parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-2].main).stopAdvanceFound||(yyvsp[0].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-5].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = *(yyvsp[-7].main).text + "(" + *(yyvsp[-5].main).text + ")" + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3186 "parser.tab.c"
    break;

  case 159:
#line 909 "parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = "else if(" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3196 "parser.tab.c"
    break;

  case 160:
#line 915 "parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-7].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = *(yyvsp[-7].main).text + "else if(" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3206 "parser.tab.c"
    break;

  case 161:
#line 925 "parser.y"
                     { *(yyval.main).text = *(yyvsp[0].main).text; }
#line 3212 "parser.tab.c"
    break;

  case 162:
#line 926 "parser.y"
                     { *(yyval.main).text = *(yyvsp[0].main).text; }
#line 3218 "parser.tab.c"
    break;

  case 163:
#line 929 "parser.y"
                { addSymTabPtr(); }
#line 3224 "parser.tab.c"
    break;

  case 164:
#line 930 "parser.y"
              {
                     insertType((yyvsp[-2].main).name, Var, (yyvsp[-3].main).eletype);
                     *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;  //change this
                     delete (yyvsp[-2].main).name;
              }
#line 3234 "parser.tab.c"
    break;

  case 165:
#line 935 "parser.y"
                { addSymTabPtr(); }
#line 3240 "parser.tab.c"
    break;

  case 166:
#line 937 "parser.y"
              { 
                     *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
                     delete (yyvsp[-2].main).name; 
              }
#line 3249 "parser.tab.c"
    break;

  case 167:
#line 941 "parser.y"
                { addSymTabPtr(); }
#line 3255 "parser.tab.c"
    break;

  case 168:
#line 944 "parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 3261 "parser.tab.c"
    break;

  case 169:
#line 945 "parser.y"
                          {(yyval.main).eletype = UNDEF;}
#line 3267 "parser.tab.c"
    break;

  case 170:
#line 949 "parser.y"
              { 
                     if(!(arithCompatible((yyvsp[-5].main).eletype)) && (yyvsp[-5].main).eletype != UNDEF) semanticError("Error: Semantic error incompatible datatype11");
                     *(yyval.main).text = "for(" + *(yyvsp[-7].main).text + ";" + *(yyvsp[-5].main).text + ";" + *(yyvsp[-3].main).text + ")" + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3276 "parser.tab.c"
    break;

  case 171:
#line 954 "parser.y"
                                                              {*(yyval.main).text = "while(" + *(yyvsp[-3].main).text + ")" + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 3282 "parser.tab.c"
    break;


#line 3286 "parser.tab.c"

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
#line 958 "parser.y"


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

string datatypeTranslation(string dtype) {
       string type;

       if(dtype=="real") {
              type = "double";
       }
       else if(dtype=="angle") {
              type = "double";
       }
       else if(dtype=="label") {
              type = "string";
       }
       else {
              type = dtype;
       }

       return type;
       
}

string centerTranslation(string center) {
       string translatedCenter;
       if(center[0]=='(') {
              int idx = center.find(',');
              if(idx!=string::npos) {
                     string x = center.substr(1,idx-1);
                     string y = center.substr(idx+1,center.size()-idx-1);
                     translatedCenter = "Point(" + x + "," + y + ")";
              }
       }
       else {
              string x = center + ".x";
              string y = center + ".y";
              translatedCenter = "Point(" + x + "," + y + ")";
       }

       return translatedCenter;
}


int main(int argc, char*argv[])
{    

    /* yydebug = 1; */
    if (argc < 2){

        fprintf(stderr, "Please provide the input file\n");
        exit(1);
    }

    /* Appending \n */ 
    FILE* a = fopen(argv[1], "a");
       
       // test
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
    fprintf(fout_translated,"#include<bits/stdc++.h>\n");
    fprintf(fout_translated,"#include<string>\n");
    fprintf(fout_translated,"#include<stdlib.h>\n");
    fprintf(fout_translated,"#include<math.h>\n");
    fprintf(fout_translated,"#include<deque>\n");
    fprintf(fout_translated,"#include \"standard_lib.hpp\" \n");
    fprintf(fout_translated,"using namespace std;\n \n");
    fprintf(fout_translated,"void initGL() { \n glClearColor(1.0f, 1.0f, 1.0f, 1.0f); \n } \n");
    fprintf(fout_translated,"void reshape(GLsizei width, GLsizei height)\n{ if (height == 0)\n   height = 1;\nGLfloat aspect = (GLfloat)width / (GLfloat)height; \n glViewport(0, 0, width, height);glMatrixMode(GL_PROJECTION);\n glLoadIdentity();\n if (width >= height) \n{gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);} \nelse \n{gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);}\n}");
    
    insertConstructTab();
    int x = yyparse();

    for(int i = 0;i<fig_func.size();i++)
       fprintf(fout_translated,"%s\n",fig_func[i].c_str());

    fprintf(fout_translated,"int main(int argc, char** argv){\n");
    fprintf(fout_translated,"glutInit(&argc, argv);\n  glutInitWindowSize(640, 480);\n  glutInitWindowPosition(50, 50);\n  glutCreateWindow(\"Viewport Transform\");\n  gluOrtho2D(-50.0, 50.0, -50.0, 50.0);\n  glutDisplayFunc(display);\n  initGL();\n  glutMainLoop();\n");
    /* fprintf(fout_translated,"  glutInit(&argc, argv); \n  glutInitWindowSize(640, 480); \n  glutInitWindowPosition(50, 50);\n  glutCreateWindow(\"Viewport Transform\"); \n  glutDisplayFunc(display);\n glutReshapeFunc(reshape); \n initGL();\n  glutMainLoop();\n") */
    for(int i=0;i<collection.size();i++){
       fprintf(fout_translated,"%s\n",collection[i].c_str());
    }
    fprintf(fout_translated,"  return 0\n } \n");

    fclose(fp);
    fclose(fout_token);
    return x;
} 
