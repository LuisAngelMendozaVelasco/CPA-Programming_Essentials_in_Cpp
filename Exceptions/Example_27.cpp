/* 
A badly constructed broker may ruin the exception handling logic at higher levels. 
The broker’s decided to take control over all arriving exceptions. None of them will leave the broker. 
We can say that “everything that comes to the broker stays in the broker”.
*/

#include <iostream> 
#include "../myFunctions.h"
using namespace std;

void function(int i) {
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
        cout << "Broker swept problems under the carpet" << endl;
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

/*
Output:

Broker swept problems under the carpet
Broker swept problems under the carpet
Broker swept problems under the carpet
Broker swept problems under the carpet
Broker swept problems under the carpet
*/