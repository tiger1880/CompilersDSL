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

extern int yydebug;

#define YYDEBUG 1

/* Linearr left */


int ret_flag = 0;
int ret_fig_flag = 0;
int is_member = 0;
int isArray = 0;
int is_fig = 0;

int lineArrNo = 0;

enum eletype ret_type = UNDEF;

vector<ParamList> paramslist;
STentry typelist;
vector<types> params;
vector<types> construct_params;
vector<ParamList> func_paramlist;


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

#include "parser.tab.h"
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
  YYSYMBOL_construct = 80,                 /* construct  */
  YYSYMBOL_constructor = 81,               /* constructor  */
  YYSYMBOL_valid_arg = 82,                 /* valid_arg  */
  YYSYMBOL_param_list = 83,                /* param_list  */
  YYSYMBOL_construct_param_list = 84,      /* construct_param_list  */
  YYSYMBOL_point = 85,                     /* point  */
  YYSYMBOL_vertex = 86,                    /* vertex  */
  YYSYMBOL_angle = 87,                     /* angle  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_inside_norm = 89,               /* inside_norm  */
  YYSYMBOL_assign = 90,                    /* assign  */
  YYSYMBOL_decl_stmt = 91,                 /* decl_stmt  */
  YYSYMBOL_id_list = 92,                   /* id_list  */
  YYSYMBOL_decl_assign = 93,               /* decl_assign  */
  YYSYMBOL_decl_token = 94,                /* decl_token  */
  YYSYMBOL_check_arr = 95,                 /* check_arr  */
  YYSYMBOL_dim = 96,                       /* dim  */
  YYSYMBOL_arr_assign_line = 97,           /* arr_assign_line  */
  YYSYMBOL_arr_assign = 98,                /* arr_assign  */
  YYSYMBOL_comma_arr_assign = 99,          /* comma_arr_assign  */
  YYSYMBOL_arr1d_in_list = 100,            /* arr1d_in_list  */
  YYSYMBOL_mult_elements = 101,            /* mult_elements  */
  YYSYMBOL_const_expr = 102,               /* const_expr  */
  YYSYMBOL_member_access = 103,            /* member_access  */
  YYSYMBOL_memb_access = 104,              /* memb_access  */
  YYSYMBOL_arr_access = 105,               /* arr_access  */
  YYSYMBOL_func_call = 106,                /* func_call  */
  YYSYMBOL_107_7 = 107,                    /* $@7  */
  YYSYMBOL_param_list_opt = 108,           /* param_list_opt  */
  YYSYMBOL_empty_space = 109,              /* empty_space  */
  YYSYMBOL_cond_stmt = 110,                /* cond_stmt  */
  YYSYMBOL_elif_stmt = 111,                /* elif_stmt  */
  YYSYMBOL_loop = 112,                     /* loop  */
  YYSYMBOL_for_loop_decl = 113,            /* for_loop_decl  */
  YYSYMBOL_114_8 = 114,                    /* $@8  */
  YYSYMBOL_115_9 = 115,                    /* $@9  */
  YYSYMBOL_optional_arg = 116,             /* optional_arg  */
  YYSYMBOL_for_loop = 117,                 /* for_loop  */
  YYSYMBOL_while_loop = 118                /* while_loop  */
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
#define YYLAST   1032

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  317

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
       0,   168,   168,   169,   170,   171,   180,   180,   180,   205,
     205,   205,   229,   230,   233,   233,   235,   244,   259,   259,
     272,   273,   276,   277,   278,   279,   280,   281,   282,   283,
     286,   287,   290,   290,   293,   296,   297,   301,   303,   303,
     303,   306,   307,   336,   337,   340,   341,   342,   343,   346,
     347,   350,   360,   372,   382,   395,   396,   400,   402,   405,
     406,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   441,   442,   443,   447,   448,   449,   450,   454,   455,
     458,   459,   460,   461,   462,   463,   466,   467,   470,   471,
     475,   476,   477,   480,   488,   499,   500,   509,   510,   513,
     514,   517,   518,   521,   522,   525,   538,   550,   562,   573,
     576,   588,   595,   602,   603,   604,   609,   623,   632,   643,
     644,   647,   647,   679,   680,   683,   684,   689,   697,   698,
     699,   702,   703,   709,   710,   713,   713,   714,   714,   715,
     718,   719,   722,   724
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
  "return_stmt", "ret_var", "assign_stmt", "construct", "constructor",
  "valid_arg", "param_list", "construct_param_list", "point", "vertex",
  "angle", "expression", "inside_norm", "assign", "decl_stmt", "id_list",
  "decl_assign", "decl_token", "check_arr", "dim", "arr_assign_line",
  "arr_assign", "comma_arr_assign", "arr1d_in_list", "mult_elements",
  "const_expr", "member_access", "memb_access", "arr_access", "func_call",
  "$@7", "param_list_opt", "empty_space", "cond_stmt", "elif_stmt", "loop",
  "for_loop_decl", "$@8", "$@9", "optional_arg", "for_loop", "while_loop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-207)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-160)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -207,   308,  -207,  -207,  -207,  -207,   -28,   -25,     2,   453,
      43,    46,    -8,    89,    23,    77,    82,  -207,  -207,  -207,
    -207,  -207,  -207,  -207,   503,    -8,   503,   503,  -207,  -207,
    -207,  -207,    -3,  -207,  -207,  -207,    88,    22,  -207,  -207,
     864,  -207,    19,    72,  -207,  -207,  -207,  -207,  -207,   503,
     -24,   503,   100,  -207,    86,   897,  -207,  -207,   503,  -207,
    -207,    20,  -207,   101,   109,  -207,  -207,   -16,     8,    87,
    -207,    -8,    92,   519,  -207,  -207,   412,    18,   503,   503,
     503,   503,   503,  -207,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,  -207,   503,   503,   503,   503,  -207,
      93,   120,   700,    95,   132,   126,   741,  -207,   601,  -207,
      -8,    -8,  -207,  -207,   108,   453,    27,  -207,   134,   105,
    -207,   133,   503,    -8,  -207,   503,   164,  -207,  -207,  -207,
     -38,   897,  -207,    10,   957,   930,   103,   587,   324,   984,
     103,   103,    10,    10,    92,    92,    92,    92,   897,   897,
     897,   897,   453,  -207,  -207,   503,   136,   137,  -207,  -207,
    -207,   121,   123,   475,  -207,   897,  -207,  -207,  -207,  -207,
      24,    24,   127,   176,   384,    24,   -16,   338,    57,   560,
    -207,  -207,  -207,   453,  -207,   131,   139,    87,   148,   897,
     143,   156,   503,   148,   180,   180,   175,   153,   634,   142,
     245,    24,   105,    24,    24,    24,    24,    24,    24,  -207,
     384,   897,  -207,  -207,   231,  -207,   178,  -207,  -207,   202,
    -207,   182,  -207,   453,  -207,  -207,   179,   503,   503,   897,
    -207,   181,  -207,   161,  -207,  -207,   503,  -207,   503,  -207,
     142,   142,   166,   166,   166,   166,   897,  -207,   -34,   162,
     165,  -207,   384,   184,   173,  -207,   111,   188,   897,   174,
     192,   180,   196,   667,   148,   897,   177,  -207,  -207,   503,
    -207,  -207,  -207,   198,  -207,   114,  -207,  -207,  -207,  -207,
    -207,   191,  -207,  -207,   897,   503,   148,   199,  -207,    13,
     148,   148,   225,   782,   224,   503,   148,  -207,  -207,  -207,
    -207,   503,  -207,  -207,   823,   226,   229,   897,   148,  -207,
    -207,  -207,   227,   148,  -207,   236,  -207
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    32,     1,    85,    86,    84,     0,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,    87,    27,   140,
      45,    46,    47,    48,     0,     0,     0,     0,     2,     3,
       4,    28,     0,    29,    26,    25,     0,     0,    89,    90,
       0,    24,    82,   136,    88,    22,    23,   153,   154,     0,
     155,     0,     0,    38,     0,    39,    36,    35,     0,    58,
      93,     0,    57,     0,     0,    18,    72,   107,     0,   138,
      74,     0,    71,     0,    31,    42,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    70,
       0,     0,     9,     6,     0,     0,     0,   105,   103,   110,
      98,     0,     0,     0,    83,     0,    32,    44,    49,    54,
       0,    50,    99,    67,    68,    69,    78,    81,    75,    76,
      79,    80,    61,    62,    63,    64,    65,    66,    95,    96,
      97,    94,   144,   140,   146,   161,     0,     0,   146,    91,
      92,     0,     0,     0,   108,   109,   106,   134,   135,   133,
       0,     0,   111,     0,     0,     0,   107,     0,     0,     0,
      33,    30,    43,     0,    52,   143,     0,   137,    32,   160,
       0,     0,     0,    32,    13,    13,     0,     0,     0,   131,
       0,     0,   112,     0,     0,     0,     0,     0,     0,   114,
     122,   116,   104,   115,     0,   102,   101,   139,    60,     0,
      56,     0,    53,     0,   142,   145,     0,   161,     0,   158,
     163,     0,    10,    12,    15,     7,     0,   146,     0,   132,
     125,   126,   127,   128,   129,   130,   124,   120,     0,     0,
     121,   113,     0,     0,     0,    51,   147,     0,   156,    17,
       0,     0,     0,     0,    32,    20,     0,   118,   117,     0,
     100,    59,    55,     0,   146,   150,   146,    16,   146,    14,
     146,     0,    19,   119,   123,     0,    32,     0,   146,     0,
      32,    32,     0,     0,     0,     0,    32,    31,   162,    11,
       8,     0,   146,   148,     0,     0,    32,    21,    32,   146,
     149,    34,     0,    32,   151,     0,   152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -207,  -207,  -207,  -207,  -207,  -207,  -207,    59,  -207,     5,
    -207,  -207,  -207,   266,   -27,  -153,  -207,  -207,  -207,  -207,
    -207,  -207,     0,     1,  -149,  -207,  -207,    -7,   -10,  -207,
      -1,  -207,  -207,  -207,   234,   104,  -207,  -160,   113,    29,
    -206,  -207,  -207,  -207,   260,    -5,  -207,   130,  -207,  -207,
    -207,  -144,  -207,  -207,  -207,  -207,  -207,  -207,    65,  -207,
    -207
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    28,   162,   262,   161,   260,   232,   233,   234,
      29,   114,   197,   181,   126,    31,    32,   298,    33,    34,
      52,    35,   128,    54,   129,   185,   130,    38,    60,    39,
     131,    61,    99,    41,    68,   117,   166,   118,   119,   212,
     213,   248,   249,   250,   173,    42,    43,    69,    44,   100,
     186,   188,    45,   275,    46,   103,   104,   105,   190,    47,
      48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    36,    37,   184,   247,    59,  -157,    62,    55,    53,
      66,   115,   182,   183,   193,    71,   216,   266,    59,   267,
      62,    49,    19,    70,    50,    72,    73,   167,   168,   169,
     167,   168,   169,  -159,   222,   226,   109,   120,   116,    94,
     230,    58,   225,    95,    96,    97,    98,   132,   102,    74,
     106,    51,    67,    65,    90,    91,    92,   108,    93,   121,
     283,   123,   110,   111,    59,   297,    62,   170,  -141,   121,
     170,    76,    56,   171,   255,    57,   171,   133,   134,   135,
     136,   137,   172,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   264,   148,   149,   150,   151,   218,   277,
     159,   160,    63,    59,    59,    62,    62,    19,   219,    78,
      64,   282,    67,   178,   165,   164,    59,    75,    62,   273,
     274,   177,   287,   288,   179,    40,    36,    37,   101,   107,
     286,   112,   289,   294,   290,    76,   291,   299,   300,   113,
      93,   122,   152,   305,   296,    88,    89,    90,    91,    92,
     153,    93,   155,   156,   189,   312,   157,   163,   308,   175,
     315,   174,   198,   176,   192,   313,   191,     3,     4,     5,
     194,     6,   195,   211,     7,     8,     9,   225,    10,    11,
      12,   201,   223,   228,    15,    16,   205,   206,   207,   224,
     208,   229,    17,    18,    19,    20,    21,    22,    23,    24,
     227,   231,   236,   237,    25,   252,   253,    26,   256,   246,
     254,   259,   261,    27,   208,   268,   269,   180,   203,   204,
     205,   206,   207,   272,   208,   271,   189,   258,   116,   210,
     292,   209,     3,     4,     5,   263,     6,   265,   276,     7,
       8,     9,   278,    10,    11,    12,   280,   285,   295,    15,
      16,   211,   301,   303,   235,   310,   314,    17,    18,    19,
      20,    21,    22,    23,    24,   316,   279,    30,   284,    25,
     306,    77,    26,   203,   204,   205,   206,   207,    27,   208,
     215,   270,   311,   187,   293,   202,   251,   203,   204,   205,
     206,   207,   257,   208,   304,   239,     0,     0,     0,     0,
     307,     0,     0,     0,     0,    40,    36,    37,     2,     0,
       0,     3,     4,     5,     0,     6,     0,     0,     7,     8,
       9,     0,    10,    11,    12,     0,    13,    14,    15,    16,
      78,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    78,     0,    81,    82,    25,     0,
       0,    26,     0,     0,    79,    80,     0,    27,     0,     0,
      81,    82,     0,     0,    86,    87,    88,    89,    90,    91,
      92,     0,    93,     0,    84,    85,     0,     0,    86,    87,
      88,    89,    90,    91,    92,     0,    93,     3,     4,     5,
       0,     0,     0,   217,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,    17,     0,    19,     3,     4,     5,     0,    24,
       0,     0,     0,     0,    25,     0,     0,    26,    12,     0,
     199,   200,    15,    27,     0,   214,   210,     0,     0,     0,
      17,     0,    19,    20,    21,    22,    23,    24,     0,     0,
       0,     0,    25,     0,     0,    26,     3,     4,     5,     0,
       0,    27,   127,   240,   241,   242,   243,   244,   245,    12,
       0,     0,     0,    15,     0,     0,     0,     0,     3,     4,
       5,    17,     0,    19,    20,    21,    22,    23,    24,     0,
       0,    12,     0,    25,     0,    15,    26,     0,     0,     0,
       0,     0,    27,    17,     0,    19,     3,     4,     5,     0,
      24,     0,     0,   196,     0,    25,     0,     0,    26,    12,
       0,     0,     0,    15,    27,    78,     0,     0,     0,     0,
       0,    17,     0,    19,     0,    79,    80,     0,    24,     0,
       0,    81,    82,    25,     0,     0,    26,     0,     0,     0,
       0,     0,    27,     0,     0,    84,    85,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    78,    93,     0,   124,
     125,     0,     0,     0,     0,     0,    79,    80,     0,     0,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    84,    85,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    78,    93,    81,
     220,   221,     0,     0,     0,     0,     0,    79,    80,     0,
       0,     0,     0,    81,    82,     0,     0,    86,    87,    88,
      89,    90,    91,    92,     0,    93,     0,    84,    85,     0,
      78,    86,    87,    88,    89,    90,    91,    92,     0,    93,
      79,    80,   125,     0,     0,     0,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,     0,    78,    86,    87,    88,    89,    90,    91,
      92,     0,    93,    79,    80,   238,     0,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,    78,    86,    87,    88,
      89,    90,    91,    92,     0,    93,    79,    80,   281,     0,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    78,    93,     0,
     154,     0,     0,     0,     0,     0,     0,    79,    80,     0,
       0,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    78,    93,
       0,   158,     0,     0,     0,     0,     0,     0,    79,    80,
       0,     0,     0,     0,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    78,
      93,     0,   302,     0,     0,     0,     0,     0,     0,    79,
      80,     0,     0,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      78,    93,     0,   309,     0,     0,     0,     0,     0,     0,
      79,    80,     0,     0,     0,     0,    81,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
      84,    85,     0,    78,    86,    87,    88,    89,    90,    91,
      92,     0,    93,    79,    80,     0,     0,     0,     0,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,     0,    78,    86,    87,    88,
      89,    90,    91,    92,     0,    93,    79,     0,     0,     0,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    84,    85,     0,     0,
      86,    87,    88,    89,    90,    91,    92,     0,    93,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,    84,    85,     0,     0,    86,    87,    88,
      89,    90,    91,    92,     0,    93,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,     0,    93
};

