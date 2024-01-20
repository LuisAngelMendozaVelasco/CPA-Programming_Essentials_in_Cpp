///////////////////////////////
// Throw and catch separated //
///////////////////////////////

/*
The throw and the catch may live separately as well. We can put throw in one function, catch in another, and the mechanism will still work effectively, but of course, 
only when the functions invoke themselves in the proper order.
This means that the exception object is able to fly above the function’s boundaries and can even skip over more than one function in order to find its own catch.
Throw will stay in its home do_calculation() function, while catch will move to the main function. When the throw statement is executed inside the function, 
the function won’t be able to return any useful value. This isn’t a problem as the function isn’t going return to the place where the result may be used 
in any meaningful way. The link between the function and the invocation is irretrievably broken when the throw processing starts.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

float do_calculations(float a, float b, float c, float d)
{
    float x = 1.;

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

int main()
{
    try {
        do_calculations(1, 2, 3, 0);
    } 
    catch(string &exc) {
        cout << "Something bad happened: " << exc << endl;
    }

    askOS();
    return 0;
}

/*
Output:

Something bad happened: Bad arg d
*/