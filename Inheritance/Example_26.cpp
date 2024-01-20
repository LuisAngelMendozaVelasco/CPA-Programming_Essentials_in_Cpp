//////////////////////////
// Copying constructors //
//////////////////////////

/*
In some cases, we may want to prevent any use of the copying constructor forcing the user of our class to construct its objects in a more detailed way.
All we have to do is specify the explicit copying constructor (it may be empty) and put it inside the private part of our class.
Any attempt to make use of the copying constructor (whether implicit or explicit) will cause a compilation error.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Dummy {
    private:
        Dummy(Dummy &source) {}

    public:
        Dummy(int value) {}
};

void do_something(Dummy ob)
{
    cout << "I'm here!" << endl;
}

/* 
Errors are caused by the fact that the copying constructor is private i.e. it's unaccessible in contexts where it is invoked implicitly e.g. during o2 declaration. 
The same problem appears during do_something() invocation when o1 is copied into parameter passed by value. 
Moving the constructor to public part eliminates these errors.
*/
int main()
{
    Dummy o1(123);
    Dummy o2 = o1; // Error

    do_something(o1); //Error

    askOS();
    return 0;   
}

/*
Output:

error: ‘Dummy::Dummy(Dummy&)’ is private within this context
note: declared private here
    Dummy(Dummy &source) {}
*/