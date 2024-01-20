/* 
Newer compilers accepts completely differ syntax for the same purpose. A function which throws an exception (no matter which exactly) announces its intent using the following form:.
    noexcept(false)
A statement to the contrary is written as:
    noexcept(true)
or simply as:
    noexcept   
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

void thrower() noexcept(false)
{
    cout << "Thrower" << endl;
    throw Class("object");
}

void putter() noexcept(true)
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

Putter
Thrower
Caught!
*/