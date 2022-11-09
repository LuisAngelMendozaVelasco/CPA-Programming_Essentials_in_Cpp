/* The responsibility of handling exceptions may not only be divided – it may be shared, too. This means that the handling of the same exceptions may be provided at more than one level.
Note that any of the catch branches might throw an exception too, and the exception won’t be handled in the place where it was created, but at a higher level.
The broker tries to catch all the exceptions (and succeeds!), but immediately re-throws all of them using the argument-less throw instruction.
This is the only possible way of re-throwing an exception in the ellipsis branch where the caught exception is completely anonymous and therefore imperceptible.
This form may be used in other kinds of catches, but there are no obstacles to using less anonymous variants, like this one:
    catch(exception &ex) {
        throw ex;
    }
We can throw another (new) exception instead of throwing the received exception. This might be a good idea when we want to change the category of the exception.
Here’s an example:
    catch(logic_error &err) {
        throw "We have a problem";
    }*/
#include <iostream> 
#include "../myFunctions.h"

using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

void broker(int i)
{
    try {
        function(i);
    }
    catch(...) {
        cout << "Broker swept problems under the carpet " << endl;
        throw;
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            broker(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error &re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    askOS();
    return 0;
}