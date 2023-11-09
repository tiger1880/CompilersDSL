%{
#include "symbol_table.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void semanticError(const char* s);

enum eletype sumTypeCheck(enum eletype E1, enum eletype E2);
enum eletype diffTypeCheck(enum eletype E1, enum eletype E2);
enum eletype mulTypeCheck(enum eletype E1, enum eletype E2);
enum eletype arithTypeCheck(enum eletype E1, enum eletype E2);
enum eletype pointCheck (enum eletype x, enum eletype y);
bool arithCompatible(int e);

bool coercible(int t1, int t2);
void typeUpdate(vector<char*>* v, enum eletype t);
void insert(char* name, vector<int>* dim, enum eletype t);
void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x);
void updateMaxDim(vector<int>* comma, vector<int>* assign); // for now have to be equal
void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList);
void insertArray(char* name, vector <int>* dimList);


/*     ONLY FOR  DEBUGGING    */
template < typename T >
void print(vector<T>& v){

    for (int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    
    cout << "\n";
}

extern int yydebug;

#define YYDEBUG 1
/*     ONLY FOR  DEBUGGING    */


int ret_flag = 0;
int ret_fig_flag = 0;

enum eletype ret_type = UNDEF;

std::vector<ParamList> paramslist;

%}



%union {
    char* name; 
    enum eletype eletype;  
    vector<char*>* nameList;
    vector<int>* dimList;
    struct ConstExp {
       enum eletype eletype;  
       union {
              int i;
              double d;
       };
    } constExp;
    struct {
       int count;
       enum eletype eletype;  
    } countAndType;
    struct {
       vector<int>* dimList;
       enum eletype eletype;  
    } listAndType;
    
    
}


%token <constExp> INTEGERS BOOLEAN FLOATS
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
%token <eletype> TRICONSTRUCT CIRCLECONSTRUCT PARACONSTRUCT REGPOLYCONSTRUCT
%token NOT AND OR 
%token SCALE CENTER


// non-terminals
%nterm <eletype> construct assign_stmt constructor
%nterm <eletype> point angle expression member_access
%nterm <eletype> assign
%nterm <nameList> id_list
%nterm <countAndType> mult_elements arr1d_in_list
%nterm <constExp> const_expr 
%nterm <dimList> check_arr dim 
%nterm <listAndType> arr_assign comma_arr_assign
%nterm <eletype> decl_token decl_assign
%nterm <eletype> cond_stmt ret_var 
%nterm <eletype> optional_arg valid_arg


// precedence
%right EQUAL  SUM_ASSIGN_OP SUB_ASSIGN_OP ASSIGN_OP
%left PERPENDICULAR
%left PARALLEL 
%left OR 
%left AND
%left EQ_CMP_OP
%left CMP_OP '<' '>'
%left '+' '-' LINE_OP  
%left '*' '/' '%'
%precedence NEG
%right '^'
%nonassoc UNARY
%right NOT

%%

/* a program is a series of functions, figures and statements */
program: program func 
       | program fig 
       | program stmt 
       | /* empty */ {
              if(ret_flag) {
                     cerr<<"Error: Return statement not allowed outside function"<<endl;
              }
         }      
       ; 
 
 /* Function Definition */
func:  FUNC DATATYPE  ID  '(' arg_list ')' empty_space '{' func_body '}' {
              insertType($3, Func, $2);  
              if(paramslist.size()>0) {
                     addParamList($3,paramslist);
                     paramslist.clear();
              }
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
              if(paramslist.size()>0) {
                     addParamList($3,paramslist);
                     paramslist.clear();
              }
              paramslist.clear();
              printSymbolTable();
              
              if(ret_type!=UNDEF && ret_type!=Void) {
                    cerr<<"Error: Semantic error return type not matching"<<endl; 
              }
              ret_flag = 0; 
       }   //Need to do testing
       ;

arg_list : list1 
         | 
         ;

list1: list1 ',' argument  
     | argument  

argument : DATATYPE ID check_arr {
       ParamList param;
       param.Eletype = $1;
       param.name = $2;
       param.dim = *$3;
       paramslist.push_back(param);
       
};

func_body : func_body stmt  | ;
 
