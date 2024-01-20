//////////////////////
// Memory on demand //
//////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    /*
    We declare a variable called arr which will point to the data of type float (the pointer's type is float *); no value is initially assigned to this variable.
    We use the "new" keyword to allocate a block of memory sufficient to store a float array consisting of 5 elements.
    */
    float *arr = new float[5];

    for (int i = 0; i < 5; i++) {
        arr[i] = i * i;
        cout << arr[i] << endl;
    }

    // We make use of the newly allocated array (to be precise, a vector) and next we release it using the delete keyword.
    delete[] arr;

    askOS();
    return 0;
}

/*
Output:

0
1
4
9
16
*/