#include "symbol_table.hpp"
#include <map>
#include <deque>
#include <string>
#include <iostream> 
#include <bits/stdc++.h> 
#include <algorithm> 
#include <vector>

using namespace std;

deque< map<string, STentry> > SymTab;
vector< map<string,STentry> > ConstructTab;

extern int yylineno;
extern int lineArrNo;

/* 
* inserts into symbol table the name, type, eletype 
*/
void insertType(char* name, enum type t, enum eletype etype) {
    
    if (SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
        
    if (SymTab.back().find(name) != SymTab.back().end()) {
        cerr << "Error: " << "Redeclaration of " << name << endl;
        exit(1); // ERROR_RECOVERY
    }
    else {
        SymTab.back()[name].Type = t;
        SymTab.back()[name].Eletype = etype;      
    }  
    
}

void insertParams(vector<ParamList>& paramlist) {
    for(int i = 0;i < paramlist.size();i++) {
        insertType(const_cast<char*>(paramlist[i].name.data()), paramlist[i].Type, paramlist[i].Eletype);
        addDimList(const_cast<char*>(paramlist[i].name.data()), paramlist[i].dim);
    }
}

/*
* updates the eletype of name with etype
* if not found exits ERROR_RECOVERY
*/
void updateType(char* name, enum eletype etype) {
    
    if (SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    } 
        
    if (SymTab.back().find(name) == SymTab.back().end()) {
        cerr << "Error: " << "Not declared " << name << endl;
        exit(1); // ERROR_RECOVERY
    }
    else{
        SymTab.back()[name].Eletype = etype;      
    }  
    
}

STentry lookupConstructTab(char* name,enum eletype e) {
    if(e==UNDEF) {
        if(!strcmp(name,"COMMON_TANGENT") || !strcmp(name,"INTERSECTION_CIRCLE")) {
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

/* 
* searches the symbol table for name 
* returns the topmost entry found 
* if not found returns an STEntry with Type Invalid 
*/
STentry lookup(char *name) {

    for (int i = SymTab.size()-1;i >= 0;i--){

        if (SymTab[i].find(name) != SymTab[i].end()) {
            return SymTab[i][name];
        }
    }

    STentry stentry;
    stentry.Type = Invalid;
    return stentry;
}

/* 
* searches name in symbol table 
* if found returns Type as int
* otherwise returns -1 
*/ 
int checkType(char* name) {

    if (SymTab.empty()) {
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type != Invalid) {
        return lookup(name).Type;
    }
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }
}

/* 
* searches name in symbol table
* if found returns eletype as int 
* otherwise returns -1 
*/ 
int checkEletype(char* name) {
    
    if (SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type != Invalid) {
        return lookup(name).Eletype;
    }
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        return -1;
    }  
}

/*
* searches the symbol table by name
* if found returns a copy of the dimList associated with name
* otherwise returns a copy of an empty vector
*/
vector<int> checkDimList(char* name) {

    if (SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (lookup(name).Type != Invalid) {
        return lookup(name).DimList;
    }
    else{
        cerr << "Error: " << name << " not found in SymTab." << endl;
        vector<int> temp;
        return temp;
    }  
}

void addParamList(char* name, vector<ParamList>& paramlist) {
    if (SymTab.empty()){
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

/*
* inserts dimList for name in the current scope
* if found inserts the a copy of the reference in the symbol table, however if dimList has a negative value doesn't insert
* if not found reports error doesn't exit
*/
void addDimList(char* name, vector<int>& dim) {

    if (SymTab.empty()){
        SymTab.push_back(map<string,STentry>());
    }
    
    if (SymTab.back().find(name) != SymTab.back().end()) {
        
        for(int i = 0;i < dim.size();i++){
            if (dim[i] < 0)
            {   cerr<<"Array index cannot be negative"<<endl;
                return;
            }
        }

        SymTab.back()[name].DimList = dim; // ref destroy while removing ERROR_RECOVERY
    } 
    else {
        cerr << "Error: " << name << " not found in SymTab." << endl;
    }
}

/* 
* inserts a new scope on top of the symbol table 
*/
void addSymTabPtr() {
    SymTab.push_back(map<string,STentry>());
}

/*
* pops the topmost symbol table if it exists
*/
void delSymTabPtr() {
    if (!SymTab.empty()){
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

    for(int i = 0;i < 6;i++) {
        ConstructTab.push_back(map<string,STentry>());
    }
    
    /*POINT*/
    ConstructTab[0]["x"]={Var,REAL,{},{}};
    ConstructTab[0]["y"]={Var,REAL,{},{}};


    /*Line*/
    ConstructTab[1]["INTERSECTION"] = {Func,POINT,{{Var,LINE,"a",{}},{Var,LINE,"b",{}}},{}};
    ConstructTab[1]["MIDPOINT_LINE"] = {Func,POINT,{{Var,LINE,"l",{}}},{}};
    //ConstructTab[1]["MIDPOINT_POINTS"] = {Func,LINE,{{Var,POINT,"a",{}},{Var,POINT,"b",{}}},{}};
    ConstructTab[1]["SHORTEST_DISTANCE"] = {Func,REAL,{{Var,LINE,"a",{}},{Var,LINE,"b",{}}},{}};
    ConstructTab[1]["ANGLE_BISECTOR"] = {Func,LINE,{{Var,LINE,"a",{}},{Var,LINE,"b",{}}},{}};
    ConstructTab[1]["passesThrough"] = {Func,BOOL,{{Var,POINT,"a",{}}},{}};
    ConstructTab[1]["LINE_AT_ANGLE"] = {Func,LINE,{{Var,ANGLE,"ang",{}},{Var,LINE,"l",{}},{Var,POINT,"a",{}}},{}};

    /*Circle*/
    ConstructTab[2]["TANGENT"] = {Func,LINE,{{Var,POINT,"a",{}}},{}};
    ConstructTab[2]["INTERSECTION_CIRCLE"] = {Func,POINT,{{Var,CIRCLE,"c1",{}},{Var,CIRCLE,"c2",{}}},{}};
    ConstructTab[2]["COMMON_TANGENT"] = {Func,LINE,{{Var,CIRCLE,"c1",{}},{Var,CIRCLE,"c2",{}}},{}};
    ConstructTab[2]["AREA"] = {Func,REAL,{},{}};
    ConstructTab[2]["PERIMETER"]={Func,REAL,{},{}};

    /*Triangle*/
    ConstructTab[3]["CIRCUMCENTER"] = {Func,POINT,{},{}};
    ConstructTab[3]["EXCENTER"] = {Func,POINT,{{Var,POINT,"a",{}}},{}};
    ConstructTab[3]["INCENTER"] = {Func,POINT,{},{}};
    ConstructTab[3]["ORTHOCENTER"]={Func,POINT,{},{}};
    ConstructTab[3]["ALTITUDE"] = {Func,LINE,{{Var,POINT,"a",{}}},{}};
    ConstructTab[3]["MEDIAN"] = {Func,LINE,{{Var,POINT,"a",{}}},{}};
    ConstructTab[3]["CENTROID"] = {Func,POINT,{},{}};
    ConstructTab[3]["AREA"] = {Func,REAL,{},{}};
    ConstructTab[3]["PERIMETER"] = {Func,REAL,{},{}};

    /*Parallelogram*/
    ConstructTab[4]["DIAGONAL"]={Func,LINE,{},{}};
    ConstructTab[3]["AREA"] = {Func,REAL,{},{}};
    ConstructTab[3]["PERIMETER"] = {Func,REAL,{},{}};

    /*Regular Polygon*/
    ConstructTab[5]["AREA"]={Func,REAL,{},{}};
    ConstructTab[5]["PERIMETER"]={Func,REAL,{},{}};
}

/* 
prints s along with line no 
exits ERROR_RECOVERY
*/
void semanticError(const char* s){
       cerr << yylineno << ": "<< s << "\n";
       //exit(1);
}
  
/*
* Checks if E1, E2 can be added returns the eletype of the result
* POINT + POINT = POINT
* LABEL + LABEL = LABEL
* rest arithCompatible: BOOL < INT < ANGLE < REAL 
* Here, '<' shows casting order
*/
enum eletype sumTypeCheck(enum eletype E1, enum eletype E2){
       
       if (E1 == LABEL && E2 == LABEL)
              return LABEL;
       else if (E1 == POINT && E2 == POINT)
              return POINT;
       else if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
            semanticError("Error: Semantic error incompatible datatypes for +\n");
            exit(1); // ERROR_RECOVERY
       }
}

enum eletype arithTypeCheck(enum eletype E1, enum eletype E2  ){
       
       if((E1 == REAL || E1 == BOOL || E1 == INT) && (E2 == REAL || E2 == BOOL || E2 == INT) ){
              return max(E1, E2);
       }
       else {
            semanticError("Error: Semantic error incompatible datatypes\n");
            exit(1); // ERROR_RECOVERY
       }
}

/* 
* returns true if e is compatible with arithmetic operations 
* else returns false
* REAL, BOOL, INT, ANGLE are arithCompatible
*/
bool arithCompatible(int e){
       if (e == REAL || e == BOOL || e == INT || e == ANGLE) 
              return true;
       return false;
}

/* 
* Checks if x, y can be coordinates of a point
* retuns POINT eletype 
* x/y can be : INT, REAL
*/
enum eletype pointCheck (enum eletype x, enum eletype y){
       if ((arithCompatible(x) && arithCompatible(y)))
              return POINT;
       else {
              semanticError("Error: Semantic error invalid point \n");
              exit(1);
       }
}

/* 
* returns true if t1, t2 are interconvertible, 
* false otherwise 
* UNDEF can be converted to any type
*/
bool coercible(int t1, int t2){
       
       if (arithCompatible(t1) && arithCompatible(t2))
              return true;

       if (t1 == UNDEF || t2 == UNDEF)
              return true; // check where this function is used and make sure it doesn't cause problems
              //member_access funciton in expression makesure not passed up

       if (t1 == t2)
              return true;

       /* 
            POINT
            LABEL
            LINE
            CIRCLE
            TRI
            PARA
            REGPOLY cannot be interconverted
       */

       return false;      

}

/*
* v: is list of identifier names already stored in symbol table 
* prevType is the type with which the id was initialised (UNDEF if uninitialised)
*/
void typeUpdate(vector<char*>* v, enum eletype t){

       for (int i = 0;i < v->size();i++){

            int prevType = checkEletype(v->at(i));
              
              if (!coercible(prevType, t)){

                semanticError("Error: types don't match in declaration and initialisation\n");
              }
              
              updateType(v->at(i), t);
              
            
       } 

       return;
}

/*
* inserts name as Array along with its declation dimlist
* Type is set as UNDEF
*/
void insertArray(char* name, vector <int>* dimList){

    insertType(name, Array, UNDEF);
    addDimList(name, *dimList);
       
}

/*
* updates type of array name after checking if the decDimlist and assignDimlist are compatible
*/
void compareAndInsertArray(char* name, vector <int>* decDimList, enum eletype e, vector<int>* assignList){

       if (decDimList->size() != assignList->size()){

            // not freeing anything
            semanticError("Error: arrays declaration and initialization list don't match\n");
       }

       if ((*decDimList)[0] == -1)
             (*decDimList)[0] = (*assignList)[0];

       for (int i = 0;i < decDimList->size();i++){

              if ((*decDimList)[i] < (*assignList)[i]){
                    semanticError("Error: arrays declaration and initialization list don't match\n");
                    // not freeing anything
              }
       } 

       insertType(name, Array, e);
       addDimList(name, *decDimList);

       return;
}


void compareAndInsertLineArr(char* name, vector <int>* decDimList, int count){

    if (decDimList->size() != 1)
        semanticError("Error: arrays declaration and initialization list don't match :: linarr\n");
    
    if ((*decDimList)[0] == -1)
        (*decDimList)[0] = count;
    
    
    if ((*decDimList)[0] < count){
        semanticError("Error: arrays declaration and initialization list don't match\n");
                    // not freeing anything
    }

    insertType(name, Array, LINE);
    addDimList(name, *decDimList);

}


/*
* CHECK
*/
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

enum eletype parallelCheck(enum eletype E1, enum eletype E2){

    if (!(E1 == LINE)){
        semanticError("Error: Operands for || can be only bool or line");
        return BOOL; 
    }

    if (!(E2 == LINE)){
        semanticError("Error: Operands for || can be only bool or line");
        return BOOL; 
    }

    return BOOL;

}

enum eletype perpendicularCheck(enum eletype E1, enum eletype E2){

    if (E1 == LINE && E2 == LINE)
        return BOOL;
    else {
        semanticError("Error: Operands for |- has to be a line");
        return BOOL; //  so that error won't cascade
    }

}

/*
* CHANGE WITH LINEARR
*/
enum eletype diffTypeCheck(enum eletype E1, enum eletype E2){

       if (E1 == POINT && E2 == POINT){
            return LINE;
       }


       if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
              cerr << "Error: Semantic error incompatible datatypes\n";
              exit(1); // Change Later
       }
}

/*
* Checks if E1, E2 are compatible for multiplication 
* returns the type of the result
* only arithCompatible i.e BOOL < INT < ANGLE < REAL are valid
* Here: '<' shows type casting order
*/
enum eletype mulTypeCheck(enum eletype E1, enum eletype E2){

       if (arithCompatible(E1) && arithCompatible(E2)){
              return max(E1, E2);
       }
       else {
            semanticError("Error: Semantic error incompatible datatypes for * operator\n");
            exit(1); // ERROR_RECOVERY
       }
}

/*
* copies vector pointed by src to vector pointer to dest after inserting x as the first element
*/
void addFrontAndCopy(vector<int>* dest, vector<int>* src , int x){

       dest->push_back(x);

       for (int i = 0;i < src->size();i++)
              dest->push_back(src->at(i));
}

int checkDims(char* name,int count) {

       if (lookupConstructTab2(name).Type != Invalid) {
           return 0;
       }
       vector<int> dimlist (checkDimList(name)); 
       if (dimlist.size() < count) {
              cerr<<"Error: Dimension not matching"<<endl;
              return -1;
       }
       else {
              return count;
       }
}

STentry returnType(vector<cntAndType> dimsAndType) {
       STentry t;
       STentry s = lookup(dimsAndType[0].name);
       if(s.Type==Invalid) {
           STentry st = lookupConstructTab(dimsAndType[0].name,UNDEF);
           if(st.Type==Invalid) {
              cerr<<"Error: Identifier not found"<<endl;
              exit(1);
           }
           else {
              return st;  // Std Library function
           }   
       }
       else {
              t = s;
              vector<int> new_dimlist;
              for(int i = dimsAndType[0].count;i<t.DimList.size();i++) {
                     
                     new_dimlist.push_back(t.DimList[i]);
              }
              t.DimList = new_dimlist;
              for(int i = 1;i<dimsAndType.size();i++) {
                     if(dimsAndType[i-1].count > 0) {
                            cerr<<"Error: Array has no member attribute"<<endl;
                            exit(1);
                     }
                     else {
                        STentry st = lookupConstructTab(dimsAndType[i].name,t.Eletype);
                        if(st.Type!=Invalid) {
                            t = st;
                        }            
                     }         
              }

              return t;
       }
       
}

void argumentTypeChecking(vector<ParamList> &func_params,vector<types> &passed_params) {
       if(func_params.size() > passed_params.size()) {
              semanticError("Error: Too few arguments");
       }
       else if(func_params.size() < passed_params.size()) {
              semanticError("Error: Too many arguments");
       }
       else {
              for(int i = 0;i<func_params.size();i++) {
                     if(coercible(func_params[i].Eletype, passed_params[i].eletype)) {
                            bool isEqual = 0;
                            if(equal(func_params[i].dim.begin(),func_params[i].dim.end(),passed_params[i].dim.begin(),passed_params[i].dim.end())) {
                                   isEqual = 1;
                            }
                            if(!isEqual) {
                                   semanticError("Error: Array dimension is not matching for argument"); 
                            }  
                     }
                     else {
                            semanticError("Error: Type is not matching for argument");
                     }
              }
       }
}

void figArgumentChecking(vector<types>& passed_params) {
       if(passed_params.size()>2) {
            semanticError("Too many arguments");  
       }

       if(passed_params.size()==2) {
              if (!arithCompatible(passed_params[0].eletype) && passed_params[0].eletype != UNDEF){
              
                     semanticError("in fig call scale has to be a number type");
              }

              if (passed_params[1].eletype != POINT && passed_params[1].eletype != UNDEF){
                     //cout<<passed_params[1].eletype<<endl;
                     semanticError("in fig call center has to be a point type");

              }  
       }

       if(passed_params.size()==1) {
              if ((!arithCompatible(passed_params[0].eletype) && passed_params[0].eletype != UNDEF) || (passed_params[0].eletype != POINT && passed_params[0].eletype != UNDEF)){
                     semanticError("in fig call arguemnt can be scale or center");
              }  
       }
       
}

/* 
* prints the symbol table 
*/
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
            // case LINEARR:
                // cout << "ERROR!!!";
                // break;   
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
