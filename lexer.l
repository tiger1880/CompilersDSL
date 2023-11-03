%option yylineno

%{

#include <stdio.h>
#include<string>
#include "y.tab.h"
extern FILE *fout_token;

%}

integers [1-9][0-9]*|0
floats (\.[0-9]+|[1-9][0-9]*\.[0-9]*|0\.[0-9]+)  
parenthesis "["|"]"|"{"|"}"|"("|")"
punctuation ,
constructor "Circle"|"Tri"|"RegPoly"|"Para"
boolean  "true"|"false"
line_op "->"|"<->"
cmp_op ">="|"<="
datatype "int"|"real"|"bool"|"point"|"angle"|"label"|"line"|"circle"|"tri"|"para"|"regPoly"
assign "+:="|"-:="|"^:="|"/:="|"%:="|"*:="
unary "++"|"--"
operators "+"|"*"|"/"|"%"|"^"|"-"
string_literal (\"([^"]|"\\\"")*\")
id [a-zA-Z_][a-zA-Z0-9_]*

%%
{floats} { // .05 1.
    fprintf(fout_token, "FLOATS: %s\n", yytext);
    return FLOATS;
}

{constructor} {
    fprintf(fout_token, "CONSTRUCTOR: %s\n", yytext);
    return CONSTRUCTOR;
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

{boolean} {
    fprintf(fout_token, "BOOLEAN: %s\n", yytext);
    return BOOLEAN;
}

"func" {
    //yylval.type = yytext;
    fprintf(fout_token, "FUNC: %s\n", yytext);
    return FUNC;
}

"fig" {
    //yylval.type = yytext;
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

{assign} {
    fprintf(fout_token, "ASSIGN_OP: %s\n", yytext);
    return ASSIGN_OP;
}

":=" {
    fprintf(fout_token, "EQUAL: %s\n", yytext);
    return EQUAL;
}

{string_literal}  {
    fprintf(fout_token, "STRING_LITERAL: %s\n", yytext);
    return STRING_TOKEN;
}

{id} { 
    yylval.name = yytext;
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
