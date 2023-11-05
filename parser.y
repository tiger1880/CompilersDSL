%{
#include "symbol_table.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>

extern FILE *yyin; 
FILE* fout_token;
void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char* yytext;

using namespace std;

enum eletype sumTypeCheck(enum eletype E1, enum eletype E2);
enum eletype arithTypeCheck(enum eletype E1, enum eletype E2);
enum eletype pointCheck (enum eletype x, enum eletype y);
bool arithCompatible(enum eletype e);
void semanticError(const char* s);

%}



%union {
    char* name; 
    enum eletype eletype;  
}



%token <eletype> INTEGERS
%token LINE_OP  
%token IF
%token ELIF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token <eletype> VOID
%token CONTINUE
%token BREAK
%token PARALLEL
%token PERPENDICULAR
%token <eletype> BOOLEAN
%token FUNC
%token FIG
%token UNARY
%token <eletype> DATATYPE
%token CMP_OP EQ_CMP_OP
%token ASSIGN_OP
%token EQUAL
%token <eletype> STRING_TOKEN
%token ENDLINE
%token <name> ID
%token <eletype> FLOATS
%token CONSTRUCTOR
%token NOT AND OR 
%token SCALE CENTER


// non-terminals
%type <eletype> expression
%type <eletype> point angle

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

/* %type<Eletype> DATATYPE   // Used in non-terminals mostly hence went back to token .
%type<name> ID */


%%

program: program func | program fig | program stmt | ; 
 
 /* Function Defination */
func: FUNC DATATYPE  ID   { insertType($3, Func, $2);  printSymbolTable();} '(' arg_list ')' empty_space '{' func_body '}'
    |  FUNC VOID ID '(' arg_list ')' empty_space '{' func_body '}' 
    ;

arg_list : list1 | ;

list1: list1 ',' argument  | argument ; 

argument : DATATYPE ID check_arr;

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
 
point : '(' expression ','  expression ',' STRING_TOKEN ')' {  $$ = pointCheck($2, $4); }
       |  '(' expression ','  expression  ')'  {  $$ = pointCheck($2, $4); }
       ; 

vertex: ID | point ;

angle : '<' vertex vertex vertex ',' BOOLEAN '>'  {$$ = REAL;}
       | '<' vertex vertex vertex '>' {$$ = REAL;}
       ;

expression:  expression '+' expression {$$ = sumTypeCheck($1, $3); cout << $$ << "\n";}
            | expression '-' expression  {if($1 == LABEL ||$3 == LABEL) semanticError("Error: Semantic error incompatible datatype") ;  $$ = sumTypeCheck($1, $3) ;}
            | expression '*' expression {$$ = arithTypeCheck($1, $3) ;}
            | expression '/' expression {$$ = arithTypeCheck($1, $3) ;}
            | expression '%' expression {$$ = arithTypeCheck($1, $3) ;}
            | expression '^' expression {$$ = arithTypeCheck($1, $3) ;}
            | expression LINE_OP expression {if($1 == POINT && $3 == POINT) $$ = LINE ; else  semanticError("Error: Semantic error incompatible datatype") ;  }  // <-> ->
            | expression PARALLEL expression {if($1 == LINE && $3 == LINE) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
            | expression PERPENDICULAR expression  {if($1 == LINE && $3 == LINE) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
            | PARALLEL expression PARALLEL  {if ($2 != POINT) semanticError("Error: Semantic error incompatible datatype") ; $$ = REAL; }
            | '-' expression {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; } 
            | UNARY expression {if(!($2 == INT && $2 == BOOL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;  }
            | expression UNARY {if(!($1 == INT && $1 == BOOL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;  }
            | NOT expression {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;}
            | expression AND expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression OR expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | id_list EQUAL expression 
            | id_list ASSIGN_OP expression
            | expression CMP_OP expression 
            | expression '<' expression
            | expression '>' expression  
            | expression EQ_CMP_OP expression 
            | id_list
            | FLOATS {$$ = $1;}
            | INTEGERS {$$ = $1;}
            | STRING_TOKEN {$$ = $1;}
            | BOOLEAN {$$ = $1;}
            | func_call 
            | point {$$ = $1;}
            | angle {$$ = $1;}
            | '(' expression ')' {$$ = $2;}
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

void semanticError(const char* s)
{
       cerr << s << "\n";
       exit(1);
}
  
enum eletype sumTypeCheck(enum eletype E1, enum eletype E2  ){
       if(E1 == LABEL && E2 == LABEL)
              return LABEL;
       else if(E1 == POINT && E2 == POINT)
              return POINT;
       else if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1);
       }
}

enum eletype arithTypeCheck(enum eletype E1, enum eletype E2  ){
       
       if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1);
       }
}

bool arithCompatible(enum eletype e){

       if (e == REAL || e == BOOL || e == INT)
              return true;
       return false;
}
enum eletype pointCheck (enum eletype x, enum eletype y){
       if (arithCompatible(x) && arithCompatible(y))
              return POINT;
       else {
              cerr << "Error: Semantic error invalid point \n";
              exit(1);
       }
}


int main(int argc, char*argv[])
{    

    FILE *fp;
    fp = fopen(argv[1], "r");
    fout_token = fopen("seq_token.txt","w");
    yyin = fp;


    return yyparse();
} 
