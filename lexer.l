%option yylineno

%{

#include "symbol_table.hpp"
#include <stdio.h>
#include <string.h>
#include <math.h>
// #include "y.tab.h"
#include "parser.tab.h" 

extern FILE *fout_token;

char* dupString(char* src);

//Free all main.text !!!

%}

integers [1-9][0-9]*|0
floats (\.[0-9]+|[1-9][0-9]*\.[0-9]*|0\.[0-9]+)  
parenthesis "["|"]"|"{"|"}"|"("|")"
punctuation ,
triConstruct "Tri"
circleConstruct "Circle"
regPolyConstruct "RegPoly"
paraConstruct "Para"
line_op "->"|"<->"
cmp_op ">="|"<="
datatype "int"|"real"|"bool"|"point"|"angle"|"label"|"line"|"circle"|"tri"|"para"|"regPoly"|"linearr"
assign "^:="|"/:="|"%:="|"*:="
unary "++"|"--"
operators "+"|"*"|"/"|"%"|"^"|"-"
string_literal (\"([^"]|"\\\"")*\")
id [a-zA-Z_][a-zA-Z0-9_]*

%%
{floats} {
    yylval.main.constExp.eletype = REAL;
    yylval.main.constExp.d = atof(yytext);
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "FLOATS: %s\n", yytext);
    return FLOATS;
}

{triConstruct} {
    yylval.main.eletype = TRI;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return TRICONSTRUCT;
}

{circleConstruct} {
    yylval.main.eletype = CIRCLE;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return CIRCLECONSTRUCT;
}

{regPolyConstruct} {
    yylval.main.eletype = REGPOLY;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return REGPOLYCONSTRUCT;
}

{paraConstruct} {
    yylval.main.eletype = PARA;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return PARACONSTRUCT;
}

{parenthesis} {
    fprintf(fout_token, "PARENTHESIS: %s\n", yytext);
    return *yytext;
}

printSymbolTable {
    printSymbolTable();
}

scale {  //add main.text ?
    fprintf(fout_token, "KEYWORD: %s\n", yytext);
    return SCALE;
}

center {  //add main.text ?
    fprintf(fout_token, "KEYWORD: %s\n", yytext);
    return CENTER;
}

{punctuation} {
    fprintf(fout_token, "PUNCTUATION: %s\n", yytext);
    return *yytext;
}

{integers} {
    yylval.main.constExp.i = atoi(yytext);
    yylval.main.constExp.eletype = INT;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "INTEGERS: %s\n", yytext);
    return INTEGERS;
}

{line_op} {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    
    fprintf(fout_token, "LINE_OP: %s\n", yytext);
    return LINE_OP;
}

"."  {fprintf(fout_token, "MEMEBER ACCESS: .\n"); return *yytext;}

$.*     { fprintf(fout_token, "LINE COMMENT: %s\n", yytext);}
"$$"([^$]|$[^$])*"$$" { fprintf(fout_token, "BLOCK COMMENT: %s\n", yytext);}

"if" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "IF: %s\n", yytext);
    return IF;
} 

"elif" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "ELIF: %s\n", yytext);
    return ELIF;
}

"else" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "ELSE: %s\n", yytext);
    return ELSE;
}

"repeat" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "FOR: %s\n", yytext);
    return FOR;
}

"until" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "WHILE: %s\n", yytext);
    return WHILE;
}

"return" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "RETURN: %s\n", yytext);
    return RETURN;
}

"void" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    if (strcmp(yytext, "void") == 0) {
        yylval.main.eletype = Void;
    } 
    fprintf(fout_token, "VOID: %s\n", yytext);
    return VOID;
}

{operators} {
    fprintf(fout_token, "OPERATORS: %s\n", yytext);
    return *yytext;
}

"stop" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "STOP: %s\n", yytext);
    return BREAK;
}

"advance" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "CONTINUE: %s\n", yytext);
    return CONTINUE;
}

and {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "LOGICAL_OP: %s\n", yytext);
    return AND;
}

or {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "LOGICAL_OP: %s\n", yytext);
    return OR;
}

"||" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "PARALLEL: %s\n", yytext);
    return PARALLEL;
}

"|-" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "PERPENDICULAR: %s\n", yytext);
    return PERPENDICULAR;
}

"true" {
    yylval.main.constExp.eletype = BOOL;
    yylval.main.constExp.i = true;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "BOOLEAN: %s\n", yytext);
    return BOOLEAN;
}

"false" {
    yylval.main.constExp.eletype = BOOL;
    yylval.main.constExp.i = false;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
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
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "UNARY: %s\n", yytext);
    return UNARY;
}

"not" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "NOT: %s\n", yytext);
    return NOT;
}

{datatype} {
    
    if (strcmp(yytext, "int") == 0) {
        yylval.main.eletype = INT;
    } 
    else if (strcmp(yytext, "real") == 0) {
        yylval.main.eletype = REAL;
    } 
    else if (strcmp(yytext, "bool") == 0) {
        yylval.main.eletype = BOOL;
    } 
    else if (strcmp(yytext, "label") == 0) {
        yylval.main.eletype = LABEL;
    } 
    else if (strcmp(yytext, "tri") == 0) {
        yylval.main.eletype = TRI;
    } 
    else if (strcmp(yytext, "circle") == 0) {
        yylval.main.eletype = CIRCLE;
    } 
    else if (strcmp(yytext, "para") == 0) {
        yylval.main.eletype = PARA;
    } 
    else if (strcmp(yytext, "regPoly") == 0) {
        yylval.main.eletype = REGPOLY;
    } 
    else if (strcmp(yytext, "point") == 0) {
        yylval.main.eletype = POINT;
    } 
    else if (strcmp(yytext, "line") == 0) {
        yylval.main.eletype = LINE;
    } 
    else if (strcmp(yytext, "linearr") == 0) {
        // yylval.eletype = LINEARR;
        yylval.main.eletype = UNDEF;
    }
    else if (strcmp(yytext, "angle") == 0) {
        yylval.main.eletype = ANGLE;
    } 

    yylval.main.text = new string;
    *yylval.main.text = yytext;
    
    fprintf(fout_token, "DATATYPE: %s\n", yytext);
    return DATATYPE;
}

{cmp_op} {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "CMP_OP: %s\n", yytext);
    return CMP_OP;
}

"<"|">" {
    fprintf(fout_token, "CMP_OP/BRACKET: %s\n", yytext);
    return *yytext;
}

"=="|"!=" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "EQ_CMP_OP: %s\n", yytext);
    return EQ_CMP_OP;
} 

"|" {
    fprintf(fout_token, "SEPERATOR: %s\n", yytext);
    return *yytext;
}

"+:=" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "SUM_ASSIGN_OP: %s\n", yytext);
    return SUM_ASSIGN_OP;

}
"-:=" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "SUB_ASSIGN_OP: %s\n", yytext);
    return SUB_ASSIGN_OP;
}

":=" {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "EQUAL: %s\n", yytext);
    return EQUAL;
}

{assign} {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "ASSIGN_OP: %s\n", yytext);
    return ASSIGN_OP;
}

{string_literal}  {
    yylval.main.eletype = LABEL;
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "STRING_LITERAL: %s\n", yytext);
    return STRING_TOKEN;
}

{id} { 

    yylval.main.name = dupString(yytext); // have to free !
    yylval.main.text = new string;
    *yylval.main.text = yytext;
    fprintf(fout_token, "IDENTIFIER: %s\n", yytext);
    return ID;
}


[\t ]   {

}

\n  {
    yylval.main.text = new string;
    *yylval.main.text = yytext;
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
