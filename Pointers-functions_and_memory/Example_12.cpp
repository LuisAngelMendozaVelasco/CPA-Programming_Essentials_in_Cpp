/////////////////////////////////////
// Passing by reference limitation //
/////////////////////////////////////

/*
A function can’t place a value in something other than a variable. It cannot assign a new value to a literal, or force an expression to change its result. 
All the following invocations are permitted:
    by_val(var);
    by_val(var + 2);
    by_val(var * fun(1));
If you want to modify the invocations to take advantage of the by_ref() function, you can only use the first one. All the others will cause a compilation error.*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

/*
An argument referring to a “passed by value” parameter may be an expression in general, 
so we can use not only a variable but also a literal, or even a function invocation's result.
*/
void by_val(int parameter)
{
    parameter++;
}

/* 
If a parameter is declared as passed by reference (so it is preceded by the & sign) 
its corresponding argument must be a variable.
*/
void by_ref(int& parameter)
{
    parameter++;
}

int main()
{
    int var = 1;

    by_val(var);
    cout << "var = " << var << endl;

    by_ref(var);
    cout << "var = " << var << endl;

    askOS();
    return 0;
}

/*
Output:

var = 1
var = 2
*/