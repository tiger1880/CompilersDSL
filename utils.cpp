#include "symbol_table.hpp"
#include<map>
#include<deque>
#include<string>
#include <iostream> 
#include<bits/stdc++.h> 
#include<vector>

using namespace std;

deque<map<string, STentry>> SymTab;
vector<map<string,ConstructEntry> > ConstructTab;


// Define functions here
void insertType(char* name, enum type t ,enum eletype etype) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
        
    if(SymTab.back().find(name) != SymTab.back().end()) {
        cerr << "Error: " << "Redeclaration of " << name << endl;
        exit(1); // error recovery later
    }
    else{
        SymTab.back()[name].Type = t;
        SymTab.back()[name].Eletype = etype;      
    }  
    
}

void updateType(char* name, enum eletype etype) {
    
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    } //remove
        
    if(SymTab.back().find(name) == SymTab.back().end()) {
        cerr << "Error: " << "Not declared " << name << endl;
        exit(1); // error recovery later
    }
    else{
        SymTab.back()[name].Eletype = etype;      
    }  
    
}

STentry lookup(char *name) {
    for(int i = SymTab.size();i>=0;i--) {
        if(SymTab[i].find(name) != SymTab[i].end()) {
            return SymTab[i][name];
        }
    }
    STentry stentry;
    stentry.Type = Invalid;
    return stentry;
}

int checkType(char* name) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type!=Invalid) {
        return lookup(name).Type;
    }
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }
}

//check return type
int checkEletype(char* name) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type!=Invalid) {
        return lookup(name).Eletype;
    }
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }  
}


void addParamList(char* name, ParamList& param) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (SymTab.back().find(name) != SymTab.back().end()) {
        SymTab.back()[name].paramList.push_back(param);
    } 
    else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
    }
}

int sizeParamList(char* name) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type!=Invalid) {
        return lookup(name).paramList.size();
    }
    else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }    
}

void addDimList(char* name, vector<int>& dim) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (SymTab.back().find(name) != SymTab.back().end()) {
        
        for(int i=0;i<dim.size();i++){
            if(dim[i]<0)
            {   cerr<<"Array index cannot be negative";
                return;
            }
        }
        SymTab.back()[name].DimList = dim; //ref destroy while removing
    } 
    else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
    }
}

void addSymTabPtr() {
    SymTab.push_back(map<string,STentry>());
}

void delSymTabPtr() {
    if(!SymTab.empty()){
        SymTab.pop_back();
    }
    
}

bool funcParamSizeCheck(char *name, vector<ParamList> param) {
    if(sizeParamList(name)==param.size()){
        return true;
    }
    return false;
}

/* insert into constructors table */
/*example : c.TANGENT(q) , insertConstructTab(c,tangent,{point,q,{}})*/
void insertConstructTab(char* name,char* memberFunc,vector<ParamList> param) {
    if(!lookup(name)){
        cerr<<"Error: "<<name<<" not found in SymTab."<<endl;
        exit(1);
    }
    enum type t = lookup(name).Type;

    if(t==POINT){
        pointMembers(memberFunc,param);
    }
    else if(t==line){
        lineMembers(memberFunc,param);
    }
    else if(t==CIRCLE){
        circleMembers(memberFunc,param);
    }
    else if(t==TRI){
        triMembers(memberFunc,param);
    }
    else if(t==PARA){
        paraMembers(memberFunc,param);
    }
    else if(t==REGPOLY){
        regPolyMembers(memberFunc,param);
    }
    else{
        cerr<<"Error: Invalid type"<<endl;
        exit(1);
    }
    
}



