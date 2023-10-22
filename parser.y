%{
#include <stdio.h>
FILE *yyin; // input file
extern FILE *fp,*fout_token,*fout_parse ;
void yyerror(char *s);
int yylex();
%}
/* %start S */
%token INTEGERS
%token LINE_OP  
%token IF
%token ELIF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token VOID
%token CONTINUE
%token LOGICAL_OP
%token PARALLEL
%token PERPENDICULAR
%token BOOLEAN
%token FUNC
%token FIG
%token UNARY
%token DATATYPE
%token REL_OP
%token ASSIGN_OP
%token EQUAL
%token STRING_TOKEN
%token ENDLINE
%token ID
%token FLOATS
%token CONSTRUCTOR
%token NOT
%%

 S: Func S| Fig S|;
 Func: ;
 Fig: ;
 Decl : DATATYPE ID_LIST ENDLINE;
 ID_LIST : ID check_arr decl_assign ',' ID_LIST  |  ID  check_arr decl_assign;
 decl_assign : EQUAL decl_token | ;
 decl_token :  STATEMENT  | point_assign | angle_assign |construct | arr_assign | line_assign | construct; 
 check_arr: '[' INTEGERS  ']' | '[' ']' | 
 point_assign : '(' INTEGERS ','  INTEGERS ',' STRING_TOKEN ')'
 angle_assign : '<' ID ID ID ',' BOOLEAN '>' | '<' ID ID ID '>' ;
 line_assign : ID LINE_OP line_assign | ID;
 arr_assign : '{' mult_integers '}'| '{''}';
 mult_integers : INTEGERS ',' mult_integers | INTEGERS ;
 construct :  CONSTRUCTOR '(' input_list ')';
 input_list:  STATEMENT ',' input_list | STATEMENT ;
 STATEMENT:  STATEMENT '+' STATEMENT | STATEMENT '*' STATEMENT | STATEMENT '/' STATEMENT| STATEMENT '%' STATEMENT | STATEMENT '^' STATEMENT | '(' STATEMENT ')' |  Unary | Func_dec | ID | FLOATS | INTEGERS | STRING_TOKEN | BOOLEAN  ;
 Unary: UNARY ID | ID UNARY | NOT ID;
 Func_dec: ID '(' input_list ')';
%%
void yyerror(char * s)
/* yacc error handler */| ID | FLOATS | INTEGERS | STRING_TOKEN | BOOLEAN
{   
    printf ( "%d\n", yylval);
    fprintf (stderr, "%s\n", s);
}
  
int main(int argc, char*argv[])
{    extern FILE *yyin; 
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    fout_parse = fopen("parse.txt","w");
    yyin = fp;
    yyparse();
    return 0;
} 