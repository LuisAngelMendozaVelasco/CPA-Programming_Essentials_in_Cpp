/* Static class variables

There are no obstacles to making a particular variable private and static at the same time. This will obviously prevent direct access to the variable, 
but it may be something we want if we want to protect the value against any unauthorized modification.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Class {
	static int Counter;
public:
    Class() { 
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

/* Note that any attempts to access the Counter variable expressed like this:
    Class::Counter = 1;
are strictly prohibited. */
int Class::Counter = 0;

int main()
{
    Class a;
    Class b;

    b.HowMany();

    Class c;
    Class d;

    d.HowMany();

    askOS();
    return 0; 
}