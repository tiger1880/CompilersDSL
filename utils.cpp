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

void insertParams(vector<ParamList>& paramlist) {
    for(int i = 0;i<paramlist.size();i++) {
        insertType(const_cast<char*>(paramlist[i].name.data()),paramlist[i].Type,paramlist[i].Eletype);
        addDimList(const_cast<char*>(paramlist[i].name.data()),paramlist[i].dim);
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

STentry lookupConstructTab(char* name,enum eletype e) {
    if(e==UNDEF) {
        if(!strcpy(name,"COMMON_TANGENT") || !strcpy(name,"INTERSECTION_CIRCLE")) {
            e = CIRCLE;
        }
        else {
            e = LINE;
        }
    }

    int index;

    if(e==POINT) {
        index = 0;
    }
    else if(e==LINE) {
        index = 1;
    }
    else if(e==CIRCLE) {
        index = 2;
    }
    else if(e==TRI) {
        index = 3;
    }
    else if(e==PARA) {
        index = 4;
    }
    else if(e==REGPOLY) {
        index = 5;
    }
    else {
        STentry stentry;
        stentry.Type = Invalid;
        return stentry; 
    }

    
    if(ConstructTab[index].find(name) != ConstructTab[index].end()) {
        return ConstructTab[index][name];
    }
    
    STentry stentry;
    stentry.Type = Invalid;
    return stentry;


}

STentry lookupConstructTab2(char* name) {
    if(lookupConstructTab(name,UNDEF).Type!=Invalid) {
       return lookupConstructTab(name,UNDEF); 
    }
    else if(lookupConstructTab(name,POINT).Type!=Invalid) {
        return lookupConstructTab(name,POINT);
    }
    else if(lookupConstructTab(name,LINE).Type!=Invalid) {
        return lookupConstructTab(name,LINE);
    }
    else if(lookupConstructTab(name,CIRCLE).Type!=Invalid) {
        return lookupConstructTab(name,CIRCLE);
    }
    else if(lookupConstructTab(name,TRI).Type!=Invalid) {
        return lookupConstructTab(name,TRI);
    }
    else if(lookupConstructTab(name,PARA).Type!=Invalid) {
        return lookupConstructTab(name,PARA);
    }
    else if(lookupConstructTab(name,REGPOLY).Type!=Invalid) {
        return lookupConstructTab(name,REGPOLY);
    }
    else {
        STentry stentry;
        stentry.Type = Invalid;
        return stentry;
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


vector<int> checkDimList(char* name) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type!=Invalid) {
        return lookup(name).DimList;
    }
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        vector<int> temp;
        return temp;
    }  
}


void addParamList(char* name, vector<ParamList>& paramlist) {
    if(SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (SymTab.at(SymTab.size()-2).find(name) != SymTab.at(SymTab.size()-2).end()) {
        SymTab.at(SymTab.size()-2)[name].paramList = paramlist;
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
    for(int i=0;i<6;i++) {
        ConstructTab.push_back(map<string,STentry>());
    }
    
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
    ConstructTab[2]["INTERSECTION_CIRCLE"] = {Array,POINT,{{Var,CIRCLE,"c1",{}},{Var,CIRCLE,"c2",{}}},{}};
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

void semanticError(const char* s){
       cerr << s << "\n";
       exit(1);
}
  
enum eletype sumTypeCheck(enum eletype E1, enum eletype E2  ){
       
       if(E1 == LABEL && E2 == LABEL)
              return LABEL;
       else if(E1 == POINT && E2 == POINT)
              return POINT;
       else if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes+\n";
              exit(1);
       }
}

enum eletype arithTypeCheck(enum eletype E1, enum eletype E2  ){
       
       if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1);
       }
}

// check int change 
bool arithCompatible(int e){

       if (e == REAL || e == BOOL || e == INT || e == ANGLE) 
              return true;
       return false;
}

enum eletype pointCheck (enum eletype x, enum eletype y){
       if ((x == INT || x == REAL) && (y == INT || y == REAL ))
              return POINT;
       else {
              cerr << "Error: Semantic error invalid point \n";
              exit(1);
       }
}

bool coercible(int t1, int t2){
       
       if (arithCompatible(t1) && arithCompatible(t2))
              return true;

       if (t1 == UNDEF || t2 == UNDEF)
              return true; // check where this function is used and make sure it doesn't cause problems

       if (t1 == t2)
              return true;

       /* 
              POINT
              LABEL
              LINE
              CIRCLE
              TRI
              PARA
              REGPOLY 
       */

       return false;      

}

void typeUpdate(vector<char*>* v, enum eletype t){

       for (int i = 0;i < v->size();i++){

              int prevType = checkEletype(v->at(i));
              
              
              if (!coercible(prevType, t))
              {
                     cerr << "Error: " << "types don't match in declaration and initialisation\n";
                     exit(1);
                     // error recovery
              }
              
              updateType(v->at(i), t);
              
              free(v->at(i));
       }

       delete v;

       printSymbolTable();

       return;
}

void insertArray(char* name, vector <int>* dimList){

       insertType(name, Array, UNDEF);
       addDimList(name, *dimList);
       
}

void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList){

       if (decDimList->size() != assignList->size()){

              cerr << "Error: arrays declaration and initialization list don't match\n";
              exit(1); // not freeing anything
       }

       if ((*decDimList)[0] == -1)
             (*decDimList)[0] = (*assignList)[0];

       for (int i = 0;i < decDimList->size();i++){

              if ((*decDimList)[i] < (*assignList)[i]){
                     cerr << "Error: arrays declaration and initialization list don't match\n";
                     exit(1); // not freeing anything
              }
       } 

       insertType(name, Array, e);
       addDimList(name, *decDimList);

       return;
}

void updateMaxDim(vector<int>* comma, vector<int>* assign){

       if (comma->size() != assign->size()+1){

              cerr << "Error: invaid array initializer list\n";
              exit(1); // remove this only if added length checks in declarations O/W segfault 
       }

       for (int i = 0;i < assign->size();i++){

              (*comma)[i+1] = max((*comma)[i+1], (*assign)[i]);
       }

       (*comma)[0] = (*comma)[0] + 1;

       return;
}

/*  eletype can be TRI, CIRCLE, LINE .. as well from identifiers */

enum eletype diffTypeCheck(enum eletype E1, enum eletype E2){

       if (E1 == POINT && E2 == POINT)
              return POINT;
       else if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1); // Change Later
       }
}

enum eletype mulTypeCheck(enum eletype E1, enum eletype E2){

       if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1); // Change Later
       }
}

void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x){

       dest->push_back(x);

       for (int i = 0;i < src->size();i++)
              dest->push_back(src->at(i));
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





