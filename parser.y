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
%token BREAK
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

 S: func S| fig S|;
 
 /*Function Defination */
 func: FUNC DATATYPE ID '(' arg_list ')' '{' func_body '}' ;
 arg_list : argument list1 ;
 argument : DATATYPE ID ;
 list1 : arg_list | ',' arg_list | ;
 func_body : func_stmt func_body | ;
 func_stmt : stmt | return_stmt ;
 
 /* Figure defination */
 fig: FIG ID '(' params ')' '{' fig_body '}' ;
 params : decl_token ',' decl_token ;
        /*| 'scale' EQUAL decl_token ',' 'center' EQUAL decl_token ; */
 fig_body : stmt fig_body | ;

 stmt : cond_stmt | loop | decl_stmt | assign_stmt ;

 assign_stmt : assign_stmt_defn ENDLINE;
 assign_stmt_defn : ID EQUAL decl_token | ID ASSIGN_OP decl_token | UNARY expression | expression UNARY | func_call ;

 return_stmt : RETURN ret_var ;
 ret_var : decl_token | VOID ; 
 
 decl_stmt : DATATYPE ID_LIST ENDLINE;
 ID_LIST : ID check_arr decl_assign ',' ID_LIST  | ID check_arr decl_assign;
 decl_assign : EQUAL decl_token | ;
 decl_token :  expression | assignment;
 assignment :  point_assign | line_assign | arr_assign | angle_assign | construct ;
 
 check_arr: '[' INTEGERS  ']' | '[' ']' | ;

 point_assign : '(' INTEGERS ','  INTEGERS ',' STRING_TOKEN ')' |  
                '(' FLOATS ','  INTEGERS ',' STRING_TOKEN ')'|
                '(' INTEGERS ','  FLOATS ',' STRING_TOKEN ')'|
                '(' FLOATS ','  FLOATS ',' STRING_TOKEN ')';  /* can have floats */

 angle_assign : '<' ID ID ID ',' BOOLEAN '>' | '<' ID ID ID '>' ;

 line_assign : ID LINE_OP line_assign | ID;

 arr_assign : '{' mult_integers '}'| '{''}';       /* can have floats,strings,other datatypes */

 mult_integers : INTEGERS ',' mult_integers 
                | FLOATS ',' mult_integers
                | STRING_TOKEN ',' mult_integers
                | INTEGERS | FLOATS | STRING_TOKEN ;
 
 construct :  CONSTRUCTOR '(' param_list ')'; 
     
 param_list:  decl_token ',' param_list | decl_token ;
 
 expression:  expression '+' expression 
            | expression '*' expression 
            | expression '/' expression
            | expression '%' expression 
            | expression '^' expression 
            | '(' expression ')' 
            | UNARY expression
            | expression UNARY
            | NOT expression 
            | func_call 
            | ID 
            | FLOATS | INTEGERS | STRING_TOKEN | BOOLEAN  ;
 
 func_call: ID '(' param_list ')' ;

/* Conditional */
cond_stmt : ;

/* Loops */
loop : for_loop | while_loop ;

break_stmt : stmt | BREAK ENDLINE | CONTINUE ENDLINE ;

for_loop_decl : DATATYPE ID EQUAL decl_token ;
for_loop : FOR '(' for_loop_decl '|' predicate '|' assign_stmt ')' '{' break_stmt '}' ;

while_loop : WHILE '(' predicate ')' '{' break_stmt '}' ;


/* Predicate */
predicate : ;



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