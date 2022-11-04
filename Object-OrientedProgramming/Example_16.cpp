/* Pointers to objects

We’ve treated objects like ordinary variables and assumed that an object is created in the place where it is declared and destroyed when its declaration scope is exited. 
This is only one of the many possible object incarnations. Objects may also exist as dynamically created and destroyed entities. 
In other words, objects may appear on demand – when they’re needed – and vanish in the same way.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* The class has no fields and no member functions. There’s only one constructor and one destructor within this class. 
They both do nothing – their only activity is to announce that they’ve been invoked.*/
class Class {
public:
    Class() 
    {
        cout << "Object constructed!" << endl;
    }
    ~Class() 
    {
        cout << "Object destructed!" << endl;
    }
};

/* The main function declares the ptr variable, which is a pointer to objects of the Class class. 
Next, we’ve created one object of that class using the new keyword. Note that we can omit the empty parentheses after the Class name – in either case, 
the parameter-less constructor will be activated - check it, please. Finally, the object is destroyed using the delete keyword. 
The process of destroying the object begins with the implicit invocation of its destructor.*/
int main() 
{
    Class *ptr = new Class();

    delete ptr;

    askOS();
    return 0; 
}