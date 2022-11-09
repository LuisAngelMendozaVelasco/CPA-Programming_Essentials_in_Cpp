/* We can selectively choose the exceptions we want to catch and handle carefully, and those that we want to handle very briefly.
The code mixes the two previous approaches: some of the exceptions are caught individually while others go to the ellipsis.
There’s one important condition: the ellipsis branch, if it exists, must be the last specified branch. Otherwise, the compiler will produce an error.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        case 3: throw exception();
        case 4: throw "so bad";
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            function(i);
        }
        catch(out_of_range &ofr) {
            cout << "Out of range: " << ofr.what() << endl;
        }
        catch(overflow_error &ovf) {
            cout << "Overflow: " << ovf.what() << endl;
        }
        catch(domain_error &dmn) {
            cout << "Domain: " << dmn.what() << endl;
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