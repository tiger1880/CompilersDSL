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
          3.) Error Handling
          4.) figure call
*/


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

    bool stopAdvanceFound; // true for a non-nullified stop/advance
   
    
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
%nterm <eletype> construct constructor
%nterm <eletype> point angle expression member_access 
%nterm <eletype> assign func_call
%nterm <nameList> id_list
%nterm <countAndType> mult_elements arr1d_in_list
%nterm <constExp> const_expr 
%nterm <dimList> check_arr dim 
%nterm <listAndType> arr_assign comma_arr_assign arr_assign_line
%nterm <eletype> decl_token decl_assign
%nterm <eletype> ret_var 
%nterm <eletype> optional_arg valid_arg
%nterm <count> arr_access
%nterm <dimCount> memb_access
%nterm <stopAdvanceFound> stmt cond_stmt stmt_list stmt_block stmt_block_for elif_stmt
%nterm <eletype> opt_exp
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
       | program stmt  {if ($stmt) semanticError("stop/advance cannot be outside the loop");}
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
              ')' empty_space stmt_block {
                     
                     if (ret_flag == 0) {
                            cerr<<"Error: Semantic error no return statement"<<endl;
                     }
                     else if ($DATATYPE != ret_type) {
                            cerr<<"Error: Semantic error return type not matching"<<endl; 
                     }
                     
                     ret_flag = 0;
                     ret_fig_flag = 0;
                     ret_type = UNDEF;

                     if ($[stmt_block]){
                            semanticError("stop/advance cannot be outside the loop");
                     }

                     delete $ID;
                     delSymTabPtr();
              }
              |  FUNC VOID ID { insertType($3, Func, $2);  addSymTabPtr(); } '(' arg_list {if(paramslist.size()>0) {
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

                     if ($[stmt_block]){
                            semanticError("stop/advance cannot be outside the loop");
                     }

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

 
/* Figure Definition */
              
fig: FIG ID {insertType($ID, Fig, UNDEF); addSymTabPtr();}  '(' params ')' empty_space stmt_block { 
                                                        if (ret_fig_flag == 1)  
                                                               semanticError("Error: Return statement is not allowed in figures."); 
                                                        ret_fig_flag = 0;
                                                        

                                                        if ($[stmt_block])
                                                               semanticError("stop/advance cannot be outside the loop");

                                                        delSymTabPtr();
                                                        delete $ID;
                                                        } 

params : expression ',' expression { if(!(arithCompatible($1) && $3 == POINT)) semanticError("Error: Semantic error incompatible datatype..") ;}
       | SCALE EQUAL expression ',' CENTER EQUAL expression { if(!(arithCompatible($3) && $7 == POINT)) semanticError("Error: Semantic error incompatible datatype") ;}

 /* Statements */
stmt : cond_stmt {$$ = $1;}
     | loop     {$$ = false;}
     | decl_stmt {$$ = false;}
     | assign_stmt {$$ = false;}
     | return_stmt {$$ = false;}
     | ENDLINE    {$$ = false;}
     | stmt_block {$$ = $1;}
     | break_stmt {$$ = true;}
     ;

stmt_list: stmt_list stmt {$$ = $1 || $2;}
         |  /* empty */ {$$ = false;}
         ;

stmt_block: { addSymTabPtr(); } '{'  stmt_list '}' { $$ = $3; delSymTabPtr(); }
          ;

stmt_block_for: '{'  stmt_list '}' { $$ = $2; delSymTabPtr(); } // addSymTabPtr before for decl
          ;

break_stmt : BREAK ENDLINE 
           | CONTINUE ENDLINE 
           ;

       /* Return Statement */
return_stmt : RETURN ret_var ENDLINE {ret_type = $2; ret_flag = 1; ret_fig_flag = 1;};

ret_var : construct {$$ = $1;} | expression {$$ = $1;} | {$$ = Void;}; 

       /* Assignment Statement */
assign_stmt : expression ENDLINE {lineArrNo = 0;}
            | construct ENDLINE  {lineArrNo = 0;}
            /* | fig_call ENDLINE */
            ;

opt_exp: expression {$$ = $1;}
       | /* empty */ {$$ = UNDEF;}
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
}

construct :  constructor '(' construct_param_list ')' {$$ = $1; construct_params.clear(); } 
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
                  is_member = 0; 
              }
              else {
                     vector<int> dim;
                     params.push_back({$3,Var,dim});   
              }
          }
          | valid_arg {
              if(is_member) {
                     params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                     is_member = 0;
              }
              else {
                     vector<int> dim;
                     params.push_back({$1,Var,dim});   
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
                     construct_params.push_back({$3,Var,dim});   
              }
          }
          | valid_arg {
              if(is_member) {
                     construct_params.push_back({typelist.Eletype,typelist.Type,typelist.DimList});
                    is_member = 0;
                    
              }
              else {
                     vector<int> dim;
                     construct_params.push_back({$1,Var,dim});   
              }
          }
          ;

