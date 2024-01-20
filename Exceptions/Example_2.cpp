////////////////////////////////////
// How are exceptions not caught? //
////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

float div(float a, float b)
{
    if(b == 0.0)
        throw string("division by zero :(");
    return a/b;
}

int main() {
    float a, b;

    cout << "a: ";

    // On Windows, ctrl-Z tells the terminal application that you're at the end of your input. On Unix systems, it's ctrl-D.
    while(cin >> a) {
        try {
            cout << "b: ";
            cin >> b;
            cout << div(a, b) << endl << endl;
        } 
        /* 
        We’ve changed the type specification in the catch statement (it was: string &, now it’s int)
        When the second value is zero, the program will be aborted with a message saying that an instance of an unhandled exception has been thrown.
        */
        catch (int problem) {
            cout << "Look what you did, you bad user!" << endl;
            cout << problem << endl;
        }

        cout << "a: ";
    }
    cout << "\nThe End" << endl;

    askOS();
    return 0;
}

/*
Output:

a: 1
b: 2
0.5

a: 1
b: 0
terminate called after throwing an instance of 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >'
Aborted
*/