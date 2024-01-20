////////////////////////////
// Static class variables //
////////////////////////////

/*
The unique traits of the static class variables predestine them to be used as counters of instances of a particular class. 
The Counter field is accessed directly when it’s being used inside the class and with the "::" operator when it’s being used outside the class. 
It’s also possible to access the static variable through any of the existing class instances, like this:
    cout << b.Counter ;
as long as the accessed variable is publicly available.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        /* 
        First, we equip the Class class with the static field Counter. The Counter variable is defined outside the class and assigned 
        a value of zero to show that none of the class’s instances exist so far.
        */
        static int Counter;

        // We’ll increment the Counter inside the Class constructor and decrement it inside the Class destructor.
        Class() 
        { 
            ++Counter; 
        };

        ~Class() 
        { 
            --Counter; 
            if(Counter == 0) 
                cout << "Bye, bye!" << endl; 
        };

        void HowMany() 
        { 
            cout << Counter << " instances" << endl; 
        }
};

int Class::Counter = 0;

int main() 
{
    Class a;
    Class b;

    cout << Class::Counter << " instances so far" << endl;

    Class c;
    Class d;

    d.HowMany();

    askOS();
    return 0; 
}

/*
Output:

2 instances so far
4 instances
Bye, bye!
*/