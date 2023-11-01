%{
#include <stdio.h>
extern FILE *yyin; 
FILE* fout_token;
void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char* yytext;
int yydebug = 1;
%}


//parameter of function
typedef struct ParamFunc{
    char name[64];
    char type[64];
} ParamFunc;


//varList of function
typedef struct VarFunc{
    char name[64];
    char type[64];
    int levelFunc;
} VarFunc;


//function symbol table 
typedef struct FuncSym {
    char name[64];
    char type[64];
    ParamFunc paramList[64];
    VarFunc varList[64];
    int numParams;
} FuncSym;

FuncSym symbolTable[100];
int symTabSize = 0;



void addFuncToSymTab(const char* name, const char* type, ParamFunc* paramList, VarFunc* varList,int numParams, int) {
    
}

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
 
 /* Function Defination */
func: FUNC DATATYPE ID '(' arg_list ')' empty_space '{' func_body '}' 
    |  FUNC VOID ID '(' arg_list ')' empty_space '{' func_body '}' 
    ;

arg_list : list1 | ;

list1: list1 ',' argument  | argument ; 

argument : DATATYPE ID ;

func_body : func_body stmt | ;
 
/* Figure Defination */
fig: FIG ID '(' params ')' empty_space '{' fig_body '}' ;
params : expression ',' expression 
       | SCALE EQUAL expression ',' CENTER EQUAL expression ;
fig_body : fig_body stmt | ;

 /* Statements */
stmt : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | ENDLINE;
stmt_loop : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | break_stmt | ENDLINE;
break_stmt : BREAK ENDLINE | CONTINUE ENDLINE ;

assign_stmt : expression ENDLINE | construct ENDLINE;
 
return_stmt : RETURN ret_var ENDLINE;

ret_var : construct | expression | ; 
 
decl_stmt : DATATYPE ID_LIST ENDLINE;

ID_LIST: ID_LIST  ',' ID check_arr decl_assign   
       | ID check_arr decl_assign
       ;

decl_assign : EQUAL decl_token | ;
decl_token :  arr_assign | construct | expression ;
 
dim : '[' expression  ']' | '[' ']' ;
check_arr:  check_arr dim | ;
  
arr_assign : '{' arr1d_in_list '}' | '{' comma_arr_assign '}'; // { {1,, 2}, {2, 3}}
comma_arr_assign: comma_arr_assign ',' arr_assign  | arr_assign ;       
arr1d_in_list: mult_elements | ;
mult_elements : mult_elements ',' expression  | expression ; 
                
construct :  CONSTRUCTOR '(' param_list ')' | CONSTRUCTOR '(' ')' ; 

valid_arg: construct | expression ;

param_list: param_list ',' valid_arg | valid_arg ;
 
point : '(' expression ','  expression ',' STRING_TOKEN ')' 
       |  '(' expression ','  expression  ')'
       ; 

vertex: ID | point ;

angle : '<' vertex vertex vertex ',' BOOLEAN '>' 
       | '<' vertex vertex vertex '>' 
       ;

expression:  expression '+' expression 
            | expression '-' expression 
            | expression '*' expression 
            | expression '/' expression
            | expression '%' expression 
            | expression '^' expression 
            | expression LINE_OP expression // <-> ->
            | expression PARALLEL expression
            | expression PERPENDICULAR expression
            | PARALLEL expression PARALLEL
            | '-' expression 
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

id_list: id_list '.' ID  arr_access 
       | ID arr_access
       ;  

arr_access: arr_access '[' expression ']' |  ;

func_call: id_list '(' param_list ')' | id_list '(' ')' ;


empty_space: empty_space ENDLINE | ;

/* Conditional */

stmt_list: stmt_list stmt | stmt ;  
stmt_block: empty_space '{' stmt_list '}' ENDLINE | empty_space '{' '}' ENDLINE;

cond_stmt : IF '(' expression ')' stmt_block 
        |   IF '(' expression ')' stmt_block  ELSE stmt_block 
        |   IF '(' expression ')' stmt_block elif_stmt ELSE stmt_block
        |   IF '(' expression ')' stmt_block elif_stmt 
        ;

elif_stmt : ELIF '(' expression ')' stmt_block 
          | elif_stmt ELIF '(' expression ')' stmt_block
          ;

/* Loops */

stmt_loop_list: stmt_loop_list stmt_loop | stmt_loop ;   
stmt_loop_block: empty_space '{' stmt_loop_list '}' | empty_space '{' '}';

loop : for_loop | while_loop ;

for_loop_decl : DATATYPE ID EQUAL expression | ID EQUAL expression | ;
optional_arg: expression | ;
for_loop : FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' stmt_loop_block ;

while_loop : WHILE '(' expression ')' stmt_loop_block ;

%%

/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}
  
int main(int argc, char*argv[])
{    
    FILE *fp;
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    yyin = fp;

    return yyparse();
} 
