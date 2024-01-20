//////////////////
// Memory leaks //
//////////////////

/*
In real programming many of the objects are allocated memory that they need for their operation. This memory should be released 
when the object finishes its activity and the best way to do this is to do the cleaning automatically. Failure to clean the memory 
will cause a phenomenon named "memory leaking", where the unused (but still allocated!) memory grows in size, affecting system performance.
We can also provoke memory leaking intentionally.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        // Constructor, which is responsible for allocating memory of the size specified by its parameter value. 
        Class(int val) 
        { 
            value = new int[val]; 
            cout << "Allocation (" << val << ") done." << endl;
        }
        
        int *value;
};

// The object of this class is created as a local variable.
void make_a_leak() 
{
    Class object(1000);
}

/* 
We can imagine that object creation consists of two phases:
    1. The object itself is created and a part of the memory is implicitly allocated to the object.
    2. The constructor explicitly allocates another part of the memory.
The object variable is an example of an “automatic variable”. This means that the variable automatically finishes 
its life when the execution of the function containing the variable’s declaration ends.
*/
int main() 
{

    /* 
    We may want that returning from make_a_leak() will implicitly free all memory allocated to the object, 
    but (unfortunately), the memory explicitly allocated by the constructor remains allocated. To make matters worse, 
    we’ve also lost the only pointer that held the address of that memory (it was stored by the value field, 
    but the object containing this field doesn’t exist anymore).
    */
    make_a_leak();

    askOS();
    return 0; 
}

/*
Output:

Allocation (1000) done.
*/