point : '(' expression ','  expression ',' STRING_TOKEN ')' {  $$ = pointCheck($2, $4); }
       |  '(' expression ','  expression  ')'  {  $$ = pointCheck($2, $4);}
       ; 

// NOT TESTED
vertex: member_access { if ($1 != POINT) semanticError("Error: vertex has to be a point");}
      /* | func_call { if ($1 != POINT) semanticError("Error: vertex has to be a point");} */
      | point 
      ;

angle : '<' vertex vertex vertex ',' BOOLEAN '>'  {$$ = ANGLE;}
       | '<' vertex vertex vertex '>' {$$ = ANGLE;}
       ;

expression:   expression '+' expression {$$ = sumTypeCheck($1, $3);}
            | expression '-' expression {$$ = diffTypeCheck($1, $3);} 
            | expression '*' expression {$$ = mulTypeCheck($1, $3);}
            | expression '/' expression {$$ = mulTypeCheck($1, $3);}
            | expression '%' expression {if ($1 != INT || $3 != INT) semanticError("Error: Semantic error incompatible datatype"); $$ = INT;}
            | expression '^' expression {$$ = mulTypeCheck($1, $3);}
            | expression LINE_OP expression {if(($1 == POINT || $1 == LINEARR) && $3 == POINT) {$$ = LINEARR; lineArrNo++;} else  semanticError("Error: Semantic error incompatible datatype");}  // <-> ->
            | expression PARALLEL expression {$$ = parallelCheck($1, $3);}
            | expression PERPENDICULAR expression  {$$ = perpendicularCheck($1, $3);}
            | PARALLEL inside_norm PARALLEL  {$$ = REAL;}
            | '-' expression %prec NEG {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; } 
            | UNARY member_access {if(!($2 == INT || $2 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;  }
            | member_access UNARY {if(!($1 == INT || $1 == REAL)) semanticError("Error: Semantic error incompatible datatype"); $$ = $1;  }
            | NOT expression {if (!arithCompatible($2)) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;}
            | expression AND expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | expression OR expression {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
            | member_access assign       {if (!(($1 == $2) || coercible($1, $2) || ($1 == LINE && $2 == LINEARR && lineArrNo == 1))) semanticError("Error: Semantic error incompatible datatype"); $$ = $1; }
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
            | func_call {$$ = $1;}
            | point {$$ = $1;}
            | angle {$$ = $1;}            
            ; 

inside_norm: inside_norm '+' vertex 
           | inside_norm '-' vertex 
           | vertex
           /* | memb_access assign   will := add in || ||  later*/
           ; // norm cannot be empty

assign:  EQUAL expression {$$ = $2;}
       | ASSIGN_OP  expression  {if(!(arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }  
       | SUM_ASSIGN_OP  expression  {if(!(arithCompatible($2) || $2 == LABEL || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2; }
       | SUB_ASSIGN_OP expression {if(!(arithCompatible($2) || $2 == POINT)) semanticError("Error: Semantic error incompatible datatype"); $$ = $2;}
       ;

       /* Declaration Statement */
decl_stmt : DATATYPE id_list ENDLINE {typeUpdate($2, $1);lineArrNo = 0;}
          | constructor id_list ENDLINE {typeUpdate($2, $1);lineArrNo = 0;}
          ;

id_list: id_list ',' ID check_arr EQUAL arr_assign_line {$$ = $1;$$->push_back($3);compareAndInsertArray($3, $4, $6.eletype, $6.dimList);}
       | id_list ',' ID check_arr  {$$ = $1;$$->push_back($3);insertArray($3, $4);}       
       | id_list ',' ID decl_assign {$$ = $1;$$->push_back($3);insertType($3, Var, $4);}
       | ID check_arr  {$$ = new vector<char*>;$$->push_back($1);insertArray($1, $2);}
       | ID check_arr EQUAL arr_assign_line {$$ = new vector<char*>;$$->push_back($1);compareAndInsertArray($1, $2, $4.eletype, $4.dimList);}
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

arr_assign_line : arr_assign {$$.dimList = $1.dimList;$$.eletype = $1.eletype;}
                | expression {
                            if ($1 != LINEARR) 
                                   semanticError("Error: Invalid Datatypes\n");
                            $$.dimList = new vector<int>;
                            $$.dimList->push_back(lineArrNo);
                            lineArrNo = 0;
                     }
                ;

arr_assign : '{'  arr1d_in_list '}' {$$.dimList = new vector<int>; $$.dimList->push_back($2.count); $$.eletype = $2.eletype;}
           | '{' comma_arr_assign '}' {$$.dimList = $2.dimList;$$.eletype = $2.eletype;}
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

arr_access: arr_access '[' expression ']' {$$ = $1; $$ = $$ + 1;} 
          | /* empty */ {$$ = 0;} 
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
                     $$ = UNDEF;
              }
              else {

                     argumentTypeChecking(func_paramlist, params);
                     params.clear();

                     $$ = $1;              
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

cond_stmt:  IF '(' expression ')' empty_space stmt_block ENDLINE {$$ = $6;if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' empty_space stmt_block ENDLINE  ELSE empty_space stmt_block ENDLINE {$$ = $6||$10;if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt ELSE empty_space stmt_block ENDLINE {$$ = $6||$8||$11;if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        |   IF '(' expression ')' empty_space stmt_block ENDLINE elif_stmt {$$ = $6||$8;if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
        ;

elif_stmt : ELIF '(' expression ')' empty_space stmt_block ENDLINE  {$$ = $[stmt_block];if(!(arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype");}
          | elif_stmt ELIF '(' expression ')' empty_space stmt_block ENDLINE {$$ = $1||$[stmt_block];if(!(arithCompatible($4))) semanticError("Error: Semantic error incompatible datatype");}
          ;


/* Loops */

loop : for_loop 
     | while_loop
     ;

for_loop_decl : { addSymTabPtr(); } DATATYPE ID EQUAL expression { insertType($ID, Var, $DATATYPE);delete $ID;}
              | { addSymTabPtr(); } ID EQUAL expression { delete $ID; }
              | { addSymTabPtr(); } 
              ;

optional_arg: expression  {$$ = $1;} 
            | /* empty */ {$$ = UNDEF;} 
            ;
            
for_loop : FOR '(' for_loop_decl '|' optional_arg '|' optional_arg ')' empty_space stmt_block_for {if(!(arithCompatible($5)) && $5 != UNDEF) semanticError("Error: Semantic error incompatible datatype11");}

while_loop : WHILE '(' expression ')' empty_space stmt_block 
           ;


%%

/* yacc error handler */
void yyerror(const char * s)
{   
    fprintf(stderr, "Error: Syntax error on line %d: %s at or near %s\n", yylineno, s, yytext);
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
