/* The classes have been equipped them with copying constructors. They aren’t all that complex and they don’t actually do anything useful. 
They only emit a message allowing us to notice that the constructor has been invoked. We’ve had to add default constructors too.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class A { 
public:
    A(A &src)
    { 
        cout << "copying A..." << endl; 
    }
    A() { }
    void do_it() 
    { 
        cout << "A is doing something" << endl; 
    }
};

class B { 
public:
    B(B &src) 
    { 
        cout << "copying B..." << endl; 
    }
    B(){ }
    void do_it() 
    { 
        cout << "B is doing something" << endl; 
    }
};

/* The Compo class doesn’t have a copying constructor. This means that the compiler will generate an implicit copying constructor for the class.
This constructor copies the objects bit by bit.
Besides its normal activity (the cloning), the copying constructor takes into consideration all the existing copying constructors 
(implicit and explicit) defined within the objects used to compose the class. This gives a chance to copy the components in the most appropriate way.*/
class Compo {
public:
    Compo() { } ;
    A f1;
    B f2;
};

int main() 
{
    Compo  co1;
    Compo  co2 = co1;

    co2.f1.do_it();
    co2.f2.do_it();

    askOS();
    return 0; 
}