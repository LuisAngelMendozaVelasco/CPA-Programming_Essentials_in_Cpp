/* Different catches for different purposes

The catch instruction is supposed to “catch” events passing through the instruction’s scope. We also know that the catch “catches” only these exceptions that are compatible in type with the catch header. 
For example, the following instruction:
    catch(string excp) {  }
catches exceptions encapsulated inside objects of type string, and ignores all others.
There’s a specialized form of the catch that’s able to catch literally all passing exceptions – it looks like:
    catch(...) { … }
but in contrast to the previous form, it can neither identify the exception object, nor make any use of it. Therefore, it’s intended for some very general actions, such as final cleanings, 
rather than for the subtle and finesse handling of a well-recognized problem.
If a try block contains more than one catch branch, then at most one of them may be executed. An exception caught by one of the branches leaves the try block and any of its other catches won’t be bothered.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
    }
}

int main()
{
    for(int i = 0; i < 3; i++) {
        try {
            function(i);
        }
        // The “...” tri-graph is known as an ellipsis
        catch(...) {
            cout << "Exception caught!" << endl;
        }
    }

    askOS();
    return 0;
}