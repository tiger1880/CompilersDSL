%{
#include "symbol_table.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include<algorithm>
#include <vector>
#include <map>

extern FILE *yyin; 
FILE* fout_token;
void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char* yytext;

using namespace std;

int checkDims(char* name,int count);
STentry returnType(vector<cntAndType> dimsAndType);
void argumentTypeChecking(vector<ParamList> &func_params,vector<types> &passed_params);


/*     ONLY FOR  DEBUGGING    */
template < typename T >
void print(vector<T>& v){

    for (int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    
    cout << "\n";
}

extern int yydebug;

#define YYDEBUG 1
/*     ONLY FOR  DEBUGGING    

Problems: 1.) linearr should have dimension 1. Hence dimension not matching
          2.) label s := "LABEL" showing  Error: types don't match in declaration and initialisation  
          3.) Some problem with point declaration/initialization check once.
          4.) 
*/


int ret_flag = 0;
int ret_fig_flag = 0;
int is_member = 0;
int isArray = 0;

enum eletype ret_type = UNDEF;

vector<ParamList> paramslist;
STentry typelist;
vector<types> params;
vector<ParamList> func_paramlist;

%}



%union {
    char* name; 
    int count;
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
    
    vector<cntAndType>* dimCount;
   
    
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
%nterm <eletype> assign func_call
%nterm <nameList> id_list
%nterm <countAndType> mult_elements arr1d_in_list
%nterm <constExp> const_expr 
%nterm <dimList> check_arr dim 
%nterm <listAndType> arr_assign comma_arr_assign
%nterm <eletype> decl_token decl_assign
%nterm <eletype> cond_stmt ret_var 
%nterm <eletype> optional_arg valid_arg
%nterm <count> arr_access
%nterm <dimCount> memb_access
//%nterm <types> param_list;



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
                     cerr << "Error: Return statement not allowed outside function" << endl;
              }
         }      
       ; 
 

 /* Function Definition */
