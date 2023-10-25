%option yylineno

%{

#include <stdio.h>
#include "y.tab.h"
extern FILE *fp,*fout_token,*fout_parse ;
int line = 0; // what is yylineno for then ?
extern int error_flag; // ?? 

%}

digit [0-9]
integers {digit}+
floats {integers}"."{integers}
parenthesis "["|"]"|"{"|"}"|"("|")"
punctuation ,
constructor "Circle"|"Tri"|"RegPoly"|"Para"
std_token "INTERSECTION"|"MIDPOINT"|"SHORTEST_DISTANCE"|"ANGLE_BISECTOR"|"LINE_AT_ANGLE"|"TANGENT"|"COMMON_TANGENT"|"EXCENTRE"|"INCENTRE"|"CENTROID"|"CIRCUMCENTRE"|"ORTHOCENTRE"|"ALTITUDE"|"MEDIAN"|"DIAGONAL"|"AREA"|"PERIMETER"
boolean  "true"|"false"
line_op "->"|"<->"
relational ">"|"<"|">="|"<="|"=="|"!=" 
datatype "int"|"real"|"bool"|"point"|"angle"|"label"|"line"|"circle"|"tri"|"para"|"regPoly"
logical "and"|"or"
assign "+:="|"-:="|"^:="|"/:="|"%:="
unary "++"|"--"
operators "+"|"*"|"/"|"%"|"^"|"-"
string_literal (\"([^"]|"\\\"")*\")
id [a-zA-Z_][a-zA-Z0-9_]*

%%
{floats} {
    printf("FLOATS: %s\n", yytext);
    return FLOATS;
}

{constructor} {
    printf("CONSTRUCTOR: %s\n", yytext);
    return CONSTRUCTOR;
}

{parenthesis} {
    printf("PARENTHESIS: %s\n", yytext);
    return *yytext;
}

{punctuation} {
    printf("PUNCTUATION: %s\n", yytext);
    return *yytext;
}

{integers} {
    printf("INTEGERS: %s\n", yytext);
    return INTEGERS;
}

{line_op} {
    printf("LINE_OP: %s\n", yytext);
    return LINE_OP;
}

$.*     { printf("line comment: %s\n", yytext);}
"$$"([^$]|$[^$])*"$$" { printf("block comment: %s\n", yytext);}

"if" {
    printf("IF: %s\n", yytext);
    return IF;
} 

"elif" {
    printf("ELIF: %s\n", yytext);
    return ELIF;
}

"else" {
    printf("ELSE: %s\n", yytext);
    return ELSE;
}

"repeat" {
    printf("FOR: %s\n", yytext);
    return FOR;
}

"until" {
    printf("WHILE: %s\n", yytext);
    return WHILE;
}

"return" {
    printf("RETURN: %s\n", yytext);
    return RETURN;
}

"void" {
    printf("VOID: %s\n", yytext);
    return VOID;
}

{operators} {
    printf("OPERATORS: %s\n", yytext);
    return *yytext;
}

"stop" {
    printf("STOP: %s\n", yytext);
    return BREAK;
}

"advance" {
    printf("CONTINUE: %s\n", yytext);
    return CONTINUE;
}

{logical} {
    printf("LOGICAL_OP: %s\n", yytext);
    return LOGICAL_OP;
}

"||" {
    printf("PARALLEL: %s\n", yytext);
    return PARALLEL;
}

"|-" {
    printf("PERPENDICULAR: %s\n", yytext);
    return PERPENDICULAR;
}

{boolean} {
    printf("BOOLEAN: %s\n", yytext);
    return BOOLEAN;
}

"func" {
    printf("FUNC: %s\n", yytext);
    return FUNC;
}

"fig" {
    printf("FIG: %s\n", yytext);
    return FIG;
}

{unary} {
    printf("UNARY: %s\n", yytext);
    return UNARY;
}

"not" {
    printf("NOT: %s\n", yytext);
    return NOT;
}

{datatype} {
    printf("DATATYPE: %s\n", yytext);
    return DATATYPE;
}

{relational} {
    printf("REL_OP: %s\n", yytext);
    return REL_OP;
}

{assign} {
    printf("ASSIGN_OP: %s\n", yytext);
    return ASSIGN_OP;
}

":=" {
    printf("EQUAL: %s\n", yytext);
    return EQUAL;
}

{string_literal}  {
    printf("STRING_LITERAL: %s\n", yytext);
    return STRING_TOKEN;
}

{id} { 
    printf("IDENTIFIER: %s\n", yytext);
    return ID;
}


[\t ]   {

}

\n  {
    line++; 
    // if(error_flag!=0) 
    // {
    //     // fprintf(parsed," : invalid statement");
    //     exit(1);
    // }
    // fprintf(parsed,"%s",yytext); 
    // return ENDLINE;
}

. {
    printf("Invalid token: %s\n", yytext);
}

%%


int  yywrap(){

    return 1;
}

/*
int main(){

    printf("here we are\n");

    int x;
    do{
        x = yylex();
    }
    while(x != 0);

    printf("and now we are no more\n");

    return 0;
}
*/