//(TANGENT,{var,point,q,{}}) 
void circleMembers(char* memberFunc,vector<ParamList> param){
        if(memberFunc=="TANGENT"){
            //c.tangent(q) is a line
            //param: {type,eletype,name,vector<int>dim}= {var,POINT,q,{}}
            //point p := c.tangent(q)
            if(param.size()==1){
                //lookup for point of param
                if(lookup(param.name).Eletype==POINT){
                    ConstructTab[2][memberFunc].entry.Eletype = LINE;
                    ConstructTab[2][memberFunc].entry.Type = Var;
                    ConstructTab[2][memberFunc].entry.paramList = param;
                }else{
                    cerr<<"Error: Parameter passed to TANGENT is not a POINT"<<endl;
                    exit(1);
                }
            }else{
                cerr<<"Error: More than 1 parameter passed to TANGENT"<<endl;
                exit(1);
            }
        }
        else if(memberFunc=="INTESECTION"){
            //c.intersection(c1,c2) is a point array
            //param: {type,eletype,name,vector<int>dim}= {{Var,CIRCLE,c1,{}},{Var,CIRCLE,c2,{}}}
            //point l[] := INTERSECTION(c1,c2)
            //eletype = point , type = array 
            if(param.size()==2){
                //lookup for circles of param
                for(int i=0;i<2;i++){
                    if(lookup(param[i].name).Eletype!=CIRCLE){
                        cerr<<"Error: Parameter passed to INTERSECTION is not a CIRCLE"<<endl;
                        exit(1);
                    }
                }
                ConstructTab[2][memberFunc].entry.Eletype = POINT;
                ConstructTab[2][memberFunc].entry.Type = Array;
                ConstructTab[2][memberFunc].entry.paramList = param;
            }else{
                cerr<<"Error: More than 1 parameter passed to INTERSECTION"<<endl;
                exit(1);
            }
        }else if(memberFunc=="COMMON_TANGENT"){
            //c.common_tangent(c1,c2) is a line array
            //param: {type,eletype,name,vector<int>dim}= {{Var,CIRCLE,c1,{}},{Var,CIRCLE,c2,{}}}
            if(param.size()==2){
                //lookup for circles of param
                for(int i=0;i<2;i++){
                    if(lookup(param[i].name).Eletype!=CIRCLE){
                        cerr<<"Error: Parameter passed to COMMON_TANGENT is not a CIRCLE"<<endl;
                        exit(1);
                    }
                }
                ConstructTab[2][memberFunc].entry.Eletype = LINE;
                ConstructTab[2][memberFunc].entry.Type = Array;
                ConstructTab[2][memberFunc].entry.paramList = param;
            }else{
                cerr<<"Error: More than 2 parameter passed to COMMON_TANGENT"<<endl;
                exit(1);
            }
        }
}


void printSymbolTable() {
    cout << "Symbol Table:" << endl;
    for (const auto& entry : SymTab.back()) {
        const STentry& stEntry = entry.second;
        cout << "Name: " << entry.first << endl;
        cout << "Type: ";
        switch (stEntry.Type) {
            case Array:
                cout << "Array";
                break;
            case Func:
                cout << "Function";
                break;
            case Fig:
                cout << "Figure";
                break;
            case Var:
                cout << "Variable";
                break;
        }    
        cout << endl;
        cout << "Element Type: ";
        switch (stEntry.Eletype) {
            case Void:
                cout << "Void";
                break;
            case INT:
                cout << "INT";
                break;
            case REAL:
                cout << "REAL";
                break;
            case POINT:
                cout << "POINT";
                break;
            case LABEL:
                cout << "LABEL";
                break;
            case BOOL:
                cout << "BOOL";
                break;
            case ANGLE:
                cout << "ANGLE";
                break;
            case LINE:
                cout << "LINE";
                break;
            case CIRCLE:
                cout << "CIRCLE";
                break;
            case TRI:
                cout << "TRI";
                break;
            case PARA:
                cout << "PARA";
                break;
            case REGPOLY:
                cout << "REGPOLY";
                break;
        }
        cout << endl;
        
        cout << "Parameter List:" << endl;
        for (const ParamList& param : stEntry.paramList) {
            cout << "  Parameter Type: ";
            switch (param.Type) {
                case Array:
                    cout << "Array";
                    break;
                case Func:
                    cout << "Function";
                    break;
                case Fig:
                    cout << "Figure";
                    break;
                case Var:
                    cout << "Variable";
                    break;
            }
            cout << ", Name: " << param.name << ", Dimensions: ";
            for (int dim : param.dim) {
                cout << dim << " ";
            }
            cout << endl;
        }

        cout << "Dimension List:" << endl;
        for (int dim : stEntry.DimList) {
            cout << dim << " ";
        }
        cout << endl;

        cout << "-------------------------" << endl;
    }
}



