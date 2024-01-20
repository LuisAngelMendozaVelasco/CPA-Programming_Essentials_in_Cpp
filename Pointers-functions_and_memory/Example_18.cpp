//////////////////////
// Inline functions //
//////////////////////

/*
The tactic of compiling function invocations is called function inlining. 
A function compiled like this is called an inline function.
It doesn't matter whether the inline keyword is placed before or after the 
name of the type; both of the following lines are syntactically correct:
    * inline int function(int parameter)
    * int inline function(int parameter)
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

inline int function(int parameter) // Inline function
{
    return parameter * 2;
}

int main()
{
    int var = 1;

    var = function(var);
    var = function(var);
    var = function(var);
    cout << "var: " << var << endl;
    
    askOS();
    return 0;
}

/*
Output:

var: 8
*/