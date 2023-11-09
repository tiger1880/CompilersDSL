#include "symbol_table.hpp"
#include<map>
#include<deque>
#include<string>
#include <iostream> 
#include<bits/stdc++.h> 
#include<vector>

using namespace std;

deque<map<string, STentry>> SymTab;
vector<map<string,STentry> > ConstructTab;




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

void insertConstructTab() {
    ConstructTab.resize(6);
    /*POINT*/
    ConstructTab[0]["x"]={Var,REAL,{},{}};
    ConstructTab[0]["y"]={Var,REAL,{},{}};


    /*Line*/
    ConstructTab[1]["INTERSECTION"] = {Var,POINT,{{Var,POINT,"a",{}},{Var,POINT,"b",{}}},{}};
    ConstructTab[1]["MIDPOINT_LINE"] = {Var,POINT,{{Var,LINE,"l",{}}},{}};
    ConstructTab[1]["MIDPOINT_POINTS"] = {Var,LINE,{{Var,POINT,"a",{}},{Var,POINT,"b",{}}},{}};
    ConstructTab[1]["SHORTEST_DISTNACE"] = {Var,REAL,{{Var,POINT,"a",{}},{Var,POINT,"b",{}}},{}};
    ConstructTab[1]["ANGLE_BISECTOR"] = {Var,LINE,{{Var,LINE,"a",{}},{Var,POINT,"b",{}}},{}};
    ConstructTab[1]["LINE_AT_ANGLE"] = {Var,LINE,{{Var,ANGLE,"ang",{}},{Var,LINE,"l",{}},{Var,POINT,"a",{}}},{}};

    /*Circle*/
    ConstructTab[2]["TANGENT"] = {Var,LINE,{{Var,POINT,"a",{}}},{}};
    ConstructTab[2]["INTERSECTION"] = {Array,POINT,{{Var,CIRCLE,"c1",{}},{Var,CIRCLE,"c2",{}}},{}};
    ConstructTab[2]["COMMON_TANGENT"] = {Array,LINE,{{Var,CIRCLE,"c1",{}},{Var,CIRCLE,"c2",{}}},{}};
    ConstructTab[2]["AREA"] = {Var,REAL,{},{}};
    ConstructTab[2]["PERIMETER"]={Var,REAL,{},{}};

    /*Triangle*/
    ConstructTab[3]["CIRCUMCENTRE"] = {Var,POINT,{},{}};
    ConstructTab[3]["EXCENTRE"] = {Var,POINT,{},{}};
    ConstructTab[3]["INCENTRE"] = {Var,POINT,{{Var,POINT,"a",{}}},{}};
    ConstructTab[3]["ORTHOCENTRE"]={Var,POINT,{},{}};
    ConstructTab[3]["ALTITUDE"] = {Var,LINE,{{Var,POINT,"a",{}}},{}};
    ConstructTab[3]["MEDIAN"] = {Var,LINE,{{Var,POINT,"a",{}}},{}};
    ConstructTab[3]["CENTROID"] = {Var,POINT,{},{}};
    ConstructTab[3]["AREA"] = {Var,REAL,{},{}};
    ConstructTab[3]["PERIMETER"] = {Var,REAL,{},{}};

    /*Parallelogram*/
    ConstructTab[4]["DIAGONAL"]={Array,LINE,{},{}};

    /*Regular Polygon*/
    ConstructTab[5]["AREA"]={Var,REAL,{},{}};
    ConstructTab[5]["PERIMETER"]={Var,REAL,{},{}};
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
            case LINEARR:
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





