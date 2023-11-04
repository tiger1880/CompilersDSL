#include "symbol_table.hpp"
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string, STentry> SymTab;

// Define functions here
void insertType(char* name, enum type t,enum eletype etype) {
    cout<<"insertType: "<<endl;
    SymTab[name].Type = t;
    SymTab[name].Eletype = etype;
}


int checkType(char* name) {
    return SymTab[name].Type;
}

//check return type
int checkEletype(char* name) {
    return SymTab[name].Eletype;
}


void addParamList(char* name, ParamList& param) {
   if (SymTab.find(name) != SymTab.end()) {
        SymTab[name].paramList.push_back(param);
    } else {
        std::cerr << "Error: " << name << " not found in SymTab." << std::endl;
    }
}

int sizeParamList(char* name) {
    if (SymTab.find(name) == SymTab.end()) {
        std::cerr << "Error: " << name << " not found in SymTab." << std::endl;
    }
    return SymTab[name].paramList.size();
}

void addDimList(char* name, vector<int>& dim) {
     if (SymTab.find(name) != SymTab.end()) {
        SymTab[name].DimList = dim;
    } else {
        std::cerr << "Error: " << name << " not found in SymTab." << std::endl;
    }
}


void printSymbolTable() {
    cout << "Symbol Table:" << endl;
    for (const auto& entry : SymTab) {
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



