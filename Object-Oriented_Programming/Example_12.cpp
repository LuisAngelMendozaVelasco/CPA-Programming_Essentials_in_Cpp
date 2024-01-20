////////////////////////////
// Static class variables //
////////////////////////////

/*
It’s not only class variables that can be declared as static – functions can be declared like this, too.
The program displays a program containing a class with two static components: a variable and a function.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
	static int Counter;

    public:
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

        /* 
        The static function, like a static variable, may also be accessed (or more precisely, invoked) when no instances of the class have been created.
        Note that the static function may be invoked from inside the class, like this:
            HowMany();
        or by using any of the existing instances, like this:
            b.HowMany();
        */
        static void HowMany() 
        { 
            cout << Counter << " instances" << endl; 
        }
};

int Class::Counter = 0;

int main()
{
    Class::HowMany();

    Class a;
    Class b;

    b.HowMany();

    Class c;
    Class d;

    d.HowMany();

    askOS();
    return 0; 
}

/*
Output:

0 instances
2 instances
4 instances
Bye, bye!
*/