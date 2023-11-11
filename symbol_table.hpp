#ifndef UTILS_HPP
#define UTILS_HPP

// Data structures file

#include <stdio.h>
#include <stdlib.h>
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
       Invalid
}; //array,func,fig,var

enum eletype {
       BOOL,
       INT,
       ANGLE,
       REAL, // dont change order -> sumTypeCheck dependent
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
}; //int,float,...

typedef struct ParamList{
       enum type Type;
       enum eletype Eletype; //added eletype
       string name;
       vector<int> dim;
} ParamList;

// //function entry
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

extern deque<map<string,STentry> > SymTab;

/* 0-Point  1-Line  2-Circle  3-Triangle 4-para 5-regPoly */
extern vector<map<string,STentry> > ConstructTab;

extern void insertType(char* name,enum type t, enum eletype etype);
extern void insertParams(vector<ParamList>& paramlist);
extern void printSymbolTable();
extern int checkType(char* name);
extern int checkEletype(char* name);
extern vector<int> checkDimList(char* name);
extern void addParamList(char* name, vector<ParamList>& paramlist);
extern int sizeParamList(char* name);
extern void addDimList(char* name, vector<int>& dim);
extern void addSymTabPtr();
extern void delSymTabPtr();
extern STentry lookup(char* name);
extern STentry lookupConstructTab(char* name,enum eletype e);
extern STentry lookupConstructTab2(char* name);
extern bool funcParamSizeCheck(char *name, vector<ParamList> param);
extern void updateType(char* name, enum eletype etype);
extern void insertConstructTab();

extern void semanticError(const char* s);

extern enum eletype sumTypeCheck(enum eletype E1, enum eletype E2);
extern enum eletype diffTypeCheck(enum eletype E1, enum eletype E2);
extern enum eletype mulTypeCheck(enum eletype E1, enum eletype E2);
extern enum eletype arithTypeCheck(enum eletype E1, enum eletype E2);
extern enum eletype pointCheck (enum eletype x, enum eletype y);
extern enum eletype parallelCheck(enum eletype E1, enum eletype E2);
extern enum eletype perpendicularCheck(enum eletype E1, enum eletype E2);

extern bool arithCompatible(int e);

extern bool coercible(int t1, int t2);
extern void typeUpdate(vector<char*>* v, enum eletype t);
extern void insert(char* name, vector<int>* dim, enum eletype t);
extern void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x);
extern void updateMaxDim(vector<int>* comma, vector<int>* assign); // for now have to be equal
extern void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList);
extern void insertArray(char* name, vector <int>* dimList);

extern int checkDims(char* name,int count);
extern STentry returnType(vector<cntAndType> dimsAndType);
extern void argumentTypeChecking(vector<ParamList> &func_params,vector<types> &passed_params);


#endif // UTILS_HPP


