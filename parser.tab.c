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

void semanticError(const char* s);

enum eletype sumTypeCheck(enum eletype E1, enum eletype E2);
enum eletype diffTypeCheck(enum eletype E1, enum eletype E2);
enum eletype mulTypeCheck(enum eletype E1, enum eletype E2);
enum eletype arithTypeCheck(enum eletype E1, enum eletype E2);
enum eletype pointCheck (enum eletype x, enum eletype y);
bool arithCompatible(int e);

bool coercible(int t1, int t2);
void typeUpdate(vector<char*>* v, enum eletype t);
void insert(char* name, vector<int>* dim, enum eletype t);
void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x);
void updateMaxDim(vector<int>* comma, vector<int>* assign); // for now have to be equal
void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList);
void insertArray(char* name, vector <int>* dimList);


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


#line 130 "parser.tab.c"

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
#line 63 "parser.y"

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

#line 245 "parser.tab.c"

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
#define YYLAST   1206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

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
       0,   147,   147,   148,   149,   150,   158,   169,   179,   179,
     181,   181,   183,   184,   187,   187,   190,   191,   192,   193,
     193,   196,   196,   196,   196,   196,   196,   196,   198,   199,
     202,   205,   205,   205,   205,   205,   205,   205,   207,   207,
     210,   212,   212,   212,   215,   216,   219,   220,   223,   224,
     225,   226,   229,   230,   233,   234,   237,   238,   242,   243,
     247,   248,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   283,   284,   285,   286,   292,   293,   296,   297,
     298,   299,   300,   301,   304,   305,   308,   309,   313,   314,
     315,   320,   328,   339,   340,   343,   344,   347,   348,   351,
     352,   360,   373,   385,   397,   408,   411,   423,   430,   437,
     438,   439,   443,   444,   447,   447,   449,   449,   452,   452,
     456,   456,   457,   457,   459,   460,   461,   462,   465,   466,
     471,   471,   472,   472,   474,   474,   476,   476,   476,   477,
     477,   478,   480
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
  "cond_stmt", "ret_var", "optional_arg", "program", "func", "arg_list",
  "list1", "argument", "func_body", "fig", "params", "fig_body", "stmt",
  "stmt_list", "stmt_block", "stmt_loop", "break_stmt", "return_stmt",
  "valid_arg", "param_list", "vertex", "decl_stmt", "arr_access",
  "func_call", "empty_space", "stmt_list1", "stmt_block1", "elif_stmt",
  "stmt_loop_list", "stmt_loop_block", "loop", "for_loop_decl", "for_loop",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      60,    62,    43,    45,    42,    47,    37,   295,    94,    40,
      41,   123,   125,    44,    91,    93,    46,   124
};
# endif

