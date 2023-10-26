%{
#include <stdio.h>
extern FILE *yyin; // input file
FILE *fp,*fout_token,*fout_parse ;
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
%token LOGICAL_OP
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
%left PERPENDICULAR
%left PARALLEL
%right EQUAL ASSIGN_OP
%left OR 
%left AND
%left EQ_CMP_OP
%left CMP_OP 
%left '+' '-' LINE_OP
%left '*' '/' '%'
%left '^'
%right NOT

%% 
// need to take care of arrays, unary
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
            /* | UNARY id_list */
            /* | id_list UNARY */
            | NOT expression 
            | expression AND expression
            | expression OR expression
            | expression EQUAL expression
            | expression ASSIGN_OP expression
            | expression CMP_OP expression
            | expression EQ_CMP_OP expression
            | id_list
            /* | id_list '.' func_call */
            | FLOATS 
            | INTEGERS 
            | STRING_TOKEN 
            | BOOLEAN 
            /* | func_call */
            | point
            | angle
            | '(' expression ')'
            ; 
 id_list: id_list '.' ID  // will ensure left to right associativity
        | ID
        ;   
    
 num:  INTEGERS | FLOATS ; 

 point : '(' num ','  num ',' STRING_TOKEN ')' 
        |  '(' num ','  num  ')'
        ;

 angle : '<' ID ID ID ',' BOOLEAN '>' 
        | '<' ID ID ID '>' 
        ;


%%

/* yacc error handler */
void yyerror(char * s)
{   
    printf ( "%d\n", yylval);
    fprintf (stderr, "%s\n", s);
}
  
int main(int argc, char*argv[])
{    
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    fout_parse = fopen("parse.txt","w");
    yyin = fp;
    yyparse();
    return 0;
} 
