/* Throw and the objects it throws

The throw statement is obligated to throw a value e.g. an object – it can’t throw nothing. Throw is able to throw any object of any accessible class. 
We also know that the type of the object thrown may be used to choose the catch which will be responsible for handling the exception.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* We use the class in two roles: once as data being “processed” by the do_calculations() function and once as an exception container. 
These two applications have nothing in common! We want to show that these two paths (routine and exceptional) go completely separately.*/
class Class {
public:
    string msg;
    Class(string txt) : msg(txt)
    {
        cout << "Object [" << msg << "] constructed" << endl; 
    }
    ~Class()
    {
        cout << "Object [" << msg << "] destructed" << endl; 
    }
    void hello()
    { 
        cout << "Object [" << msg << "] says: hello" << endl; 
    }
};

void do_calculations(int i)
{
    if(i == 0) 
        /* It will cause the creation of a new object of class Class. This means that the appropriate constructor will be invoked before the function ends its life.
        It doesn’t mean that the destructor will be invoked before the function ends its life. The object will be alive even after the function’s epilogue. 
        It must live until it finds its target catch and will die only when catch ends its job. Not sooner.*/
        throw Class("exception 1");
    Class object("object");
    if(i == 1)
        throw Class("exception 2");
    object.hello();
    if(i == 2)
        throw Class("exception 3");
}

int main()
{
    for(int i = 0; i < 3; i++) {
        try {
            cout << "-------" << endl;
            do_calculations(i);
        }
        catch (Class &exc) {
            cout << "Caught!" << endl;
            cout << exc.msg << endl;
        }
    }   

    askOS();
    return 0;
}