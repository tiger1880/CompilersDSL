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
bool arithCompatible(int e);
void semanticError(const char* s);
void typeUpdate(vector<char*>* v, enum eletype t);
void insert(char* name, vector<int>* dim, enum eletype t);
bool coercible(int t1, int t2);

int ret_flag = 0;
int ret_fig_flag = 0;

enum eletype ret_type = UNDEF;

%}



%union {
    char* name; 
    enum eletype eletype;  
    vector<char*>* nameList;
    vector<int>* dimList;
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
%token SUM_ASSIGN_OP
%token SUB_ASSIGN_OP
%token EQUAL
%token <eletype> STRING_TOKEN
%token ENDLINE
%token <name> ID
%token <eletype> FLOATS
%token <eletype> TRICONSTRUCT
%token <eletype> CIRCLECONSTRUCT
%token <eletype> PARACONSTRUCT
%token <eletype> REGPOLYCONSTRUCT
%token NOT AND OR 
%token SCALE CENTER


// non-terminals
%type <nameList> ID_LIST
%type <eletype> expression decl_token decl_assign assign
%type <eletype> point angle id_list
%type <eletype> cond_stmt ret_var 
%type <eletype> optional_arg assign_stmt construct constructor
%type <dimList> check_arr dim
// precedence

%right EQUAL  SUM_ASSIGN_OP SUB_ASSIGN_OP ASSIGN_OP
%left PERPENDICULAR
%left PARALLEL 
%left OR 
%left AND
%left EQ_CMP_OP
%left CMP_OP '<' '>'
%left '+' '-' LINE_OP // change the precedence of unary NEG 
%left '*' '/' '%'
%precedence NEG
%right '^'
%nonassoc UNARY
%right NOT

/* %type<Eletype> DATATYPE   // Used in non-terminals mostly hence went back to token .
%type<name> ID */


%%

//Also make sure you handle 8++
program: program func | program fig | program stmt | {if(ret_flag) {
       cerr<<"Error: Return statement not allowed outside function"<<endl;
}}; 
 
 /* Function Defination */
func:  FUNC DATATYPE  ID  '(' arg_list ')' empty_space '{' func_body '}' {
              insertType($3, Func, $2);  
              printSymbolTable();
              if(ret_flag==0) {
                     cerr<<"Error: Semantic error no return statement"<<endl;
              }
              else if($2!=ret_type) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0;
       }
       |  FUNC VOID ID '(' arg_list ')' empty_space '{' func_body '}' {
              insertType($3, Func, $2);  
              printSymbolTable();
              if(ret_type!=UNDEF && ret_type!=Void) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0; 
       }   //Need to do testing
       ;

arg_list : list1 | ;

list1: list1 ',' argument  | argument ; 

argument : DATATYPE ID check_arr;

func_body : func_body stmt  | ;
 
/* Figure Defination */
fig: FIG ID '(' params ')' empty_space '{' fig_body '}'{ if (ret_fig_flag == 1)  semanticError("Error: Return statement is not allowed in figures."); ret_fig_flag =0; } 
params : expression ',' expression { if(!(arithCompatible($1) && $3 == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
       | SCALE EQUAL expression ',' CENTER EQUAL expression { if(!($3 == REAL && $7 == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
fig_body : fig_body stmt | ;

 /* Statements */
stmt : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | ENDLINE;
stmt_loop : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | break_stmt | ENDLINE;  //Add return type here

break_stmt : BREAK ENDLINE | CONTINUE ENDLINE ;

assign_stmt : expression ENDLINE | construct ENDLINE {$$ = $1;};
 
return_stmt : RETURN ret_var ENDLINE {ret_type = $2; ret_flag = 1; ret_fig_flag = 1;};

ret_var : construct {$$ = $1;} | expression {$$ = $1;} | {$$ = Void;}; 
 
decl_stmt : DATATYPE ID_LIST ENDLINE {typeUpdate($2, $1);};

ID_LIST: ID_LIST ',' ID check_arr decl_assign {$$ = $1;$$->push_back($3);insert($3, $4, $5);}
       | ID check_arr decl_assign {$$ = new vector<char*>;$$->push_back($1);insert($1, $2, $3);}
       ;

decl_assign : EQUAL decl_token {$$ = $2;}
       | /* empty */  {$$ = UNDEF;}
       ; 

decl_token :  
         arr_assign {$$ = UNDEF;}
       | construct  {$$ = UNDEF;}
       | expression {$$ = $1;}
       ;

 // change after adding expression values
dim : dim '[' expression ']' {$$ = $1;}
    | '[' expression ']' {$$ = new vector<int>; $$->push_back(1);}
    ;

check_arr: dim {$$ = $1;}
         | '['']' 
         | '['']' dim 
         | /* empty */ {$$ = new vector<int>;}
         ;
  
arr_assign : '{' arr1d_in_list '}' | '{' comma_arr_assign '}'; // { {1,, 2}, {2, 3}}
comma_arr_assign: comma_arr_assign ',' arr_assign  | arr_assign ;       
arr1d_in_list: mult_elements | ;
mult_elements : mult_elements ',' expression  | expression ; 
                
construct :  constructor '(' param_list ')' { $$ = $1;} | constructor '(' ')' { $$ = $1;} ; 
constructor : TRICONSTRUCT { $$ = $1;} | CIRCLECONSTRUCT { $$ = $1;} | PARACONSTRUCT { $$ = $1;} | REGPOLYCONSTRUCT { $$ = $1;};

valid_arg: construct | expression ;

param_list: param_list ',' valid_arg | valid_arg ;
 
point : '(' expression ','  expression ',' STRING_TOKEN ')' {  $$ = pointCheck($2, $4); }
       |  '(' expression ','  expression  ')'  {  $$ = pointCheck($2, $4); }
       ; 

vertex: ID | point ;

angle : '<' vertex vertex vertex ',' BOOLEAN '>'  {$$ = REAL;}
       | '<' vertex vertex vertex '>' {$$ = REAL;}
       ;

expression:   expression '+' expression {$$ = sumTypeCheck($1, $3); }
            | expression '-' expression {if($1 == LABEL ||$3 == LABEL) semanticError("Error: Semantic error incompatible datatype") ;  $$ = sumTypeCheck($1, $3) ;}
            | expression '*' expression {if($1 == LABEL ||$3 == LABEL||$1 == POINT || $3 == POINT) semanticError("Error: Semantic error incompatible datatype") ;  $$ = sumTypeCheck($1, $3) ;}
            | expression '/' expression {if($1 == LABEL ||$3 == LABEL||$1 == POINT || $3 == POINT) semanticError("Error: Semantic error incompatible datatype") ;  $$ = sumTypeCheck($1, $3) ;}
            | expression '%' expression {if($1 == LABEL ||$3 == LABEL||$1 == POINT || $3 == POINT) semanticError("Error: Semantic error incompatible datatype") ;  $$ = sumTypeCheck($1, $3) ;}
            | expression '^' expression {if($1 == LABEL ||$3 == LABEL||$1 == POINT || $3 == POINT) semanticError("Error: Semantic error incompatible datatype") ;  $$ = sumTypeCheck($1, $3) ;}
            | expression LINE_OP expression {if(($1 == POINT || $1 == LINE) && $3 == POINT) $$ = LINE ; else  semanticError("Error: Semantic error incompatible datatype") ;  }  // <-> ->
            | expression PARALLEL expression {if($1 == LINE && $3 == LINE) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
            | expression PERPENDICULAR expression  {if($1 == LINE && $3 == LINE) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
            | PARALLEL expression PARALLEL  {if ($2 != POINT) semanticError("Error: Semantic error incompatible datatype") ; $$ = REAL; }
            | '-' expression %prec NEG {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; } 
            | UNARY expression {if(!($2 == INT || $2 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;  }
            | expression UNARY {if(!($1 == INT || $1 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;  }
            | NOT expression {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;}
            | expression AND expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression OR expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | id_list assign  
            | expression CMP_OP expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  } 
            | expression '<' expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression '>' expression  {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression EQ_CMP_OP expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1 == $3)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | id_list {$$ = $1;}
            | FLOATS {$$ = $1;} 
            | INTEGERS {$$ = $1;}
            | STRING_TOKEN {$$ = $1;  cout<< $$;}
            | BOOLEAN {$$ = $1;}
            | func_call 
            | point {$$ = $1;}
            | angle {$$ = $1;}            
            | '(' expression ')' {$$ = $2;}
            ; 

assign:  EQUAL expression 
       | ASSIGN_OP  expression  {if(!(arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }  
       | SUM_ASSIGN_OP  expression  {if(!(arithCompatible($2) || $2 == LABEL || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }
       | SUB_ASSIGN_OP expression {if(!(arithCompatible($2) || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;}

id_list: id_list '.' ID  arr_access 
       | ID arr_access 
       ;  

arr_access: arr_access '[' expression ']' |  ;

func_call: id_list '(' param_list ')' | id_list '(' ')' ;


empty_space: empty_space ENDLINE | ;

/* Conditional */

stmt_list: stmt_list stmt | stmt ;  
stmt_block: empty_space '{' stmt_list '}' ENDLINE | empty_space '{' '}' ENDLINE;

cond_stmt : IF '(' expression ')' stmt_block {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block  ELSE stmt_block {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block elif_stmt ELSE stmt_block {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block elif_stmt {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        ;

elif_stmt : ELIF '(' expression ')' stmt_block  {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
          | elif_stmt ELIF '(' expression ')' stmt_block {if(!(arithCompatible($4))) semanticError("Error: Semantic error incompatible datatype");}
          ;

/* Loops */

stmt_loop_list: stmt_loop_list stmt_loop | stmt_loop ;   
stmt_loop_block: empty_space '{' stmt_loop_list '}' | empty_space '{' '}';

loop : for_loop | while_loop ;

for_loop_decl : DATATYPE ID EQUAL expression | ID EQUAL expression | ;
optional_arg: expression {$$ = $1;} | {$$ = BOOL;} ;
for_loop : FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' stmt_loop_block {if(!(arithCompatible($5))) semanticError("Error: Semantic error incompatible datatype11"); cout<<"k";}

while_loop : WHILE '(' expression ')' stmt_loop_block 


%%

/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

void semanticError(const char* s){
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
              cerr << "Error: Semantic error incompatible datatypes+\n";
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

// check int change 
bool arithCompatible(int e){

       if (e == REAL || e == BOOL || e == INT || e == ANGLE) 
              return true;
       return false;
}

enum eletype pointCheck (enum eletype x, enum eletype y){
       if ((x == INT || x == REAL) && (y == INT || y == REAL ))
              return POINT;
       else {
              cerr << "Error: Semantic error invalid point \n";
              exit(1);
       }
}

bool coercible(int t1, int t2){
       
       if (arithCompatible(t1) && arithCompatible(t2))
              return true;

       if (t1 == t2)
              return true;

       /* 
              POINT
              LABEL
              LINE
              CIRCLE
              TRI
              PARA
              REGPOLY 
       */

       return false;      

}

void typeUpdate(vector<char*>* v, enum eletype t){

       for (int i = 0;i < v->size();i++){

              int prevType = checkEletype(v->at(i));
              
              if (prevType == UNDEF)
              {
                     updateType(v->at(i), t);
              }
              else if (!coercible(prevType, t))
              {
                     cerr << "Error: " << "types don't match in declaration and initialisation\n";
                     exit(1);
                     // error recovery
              }
              
              free(v->at(i));
       }

       delete v;

       printSymbolTable();

       return;
}

void insert(char* name, vector<int>* dim, enum eletype t){

       if (dim->size() == 0)
              insertType(name, Var, t);
       else {
              insertType(name, Array, t);
              addDimList(name, *dim); 
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
