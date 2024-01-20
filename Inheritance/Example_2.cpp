////////////////////////////
// Protected access level //
////////////////////////////

/*
The keyword protected means that any component marked with it behaves like a public component when used by any 
of the subclasses and looks like a private component to the rest of the world.
We should add that this is true only for publicly inherited classes.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Super {
    protected:
        int storage;

    public:
        void put(int val)
        { 
            storage = val; 
        }

        int get() 
        { 
            return storage; 
    }
};

// The print function accesses the storage variable from the Superclass. This wouldn’t be possible if the variable was declared as private.
class Sub : public Super {
    public:
        void print() 
        { 
            cout << "storage = " << storage << endl; 
        }
};

// In the main function scope, the storage variable remains hidden anyway.
int main() 
{
    Sub object;

    object.put(100);
    object.put(object.get() + 1);
    object.print();

    askOS();
    return 0; 
}

/*
Output:

storage = 101
*/