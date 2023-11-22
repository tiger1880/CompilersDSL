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
#include<deque>

extern FILE *yyin; 
FILE* fout_token;
FILE* fout_translated;
void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char* yytext;

using namespace std;

/*     ONLY FOR  DEBUGGING    */
template < typename T >
void print(vector<T>& v){

    for (int i = 0;i < v.size();i++)
        cout << v[i] << " ";
    
    cout << "\n";
}

deque <string> collection;

extern int yydebug;

#define YYDEBUG 1

/* Linearr left */


int ret_flag = 0;
int ret_fig_flag = 0;
int is_member = 0;
int isArray = 0;
int is_fig = 0;

int lineArrNo = 0;

enum eletype ret_type = UNDEF;

vector<ParamList> paramslist;
STentry typelist;
vector<types> params;
vector<types> construct_params;
vector<ParamList> func_paramlist;

%}



%union {

    struct {
       union {
              char* name; 
              int count;
              enum eletype eletype;  
              vector<char*>* nameList;
              vector<int>* dimList;
              struct {
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

              bool stopAdvanceFound; // true for a non-nullified stop/advance
       };

       string* text;
       
    } main;
    
}


%token <main> INTEGERS BOOLEAN FLOATS
%token <main.text> LINE_OP  
%token <main.text> IF
%token <main.text> ELIF
%token <main.text> ELSE
%token <main.text> FOR
%token <main.text> WHILE
%token <main.text> RETURN
%token <main> VOID
%token <main.text> CONTINUE
%token <main.text> BREAK
%token <main.text> PARALLEL
%token <main.text> PERPENDICULAR
%token FUNC
%token FIG
%token <main.text> UNARY
%token <main> DATATYPE
%token <main.text> CMP_OP EQ_CMP_OP
%token <main.text> ASSIGN_OP
%token <main.text> SUM_ASSIGN_OP
%token <main.text> SUB_ASSIGN_OP
%token <main.text> EQUAL
%token <main> STRING_TOKEN
%token ENDLINE
%token <main.name> ID
%token <main> TRICONSTRUCT CIRCLECONSTRUCT PARACONSTRUCT REGPOLYCONSTRUCT
%token <main.text> NOT AND OR 
%token SCALE CENTER


// non-terminals
%nterm <main> construct constructor
%nterm <main> point angle expression member_access 
%nterm <main> assign func_call
%nterm <main> id_list
%nterm <main> mult_elements arr1d_in_list
%nterm <main> const_expr 
%nterm <main> check_arr dim 
%nterm <main> arr_assign comma_arr_assign arr_assign_line
%nterm <main> decl_token decl_assign
%nterm <main> ret_var 
%nterm <main> optional_arg valid_arg
%nterm <main> arr_access
%nterm <main> memb_access
%nterm <main> stmt cond_stmt stmt_list stmt_block stmt_block_for elif_stmt
//%nterm <main.eletype> opt_exp
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
       | program stmt  {if ($stmt.stopAdvanceFound) semanticError("stop/advance cannot be outside the loop");}
       | /* empty */ {
              if(ret_flag) {
                     cerr << "Error: Return statement not allowed outside function" << endl;
              }
         }      
       ; 
 

 /* Function Definition */
func:  FUNC DATATYPE  ID { insertType($3, Func, $2.eletype); addSymTabPtr(); } '(' arg_list {if(paramslist.size()>0) {
                     addParamList($3,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
              ')' empty_space stmt_block {
                     
                     if (ret_flag == 0) {
                            cerr<<"Error: Semantic error no return statement"<<endl;
                     }
                     else if ($DATATYPE.eletype != ret_type) {
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     
                     ret_flag = 0;
                     ret_fig_flag = 0;
                     ret_type = UNDEF;

                     if ($[stmt_block].stopAdvanceFound){
                            semanticError("stop/advance cannot be outside the loop");
                     }

                     delete $ID;
                     delSymTabPtr();
              }
              |  FUNC VOID ID { insertType($3, Func, $2.eletype);  addSymTabPtr(); } '(' arg_list {if(paramslist.size()>0) {
                     addParamList($3,paramslist);
                     insertParams(paramslist);
                     paramslist.clear();
              }}
              ')' empty_space stmt_block {
                     paramslist.clear();
                     
                     if(ret_type!=UNDEF && ret_type!=Void) {
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     ret_flag = 0; 
                     ret_fig_flag = 0;
                     ret_type = UNDEF;

                     if ($[stmt_block].stopAdvanceFound){
                            semanticError("stop/advance cannot be outside the loop");
                     }

                     delete $ID;
                     delSymTabPtr();
              } 
              ;

arg_list : list1 
         | /* empty */
         ;

list1: list1 ',' argument | argument ;

argument : DATATYPE ID check_arr {
              ParamList param;
              param.Eletype = $1.eletype;
              param.name = $2;
              param.dim = *$3.dimList;
              param.Type = Array;
              paramslist.push_back(param);
              delete $ID;
       }
       | DATATYPE ID {
              ParamList param;
              param.Eletype = $1.eletype;
              param.name = $2;
              vector<int> dim;
              param.dim = dim;
              param.Type = Var;
              paramslist.push_back(param);
              delete $ID;
       }
       ;

 
/* Figure Definition */
              
fig: FIG ID {insertType($ID, Fig, UNDEF); addSymTabPtr();}  '(' params ')' empty_space stmt_block { 
                                                        if (ret_fig_flag == 1)  
                                                               semanticError("Error: Return statement is not allowed in figures."); 
                                                        ret_fig_flag = 0;
                                                        

                                                        if ($[stmt_block].stopAdvanceFound)
                                                               semanticError("stop/advance cannot be outside the loop");

                                                        delSymTabPtr();
                                                        delete $ID;
                                                        } 

params : expression ',' expression { if(!(arithCompatible($1.eletype) && $3.eletype == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
       | SCALE EQUAL expression ',' CENTER EQUAL expression { if(!(arithCompatible($3.eletype) && $7.eletype == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}

 /* Statements */
stmt : cond_stmt {$$.stopAdvanceFound = $1.stopAdvanceFound;}
     | loop     {$$.stopAdvanceFound = false;}
     | decl_stmt {$$.stopAdvanceFound = false;}
     | assign_stmt {$$.stopAdvanceFound = false;}
     | return_stmt {$$.stopAdvanceFound = false;}
     | ENDLINE    {$$.stopAdvanceFound = false;}
     | stmt_block {$$.stopAdvanceFound = $1.stopAdvanceFound;}
     | break_stmt {$$.stopAdvanceFound = true;}
     ;

stmt_list: stmt_list stmt {$$.stopAdvanceFound = $1.stopAdvanceFound || $2.stopAdvanceFound;}
         |  /* empty */ {$$.stopAdvanceFound = false;}
         ;

stmt_block: { addSymTabPtr(); } '{'  stmt_list '}' { $$.stopAdvanceFound = $3.stopAdvanceFound; delSymTabPtr(); }
          ;

stmt_block_for: '{'  stmt_list '}' { $$.stopAdvanceFound = $2.stopAdvanceFound; delSymTabPtr(); } // addSymTabPtr before for decl
          ;

break_stmt : BREAK ENDLINE 
           | CONTINUE ENDLINE 
           ;

       /* Return Statement */
return_stmt : RETURN ret_var ENDLINE {ret_type = $2.eletype; ret_flag = 1; ret_fig_flag = 1;};

ret_var : construct {$$.eletype = $1.eletype;} | expression {$$.eletype = $1.eletype;} | {$$.eletype = Void;}; 

       /* Assignment Statement */
assign_stmt : expression ENDLINE {lineArrNo = 0;}
            | construct ENDLINE  {lineArrNo = 0;}
            /* | fig_call ENDLINE */
            ;

/* opt_exp: expression {$$ = $1;}
       | {$$ = UNDEF;}
       ;

fig_call: ID '(' opt_exp[scale] ',' opt_exp[center] ')' {

       if (!arithCompatible($scale) && $scale != UNDEF){
              
              semanticError("in fig call scale has to be a number type");
       }

       if ($center != POINT && $center != UNDEF){
              
              semanticError("in fig call scale has to be a point type");

       }

       STentry figEntry = lookup($ID);

       if (figEntry.Type != Fig)
              semanticError("fig not defined");

       delete $ID;
} */

construct :  constructor '(' construct_param_list ')' {$$.eletype = $1.eletype; construct_params.clear(); } 
          | constructor '(' ')' {$$.eletype = $1.eletype;} 
          ; 

constructor : TRICONSTRUCT { $$.eletype = $1.eletype;} 
            | CIRCLECONSTRUCT { $$.eletype = $1.eletype;} 
            | PARACONSTRUCT { $$.eletype = $1.eletype;} 
            | REGPOLYCONSTRUCT { $$.eletype = $1.eletype;}
            ;

valid_arg: construct {$$.eletype = $1.eletype;}
         | expression {$$.eletype = $1.eletype;}
         ;

param_list: param_list ',' valid_arg {
              if(is_member) {
                  params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     params.push_back({$3.eletype,Var,dim});   
              }
          }
          | valid_arg {
              if(is_member) {
                     params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                     is_member = 0;
              }
              else {
                     vector<int> dim;
                     params.push_back({$1.eletype,Var,dim});   
              }
          }
          ;

construct_param_list: construct_param_list ',' valid_arg {
              if(is_member) {
                  construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList}); 
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({$3.eletype,Var,dim});   
              }
          }
          | valid_arg {
              if(is_member) {
                     construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                    is_member = 0;
                    
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({$1.eletype,Var,dim});   
              }
          }
          ;

point : '(' expression ','  expression ',' STRING_TOKEN ')' {  $$.eletype = pointCheck($2.eletype, $4.eletype); }
       |  '(' expression ','  expression  ')'  {  $$.eletype = pointCheck($2.eletype, $4.eletype);}
       ; 

// NOT TESTED
vertex: member_access { if ($1.eletype != POINT) semanticError("Error: vertex has to be a point");}
      /* | func_call { if ($1 != POINT) semanticError("Error: vertex has to be a point");} */
      | point 
      ;

angle : '<' vertex vertex vertex ',' BOOLEAN '>'  {$$.eletype = ANGLE;}
       | '<' vertex vertex vertex '>' {$$.eletype = ANGLE;}
       ;

expression:   expression '+' expression {$$.eletype = sumTypeCheck($1.eletype, $3.eletype);}
            | expression '-' expression {$$.eletype = diffTypeCheck($1.eletype, $3.eletype);} 
            | expression '*' expression {$$.eletype = mulTypeCheck($1.eletype, $3.eletype);}
            | expression '/' expression {$$.eletype = mulTypeCheck($1.eletype, $3.eletype);}
            | expression '%' expression {if ($1.eletype != INT || $3.eletype != INT) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = INT;}
            | expression '^' expression {$$.eletype = mulTypeCheck($1.eletype, $3.eletype);}
            | expression LINE_OP expression {if(($1.eletype == POINT || $1.eletype == LINEARR) && $3.eletype == POINT) {$$.eletype = LINEARR; lineArrNo++;} else  semanticError("Error: Semantic error incompatible datatype");}  // <-> ->
            | expression PARALLEL expression {$$.eletype = parallelCheck($1.eletype, $3.eletype);}
            | expression PERPENDICULAR expression  {$$.eletype = perpendicularCheck($1.eletype, $3.eletype);}
            | PARALLEL inside_norm PARALLEL  {$$.eletype = REAL;}
            | '-' expression %prec NEG {if (!arithCompatible($2.eletype)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $2.eletype; } 
            | UNARY member_access {if(!($2.eletype == INT || $2.eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $2.eletype;  }
            | member_access UNARY {if(!($1.eletype == INT || $1.eletype == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $1.eletype;  }
            | NOT expression {if (!arithCompatible($2.eletype)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;}
            | expression AND expression {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;  }
            | expression OR expression {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;  }
            | member_access assign       {if (!(($1.eletype == $2.eletype) || coercible($1.eletype, $2.eletype) || ($1.eletype == LINE && $2.eletype == LINEARR && lineArrNo == 1))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $1.eletype; }
            | expression CMP_OP expression {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype)) && ($1.eletype!=LABEL || $3.eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;} 
            | expression '<' expression {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype)) && ($1.eletype!=LABEL || $3.eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;}
            | expression '>' expression  {if(!(arithCompatible($1.eletype) && arithCompatible($3.eletype)) && ($1.eletype!=LABEL || $3.eletype != LABEL)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;}
            | expression EQ_CMP_OP expression {if(!((arithCompatible($1.eletype) && arithCompatible($3.eletype)) || ($1.eletype == $3.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = BOOL;}
            | member_access {$$.eletype = $1.eletype;}
            | '(' expression ')' {$$.eletype = $2.eletype;}
            | FLOATS {$$.eletype = $1.constExp.eletype;} 
            | INTEGERS {$$.eletype = $1.constExp.eletype;}
            | BOOLEAN {$$.eletype = $1.constExp.eletype;}
            | STRING_TOKEN {$$.eletype = $1.eletype;}
            | func_call {$$.eletype = $1.eletype;}
            | point {$$.eletype = $1.eletype;}
            | angle {$$.eletype = $1.eletype;}            
            ; 

inside_norm: inside_norm '+' vertex 
           | inside_norm '-' vertex 
           | vertex
           /* | memb_access assign   will := add in || ||  later*/
           ; // norm cannot be empty

assign:  EQUAL expression {$$.eletype = $2.eletype;}
       | ASSIGN_OP  expression  {if(!(arithCompatible($2.eletype))) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $2.eletype; }  
       | SUM_ASSIGN_OP  expression  {if(!(arithCompatible($2.eletype) || $2.eletype == LABEL || $2.eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $2.eletype; }
       | SUB_ASSIGN_OP expression {if(!(arithCompatible($2.eletype) || $2.eletype == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$.eletype = $2.eletype;}
       ;

       /* Declaration Statement */
decl_stmt : DATATYPE id_list ENDLINE {typeUpdate($2.nameList, $1.eletype);lineArrNo = 0;}
          | constructor id_list ENDLINE {typeUpdate($2.nameList, $1.eletype);lineArrNo = 0;}
          ;

id_list: id_list ',' ID check_arr EQUAL arr_assign_line {$$.nameList = $1.nameList;$$.nameList->push_back($3);compareAndInsertArray($3, $4.dimList, $6.listAndType.eletype, $6.listAndType.dimList);}
       | id_list ',' ID check_arr  {$$.nameList = $1.nameList;$$.nameList->push_back($3);insertArray($3, $4.dimList);}       
       | id_list ',' ID decl_assign {$$.nameList = $1.nameList;$$.nameList->push_back($3);insertType($3, Var, $4.eletype);}
       | ID check_arr  {$$.nameList = new vector<char*>;$$.nameList->push_back($1);insertArray($1, $2.dimList);}
       | ID check_arr EQUAL arr_assign_line {$$.nameList = new vector<char*>;$$.nameList->push_back($1);compareAndInsertArray($1, $2.dimList, $4.listAndType.eletype, $4.listAndType.dimList);}
       | ID decl_assign {$$.nameList = new vector<char*>;$$.nameList->push_back($1);insertType($1, Var, $2.eletype);}
       ;

decl_assign: EQUAL decl_token {$$.eletype = $2.eletype;}
       | /* empty */  {$$.eletype = UNDEF;}
       ; 

decl_token: construct  {$$.eletype = $1.eletype;}
       | expression {$$.eletype = $1.eletype;}
       ;

/* Arrays */
check_arr: dim {$$.dimList = $1.dimList;}
         | '['']' {$$.dimList = new vector<int>;$$.dimList->push_back(-1);}
         | '['']' dim {$$.dimList = new vector<int>;addFrontAndCopy($$.dimList, $3.dimList, -1);delete $3.dimList;}
         ;
         
dim : dim '[' const_expr ']' {$$.dimList = $1.dimList;
                              
                            if ($3.constExp.eletype == REAL)
                                   $$.dimList->push_back($3.constExp.d);
                            else              
                                   $$.dimList->push_back($3.constExp.i);
                            
                            }
    | '[' const_expr ']' {$$.dimList = new vector<int>; 

                            if ($2.constExp.eletype == REAL)
                                   $$.dimList->push_back($2.constExp.d);
                            else              
                                   $$.dimList->push_back($2.constExp.i);
                         }
    ;

/* NEED TO ADD EMPTY SPACE WHEREEVER POSSIBLE IN ARRAY ASSIGN */

arr_assign_line : arr_assign {$$.listAndType.dimList = $1.listAndType.dimList;$$.listAndType.eletype = $1.listAndType.eletype;}
                | expression {
                            if ($1.eletype != LINEARR) 
                                   semanticError("Error: Invalid Datatypes\n");
                            $$.listAndType.dimList = new vector<int>;
                            $$.listAndType.dimList->push_back(lineArrNo);
                            lineArrNo = 0;
                     }
                ;

arr_assign : '{'  arr1d_in_list '}' {$$.listAndType.dimList = new vector<int>; $$.listAndType.dimList->push_back($2.countAndType.count); $$.listAndType.eletype = $2.countAndType.eletype;}
           | '{' comma_arr_assign '}' {$$.listAndType.dimList = $2.listAndType.dimList;$$.listAndType.eletype = $2.listAndType.eletype;}
           ; // { {1, 2}, {2, 3}}

comma_arr_assign: comma_arr_assign ',' arr_assign  {updateMaxDim($1.listAndType.dimList, $3.listAndType.dimList); delete $3.listAndType.dimList;$$.listAndType.dimList = $1.listAndType.dimList;if (!coercible($1.listAndType.eletype, $3.listAndType.eletype)) semanticError("arrays should be initialized with same datatype");else $$.listAndType.eletype = $1.listAndType.eletype;}
                | arr_assign {$$.listAndType.dimList = new vector<int>; addFrontAndCopy($$.listAndType.dimList, $1.listAndType.dimList, 1);delete $1.listAndType.dimList;$$.listAndType.eletype = $1.listAndType.eletype;}
                ;

arr1d_in_list: mult_elements {$$.countAndType.count = $1.countAndType.count;$$.eletype = $1.countAndType.eletype;}
             | /* empty */ {$$.countAndType.count = 0;$$.eletype = UNDEF;}
             ;

mult_elements : mult_elements ',' expression  {$$.count = $1.countAndType.count + 1; if (!coercible($1.countAndType.eletype, $3.eletype)) semanticError("arrays should be initialized with same datatype");else $$.countAndType.eletype = $3.eletype;} //double to int only checked at decl_stmt 
              | expression {$$.countAndType.count = 1;$$.countAndType.eletype = $1.eletype;}
              ;

const_expr: const_expr '+' const_expr {$$.constExp.eletype = sumTypeCheck($1.constExp.eletype, $3.constExp.eletype);

                                          if ($1.constExp.eletype == REAL && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.d + $3.constExp.d;
                                          else if ($1.constExp.eletype == INT && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.i + $3.constExp.d;  
                                          else if ($1.constExp.eletype == REAL && $3.constExp.eletype == INT)
                                                 $$.constExp.d = $1.constExp.d + $3.constExp.i;
                                          else 
                                                 $$.constExp.i = $1.constExp.i + $3.constExp.i;                           
                                          

                                      }
       | const_expr '-' const_expr {$$.constExp.eletype = diffTypeCheck($1.constExp.eletype, $3.constExp.eletype);

                                          if ($1.constExp.eletype == REAL && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.d - $3.constExp.d;
                                          else if ($1.constExp.eletype == INT && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.i - $3.constExp.d;  
                                          else if ($1.constExp.eletype == REAL && $3.constExp.eletype == INT)
                                                 $$.constExp.d = $1.constExp.d - $3.constExp.i;
                                          else
                                                 $$.constExp.i = $1.constExp.i - $3.constExp.i;
                                   
                                   }
       | const_expr '*' const_expr {$$.constExp.eletype = mulTypeCheck($1.constExp.eletype, $3.constExp.eletype);

                                          if ($1.constExp.eletype == REAL && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.d * $3.constExp.d;
                                          else if ($1.constExp.eletype == INT && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.i * $3.constExp.d;  
                                          else if ($1.constExp.eletype == REAL && $3.constExp.eletype == INT)
                                                 $$.constExp.d = $1.constExp.d * $3.constExp.i;
                                          else
                                                 $$.constExp.i = $1.constExp.i * $3.constExp.i;
                                          
                                   }
       | const_expr '/' const_expr {$$.constExp.eletype = mulTypeCheck($1.constExp.eletype, $3.constExp.eletype);

                                          if ($1.constExp.eletype == REAL && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.d / $3.constExp.d;
                                          else if ($1.constExp.eletype == INT && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = $1.constExp.i / $3.constExp.d;  
                                          else if ($1.constExp.eletype == REAL && $3.constExp.eletype == INT)
                                                 $$.constExp.d = $1.constExp.d / $3.constExp.i;
                                          else
                                                 $$.constExp.i = $1.constExp.i / $3.constExp.i;
                                   }
       | const_expr '%' const_expr {if ($1.constExp.eletype != INT || $3.constExp.eletype != INT) semanticError("Error: Semantic error incompatible datatype");$$.constExp.eletype = INT;
                                          $$.constExp.i = $1.constExp.i % $3.constExp.i;
                                   }
       | const_expr '^' const_expr {$$.constExp.eletype = mulTypeCheck($1.constExp.eletype, $3.constExp.eletype);

                                          if ($1.constExp.eletype == REAL && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = pow($1.constExp.d, $3.constExp.d);
                                          else if ($1.constExp.eletype == INT && $3.constExp.eletype == REAL)
                                                 $$.constExp.d = pow($1.constExp.i, $3.constExp.d);  
                                          else if ($1.constExp.eletype == REAL && $3.constExp.eletype == INT)
                                                 $$.constExp.d = pow($1.constExp.d, $3.constExp.i);
                                          else
                                                 $$.constExp.i = pow($1.constExp.i, $3.constExp.i);

                                   }
       | '-' const_expr {if (!arithCompatible($2.constExp.eletype)) semanticError("Error: Semantic error incompatible datatype"); $$.constExp.eletype = $2.constExp.eletype;

                            if ($$.constExp.eletype == REAL) 
                                   $$.constExp.d = -$2.constExp.d; 
                            else 
                                   $$.constExp.i = -$2.constExp.i;
                        } 
       | '(' const_expr ')' {
                                   $$.constExp.eletype = $2.constExp.eletype;
                                   if ($$.constExp.eletype == REAL) 
                                          $$.constExp.d = $2.constExp.d; 
                                   else 
                                          $$.constExp.i = $2.constExp.i;
                            } 
       | FLOATS {$$.eletype = $1.constExp.eletype;$$.constExp.d = $1.constExp.d;} 
       | INTEGERS {$$.eletype = $1.constExp.eletype;$$.constExp.i = $1.constExp.i;}
       | BOOLEAN {$$.eletype = INT;$$.constExp.i = $1.constExp.i;}
       ;          



member_access : memb_access {
              if($1.dimCount->empty()) {
                     exit(1);
              }
              typelist = returnType(*$1.dimCount);
              $$.eletype = typelist.Eletype;
              for (int i = 0;i < $1.dimCount->size();i++){
                     delete ($1.dimCount->at(i)).name ;
              }
              is_member = 1;
       };

memb_access: memb_access '.' ID  arr_access {
                     $$.dimCount = $1.dimCount; 
                     int count = checkDims($3,$4.count);
                     if(count >= 0) {
                            $$.dimCount->push_back({count,$3});
                     }
              }
              | ID arr_access {
                     int count = checkDims($1,$2.count);
                     $$.dimCount = new vector<cntAndType> ;   //free?
                     if(count >= 0) {
                            $$.dimCount->push_back({count,$1});  
                     }     
              }
       ;  

arr_access: arr_access '[' expression ']' {$$.count = $1.count; $$.count = $$.count + 1;} 
          | /* empty */ {$$.count = 0;} 
          ;

func_call : member_access {

              if (typelist.Type == Fig){
                     is_fig = 1;
              }
              else {
                     if (typelist.Type != Func) 
                            semanticError("Error: Identifier is not a function"); 
                     func_paramlist = typelist.paramList;
              }
              is_member = 0;
       }
       '(' param_list_opt ')' {

              if (is_fig){
                     figArgumentChecking(params);
                     params.clear();
                     $$.eletype = UNDEF;
              }
              else {

                     argumentTypeChecking(func_paramlist, params);
                     params.clear();

                     $$.eletype = $1.eletype;              
              }

              is_fig = 0;
       };
          

param_list_opt : param_list 
               | /* empty */ 
               ;

empty_space: empty_space ENDLINE 
           | /* empty */ 
           ;

/* Conditional Statements */

cond_stmt:  IF '(' expression ')' empty_space stmt_block ENDLINE {$$.stopAdvanceFound = $6.stopAdvanceFound;if(!(arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' empty_space stmt_block ENDLINE  ELSE empty_space stmt_block ENDLINE {$$.stopAdvanceFound = $6.stopAdvanceFound||$10.stopAdvanceFound;if(!(arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt ELSE empty_space stmt_block ENDLINE {$$.stopAdvanceFound = $6.stopAdvanceFound||$8.stopAdvanceFound||$11.stopAdvanceFound;if(!(arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt {$$.stopAdvanceFound = $6.stopAdvanceFound||$8.stopAdvanceFound;if(!(arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype");}
        ;

elif_stmt : ELIF '(' expression ')' empty_space stmt_block ENDLINE  {$$.stopAdvanceFound = $[stmt_block].stopAdvanceFound;if(!(arithCompatible($3.eletype))) semanticError("Error: Semantic error incompatible datatype");}
          | elif_stmt ELIF '(' expression ')' empty_space stmt_block ENDLINE {$$.stopAdvanceFound = $1.stopAdvanceFound||$[stmt_block].stopAdvanceFound;if(!(arithCompatible($4.eletype))) semanticError("Error: Semantic error incompatible datatype");}
          ;


/* Loops */

loop : for_loop 
     | while_loop
     ;

for_loop_decl : { addSymTabPtr(); } DATATYPE ID EQUAL expression { insertType($ID, Var, $DATATYPE.eletype);delete $ID;}
              | { addSymTabPtr(); } ID EQUAL expression { delete $ID; }
              | { addSymTabPtr(); } 
              ;

optional_arg: expression  {$$.eletype = $1.eletype;} 
            | /* empty */ {$$.eletype = UNDEF;} 
            ;
            
for_loop : FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' empty_space stmt_block_for {if(!(arithCompatible($5.eletype)) && $5.eletype != UNDEF) semanticError("Error: Semantic error incompatible datatype11");}

while_loop : WHILE '(' expression ')' empty_space stmt_block 
           ;


%%

/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
}

string function_translation(string text) {
       return "true";
}

string fig_translation(string text) {
       return "true";
}




int main(int argc, char*argv[])
{    

    /* yydebug = 1; */
    if (argc < 2){

        fprintf(stderr, "Please provide the input file\n");
        exit(1);
    }

    /* Appending \n */ 
    FILE* a = fopen(argv[1], "a");
       
       // test
    if (a == NULL)
    {
       fprintf(stderr, "%s file could not be opened\n", argv[1]);
       fclose(a);
       exit(1);
    }

    fprintf(a, "\n");

    fclose(a);


    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", argv[1]);
      fclose(fp);
      exit(1);
    }

    yyin = fp;

    /* For testing Lexer */
    const char* tokenFilename = "seq_token.txt";
    fout_token = fopen(tokenFilename, "w");

    if (fout_token == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", tokenFilename);
      fclose(fout_token);
      exit(1);
    }

    /*For translation */

    const char* translatedFilename = "translated.cpp";
    fout_translated = fopen(translatedFilename, "w");

    if (fout_translated == NULL)
    {
      fprintf(stderr, "%s file could not be opened\n", translatedFilename);
      exit(1);
    }

    fprintf(fout_translated,"#include<iostream>\n");
    fprintf(fout_translated,"#include<vector>\n");
    fprintf(fout_translated,"#include<GL/glut.h>\n");
    fprintf(fout_translated,"#include<string>\n");
    fprintf(fout_translated,"#include<stdlib.h>\n");
    fprintf(fout_translated,"#include<math.h>\n");
    fprintf(fout_translated,"#include<deque>\n");
    fprintf(fout_translated,"#include \"standard_lib.hpp \" \n");


    insertConstructTab();

    int x = yyparse();

    fclose(fp);
    fclose(fout_token);
    return x;
} 
