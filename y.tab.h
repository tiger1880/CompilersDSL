/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 130 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
