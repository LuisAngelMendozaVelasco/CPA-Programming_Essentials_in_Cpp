///////////////////////////
// The 'exception' class //
///////////////////////////

/*
The exception class is a base (or a root) for all other predefined exceptions. It contains a function called what(), which is designed to provide a pointer to the so-called “C”-style string 
(a character sequence terminated with a null character) describing the nature of the exception.
The exact form of this message is implementation-dependent and different compilers may name the same events in different ways.
*/

#include <iostream>
#include <exception>
#include "../myFunctions.h"
using namespace std;

class A {  
    public:
        virtual void f() {}
};

class AA : public A {  
    public:
        void aa() {};
};

int main()
{
    A a;

    // We’ve tried to perform illegal typecasting and used the exception object caught by the catch statement to demonstrate the message we may get.
    try {
        dynamic_cast<AA &>(a).aa();
    } 
    catch (exception ex) {
        cout << "[" << ex.what() << "]" << endl;
    }

    askOS();
    return 0;
}

/*
Output:

[std::exception]
*/