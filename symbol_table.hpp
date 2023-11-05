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
       Var
}; //array,func,fig,var

enum eletype {
       Void,
       INT,
       REAL,
       POINT,
       LABEL,
       BOOL,
       ANGLE,
       LINE,
       CIRCLE,
       TRI,
       PARA,
       REGPOLY
}; //int,float,...

typedef struct ParamList{
       enum type Type;
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

extern void insertType(char* name,enum type t, enum eletype etype);
extern void printSymbolTable();
extern int checkType(char* name);
extern int checkEletype(char* name);
extern void addParamList(char* name, ParamList param);
extern int sizeParamList(char* name);
extern void addDimList(char* name, vector<int> dim);
extern void addSymTabPtr();
extern void delSymTabPtr();



#endif // UTILS_HPP


