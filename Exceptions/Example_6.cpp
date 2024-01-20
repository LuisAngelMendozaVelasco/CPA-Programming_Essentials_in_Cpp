/////////////////////////////////
// Throw vs. function epilogue //
/////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        Class()
        { 
            cout << "Object constructed" << endl; 
        }

        ~Class()
        { 
            cout << "Object destructed" << endl; 
        }

        void hello()
        {
            cout << "Object says: hello" << endl; 
        }
};	

/* 
We’ve added three throw instructions within the do_calculations() function. Now we can precisely control (using a parameter value) which one will be executed. 
Note that the first is placed at the function beginning, before the object is created, the second in the middle and the third at the end of the function.
*/
void do_calculations(int i)
{
    /* 
    In the first case, no objects were created during the (broken) function execution, as the throw occurred before the line where the object is declared. 
    There is no trace of either constructor or destructor activity.
    */
    if(i == 0) 
        throw string("fatal 1");

    /* 
    In both remaining cases, both constructor and destructor proved to us that they worked, although the function didn’t reach its normal end.
    We can use throw without the fear that we may cause memory leaks.
    */
    Class object;

    if(i == 1)
        throw string("fatal 2");

    object.hello();
    
    if(i == 2)
        throw string("fatal 3");
}

// The main() function will invoke do_calculations() three times and we’ll be able to observe the function’s behaviour.
int main()
{
    for(int i = 0; i < 3; i++)
    {
        try {
            cout << "-------" << endl;	
            do_calculations(i);
        }
        catch (string &exc) {
            cout << exc << endl;
        }
    }	

    askOS();
    return 0;
}

/*
Output:

-------
fatal 1
-------
Object constructed
Object destructed
fatal 2
-------
Object constructed
Object says: hello
Object destructed
fatal 3
*/