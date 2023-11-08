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


//structs for constructors
typedef struct ConstructEntry {
       // char* name;
       char* memberFunc;
       STentry entry;
} ConstructEntry;


extern deque<map<string,STentry> > SymTab;

/*  0-Line  1-Circle 2-Triangle 3-para 4-regPoly */
extern vector<map<string,ConstructEntry> > ConstructTab;

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
extern void insertConstructTab(char* name, char* memberFunc, vector<eletype> param);
extern void circleMembers(char* memberFunc,vector<eletype> paramEletype)
extern void lineMembers(char* memberFunc,vector<eletype> paramEletype);

#endif // UTILS_HPP


