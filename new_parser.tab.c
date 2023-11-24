/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
string center = "Point(0,0)";

enum eletype ret_type = UNDEF;

vector<ParamList> paramslist;
STentry typelist;
vector<types> params;
vector<types> construct_params;
vector<ParamList> func_paramlist;

string totalProgram;


#line 140 "new_parser.tab.c"

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

#include "new_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGERS = 3,                   /* INTEGERS  */
  YYSYMBOL_BOOLEAN = 4,                    /* BOOLEAN  */
  YYSYMBOL_FLOATS = 5,                     /* FLOATS  */
  YYSYMBOL_LINE_OP = 6,                    /* LINE_OP  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELIF = 8,                       /* ELIF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 15,                     /* BREAK  */
  YYSYMBOL_PARALLEL = 16,                  /* PARALLEL  */
  YYSYMBOL_PERPENDICULAR = 17,             /* PERPENDICULAR  */
  YYSYMBOL_FUNC = 18,                      /* FUNC  */
  YYSYMBOL_FIG = 19,                       /* FIG  */
  YYSYMBOL_UNARY = 20,                     /* UNARY  */
  YYSYMBOL_DATATYPE = 21,                  /* DATATYPE  */
  YYSYMBOL_CMP_OP = 22,                    /* CMP_OP  */
  YYSYMBOL_EQ_CMP_OP = 23,                 /* EQ_CMP_OP  */
  YYSYMBOL_ASSIGN_OP = 24,                 /* ASSIGN_OP  */
  YYSYMBOL_SUM_ASSIGN_OP = 25,             /* SUM_ASSIGN_OP  */
  YYSYMBOL_SUB_ASSIGN_OP = 26,             /* SUB_ASSIGN_OP  */
  YYSYMBOL_EQUAL = 27,                     /* EQUAL  */
  YYSYMBOL_STRING_TOKEN = 28,              /* STRING_TOKEN  */
  YYSYMBOL_ENDLINE = 29,                   /* ENDLINE  */
  YYSYMBOL_ID = 30,                        /* ID  */
  YYSYMBOL_TRICONSTRUCT = 31,              /* TRICONSTRUCT  */
  YYSYMBOL_CIRCLECONSTRUCT = 32,           /* CIRCLECONSTRUCT  */
  YYSYMBOL_PARACONSTRUCT = 33,             /* PARACONSTRUCT  */
  YYSYMBOL_REGPOLYCONSTRUCT = 34,          /* REGPOLYCONSTRUCT  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_SCALE = 38,                     /* SCALE  */
  YYSYMBOL_CENTER = 39,                    /* CENTER  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_NEG = 47,                       /* NEG  */
  YYSYMBOL_48_ = 48,                       /* '^'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_57_ = 57,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_func = 60,                      /* func  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_arg_list = 65,                  /* arg_list  */
  YYSYMBOL_list1 = 66,                     /* list1  */
  YYSYMBOL_argument = 67,                  /* argument  */
  YYSYMBOL_fig = 68,                       /* fig  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_params = 70,                    /* params  */
  YYSYMBOL_stmt = 71,                      /* stmt  */
  YYSYMBOL_stmt_list = 72,                 /* stmt_list  */
  YYSYMBOL_stmt_block = 73,                /* stmt_block  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_stmt_block_for = 75,            /* stmt_block_for  */
  YYSYMBOL_break_stmt = 76,                /* break_stmt  */
  YYSYMBOL_return_stmt = 77,               /* return_stmt  */
  YYSYMBOL_ret_var = 78,                   /* ret_var  */
  YYSYMBOL_assign_stmt = 79,               /* assign_stmt  */
  YYSYMBOL_line_op = 80,                   /* line_op  */
  YYSYMBOL_lineArr = 81,                   /* lineArr  */
  YYSYMBOL_construct = 82,                 /* construct  */
  YYSYMBOL_constructor = 83,               /* constructor  */
  YYSYMBOL_valid_arg = 84,                 /* valid_arg  */
  YYSYMBOL_param_list = 85,                /* param_list  */
  YYSYMBOL_construct_param_list = 86,      /* construct_param_list  */
  YYSYMBOL_point = 87,                     /* point  */
  YYSYMBOL_vertex = 88,                    /* vertex  */
  YYSYMBOL_angle = 89,                     /* angle  */
  YYSYMBOL_expression = 90,                /* expression  */
  YYSYMBOL_inside_norm = 91,               /* inside_norm  */
  YYSYMBOL_assign = 92,                    /* assign  */
  YYSYMBOL_decl_stmt = 93,                 /* decl_stmt  */
  YYSYMBOL_id_list = 94,                   /* id_list  */
  YYSYMBOL_decl_assign = 95,               /* decl_assign  */
  YYSYMBOL_decl_token = 96,                /* decl_token  */
  YYSYMBOL_check_arr = 97,                 /* check_arr  */
  YYSYMBOL_dim = 98,                       /* dim  */
  YYSYMBOL_arr_assign = 99,                /* arr_assign  */
  YYSYMBOL_comma_arr_assign = 100,         /* comma_arr_assign  */
  YYSYMBOL_arr1d_in_list = 101,            /* arr1d_in_list  */
  YYSYMBOL_mult_elements = 102,            /* mult_elements  */
  YYSYMBOL_const_expr = 103,               /* const_expr  */
  YYSYMBOL_member_access = 104,            /* member_access  */
  YYSYMBOL_memb_access = 105,              /* memb_access  */
  YYSYMBOL_arr_access = 106,               /* arr_access  */
  YYSYMBOL_func_call = 107,                /* func_call  */
  YYSYMBOL_108_7 = 108,                    /* $@7  */
  YYSYMBOL_param_list_opt = 109,           /* param_list_opt  */
  YYSYMBOL_empty_space = 110,              /* empty_space  */
  YYSYMBOL_cond_stmt = 111,                /* cond_stmt  */
  YYSYMBOL_elif_stmt = 112,                /* elif_stmt  */
  YYSYMBOL_loop = 113,                     /* loop  */
  YYSYMBOL_for_loop_decl = 114,            /* for_loop_decl  */
  YYSYMBOL_115_8 = 115,                    /* $@8  */
  YYSYMBOL_116_9 = 116,                    /* $@9  */
  YYSYMBOL_optional_arg = 117,             /* optional_arg  */
  YYSYMBOL_for_loop = 118,                 /* for_loop  */
  YYSYMBOL_while_loop = 119                /* while_loop  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   1003

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,   195,   195,   196,   197,   211,   223,   223,   223,   252,
     252,   252,   278,   279,   282,   283,   286,   297,   315,   315,
     330,   338,   349,   350,   351,   352,   353,   354,   355,   356,
     359,   365,   368,   368,   377,   386,   387,   391,   393,   394,
     395,   398,   399,   403,   404,   407,   408,   436,   437,   440,
     441,   442,   443,   446,   447,   450,   461,   474,   486,   502,
     503,   507,   509,   512,   513,   516,   517,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   554,   555,   559,   560,   561,
     562,   566,   567,   570,   578,   586,   594,   602,   610,   619,
     629,   630,   633,   634,   638,   639,   640,   643,   653,   667,
     675,   684,   693,   704,   705,   708,   717,   720,   734,   748,
     761,   775,   780,   793,   803,   812,   813,   814,   819,   833,
     842,   854,   855,   858,   858,   891,   892,   895,   896,   901,
     909,   916,   923,   932,   939,   951,   952,   955,   955,   962,
     962,   969,   972,   973,   976,   983
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGERS", "BOOLEAN",
  "FLOATS", "LINE_OP", "IF", "ELIF", "ELSE", "FOR", "WHILE", "RETURN",
  "VOID", "CONTINUE", "BREAK", "PARALLEL", "PERPENDICULAR", "FUNC", "FIG",
  "UNARY", "DATATYPE", "CMP_OP", "EQ_CMP_OP", "ASSIGN_OP", "SUM_ASSIGN_OP",
  "SUB_ASSIGN_OP", "EQUAL", "STRING_TOKEN", "ENDLINE", "ID",
  "TRICONSTRUCT", "CIRCLECONSTRUCT", "PARACONSTRUCT", "REGPOLYCONSTRUCT",
  "NOT", "AND", "OR", "SCALE", "CENTER", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "NEG", "'^'", "'('", "')'", "','", "'{'", "'}'", "'['",
  "']'", "'.'", "'|'", "$accept", "program", "func", "$@1", "$@2", "$@3",
  "$@4", "arg_list", "list1", "argument", "fig", "$@5", "params", "stmt",
  "stmt_list", "stmt_block", "$@6", "stmt_block_for", "break_stmt",
  "return_stmt", "ret_var", "assign_stmt", "line_op", "lineArr",
  "construct", "constructor", "valid_arg", "param_list",
  "construct_param_list", "point", "vertex", "angle", "expression",
  "inside_norm", "assign", "decl_stmt", "id_list", "decl_assign",
  "decl_token", "check_arr", "dim", "arr_assign", "comma_arr_assign",
  "arr1d_in_list", "mult_elements", "const_expr", "member_access",
  "memb_access", "arr_access", "func_call", "$@7", "param_list_opt",
  "empty_space", "cond_stmt", "elif_stmt", "loop", "for_loop_decl", "$@8",
  "$@9", "optional_arg", "for_loop", "while_loop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-193)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -193,   312,  -193,  -193,  -193,  -193,   -43,   -28,    -4,   457,
      23,    29,    33,    34,    39,    45,    71,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   507,    33,   507,   507,  -193,  -193,
    -193,  -193,    51,  -193,  -193,  -193,    83,    70,  -193,  -193,
     868,  -193,    12,    62,  -193,  -193,  -193,  -193,  -193,   507,
      -8,   507,    92,  -193,    88,   901,  -193,  -193,   507,  -193,
      98,   131,  -193,   118,   121,  -193,  -193,    -3,   -16,   100,
    -193,    33,   104,   523,  -193,  -193,   416,     2,   507,   507,
     507,   507,   507,  -193,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,  -193,   507,   507,   507,   507,  -193,
     108,   129,   704,   109,   151,   152,   745,  -193,   605,    33,
    -193,  -193,  -193,   134,   457,    67,  -193,   157,   138,  -193,
     161,   507,    33,  -193,   507,   183,  -193,  -193,  -193,    93,
     901,  -193,    61,   928,   133,    -2,   591,   328,   955,    -2,
      -2,    61,    61,   104,   104,   104,   104,   901,   901,   901,
     901,   457,  -193,  -193,   507,   166,   173,  -193,  -193,   153,
     156,   479,  -193,   901,  -193,  -193,  -193,  -193,    25,    25,
     147,   248,    78,    25,    -3,   342,   -24,   564,  -193,  -193,
    -193,   457,  -193,   155,   158,   100,   180,   901,   162,   193,
     507,   180,   189,   189,   194,   172,   638,    87,   488,    25,
     138,    25,    25,    25,    25,    25,    25,  -193,   388,    13,
     221,  -193,   357,  -193,   201,  -193,  -193,   225,  -193,   202,
    -193,   457,  -193,  -193,   205,   507,   507,   901,  -193,   207,
    -193,   187,  -193,  -193,   507,  -193,   507,  -193,    87,    87,
     191,   191,   191,   191,   901,  -193,    14,   178,   192,  -193,
    -193,    33,    33,  -193,   190,   211,   198,  -193,   120,   204,
     901,   209,   214,   189,   215,   671,   180,   901,   190,  -193,
    -193,   507,  -193,  -193,  -193,  -193,  -193,   206,  -193,   137,
    -193,  -193,  -193,  -193,  -193,   220,  -193,  -193,   901,   507,
     180,   219,  -193,   -18,   180,   180,   242,   786,   243,   507,
     180,  -193,  -193,  -193,  -193,   507,  -193,  -193,   827,   244,
     246,   901,   180,  -193,  -193,  -193,   253,   180,  -193,   254,
    -193
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    32,     1,    89,    90,    88,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,    91,    27,   142,
      49,    50,    51,    52,     0,     0,     0,     0,     2,     3,
       4,    28,     0,    29,    26,    25,     0,     0,    93,    94,
       0,    24,    86,   138,    92,    22,    23,   155,   156,     0,
     157,     0,     0,    38,     0,    39,    36,    35,     0,    62,
      96,     0,    61,     0,     0,    18,    76,   111,     0,   140,
      78,     0,    75,     0,    31,    42,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,     0,    81,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
      74,     9,     6,     0,     0,     0,   109,   106,   114,   101,
       0,     0,     0,    87,     0,    32,    48,    53,    58,     0,
      54,   102,    67,    72,    73,    82,    85,    79,    80,    83,
      84,    65,    66,    68,    69,    70,    71,    98,    99,   100,
      97,   146,   142,   148,   163,     0,     0,   148,    95,     0,
       0,     0,   112,   113,   110,   136,   137,   135,     0,     0,
     115,     0,     0,     0,   111,     0,     0,     0,    33,    30,
      47,     0,    56,   145,     0,   139,    32,   162,     0,     0,
       0,    32,    13,    13,     0,     0,     0,   133,     0,     0,
     116,     0,     0,     0,     0,     0,     0,   118,   124,   108,
       0,   107,     0,   105,   104,   141,    64,     0,    60,     0,
      57,     0,   144,   147,     0,   163,     0,   160,   165,     0,
      10,    12,    15,     7,     0,   148,     0,   134,   127,   128,
     129,   130,   131,   132,   126,   122,     0,     0,   123,    43,
      44,     0,     0,   117,     0,     0,     0,    55,   149,     0,
     158,    17,     0,     0,     0,     0,    32,    20,     0,   120,
     119,     0,    45,    46,   103,    63,    59,     0,   148,   152,
     148,    16,   148,    14,   148,     0,    19,   121,   125,     0,
      32,     0,   148,     0,    32,    32,     0,     0,     0,     0,
      32,    31,   164,    11,     8,     0,   148,   150,     0,     0,
      32,    21,    32,   148,   151,    34,     0,    32,   153,     0,
     154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,  -193,  -193,  -193,  -193,    91,  -193,     8,
    -193,  -193,  -193,   284,   -14,  -132,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,     0,     1,  -148,  -193,  -193,    -7,
     -11,  -193,    -1,  -193,  -193,  -193,   260,   126,  -193,  -162,
     132,  -192,  -193,  -193,  -193,   266,    -5,  -193,   149,  -193,
    -193,  -193,  -142,  -193,  -193,  -193,  -193,  -193,  -193,    80,
    -193,  -193
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   160,   264,   159,   262,   230,   231,   232,
      29,   113,   195,   179,   125,    31,    32,   302,    33,    34,
      52,    35,   251,   209,   127,    54,   128,   183,   129,    38,
      60,    39,   130,    61,    99,    41,    68,   116,   164,   117,
     118,   211,   246,   247,   248,   171,    42,    43,    69,    44,
     100,   184,   186,    45,   279,    46,   103,   104,   105,   188,
      47,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    36,    37,   182,    78,    59,    49,    62,    55,    53,
      66,   223,   214,   119,    71,   191,   245,   216,    59,   249,
      62,    50,  -159,    70,   114,    72,    73,   217,   165,   166,
     167,   131,    94,   220,   301,   120,    95,    96,    97,    98,
      88,    89,    90,    91,    92,    51,    93,    63,   102,  -161,
     106,   115,    56,   120,   224,    64,   250,   108,    57,   228,
     122,  -143,   274,    19,    59,   268,    62,   269,   168,    65,
     165,   166,   167,   257,   169,    19,   287,   132,   133,   134,
     135,   136,    58,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   266,   147,   148,   149,   150,   158,   281,
      67,    67,    59,    74,    62,    90,    91,    92,    19,    93,
     168,   176,    75,   163,   162,    59,   169,    62,   101,    76,
     175,   107,   170,   177,    40,    36,    37,    58,   277,   278,
     208,   203,   204,   205,   286,   206,   290,    76,   293,    78,
     294,   109,   295,   180,   181,   291,   292,   110,   111,    79,
     300,   112,    93,   187,   121,    81,    82,   151,   298,   152,
     196,   210,   303,   304,   312,    59,   154,    62,   309,    84,
      85,   317,   155,    86,    87,    88,    89,    90,    91,    92,
     316,    93,   156,   161,   172,   319,     3,     4,     5,   227,
       6,   174,   173,     7,     8,     9,   189,    10,    11,    12,
     190,   199,   192,    15,    16,   193,   221,   244,   222,   223,
     229,    17,    18,    19,    20,    21,    22,    23,    24,   225,
     226,   234,   235,    25,   187,   260,    26,   252,   254,   255,
     256,   270,    27,   265,   258,   267,   178,   261,   263,   206,
     272,   273,   208,   271,    59,    59,    62,    62,   276,     3,
       4,     5,   275,     6,   280,   289,     7,     8,     9,   296,
      10,    11,    12,   115,   282,   284,    15,    16,   299,   305,
     288,   283,   307,   314,    17,    18,    19,    20,    21,    22,
      23,    24,   318,   320,   233,    30,    25,   310,   297,    26,
     201,   202,   203,   204,   205,    27,   206,    77,   308,   315,
     213,   185,   200,   207,   311,   259,     0,     0,     0,    40,
      36,    37,     2,     0,     0,     3,     4,     5,     0,     6,
       0,     0,     7,     8,     9,     0,    10,    11,    12,     0,
      13,    14,    15,    16,    78,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    78,     0,
      81,    82,    25,     0,     0,    26,     0,     0,    79,    80,
       0,    27,     0,     0,    81,    82,     0,     0,    86,    87,
      88,    89,    90,    91,    92,     0,    93,     0,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,     0,
      93,     3,     4,     5,     0,     0,     0,   215,     0,   201,
     202,   203,   204,   205,    12,   206,     0,     0,    15,     0,
       0,     0,   253,     0,     0,     0,    17,     0,    19,     3,
       4,     5,     0,    24,     0,     0,     0,     0,    25,     0,
       0,    26,    12,     0,   197,   198,    15,    27,     0,   212,
     208,     0,     0,     0,    17,     0,    19,    20,    21,    22,
      23,    24,     0,     0,     0,     0,    25,     0,     0,    26,
       3,     4,     5,     0,     0,    27,   126,   238,   239,   240,
     241,   242,   243,    12,     0,     0,     0,    15,     0,     0,
       0,     0,     3,     4,     5,    17,     0,    19,    20,    21,
      22,    23,    24,     0,     0,    12,     0,    25,     0,    15,
      26,     0,     0,     0,     0,     0,    27,    17,     0,    19,
       3,     4,     5,     0,    24,     0,     0,   194,     0,    25,
       0,     0,    26,    12,     0,     0,     0,    15,    27,    78,
     201,   202,   203,   204,   205,    17,   206,    19,   237,    79,
      80,     0,    24,     0,     0,    81,    82,    25,     0,     0,
      26,     0,     0,     0,     0,     0,    27,     0,     0,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      78,    93,     0,   123,   124,     0,     0,     0,     0,     0,
      79,    80,     0,     0,     0,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    78,    93,    81,   218,   219,     0,     0,     0,     0,
       0,    79,    80,     0,     0,     0,     0,    81,    82,     0,
       0,    86,    87,    88,    89,    90,    91,    92,     0,    93,
       0,    84,    85,     0,    78,    86,    87,    88,    89,    90,
      91,    92,     0,    93,    79,    80,   124,     0,     0,     0,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,    78,    86,    87,
      88,    89,    90,    91,    92,     0,    93,    79,    80,   236,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
      78,    86,    87,    88,    89,    90,    91,    92,     0,    93,
      79,    80,   285,     0,     0,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    78,    93,     0,   153,     0,     0,     0,     0,     0,
       0,    79,    80,     0,     0,     0,     0,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    78,    93,     0,   157,     0,     0,     0,     0,
       0,     0,    79,    80,     0,     0,     0,     0,    81,    82,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    78,    93,     0,   306,     0,     0,     0,
       0,     0,     0,    79,    80,     0,     0,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    78,    93,     0,   313,     0,     0,
       0,     0,     0,     0,    79,    80,     0,     0,     0,     0,
      81,    82,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,    84,    85,     0,    78,    86,    87,
      88,    89,    90,    91,    92,     0,    93,    79,    80,     0,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,     0,     0,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,     0,    93,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,    90,    91,    92,     0,    93,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,     0,    93
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,   151,     6,    12,    49,    12,     9,     9,
      15,    29,   174,    29,    25,   157,   208,    41,    25,     6,
      25,    49,    30,    24,    27,    26,    27,    51,     3,     4,
       5,    29,    20,   181,    52,    51,    24,    25,    26,    27,
      42,    43,    44,    45,    46,    49,    48,    13,    49,    57,
      51,    54,    29,    51,   186,    21,    43,    58,    29,   191,
      71,    49,   254,    30,    71,    51,    71,    53,    43,    30,
       3,     4,     5,   221,    49,    30,   268,    78,    79,    80,
      81,    82,    49,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   235,    95,    96,    97,    98,   109,   261,
      30,    30,   109,    52,   109,    44,    45,    46,    30,    48,
      43,   122,    29,   114,   114,   122,    49,   122,    56,    49,
     121,    29,    55,   124,   125,   125,   125,    49,     8,     9,
      52,    44,    45,    46,   266,    48,   278,    49,   280,     6,
     282,    43,   284,    50,    51,     8,     9,    16,    30,    16,
     292,    30,    48,   154,    54,    22,    23,    49,   290,    30,
     161,   172,   294,   295,   306,   172,    57,   172,   300,    36,
      37,   313,    21,    40,    41,    42,    43,    44,    45,    46,
     312,    48,    30,    49,    27,   317,     3,     4,     5,   190,
       7,    30,    54,    10,    11,    12,    30,    14,    15,    16,
      27,    54,    49,    20,    21,    49,    51,   208,    50,    29,
      21,    28,    29,    30,    31,    32,    33,    34,    35,    57,
      27,    27,    50,    40,   225,   226,    43,     6,    27,     4,
      28,    53,    49,   234,    29,   236,    53,    30,    51,    48,
     251,   252,    52,    51,   251,   252,   251,   252,    50,     3,
       4,     5,    41,     7,    50,    49,    10,    11,    12,    39,
      14,    15,    16,    54,    50,    50,    20,    21,    49,    27,
     271,   263,    29,    29,    28,    29,    30,    31,    32,    33,
      34,    35,    29,    29,   193,     1,    40,   301,   289,    43,
      42,    43,    44,    45,    46,    49,    48,    37,   299,    53,
     174,   152,   170,    55,   305,   225,    -1,    -1,    -1,   310,
     310,   310,     0,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    10,    11,    12,    -1,    14,    15,    16,    -1,
      18,    19,    20,    21,     6,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,     6,    -1,
      22,    23,    40,    -1,    -1,    43,    -1,    -1,    16,    17,
      -1,    49,    -1,    -1,    22,    23,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,     3,     4,     5,    -1,    -1,    -1,    55,    -1,    42,
      43,    44,    45,    46,    16,    48,    -1,    -1,    20,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    28,    -1,    30,     3,
       4,     5,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    43,    16,    -1,   168,   169,    20,    49,    -1,   173,
      52,    -1,    -1,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    43,
       3,     4,     5,    -1,    -1,    49,    50,   201,   202,   203,
     204,   205,   206,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,     3,     4,     5,    28,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    16,    -1,    40,    -1,    20,
      43,    -1,    -1,    -1,    -1,    -1,    49,    28,    -1,    30,
       3,     4,     5,    -1,    35,    -1,    -1,    38,    -1,    40,
      -1,    -1,    43,    16,    -1,    -1,    -1,    20,    49,     6,
      42,    43,    44,    45,    46,    28,    48,    30,    50,    16,
      17,    -1,    35,    -1,    -1,    22,    23,    40,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
       6,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     6,    48,    22,    50,    51,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    36,    37,    -1,     6,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    16,    17,    51,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,     6,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    16,    17,    51,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
       6,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      16,    17,    51,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     6,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,     6,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,     6,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,     6,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,     6,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,    -1,    -1,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,    -1,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     3,     4,     5,     7,    10,    11,    12,
      14,    15,    16,    18,    19,    20,    21,    28,    29,    30,
      31,    32,    33,    34,    35,    40,    43,    49,    60,    68,
      71,    73,    74,    76,    77,    79,    82,    83,    87,    89,
      90,    93,   104,   105,   107,   111,   113,   118,   119,    49,
      49,    49,    78,    82,    83,    90,    29,    29,    49,    87,
      88,    91,   104,    13,    21,    30,   104,    30,    94,   106,
      90,    88,    90,    90,    52,    29,    49,    94,     6,    16,
      17,    22,    23,    29,    36,    37,    40,    41,    42,    43,
      44,    45,    46,    48,    20,    24,    25,    26,    27,    92,
     108,    56,    90,   114,   115,   116,    90,    29,    90,    43,
      16,    30,    30,    69,    27,    54,    95,    97,    98,    29,
      51,    54,    88,    50,    51,    72,    50,    82,    84,    86,
      90,    29,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    49,    30,    50,    57,    21,    30,    50,    88,    63,
      61,    49,    82,    90,    96,     3,     4,     5,    43,    49,
      55,   103,    27,    54,    30,    90,    88,    90,    53,    71,
      50,    51,    84,    85,   109,   106,   110,    90,   117,    30,
      27,   110,    49,    49,    38,    70,    90,   103,   103,    54,
      98,    42,    43,    44,    45,    46,    48,    55,    52,    81,
      88,    99,   103,    95,    97,    55,    41,    51,    50,    51,
      84,    51,    50,    29,    73,    57,    27,    90,    73,    21,
      65,    66,    67,    65,    27,    50,    51,    50,   103,   103,
     103,   103,   103,   103,    90,    99,   100,   101,   102,     6,
      43,    80,     6,    55,    27,     4,    28,    84,    29,   117,
      90,    30,    64,    51,    62,    90,   110,    90,    51,    53,
      53,    51,    88,    88,    99,    41,    50,     8,     9,   112,
      50,    97,    50,    67,    50,    51,    73,    99,    90,    49,
     110,     8,     9,   110,   110,   110,    39,    90,    73,    49,
     110,    52,    75,    73,    73,    27,    50,    29,    90,    73,
      72,    90,   110,    50,    29,    53,    73,   110,    29,    73,
      29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    61,    62,    60,    63,
      64,    60,    65,    65,    66,    66,    67,    67,    69,    68,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    74,    73,    75,    76,    76,    77,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   105,
     105,   106,   106,   108,   107,   109,   109,   110,   110,   111,
     111,   111,   111,   112,   112,   113,   113,   115,   114,   116,
     114,   114,   117,   117,   118,   119
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: program func  */
#line 195 "new_parser.y"
                      {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;cout << "hello: " << *(yyval.main).text << "\n";totalProgram = *(yyval.main).text;}
