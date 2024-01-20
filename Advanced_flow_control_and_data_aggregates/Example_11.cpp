/////////////
// Vectors //
/////////////

/*
The power of the modern vectors (compared to old-style solutions) lies in the fact that 
they are equipped with a numerous methods what makes them elastic and flexible.
*/

#include <iostream>
#include <vector>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int elements = 10;
    vector<int> vect(elements); // Vector declaration
    int current_size = vect.size(); // Vectors have a method named size which provides you with current size of the subject vector.

    cout << "Vector size: " << current_size << endl;

    askOS();
    return 0;
}

/*
Output:

Vector size: 10
*/