#define YYPACT_NINF (-218)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -218,   126,  -218,  -218,  -218,  -218,   -29,    51,    57,   829,
     879,    89,     2,     4,    86,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,   879,    74,   879,   879,  -218,    96,  -218,    75,
    -218,  -218,  1059,   159,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,   879,    14,   879,  -218,    85,
    1092,   110,  1125,   113,   123,   114,   106,   -17,    -5,   117,
    -218,  -218,   879,  -218,    74,   120,   554,   291,  -218,   646,
      65,   879,   879,   879,   879,   879,  -218,   879,   879,   879,
     879,   879,   879,   879,   879,   879,   879,  -218,   879,   879,
     879,   879,   687,   134,  -218,   895,   137,   145,   121,   936,
    -218,   624,   124,   125,   851,   829,     3,   149,   133,  -218,
    -218,   150,   879,   717,    74,  -218,   879,  -218,  -218,  -218,
    -218,  1092,  -218,    64,  -218,   -15,   208,  1158,   191,   963,
     477,   702,   191,   191,   -15,   -15,   120,   120,   120,   120,
    1092,  1092,  1092,  1092,  -218,    82,  -218,  -218,   161,   879,
     879,  -218,   168,   168,   171,   750,   152,  -218,  1092,  -218,
    -218,  -218,  -218,    18,    18,   153,   507,   155,    18,   -17,
     492,   -14,   595,  -218,   829,  -218,   117,   -11,   119,   879,
    1092,  1092,   154,   -10,  -218,   183,   166,   172,  -218,   176,
     879,   879,  -218,    67,   656,    18,   133,    18,    18,    18,
      18,    18,    18,  -218,   538,  -218,   578,   201,  -218,  -218,
    -218,   238,  -218,   215,  -218,  -218,   325,   197,  -218,   141,
    1092,   879,   189,   193,  -218,   168,  -218,   783,  1092,    -1,
    -218,    67,    67,   207,   207,   207,   207,  1092,   204,   206,
    -218,    99,  -218,   155,   224,   216,   241,  -218,   359,   879,
    -218,   226,  -218,   231,   247,   253,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,   257,  -218,  -218,    68,  -218,    69,
     244,  -218,   879,  -218,  -218,   155,  -218,  -218,  -218,  -218,
     270,  -218,   977,   879,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,   278,   393,  1092,  -218,  -218,  -218,  1018,  -218,
     427,   461,   879,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    1092,  -218
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     1,    86,    87,    85,     0,     0,     0,    43,
       0,     0,     0,     0,     0,    88,    26,   135,    48,    49,
      50,    51,     0,     0,     0,     0,    29,     0,    24,     0,
      90,    91,     0,    83,    21,     2,     3,     4,    27,    25,
      23,    89,    22,   154,   155,     0,   158,     0,    41,     0,
      42,     0,     0,     0,     0,     0,    73,   105,     0,   133,
      75,    58,     0,    59,     0,    72,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
      40,    71,     0,     0,     0,     0,     0,   101,   108,   103,
      96,     0,     0,     0,     0,    84,     0,    30,    28,    47,
      52,    53,    55,     0,    97,    68,    69,    70,    79,    82,
      76,    77,    80,    81,    62,    63,    64,    65,    66,    67,
      93,    94,    95,    92,   137,     0,   135,   139,     0,     0,
     160,   139,     9,     9,     0,     0,     0,   106,   107,   104,
     130,   131,   129,     0,     0,   109,     0,     0,     0,   105,
       0,     0,     0,    46,     0,   136,   132,     0,   144,     0,
     157,   159,     0,     0,   162,     0,     0,     8,    11,     0,
       0,     0,   139,   127,     0,     0,   110,     0,     0,     0,
       0,     0,     0,   112,   118,   102,     0,    99,   100,   134,
      61,     0,    57,     0,    54,   138,     0,     0,   139,   147,
     156,   160,     0,    13,   139,     0,   139,     0,    17,     0,
     128,   121,   122,   123,   124,   125,   126,   120,   117,     0,
     116,     0,   111,     0,     0,     0,     0,   141,     0,     0,
     145,     0,   139,     0,     0,     0,    37,   153,    34,    31,
     151,    36,    35,    33,     0,    32,    12,     0,    10,     0,
       0,    20,     0,   113,   114,     0,    98,    60,    56,   143,
       0,   140,     0,     0,   146,   139,    39,    38,   152,   150,
      15,    15,     0,     0,   119,   115,   142,   139,     0,   161,
       0,     0,     0,    16,    19,   148,   139,     7,    14,     6,
      18,   149
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,    16,  -217,    17,   -21,  -218,    -9,   295,  -218,   281,
    -218,  -218,   116,  -166,   162,  -187,  -218,  -218,   164,  -213,
    -218,   118,  -218,  -218,   185,  -218,   122,    53,  -218,  -218,
    -218,    11,  -218,  -218,    84,  -218,  -180,   175,   258,   -60,
    -173,   205,  -218,  -137,  -218,  -207,  -218,  -218,    76,  -163,
    -218,  -218,  -218
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,    30,    31,    32,    33,    94,    58,
     238,   239,   166,   107,   108,   205,   241,   159,   109,    34,
      51,   182,     1,    35,   186,   187,   188,   300,    36,   156,
     293,   308,    67,    38,   260,   261,    39,   122,   123,    64,
      40,    59,    41,   177,   248,   178,   219,   264,   184,    42,
      98,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    52,    63,   207,   114,   258,   160,   161,   162,   259,
     105,   250,    37,    60,   183,    65,    66,   240,   215,   215,
      45,   160,   161,   162,   110,    48,    49,   210,   215,    83,
      84,    85,    55,    86,    17,    96,    95,   106,    99,   211,
     216,   222,   262,    63,    97,   284,   163,   258,   111,   263,
     271,   259,   164,   113,   171,   229,   276,   266,   165,   265,
     121,   163,   125,   126,   127,   128,   129,   164,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   118,   140,
     141,   142,   143,   121,   262,   120,    49,   267,   295,   269,
     305,   263,   126,    63,   124,   155,   158,   215,   215,   311,
      46,   265,    53,   170,    61,    57,    47,   172,   120,    49,
      54,   199,   200,   201,   173,   202,    57,   174,   111,   290,
     291,   157,    49,    62,    69,    68,     2,   217,   218,     3,
       4,     5,   175,     6,    69,   174,     7,     8,     9,   100,
     180,   181,    10,   102,    11,    12,    13,    14,   183,   251,
     252,   274,   275,   103,    15,    16,    17,    18,    19,    20,
      21,    22,    93,   104,   146,   121,    23,   148,    86,    24,
     220,   112,   149,   152,   153,    25,   167,    26,   150,    87,
     169,   227,   228,    88,    89,    90,    91,   168,   179,   185,
     120,    49,     3,     4,     5,   237,     6,    71,   190,     7,
       8,     9,   192,   254,   255,    10,   204,   195,    92,    13,
      14,   221,   181,   223,    71,    93,   224,    15,   256,    17,
      18,    19,    20,    21,    22,   225,   226,   247,   243,    23,
      74,    75,    24,    81,    82,    83,    84,    85,    25,    86,
     282,   257,   244,   245,    77,    78,   249,   106,    79,    80,
      81,    82,    83,    84,    85,   202,    86,   272,   273,   281,
       3,     4,     5,   294,     6,   277,   278,     7,     8,     9,
     279,   254,   255,    10,   298,   283,   286,    13,    14,   193,
     194,   285,   287,   292,   206,    15,   256,    17,    18,    19,
      20,    21,    22,   310,     3,     4,     5,    23,     6,   296,
      24,     7,     8,     9,   304,   302,    25,    10,    56,   288,
      70,    13,    14,   231,   232,   233,   234,   235,   236,    15,
      16,    17,    18,    19,    20,    21,    22,   196,     3,     4,
       5,    23,     6,   208,    24,     7,     8,     9,   189,   253,
      25,    10,    26,   117,   301,    13,    14,   268,   289,   214,
     145,   176,     0,    15,    16,    17,    18,    19,    20,    21,
      22,   299,     3,     4,     5,    23,     6,     0,    24,     7,
       8,     9,     0,     0,    25,    10,    26,   246,     0,    13,
      14,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     3,     4,     5,    23,
       6,     0,    24,     7,     8,     9,     0,     0,    25,    10,
      26,   280,     0,    13,    14,     0,     0,     0,     0,     0,
       0,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       3,     4,     5,    23,     6,     0,    24,     7,     8,     9,
       0,     0,    25,    10,    26,   303,     0,    13,    14,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     3,     4,     5,    23,     6,     0,
      24,     7,     8,     9,     0,     0,    25,    10,    26,   307,
       0,    13,    14,    71,     0,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,    22,     0,    71,    74,
      75,    23,     0,     0,    24,     0,     0,     0,    72,    73,
      25,     0,    26,   309,    74,    75,     0,    79,    80,    81,
      82,    83,    84,    85,     0,    86,     0,     0,    77,    78,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     3,     4,     5,     0,     0,     0,   209,     0,   197,
     198,   199,   200,   201,    10,   202,     0,     0,    13,     0,
      71,     0,   203,     0,     0,     0,    15,     0,    17,     0,
      72,    73,     0,    22,     0,     0,    74,    75,    23,     0,
       0,    24,     0,     0,     0,     0,     0,    25,     0,   204,
      77,    78,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    71,    86,     0,   115,     0,     0,   116,     0,     0,
       0,    72,    73,     0,     0,     0,     0,    74,    75,     0,
     197,   198,   199,   200,   201,     0,   202,     3,     4,     5,
       0,    77,    78,   242,     0,    79,    80,    81,    82,    83,
      84,    85,     0,    86,    13,   212,     0,     0,   213,     3,
       4,     5,    15,     0,    17,     0,     0,     0,     0,    22,
       0,     0,    10,     0,    23,     0,    13,    24,     0,     0,
       0,     0,     0,    25,    15,     0,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,    23,     0,     0,    24,
       3,     4,     5,     0,     0,    25,   119,     0,   197,   198,
     199,   200,   201,    10,   202,     0,   230,    13,    71,     0,
       0,     0,     0,     0,     0,    15,     0,    17,    18,    19,
      20,    21,    22,    71,    74,    75,     0,    23,     0,     0,
      24,     0,     0,    72,    73,     0,    25,   144,    77,    74,
      75,     0,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,     0,    77,    78,     0,    71,    79,    80,    81,
      82,    83,    84,    85,     0,    86,    72,    73,     0,     0,
     116,     0,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,     0,    71,
      79,    80,    81,    82,    83,    84,    85,     0,    86,    72,
      73,     0,     0,   191,     0,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,     0,     0,    79,    80,    81,    82,    83,    84,    85,
       0,    86,     3,     4,     5,     0,   270,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,    13,
       0,     0,     0,     0,     3,     4,     5,    15,     0,    17,
      18,    19,    20,    21,    22,     0,     0,    10,     0,    23,
       0,    13,    24,     0,     0,     0,     0,     0,    25,    15,
       0,    17,     3,     4,     5,     0,    22,     0,     0,   154,
       0,    23,     0,     0,    24,    10,     0,     0,     0,    13,
      25,    71,     0,     0,     0,     0,     0,    15,     0,    17,
       0,    72,    73,     0,    22,     0,     0,    74,    75,    23,
       0,     0,    24,     0,     0,     0,     0,     0,    25,     0,
       0,    77,    78,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    71,    86,     0,   147,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,    77,    78,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    71,    86,    74,   151,     0,     0,     0,
       0,     0,     0,    72,    73,     0,     0,     0,     0,    74,
      75,     0,     0,    79,    80,    81,    82,    83,    84,    85,
       0,    86,     0,    77,    78,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    71,    86,     0,   297,     0,     0,
       0,     0,     0,     0,    72,    73,     0,     0,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    71,    86,     0,   306,     0,
       0,     0,     0,     0,     0,    72,    73,     0,     0,     0,
       0,    74,    75,     0,     0,     0,     0,     0,    76,     0,
       0,     0,     0,     0,     0,    77,    78,     0,    71,    79,
      80,    81,    82,    83,    84,    85,     0,    86,    72,    73,
       0,     0,     0,     0,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
       0,    71,    79,    80,    81,    82,    83,    84,    85,     0,
      86,   101,    73,     0,     0,     0,     0,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,     0,    71,    79,    80,    81,    82,    83,
      84,    85,     0,    86,    72,     0,     0,     0,     0,     0,
      74,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,     0,     0,    79,    80,
      81,    82,    83,    84,    85,     0,    86
};

