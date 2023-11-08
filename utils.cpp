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
/*example : c.TANGENT(q) , insertConstructTab(c,TANGENT,{POINT}) 
:: take types from parser */
void insertConstructTab(char* name,char* memberFunc,vector<eletype> paramEletype) {  
    enum eletype t;

    /* point p := MIDPOINT(l) , no name for line*/
    if(name==""){
        t = LINE:
    }else if(lookup(name).Type != Invalid){
        t = lookup(name).eletype;
    }else{
        cerr<<"Error: "<<name<<" not found in SymTab."<<endl;
        exit(1);
    }

    if(t==LINE){
        lineMembers(memberFunc,paramEletype);
    }
    else if(t==CIRCLE){
        circleMembers(memberFunc,paramEletype);
    }
    else if(t==TRI){
        triMembers(memberFunc,paramEletype);
    }
    else if(t==PARA){
        paraMembers(memberFunc,paramEletype);
    }
    else if(t==REGPOLY){
        regPolyMembers(memberFunc,paramEletypes);
    }
    else{
        cerr<<"Error: Invalid type for constructTable"<<endl;
        exit(1);
    } 
}

void lineMembers(char* memberFunc,vector<eletype> paramEletype){
    if(memberFunc=="INTERSECTION"){
        if(paramEletype.size()==2){
            //lookup for lines of param
            for(int i=0;i<2;i++){
                if(param[i]!=LINE){
                    cerr<<"Error: Parameter passed to INTERSECTION is not a LINE"<<endl;
                    exit(1);
                }
            }
            ConstructTab[0][memberFunc].entry.Eletype = POINT;
            ConstructTab[0][memberFunc].entry.Type = Var;
            for(int i=0;i<2;i++){
                    ConstructTab[1][memberFunc].entry.paramList[i].Eletype.push_back(paramEletype[i]);
            }
        }else{
            cerr<<"Error: More than 2 parameter passed to INTERSECTION of lines"<<endl;
            exit(1);
        }
    }
    else if(memberFunc=="MIDPOINT"){
        if(paramEletype.size()==1){
            /*point p := MIDPOINT(l)*/
            if(param[0]==LINE){
                //insert  STentry entry
                ConstructTab[0][memberFunc].entry.Eletype = POINT;
                ConstructTab[0][memberFunc].entry.Type = Var;
                ConstructTab[0][memberFunc].entry.paramList[0].push_back(paramEletype[0]);
            }else{
                cerr<<"Error: Parameter passed to MIDPOINT(one parameter) is not a LINE"<<endl;
                exit(1);        
            }
        }
        else if(paramEletype.size()==2){
            /*point p := MIDPOINT(l1,l2)*/
            if(param[0]==POINT && param[1]==POINT){
                //insert  STentry entry
                ConstructTab[0][memberFunc].entry.Eletype = POINT;
                ConstructTab[0][memberFunc].entry.Type = Var;
                for(int i=0;i<2;i++){
                    ConstructTab[0][memberFunc].entry.paramList[i].push_back(paramEletype[i]);
                }
            }else{
                cerr<<"Error: Parameters passed to MIDPOINT(two parameter) are not points "<<endl;
                exit(1);        
            }
        }
        else{
            cerr<<"Error: More than 2 parameter passed to MIDPOINT of LINE"<<endl;
            exit(1);
        }
    }
    else if(memberFunc=="SHORTEST_DISTANCE"){
        if(paramEletype.size()==2){
            /*real dist := SHORTEST_DISTANCE(a,b)*/
            if(param[0]==POINT && param[1]==POINT){
                //insert  STentry entry
                ConstructTab[0][memberFunc].entry.Eletype = REAL;
                ConstructTab[0][memberFunc].entry.Type = Var;
                for(int i=0;i<2;i++){
                    ConstructTab[0][memberFunc].entry.paramList[i].push_back(paramEletype[i]);
                }
            }else{
                cerr<<"Error: Parameters passed to SHORTEST_DISTANCE are not points "<<endl;
                exit(1);        
            }
        }else{
            cerr<<"Error: More than 2 parameter passed to SHORTEST_DISTANCE between 2 points"<<endl;
            exit(1);
        }
    }
    else if(memberFunc=="ANGLE_BISECTOR"){
        if(paramEletype.size()==2){
            /* line p := ANGLE_BISECTOR(a,b) */
            if(param[0]==LINE && param[1]==LINE){
                //insert  STentry entry
                ConstructTab[0][memberFunc].entry.Eletype = LINE;
                ConstructTab[0][memberFunc].entry.Type = Var;
                for(int i=0;i<2;i++){
                    ConstructTab[0][memberFunc].entry.paramList[i].push_back(paramEletype[i]);
                }
            }else{
                cerr<<"Error: Parameters passed to ANGLE_BISECTOR are not lines "<<endl;
                exit(1);        
            }
        }else{
            cerr<<"Error: More than 2 parameter passed to ANGLE_BISECTOR of lines"<<endl;
            exit(1);
        }
    }
    else if(memberFunc=="LINE_AT_ANGLE"){
        if(paramEletype.size()==3){
           /* line p := LINE_AT_ANGLE(40,a,q) */
           if(param[0]==ANGLE && param[1]==LINE && param[2]==POINT){
                ConstructTab[0][memberFunc].entry.Eletype = LINE;
                ConstructTab[0][memberFunc].entry.Type = Var;
                for(int i=0;i<3;i++){
                    ConstructTab[0][memberFunc].entry.paramList[i].push_back(paramEletype[i]);
                }
           }else{
                cerr<<"Error: Invlaid Parameters passed to LINE_AT_ANGLE , format(angle,line,point )"<<endl;
                exit(1);        
           }
        }else{
            cerr<<"Error: More than 3 parameter passed to LINE_AT_ANGLE"<<endl;
            exit(1);
        }
    }else{
        cerr<<"Error: Invalid member function of LINE"<<endl;
        exit(1);
    }
}