/* Figure Definition */
fig: FIG ID '(' params ')' empty_space '{' fig_body '}'{ if (ret_fig_flag == 1)  semanticError("Error: Return statement is not allowed in figures."); ret_fig_flag =0; } 
params : expression ',' expression { if(!(arithCompatible($1) && $3 == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
       | SCALE EQUAL expression ',' CENTER EQUAL expression { if(!($3 == REAL && $7 == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
fig_body : fig_body stmt | ;

 /* Statements */
stmt : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | ENDLINE | stmt_block;

stmt_list: stmt_list stmt
         |  /* empty */
         ;

stmt_block: '{'  stmt_list '}' 
          ;

stmt_loop : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | break_stmt | ENDLINE;  //Add return type here

break_stmt : BREAK ENDLINE | CONTINUE ENDLINE ;

       /* Return Statement */
return_stmt : RETURN ret_var ENDLINE {ret_type = $2; ret_flag = 1; ret_fig_flag = 1;};

ret_var : construct {$$ = $1;} | expression {$$ = $1;} | {$$ = Void;}; 

       /* Assignment Statement */
assign_stmt : expression ENDLINE {$$ = $1;}
            | construct ENDLINE  {$$ = $1;}
            ;

construct :  constructor '(' param_list ')' {$$ = $1;} 
          | constructor '(' ')' {$$ = $1;} 
          ; 

constructor : TRICONSTRUCT { $$ = $1;} 
            | CIRCLECONSTRUCT { $$ = $1;} 
            | PARACONSTRUCT { $$ = $1;} 
            | REGPOLYCONSTRUCT { $$ = $1;}
            ;

valid_arg: construct {$$ = $1;}
         | expression {$$ = $1;}
         ;

param_list: param_list ',' valid_arg 
          | valid_arg 
          ;

point : '(' expression ','  expression ',' STRING_TOKEN ')' {  $$ = pointCheck($2, $4); }
       |  '(' expression ','  expression  ')'  {  $$ = pointCheck($2, $4); }
       ; 

// NOT TESTED
vertex: ID { if (checkEletype($1) != POINT) semanticError("Error: vertex has to be a point");}
      | point 
      ;

/* Should I change to ANGLE ? */
angle : '<' vertex vertex vertex ',' BOOLEAN '>'  {$$ = REAL;}
       | '<' vertex vertex vertex '>' {$$ = REAL;}
       ;

expression:   expression '+' expression {$$ = sumTypeCheck($1, $3); }
            | expression '-' expression {$$ = diffTypeCheck($1, $3);}
            | expression '*' expression {$$ = mulTypeCheck($1, $3);}
            | expression '/' expression {$$ = mulTypeCheck($1, $3);}
            | expression '%' expression {if ($1 != INT || $3 != INT) semanticError("Error: Semantic error incompatible datatype"); $$ = INT;}
            | expression '^' expression {$$ = mulTypeCheck($1, $3);}
            | expression LINE_OP expression {if(($1 == POINT || $1 == LINEARR) && $3 == POINT) $$ = LINEARR ; else  semanticError("Error: Semantic error incompatible datatype") ;  }  // <-> ->
            | expression PARALLEL expression {if(($1 == LINE||$1 == LINEARR) && ($3 == LINE||$1 == LINEARR)) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  }
            | expression PERPENDICULAR expression  {if(($1 == LINE||$1 == LINEARR) && ($3 == LINE||$1 == LINEARR)) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; }
            | PARALLEL expression PARALLEL  {if ($2 != POINT) semanticError("Error: Semantic error incompatible datatype") ; $$ = REAL; }
            | '-' expression %prec NEG {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; } 
            | UNARY member_access {if(!($2 == INT || $2 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;  }
            | member_access UNARY {if(!($1 == INT || $1 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;  }
            | NOT expression {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression AND expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression OR expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | member_access assign  {if(!($2 == POINT && $1 == POINT)||($2 == LABEL && $1 == LABEL || arithCompatible($1) && arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;}
            | expression CMP_OP expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;} 
            | expression '<' expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression '>' expression  {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression EQ_CMP_OP expression {if(!((arithCompatible($1) && arithCompatible($3)) || ($1 == $3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | member_access {$$ = $1;}
            | '(' expression ')' {$$ = $2;}
            | FLOATS {$$ = $1.eletype;} 
            | INTEGERS {$$ = $1.eletype;}
            | BOOLEAN {$$ = $1.eletype;}
            | STRING_TOKEN {$$ = $1;}
            | func_call 
            | point {$$ = $1;}
            | angle {$$ = $1;}            
            ; 

assign:  EQUAL expression 
       | ASSIGN_OP  expression  {if(!(arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }  
       | SUM_ASSIGN_OP  expression  {if(!(arithCompatible($2) || $2 == LABEL || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }
       | SUB_ASSIGN_OP expression {if(!(arithCompatible($2) || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;}
       ;
       


       /* Declaration Statement */
decl_stmt : DATATYPE id_list ENDLINE {typeUpdate($2, $1);}
          ;

id_list: id_list ',' ID check_arr EQUAL arr_assign {$$ = $1;$$->push_back($3);compareAndInsertArray($3, $4, $6.eletype, $6.dimList);}
       | id_list ',' ID check_arr  {$$ = $1;$$->push_back($3);insertArray($3, $4);}       
       | id_list ',' ID decl_assign {$$ = $1;$$->push_back($3);insertType($3, Var, $4);}
       | ID check_arr  {$$ = new vector<char*>;$$->push_back($1);insertArray($1, $2);}
       | ID check_arr EQUAL arr_assign {$$ = new vector<char*>;$$->push_back($1);compareAndInsertArray($1, $2, $4.eletype, $4.dimList);}
       | ID decl_assign {$$ = new vector<char*>;$$->push_back($1);insertType($1, Var, $2);}
       ;

decl_assign: EQUAL decl_token {$$ = $2;}
       | /* empty */  {$$ = UNDEF;}
       ; 

decl_token: construct  {$$ = $1;}
       | expression {$$ = $1;}
       ;

/* Arrays */
check_arr: dim {$$ = $1;}
         | '['']' {$$ = new vector<int>;$$->push_back(-1);}
         | '['']' dim {$$ = new vector<int>;addFrontAndCopy($$, $3, -1);delete $3;}
         /* | empty {$$ = new vector<int>;} */
         ;
         
 // change after adding expression values
dim : dim '[' const_expr ']' {$$ = $1;
                              
                            if ($3.eletype == REAL)
                                   $$->push_back($3.d);
                            else              
                                   $$->push_back($3.i);
                            
                            }
    | '[' const_expr ']' {$$ = new vector<int>; 

                            if ($2.eletype == REAL)
                                   $$->push_back($2.d);
                            else              
                                   $$->push_back($2.i);
                         }
    ;

/* NEED TO ADD EMPTY SPACE WHEREEVER POSSIBLE IN ARRAY ASSIGN */

arr_assign : '{' arr1d_in_list '}' {$$.dimList = new vector<int>; $$.dimList->push_back($2.count); $$.eletype = $2.eletype;print(*($$.dimList));}
           | '{' comma_arr_assign '}' {$$.dimList = $2.dimList;print(*($$.dimList));$$.eletype = $2.eletype;}
           ; // { {1, 2}, {2, 3}}

comma_arr_assign: comma_arr_assign ',' arr_assign  {updateMaxDim($1.dimList, $3.dimList); delete $3.dimList;$$.dimList = $1.dimList;if (!coercible($1.eletype, $3.eletype)) semanticError("arrays should be initialized with same datatype");else $$.eletype = $1.eletype;}
                | arr_assign {$$.dimList = new vector<int>; addFrontAndCopy($$.dimList, $1.dimList, 1);delete $1.dimList;$$.eletype = $1.eletype;}
                ;

arr1d_in_list: mult_elements {$$.count = $1.count;$$.eletype = $1.eletype;}
             | /* empty */ {$$.count = 0;$$.eletype = UNDEF;}
             ;

mult_elements : mult_elements ',' expression  {$$.count = $1.count + 1; if (!coercible($1.eletype, $3)) semanticError("arrays should be initialized with same datatype");else $$.eletype = $3;} //double to int only checked at decl_stmt 
              | expression {$$.count = 1;$$.eletype = $1;}
              ;

/*  
              ** const_expr: TESTING NOT DONE PROPERLY **
x : const_expr ENDLINE {if ($1.eletype == INT) cout << $1.i; else cout << $1.d;}; 

*/
const_expr: const_expr '+' const_expr {$$.eletype = sumTypeCheck($1.eletype, $3.eletype);

                                          if ($1.eletype == REAL && $3.eletype == REAL)
                                                 $$.d = $1.d + $3.d;
                                          else if ($1.eletype == INT && $3.eletype == REAL)
                                                 $$.d = $1.i + $3.d;  
                                          else if ($1.eletype == REAL && $3.eletype == INT)
                                                 $$.d = $1.d + $3.i;
                                          else 
                                                 $$.i = $1.i + $3.i;                           
                                          

                                      }
       | const_expr '-' const_expr {$$.eletype = diffTypeCheck($1.eletype, $3.eletype);

                                          if ($1.eletype == REAL && $3.eletype == REAL)
                                                 $$.d = $1.d - $3.d;
                                          else if ($1.eletype == INT && $3.eletype == REAL)
                                                 $$.d = $1.i - $3.d;  
                                          else if ($1.eletype == REAL && $3.eletype == INT)
                                                 $$.d = $1.d - $3.i;
                                          else
                                                 $$.i = $1.i - $3.i;
                                   
                                   }
       | const_expr '*' const_expr {$$.eletype = mulTypeCheck($1.eletype, $3.eletype);

                                          if ($1.eletype == REAL && $3.eletype == REAL)
                                                 $$.d = $1.d * $3.d;
                                          else if ($1.eletype == INT && $3.eletype == REAL)
                                                 $$.d = $1.i * $3.d;  
                                          else if ($1.eletype == REAL && $3.eletype == INT)
                                                 $$.d = $1.d * $3.i;
                                          else
                                                 $$.i = $1.i * $3.i;
                                          
                                   }
       | const_expr '/' const_expr {$$.eletype = mulTypeCheck($1.eletype, $3.eletype);

                                          if ($1.eletype == REAL && $3.eletype == REAL)
                                                 $$.d = $1.d / $3.d;
                                          else if ($1.eletype == INT && $3.eletype == REAL)
                                                 $$.d = $1.i / $3.d;  
                                          else if ($1.eletype == REAL && $3.eletype == INT)
                                                 $$.d = $1.d / $3.i;
                                          else
                                                 $$.i = $1.i / $3.i;
                                   }
       | const_expr '%' const_expr {if ($1.eletype != INT || $3.eletype != INT) semanticError("Error: Semantic error incompatible datatype");$$.eletype = INT;
                                          $$.i = $1.i % $3.i;
                                   }
       | const_expr '^' const_expr {$$.eletype = mulTypeCheck($1.eletype, $3.eletype);

                                          if ($1.eletype == REAL && $3.eletype == REAL)
                                                 $$.d = pow($1.d, $3.d);
                                          else if ($1.eletype == INT && $3.eletype == REAL)
                                                 $$.d = pow($1.i, $3.d);  
                                          else if ($1.eletype == REAL && $3.eletype == INT)
                                                 $$.d = pow($1.d, $3.i);
                                          else
                                                 $$.i = pow($1.i, $3.i);

                                   }
       | '-' const_expr {if (!arithCompatible($2.eletype)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $2.eletype;

                            if ($$.eletype == REAL) 
                                   $$.d = -$2.d; 
                            else 
                                   $$.i = -$2.i;
                        } 
/*  

       if these are there in array declarations it is prolly wrong, so not allowing for now

       | NOT const_expr {if (!arithCompatible($2.eletype)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;}
       | const_expr AND const_expr {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;}
       | const_expr OR const_expr{if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;}
       | const_expr CMP_OP const_expr {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;} 
       | const_expr '<' const_expr {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;}
       | const_expr '>' const_expr  {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;}
       | const_expr EQ_CMP_OP const_expr {if(!((arithCompatible($1.eletype) && arithCompatible($3.eletype)))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;}
*/   
       | '(' const_expr ')' {
                                   $$.eletype = $2.eletype;
                                   if ($$.eletype == REAL) 
                                          $$.d = $2.d; 
                                   else 
                                          $$.i = $2.i;
                            } 
       | FLOATS {$$.eletype = $1.eletype;$$.d = $1.d;} 
       | INTEGERS {$$.eletype = $1.eletype;$$.i = $1.i;}
       | BOOLEAN {$$.eletype = INT;$$.i = $1.i;}
       ;          


/* 
ID_LIST: ID_LIST ',' ID check_arr decl_assign {$$ = $1;$$->push_back($3);insert($3, $4, $5);}
       | ID check_arr decl_assign {$$ = new vector<char*>;$$->push_back($1);insert($1, $2, $3);}


decl_assign : EQUAL decl_token {$$ = $2;}
       |   {$$ = UNDEF;}
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
         | {$$ = new vector<int>;}
         ;
  
arr_assign : '{' arr1d_in_list '}' | '{' comma_arr_assign '}'; // { {1,, 2}, {2, 3}}
comma_arr_assign: comma_arr_assign ',' arr_assign  | arr_assign ;       
arr1d_in_list: mult_elements | ;
mult_elements : mult_elements ',' expression  | expression ; 
              
       ; 
*/


member_access: member_access '.' ID  arr_access 
       | ID arr_access 
       ;  

arr_access: arr_access '[' expression ']' |  ;

func_call: member_access '(' param_list ')' | member_access '(' ')' ;


empty_space: empty_space ENDLINE | ;

/* Conditional */

stmt_list1: stmt_list1 stmt | stmt ;  
stmt_block1: empty_space '{' stmt_list1 '}' ENDLINE | empty_space '{' '}' ENDLINE;

cond_stmt : IF '(' expression ')' stmt_block1 {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block1  ELSE stmt_block1 {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block1 elif_stmt ELSE stmt_block1 {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block1 elif_stmt {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        ;

elif_stmt : ELIF '(' expression ')' stmt_block1  {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
          | elif_stmt ELIF '(' expression ')' stmt_block1 {if(!(arithCompatible($4))) semanticError("Error: Semantic error incompatible datatype");}
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

       if (t1 == UNDEF || t2 == UNDEF)
              return true; // check where this function is used and make sure it doesn't cause problems

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
              
              
              if (!coercible(prevType, t))
              {
                     cerr << "Error: " << "types don't match in declaration and initialisation\n";
                     exit(1);
                     // error recovery
              }
              
              updateType(v->at(i), t);
              
              free(v->at(i));
       }

       delete v;

       printSymbolTable();

       return;
}

void insertArray(char* name, vector <int>* dimList){

       insertType(name, Array, UNDEF);
       addDimList(name, *dimList);
       
}

void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList){

       if (decDimList->size() != assignList->size()){

              cerr << "Error: arrays declaration and initialization list don't match\n";
              exit(1); // not freeing anything
       }

       if ((*decDimList)[0] == -1)
             (*decDimList)[0] = (*assignList)[0];

       for (int i = 0;i < decDimList->size();i++){

              if ((*decDimList)[i] < (*assignList)[i]){
                     cerr << "Error: arrays declaration and initialization list don't match\n";
                     exit(1); // not freeing anything
              }
       } 

       insertType(name, Array, e);
       addDimList(name, *decDimList);

       return;
}

void updateMaxDim(vector<int>* comma, vector<int>* assign){

       if (comma->size() != assign->size()+1){

              cerr << "Error: invaid array initializer list\n";
              exit(1); // remove this only if added length checks in declarations O/W segfault 
       }

       for (int i = 0;i < assign->size();i++){

              (*comma)[i+1] = max((*comma)[i+1], (*assign)[i]);
       }

       (*comma)[0] = (*comma)[0] + 1;

       return;
}

/*  eletype can be TRI, CIRCLE, LINE .. as well from identifiers */

enum eletype diffTypeCheck(enum eletype E1, enum eletype E2){

       if (E1 == POINT && E2 == POINT)
              return POINT;
       else if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1); // Change Later
       }
}

enum eletype mulTypeCheck(enum eletype E1, enum eletype E2){

       if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1); // Change Later
       }
}

void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x){

       dest->push_back(x);

       for (int i = 0;i < src->size();i++)
              dest->push_back(src->at(i));
}


int main(int argc, char*argv[])
{    
    if (argc < 2){

        fprintf(stderr, "Please provide the input file\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", argv[1]);
      exit(1);
    }
    yyin = fp;

    /* For testing Lexer */
    const char* tokenFilename = "seq_token.txt";
    fout_token = fopen(tokenFilename, "w");

    if (fout_token == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", tokenFilename);
      exit(1);
    }

    insertConstructTab();

    return yyparse();
} 
