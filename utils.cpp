#include "symbol_table.hpp"
#include<map>
#include<string>
#include<vector>

using namespace std;

map<string, STentry> SymTab;

// Define functions here

void insertType(char* name, enum type t,enum eletype etype) {
    SymTab[name].Type = t;
    SymTab[name].Eletype = etype;
}



