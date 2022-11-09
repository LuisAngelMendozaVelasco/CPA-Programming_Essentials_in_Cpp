/* Proper handling of the bad_exception exception requires the function to specify bad_exception on its throw list (it looks like a paradox but it’s true), 
and the unexpected handler function must be defined and set. Failure to meet any of these conditions will result in undesired program behaviour.*/
#include <iostream>
#include <exception>
#include "../myFunctions.h"

using namespace std;

// Note the empty throw statement inside the unexp function. This form doesn’t mean that the function throws nothing – on the contrary, it means that the exception received by the function is re-thrown.
void unexp()
{
    cout << "Unexpected exception arrived!" << endl;
    throw;
}

void function() throw(int, bad_exception) 
{
    throw 3.14; 
}

int main()
{
    set_unexpected(unexp);
    try {
        function();
    } 
    catch(double f) {
        cout << "Got double" << endl;	
    } 
    catch(bad_exception bad) {
        cout << "It's so bad..." << endl;
    }
    cout << "Done" << endl;

    askOS();
    return 0;
}