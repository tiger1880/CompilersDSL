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
%token SINGLE_COMMENT
%token MULTI_COMMENT
%token IF
%token ELIF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token VOID
%token INTERSECTION
%token MIDPOINT
%token SHORTEST_DISTANCE
%token ANGLE_BISECTOR
%token LINE_AT_ANGLE
%token TANGENT
%token COMMON_TANGENT
%token EXCENTRE
%token INCENTRE
%token CENTROID
%token CIRCUMCENTRE
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
%%

 S: Func S| Fig S|
 Func:
 Fig:
 decl : DATATYPE ID  check_arr decl_assign
 decl_assign : EQUAL decl_token | ;
 decl_token : ID | FLOATS | INTEGERS | STRING_TOKEN | BOOLEAN | point_assign | angle_assign |construct | arr_assign | line_assign | construct; 
 check_arr: '[' INTEGERS  ']' | '[' ']'
 point_assign : '(' INTEGERS ','  INTEGERS ',' STRING_TOKEN ')'
 angle_assign : '<' ID ID ID display_angle'>' ;
 line_assign : ID LINE_OP line_assign | ID;
 display_angle : ',' BOOLEAN | ;
 arr_assign : '{' mult_integers '}'| '{''}'
 mult_integers : INTEGERS ',' mult_integers | INTEGERS 
 construct :  CONSTRUCTOR '(' input_list ')';
 input_list:  INTEGERS ',' input_list| ID ',' input_list | FLOATS ',' input_list |FLOATS | INTEGERS  | ID;
 
%%
void yyerror(char * s)
/* yacc error handler */
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