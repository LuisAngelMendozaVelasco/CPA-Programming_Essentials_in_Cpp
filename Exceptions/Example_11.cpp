//////////////////////////
// Crime and Punishment //
//////////////////////////

// What happens when the promise expressed as noexcept(true) isn't kept? 

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

// The unreliable() function declares itself as throwing no exceptions and recklessly breaks the promise.
void unreliable() noexcept(true) {
    throw string("");
}

/* 
Compiler warnings something really catastrophic will occur here. Our program will be immediately terminated when any exception is thrown inside the function. 
The catch is neither reached nor executed. This is what the penalty for perjury looks like.
*/
int main()
{
    try {
        unreliable();
    } 
    catch(string &exc) {
        cout << "Caught!" << endl;
    }

    askOS();
    return 0;
}

/*
Output:

warning: ‘throw’ will always call ‘terminate’ [-Wterminate]
    throw string("");
*/