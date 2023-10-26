%{
#include <stdio.h>
FILE *yyin; // input file
extern FILE *fp,*fout_token,*fout_parse ;
void yyerror(char *s);
int yylex();
%}

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
%token LOGICAL_OP REL_OP// remove
%token PARALLEL
%token PERPENDICULAR
%token BOOLEAN
%token FUNC
%token FIG
%token UNARY
%token DATATYPE
%token CMP_OP EQ_CMP_OP
%token ASSIGN_OP
%token EQUAL
%token STRING_TOKEN
%token ENDLINE
%token ID
%token FLOATS
%token CONSTRUCTOR
%token NOT AND OR 
%token OPERATORS

// precedence

%right EQUAL ASSIGN_OP
%left OR 
%left AND
%left EQ_CMP_OP
%left CMP_OP 
%left '+' '-'
%left '*' '/' '%'
%left '^'
%right NOT

%%

 program: func program | fig program | stmt program | ; // favour left recursion since it leads to smaller stack
 // empty program ??
 
 /*Function Defination */
 func: FUNC DATATYPE ID '(' arg_list ')' '{' func_body '}' ;
 arg_list : list1 | ;
 list1: list1 ',' argument  | argument ; // arglist with atleast 1 argument
 argument : DATATYPE ID ;
 func_body : func_body stmt | ;
 
 /* Figure Defination */
 fig: FIG ID '(' params ')' '{' fig_body '}' ;
 params : decl_token ',' decl_token ;
        /*| 'scale' EQUAL decl_token ',' 'center' EQUAL decl_token ; */
 fig_body : fig_body stmt | ;

 /* Statements */
 stmt : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt ;
 stmt2 : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | break_stmt ;
 break_stmt : BREAK ENDLINE | CONTINUE ENDLINE ;

 assign_stmt : assign_stmt_defn ENDLINE;
 assign_stmt_defn : ID EQUAL decl_token | ID ASSIGN_OP decl_token | UNARY expression | expression UNARY | func_call ;

 return_stmt : RETURN ret_var ;
 ret_var : decl_token | VOID ; 
 
 decl_stmt : DATATYPE ID_LIST ENDLINE;
 ID_LIST : ID check_arr decl_assign ',' ID_LIST  | ID check_arr decl_assign;
 decl_assign : EQUAL decl_token | ;
 decl_token :  assignment | predicate;
 assignment :  point_assign | line_assign | arr_assign | angle_assign | construct ;
 
 check_arr: '[' INTEGERS  ']' | '[' ']' | ;

 point_assign : '(' INTEGERS ','  INTEGERS ',' STRING_TOKEN ')' |  
                '(' FLOATS ','  INTEGERS ',' STRING_TOKEN ')'|
                '(' INTEGERS ','  FLOATS ',' STRING_TOKEN ')'|
                '(' FLOATS ','  FLOATS ',' STRING_TOKEN ')';

 angle_assign : '<' ID ID ID ',' BOOLEAN '>' | '<' ID ID ID '>' ;

 line_assign : ID LINE_OP line_assign | ID;

 arr_assign : '{' mult_elements '}' | '{''}';      

 mult_elements : DATATYPE ',' mult_elements | DATATYPE ; 
                
 construct :  CONSTRUCTOR '(' param_list ')'; 

 param_list:  decl_token ',' param_list | decl_token ;
 
 /*
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
    */
 expression:  factor '+' factor 
            | factor '*' factor 
            | factor '/' factor
            | factor '%' factor 
            | factor '^' factor 
            /* | UNARY factor */
            /* | factor UNARY */
            | NOT factor 
            | factor AND factor
            | factor OR factor 
            | factor EQUAL factor 
            | factor ASSIGN_OP factor
            | factor CMP_OP factor
            | factor EQ_CMP_OP factor
            | factor
            ;
 factor: ID
       | FLOATS 
       | INTEGERS  
       | STRING_TOKEN 
       | BOOLEAN 
       /* | func_call */
       | '(' expression ')'
       ;  

 func_call: ID '(' param_list ')' ;

/* Conditional */
cond_stmt : IF '(' predicate ')' '{' stmt '}' 
            | IF '(' predicate ')' '{' stmt '}' ELSE '{' stmt '}' 
            | IF '(' predicate ')' '{' stmt '}' elif_stmt ELSE '{' stmt '}';

elif_stmt : ELIF '(' predicate ')' '{' stmt '}' | elif_stmt ELIF '(' predicate ')' '{' stmt '}' ;

/* Loops */
loop : for_loop | while_loop ;

for_loop_decl : DATATYPE ID EQUAL decl_token ;
for_loop : FOR '(' for_loop_decl '|' predicate '|' assign_stmt ')' '{' stmt2 '}' ;

while_loop : WHILE '(' predicate ')' '{' stmt2 '}' ;

/* Predicate */
predicate : predicate LOGICAL_OP predicate 
            | predicate OPERATORS predicate 
            | predicate REL_OP predicate
            | predicate PARALLEL predicate 
            | predicate PERPENDICULAR predicate 
            | '(' predicate ')' 
            | NOT predicate
            | expression ;

%%

/* yacc error handler */
void yyerror(char * s)
{   
    printf ( "%d\n", yylval);
    fprintf (stderr, "%s\n", s);
}
  
int main(int argc, char*argv[])
{    
    extern FILE *yyin; 
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    fout_parse = fopen("parse.txt","w");
    yyin = fp;
    int x = yyparse();

    if (x != 0){
        fprintf(stderr, "Error in parsing\n");
    }

    return 0;
} 
