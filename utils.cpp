#include "symbol_table.hpp"
#include<map>
#include<deque>
#include<string>
#include <iostream> 
#include<bits/stdc++.h> 
#include<vector>

using namespace std;

deque<map<string, STentry>> SymTab;




// Define functions here
void insertType(char* name, enum type t ,enum eletype etype) {
    cout<<"inserting "<<name<<endl;

    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
        
    if(SymTab.back().find(name) != SymTab.back().end()) {
        cerr << "Error: " << "Redeclaration of " << name << endl;
    }else{
        SymTab.back()[name].Type = t;
        SymTab.back()[name].Eletype = etype;      
    }  
    
}

int checkType(char* name) {
    if(SymTab.back().find(name) != SymTab.back().end())
        return SymTab.back()[name].Type;
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }
}

//check return type
int checkEletype(char* name) {
    if(SymTab.back().find(name) != SymTab.back().end())
        return SymTab.back()[name].Eletype;
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }  
}



void addParamList(char* name, ParamList& param) {
    if (SymTab.back().find(name) != SymTab.back().end()) {
        SymTab.back()[name].paramList.push_back(param);
    } else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
    }
}

int sizeParamList(char* name) {
    if (SymTab.back().find(name) != SymTab.back().end()) {
        return SymTab.back()[name].paramList.size();
    }
    else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }    
}

void addDimList(char* name, vector<int>& dim) {
     if (SymTab.back().find(name) != SymTab.back().end()) {
        
        for(int i=0;i<dim.size();i++){
            if(dim[i]<0)
            {   cerr<<"Array index cannot be negative";
                return;
            }
        }
        SymTab.back()[name].DimList = dim;
    } else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
    }
}

void addSymTabPtr() {
    SymTab.push_back(map<string,STentry>());
}

void delSymTabPtr() {
    SymTab.pop_back(map<string,STentry>());
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