#line 1610 "new_parser.tab.c"
    break;

  case 3: /* program: program fig  */
#line 196 "new_parser.y"
                     {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text; totalProgram = *(yyval.main).text;}
#line 1616 "new_parser.tab.c"
    break;

  case 4: /* program: program stmt  */
#line 197 "new_parser.y"
                       {
              (yyval.main).text = new string;
              if ((yyvsp[0].main).stopAdvanceFound) 
                     semanticError("stop/advance cannot be outside the loop");
              if(is_decl_stmt) {
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
                     is_decl_stmt = 0;
                     totalProgram = totalProgram + *(yyval.main).text;
              }
              else {
                     collection.push_back(*(yyvsp[0].main).text);
              }
              
              }
#line 1635 "new_parser.tab.c"
    break;

  case 5: /* program: %empty  */
#line 211 "new_parser.y"
                     {
              if(ret_flag) {
                     cerr << "Error: Return statement not allowed outside function" << endl;
              }
              (yyval.main).text = new string;
              *(yyval.main).text = "";
              totalProgram = *(yyval.main).text;
         }
#line 1648 "new_parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 223 "new_parser.y"
                         { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype); addSymTabPtr(); }
#line 1654 "new_parser.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 223 "new_parser.y"
                                                                                                 {
                     if(paramslist.size()>0) {
                            addParamList((yyvsp[-3].main).name,paramslist);
                            insertParams(paramslist);
                            paramslist.clear();
                     }
              }
