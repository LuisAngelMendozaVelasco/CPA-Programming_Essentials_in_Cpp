// We’ve changed the catch header and added the “exception &ex” instead of the ellipsis.

#include <iostream>
#include "../myFunctions.h"
using namespace std;

void function(int i)
{
    switch(i) {
        // All exceptions (excluding the last one, which is just a class exception) thrown by a function are derived from the exception class and thus are compatible in type.
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        case 3: throw exception();
    }
}

int main()
{
    for(int i = 0; i < 4; i++) {
        try {
            function(i);
        }
        /* 
        The branch is allowed to catch all exceptions whose objects are compatible in type with the exceptions class.
        We can identify an object, name it locally (as ex) and make use of its properties and/or functions. 
        We invoke the what function to find out what the object wants to say about itself.
        */
        catch(exception &ex) {
            cout << "Exception caught: " << ex.what() << endl;
        }
    }

    askOS();
    return 0;
}

/*
Output:

Exception caught: 0
Exception caught: 1
Exception caught: 2
Exception caught: std::exception
*/