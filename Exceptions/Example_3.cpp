//////////////////////////////////////
// Throw and catch coupled together //
//////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// The do_calculations() function contains four “sensible” fragments where an error may occur: they’re connected to divisions which may go wrong sometimes.
float do_calculations(float a, float b, float c, float d)
{
    try {
        float x = 1.;

        /* 
        All these divisions are “protected” by appropriate checks and in case of a wrong argument, an exception is thrown. The exception is “packed” in a box of 
        type string and carries a simple message describing the problem.
        */
		if(a == 0.0)
			throw string("Bad arg a");
		x /= a;

		if(b == 0.0)
			throw string("Bad arg b");
		x /= b;

		if(c == 0.0)
			throw string("Bad arg c");
		x /= c;

		if(d == 0.0)
			throw string("Bad arg d");
        return x / d;
    } 
    /* 
    There’s also one catch branch designed to catch the exception and provide very simple handling. The exception specification placed in the catch branch header
    works like a local (automatic) variable declaration. 
    */
    catch(string &exc) {
        cout << "Something bad happened: " << exc << endl;
        return 0.0;
    }
}

int main()
{
    do_calculations(1, 2, 3, 0);

    askOS();
    return 0;
}

/*
Output:

Something bad happened: Bad arg d
*/