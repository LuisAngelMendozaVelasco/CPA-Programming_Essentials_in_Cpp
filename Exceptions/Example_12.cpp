/* 
It’s a very simple illustration of the concept saying that exception handling may be distributed among different parts of the program. 
We can handle our exceptions in the most suitable places and don’t need to collect all catches in one function or module.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

// The function thrower() throws two different exceptions, but exceptions of different types are handled differently.
void thrower(int i)
{
    switch(i) {
        case 0 : throw string("string");
        case 1 : throw Class("object");
        default: cout << "OK" << endl;
    }
}

/* 
There’s another function (named midlevel()) which has created an intermediate level between the function and the main.
The midlevel() function catches exceptions of type string (the objects of this class end their lives there), but Class exceptions fly on to the main() function and are caught there.
*/
void midlevel(int i) 
{
    try {
        thrower(i);
    } 
    catch(string &exc) {
        cout << "String [" << exc << "] caught in level()" << endl;
    }    
}

int main()
{
    for(int i = 0; i < 3; i++) {
        cout << "-------" << endl;

        try {
            midlevel(i);
        } 
        catch(Class &exc) {
            cout << "Object [" << exc.msg << "] caught in main()" << endl;
        }
    }

    askOS();
    return 0;
}

/*
Output:

-------
String [string] caught in level()
-------
Object [object] caught in main()
-------
OK
*/