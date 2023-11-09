%option yylineno

%{

#include "symbol_table.hpp"
#include <stdio.h>
#include <string.h>
#include <math.h>
// #include "y.tab.h"
#include "test.tab.h" 

extern FILE *fout_token;

char* dupString(char* src);

%}

integers [1-9][0-9]*|0
floats (\.[0-9]+|[1-9][0-9]*\.[0-9]*|0\.[0-9]+)  
parenthesis "["|"]"|"{"|"}"|"("|")"
punctuation ,
triConstruct "Tri"
circleConstruct "Circle"
regPolyConstruct "RegPoly"
paraConstruct "Para"
boolean  "true"|"false"
line_op "->"|"<->"
cmp_op ">="|"<="
datatype "int"|"real"|"bool"|"point"|"angle"|"label"|"line"|"circle"|"tri"|"para"|"regPoly"
assign "^:="|"/:="|"%:="|"*:="
unary "++"|"--"
operators "+"|"*"|"/"|"%"|"^"|"-"
string_literal (\"([^"]|"\\\"")*\")
id [a-zA-Z_][a-zA-Z0-9_]*

%%
{floats} {
    yylval.constExp.eletype = REAL;
    yylval.constExp.d = atof(yytext);
    fprintf(fout_token, "FLOATS: %s\n", yytext);
    return FLOATS;
}

{triConstruct} {
    yylval.eletype = TRI;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return TRICONSTRUCT;
}

{circleConstruct} {
    yylval.eletype = CIRCLE;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return CIRCLECONSTRUCT;
}

{regPolyConstruct} {
    yylval.eletype = REGPOLY;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return REGPOLYCONSTRUCT;
}

{paraConstruct} {
    yylval.eletype = PARA;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return PARACONSTRUCT;
}

{parenthesis} {
    fprintf(fout_token, "PARENTHESIS: %s\n", yytext);
    return *yytext;
}

scale {
    fprintf(fout_token, "KEYWORD: %s\n", yytext);
    return SCALE;
}

center {
    fprintf(fout_token, "KEYWORD: %s\n", yytext);
    return CENTER;
}

{punctuation} {
    fprintf(fout_token, "PUNCTUATION: %s\n", yytext);
    return *yytext;
}

{integers} {
    yylval.constExp.i = atoi(yytext);
    yylval.constExp.eletype = INT;
    fprintf(fout_token, "INTEGERS: %s\n", yytext);
    return INTEGERS;
}

{line_op} {
    fprintf(fout_token, "LINE_OP: %s\n", yytext);
    return LINE_OP;
}

"."  {fprintf(fout_token, "MEMEBER ACCESS: .\n"); return *yytext;}

$.*     { fprintf(fout_token, "LINE COMMENT: %s\n", yytext);}
"$$"([^$]|$[^$])*"$$" { fprintf(fout_token, "BLOCK COMMENT: %s\n", yytext);}

"if" {
    fprintf(fout_token, "IF: %s\n", yytext);
    return IF;
} 

"elif" {
    fprintf(fout_token, "ELIF: %s\n", yytext);
    return ELIF;
}

"else" {
    fprintf(fout_token, "ELSE: %s\n", yytext);
    return ELSE;
}

"repeat" {
    fprintf(fout_token, "FOR: %s\n", yytext);
    return FOR;
}

"until" {
    fprintf(fout_token, "WHILE: %s\n", yytext);
    return WHILE;
}

"return" {
    fprintf(fout_token, "RETURN: %s\n", yytext);
    return RETURN;
}

"void" {
    if (strcmp(yytext, "void") == 0) {
        yylval.eletype = Void;
    } 
    fprintf(fout_token, "VOID: %s\n", yytext);
    return VOID;
}

{operators} {
    fprintf(fout_token, "OPERATORS: %s\n", yytext);
    return *yytext;
}

"stop" {
    fprintf(fout_token, "STOP: %s\n", yytext);
    return BREAK;
}

"advance" {
    fprintf(fout_token, "CONTINUE: %s\n", yytext);
    return CONTINUE;
}

and {
    fprintf(fout_token, "LOGICAL_OP: %s\n", yytext);
    return AND;
}

or {
    fprintf(fout_token, "LOGICAL_OP: %s\n", yytext);
    return OR;
}

