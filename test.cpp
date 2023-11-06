#include <iostream>
using namespace std;

int main(){

    if (-0.0)
        cout << "hello" << "\n";
    
    cout << "world" << "\n";
    bool x=2.3;
    x++;
   cout<<x;
   return 0;
}
// {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
//             {if(!(arithCompatible($1) && arithCompatible($3))) semanticError("Error: Semantic error incompatible datatype"); $$ = BOOL;  }
// // {if(!(arithCompatible($2))) semanticError("Error: Semantic error incompatible datatype");   }