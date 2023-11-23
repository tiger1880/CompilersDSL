#ifndef UTILS_HPP
#define UTILS_HPP

/* Declarations  for the Symbol Table */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <map>

using namespace std;


enum type {
       Array,
       Func,
       Fig,
       Var,
       Invalid // used in case an entry in not found in symbol table
}; // array, func, fig, var

enum eletype {
       BOOL,
       INT,
       ANGLE,
       REAL, // dont change order -> sumTypeCheck, mulTypeCheck
       POINT,
       LABEL,
       Void,
       LINE,
       LINEARR,
       CIRCLE,
       TRI,
       PARA,
       REGPOLY,
       UNDEF // make sure doesn't cause prob
}; // int, float, ...

typedef struct ParamList{
       enum type Type;
       enum eletype Eletype; // added eletype
       string name;
       vector<int> dim;
} ParamList;

typedef struct STentry {
       enum type Type;
       enum eletype Eletype;
       vector<ParamList> paramList;
       vector<int> DimList;
} STentry;   

typedef struct cntAndType {
       int count;
       char* name;
} cntAndType;

typedef struct types {
       enum eletype eletype;  
       enum type type;
       vector<int> dim;
} types;

/* Symbol Table */
extern deque< map <string, STentry> > SymTab;

/* 0-Point  1-Line  2-Circle  3-Triangle 4-para 5-regPoly */
extern vector< map< string, STentry> > ConstructTab;


extern void insertType(char* name, enum type t, enum eletype etype); /* inserts into symbol table the name, type, eletype */ // on redeclaration exits => ERROR_RECOVERY
extern void insertParams(vector<ParamList>& paramlist); 
extern void printSymbolTable(); /* prints the symbol table */
extern int checkType(char* name); /* searches name in symbol table, if found returns Type otherwise returns -1 */ 
extern int checkEletype(char* name); /* searches name in symbol table, if found returns eletype otherwise returns -1 */ 
extern vector<int> checkDimList(char* name); /* searches the symbol table by name, if found returns a copy of the dimList associated with name, otherwise returns a copy of an empty vector */
extern void addParamList(char* name, vector<ParamList>& paramlist);
extern int sizeParamList(char* name);
extern void addDimList(char* name, vector<int>& dim); /* inserts a copy of dim with name in symbol table ERROR_RECOVERY */
extern void addSymTabPtr(); /* inserts a new scope on top of the symbol table */
extern void delSymTabPtr(); /* pops the topmost symbol table */
extern STentry lookup(char* name); /* searches the symbol table for name returns the topmost entry found, if not found returns an STEntry with Type Invalid */
extern STentry lookupConstructTab(char* name,enum eletype e);
extern STentry lookupConstructTab2(char* name);
extern bool funcParamSizeCheck(char *name, vector<ParamList> param);
extern void updateType(char* name, enum eletype etype); /* updates the eletype of name with etype, if not found exits ERROR_RECOVERY */
extern void insertConstructTab();

extern void semanticError(const char* s);  /* prints s along with line no, exits ERROR_RECOVERY */

extern enum eletype sumTypeCheck(enum eletype E1, enum eletype E2); /* Checks if E1, E2 can be added returns the eletype of the result */
extern enum eletype diffTypeCheck(enum eletype E1, enum eletype E2); /* CHANGE LINEARR */
extern enum eletype mulTypeCheck(enum eletype E1, enum eletype E2);  /* Checks if E1, E2 can be multiplied returns the eletype of the result */
extern enum eletype arithTypeCheck(enum eletype E1, enum eletype E2); // CHECK WHERE WHERE IT IS CALLED, INCLUDE ANGLE ?
extern enum eletype pointCheck (enum eletype x, enum eletype y); /* Checks if x, y can be coordinates of a point, retuns POINT eletype INCLUDE BOOL, ANGLE ? ryt now only INT, REAL*/
extern enum eletype parallelCheck(enum eletype E1, enum eletype E2); // CHANGE AFTER TRANSLATION
extern enum eletype perpendicularCheck(enum eletype E1, enum eletype E2);  // CHANGE AFTER TRANSLATION

extern bool arithCompatible(int e); /* returns true if e (eletype taken as int) is compatible with arithmetic operations else returns false */

extern bool coercible(int t1, int t2); /* returns true if t1, t2 are interconvertible, false otherwise CHECK WHERE CALLED*/
extern void typeUpdate(vector<char*>* v, enum eletype t); /* v:list of identifiers are updated with type t after checking if the initialization type is coercible */
extern void insert(char* name, vector<int>* dim, enum eletype t); // WHERE IS THIS DEFINED ?
extern void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x); /* copies vector pointed by src to vector pointer to dest after inserting x as the first element */
extern void updateMaxDim(vector<int>* comma, vector<int>* assign); // for now have to be equal // CHECK
extern void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList); /* updates type of array name after checking if the decDimlist and assignDimlist are compatible */
extern void insertArray(char* name, vector <int>* dimList); /* inserts name as Array along with its declation dimlist */

extern int checkDims(char* name,int count);
extern STentry returnType(vector<cntAndType> dimsAndType);
extern void argumentTypeChecking(vector<ParamList> &func_params, vector<types> &passed_params);
extern void figArgumentChecking(vector<types>& passed_params);


#endif 


