/////////////////////////////////
// Throw vs. function epilogue //
/////////////////////////////////

/*
The functions executions consist, in general, of three phases: prologue (when all automatic variables/objects are created), 
execution (when the function code is performed) and epilogue (when the previously created entities are destructed).
We know that the function won’t return after the footsteps but, in some measure, will go for shortcuts, omitting normal completion.
All desired cleanings will be done, giving the program a chance to retrieve its normal operation in the nearest future.
This is a routine, clear code, without any throw instruction. It demonstrates how the epilogue may manifest its effects, 
although normally it works quietly without bothering anybody.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// A simple class in the code equipped with one constructor and one destructor. They do nothing except output short messages proving that the functions were invoked.
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

float do_calculations()
{
    Class object;

    object.hello();
    return 42.;
}

int main()
{
    cout << do_calculations() << endl;

    askOS();
    return 0;
}

/*
Output:

Object constructed
Object says: hello
Object destructed
42
*/