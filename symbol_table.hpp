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
       REAL,
       POINT,
       LABEL,
       ANGLE,
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


extern deque<map<string,STentry> > SymTab;

/* 0-Point  1-Line  2-Circle  3-Triangle 4-para 5-regPoly */
extern vector<map<string,STentry> > ConstructTab;

extern void insertType(char* name,enum type t, enum eletype etype);
extern void printSymbolTable();
extern int checkType(char* name);
extern int checkEletype(char* name);
extern void addParamList(char* name, ParamList param);
extern int sizeParamList(char* name);
extern void addDimList(char* name, vector<int>& dim);
extern void addSymTabPtr();
extern void delSymTabPtr();
extern STentry lookup(char* name);
extern bool funcParamSizeCheck(char *name, vector<ParamList> param);
extern void updateType(char* name, enum eletype etype);
extern void insertConstructTab();


#endif // UTILS_HPP


