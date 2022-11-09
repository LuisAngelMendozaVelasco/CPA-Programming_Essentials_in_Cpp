/* Sharing the responsibility

We’ve added a broker between the main() and the function(). The broker handles some of the passing exceptions, namely those compatible with the exception class. 
Now the handling process is dispersed over two levels: lower (inside broker) and upper (inside main).*/
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

/* Most of the exceptions have been handled by the broker and haven’t reached the main function.We can use this method when we want to divide the responsibility 
of handling different kinds of exceptions between different layers of the program logic.*/
void broker(int i)
{
    try { 
        function(i); 
    }
    catch(exception &ex) { 
        cout << "Broker - exception: " << ex.what() << endl; 
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