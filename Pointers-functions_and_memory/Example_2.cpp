//////////////////////////
// Pointers and vectors //
//////////////////////////

/*
The declaration of pointers follows this syntax:
    type * name;
where type is the data type pointed to by the pointer. This type is not the type of the pointer itself, 
but the type of the data the pointer points to.
*/

#include <iostream>
#include <vector>
#include "../myFunctions.h"
using namespace std;

int main() 
{
	vector<int> vect {1, 2, 3}; // Three-element vector of type int.

    // Store information about the location of the data.
	int *ptr = vect.data(); // Return a pointer (initially set to a value associated with a very first element of the vector!).
	int *ptr2 = &vect[0]; // Store the address into the pointer.
    
    cout << "ptr: " << ptr << endl;
    cout << "ptr2: " << ptr2 << endl;
	cout << "(ptr == prt2): " << (bool)(ptr == ptr2) << endl; // ptr and ptr2 point to the same location inside memory - the first vector's element.

    askOS();
    return 0;
}

/*
Output:

ptr: 0x55cb87a772b0
ptr2: 0x55cb87a772b0
(ptr == prt2): 1
*/