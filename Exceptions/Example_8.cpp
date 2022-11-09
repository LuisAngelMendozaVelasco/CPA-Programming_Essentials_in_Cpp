/* Throw and how we can find out about it

We can learn about it from reading the function body, but that isn’t a good idea. There are two important arguments worth considering:
    * The function may be very long and very complex – reading it may be time consuming and we may overlook some of the throw statements
    * The source code of the function may be inaccessible – it may happen if we use a ready-made library, written by other authors, 
    when we’ve compiled (binary) files containing only executable code and header files specifying function’s headers but not the bodies.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Class {
public:
    string msg;
    Class(string txt) : msg(txt) {}
};

void function(int i)
{
    throw Class("object");
}

int main()
{
    try {
        function(1);
    }
    catch(Class &exc) {
        cout << "Caught!";
    }

    askOS();
    return 0;
}