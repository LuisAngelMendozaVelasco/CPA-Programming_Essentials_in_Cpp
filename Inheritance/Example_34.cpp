/* Friends rules

There are some additional rules that must be taken into account:
    * a class may be a friend of many classes
    * a class may have many friends
    * my friend’s friend isn’t my friend
    * friendship isn’t inherited – the subclass has to define its own friendships*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class A {
friend class B;
friend class C;
private:
    int field;
protected:
    void print() 
    { 
        cout << "It's a secret, that field = " << field << endl; 
    }
};

class C {
public:
    void do_it(A &a)
    { 
        a.print(); 
    }
};

class B {
public:
    void do_it(A &a, C &c)
    { 
        a.field = 111; c.do_it(a); 
    }
};

int main()
{
    A a; B b; C c;

    b.do_it(a, c);

    askOS();
    return 0; 
}