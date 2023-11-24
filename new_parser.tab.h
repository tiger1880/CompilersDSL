/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_NEW_PARSER_TAB_H_INCLUDED
# define YY_YY_NEW_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGERS = 258,                /* INTEGERS  */
    BOOLEAN = 259,                 /* BOOLEAN  */
    FLOATS = 260,                  /* FLOATS  */
    LINE_OP = 261,                 /* LINE_OP  */
    IF = 262,                      /* IF  */
    ELIF = 263,                    /* ELIF  */
    ELSE = 264,                    /* ELSE  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    RETURN = 267,                  /* RETURN  */
    VOID = 268,                    /* VOID  */
    CONTINUE = 269,                /* CONTINUE  */
    BREAK = 270,                   /* BREAK  */
    PARALLEL = 271,                /* PARALLEL  */
    PERPENDICULAR = 272,           /* PERPENDICULAR  */
    FUNC = 273,                    /* FUNC  */
    FIG = 274,                     /* FIG  */
    UNARY = 275,                   /* UNARY  */
    DATATYPE = 276,                /* DATATYPE  */
    CMP_OP = 277,                  /* CMP_OP  */
    EQ_CMP_OP = 278,               /* EQ_CMP_OP  */
    ASSIGN_OP = 279,               /* ASSIGN_OP  */
    SUM_ASSIGN_OP = 280,           /* SUM_ASSIGN_OP  */
    SUB_ASSIGN_OP = 281,           /* SUB_ASSIGN_OP  */
    EQUAL = 282,                   /* EQUAL  */
    STRING_TOKEN = 283,            /* STRING_TOKEN  */
    ENDLINE = 284,                 /* ENDLINE  */
    ID = 285,                      /* ID  */
    MAIN = 286,                    /* MAIN  */
    TRICONSTRUCT = 287,            /* TRICONSTRUCT  */
    CIRCLECONSTRUCT = 288,         /* CIRCLECONSTRUCT  */
    PARACONSTRUCT = 289,           /* PARACONSTRUCT  */
    REGPOLYCONSTRUCT = 290,        /* REGPOLYCONSTRUCT  */
    NOT = 291,                     /* NOT  */
    AND = 292,                     /* AND  */
    OR = 293,                      /* OR  */
    SCALE = 294,                   /* SCALE  */
    CENTER = 295,                  /* CENTER  */
    NEG = 296                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
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
    

#line 141 "new_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_NEW_PARSER_TAB_H_INCLUDED  */