#line 1666 "new_parser.tab.c"
    break;

  case 8: /* func: FUNC DATATYPE ID $@1 '(' arg_list $@2 ')' empty_space stmt_block  */
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
#line 1693 "new_parser.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 252 "new_parser.y"
                              { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype);  addSymTabPtr(); }
#line 1699 "new_parser.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 252 "new_parser.y"
                                                                                                       {if(paramslist.size()>0) {
                     addParamList((yyvsp[-3].main).name,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
#line 1709 "new_parser.tab.c"
    break;

  case 11: /* func: FUNC VOID ID $@3 '(' arg_list $@4 ')' empty_space stmt_block  */
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
#line 1733 "new_parser.tab.c"
    break;

  case 12: /* arg_list: list1  */
#line 278 "new_parser.y"
                 {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 1739 "new_parser.tab.c"
    break;

  case 13: /* arg_list: %empty  */
#line 279 "new_parser.y"
                       {(yyval.main).text = new string;*(yyval.main).text = "";}
#line 1745 "new_parser.tab.c"
    break;

  case 14: /* list1: list1 ',' argument  */
#line 282 "new_parser.y"
                          {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text;}
#line 1751 "new_parser.tab.c"
    break;

  case 15: /* list1: argument  */
#line 283 "new_parser.y"
                  {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 1757 "new_parser.tab.c"
    break;

  case 16: /* argument: DATATYPE ID check_arr  */
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
#line 1773 "new_parser.tab.c"
    break;

  case 17: /* argument: DATATYPE ID  */
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
#line 1791 "new_parser.tab.c"
    break;

  case 18: /* $@5: %empty  */
#line 315 "new_parser.y"
            {insertType((yyvsp[0].main).name, Fig, UNDEF); addSymTabPtr();}
#line 1797 "new_parser.tab.c"
    break;

  case 19: /* fig: FIG ID $@5 '(' params ')' empty_space stmt_block  */
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
                                                        *(yyval.main).text = "void" + *(yyvsp[-6].main).text + "(" + *(yyvsp[-3].main).text + ")" + *((yyvsp[-1].main).text) + *((yyvsp[0].main).text);
                                                 }
#line 1816 "new_parser.tab.c"
    break;

  case 20: /* params: expression ',' expression  */
#line 330 "new_parser.y"
                                   { 
              if(!(arithCompatible((yyvsp[-2].main).eletype) && (yyvsp[0].main).eletype == POINT)) 
                     semanticError("Error: Semantic error incompatible datatype..") ;
              scale = *(yyvsp[-2].main).text;
              center = centerTranslation(*(yyvsp[0].main).text);
              (yyval.main).text = new string;
              *(yyval.main).text = "double scale = " + *(yyvsp[-2].main).text + " , Point center = " + *(yyvsp[0].main).text; 
       }
#line 1829 "new_parser.tab.c"
    break;

  case 21: /* params: SCALE EQUAL expression ',' CENTER EQUAL expression  */
#line 338 "new_parser.y"
                                                            { 
              if(!(arithCompatible((yyvsp[-4].main).eletype) && (yyvsp[0].main).eletype == POINT)) 
                     semanticError("Error: Semantic error incompatible datatype") ;
              scale = *(yyvsp[-4].main).text;
              center = centerTranslation(*(yyvsp[-4].main).text);
              // *$$.text = "double scale = " + (*$3.text) ", Point center = " + (*$7.text); 
              (yyval.main).text = new string;
              *(yyval.main).text = "double scale , Point center" ; 
       }
#line 1843 "new_parser.tab.c"
    break;

  case 22: /* stmt: cond_stmt  */
#line 349 "new_parser.y"
                 {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 1849 "new_parser.tab.c"
    break;

  case 23: /* stmt: loop  */
#line 350 "new_parser.y"
                {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 1855 "new_parser.tab.c"
    break;

  case 24: /* stmt: decl_stmt  */
#line 351 "new_parser.y"
                 {(yyval.main).stopAdvanceFound = false;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text; is_decl_stmt = 1;}
#line 1861 "new_parser.tab.c"
    break;

  case 25: /* stmt: assign_stmt  */
#line 352 "new_parser.y"
                   {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 1867 "new_parser.tab.c"
    break;

  case 26: /* stmt: return_stmt  */
#line 353 "new_parser.y"
                   {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 1873 "new_parser.tab.c"
    break;

  case 27: /* stmt: ENDLINE  */
#line 354 "new_parser.y"
                  {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text ;}
#line 1879 "new_parser.tab.c"
    break;

  case 28: /* stmt: stmt_block  */
#line 355 "new_parser.y"
                  {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 1885 "new_parser.tab.c"
    break;

  case 29: /* stmt: break_stmt  */
#line 356 "new_parser.y"
                  {(yyval.main).stopAdvanceFound = true; (yyval.main).text = new string;*(yyval.main).text= *(yyvsp[0].main).text ;}
#line 1891 "new_parser.tab.c"
    break;

  case 30: /* stmt_list: stmt_list stmt  */
#line 360 "new_parser.y"
       {
              (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound || (yyvsp[0].main).stopAdvanceFound;
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 1901 "new_parser.tab.c"
    break;

  case 31: /* stmt_list: %empty  */
#line 365 "new_parser.y"
                      {(yyval.main).stopAdvanceFound = false; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 1907 "new_parser.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 368 "new_parser.y"
            { addSymTabPtr(); }
#line 1913 "new_parser.tab.c"
    break;

  case 33: /* stmt_block: $@6 '{' stmt_list '}'  */
#line 369 "new_parser.y"
              { 
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     delSymTabPtr(); 
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}" ;
              }
#line 1924 "new_parser.tab.c"
    break;

  case 34: /* stmt_block_for: '{' stmt_list '}'  */
#line 378 "new_parser.y"
              { 
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound; 
                     delSymTabPtr(); 
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}" ;
              }
#line 1935 "new_parser.tab.c"
    break;

  case 35: /* break_stmt: BREAK ENDLINE  */
#line 386 "new_parser.y"
                            {(yyval.main).text = new string;*(yyval.main).text = "break;\n";}
#line 1941 "new_parser.tab.c"
    break;

  case 36: /* break_stmt: CONTINUE ENDLINE  */
#line 387 "new_parser.y"
                              { (yyval.main).text = new string;*(yyval.main).text = "continue;\n";}
#line 1947 "new_parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN ret_var ENDLINE  */
#line 391 "new_parser.y"
                                     {ret_type = (yyvsp[-1].main).eletype; ret_flag = 1; ret_fig_flag = 1; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";"; }
#line 1953 "new_parser.tab.c"
    break;

  case 38: /* ret_var: construct  */
#line 393 "new_parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text; }
#line 1959 "new_parser.tab.c"
    break;

  case 39: /* ret_var: expression  */
#line 394 "new_parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 1965 "new_parser.tab.c"
    break;

  case 40: /* ret_var: %empty  */
#line 395 "new_parser.y"
                     {(yyval.main).eletype = Void; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 1971 "new_parser.tab.c"
    break;

  case 41: /* assign_stmt: expression ENDLINE  */
#line 398 "new_parser.y"
                                 {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + ";";}
#line 1977 "new_parser.tab.c"
    break;

  case 42: /* assign_stmt: construct ENDLINE  */
#line 399 "new_parser.y"
                                 {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + ";";}
#line 1983 "new_parser.tab.c"
    break;

  case 43: /* line_op: LINE_OP  */
#line 403 "new_parser.y"
                 {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 1989 "new_parser.tab.c"
    break;

  case 44: /* line_op: '-'  */
#line 404 "new_parser.y"
                 {(yyval.main).text = new string; *(yyval.main).text = "-";}
#line 1995 "new_parser.tab.c"
    break;

  case 45: /* lineArr: lineArr line_op vertex  */
#line 407 "new_parser.y"
                                {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[-2].main).text + "|" + *(yyvsp[-1].main).text + "|" + *(yyvsp[0].main).text;}
#line 2001 "new_parser.tab.c"
    break;

  case 46: /* lineArr: vertex LINE_OP vertex  */
#line 408 "new_parser.y"
                               {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "|" + *(yyvsp[-1].main).text + "|" + *(yyvsp[0].main).text;}
#line 2007 "new_parser.tab.c"
    break;

  case 47: /* construct: constructor '(' construct_param_list ')'  */
#line 436 "new_parser.y"
                                                      {(yyval.main).eletype = (yyvsp[-3].main).eletype; construct_params.clear(); (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-3].main).text + "(" + *(yyvsp[-1].main).text + "," + scale + "," + center + ")" ;}
#line 2013 "new_parser.tab.c"
    break;

  case 48: /* construct: constructor '(' ')'  */
#line 437 "new_parser.y"
                                {(yyval.main).eletype = (yyvsp[-2].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "(" + scale + "," + center + ")" ;}
#line 2019 "new_parser.tab.c"
    break;

  case 49: /* constructor: TRICONSTRUCT  */
#line 440 "new_parser.y"
                           { (yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2025 "new_parser.tab.c"
    break;

  case 50: /* constructor: CIRCLECONSTRUCT  */
#line 441 "new_parser.y"
                              { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2031 "new_parser.tab.c"
    break;

  case 51: /* constructor: PARACONSTRUCT  */
#line 442 "new_parser.y"
                            { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2037 "new_parser.tab.c"
    break;

  case 52: /* constructor: REGPOLYCONSTRUCT  */
#line 443 "new_parser.y"
                               { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ;}
#line 2043 "new_parser.tab.c"
    break;

  case 53: /* valid_arg: construct  */
#line 446 "new_parser.y"
                     {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2049 "new_parser.tab.c"
    break;

  case 54: /* valid_arg: expression  */
#line 447 "new_parser.y"
                      {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2055 "new_parser.tab.c"
    break;

  case 55: /* param_list: param_list ',' valid_arg  */
#line 450 "new_parser.y"
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
#line 2071 "new_parser.tab.c"
    break;

  case 56: /* param_list: valid_arg  */
#line 461 "new_parser.y"
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
#line 2087 "new_parser.tab.c"
    break;

  case 57: /* construct_param_list: construct_param_list ',' valid_arg  */
#line 474 "new_parser.y"
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
#line 2104 "new_parser.tab.c"
    break;

  case 58: /* construct_param_list: valid_arg  */
#line 486 "new_parser.y"
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
#line 2122 "new_parser.tab.c"
    break;

  case 59: /* point: '(' expression ',' expression ',' STRING_TOKEN ')'  */
#line 502 "new_parser.y"
                                                            { (yyval.main).eletype = pointCheck((yyvsp[-5].main).eletype, (yyvsp[-3].main).eletype); (yyval.main).text = new string; *(yyval.main).text = "Point(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")"; }
#line 2128 "new_parser.tab.c"
    break;

  case 60: /* point: '(' expression ',' expression ')'  */
#line 503 "new_parser.y"
                                               { (yyval.main).eletype = pointCheck((yyvsp[-3].main).eletype, (yyvsp[-1].main).eletype);(yyval.main).text = new string;*(yyval.main).text = "Point(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text +  ")";}
#line 2134 "new_parser.tab.c"
    break;

  case 61: /* vertex: member_access  */
#line 507 "new_parser.y"
                      { if ((yyvsp[0].main).eletype != POINT) semanticError("Error: vertex has to be a point"); (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 2140 "new_parser.tab.c"
    break;

  case 62: /* vertex: point  */
#line 509 "new_parser.y"
                      { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 2146 "new_parser.tab.c"
    break;

  case 63: /* angle: '<' vertex vertex vertex ',' BOOLEAN '>'  */
#line 512 "new_parser.y"
                                                  {(yyval.main).eletype = ANGLE; (yyval.main).text = new string; *(yyval.main).text = "angleBetweenPoints(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-4].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")";}
#line 2152 "new_parser.tab.c"
    break;

  case 64: /* angle: '<' vertex vertex vertex '>'  */
#line 513 "new_parser.y"
                                      {(yyval.main).eletype = ANGLE; (yyval.main).text = new string; *(yyval.main).text = "angleBetweenPoints(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-2].main).text + "," + *(yyvsp[-1].main).text + ")";}
#line 2158 "new_parser.tab.c"
    break;

  case 65: /* expression: expression '+' expression  */
#line 516 "new_parser.y"
                                        {  (yyval.main).eletype = sumTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text;}
#line 2164 "new_parser.tab.c"
    break;

  case 66: /* expression: expression '-' expression  */
#line 517 "new_parser.y"
                                        {  (yyval.main).eletype = diffTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string;
                                            if ((yyval.main).eletype == LINE)
                                                 *(yyval.main).text = "Line(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")";
                                            else 
                                                 *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text;
                                         }
#line 2175 "new_parser.tab.c"
    break;

  case 67: /* expression: expression LINE_OP expression  */
#line 523 "new_parser.y"
                                            { (yyval.main).eletype = LINE;(yyval.main).text = new string; *(yyval.main).text = "Line(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")";}
#line 2181 "new_parser.tab.c"
    break;

  case 68: /* expression: expression '*' expression  */
#line 524 "new_parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "*" + *(yyvsp[0].main).text;}
#line 2187 "new_parser.tab.c"
    break;

  case 69: /* expression: expression '/' expression  */
#line 525 "new_parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[-2].main).text + "/" + *(yyvsp[0].main).text;}
#line 2193 "new_parser.tab.c"
    break;

  case 70: /* expression: expression '%' expression  */
#line 526 "new_parser.y"
                                        { if ((yyvsp[-2].main).eletype != INT || (yyvsp[0].main).eletype != INT) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = INT; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text;}
#line 2199 "new_parser.tab.c"
    break;

  case 71: /* expression: expression '^' expression  */
#line 527 "new_parser.y"
                                        { (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string;*(yyval.main).text = "pow(" + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + ")";}
#line 2205 "new_parser.tab.c"
    break;

  case 72: /* expression: expression PARALLEL expression  */
#line 528 "new_parser.y"
                                             { (yyval.main).eletype = parallelCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);(yyval.main).text = new string;*(yyval.main).text = "isParallel(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")" ; }
#line 2211 "new_parser.tab.c"
    break;

  case 73: /* expression: expression PERPENDICULAR expression  */
#line 529 "new_parser.y"
                                                   {(yyval.main).eletype = perpendicularCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); (yyval.main).text = new string; *(yyval.main).text = "isPerpendicular(" + *(yyvsp[-2].main).text + ", " + *(yyvsp[0].main).text + ")" ;}
#line 2217 "new_parser.tab.c"
    break;

  case 74: /* expression: PARALLEL inside_norm PARALLEL  */
#line 530 "new_parser.y"
                                             { (yyval.main).eletype = REAL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text;}
#line 2223 "new_parser.tab.c"
    break;

  case 75: /* expression: '-' expression  */
#line 531 "new_parser.y"
                                       {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = "-" + *(yyvsp[0].main).text;}
#line 2229 "new_parser.tab.c"
    break;

  case 76: /* expression: UNARY member_access  */
#line 532 "new_parser.y"
                                  {if(!((yyvsp[0].main).eletype == INT || (yyvsp[0].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2235 "new_parser.tab.c"
    break;

  case 77: /* expression: member_access UNARY  */
#line 533 "new_parser.y"
                                  {if(!((yyvsp[-1].main).eletype == INT || (yyvsp[-1].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2241 "new_parser.tab.c"
    break;

  case 78: /* expression: NOT expression  */
#line 534 "new_parser.y"
                             {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;(yyval.main).text = new string;*(yyval.main).text = "!" + *(yyvsp[-1].main).text;}
#line 2247 "new_parser.tab.c"
    break;

  case 79: /* expression: expression AND expression  */
#line 535 "new_parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "&&" + *(yyvsp[0].main).text; }
#line 2253 "new_parser.tab.c"
    break;

  case 80: /* expression: expression OR expression  */
#line 536 "new_parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "||" + *(yyvsp[0].main).text; }
#line 2259 "new_parser.tab.c"
    break;

  case 81: /* expression: member_access assign  */
#line 537 "new_parser.y"
                                         {if (!(((yyvsp[-1].main).eletype == (yyvsp[0].main).eletype) || coercible((yyvsp[-1].main).eletype, (yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = assignTranslation(*(yyvsp[0].main).text,*(yyvsp[-1].main).text);}
#line 2265 "new_parser.tab.c"
    break;

  case 82: /* expression: expression CMP_OP expression  */
#line 538 "new_parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2271 "new_parser.tab.c"
    break;

  case 83: /* expression: expression '<' expression  */
#line 539 "new_parser.y"
                                        { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + "<" + *(yyvsp[0].main).text; }
#line 2277 "new_parser.tab.c"
    break;

  case 84: /* expression: expression '>' expression  */
#line 540 "new_parser.y"
                                         { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + ">" + *(yyvsp[0].main).text; }
#line 2283 "new_parser.tab.c"
    break;

  case 85: /* expression: expression EQ_CMP_OP expression  */
#line 541 "new_parser.y"
                                              {if(!((arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) || ((yyvsp[-2].main).eletype == (yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2289 "new_parser.tab.c"
    break;

  case 86: /* expression: member_access  */
#line 542 "new_parser.y"
                            {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2295 "new_parser.tab.c"
    break;

  case 87: /* expression: '(' expression ')'  */
#line 543 "new_parser.y"
                                 {(yyval.main).eletype = (yyvsp[-1].main).eletype; (yyval.main).text = new string;*(yyval.main).text = "(" + *(yyvsp[-1].main).text + ")";}
#line 2301 "new_parser.tab.c"
    break;

  case 88: /* expression: FLOATS  */
#line 544 "new_parser.y"
                     {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2307 "new_parser.tab.c"
    break;

  case 89: /* expression: INTEGERS  */
#line 545 "new_parser.y"
                       {(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2313 "new_parser.tab.c"
    break;

  case 90: /* expression: BOOLEAN  */
#line 546 "new_parser.y"
                      { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2319 "new_parser.tab.c"
    break;

  case 91: /* expression: STRING_TOKEN  */
#line 547 "new_parser.y"
                           { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2325 "new_parser.tab.c"
    break;

  case 92: /* expression: func_call  */
#line 548 "new_parser.y"
                        {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2331 "new_parser.tab.c"
    break;

  case 93: /* expression: point  */
#line 549 "new_parser.y"
                    { (yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2337 "new_parser.tab.c"
    break;

  case 94: /* expression: angle  */
#line 550 "new_parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2343 "new_parser.tab.c"
    break;

  case 95: /* inside_norm: vertex '-' vertex  */
#line 554 "new_parser.y"
                                { (yyval.main).text = new string;*(yyval.main).text = "norm( " + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + " )";}
#line 2349 "new_parser.tab.c"
    break;

  case 96: /* inside_norm: vertex  */
#line 555 "new_parser.y"
                        { (yyval.main).text = new string;*(yyval.main).text = "norm( " + *(yyvsp[0].main).text + " )";}
#line 2355 "new_parser.tab.c"
    break;

  case 97: /* assign: EQUAL expression  */
#line 559 "new_parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype;(yyval.main).text = new string; *(yyval.main).text = "=" + *(yyvsp[0].main).text;}
#line 2361 "new_parser.tab.c"
    break;

  case 98: /* assign: ASSIGN_OP expression  */
#line 560 "new_parser.y"
                                {if(!(arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = assignOpTranslation(*(yyvsp[-1].main).text) + *(yyvsp[0].main).text;}
#line 2367 "new_parser.tab.c"
    break;

  case 99: /* assign: SUM_ASSIGN_OP expression  */
#line 561 "new_parser.y"
                                    {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == LABEL || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = "+=" + *(yyvsp[0].main).text;}
#line 2373 "new_parser.tab.c"
    break;

  case 100: /* assign: SUB_ASSIGN_OP expression  */
#line 562 "new_parser.y"
                                  {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;  (yyval.main).text = new string;*(yyval.main).text = "-=" + *(yyvsp[0].main).text;}
#line 2379 "new_parser.tab.c"
    break;

  case 101: /* decl_stmt: DATATYPE id_list ENDLINE  */
#line 566 "new_parser.y"
                                     {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";"; }
#line 2385 "new_parser.tab.c"
    break;

  case 102: /* decl_stmt: constructor id_list ENDLINE  */
#line 567 "new_parser.y"
                                        {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + ";";}
#line 2391 "new_parser.tab.c"
    break;

  case 103: /* id_list: id_list ',' ID check_arr EQUAL arr_assign  */
#line 571 "new_parser.y"
       {
              (yyval.main).nameList = (yyvsp[-5].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);
              compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text  + *(yyvsp[0].main).text;
       }
#line 2403 "new_parser.tab.c"
    break;

  case 104: /* id_list: id_list ',' ID check_arr  */
#line 579 "new_parser.y"
       {
              (yyval.main).nameList = (yyvsp[-3].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2415 "new_parser.tab.c"
    break;

  case 105: /* id_list: id_list ',' ID decl_assign  */
#line 587 "new_parser.y"
       {
              (yyval.main).nameList = (yyvsp[-3].main).nameList;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2427 "new_parser.tab.c"
    break;

  case 106: /* id_list: ID check_arr  */
#line 595 "new_parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2439 "new_parser.tab.c"
    break;

  case 107: /* id_list: ID check_arr EQUAL arr_assign  */
#line 603 "new_parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-3].main).name);
              compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2451 "new_parser.tab.c"
    break;

  case 108: /* id_list: ID check_arr EQUAL lineArr  */
#line 610 "new_parser.y"
                                    {

              if ((yyvsp[-2].main).dimList->size() != 1){
                     semanticError("Dimensions of linearr don't match");
              }
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text  + "=" + translateLineArr(*(yyvsp[0].main).text);

       }
#line 2465 "new_parser.tab.c"
    break;

  case 109: /* id_list: ID decl_assign  */
#line 620 "new_parser.y"
       {
              (yyval.main).nameList = new vector<char*>;
              (yyval.main).nameList->push_back((yyvsp[-1].main).name);
              insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);
              (yyval.main).text = new string;
              *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
       }
#line 2477 "new_parser.tab.c"
    break;

  case 110: /* decl_assign: EQUAL decl_token  */
#line 629 "new_parser.y"
                              {(yyval.main).eletype = (yyvsp[0].main).eletype ; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text; }
#line 2483 "new_parser.tab.c"
    break;

  case 111: /* decl_assign: %empty  */
#line 630 "new_parser.y"
                      {(yyval.main).eletype = UNDEF; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2489 "new_parser.tab.c"
    break;

  case 112: /* decl_token: construct  */
#line 633 "new_parser.y"
                       {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2495 "new_parser.tab.c"
    break;

  case 113: /* decl_token: expression  */
#line 634 "new_parser.y"
                       {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2501 "new_parser.tab.c"
    break;

  case 114: /* check_arr: dim  */
#line 638 "new_parser.y"
               {(yyval.main).dimList = (yyvsp[0].main).dimList; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2507 "new_parser.tab.c"
    break;

  case 115: /* check_arr: '[' ']'  */
#line 639 "new_parser.y"
                   {(yyval.main).dimList = new vector<int>;(yyval.main).dimList->push_back(-1); (yyval.main).text = new string;*(yyval.main).text = "[]";}
#line 2513 "new_parser.tab.c"
    break;

  case 116: /* check_arr: '[' ']' dim  */
#line 640 "new_parser.y"
                       {(yyval.main).dimList = new vector<int>;addFrontAndCopy((yyval.main).dimList, (yyvsp[0].main).dimList, -1);delete (yyvsp[0].main).dimList; (yyval.main).text = new string;*(yyval.main).text = "[]" + *(yyvsp[0].main).text; }
#line 2519 "new_parser.tab.c"
    break;

  case 117: /* dim: dim '[' const_expr ']'  */
#line 643 "new_parser.y"
                             {(yyval.main).dimList = (yyvsp[-3].main).dimList;
                              
                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);
                            (yyval.main).text = new string;
                            *(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";
                            
                            }
#line 2534 "new_parser.tab.c"
    break;

  case 118: /* dim: '[' const_expr ']'  */
#line 653 "new_parser.y"
                         {(yyval.main).dimList = new vector<int>; 

                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);

                            (yyval.main).text = new string;
                            *(yyval.main).text =  "[" + *(yyvsp[-1].main).text + "]";
                         }
#line 2549 "new_parser.tab.c"
    break;

  case 119: /* arr_assign: '{' arr1d_in_list '}'  */
#line 668 "new_parser.y"
              {
                     (yyval.main).listAndType.dimList = new vector<int>; 
                     (yyval.main).listAndType.dimList->push_back((yyvsp[-1].main).countAndType.count); 
                     (yyval.main).listAndType.eletype = (yyvsp[-1].main).countAndType.eletype; 
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}";
              }
#line 2561 "new_parser.tab.c"
    break;

  case 120: /* arr_assign: '{' comma_arr_assign '}'  */
#line 676 "new_parser.y"
              {
                     (yyval.main).listAndType.dimList = (yyvsp[-1].main).listAndType.dimList;
                     (yyval.main).listAndType.eletype = (yyvsp[-1].main).listAndType.eletype;
                     (yyval.main).text = new string;
                     *(yyval.main).text = "{" + *(yyvsp[-1].main).text + "}";
              }
#line 2572 "new_parser.tab.c"
    break;

  case 121: /* comma_arr_assign: comma_arr_assign ',' arr_assign  */
#line 685 "new_parser.y"
              {
                     updateMaxDim((yyvsp[-2].main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList); 
                     delete (yyvsp[0].main).listAndType.dimList;(yyval.main).listAndType.dimList = (yyvsp[-2].main).listAndType.dimList;
                     if (!coercible((yyvsp[-2].main).listAndType.eletype, (yyvsp[0].main).listAndType.eletype)) semanticError("arrays should be initialized with same datatype");
                     else (yyval.main).listAndType.eletype = (yyvsp[-2].main).listAndType.eletype;
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text ;
              }
#line 2585 "new_parser.tab.c"
    break;

  case 122: /* comma_arr_assign: arr_assign  */
#line 694 "new_parser.y"
              {
                     (yyval.main).listAndType.dimList = new vector<int>; 
                     addFrontAndCopy((yyval.main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList, 1);
                     delete (yyvsp[0].main).listAndType.dimList;
                     (yyval.main).listAndType.eletype = (yyvsp[0].main).listAndType.eletype;
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[0].main).text;
              }
#line 2598 "new_parser.tab.c"
    break;

  case 123: /* arr1d_in_list: mult_elements  */
#line 704 "new_parser.y"
                             {(yyval.main).countAndType.count = (yyvsp[0].main).countAndType.count;(yyval.main).eletype = (yyvsp[0].main).countAndType.eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2604 "new_parser.tab.c"
    break;

  case 124: /* arr1d_in_list: %empty  */
#line 705 "new_parser.y"
                           {(yyval.main).countAndType.count = 0;(yyval.main).eletype = UNDEF; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2610 "new_parser.tab.c"
    break;

  case 125: /* mult_elements: mult_elements ',' expression  */
#line 709 "new_parser.y"
              {
                     (yyval.main).count = (yyvsp[-2].main).countAndType.count + 1; 
                     if (!coercible((yyvsp[-2].main).countAndType.eletype, (yyvsp[0].main).eletype)) semanticError("arrays should be initialized with same datatype");
                     else (yyval.main).countAndType.eletype = (yyvsp[0].main).eletype;
                     // double to int only checked at decl_stmt 
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text ;
              }
#line 2623 "new_parser.tab.c"
    break;

  case 126: /* mult_elements: expression  */
#line 717 "new_parser.y"
                           {(yyval.main).countAndType.count = 1;(yyval.main).countAndType.eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2629 "new_parser.tab.c"
    break;

  case 127: /* const_expr: const_expr '+' const_expr  */
#line 720 "new_parser.y"
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
#line 2648 "new_parser.tab.c"
    break;

  case 128: /* const_expr: const_expr '-' const_expr  */
#line 734 "new_parser.y"
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
#line 2667 "new_parser.tab.c"
    break;

  case 129: /* const_expr: const_expr '*' const_expr  */
#line 748 "new_parser.y"
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
#line 2685 "new_parser.tab.c"
    break;

  case 130: /* const_expr: const_expr '/' const_expr  */
#line 761 "new_parser.y"
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
#line 2704 "new_parser.tab.c"
    break;

  case 131: /* const_expr: const_expr '%' const_expr  */
#line 775 "new_parser.y"
                                   {if ((yyvsp[-2].main).constExp.eletype != INT || (yyvsp[0].main).constExp.eletype != INT) semanticError("Error: Semantic error incompatible datatype");(yyval.main).constExp.eletype = INT;
                                          (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i % (yyvsp[0].main).constExp.i;
                                          (yyval.main).text = new string;
                                          *(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text  ;
                                   }
#line 2714 "new_parser.tab.c"
    break;

  case 132: /* const_expr: const_expr '^' const_expr  */
#line 780 "new_parser.y"
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
#line 2732 "new_parser.tab.c"
    break;

  case 133: /* const_expr: '-' const_expr  */
#line 793 "new_parser.y"
                        {   
                            if (!arithCompatible((yyvsp[0].main).constExp.eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).constExp.eletype = (yyvsp[0].main).constExp.eletype;

                            if ((yyval.main).constExp.eletype == REAL) 
                                   (yyval.main).constExp.d = -(yyvsp[0].main).constExp.d; 
                            else 
                                   (yyval.main).constExp.i = -(yyvsp[0].main).constExp.i;
                            (yyval.main).text = new string;
                            *(yyval.main).text = "-" + *(yyvsp[0].main).text ;
                        }
#line 2747 "new_parser.tab.c"
    break;

  case 134: /* const_expr: '(' const_expr ')'  */
#line 803 "new_parser.y"
                            {      
                                   (yyval.main).constExp.eletype = (yyvsp[-1].main).constExp.eletype;
                                   if ((yyval.main).constExp.eletype == REAL) 
                                          (yyval.main).constExp.d = (yyvsp[-1].main).constExp.d; 
                                   else 
                                          (yyval.main).constExp.i = (yyvsp[-1].main).constExp.i;
                                   (yyval.main).text = new string;
                                   *(yyval.main).text = "(" + *(yyvsp[-1].main).text  + ")";
                            }
#line 2761 "new_parser.tab.c"
    break;

  case 135: /* const_expr: FLOATS  */
#line 812 "new_parser.y"
                { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;(yyval.main).constExp.d = (yyvsp[0].main).constExp.d;}
#line 2767 "new_parser.tab.c"
    break;

  case 136: /* const_expr: INTEGERS  */
#line 813 "new_parser.y"
                  { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype; (yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2773 "new_parser.tab.c"
    break;

  case 137: /* const_expr: BOOLEAN  */
#line 814 "new_parser.y"
                 { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; (yyval.main).eletype = INT; (yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2779 "new_parser.tab.c"
    break;

  case 138: /* member_access: memb_access  */
#line 819 "new_parser.y"
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
#line 2797 "new_parser.tab.c"
    break;

  case 139: /* memb_access: memb_access '.' ID arr_access  */
#line 833 "new_parser.y"
                                            {
                     (yyval.main).dimCount = (yyvsp[-3].main).dimCount; 
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});
                     }
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-3].main).text + "." + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2811 "new_parser.tab.c"
    break;

  case 140: /* memb_access: ID arr_access  */
#line 842 "new_parser.y"
                              {
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     (yyval.main).dimCount = new vector<cntAndType> ;   //free?
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});  
                     } 
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;    
              }
#line 2825 "new_parser.tab.c"
    break;

  case 141: /* arr_access: arr_access '[' expression ']'  */
#line 854 "new_parser.y"
                                          {(yyval.main).count = (yyvsp[-3].main).count; (yyval.main).count = (yyval.main).count + 1; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";}
#line 2831 "new_parser.tab.c"
    break;

  case 142: /* arr_access: %empty  */
#line 855 "new_parser.y"
                        {(yyval.main).count = 0; (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2837 "new_parser.tab.c"
    break;

  case 143: /* $@7: %empty  */
#line 858 "new_parser.y"
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
#line 2854 "new_parser.tab.c"
    break;

  case 144: /* func_call: member_access $@7 '(' param_list_opt ')'  */
#line 870 "new_parser.y"
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
#line 2878 "new_parser.tab.c"
    break;

  case 145: /* param_list_opt: param_list  */
#line 891 "new_parser.y"
                            {(yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 2884 "new_parser.tab.c"
    break;

  case 146: /* param_list_opt: %empty  */
#line 892 "new_parser.y"
                             {(yyval.main).text = new string;*(yyval.main).text = "";}
#line 2890 "new_parser.tab.c"
    break;

  case 147: /* empty_space: empty_space ENDLINE  */
#line 895 "new_parser.y"
                                  { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;}
#line 2896 "new_parser.tab.c"
    break;

  case 148: /* empty_space: %empty  */
#line 896 "new_parser.y"
                                  { (yyval.main).text = new string;*(yyval.main).text = "";}
#line 2902 "new_parser.tab.c"
    break;

  case 149: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE  */
#line 902 "new_parser.y"
              {     
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if (!(arithCompatible((yyvsp[-4].main).eletype))) 
                            semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-6].main).text + "(" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
              }
#line 2914 "new_parser.tab.c"
    break;

  case 150: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE ELSE empty_space stmt_block ENDLINE  */
#line 910 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-5].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-8].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-10].main).text + "(" + *(yyvsp[-8].main).text + ")" + *(yyvsp[-6].main).text + *(yyvsp[-5].main).text + *(yyvsp[-4].main).text + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2925 "new_parser.tab.c"
    break;

  case 151: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt ELSE empty_space stmt_block ENDLINE  */
#line 917 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-6].main).stopAdvanceFound||(yyvsp[-4].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-9].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-11].main).text + "(" + *(yyvsp[-9].main).text + ")" + *(yyvsp[-7].main).text + *(yyvsp[-6].main).text + *(yyvsp[-5].main).text + *(yyvsp[-4].main).text + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2936 "new_parser.tab.c"
    break;

  case 152: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt  */
#line 924 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-2].main).stopAdvanceFound||(yyvsp[0].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-5].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-7].main).text + "(" + *(yyvsp[-5].main).text + ")" + *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2947 "new_parser.tab.c"
    break;

  case 153: /* elif_stmt: ELIF '(' expression ')' empty_space stmt_block ENDLINE  */
#line 933 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = "else if (" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2958 "new_parser.tab.c"
    break;

  case 154: /* elif_stmt: elif_stmt ELIF '(' expression ')' empty_space stmt_block ENDLINE  */
#line 940 "new_parser.y"
              {
                     (yyval.main).stopAdvanceFound = (yyvsp[-7].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-7].main).text + "else if (" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2969 "new_parser.tab.c"
    break;

  case 155: /* loop: for_loop  */
#line 951 "new_parser.y"
                     { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 2975 "new_parser.tab.c"
    break;

  case 156: /* loop: while_loop  */
#line 952 "new_parser.y"
                     { (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text; }
#line 2981 "new_parser.tab.c"
    break;

  case 157: /* $@8: %empty  */
#line 955 "new_parser.y"
                { addSymTabPtr(); }
#line 2987 "new_parser.tab.c"
    break;

  case 158: /* for_loop_decl: $@8 DATATYPE ID EQUAL expression  */
#line 956 "new_parser.y"
              {
                     insertType((yyvsp[-2].main).name, Var, (yyvsp[-3].main).eletype);
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-3].main).text + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
                     delete (yyvsp[-2].main).name;
              }
#line 2998 "new_parser.tab.c"
    break;

  case 159: /* $@9: %empty  */
#line 962 "new_parser.y"
                { addSymTabPtr(); }
#line 3004 "new_parser.tab.c"
    break;

  case 160: /* for_loop_decl: $@9 ID EQUAL expression  */
#line 964 "new_parser.y"
              { 
                     (yyval.main).text = new string;
                     *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
                     delete (yyvsp[-2].main).name; 
              }
#line 3014 "new_parser.tab.c"
    break;

  case 161: /* for_loop_decl: %empty  */
#line 969 "new_parser.y"
                { addSymTabPtr(); (yyval.main).text = new string;*(yyval.main).text = "";}
#line 3020 "new_parser.tab.c"
    break;

  case 162: /* optional_arg: expression  */
#line 972 "new_parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype; (yyval.main).text = new string;*(yyval.main).text = *(yyvsp[0].main).text;}
#line 3026 "new_parser.tab.c"
    break;

  case 163: /* optional_arg: %empty  */
#line 973 "new_parser.y"
                          {(yyval.main).eletype = UNDEF;(yyval.main).text = new string;*(yyval.main).text = "";}
#line 3032 "new_parser.tab.c"
    break;

  case 164: /* for_loop: FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' empty_space stmt_block_for  */
#line 977 "new_parser.y"
              { 
                     if(!(arithCompatible((yyvsp[-5].main).eletype)) && (yyvsp[-5].main).eletype != UNDEF) semanticError("Error: Semantic error incompatible datatype11");
                     (yyval.main).text = new string;
                     *(yyval.main).text = "for (" + *(yyvsp[-7].main).text + ";" + *(yyvsp[-5].main).text + ";" + *(yyvsp[-3].main).text + ")" + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 3042 "new_parser.tab.c"
    break;

  case 165: /* while_loop: WHILE '(' expression ')' empty_space stmt_block  */
#line 983 "new_parser.y"
                                                              {(yyval.main).text = new string;*(yyval.main).text = "while (" + *(yyvsp[-3].main).text + ")" + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 3048 "new_parser.tab.c"
    break;


#line 3052 "new_parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 987 "new_parser.y"


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
    
    fprintf(fout_translated, "}\n");


    fclose(fp);
    fclose(fout_token);
    fclose(fout_translated);
    
    return x;
} 
