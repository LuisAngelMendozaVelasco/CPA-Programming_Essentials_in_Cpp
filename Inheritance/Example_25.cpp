//////////////////////////
// Copying constructors //
//////////////////////////

/*
Using an object as function parameters passed by value isn’t a good idea. The mechanism of passing parameters by value assumes that a function
operates on the copy of an actual parameter. This is clear when we consider parameters of simple types (like int or float), 
but it becomes more complex when the parameter is an object.
We do not simply make a copy of an object. The only automatic way in which the copy may be obtained is to invoke the copying constructor 
and to face up to all the advantages and disadvantages of that approach.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Dummy {
    public:
        Dummy(int value) {}

        /* 
        The copying constructor will be invoked when an object is passed to a function by value. We’ve had to make the constructor a 
        little verbose – this is the simplest way to trace its paths.
        */
        Dummy(Dummy &source)
        { 
            cout << "Hi from the copy constructor!" << endl;
        }
};

void do_something(Dummy ob)
{
    cout << "I'm here!" << endl;
}

int main()
{
    Dummy o1(123);

    do_something(o1);

    askOS();
    return 0;   
}

/*
Output:

Hi from the copy constructor!
I'm here!
*/