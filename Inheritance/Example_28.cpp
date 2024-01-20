/* 
The code cause compilation errors. There’s a constructor within the class. The existence of any constructor is like a statement given by a 
developer: “I’m ready to use constructors in my class”.
The statement is recognized by the compiler as a readiness to provide all the needed constructors so the compiler won’t produce the implicit 
default constructor for that class anymore.
The default constructor has to be implicitly invoked when a new object is created. We can write our own default (parameter-less) constructor.
It’ll make our code fully compilable and it can look something like this:
    WithConstructor() : i(0), f(0.0) { }
and be placed somewhere in the public part of the class. It’ll cause both of the fields to be zeroed at the beginning of an object’s life.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class WithConstructor {
    public:
        int i;
        float f;

        WithConstructor(int a, float b) : i(a), f(b) { }

        void display()
        { 
            cout << "i = " << i << ", f = " << f << endl; 
        }
};

int main()
{
    WithConstructor  o1;
    WithConstructor *o2 = new WithConstructor;

    o1.display();
    o2 -> display();

    askOS();
    return 0; 
}

/*
Output:

error: no matching function for call to ‘WithConstructor::WithConstructor()’
    WithConstructor  o1;
note: candidate: ‘WithConstructor::WithConstructor(int, float)’
    WithConstructor(int a, float b) : i(a), f(b) { }
note:   candidate expects 2 arguments, 0 provided
*/