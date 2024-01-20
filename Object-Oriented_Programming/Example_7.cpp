/////////////////////////
// Automatic variables //
/////////////////////////

/*
All the variables in the code belong to one of two categories. They are:
    * Automatic variables, created and destroyed, sometimes repeatedly, and automatically (hence their name) during program execution.
    * Static variables, existing continuously during the whole program execution.
"C++" programming language assumes that all variables are automatic by default unless they are declared explicitly as static. 
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

void fun() 
{
    /* 
    The var variable is created each time the fun function is invoked and is destroyed each time the function completes its execution. 
    We can say that creation and deletion of the variable is automated.
    */
    int var = 99;

    cout << "var = " << ++var << endl;
}

int main() 
{
    // The function will always produce the same output.
    for(int i = 0; i < 5; i++)
        fun();

    askOS();
    return 0; 
}

/*
Output:

var = 100
var = 100
var = 100
var = 100
var = 100
*/