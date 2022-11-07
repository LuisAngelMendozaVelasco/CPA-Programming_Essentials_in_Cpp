// Compo class has its own copying constructor. It’ll be implicitly invoked once during the life of our program at the moment the co2 object is created.
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
    B(){ };
    void do_it()
    { 
        cout << "B is doing something" << endl; 
    }
};

/* The explicit copying constructor (written by us) has invoked none of the component’s copying constructors. Unfortunately, defining our own 
copying constructor means we assume full responsibility for all the activities needed to carry out responsible copying. 
This means that we need to modify the constructor. One way to do this is to add a line like this one:
    Compo(Compo &src) : f1(src.f1), f2(src.f2)
    { 
        cout << "Copying Compo..." << endl; 
    }
instead of
    Compo(Compo &src)
    { 
        cout << "Copying Compo..." << endl; 
    }*/
class Compo {
public:
    Compo(Compo &src)
    { 
        cout << "Copying Compo..." << endl; 
    }
    Compo() { };
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