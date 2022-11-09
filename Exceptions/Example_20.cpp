/* Order of the catch branches

We’ve swapped the first and the fourth catch branches. The program’s behaviour changes.
We should expect that the compiler is going to produce some warning messages. It won’t prevent our program from being successfully compiled, but the warnings suggest that not everything has gone 
as we would have liked.*/
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
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
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
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }


    askOS();
    return 0;
}