static const yytype_int16 yycheck[] =
{
       9,    10,    23,   169,    64,   222,     3,     4,     5,   222,
      27,   218,     1,    22,   151,    24,    25,   204,    29,    29,
      49,     3,     4,     5,    29,     9,     9,    41,    29,    44,
      45,    46,    30,    48,    30,    21,    45,    54,    47,    53,
      51,    51,   222,    64,    30,   252,    43,   264,    53,   222,
      51,   264,    49,    62,   114,   192,   243,   223,    55,   222,
      69,    43,    71,    72,    73,    74,    75,    49,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    67,    88,
      89,    90,    91,    92,   264,    69,    69,   224,   275,   226,
     297,   264,   101,   114,    29,   104,   105,    29,    29,   306,
      49,   264,    13,   112,    30,    30,    49,   116,    92,    92,
      21,    44,    45,    46,    50,    48,    30,    53,    53,    51,
      51,   105,   105,    49,    49,    29,     0,     8,     9,     3,
       4,     5,    50,     7,    49,    53,    10,    11,    12,    29,
     149,   150,    16,    30,    18,    19,    20,    21,   285,     8,
       9,    52,    53,    30,    28,    29,    30,    31,    32,    33,
      34,    35,    56,    49,    30,   174,    40,    30,    48,    43,
     179,    54,    27,    49,    49,    49,    27,    51,    57,    20,
      30,   190,   191,    24,    25,    26,    27,    54,    27,    21,
     174,   174,     3,     4,     5,   204,     7,     6,    27,    10,
      11,    12,    50,    14,    15,    16,    51,    54,    49,    20,
      21,    57,   221,    30,     6,    56,    50,    28,    29,    30,
      31,    32,    33,    34,    35,    53,    50,   216,    27,    40,
      22,    23,    43,    42,    43,    44,    45,    46,    49,    48,
     249,    52,     4,    28,    36,    37,    49,    54,    40,    41,
      42,    43,    44,    45,    46,    48,    48,    53,    52,   248,
       3,     4,     5,   272,     7,    41,    50,    10,    11,    12,
      29,    14,    15,    16,   283,    49,    29,    20,    21,   163,
     164,    50,    29,    39,   168,    28,    29,    30,    31,    32,
      33,    34,    35,   302,     3,     4,     5,    40,     7,    29,
      43,    10,    11,    12,   293,    27,    49,    16,    13,    52,
      29,    20,    21,   197,   198,   199,   200,   201,   202,    28,
      29,    30,    31,    32,    33,    34,    35,   165,     3,     4,
       5,    40,     7,   169,    43,    10,    11,    12,   153,   221,
      49,    16,    51,    52,   291,    20,    21,   225,   264,   174,
      92,   146,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,   285,     3,     4,     5,    40,     7,    -1,    43,    10,
      11,    12,    -1,    -1,    49,    16,    51,    52,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,     3,     4,     5,    40,
       7,    -1,    43,    10,    11,    12,    -1,    -1,    49,    16,
      51,    52,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
       3,     4,     5,    40,     7,    -1,    43,    10,    11,    12,
      -1,    -1,    49,    16,    51,    52,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,     3,     4,     5,    40,     7,    -1,
      43,    10,    11,    12,    -1,    -1,    49,    16,    51,    52,
      -1,    20,    21,     6,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,     6,    22,
      23,    40,    -1,    -1,    43,    -1,    -1,    -1,    16,    17,
      49,    -1,    51,    52,    22,    23,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,     3,     4,     5,    -1,    -1,    -1,    55,    -1,    42,
      43,    44,    45,    46,    16,    48,    -1,    -1,    20,    -1,
       6,    -1,    55,    -1,    -1,    -1,    28,    -1,    30,    -1,
      16,    17,    -1,    35,    -1,    -1,    22,    23,    40,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,    51,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     6,    48,    -1,    50,    -1,    -1,    53,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      42,    43,    44,    45,    46,    -1,    48,     3,     4,     5,
      -1,    36,    37,    55,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    20,    50,    -1,    -1,    53,     3,
       4,     5,    28,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    16,    -1,    40,    -1,    20,    43,    -1,    -1,
      -1,    -1,    -1,    49,    28,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,
       3,     4,     5,    -1,    -1,    49,    50,    -1,    42,    43,
      44,    45,    46,    16,    48,    -1,    50,    20,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,     6,    22,    23,    -1,    40,    -1,    -1,
      43,    -1,    -1,    16,    17,    -1,    49,    50,    36,    22,
      23,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    -1,    -1,    36,    37,    -1,     6,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    16,    17,    -1,    -1,
      53,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,     6,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    16,
      17,    -1,    -1,    53,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,     3,     4,     5,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,     3,     4,     5,    28,    -1,    30,
      31,    32,    33,    34,    35,    -1,    -1,    16,    -1,    40,
      -1,    20,    43,    -1,    -1,    -1,    -1,    -1,    49,    28,
      -1,    30,     3,     4,     5,    -1,    35,    -1,    -1,    38,
      -1,    40,    -1,    -1,    43,    16,    -1,    -1,    -1,    20,
      49,     6,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    16,    17,    -1,    35,    -1,    -1,    22,    23,    40,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,     6,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,     6,    48,    22,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,     6,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,     6,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,     6,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,     6,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,     6,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    16,    -1,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    80,     0,     3,     4,     5,     7,    10,    11,    12,
      16,    18,    19,    20,    21,    28,    29,    30,    31,    32,
      33,    34,    35,    40,    43,    49,    51,    59,    60,    61,
      62,    63,    64,    65,    77,    81,    86,    89,    91,    94,
      98,   100,   107,   109,   110,    49,    49,    49,    59,    61,
      64,    78,    64,    13,    21,    30,    65,    30,    67,    99,
      64,    30,    49,    62,    97,    64,    64,    90,    29,    49,
      67,     6,    16,    17,    22,    23,    29,    36,    37,    40,
      41,    42,    43,    44,    45,    46,    48,    20,    24,    25,
      26,    27,    49,    56,    66,    64,    21,    30,   108,    64,
      29,    16,    30,    30,    49,    27,    54,    71,    72,    76,
      29,    53,    54,    64,    97,    50,    53,    52,    89,    50,
      59,    64,    95,    96,    29,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    50,    96,    30,    50,    30,    27,
      57,    50,    49,    49,    38,    64,    87,    59,    64,    75,
       3,     4,     5,    43,    49,    55,    70,    27,    54,    30,
      64,    97,    64,    50,    53,    50,    99,   101,   103,    27,
      64,    64,    79,   101,   106,    21,    82,    83,    84,    82,
      27,    53,    50,    70,    70,    54,    72,    42,    43,    44,
      45,    46,    48,    55,    51,    73,    70,    71,    76,    55,
      41,    53,    50,    53,    95,    29,    51,     8,     9,   104,
      64,    57,    51,    30,    50,    53,    50,    64,    64,   101,
      50,    70,    70,    70,    70,    70,    70,    64,    68,    69,
      73,    74,    55,    27,     4,    28,    52,    89,   102,    49,
     103,     8,     9,    79,    14,    15,    29,    52,    60,    77,
      92,    93,    94,    98,   105,   107,    71,   101,    84,   101,
      53,    51,    53,    52,    52,    53,    73,    41,    50,    29,
      52,    89,    64,    49,   103,    50,    29,    29,    52,    92,
      51,    51,    39,    88,    64,    73,    29,    50,    64,   106,
      85,    85,    27,    52,    89,   103,    50,    52,    89,    52,
      64,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    78,    78,    78,    60,    60,    59,    59,    61,    61,
      61,    61,    95,    95,    96,    96,    62,    62,    97,    97,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    66,    66,    66,    66,    98,    98,    67,    67,
      67,    67,    67,    67,    76,    76,    75,    75,    71,    71,
      71,    72,    72,    73,    73,    74,    74,    69,    69,    68,
      68,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    65,    65,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,    77,    77,    77,    77,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,    79,
      79,   109,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,    10,    10,     1,     0,
       3,     1,     3,     2,     2,     0,     9,     3,     7,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     0,     2,     2,     4,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     7,     5,     1,     1,
       7,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     3,     3,     2,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     6,     4,
       4,     2,     4,     2,     2,     0,     1,     1,     1,     2,
       3,     4,     3,     3,     3,     3,     1,     1,     0,     3,
       1,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     4,     2,     4,     0,     4,     3,     2,     0,
       2,     1,     5,     4,     5,     7,     8,     6,     5,     6,
       2,     1,     4,     3,     1,     1,     4,     3,     0,     1,
       0,     9,     5
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
#line 150 "parser.y"
                     {
              if(ret_flag) {
                     cerr<<"Error: Return statement not allowed outside function"<<endl;
              }
         }
#line 1828 "parser.tab.c"
    break;

  case 6:
#line 158 "parser.y"
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
#line 1844 "parser.tab.c"
    break;

  case 7:
#line 169 "parser.y"
                                                                      {
              insertType((yyvsp[-7].name), Func, (yyvsp[-8].eletype));  
              printSymbolTable();
              if(ret_type!=UNDEF && ret_type!=Void) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0; 
       }
#line 1857 "parser.tab.c"
    break;

  case 16:
#line 190 "parser.y"
                                                       { if (ret_fig_flag == 1)  semanticError("Error: Return statement is not allowed in figures."); ret_fig_flag =0; }
#line 1863 "parser.tab.c"
    break;

  case 17:
#line 191 "parser.y"
                                   { if(!(arithCompatible((yyvsp[-2].eletype)) && (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
#line 1869 "parser.tab.c"
    break;

  case 18:
#line 192 "parser.y"
                                                            { if(!(arithCompatible((yyvsp[-4].eletype)) && (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
#line 1875 "parser.tab.c"
    break;

  case 40:
#line 210 "parser.y"
                                     {ret_type = (yyvsp[-1].eletype); ret_flag = 1; ret_fig_flag = 1;}
#line 1881 "parser.tab.c"
    break;

  case 41:
#line 212 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1887 "parser.tab.c"
    break;

  case 42:
#line 212 "parser.y"
                                            {(yyval.eletype) = (yyvsp[0].eletype);}
#line 1893 "parser.tab.c"
    break;

  case 43:
#line 212 "parser.y"
                                                         {(yyval.eletype) = Void;}
#line 1899 "parser.tab.c"
    break;

  case 44:
#line 215 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1905 "parser.tab.c"
    break;

  case 45:
#line 216 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 1911 "parser.tab.c"
    break;

  case 46:
#line 219 "parser.y"
                                            {(yyval.eletype) = (yyvsp[-3].eletype);}
#line 1917 "parser.tab.c"
    break;

  case 47:
#line 220 "parser.y"
                                {(yyval.eletype) = (yyvsp[-2].eletype);}
#line 1923 "parser.tab.c"
    break;

  case 48:
#line 223 "parser.y"
                           { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1929 "parser.tab.c"
    break;

  case 49:
#line 224 "parser.y"
                              { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1935 "parser.tab.c"
    break;

  case 50:
#line 225 "parser.y"
                            { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1941 "parser.tab.c"
    break;

  case 51:
#line 226 "parser.y"
                               { (yyval.eletype) = (yyvsp[0].eletype);}
#line 1947 "parser.tab.c"
    break;

  case 56:
#line 237 "parser.y"
                                                            {  (yyval.eletype) = pointCheck((yyvsp[-5].eletype), (yyvsp[-3].eletype)); }
#line 1953 "parser.tab.c"
    break;

  case 57:
#line 238 "parser.y"
                                               {  (yyval.eletype) = pointCheck((yyvsp[-3].eletype), (yyvsp[-1].eletype)); }
#line 1959 "parser.tab.c"
    break;

  case 58:
#line 242 "parser.y"
           { if (checkEletype((yyvsp[0].name)) != POINT) semanticError("Error: vertex has to be a point");}
#line 1965 "parser.tab.c"
    break;

  case 60:
#line 247 "parser.y"
                                                  {(yyval.eletype) = REAL;}
#line 1971 "parser.tab.c"
    break;

  case 61:
#line 248 "parser.y"
                                      {(yyval.eletype) = REAL;}
#line 1977 "parser.tab.c"
    break;

  case 62:
#line 251 "parser.y"
                                        {(yyval.eletype) = sumTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype)); }
#line 1983 "parser.tab.c"
    break;

  case 63:
#line 252 "parser.y"
                                        {(yyval.eletype) = diffTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 1989 "parser.tab.c"
    break;

  case 64:
#line 253 "parser.y"
                                        {(yyval.eletype) = mulTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 1995 "parser.tab.c"
    break;

  case 65:
#line 254 "parser.y"
                                        {(yyval.eletype) = mulTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 2001 "parser.tab.c"
    break;

  case 66:
#line 255 "parser.y"
                                        {if ((yyvsp[-2].eletype) != INT || (yyvsp[0].eletype) != INT) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = INT;}
#line 2007 "parser.tab.c"
    break;

  case 67:
#line 256 "parser.y"
                                        {(yyval.eletype) = mulTypeCheck((yyvsp[-2].eletype), (yyvsp[0].eletype));}
#line 2013 "parser.tab.c"
    break;

  case 68:
#line 257 "parser.y"
                                            {if(((yyvsp[-2].eletype) == POINT || (yyvsp[-2].eletype) == LINEARR) && (yyvsp[0].eletype) == POINT) (yyval.eletype) = LINEARR ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 2019 "parser.tab.c"
    break;

  case 69:
#line 258 "parser.y"
                                             {if(((yyvsp[-2].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR) && ((yyvsp[0].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR)) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
#line 2025 "parser.tab.c"
    break;

  case 70:
#line 259 "parser.y"
                                                   {if(((yyvsp[-2].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR) && ((yyvsp[0].eletype) == LINE||(yyvsp[-2].eletype) == LINEARR)) (yyval.eletype) = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
#line 2031 "parser.tab.c"
    break;

  case 71:
#line 260 "parser.y"
                                            {if ((yyvsp[-1].eletype) != POINT) semanticError("Error: Semantic error incompatible datatype") ; (yyval.eletype) = REAL; }
#line 2037 "parser.tab.c"
    break;

  case 72:
#line 261 "parser.y"
                                       {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2043 "parser.tab.c"
    break;

  case 73:
#line 262 "parser.y"
                                  {if(!((yyvsp[0].eletype) == INT || (yyvsp[0].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);  }
#line 2049 "parser.tab.c"
    break;

  case 74:
#line 263 "parser.y"
                                  {if(!((yyvsp[-1].eletype) == INT || (yyvsp[-1].eletype) == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);  }
#line 2055 "parser.tab.c"
    break;

  case 75:
#line 264 "parser.y"
                             {if (!arithCompatible((yyvsp[0].eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2061 "parser.tab.c"
    break;

  case 76:
#line 265 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2067 "parser.tab.c"
    break;

  case 77:
#line 266 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;  }
#line 2073 "parser.tab.c"
    break;

  case 78:
#line 267 "parser.y"
                                    {if(!((yyvsp[0].eletype) == POINT && (yyvsp[-1].eletype) == POINT)||((yyvsp[0].eletype) == LABEL && (yyvsp[-1].eletype) == LABEL || arithCompatible((yyvsp[-1].eletype)) && arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[-1].eletype);}
#line 2079 "parser.tab.c"
    break;

  case 79:
#line 268 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2085 "parser.tab.c"
    break;

  case 80:
#line 269 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2091 "parser.tab.c"
    break;

  case 81:
#line 270 "parser.y"
                                         {if(!(arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) && ((yyvsp[-2].eletype)!=LABEL || (yyvsp[0].eletype) != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2097 "parser.tab.c"
    break;

  case 82:
#line 271 "parser.y"
                                              {if(!((arithCompatible((yyvsp[-2].eletype)) && arithCompatible((yyvsp[0].eletype))) || ((yyvsp[-2].eletype) == (yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = BOOL;}
#line 2103 "parser.tab.c"
    break;

  case 83:
#line 272 "parser.y"
                            {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2109 "parser.tab.c"
    break;

  case 84:
#line 273 "parser.y"
                                 {(yyval.eletype) = (yyvsp[-1].eletype);}
#line 2115 "parser.tab.c"
    break;

  case 85:
#line 274 "parser.y"
                     {(yyval.eletype) = (yyvsp[0].constExp).eletype;}
#line 2121 "parser.tab.c"
    break;

  case 86:
#line 275 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].constExp).eletype;}
#line 2127 "parser.tab.c"
    break;

  case 87:
#line 276 "parser.y"
                      {(yyval.eletype) = (yyvsp[0].constExp).eletype;}
#line 2133 "parser.tab.c"
    break;

  case 88:
#line 277 "parser.y"
                           {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2139 "parser.tab.c"
    break;

  case 90:
#line 279 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2145 "parser.tab.c"
    break;

  case 91:
#line 280 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2151 "parser.tab.c"
    break;

  case 93:
#line 284 "parser.y"
                                {if(!(arithCompatible((yyvsp[0].eletype)))) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2157 "parser.tab.c"
    break;

  case 94:
#line 285 "parser.y"
                                    {if(!(arithCompatible((yyvsp[0].eletype)) || (yyvsp[0].eletype) == LABEL || (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype); }
#line 2163 "parser.tab.c"
    break;

  case 95:
#line 286 "parser.y"
                                  {if(!(arithCompatible((yyvsp[0].eletype)) || (yyvsp[0].eletype) == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.eletype) = (yyvsp[0].eletype);}
#line 2169 "parser.tab.c"
    break;

  case 96:
#line 292 "parser.y"
                                     {typeUpdate((yyvsp[-1].nameList), (yyvsp[-2].eletype));}
#line 2175 "parser.tab.c"
    break;

  case 97:
#line 293 "parser.y"
                                        {typeUpdate((yyvsp[-1].nameList), (yyvsp[-2].eletype));}
#line 2181 "parser.tab.c"
    break;

  case 98:
#line 296 "parser.y"
                                                   {(yyval.nameList) = (yyvsp[-5].nameList);(yyval.nameList)->push_back((yyvsp[-3].name));compareAndInsertArray((yyvsp[-3].name), (yyvsp[-2].dimList), (yyvsp[0].listAndType).eletype, (yyvsp[0].listAndType).dimList);}
#line 2187 "parser.tab.c"
    break;

  case 99:
#line 297 "parser.y"
                                   {(yyval.nameList) = (yyvsp[-3].nameList);(yyval.nameList)->push_back((yyvsp[-1].name));insertArray((yyvsp[-1].name), (yyvsp[0].dimList));}
#line 2193 "parser.tab.c"
    break;

  case 100:
#line 298 "parser.y"
                                    {(yyval.nameList) = (yyvsp[-3].nameList);(yyval.nameList)->push_back((yyvsp[-1].name));insertType((yyvsp[-1].name), Var, (yyvsp[0].eletype));}
#line 2199 "parser.tab.c"
    break;

  case 101:
#line 299 "parser.y"
                       {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-1].name));insertArray((yyvsp[-1].name), (yyvsp[0].dimList));}
#line 2205 "parser.tab.c"
    break;

  case 102:
#line 300 "parser.y"
                                       {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-3].name));compareAndInsertArray((yyvsp[-3].name), (yyvsp[-2].dimList), (yyvsp[0].listAndType).eletype, (yyvsp[0].listAndType).dimList);}
#line 2211 "parser.tab.c"
    break;

  case 103:
#line 301 "parser.y"
                        {(yyval.nameList) = new vector<char*>;(yyval.nameList)->push_back((yyvsp[-1].name));insertType((yyvsp[-1].name), Var, (yyvsp[0].eletype));}
#line 2217 "parser.tab.c"
    break;

  case 104:
#line 304 "parser.y"
                              {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2223 "parser.tab.c"
    break;

  case 105:
#line 305 "parser.y"
                      {(yyval.eletype) = UNDEF;}
#line 2229 "parser.tab.c"
    break;

  case 106:
#line 308 "parser.y"
                       {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2235 "parser.tab.c"
    break;

  case 107:
#line 309 "parser.y"
                    {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2241 "parser.tab.c"
    break;

  case 108:
#line 313 "parser.y"
               {(yyval.dimList) = (yyvsp[0].dimList);}
#line 2247 "parser.tab.c"
    break;

  case 109:
#line 314 "parser.y"
                  {(yyval.dimList) = new vector<int>;(yyval.dimList)->push_back(-1);}
#line 2253 "parser.tab.c"
    break;

  case 110:
#line 315 "parser.y"
                      {(yyval.dimList) = new vector<int>;addFrontAndCopy((yyval.dimList), (yyvsp[0].dimList), -1);delete (yyvsp[0].dimList);}
#line 2259 "parser.tab.c"
    break;

  case 111:
#line 320 "parser.y"
                             {(yyval.dimList) = (yyvsp[-3].dimList);
                              
                            if ((yyvsp[-1].constExp).eletype == REAL)
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).d);
                            else              
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).i);
                            
                            }
#line 2272 "parser.tab.c"
    break;

  case 112:
#line 328 "parser.y"
                         {(yyval.dimList) = new vector<int>; 

                            if ((yyvsp[-1].constExp).eletype == REAL)
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).d);
                            else              
                                   (yyval.dimList)->push_back((yyvsp[-1].constExp).i);
                         }
#line 2284 "parser.tab.c"
    break;

  case 113:
#line 339 "parser.y"
                                   {(yyval.listAndType).dimList = new vector<int>; (yyval.listAndType).dimList->push_back((yyvsp[-1].countAndType).count); (yyval.listAndType).eletype = (yyvsp[-1].countAndType).eletype;print(*((yyval.listAndType).dimList));}
#line 2290 "parser.tab.c"
    break;

  case 114:
#line 340 "parser.y"
                                      {(yyval.listAndType).dimList = (yyvsp[-1].listAndType).dimList;print(*((yyval.listAndType).dimList));(yyval.listAndType).eletype = (yyvsp[-1].listAndType).eletype;}
#line 2296 "parser.tab.c"
    break;

  case 115:
#line 343 "parser.y"
                                                   {updateMaxDim((yyvsp[-2].listAndType).dimList, (yyvsp[0].listAndType).dimList); delete (yyvsp[0].listAndType).dimList;(yyval.listAndType).dimList = (yyvsp[-2].listAndType).dimList;if (!coercible((yyvsp[-2].listAndType).eletype, (yyvsp[0].listAndType).eletype)) semanticError("arrays should be initialized with same datatype");else (yyval.listAndType).eletype = (yyvsp[-2].listAndType).eletype;}
#line 2302 "parser.tab.c"
    break;

  case 116:
#line 344 "parser.y"
                             {(yyval.listAndType).dimList = new vector<int>; addFrontAndCopy((yyval.listAndType).dimList, (yyvsp[0].listAndType).dimList, 1);delete (yyvsp[0].listAndType).dimList;(yyval.listAndType).eletype = (yyvsp[0].listAndType).eletype;}
#line 2308 "parser.tab.c"
    break;

  case 117:
#line 347 "parser.y"
                             {(yyval.countAndType).count = (yyvsp[0].countAndType).count;(yyval.countAndType).eletype = (yyvsp[0].countAndType).eletype;}
#line 2314 "parser.tab.c"
    break;

  case 118:
#line 348 "parser.y"
                           {(yyval.countAndType).count = 0;(yyval.countAndType).eletype = UNDEF;}
#line 2320 "parser.tab.c"
    break;

  case 119:
#line 351 "parser.y"
                                              {(yyval.countAndType).count = (yyvsp[-2].countAndType).count + 1; if (!coercible((yyvsp[-2].countAndType).eletype, (yyvsp[0].eletype))) semanticError("arrays should be initialized with same datatype");else (yyval.countAndType).eletype = (yyvsp[0].eletype);}
#line 2326 "parser.tab.c"
    break;

  case 120:
#line 352 "parser.y"
                           {(yyval.countAndType).count = 1;(yyval.countAndType).eletype = (yyvsp[0].eletype);}
#line 2332 "parser.tab.c"
    break;

  case 121:
#line 360 "parser.y"
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
#line 2350 "parser.tab.c"
    break;

  case 122:
#line 373 "parser.y"
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
#line 2367 "parser.tab.c"
    break;

  case 123:
#line 385 "parser.y"
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
#line 2384 "parser.tab.c"
    break;

  case 124:
#line 397 "parser.y"
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
#line 2400 "parser.tab.c"
    break;

  case 125:
#line 408 "parser.y"
                                   {if ((yyvsp[-2].constExp).eletype != INT || (yyvsp[0].constExp).eletype != INT) semanticError("Error: Semantic error incompatible datatype");(yyval.constExp).eletype = INT;
                                          (yyval.constExp).i = (yyvsp[-2].constExp).i % (yyvsp[0].constExp).i;
                                   }
#line 2408 "parser.tab.c"
    break;

  case 126:
#line 411 "parser.y"
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
#line 2425 "parser.tab.c"
    break;

  case 127:
#line 423 "parser.y"
                        {if (!arithCompatible((yyvsp[0].constExp).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.constExp).eletype = (yyvsp[0].constExp).eletype;

                            if ((yyval.constExp).eletype == REAL) 
                                   (yyval.constExp).d = -(yyvsp[0].constExp).d; 
                            else 
                                   (yyval.constExp).i = -(yyvsp[0].constExp).i;
                        }
#line 2437 "parser.tab.c"
    break;

  case 128:
#line 430 "parser.y"
                            {
                                   (yyval.constExp).eletype = (yyvsp[-1].constExp).eletype;
                                   if ((yyval.constExp).eletype == REAL) 
                                          (yyval.constExp).d = (yyvsp[-1].constExp).d; 
                                   else 
                                          (yyval.constExp).i = (yyvsp[-1].constExp).i;
                            }
#line 2449 "parser.tab.c"
    break;

  case 129:
#line 437 "parser.y"
                {(yyval.constExp).eletype = (yyvsp[0].constExp).eletype;(yyval.constExp).d = (yyvsp[0].constExp).d;}
#line 2455 "parser.tab.c"
    break;

  case 130:
#line 438 "parser.y"
                  {(yyval.constExp).eletype = (yyvsp[0].constExp).eletype;(yyval.constExp).i = (yyvsp[0].constExp).i;}
#line 2461 "parser.tab.c"
    break;

  case 131:
#line 439 "parser.y"
                 {(yyval.constExp).eletype = INT;(yyval.constExp).i = (yyvsp[0].constExp).i;}
#line 2467 "parser.tab.c"
    break;

  case 144:
#line 459 "parser.y"
                                              {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2473 "parser.tab.c"
    break;

  case 145:
#line 460 "parser.y"
                                                                {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2479 "parser.tab.c"
    break;

  case 146:
#line 461 "parser.y"
                                                                         {if(!(arithCompatible((yyvsp[-5].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2485 "parser.tab.c"
    break;

  case 147:
#line 462 "parser.y"
                                                        {if(!(arithCompatible((yyvsp[-3].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2491 "parser.tab.c"
    break;

  case 148:
#line 465 "parser.y"
                                                 {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2497 "parser.tab.c"
    break;

  case 149:
#line 466 "parser.y"
                                                          {if(!(arithCompatible((yyvsp[-2].eletype)))) semanticError("Error: Semantic error incompatible datatype");}
#line 2503 "parser.tab.c"
    break;

  case 159:
#line 477 "parser.y"
                         {(yyval.eletype) = (yyvsp[0].eletype);}
#line 2509 "parser.tab.c"
    break;

  case 160:
#line 477 "parser.y"
                                      {(yyval.eletype) = BOOL;}
#line 2515 "parser.tab.c"
    break;

  case 161:
#line 478 "parser.y"
                                                                                       {if(!(arithCompatible((yyvsp[-4].eletype)))) semanticError("Error: Semantic error incompatible datatype11"); cout<<"k";}
#line 2521 "parser.tab.c"
    break;


#line 2525 "parser.tab.c"

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
#line 483 "parser.y"


/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

void semanticError(const char* s){
       cerr << s << "at line no. "<<yylineno;
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
              cerr << "Error: Semantic error incompatible datatypes at line no."<<yylineno;
              exit(1);
       }
}

enum eletype arithTypeCheck(enum eletype E1, enum eletype E2  ){
       
       if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes at line no."<<yylineno;
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

       if (t1 == UNDEF || t2 == UNDEF)
              return true; // check where this function is used and make sure it doesn't cause problems

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
              
              
              if (!coercible(prevType, t))
              {
                     cerr << "Error: " << "types don't match in declaration and initialisation\n";
                     exit(1);
                     // error recovery
              }
              
              updateType(v->at(i), t);
              
              free(v->at(i));
       }

       delete v;

       printSymbolTable();

       return;
}

void insertArray(char* name, vector <int>* dimList){

       insertType(name, Array, UNDEF);
       addDimList(name, *dimList);
       
}

void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList){

       if (decDimList->size() != assignList->size()){

              cerr << "Error: arrays declaration and initialization list don't match\n";
              exit(1); // not freeing anything
       }

       if ((*decDimList)[0] == -1)
             (*decDimList)[0] = (*assignList)[0];

       for (int i = 0;i < decDimList->size();i++){

              if ((*decDimList)[i] < (*assignList)[i]){
                     cerr << "Error: arrays declaration and initialization list don't match\n";
                     exit(1); // not freeing anything
              }
       } 

       insertType(name, Array, e);
       addDimList(name, *decDimList);

       return;
}

void updateMaxDim(vector<int>* comma, vector<int>* assign){

       if (comma->size() != assign->size()+1){

              cerr << "Error: invaid array initializer list\n";
              exit(1); // remove this only if added length checks in declarations O/W segfault 
       }

       for (int i = 0;i < assign->size();i++){

              (*comma)[i+1] = max((*comma)[i+1], (*assign)[i]);
       }

       (*comma)[0] = (*comma)[0] + 1;

       return;
}

/*  eletype can be TRI, CIRCLE, LINE .. as well from identifiers */

enum eletype diffTypeCheck(enum eletype E1, enum eletype E2){

       if (E1 == POINT && E2 == POINT)
              return POINT;
       else if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes at line no."<<yylineno;
              exit(1); // Change Later
       }
}

enum eletype mulTypeCheck(enum eletype E1, enum eletype E2){

       if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes at line no."<<yylineno;
              exit(1); // Change Later
       }
}

void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x){

       dest->push_back(x);

       for (int i = 0;i < src->size();i++)
              dest->push_back(src->at(i));
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
