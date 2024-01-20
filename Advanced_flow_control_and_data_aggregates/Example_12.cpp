///////////////////////////////////////
// Vectors old-fashioned declaration //
///////////////////////////////////////

/*
There is no simple way to determine number of vector's elements - the size() 
method does not exist and cannot be invoked 
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    /* 
    Tricks that can be used instead is to determine whole vector's size and 
    to divide it by single element's size.
    */
    int elements = 10;
    int vect[elements];
    int current_size = sizeof(vect) / sizeof(vect[0]);

    cout << "Vector size: " << current_size << endl;

    askOS();
    return 0;
}

/*
Output:

Vector size: 10
*/