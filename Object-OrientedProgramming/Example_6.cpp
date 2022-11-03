/* Destructors

Destructors have the following restrictions:
* if a class is named X, its destructor is named ~X
* a class can have no more than one destructor
* a destructor must be a parameter-less function (note that the two last restrictions are the same – can you explain why?)
* a destructor shouldn’t be invoked explicitly*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Class {
public:
    Class(int val) 
    { 
        value = new int[val]; 
        cout << "Allocation (" << val << ") done." << endl; 
    }
    // The destructor frees the memory allocated to the value field, protecting us from memory leaking.
    ~Class() 
    {
        delete [] value;
        cout << "Deletion done.";
    }
    int *value;
};

void make_a_leak() 
{
    Class object(1000);
}

int main() 
{
    make_a_leak();

    askOS();
    return 0; 
}