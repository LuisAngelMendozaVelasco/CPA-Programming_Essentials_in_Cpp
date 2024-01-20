/* 
To throw or not to throw

Knowing whether a certain function throws an exception or not can be very valuable to the compiler.
A function's epilogue can be much more complex when an exception is thrown somewhere inside function's body. It means that function which announces loudly that isn't going 
to throw exception can be compiled in more compact and economical way. 
throw(x) means that the function throws one kind of exception, of type x, for example:
    void the_fun() throw(string);
The more complex form looks like this:
    throw(x1, x2, … ,xn)
This means that the function throws n different exceptions of types x1, x2, ..., xn respectively, for example:
    int do_it(int i) throw(int, string, Class);
This function may throw exceptions of type int, string and Class.
The last form look like this:
    throw()
and means “the function throws no exceptions at all”.
COMPILATION ERROR!
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

// We’ve added the throw specifications to two of our functions.
// It declares itself as throwing one kind of exceptions
void thrower() throw(Class)
{
    cout << "Thrower" << endl;
    throw Class("object");
}

// It renounces exception throwing completely.
void putter() throw()
{
    cout << "Putter" << endl;
}

int main()
{
    try {
        putter();
        thrower();
    }
    catch(Class &exc) {
        cout << "Caught!" << endl;
    }

    askOS();
    return 0;
}

/*
Output:

error: ISO C++17 does not allow dynamic exception specifications
    void thrower() throw(Class)
*/