func:  FUNC DATATYPE  ID { insertType($3, Func, $2); addSymTabPtr(); } '(' arg_list {if(paramslist.size()>0) {
                     addParamList($3,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
              ')' empty_space '{' func_body  '}' {
                     //printSymbolTable();
                     if(ret_flag==0) {
                            cerr<<"Error: Semantic error no return statement"<<endl;
                     }
                     else if($2!=ret_type) {
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     
                     ret_flag = 0;
                     ret_fig_flag = 0;
                     ret_type = UNDEF;
                     delete $ID;
                     delSymTabPtr();
              }
              |  FUNC VOID ID { insertType($3, Func, $2);  addSymTabPtr(); } '(' arg_list {if(paramslist.size()>0) {
                     addParamList($3,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
              ')' empty_space '{' func_body '}' {
                     paramslist.clear();
                     //printSymbolTable();
                     
                     if(ret_type!=UNDEF && ret_type!=Void) {
                            cout<<"Hi"<<endl;
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     ret_flag = 0; 
                     ret_fig_flag = 0;
                     ret_type = UNDEF;
                     delete $ID;
                     delSymTabPtr();
              }   //Need to do testing
              ;

arg_list : list1 
         | /* empty */
         ;

list1: list1 ',' argument | argument ;

argument : DATATYPE ID check_arr {
              ParamList param;
              param.Eletype = $1;
              param.name = $2;
              param.dim = *$3;
              param.Type = Array;
              paramslist.push_back(param);
              // for(int i =0;i<$3->size();i++) {
              //        cout<<$3->at(i)<<endl;
              // }
              delete $ID;
       }
       | DATATYPE ID {
              ParamList param;
              param.Eletype = $1;
              param.name = $2;
              vector<int> dim;
              param.dim = dim;
              param.Type = Var;
              paramslist.push_back(param);
              delete $ID;
       }
;

func_body : func_body stmt  | ;
 
/* Figure Definition */
              
fig: FIG ID { addSymTabPtr();}  '(' params ')' empty_space '{' fig_body '}'{ if (ret_fig_flag == 1)  semanticError("Error: Return statement is not allowed in figures."); ret_fig_flag = 0;insertType($ID, Fig, UNDEF);delSymTabPtr();delete $ID; } 
params : expression ',' expression { if(!(arithCompatible($1) && $3 == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
       | SCALE EQUAL expression ',' CENTER EQUAL expression { if(!(arithCompatible($3) && $7 == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}
fig_body : fig_body stmt | ;

 /* Statements */
stmt : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | ENDLINE | stmt_block;

stmt_list: stmt_list stmt
         |  /* empty */
         ;

stmt_block: { addSymTabPtr(); } '{'  stmt_list '}' { delSymTabPtr(); }
          ;

stmt_loop : cond_stmt | loop | decl_stmt | assign_stmt | return_stmt | break_stmt | ENDLINE | stmt_loop_block ;  //Add return type here

break_stmt : BREAK ENDLINE | CONTINUE ENDLINE ;

stmt_loop_list: stmt_loop_list stmt_loop | ;

stmt_loop_block:  { addSymTabPtr(); } '{'  stmt_loop_list '}' { delSymTabPtr(); };

       /* Return Statement */
return_stmt : RETURN ret_var ENDLINE {ret_type = $2; ret_flag = 1; ret_fig_flag = 1;};

ret_var : construct {$$ = $1;} | expression {$$ = $1;} | {$$ = Void;}; 

       /* Assignment Statement */
assign_stmt : expression ENDLINE {$$ = $1;}
            | construct ENDLINE  {$$ = $1;}
            ;

construct :  constructor '(' param_list ')' {$$ = $1; params.clear(); } 
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

param_list: param_list ',' valid_arg {
              if(is_member) {
                  params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  isArray = 0; 
              }
              else {
                     vector<int> dim;
                     params.push_back({$3,Var,dim});   
              }
          }
          | valid_arg {
              if(is_member) {
                     params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                    isArray = 0;
                    
              }
              else {
                     vector<int> dim;
                     params.push_back({$1,Var,dim});   
              }
          }
          ;

point : '(' expression ','  expression ',' STRING_TOKEN ')' {  $$ = pointCheck($2, $4); }
       |  '(' expression ','  expression  ')'  {  $$ = pointCheck($2, $4);}
       ; 

// NOT TESTED
vertex: ID { if (checkEletype($1) != POINT) semanticError("Error: vertex has to be a point");delete $ID;}
      | point 
      ;

angle : '<' vertex vertex vertex ',' BOOLEAN '>'  {$$ = ANGLE;}
       | '<' vertex vertex vertex '>' {$$ = ANGLE;}
       ;

expression:   expression '+' expression {$$ = sumTypeCheck($1, $3);}
            | expression '-' expression {$$ = diffTypeCheck($1, $3);} // change this - won't work for p-q->r for now
            | expression '*' expression {$$ = mulTypeCheck($1, $3);}
            | expression '/' expression {$$ = mulTypeCheck($1, $3);}
            | expression '%' expression {if ($1 != INT || $3 != INT) semanticError("Error: Semantic error incompatible datatype"); $$ = INT;}
            | expression '^' expression {$$ = mulTypeCheck($1, $3);}
            /* | expression LINE_OP expression {if(($1 == POINT || $1 == LINEARR) && $3 == POINT) $$ = LINEARR; else  semanticError("Error: Semantic error incompatible datatype");}  // <-> -> */
            /* | expression PARALLEL expression {if(($1 == LINE||$1 == LINEARR) && ($3 == LINE||$1 == LINEARR)) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ;  } */
            /* | expression PERPENDICULAR expression  {if(($1 == LINE||$1 == LINEARR) && ($3 == LINE||$1 == LINEARR)) $$ = BOOL ; else  semanticError("Error: Semantic error incompatible datatype") ; } */
            | PARALLEL expression PARALLEL  {if ($2 != POINT) semanticError("Error: Semantic error incompatible datatype") ; $$ = REAL; }
            | '-' expression %prec NEG {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; } 
            | UNARY member_access {if(!($2 == INT || $2 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;  }
            | member_access UNARY {if(!($1 == INT || $1 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;  }
            | NOT expression {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression AND expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression OR expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | member_access assign       {if (!(($1 == $2) || coercible($1, $2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $1; }
            /* {if(!($2 == POINT && $1 == POINT)||($2 == LABEL && $1 == LABEL || arithCompatible($1) && arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;} */
            | expression CMP_OP expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;} 
            | expression '<' expression {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression '>' expression  {if(!(arithCompatible($1) && arithCompatible($3)) && ($1!=LABEL || $3 != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression EQ_CMP_OP expression {if(!((arithCompatible($1) && arithCompatible($3)) || ($1 == $3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | member_access {$$ = $1; }
            | '(' expression ')' {$$ = $2;}
            | FLOATS {$$ = $1.eletype;} 
            | INTEGERS {$$ = $1.eletype;}
            | BOOLEAN {$$ = $1.eletype;}
            | STRING_TOKEN {$$ = $1;}
            | func_call {$$ = $1;}
            | point {$$ = $1;}
            | angle {$$ = $1;}            
            ; 

assign:  EQUAL expression {$$ = $2;}
       | ASSIGN_OP  expression  {if(!(arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }  
       | SUM_ASSIGN_OP  expression  {if(!(arithCompatible($2) || $2 == LABEL || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }
       | SUB_ASSIGN_OP expression {if(!(arithCompatible($2) || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;}
       ;

//Error coming for x := x + 2 / p.x +:= 3 type statements which it shouldn't.

       /* Declaration Statement */
decl_stmt : DATATYPE id_list ENDLINE {typeUpdate($2, $1);}
          | constructor id_list ENDLINE {typeUpdate($2, $1);}
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

arr_assign : '{'  arr1d_in_list '}' {$$.dimList = new vector<int>; $$.dimList->push_back($2.count); $$.eletype = $2.eletype;print(*($$.dimList));}
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



member_access : memb_access {
              if($1->empty()) {
                     exit(1);
              }
              typelist = returnType(*$1);
              //cout<<typelist.Eletype<<endl;
              $$ = typelist.Eletype;
              for (int i = 0;i < $1->size();i++){
                     delete ($1->at(i)).name ;
              }
              is_member = 1;
       };

memb_access: memb_access '.' ID  arr_access {
                     $$ = $1; 
                     int count = checkDims($3,$4);
                     if(count >= 0) {
                            $$->push_back({count,$3});
                     }
              }
              | ID arr_access {
                     int count = checkDims($1,$2);
                     $$ = new vector<cntAndType> ;   //free?
                     if(count >= 0) {
                            $$->push_back({count,$1});  
                     }     
              }
       ;  

arr_access: arr_access '[' expression ']' {$$ = $1; $$ = $$ + 1;} | {$$ = 0;} ;

func_call : member_access {
              if(typelist.Type!=Func) semanticError("Error: Identifier is not a function"); 
              func_paramlist = typelist.paramList;
              is_member = 0;
           }
          '(' param_list_opt ')' {
              //cout<<params.size()<<endl;
              argumentTypeChecking(func_paramlist,params);
              params.clear();

              $$ = $1;
          };
          

param_list_opt : param_list 
               | /* empty */ 
               ;

empty_space: empty_space ENDLINE 
           | /* empty */ 
           ;

/* Conditional */

stmt_list1: stmt_list1 stmt 
          | stmt 
          ; 
stmt_list1_opt: stmt_list1 
              | /* empty */ 
              ; 
stmt_block1: empty_space {addSymTabPtr();} '{' stmt_list1_opt '}' { delSymTabPtr();} ENDLINE
           ;

cond_stmt:  IF '(' expression ')' stmt_block1 {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block1  ELSE stmt_block1 {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block1 elif_stmt ELSE stmt_block1 {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' stmt_block1 elif_stmt {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        ;

elif_stmt : ELIF '(' expression ')' stmt_block1  {if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
          | elif_stmt ELIF '(' expression ')' stmt_block1 {if(!(arithCompatible($4))) semanticError("Error: Semantic error incompatible datatype");}
          ;

/* Loops */
  
stmt_loop_list1: stmt_loop_list1 stmt_loop 
               | stmt_loop
               ;
stmt_loop_list1_opt: stmt_loop_list1
                   | /* empty */
                   ;
stmt_loop_block1: empty_space  '{' stmt_loop_list1_opt '}' {delSymTabPtr();} 
                ;
loop : for_loop 
     | while_loop
     ;

// need to add constructor, array here
for_loop_decl : { addSymTabPtr(); } DATATYPE ID EQUAL expression { insertType($ID, Var, $DATATYPE);delete $ID;/*printSymbolTable();*/ }
              | { addSymTabPtr(); } ID EQUAL expression { delete $ID; }
              | { addSymTabPtr(); } 
              ;

optional_arg: expression  {$$ = $1;} 
            | /* empty */ {$$ = UNDEF;} 
            ;
            
for_loop : FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' stmt_loop_block1 {if(!(arithCompatible($5))) semanticError("Error: Semantic error incompatible datatype11");}

while_loop : WHILE '(' expression ')' { addSymTabPtr(); } stmt_loop_block1


%%

/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

int checkDims(char* name,int count) {
       if(lookupConstructTab2(name).Type!=Invalid) {
           return 0;
       }
       //cout<<name<<endl;
       vector<int> dimlist (checkDimList(name)); 
       if(dimlist.size() < count) {
              /* cout<<count<<endl;
              cout<<dimlist.size()<<endl; */
              cerr<<"Error: Dimension not matching"<<endl;
              return -1;
       }
       else {
              return dimlist.size() - count;
       }
}

STentry returnType(vector<cntAndType> dimsAndType) {
       STentry t;
       STentry s = lookup(dimsAndType[0].name);
       if(s.Type==Invalid) {
           STentry st = lookupConstructTab(dimsAndType[0].name,UNDEF);
           if(st.Type==Invalid) {
              cerr<<"Error: Identifier not found"<<endl;
              exit(1);
           }
           else {
              return st;  // Std Library function
           }   
       }
       else {
              t = s;
              vector<int> new_dimlist;
              for(int i = dimsAndType[0].count;i<t.DimList.size();i++) {
                     new_dimlist.push_back(t.DimList[i]);
              }
              t.DimList = new_dimlist;
              for(int i = 1;i<dimsAndType.size();i++) {
                     if(dimsAndType[i-1].count > 0) {
                            cerr<<"Error: Array has no member attribute"<<endl;
                            exit(1);
                     }
                     else {
                        STentry st = lookupConstructTab(dimsAndType[i].name,t.Eletype);
                        if(st.Type!=Invalid) {
                            t = st;
                        }            
                     }         
              }

              return t;
       }
       
}

void argumentTypeChecking(vector<ParamList> &func_params,vector<types> &passed_params) {
       if(func_params.size() > passed_params.size()) {
              semanticError("Error: Too few arguments");
       }
       else if(func_params.size() < passed_params.size()) {
              semanticError("Error: Too many arguments");
       }
       else {
              for(int i = 0;i<func_params.size();i++) {
                     /* cout<<func_params[i].Eletype<<endl;
                     cout<<passed_params[i].eletype<<endl; */
                     if(func_params[i].Eletype==passed_params[i].eletype) {
                            bool isEqual = 0;
                            
                            if(equal(func_params[i].dim.begin(),func_params[i].dim.end(),passed_params[i].dim.begin(),passed_params[i].dim.end())) {
                                   isEqual = 1;
                            }
                            if(!isEqual) {
                                   semanticError("Error: Array dimension is not matching for argument"); 
                            }  
                     }
                     else {
                            semanticError("Error: Type is not matching for argument");
                     }
              }
       }
}


int main(int argc, char*argv[])
{    

    /* yydebug = 1; */
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
