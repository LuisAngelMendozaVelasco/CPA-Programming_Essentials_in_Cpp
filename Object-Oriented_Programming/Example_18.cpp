///////////////////////////
// Pointers to functions //
///////////////////////////

/*
Member functions invoked for an object accessed through the pointer have to be accessed using the arrow operator, too.
We’ve added a member function to our class.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

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

        void inc_and_print()
        {
            cout << "value = " << ++value << endl;
        }

        int value;
};	

int main()
{
    Class *ptr = new Class;

    ptr -> value = 1;
    ptr -> inc_and_print();
    delete ptr;

    askOS();
    return 0; 
}

/*
Output:

Object constructed!
value = 2
Object destructed!
*/