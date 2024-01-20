///////////////////////////////
// Selecting the constructor //
///////////////////////////////

/*
If a class has more than one constructor, one of them may be chosen during object creation. This is done by specifying the form of the parameter 
list associated with the class name. The list should be unambiguously compatible with one of the available class constructors.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// There are already two constructors.
class Class {
    public:
        Class()
        { 
            cout << "Object constructed (#1)" << endl; 
        }

        Class(int value) 
        { 
            this -> value = value; 
            cout << "Object constructed (#2)" << endl; 
        }

        ~Class()
        { 
            cout << "Object destructed! val = " << value << endl; 
        }

        void inc_and_print()
        {
            cout << "value = " << ++value << endl;
        }

        int value;
};

/* 
We’ve created two new objects inside the main functions. They differ in the constructor used to build each of the objects. 
In effect, their value fields have different values assigned to them.
*/
int main()
{
    Class *ptr1 = new Class, *ptr2 = new Class(2);

    ptr1 -> value = 1;
    ptr1 -> inc_and_print();
    ptr2 -> inc_and_print();

    delete ptr2;
    delete ptr1;

    askOS();
    return 0; 
}

/*
Output:

Object constructed (#1)
Object constructed (#2)
value = 2
value = 3
Object destructed! val = 3
Object destructed! val = 2
*/