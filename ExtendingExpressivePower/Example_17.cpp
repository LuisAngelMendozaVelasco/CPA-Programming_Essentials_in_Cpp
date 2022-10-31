/* Anatomy of a function invocation

Each function's code has to be supplemented with two important elements: a prologue and an epilogue.
A "prologue" is the part of the code implicitly executed before the function. The prologue is responsible for 
transferring arguments from the invoker's code and for storing them in a special transient area called a “stack”.
The "epilogue" is implicitly executed just after the function's code and is responsible for transferring the 
result of the function and for clearing the stack of the values placed there by the prologue.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int function(int parameter)
{
    return parameter * 2;
}

int main() 
{
    int var = 1;
    var = function(var);
    var = function(var);
    var = function(var);
    cout << "var: " << var;

    askOS();
    return 0;
}