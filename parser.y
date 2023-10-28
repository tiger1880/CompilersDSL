%{
#include <stdio.h>
extern FILE *yyin; // input file
FILE* fout_token;
void yyerror(char *s);
int yylex();
int yydebug = 1;
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
%token SCALE CENTER

// precedence

%right EQUAL ASSIGN_OP
%left PERPENDICULAR
%left PARALLEL 
%left OR 
%left AND
%left EQ_CMP_OP
%left CMP_OP '<' '>'
%left '+' '-' LINE_OP
%left '*' '/' '%'
%left '^'
%nonassoc UNARY
%right NOT

%%

 program: program func | program fig | program stmt | ; 
 
 /*Function Defination */
 func: FUNC DATATYPE ID '(' arg_list ')' '{' func_body '}' 
    |  FUNC VOID ID '(' arg_list ')' '{' func_body '}' 
    ;
 arg_list : list1 | ;
 list1: list1 ',' argument  | argument ; // arglist with atleast 1 argument
 argument : DATATYPE ID ;
 func_body : func_body stmt | ;
 
 /* Figure Defination */
 fig: FIG ID '(' params ')' '{' fig_body '}' ;
 params : decl_token ',' decl_token 
        | SCALE EQUAL decl_token ',' CENTER EQUAL decl_token ;
 fig_body : fig_body stmt | ;

 /* Statements */
 stmt : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | ENDLINE;
 stmt_loop : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | break_stmt | ENDLINE;
 break_stmt : BREAK ENDLINE | CONTINUE ENDLINE ;

 assign_stmt : expression ENDLINE ;
 
 return_stmt : RETURN ret_var ENDLINE;
 ret_var : decl_token | ; 
 
 decl_stmt : DATATYPE ID_LIST ENDLINE;
 ID_LIST : ID check_arr decl_assign ',' ID_LIST  | ID check_arr decl_assign;
 decl_assign : EQUAL decl_token | ;
 decl_token :  assignment | expression;
 assignment :  arr_assign | construct ;
 
 dim : '[' INTEGERS  ']' | '[' ']' ;
 check_arr:  check_arr dim | ;
  
 point : '(' expression ','  expression ',' STRING_TOKEN ')' 
              |  '(' expression ','  expression  ')'
              ; 

 vertex: ID | point ;

 angle : '<' vertex vertex vertex ',' BOOLEAN '>' 
              | '<' vertex vertex vertex '>' 
              ;

 arr_assign : '{' arr_assign '}' | '{' mult_elements '}' | '{''}';      

 mult_elements : expression ',' mult_elements | expression ; 
                
 construct :  CONSTRUCTOR '(' param_list ')'; 

 param_list:  decl_token ',' param_list | decl_token ;
 
// need to take care of arrays
// test: norms, member access
 expression:  expression '+' expression 
            | expression '-' expression 
            | expression '*' expression 
            | expression '/' expression
            | expression '%' expression 
            | expression '^' expression 
            | expression LINE_OP expression
            | expression PARALLEL expression
            | expression PERPENDICULAR expression
            | PARALLEL expression PARALLEL
            | '-' expression //check precedence => create test case 
            | UNARY expression 
            | expression UNARY 
            | NOT expression 
            | expression AND expression
            | expression OR expression
            | id_list EQUAL expression
            | id_list ASSIGN_OP expression
            | expression CMP_OP expression
            | expression '<' expression
            | expression '>' expression
            | expression EQ_CMP_OP expression
            | id_list
            | FLOATS 
            | INTEGERS 
            | STRING_TOKEN 
            | BOOLEAN 
            | func_call 
            | point
            | angle
            | '(' expression ')'
            ; 

 id_list: id_list '.' ID  // will ensure left to right associativity
        | ID
        | ID arr_access
        ;  
 arr_access: arr_access '[' expression ']' | '[' expression ']' ;

 func_call: id_list '(' param_list ')' | id_list '(' ')' ;

/* Conditional */
cond_stmt : IF '(' expression ')' '{' stmt '}' 
            | IF '(' expression ')' '{' stmt '}' ELSE '{' stmt '}' 
            | IF '(' expression ')' '{' stmt '}' elif_stmt ELSE '{' stmt '}';

elif_stmt : ELIF '(' expression ')' '{' stmt '}' | elif_stmt ELIF '(' expression ')' '{' stmt '}' ;

/* Loops */
loop : for_loop | while_loop ;

for_loop_decl : DATATYPE ID EQUAL decl_token ;
for_loop : FOR '(' for_loop_decl '|' expression '|' expression ')' '{' stmt_loop '}' ;

while_loop : WHILE '(' expression ')' '{' stmt_loop '}' ;

%%

/* yacc error handler */
void yyerror(char * s)
{   
    printf ( "%d\n", yylval);
    fprintf (stderr, "%s\n", s);
}
  
int main(int argc, char*argv[])
{    
    FILE *fp;
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    yyin = fp;
    int x = yyparse();

    if (x != 0){
        fprintf(stderr, "Error in parsing\n");
        return 1;
    }

    return 0;
} 
