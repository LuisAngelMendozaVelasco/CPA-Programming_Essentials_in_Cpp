///////////////////////////////////
// Compositions vs. constructors //
///////////////////////////////////

/*
Inheritance isn’t the only form of class/object coexistence. In fact, inheritance is completely useless when we express many of the complicated relationships 
existing in the real world.
For example, we can imagine a class designed to gather different kinds of dogs. Making a class and putting it at the bottom of a dog breed inheritance tree 
isn’t a good idea and won’t bear desirable fruit. The right solution will come to our minds when we understand the actual role of the class – it should gather 
some dogs so, in fact, it will consists of dogs (like a kennel).
This means that the class should include dogs, not inherit them. The kennel has nothing or really very little in common with a dog 
(for example, there is no kennel that can bark).
This means that the class should include dogs, not inherit them. The kennel has nothing or really very little in common with a dog (for example, there is no kennel that can bark).
We can say that any complex structure is composed using simpler elements – for example, a car is composed of an engine, transmission, suspension, etc. If we imagine all these 
parts as classes we’ll see the car class as a composition that has nothing to do with inheritance. Building a class is called composition.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class A { 
    public:
        void do_it() 
        { 
            cout << "A is doing something" << endl; 
        }
};

class B { 
    public:
        void do_it() 
        { 
            cout << "B is doing something" << endl; 
        }
};

// This example shows a simple dummy class consisting (composed) of two objects of two independent classes.
class Compo {
    public:
        A f1;
        B f2;
};

int main() 
{
    Compo  co;

    co.f1.do_it();
    co.f2.do_it();

    askOS();
    return 0; 
}

/*
Output:

A is doing something
B is doing something
*/