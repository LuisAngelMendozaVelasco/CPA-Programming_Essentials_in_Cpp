/* Friend functions

A function may be a class’s friend too. Such a function may access all the private and/or protected components of the class.
The rules are a bit different:
    * a friendship declaration must contain a complete prototype of the friend function (including return type); a function with the same name, 
    but incompatible in the sense of the parameters’ conformance, will not be recognized as a friend
    * a class may have many friend functions
    * a function may be a friend of many classes
    * a class may recognize as friends both global and member functions*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* It does nothing except inform the compiler that a class named A will be in use. The lack of line will cause compilation errors as the compiler 
won’t be aware of the existence of the A class when analysing the C class body.*/
class A;

class C {
public:
    void dec(A &a);
};

/* The A class has three friends. They are:
    * the B class
    * the global do_it() function
    * the member function dec() (from the C class)*/
class A {
friend class B;
friend void C::dec(A&);
friend void do_it(A&);
private:
    int field;
protected:
    void print() 
    { 
        cout << "It's a secret, that field = " << field << endl; 
    }
};

void C::dec(A &a) 
{ 
    a.field--; 
}

class B {
public:
    void do_it(A &a) 
    { 
        a.print(); 
    }
};

void do_it(A &a) 
{
    a.field = 99;
}

int main() 
{
    A a; B b; C c;

    do_it(a);
    b.do_it(a);

    askOS();
    return 0; 
}