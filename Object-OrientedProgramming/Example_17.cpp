/* Pointers to fields

All the variables, including objects, brought to life in the “ordinary” way (by declaration, not by the use of the new keyword) 
live in a separate area of memory called the stack. It’s a memory region dedicated to storing all automatic entities.
Try to imagine the stack as a living creature whose size varies during the execution of the program. The stack grows when new automatic 
variables are created and shrinks when the variables are no longer needed.
The entities created “on demand” (by the new keyword) are created in a specific memory region usually called a heap. 
In contrary to the stack, the heap is almost fully under our control. We decide how many variables, arrays, objects, etc. 
will occupy the heap and it’s up to us when these entities end their lives.
The object being stored in the heap must be accessed in a way that resembles the access to the dynamically allocated structures. 
You mustn’t use the ordinary “dotted” notation as there’s no structure (object) which can play the role of the left argument of the "." operator 
unless you dereference the pointer. You need to use the “arrow” (->) operator instead.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* We’ve added one field to the Class. It’s declared in the public part of the class so we can access it freely from outside the class.
The static entities accessed at the class level using the :: operator behave as usual.*/ 
class Class {
public:
    Class()
    {
        cout << "Object constructed!" << endl;
    }

    ~Class()
    {
        cout << "Object destructed!" << endl;
    }

    int value;
};

int main()
{
    Class *ptr = new Class;

    // There’s one catch – we have to use the “->” operator.
    ptr -> value = 0;
    cout << "++(ptr -> value) = " << ++(ptr -> value) << endl;
    delete ptr;

    askOS();
    return 0; 
}