"||" {
    fprintf(fout_token, "PARALLEL: %s\n", yytext);
    return PARALLEL;
}

"|-" {
    fprintf(fout_token, "PERPENDICULAR: %s\n", yytext);
    return PERPENDICULAR;
}

"true" {
    yylval.constExp.eletype = BOOL;
    yylval.constExp.i = true;
    fprintf(fout_token, "BOOLEAN: %s\n", yytext);
    return BOOLEAN;
}

"false" {
    yylval.constExp.eletype = BOOL;
    yylval.constExp.i = false;
    fprintf(fout_token, "BOOLEAN: %s\n", yytext);
    return BOOLEAN;
}

"func" {
    fprintf(fout_token, "FUNC: %s\n", yytext);
    return FUNC;
}

"fig" {
    fprintf(fout_token, "FIG: %s\n", yytext);
    return FIG;
}

{unary} {
    fprintf(fout_token, "UNARY: %s\n", yytext);
    return UNARY;
}

"not" {
    fprintf(fout_token, "NOT: %s\n", yytext);
    return NOT;
}

{datatype} {
    
    if (strcmp(yytext, "int") == 0) {
        yylval.eletype = INT;
    } 
    else if (strcmp(yytext, "real") == 0) {
        yylval.eletype = REAL;
    } 
    else if (strcmp(yytext, "bool") == 0) {
        yylval.eletype = BOOL;
    } 
    else if (strcmp(yytext, "label") == 0) {
        yylval.eletype = LABEL;
    } 
    else if (strcmp(yytext, "tri") == 0) {
        yylval.eletype = TRI;
    } 
    else if (strcmp(yytext, "circle") == 0) {
        yylval.eletype = CIRCLE;
    } 
    else if (strcmp(yytext, "para") == 0) {
        yylval.eletype = PARA;
    } 
    else if (strcmp(yytext, "regPoly") == 0) {
        yylval.eletype = REGPOLY;
    } 
    else if (strcmp(yytext, "point") == 0) {
        yylval.eletype = POINT;
    } 
    else if (strcmp(yytext, "line") == 0) {
        yylval.eletype = LINE;
    } 
    else if (strcmp(yytext, "angle") == 0) {
        yylval.eletype = ANGLE;
    } 
    
    fprintf(fout_token, "DATATYPE: %s\n", yytext);
    return DATATYPE;
}

{cmp_op} {
    fprintf(fout_token, "CMP_OP: %s\n", yytext);
    return CMP_OP;
}

"<"|">" {
    fprintf(fout_token, "CMP_OP/BRACKET: %s\n", yytext);
    return *yytext;
}

"=="|"!=" {
    fprintf(fout_token, "EQ_CMP_OP: %s\n", yytext);
    return EQ_CMP_OP;
} 

"|" {
    fprintf(fout_token, "SEPERATOR: %s\n", yytext);
    return *yytext;
}

"+:=" {
    fprintf(fout_token, "SUM_ASSIGN_OP: %s\n", yytext);
    return SUM_ASSIGN_OP;

}
"-:=" {
    fprintf(fout_token, "SUB_ASSIGN_OP: %s\n", yytext);
    return SUB_ASSIGN_OP;
}

":=" {
    fprintf(fout_token, "EQUAL: %s\n", yytext);
    return EQUAL;
}
{assign} {
    fprintf(fout_token, "ASSIGN_OP: %s\n", yytext);
    return ASSIGN_OP;
}
{string_literal}  {
    yylval.eletype = LABEL;
    fprintf(fout_token, "STRING_LITERAL: %s\n", yytext);
    return STRING_TOKEN;
}

{id} { 

    yylval.name = dupString(yytext); // have to free !

    fprintf(fout_token, "IDENTIFIER: %s\n", yytext);
    return ID;
}


[\t ]   {

}

\n  {
    return ENDLINE;
}

. {
    fprintf(stderr, "Error: Invalid token: %s at line %d\n", yytext, yylineno);
    exit(1);
}

%%

int  yywrap(){
    return 1;
}

char* dupString(char* src){

    char* cpy = (char*)malloc(sizeof(char)*(yyleng+1));
    strcpy(cpy, src);
    return cpy;

}
