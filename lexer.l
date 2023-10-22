%option yylineno

%{
#include <stdio.h>
#include "y.tab.h"
// extern int yylval;
// extern FILE* seq;
// extern FILE* parsed;
int line=0;
extern int error_flag;
%}

digit [0-9]
integers {digit}+
floats {integers}"."{integers}
parenthesis {"["|"]"|"{"|"}"|"("|")"}
constructor {"Circle"|"Tri"|"RegPoly"}
std_token {"INTERSECTION"|"MIDPOINT"|"SHORTEST_DISTANCE"|"ANGLE_BISECTOR"|"LINE_AT_ANGLE"|"TANGENT"|"COMMON_TANGENT"|"EXCENTRE"|"INCENTRE"|"CENTROID"|"CIRCUMCENTRE"|"ORTHOCENTRE"|"ALTITUDE"|"MEDIAN"|"DIAGONAL"|"AREA"|"PERIMETER"}
boolean {"true" | "false"}
line_op {"->"|"-"|"<->"}
relational {">"| "<" |">="| "<=" | "==" | "!=" }
datatype {"int"|"real"|"bool"|"point"|"angle"|"label"|"line"|"circle"|"tri"|"para"|"regPoly"}
logical {"and"|"or"}
assign {"+:="|"-:="|"^:="|"/:="|"%:="}
unary {"++"|"--"|"not"}
operators {"+"|"-"|"*"|"/"|"%"|"^"}
string_literals (\"([^"]|"\\\"")*\")
id [a-zA-Z_][a-zA-Z0-9_]*

%%

{floats} {
    return FLOATS;
}

{constructor} {
    return CONSTRUCTOR;
}

{parenthesis} {
    return PARENTHESIS;
}

{integers} {
    return INTEGERS;
    }

{line_op} {
    return LINE_OP;
}

"$"[^$]*\n {
    return SINGLE_COMMENT;
}


"$$"[^$]*"$$" {
    return MULTI_COMMENT;
}

"if" {
    return IF;
    } 

"elif" {
    return ELIF;
}

"else" {
    return ELSE;
}

"repeat" {
    return FOR;
    }

"until" {
    return WHILE;
}

"return" {
    return RETURN;
    }

"void" {
    // fprintf(parsed,"%s",yytext);
    // fprintf(seq,"datatype: %s\n",yytext);
    return VOID;
    }


{operators} {
    return OPERATORS;
}
"stop" {
    return BREAK;
}

"advance" {
    return CONTINUE;
}

{logical} {
    return LOGICAL_OP;
}

"||" {
    return PARALLEL;
}

"|-" {
    return PERPENDICULAR;
}


{boolean} {
    return BOOLEAN;
}

"func" {
    return FUNC;
}

"fig" {
    return FIG;
}

{unary} {
    return UNARY;
}


{datatype} {
    // fprintf(parsed,"%s",yytext);
    // fprintf(seq,"datatype: %s\n",yytext);
    return DATATYPE;
    }


{relational} {
    // fprintf(parsed,"%s",yytext);
    // fprintf(seq,"reserved keyword: %s\n",yytext);
    return REL_OP;
    }

{assign} {
    return ASSIGN_OP;
}

":=" {
    return EQUAL;
}
{string_literals}  {
    // fprintf(parsed,"%s",yytext);
    // fprintf(seq,"punctuation: \"\n");
    // fprintf(seq,"constant: %s\n", c);
    // fprintf(seq,"punctuation: \"\n");
    return STRING_TOKEN;
}
{id} { 
    
    fprintf(parsed,"%s",yytext);
    fprintf(seq,"ID: %s\n",yytext);
    return ID;
    }



[\t ]   {
    // fprintf(parsed,"%s",yytext); 
}

\n  {
    line++; 
    // if(error_flag!=0) 
    // {
    //     // fprintf(parsed," : invalid statement");
    //     exit(1);
    // }
    // fprintf(parsed,"%s",yytext); 
    return ENDLINE;
    }

%%


int  yywrap() {
    return 1;
}
