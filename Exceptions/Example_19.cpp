/* Order of the catch branches

The order of the catch branches matters yes and no. We’ll start from the “no” variant.*/
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
        // We’ve swapped two of the first catch branches. The program doesn't produce compilation errors.
        catch(overflow_error &ovf) {
            cout << "Overflow: " << ovf.what() << endl;
        }
        catch(out_of_range &ofr) {
            cout << "Out of range: " << ofr.what() << endl;
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