static const yytype_int16 yycheck[] =
{
       1,     1,     1,   152,   210,    12,    30,    12,     9,     9,
      15,    27,    50,    51,   158,    25,   176,    51,    25,    53,
      25,    49,    30,    24,    49,    26,    27,     3,     4,     5,
       3,     4,     5,    57,   183,   188,    16,    29,    54,    20,
     193,    49,    29,    24,    25,    26,    27,    29,    49,    52,
      51,    49,    30,    30,    44,    45,    46,    58,    48,    51,
     266,    71,    42,    43,    71,    52,    71,    43,    49,    51,
      43,    49,    29,    49,   223,    29,    49,    78,    79,    80,
      81,    82,    55,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,   237,    95,    96,    97,    98,    41,   259,
     110,   111,    13,   110,   111,   110,   111,    30,    51,     6,
      21,   264,    30,   123,   115,   115,   123,    29,   123,     8,
       9,   122,     8,     9,   125,   126,   126,   126,    56,    29,
     274,    30,   276,   286,   278,    49,   280,   290,   291,    30,
      48,    54,    49,   296,   288,    42,    43,    44,    45,    46,
      30,    48,    57,    21,   155,   308,    30,    49,   302,    54,
     313,    27,   163,    30,    27,   309,    30,     3,     4,     5,
      49,     7,    49,   174,    10,    11,    12,    29,    14,    15,
      16,    54,    51,    27,    20,    21,    44,    45,    46,    50,
      48,   192,    28,    29,    30,    31,    32,    33,    34,    35,
      57,    21,    27,    50,    40,    27,     4,    43,    29,   210,
      28,    30,    51,    49,    48,    53,    51,    53,    42,    43,
      44,    45,    46,    50,    48,    41,   227,   228,    54,    52,
      39,    55,     3,     4,     5,   236,     7,   238,    50,    10,
      11,    12,    50,    14,    15,    16,    50,    49,    49,    20,
      21,   252,    27,    29,   195,    29,    29,    28,    29,    30,
      31,    32,    33,    34,    35,    29,   261,     1,   269,    40,
     297,    37,    43,    42,    43,    44,    45,    46,    49,    48,
     176,   252,    53,   153,   285,   172,    55,    42,    43,    44,
      45,    46,   227,    48,   295,    50,    -1,    -1,    -1,    -1,
     301,    -1,    -1,    -1,    -1,   306,   306,   306,     0,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    10,    11,
      12,    -1,    14,    15,    16,    -1,    18,    19,    20,    21,
       6,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,     6,    -1,    22,    23,    40,    -1,
      -1,    43,    -1,    -1,    16,    17,    -1,    49,    -1,    -1,
      22,    23,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    -1,    36,    37,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,     3,     4,     5,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,     3,     4,     5,    -1,    35,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    43,    16,    -1,
     170,   171,    20,    49,    -1,   175,    52,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    43,     3,     4,     5,    -1,
      -1,    49,    50,   203,   204,   205,   206,   207,   208,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,     3,     4,
       5,    28,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    16,    -1,    40,    -1,    20,    43,    -1,    -1,    -1,
      -1,    -1,    49,    28,    -1,    30,     3,     4,     5,    -1,
      35,    -1,    -1,    38,    -1,    40,    -1,    -1,    43,    16,
      -1,    -1,    -1,    20,    49,     6,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,    16,    17,    -1,    35,    -1,
      -1,    22,    23,    40,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    36,    37,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,     6,    48,    -1,    50,
      51,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,     6,    48,    22,
      50,    51,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    -1,    36,    37,    -1,
       6,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      16,    17,    51,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,     6,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    16,    17,    51,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    -1,     6,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    16,    17,    51,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,     6,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,     6,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,     6,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
       6,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    -1,     6,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    -1,     6,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    16,    -1,    -1,    -1,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    -1,    36,    37,    -1,    -1,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    59,     0,     3,     4,     5,     7,    10,    11,    12,
      14,    15,    16,    18,    19,    20,    21,    28,    29,    30,
      31,    32,    33,    34,    35,    40,    43,    49,    60,    68,
      71,    73,    74,    76,    77,    79,    80,    81,    85,    87,
      88,    91,   103,   104,   106,   110,   112,   117,   118,    49,
      49,    49,    78,    80,    81,    88,    29,    29,    49,    85,
      86,    89,   103,    13,    21,    30,   103,    30,    92,   105,
      88,    86,    88,    88,    52,    29,    49,    92,     6,    16,
      17,    22,    23,    29,    36,    37,    40,    41,    42,    43,
      44,    45,    46,    48,    20,    24,    25,    26,    27,    90,
     107,    56,    88,   113,   114,   115,    88,    29,    88,    16,
      42,    43,    30,    30,    69,    27,    54,    93,    95,    96,
      29,    51,    54,    86,    50,    51,    72,    50,    80,    82,
      84,    88,    29,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    49,    30,    50,    57,    21,    30,    50,    86,
      86,    63,    61,    49,    80,    88,    94,     3,     4,     5,
      43,    49,    55,   102,    27,    54,    30,    88,    86,    88,
      53,    71,    50,    51,    82,    83,   108,   105,   109,    88,
     116,    30,    27,   109,    49,    49,    38,    70,    88,   102,
     102,    54,    96,    42,    43,    44,    45,    46,    48,    55,
      52,    88,    97,    98,   102,    93,    95,    55,    41,    51,
      50,    51,    82,    51,    50,    29,    73,    57,    27,    88,
      73,    21,    65,    66,    67,    65,    27,    50,    51,    50,
     102,   102,   102,   102,   102,   102,    88,    98,    99,   100,
     101,    55,    27,     4,    28,    82,    29,   116,    88,    30,
      64,    51,    62,    88,   109,    88,    51,    53,    53,    51,
      97,    41,    50,     8,     9,   111,    50,    95,    50,    67,
      50,    51,    73,    98,    88,    49,   109,     8,     9,   109,
     109,   109,    39,    88,    73,    49,   109,    52,    75,    73,
      73,    27,    50,    29,    88,    73,    72,    88,   109,    50,
      29,    53,    73,   109,    29,    73,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    61,    62,    60,    63,
      64,    60,    65,    65,    66,    66,    67,    67,    69,    68,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    74,    73,    75,    76,    76,    77,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    89,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   104,   104,   105,
     105,   107,   106,   108,   108,   109,   109,   110,   110,   110,
     110,   111,   111,   112,   112,   114,   113,   115,   113,   113,
     116,   116,   117,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     0,     0,    10,     0,
       0,    10,     1,     0,     3,     1,     3,     2,     0,     8,
       3,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     0,     4,     3,     2,     2,     3,     1,     1,
       0,     2,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     7,     5,     1,     1,     7,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     3,     2,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     2,     2,     2,     2,     3,     3,
       6,     4,     4,     2,     4,     2,     2,     0,     1,     1,
       1,     2,     3,     4,     3,     1,     1,     3,     3,     3,
       1,     1,     0,     3,     1,     3,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     4,     2,     4,
       0,     0,     5,     1,     0,     2,     0,     7,    11,    12,
       8,     7,     8,     1,     1,     0,     5,     0,     4,     0,
       1,     0,    10,     6
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
  case 4: /* program: program stmt  */
#line 170 "parser.y"
                       {if ((yyvsp[0].main).stopAdvanceFound) semanticError("stop/advance cannot be outside the loop");}
#line 1601 "parser.tab.c"
    break;

  case 5: /* program: %empty  */
#line 171 "parser.y"
                     {
              if(ret_flag) {
                     cerr << "Error: Return statement not allowed outside function" << endl;
              }
         }
#line 1611 "parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 180 "parser.y"
                         { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype); addSymTabPtr(); }
