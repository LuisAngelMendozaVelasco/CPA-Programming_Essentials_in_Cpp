/////////////////////////////////
// Passing parameters by value //
/////////////////////////////////

/*
It is possible to utilize “passing by value” and be able to propagate the  value outside the function despite the one-way nature of this method.
The idea is based on transferring a pointer to a value, not the value itself. 
If you declare a function with a prototype like this one:
    void by_ptr(int* ptr);
you enable the function to deal with the addresses pointing to int values, and therefore you give the function the chance to modify the values pointed to by the parameter.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// It's an old “passing by value” method! 
void by_ptr(int* ptr) 
{
    // If p is a pointer to a value, the *p represents the value itself.
    *ptr = *ptr + 1;
}

int main() 
{
    int variable = 1;
    int *pointer = &variable;

    by_ptr(pointer);
    cout << "variable = " << variable << endl;

    askOS();
    return 0;
}

/*
Output:

variable = 2
*/