void circleMembers(char* memberFunc,vector<eletype> paramEletype){
        if(memberFunc=="TANGENT"){
            //c.tangent(q) is a line
            //(TANGENT,POINT) 
            //param: {eletype}= {POINT}
            //point p := c.tangent(q)
            if(paramEletype.size()==1){
                //lookup for point of param
                if(param[0]==POINT){
                    //insert  STentry entry
                    ConstructTab[1][memberFunc].entry.Eletype = LINE;
                    ConstructTab[1][memberFunc].entry.Type = Var;
                    ConstructTab[1][memberFunc].entry.paramList[0].push_back(paramEletype[0]);
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
            //param:  {CIRCLE,CIRCLE}
            //point l[] := INTERSECTION(c1,c2)
            //eletype = point , type = array 
            if(paramEletype.size()==2){
                //lookup for circles of param
                for(int i=0;i<2;i++){
                    if(param[i]!=CIRCLE){
                        cerr<<"Error: Parameter passed to INTERSECTION is not a CIRCLE"<<endl;
                        exit(1);
                    }
                }
                ConstructTab[1][memberFunc].entry.Eletype = POINT;
                ConstructTab[1][memberFunc].entry.Type = Array;
                for(int i=0;i<2;i++){
                    ConstructTab[1][memberFunc].entry.paramList[i].Eletype.push_back(paramEletype[i]);
                }
            }else{
                cerr<<"Error: More than 1 parameter passed to INTERSECTION"<<endl;
                exit(1);
            }
        }else if(memberFunc=="COMMON_TANGENT"){
            //c.common_tangent(c1,c2) is a line array
            //param: {CIRCLE,CIRCLE}
            if(paramEletype.size()==2){
                //lookup for circles of param
                for(int i=0;i<2;i++){
                    if(paramEletype[i]!=CIRCLE){
                        cerr<<"Error: Parameter passed to COMMON_TANGENT is not a CIRCLE"<<endl;
                        exit(1);
                    }
                }
                ConstructTab[1][memberFunc].entry.Eletype = LINE;
                ConstructTab[1][memberFunc].entry.Type = Array;
                for(int i=0;i<2;i++){
                    ConstructTab[1][memberFunc].entry.paramList[i].Eletype.push_back(paramEletype[i]);
                }
            }else{
                cerr<<"Error: More than 2 parameter passed to COMMON_TANGENT"<<endl;
                exit(1);
            }
        }
        else{
            cerr<<"Error: Invalid member function of CIRCLE"<<endl;
            exit(1);
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



