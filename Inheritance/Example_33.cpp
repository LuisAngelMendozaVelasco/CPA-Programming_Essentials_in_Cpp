/* Friend

A friend of a class may be:
    a class (it’s called the friend class)
    a function (it’s called the friend function)
A friend (class of function) can access those components hidden from others. Friends are allowed to access or to use private and protected components of the class.
If there are two classes called, for example, A and B, and if A wants B to be able to access its private possessions, it has to announce that B is its friend. 
The announcement works in one direction only. The B class can’t just say, “I am A’s friend” – it won’t work.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* A class named Class has announced that Friend is its friend. In effect, an object of the Friend class is able to manipulate the Class’s private 
fields and invoke its private methods.
It doesn’t matter where we add the friendship declaration, i.e. the line starting with the phrase:
    friend class ... ;
may exist inside any of the class parts (public, private or protected), but must be placed outside any function or aggregate.*/
class Class {
friend class Friend;
private:
    int field;
    void print()
    { 
        cout << "It's a secret, that field = " << field << endl; 
    }
};

class Friend {
public:
    void do_it(Class &c) 
    { 
        c.field = 100; 
        c.print(); 
    }
};

int main()
{
    Class o;
    Friend f;

    f.do_it(o);

    askOS();
    return 0; 
}