#line 1617 "parser.tab.c"
    break;

  case 7: /* $@2: %empty  */
#line 180 "parser.y"
                                                                                                 {if(paramslist.size()>0) {
                     addParamList((yyvsp[-3].main).name,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
#line 1627 "parser.tab.c"
    break;

  case 8: /* func: FUNC DATATYPE ID $@1 '(' arg_list $@2 ')' empty_space stmt_block  */
#line 185 "parser.y"
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
              }
#line 1652 "parser.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 205 "parser.y"
                              { insertType((yyvsp[0].main).name, Func, (yyvsp[-1].main).eletype);  addSymTabPtr(); }
#line 1658 "parser.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 205 "parser.y"
                                                                                                       {if(paramslist.size()>0) {
                     addParamList((yyvsp[-3].main).name,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
#line 1668 "parser.tab.c"
    break;

  case 11: /* func: FUNC VOID ID $@3 '(' arg_list $@4 ')' empty_space stmt_block  */
#line 210 "parser.y"
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
              }
#line 1690 "parser.tab.c"
    break;

  case 16: /* argument: DATATYPE ID check_arr  */
#line 235 "parser.y"
                                 {
              ParamList param;
              param.Eletype = (yyvsp[-2].main).eletype;
              param.name = (yyvsp[-1].main).name;
              param.dim = *(yyvsp[0].main).dimList;
              param.Type = Array;
              paramslist.push_back(param);
              delete (yyvsp[-1].main).name;
       }
#line 1704 "parser.tab.c"
    break;

  case 17: /* argument: DATATYPE ID  */
#line 244 "parser.y"
                     {
              ParamList param;
              param.Eletype = (yyvsp[-1].main).eletype;
              param.name = (yyvsp[0].main).name;
              vector<int> dim;
              param.dim = dim;
              param.Type = Var;
              paramslist.push_back(param);
              delete (yyvsp[0].main).name;
       }
#line 1719 "parser.tab.c"
    break;

  case 18: /* $@5: %empty  */
#line 259 "parser.y"
            {insertType((yyvsp[0].main).name, Fig, UNDEF); addSymTabPtr();}
#line 1725 "parser.tab.c"
    break;

  case 19: /* fig: FIG ID $@5 '(' params ')' empty_space stmt_block  */
#line 259 "parser.y"
                                                                                                       { 
                                                        if (ret_fig_flag == 1)  
                                                               semanticError("Error: Return statement is not allowed in figures."); 
                                                        ret_fig_flag = 0;
                                                        

                                                        if ((yyvsp[0].main).stopAdvanceFound)
                                                               semanticError("stop/advance cannot be outside the loop");

                                                        delSymTabPtr();
                                                        delete (yyvsp[-6].main).name;
                                                        }
#line 1742 "parser.tab.c"
    break;

  case 20: /* params: expression ',' expression  */
#line 272 "parser.y"
                                   { if(!(arithCompatible((yyvsp[-2].main).eletype) && (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
#line 1748 "parser.tab.c"
    break;

  case 21: /* params: SCALE EQUAL expression ',' CENTER EQUAL expression  */
#line 273 "parser.y"
                                                            { if(!(arithCompatible((yyvsp[-4].main).eletype) && (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
#line 1754 "parser.tab.c"
    break;

  case 22: /* stmt: cond_stmt  */
#line 276 "parser.y"
                 {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound;}
#line 1760 "parser.tab.c"
    break;

  case 23: /* stmt: loop  */
#line 277 "parser.y"
                {(yyval.main).stopAdvanceFound = false;}
#line 1766 "parser.tab.c"
    break;

  case 24: /* stmt: decl_stmt  */
#line 278 "parser.y"
                 {(yyval.main).stopAdvanceFound = false;}
#line 1772 "parser.tab.c"
    break;

  case 25: /* stmt: assign_stmt  */
#line 279 "parser.y"
                   {(yyval.main).stopAdvanceFound = false;}
#line 1778 "parser.tab.c"
    break;

  case 26: /* stmt: return_stmt  */
#line 280 "parser.y"
                   {(yyval.main).stopAdvanceFound = false;}
#line 1784 "parser.tab.c"
    break;

  case 27: /* stmt: ENDLINE  */
#line 281 "parser.y"
                  {(yyval.main).stopAdvanceFound = false;}
#line 1790 "parser.tab.c"
    break;

  case 28: /* stmt: stmt_block  */
#line 282 "parser.y"
                  {(yyval.main).stopAdvanceFound = (yyvsp[0].main).stopAdvanceFound;}
#line 1796 "parser.tab.c"
    break;

  case 29: /* stmt: break_stmt  */
#line 283 "parser.y"
                  {(yyval.main).stopAdvanceFound = true;}
#line 1802 "parser.tab.c"
    break;

  case 30: /* stmt_list: stmt_list stmt  */
#line 286 "parser.y"
                          {(yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound || (yyvsp[0].main).stopAdvanceFound;}
#line 1808 "parser.tab.c"
    break;

  case 31: /* stmt_list: %empty  */
#line 287 "parser.y"
                        {(yyval.main).stopAdvanceFound = false;}
#line 1814 "parser.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 290 "parser.y"
            { addSymTabPtr(); }
#line 1820 "parser.tab.c"
    break;

  case 33: /* stmt_block: $@6 '{' stmt_list '}'  */
#line 290 "parser.y"
                                                   { (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound; delSymTabPtr(); }
#line 1826 "parser.tab.c"
    break;

  case 34: /* stmt_block_for: '{' stmt_list '}'  */
#line 293 "parser.y"
                                   { (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound; delSymTabPtr(); }
#line 1832 "parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN ret_var ENDLINE  */
#line 301 "parser.y"
                                     {ret_type = (yyvsp[-1].main).eletype; ret_flag = 1; ret_fig_flag = 1;}
#line 1838 "parser.tab.c"
    break;

  case 38: /* ret_var: construct  */
#line 303 "parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1844 "parser.tab.c"
    break;

  case 39: /* ret_var: expression  */
#line 303 "parser.y"
                                                            {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1850 "parser.tab.c"
    break;

  case 40: /* ret_var: %empty  */
#line 303 "parser.y"
                                                                                         {(yyval.main).eletype = Void;}
#line 1856 "parser.tab.c"
    break;

  case 41: /* assign_stmt: expression ENDLINE  */
#line 306 "parser.y"
                                 {lineArrNo = 0;}
#line 1862 "parser.tab.c"
    break;

  case 42: /* assign_stmt: construct ENDLINE  */
#line 307 "parser.y"
                                 {lineArrNo = 0;}
#line 1868 "parser.tab.c"
    break;

  case 43: /* construct: constructor '(' construct_param_list ')'  */
#line 336 "parser.y"
                                                      {(yyval.main).eletype = (yyvsp[-3].main).eletype; construct_params.clear(); }
#line 1874 "parser.tab.c"
    break;

  case 44: /* construct: constructor '(' ')'  */
#line 337 "parser.y"
                                {(yyval.main).eletype = (yyvsp[-2].main).eletype;}
#line 1880 "parser.tab.c"
    break;

  case 45: /* constructor: TRICONSTRUCT  */
#line 340 "parser.y"
                           { (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text + "Hello";}
#line 1886 "parser.tab.c"
    break;

  case 46: /* constructor: CIRCLECONSTRUCT  */
#line 341 "parser.y"
                              { (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1892 "parser.tab.c"
    break;

  case 47: /* constructor: PARACONSTRUCT  */
#line 342 "parser.y"
                            { (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1898 "parser.tab.c"
    break;

  case 48: /* constructor: REGPOLYCONSTRUCT  */
#line 343 "parser.y"
                               { (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1904 "parser.tab.c"
    break;

  case 49: /* valid_arg: construct  */
#line 346 "parser.y"
                     {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1910 "parser.tab.c"
    break;

  case 50: /* valid_arg: expression  */
#line 347 "parser.y"
                      {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 1916 "parser.tab.c"
    break;

  case 51: /* param_list: param_list ',' valid_arg  */
#line 350 "parser.y"
                                     {
              if(is_member) {
                  params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
          }
#line 1931 "parser.tab.c"
    break;

  case 52: /* param_list: valid_arg  */
#line 360 "parser.y"
                      {
              if(is_member) {
                     params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                     is_member = 0;
              }
              else {
                     vector<int> dim;
                     params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
          }
#line 1946 "parser.tab.c"
    break;

  case 53: /* construct_param_list: construct_param_list ',' valid_arg  */
#line 372 "parser.y"
                                                         {
              if(is_member) {
                  construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
          }
#line 1961 "parser.tab.c"
    break;

  case 54: /* construct_param_list: valid_arg  */
#line 382 "parser.y"
                      {
              if(is_member) {
                     construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                    is_member = 0;
                    
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({(yyvsp[0].main).eletype,Var,dim});   
              }
          }
#line 1977 "parser.tab.c"
    break;

  case 55: /* point: '(' expression ',' expression ',' STRING_TOKEN ')'  */
#line 395 "parser.y"
                                                            {  *(yyval.main).text = "(" + *(yyvsp[-5].main).text + "," + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text + ")"; (yyval.main).eletype = pointCheck((yyvsp[-5].main).eletype, (yyvsp[-3].main).eletype); }
#line 1983 "parser.tab.c"
    break;

  case 56: /* point: '(' expression ',' expression ')'  */
#line 396 "parser.y"
                                               {  *(yyval.main).text = "(" + *(yyvsp[-3].main).text + "," + *(yyvsp[-1].main).text +  ")";  (yyval.main).eletype = pointCheck((yyvsp[-3].main).eletype, (yyvsp[-1].main).eletype);}
#line 1989 "parser.tab.c"
    break;

  case 57: /* vertex: member_access  */
#line 400 "parser.y"
                      { if ((yyvsp[0].main).eletype != POINT) semanticError("Error: vertex has to be a point");}
#line 1995 "parser.tab.c"
    break;

  case 59: /* angle: '<' vertex vertex vertex ',' BOOLEAN '>'  */
#line 405 "parser.y"
                                                  {(yyval.main).eletype = ANGLE;}
#line 2001 "parser.tab.c"
    break;

  case 60: /* angle: '<' vertex vertex vertex '>'  */
#line 406 "parser.y"
                                      {(yyval.main).eletype = ANGLE;}
#line 2007 "parser.tab.c"
    break;

  case 61: /* expression: expression '+' expression  */
#line 409 "parser.y"
                                        {  (yyval.main).eletype = sumTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "+" + *(yyvsp[0].main).text;}
#line 2013 "parser.tab.c"
    break;

  case 62: /* expression: expression '-' expression  */
#line 410 "parser.y"
                                        {  (yyval.main).eletype = diffTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "-" + *(yyvsp[0].main).text;}
#line 2019 "parser.tab.c"
    break;

  case 63: /* expression: expression '*' expression  */
#line 411 "parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "*" + *(yyvsp[0].main).text;}
#line 2025 "parser.tab.c"
    break;

  case 64: /* expression: expression '/' expression  */
#line 412 "parser.y"
                                        {  (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype); *(yyval.main).text = *(yyvsp[-2].main).text + "/" + *(yyvsp[0].main).text;}
#line 2031 "parser.tab.c"
    break;

  case 65: /* expression: expression '%' expression  */
#line 413 "parser.y"
                                        { if ((yyvsp[-2].main).eletype != INT || (yyvsp[0].main).eletype != INT) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = INT; *(yyval.main).text = *(yyvsp[-2].main).text + "%" + *(yyvsp[0].main).text;}
#line 2037 "parser.tab.c"
    break;

  case 66: /* expression: expression '^' expression  */
#line 414 "parser.y"
                                        { (yyval.main).eletype = mulTypeCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);*(yyval.main).text = "pow(" + *(yyvsp[-2].main).text + "," + *(yyvsp[0].main).text + ")";}
#line 2043 "parser.tab.c"
    break;

  case 67: /* expression: expression LINE_OP expression  */
#line 415 "parser.y"
                                            { *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ; if(((yyvsp[-2].main).eletype == POINT || (yyvsp[-2].main).eletype == LINEARR) && (yyvsp[0].main).eletype == POINT) {(yyval.main).eletype = LINEARR; lineArrNo++;} else  semanticError("Error: Semantic error incompatible datatype");}
#line 2049 "parser.tab.c"
    break;

  case 68: /* expression: expression PARALLEL expression  */
#line 416 "parser.y"
                                             { *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ; (yyval.main).eletype = parallelCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);}
#line 2055 "parser.tab.c"
    break;

  case 69: /* expression: expression PERPENDICULAR expression  */
#line 417 "parser.y"
                                                   {  *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ; cout<<*(yyval.main).text<<endl; (yyval.main).eletype = perpendicularCheck((yyvsp[-2].main).eletype, (yyvsp[0].main).eletype);}
#line 2061 "parser.tab.c"
    break;

  case 70: /* expression: PARALLEL inside_norm PARALLEL  */
#line 418 "parser.y"
                                             {(yyval.main).eletype = REAL;}
#line 2067 "parser.tab.c"
    break;

  case 71: /* expression: '-' expression  */
#line 419 "parser.y"
                                       {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = "-" + *(yyvsp[0].main).text;}
#line 2073 "parser.tab.c"
    break;

  case 72: /* expression: UNARY member_access  */
#line 420 "parser.y"
                                  {if(!((yyvsp[0].main).eletype == INT || (yyvsp[0].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2079 "parser.tab.c"
    break;

  case 73: /* expression: member_access UNARY  */
#line 421 "parser.y"
                                  {if(!((yyvsp[-1].main).eletype == INT || (yyvsp[-1].main).eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype;  *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2085 "parser.tab.c"
    break;

  case 74: /* expression: NOT expression  */
#line 422 "parser.y"
                             {if (!arithCompatible((yyvsp[0].main).eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;*(yyval.main).text = "!" + *(yyvsp[-1].main).text;}
#line 2091 "parser.tab.c"
    break;

  case 75: /* expression: expression AND expression  */
#line 423 "parser.y"
                                        {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + "&&" + *(yyvsp[0].main).text; }
#line 2097 "parser.tab.c"
    break;

  case 76: /* expression: expression OR expression  */
#line 424 "parser.y"
                                       {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + "||" + *(yyvsp[0].main).text; }
#line 2103 "parser.tab.c"
    break;

  case 77: /* expression: member_access assign  */
#line 425 "parser.y"
                                         {if (!(((yyvsp[-1].main).eletype == (yyvsp[0].main).eletype) || coercible((yyvsp[-1].main).eletype, (yyvsp[0].main).eletype) || ((yyvsp[-1].main).eletype == LINE && (yyvsp[0].main).eletype == LINEARR && lineArrNo == 1))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[-1].main).eletype; }
#line 2109 "parser.tab.c"
    break;

  case 78: /* expression: expression CMP_OP expression  */
#line 426 "parser.y"
                                           {if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL;*(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2115 "parser.tab.c"
    break;

  case 79: /* expression: expression '<' expression  */
#line 427 "parser.y"
                                        { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + "<" + *(yyvsp[0].main).text; }
#line 2121 "parser.tab.c"
    break;

  case 80: /* expression: expression '>' expression  */
#line 428 "parser.y"
                                         { if(!(arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) && ((yyvsp[-2].main).eletype!=LABEL || (yyvsp[0].main).eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + ">" + *(yyvsp[0].main).text; }
#line 2127 "parser.tab.c"
    break;

  case 81: /* expression: expression EQ_CMP_OP expression  */
#line 429 "parser.y"
                                              {if(!((arithCompatible((yyvsp[-2].main).eletype) && arithCompatible((yyvsp[0].main).eletype)) || ((yyvsp[-2].main).eletype == (yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = BOOL; *(yyval.main).text = *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;}
#line 2133 "parser.tab.c"
    break;

  case 82: /* expression: member_access  */
#line 430 "parser.y"
                            {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2139 "parser.tab.c"
    break;

  case 83: /* expression: '(' expression ')'  */
#line 431 "parser.y"
                                 {(yyval.main).eletype = (yyvsp[-1].main).eletype;*(yyval.main).text = "(" + *(yyvsp[-1].main).text + ")";}
#line 2145 "parser.tab.c"
    break;

  case 84: /* expression: FLOATS  */
#line 432 "parser.y"
                     { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2151 "parser.tab.c"
    break;

  case 85: /* expression: INTEGERS  */
#line 433 "parser.y"
                       { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2157 "parser.tab.c"
    break;

  case 86: /* expression: BOOLEAN  */
#line 434 "parser.y"
                      { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).constExp.eletype;}
#line 2163 "parser.tab.c"
    break;

  case 87: /* expression: STRING_TOKEN  */
#line 435 "parser.y"
                           { *(yyval.main).text = *(yyvsp[0].main).text ; (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2169 "parser.tab.c"
    break;

  case 88: /* expression: func_call  */
#line 436 "parser.y"
                        {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2175 "parser.tab.c"
    break;

  case 89: /* expression: point  */
#line 437 "parser.y"
                    { (yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2181 "parser.tab.c"
    break;

  case 90: /* expression: angle  */
#line 438 "parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype; *(yyval.main).text = *(yyvsp[0].main).text;}
#line 2187 "parser.tab.c"
    break;

  case 94: /* assign: EQUAL expression  */
#line 447 "parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2193 "parser.tab.c"
    break;

  case 95: /* assign: ASSIGN_OP expression  */
#line 448 "parser.y"
                                {if(!(arithCompatible((yyvsp[0].main).eletype))) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; }
#line 2199 "parser.tab.c"
    break;

  case 96: /* assign: SUM_ASSIGN_OP expression  */
#line 449 "parser.y"
                                    {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == LABEL || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype; }
#line 2205 "parser.tab.c"
    break;

  case 97: /* assign: SUB_ASSIGN_OP expression  */
#line 450 "parser.y"
                                  {if(!(arithCompatible((yyvsp[0].main).eletype) || (yyvsp[0].main).eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2211 "parser.tab.c"
    break;

  case 98: /* decl_stmt: DATATYPE id_list ENDLINE  */
#line 454 "parser.y"
                                     {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);lineArrNo = 0;}
#line 2217 "parser.tab.c"
    break;

  case 99: /* decl_stmt: constructor id_list ENDLINE  */
#line 455 "parser.y"
                                        {typeUpdate((yyvsp[-1].main).nameList, (yyvsp[-2].main).eletype);lineArrNo = 0;}
#line 2223 "parser.tab.c"
    break;

  case 100: /* id_list: id_list ',' ID check_arr EQUAL arr_assign_line  */
#line 458 "parser.y"
                                                        {(yyval.main).nameList = (yyvsp[-5].main).nameList;(yyval.main).nameList->push_back((yyvsp[-3].main).name);compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);}
#line 2229 "parser.tab.c"
    break;

  case 101: /* id_list: id_list ',' ID check_arr  */
#line 459 "parser.y"
                                   {(yyval.main).nameList = (yyvsp[-3].main).nameList;(yyval.main).nameList->push_back((yyvsp[-1].main).name);insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);}
#line 2235 "parser.tab.c"
    break;

  case 102: /* id_list: id_list ',' ID decl_assign  */
#line 460 "parser.y"
                                    {(yyval.main).nameList = (yyvsp[-3].main).nameList;(yyval.main).nameList->push_back((yyvsp[-1].main).name);insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);}
#line 2241 "parser.tab.c"
    break;

  case 103: /* id_list: ID check_arr  */
#line 461 "parser.y"
                       {(yyval.main).nameList = new vector<char*>;(yyval.main).nameList->push_back((yyvsp[-1].main).name);insertArray((yyvsp[-1].main).name, (yyvsp[0].main).dimList);}
#line 2247 "parser.tab.c"
    break;

  case 104: /* id_list: ID check_arr EQUAL arr_assign_line  */
#line 462 "parser.y"
                                            {(yyval.main).nameList = new vector<char*>;(yyval.main).nameList->push_back((yyvsp[-3].main).name);compareAndInsertArray((yyvsp[-3].main).name, (yyvsp[-2].main).dimList, (yyvsp[0].main).listAndType.eletype, (yyvsp[0].main).listAndType.dimList);}
#line 2253 "parser.tab.c"
    break;

  case 105: /* id_list: ID decl_assign  */
#line 463 "parser.y"
                        {(yyval.main).nameList = new vector<char*>;(yyval.main).nameList->push_back((yyvsp[-1].main).name);insertType((yyvsp[-1].main).name, Var, (yyvsp[0].main).eletype);}
#line 2259 "parser.tab.c"
    break;

  case 106: /* decl_assign: EQUAL decl_token  */
#line 466 "parser.y"
                              {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2265 "parser.tab.c"
    break;

  case 107: /* decl_assign: %empty  */
#line 467 "parser.y"
                      {(yyval.main).eletype = UNDEF;}
#line 2271 "parser.tab.c"
    break;

  case 108: /* decl_token: construct  */
#line 470 "parser.y"
                       {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2277 "parser.tab.c"
    break;

  case 109: /* decl_token: expression  */
#line 471 "parser.y"
                    {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2283 "parser.tab.c"
    break;

  case 110: /* check_arr: dim  */
#line 475 "parser.y"
               {(yyval.main).dimList = (yyvsp[0].main).dimList;}
#line 2289 "parser.tab.c"
    break;

  case 111: /* check_arr: '[' ']'  */
#line 476 "parser.y"
                  {(yyval.main).dimList = new vector<int>;(yyval.main).dimList->push_back(-1);}
#line 2295 "parser.tab.c"
    break;

  case 112: /* check_arr: '[' ']' dim  */
#line 477 "parser.y"
                      {(yyval.main).dimList = new vector<int>;addFrontAndCopy((yyval.main).dimList, (yyvsp[0].main).dimList, -1);delete (yyvsp[0].main).dimList;}
#line 2301 "parser.tab.c"
    break;

  case 113: /* dim: dim '[' const_expr ']'  */
#line 480 "parser.y"
                             {(yyval.main).dimList = (yyvsp[-3].main).dimList;
                              
                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);
                            
                            }
#line 2314 "parser.tab.c"
    break;

  case 114: /* dim: '[' const_expr ']'  */
#line 488 "parser.y"
                         {(yyval.main).dimList = new vector<int>; 

                            if ((yyvsp[-1].main).constExp.eletype == REAL)
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.d);
                            else              
                                   (yyval.main).dimList->push_back((yyvsp[-1].main).constExp.i);
                         }
#line 2326 "parser.tab.c"
    break;

  case 115: /* arr_assign_line: arr_assign  */
#line 499 "parser.y"
                             {(yyval.main).listAndType.dimList = (yyvsp[0].main).listAndType.dimList;(yyval.main).listAndType.eletype = (yyvsp[0].main).listAndType.eletype;}
#line 2332 "parser.tab.c"
    break;

  case 116: /* arr_assign_line: expression  */
#line 500 "parser.y"
                             {
                            if ((yyvsp[0].main).eletype != LINEARR) 
                                   semanticError("Error: Invalid Datatypes\n");
                            (yyval.main).listAndType.dimList = new vector<int>;
                            (yyval.main).listAndType.dimList->push_back(lineArrNo);
                            lineArrNo = 0;
                     }
#line 2344 "parser.tab.c"
    break;

  case 117: /* arr_assign: '{' arr1d_in_list '}'  */
#line 509 "parser.y"
                                    {(yyval.main).listAndType.dimList = new vector<int>; (yyval.main).listAndType.dimList->push_back((yyvsp[-1].main).countAndType.count); (yyval.main).listAndType.eletype = (yyvsp[-1].main).countAndType.eletype;}
#line 2350 "parser.tab.c"
    break;

  case 118: /* arr_assign: '{' comma_arr_assign '}'  */
#line 510 "parser.y"
                                      {(yyval.main).listAndType.dimList = (yyvsp[-1].main).listAndType.dimList;(yyval.main).listAndType.eletype = (yyvsp[-1].main).listAndType.eletype;}
#line 2356 "parser.tab.c"
    break;

  case 119: /* comma_arr_assign: comma_arr_assign ',' arr_assign  */
#line 513 "parser.y"
                                                   {updateMaxDim((yyvsp[-2].main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList); delete (yyvsp[0].main).listAndType.dimList;(yyval.main).listAndType.dimList = (yyvsp[-2].main).listAndType.dimList;if (!coercible((yyvsp[-2].main).listAndType.eletype, (yyvsp[0].main).listAndType.eletype)) semanticError("arrays should be initialized with same datatype");else (yyval.main).listAndType.eletype = (yyvsp[-2].main).listAndType.eletype;}
#line 2362 "parser.tab.c"
    break;

  case 120: /* comma_arr_assign: arr_assign  */
#line 514 "parser.y"
                             {(yyval.main).listAndType.dimList = new vector<int>; addFrontAndCopy((yyval.main).listAndType.dimList, (yyvsp[0].main).listAndType.dimList, 1);delete (yyvsp[0].main).listAndType.dimList;(yyval.main).listAndType.eletype = (yyvsp[0].main).listAndType.eletype;}
#line 2368 "parser.tab.c"
    break;

  case 121: /* arr1d_in_list: mult_elements  */
#line 517 "parser.y"
                             {(yyval.main).countAndType.count = (yyvsp[0].main).countAndType.count;(yyval.main).eletype = (yyvsp[0].main).countAndType.eletype;}
#line 2374 "parser.tab.c"
    break;

  case 122: /* arr1d_in_list: %empty  */
#line 518 "parser.y"
                           {(yyval.main).countAndType.count = 0;(yyval.main).eletype = UNDEF;}
#line 2380 "parser.tab.c"
    break;

  case 123: /* mult_elements: mult_elements ',' expression  */
#line 521 "parser.y"
                                              {(yyval.main).count = (yyvsp[-2].main).countAndType.count + 1; if (!coercible((yyvsp[-2].main).countAndType.eletype, (yyvsp[0].main).eletype)) semanticError("arrays should be initialized with same datatype");else (yyval.main).countAndType.eletype = (yyvsp[0].main).eletype;}
#line 2386 "parser.tab.c"
    break;

  case 124: /* mult_elements: expression  */
#line 522 "parser.y"
                           {(yyval.main).countAndType.count = 1;(yyval.main).countAndType.eletype = (yyvsp[0].main).eletype;}
#line 2392 "parser.tab.c"
    break;

  case 125: /* const_expr: const_expr '+' const_expr  */
#line 525 "parser.y"
                                      {(yyval.main).constExp.eletype = sumTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d + (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i + (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d + (yyvsp[0].main).constExp.i;
                                          else 
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i + (yyvsp[0].main).constExp.i;                           
                                          

                                      }
#line 2410 "parser.tab.c"
    break;

  case 126: /* const_expr: const_expr '-' const_expr  */
#line 538 "parser.y"
                                   {(yyval.main).constExp.eletype = diffTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d - (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i - (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d - (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i - (yyvsp[0].main).constExp.i;
                                   
                                   }
#line 2427 "parser.tab.c"
    break;

  case 127: /* const_expr: const_expr '*' const_expr  */
#line 550 "parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d * (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i * (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d * (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i * (yyvsp[0].main).constExp.i;
                                          
                                   }
#line 2444 "parser.tab.c"
    break;

  case 128: /* const_expr: const_expr '/' const_expr  */
#line 562 "parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d / (yyvsp[0].main).constExp.d;
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.i / (yyvsp[0].main).constExp.d;  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = (yyvsp[-2].main).constExp.d / (yyvsp[0].main).constExp.i;
                                          else
                                                 (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i / (yyvsp[0].main).constExp.i;
                                   }
#line 2460 "parser.tab.c"
    break;

  case 129: /* const_expr: const_expr '%' const_expr  */
#line 573 "parser.y"
                                   {if ((yyvsp[-2].main).constExp.eletype != INT || (yyvsp[0].main).constExp.eletype != INT) semanticError("Error: Semantic error incompatible datatype");(yyval.main).constExp.eletype = INT;
                                          (yyval.main).constExp.i = (yyvsp[-2].main).constExp.i % (yyvsp[0].main).constExp.i;
                                   }
#line 2468 "parser.tab.c"
    break;

  case 130: /* const_expr: const_expr '^' const_expr  */
#line 576 "parser.y"
                                   {(yyval.main).constExp.eletype = mulTypeCheck((yyvsp[-2].main).constExp.eletype, (yyvsp[0].main).constExp.eletype);

                                          if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.d, (yyvsp[0].main).constExp.d);
                                          else if ((yyvsp[-2].main).constExp.eletype == INT && (yyvsp[0].main).constExp.eletype == REAL)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.i, (yyvsp[0].main).constExp.d);  
                                          else if ((yyvsp[-2].main).constExp.eletype == REAL && (yyvsp[0].main).constExp.eletype == INT)
                                                 (yyval.main).constExp.d = pow((yyvsp[-2].main).constExp.d, (yyvsp[0].main).constExp.i);
                                          else
                                                 (yyval.main).constExp.i = pow((yyvsp[-2].main).constExp.i, (yyvsp[0].main).constExp.i);

                                   }
#line 2485 "parser.tab.c"
    break;

  case 131: /* const_expr: '-' const_expr  */
#line 588 "parser.y"
                        {if (!arithCompatible((yyvsp[0].main).constExp.eletype)) semanticError("Error: Semantic error incompatible datatype"); (yyval.main).constExp.eletype = (yyvsp[0].main).constExp.eletype;

                            if ((yyval.main).constExp.eletype == REAL) 
                                   (yyval.main).constExp.d = -(yyvsp[0].main).constExp.d; 
                            else 
                                   (yyval.main).constExp.i = -(yyvsp[0].main).constExp.i;
                        }
#line 2497 "parser.tab.c"
    break;

  case 132: /* const_expr: '(' const_expr ')'  */
#line 595 "parser.y"
                            {
                                   (yyval.main).constExp.eletype = (yyvsp[-1].main).constExp.eletype;
                                   if ((yyval.main).constExp.eletype == REAL) 
                                          (yyval.main).constExp.d = (yyvsp[-1].main).constExp.d; 
                                   else 
                                          (yyval.main).constExp.i = (yyvsp[-1].main).constExp.i;
                            }
#line 2509 "parser.tab.c"
    break;

  case 133: /* const_expr: FLOATS  */
#line 602 "parser.y"
                {(yyval.main).eletype = (yyvsp[0].main).constExp.eletype;(yyval.main).constExp.d = (yyvsp[0].main).constExp.d;}
#line 2515 "parser.tab.c"
    break;

  case 134: /* const_expr: INTEGERS  */
#line 603 "parser.y"
                  {(yyval.main).eletype = (yyvsp[0].main).constExp.eletype;(yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2521 "parser.tab.c"
    break;

  case 135: /* const_expr: BOOLEAN  */
#line 604 "parser.y"
                 {(yyval.main).eletype = INT;(yyval.main).constExp.i = (yyvsp[0].main).constExp.i;}
#line 2527 "parser.tab.c"
    break;

  case 136: /* member_access: memb_access  */
#line 609 "parser.y"
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
#line 2545 "parser.tab.c"
    break;

  case 137: /* memb_access: memb_access '.' ID arr_access  */
#line 623 "parser.y"
                                            {
                     (yyval.main).dimCount = (yyvsp[-3].main).dimCount; 
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});
                     }

                     *(yyval.main).text = *(yyvsp[-3].main).text + "." + *(yyvsp[-1].main).text + *(yyvsp[0].main).text;
              }
#line 2559 "parser.tab.c"
    break;

  case 138: /* memb_access: ID arr_access  */
#line 632 "parser.y"
                              {
                     int count = checkDims((yyvsp[-1].main).name,(yyvsp[0].main).count);
                     (yyval.main).dimCount = new vector<cntAndType> ;   //free?
                     if(count >= 0) {
                            (yyval.main).dimCount->push_back({count,(yyvsp[-1].main).name});  
                     } 
                     *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text;    
              }
#line 2572 "parser.tab.c"
    break;

  case 139: /* arr_access: arr_access '[' expression ']'  */
#line 643 "parser.y"
                                          {(yyval.main).count = (yyvsp[-3].main).count; (yyval.main).count = (yyval.main).count + 1; *(yyval.main).text = *(yyvsp[-3].main).text + "[" + *(yyvsp[-1].main).text + "]";}
#line 2578 "parser.tab.c"
    break;

  case 140: /* arr_access: %empty  */
#line 644 "parser.y"
                        {(yyval.main).count = 0; *(yyval.main).text = "";}
#line 2584 "parser.tab.c"
    break;

  case 141: /* $@7: %empty  */
#line 647 "parser.y"
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
#line 2601 "parser.tab.c"
    break;

  case 142: /* func_call: member_access $@7 '(' param_list_opt ')'  */
#line 659 "parser.y"
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
              // *$$.text = *$1.text + "(" + *$3.text + ")";
       }
#line 2624 "parser.tab.c"
    break;

  case 143: /* param_list_opt: param_list  */
#line 679 "parser.y"
                            {/**$$.text = *$1.text;*/}
#line 2630 "parser.tab.c"
    break;

  case 144: /* param_list_opt: %empty  */
#line 680 "parser.y"
                             {/**$$.text = "";*/}
#line 2636 "parser.tab.c"
    break;

  case 145: /* empty_space: empty_space ENDLINE  */
#line 683 "parser.y"
                                  { *(yyval.main).text = *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;}
#line 2642 "parser.tab.c"
    break;

  case 146: /* empty_space: %empty  */
#line 684 "parser.y"
                                  { *(yyval.main).text = " " ;}
#line 2648 "parser.tab.c"
    break;

  case 147: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE  */
#line 690 "parser.y"
              {     
                     (yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;
                     if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");
                     *(yyval.main).text = *(yyvsp[-6].main).text + "(" + *(yyvsp[-4].main).text + ")" + *(yyvsp[-2].main).text + *(yyvsp[-1].main).text + *(yyvsp[0].main).text ;
                     // cout << *$$.text << endl;
                     // fprintf(fout_translated, "%s", $$.text->c_str());
              }
#line 2660 "parser.tab.c"
    break;

  case 148: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE ELSE empty_space stmt_block ENDLINE  */
#line 697 "parser.y"
                                                                                                      {(yyval.main).stopAdvanceFound = (yyvsp[-5].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;if(!(arithCompatible((yyvsp[-8].main).eletype))) semanticError("Error: Semantic error incompatible datatype");}
#line 2666 "parser.tab.c"
    break;

  case 149: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt ELSE empty_space stmt_block ENDLINE  */
#line 698 "parser.y"
                                                                                                               {(yyval.main).stopAdvanceFound = (yyvsp[-6].main).stopAdvanceFound||(yyvsp[-4].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;if(!(arithCompatible((yyvsp[-9].main).eletype))) semanticError("Error: Semantic error incompatible datatype");}
#line 2672 "parser.tab.c"
    break;

  case 150: /* cond_stmt: IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt  */
#line 699 "parser.y"
                                                                           {(yyval.main).stopAdvanceFound = (yyvsp[-2].main).stopAdvanceFound||(yyvsp[0].main).stopAdvanceFound;if(!(arithCompatible((yyvsp[-5].main).eletype))) semanticError("Error: Semantic error incompatible datatype");}
#line 2678 "parser.tab.c"
    break;

  case 151: /* elif_stmt: ELIF '(' expression ')' empty_space stmt_block ENDLINE  */
#line 702 "parser.y"
                                                                    {(yyval.main).stopAdvanceFound = (yyvsp[-1].main).stopAdvanceFound;if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");}
#line 2684 "parser.tab.c"
    break;

  case 152: /* elif_stmt: elif_stmt ELIF '(' expression ')' empty_space stmt_block ENDLINE  */
#line 703 "parser.y"
                                                                             {(yyval.main).stopAdvanceFound = (yyvsp[-7].main).stopAdvanceFound||(yyvsp[-1].main).stopAdvanceFound;if(!(arithCompatible((yyvsp[-4].main).eletype))) semanticError("Error: Semantic error incompatible datatype");}
#line 2690 "parser.tab.c"
    break;

  case 155: /* $@8: %empty  */
#line 713 "parser.y"
                { addSymTabPtr(); }
#line 2696 "parser.tab.c"
    break;

  case 156: /* for_loop_decl: $@8 DATATYPE ID EQUAL expression  */
#line 713 "parser.y"
                                                                 { insertType((yyvsp[-2].main).name, Var, (yyvsp[-3].main).eletype);delete (yyvsp[-2].main).name;}
#line 2702 "parser.tab.c"
    break;

  case 157: /* $@9: %empty  */
#line 714 "parser.y"
                { addSymTabPtr(); }
#line 2708 "parser.tab.c"
    break;

  case 158: /* for_loop_decl: $@9 ID EQUAL expression  */
#line 714 "parser.y"
                                                        { delete (yyvsp[-2].main).name; }
#line 2714 "parser.tab.c"
    break;

  case 159: /* for_loop_decl: %empty  */
#line 715 "parser.y"
                { addSymTabPtr(); }
#line 2720 "parser.tab.c"
    break;

  case 160: /* optional_arg: expression  */
#line 718 "parser.y"
                          {(yyval.main).eletype = (yyvsp[0].main).eletype;}
#line 2726 "parser.tab.c"
    break;

  case 161: /* optional_arg: %empty  */
#line 719 "parser.y"
                          {(yyval.main).eletype = UNDEF;}
#line 2732 "parser.tab.c"
    break;

  case 162: /* for_loop: FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' empty_space stmt_block_for  */
#line 722 "parser.y"
                                                                                                  {if(!(arithCompatible((yyvsp[-5].main).eletype)) && (yyvsp[-5].main).eletype != UNDEF) semanticError("Error: Semantic error incompatible datatype11");}
#line 2738 "parser.tab.c"
    break;


#line 2742 "parser.tab.c"

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

#line 728 "parser.y"


/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

string function_translation(string text) {
       return "true";
}

string fig_translation(string text) {
       return "true";
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
    fprintf(fout_translated,"#include<string>\n");
    fprintf(fout_translated,"#include<stdlib.h>\n");
    fprintf(fout_translated,"#include<math.h>\n");
    fprintf(fout_translated,"#include<deque>\n");
    fprintf(fout_translated,"#include \"standard_lib.hpp \" \n");


    insertConstructTab();

    int x = yyparse();

    fclose(fp);
    fclose(fout_token);
    return x;
} 
