#ifndef UTILS_HPP
#define UTILS_HPP

// Data structures file

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
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
       struct STentry *STptr;
} STentry;        


extern map<string,STentry> SymTab;

#endif // UTILS_HPP


