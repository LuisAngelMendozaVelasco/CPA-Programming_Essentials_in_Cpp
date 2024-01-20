//////////////////////////
// Copying constructors //
//////////////////////////

/*
The copying constructor is a specific form of constructor designed to make a more or less literal copy of an object. 
You can recognize this constructor by its distinguishable header.
Assuming that a class is called A, its copying constructor will be declared as:
    A(A &)
This means that the constructor expects one parameter to be a reference to an object whose content is intended to be copied to the newly created object. 
There’s no obligation to declare your own copying constructor within any of the classes.
If there’s no explicit copying constructor in some class, an implicit constructor will be used instead. 
The implicit constructor simply clones (bit by bit) the source object, producing a twin copy of it. It works satisfactorily in most cases, 
but requires attention and some consideration when used with objects that contain other objects or pointers.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// The class declared in the example has no explicit copying constructor. We expect that an implicit constructor will be used then.
class Class {
    int data;

    public:
        Class(int value) : data(value) {}

        void increment() 
        {
            data++; 
        }

        int value()
        { 
            return data; 
        }
};

int main()
{
    /* 
    It’ll be activated twice – during the initializations of the o2 and o3 objects. The example reminds us of two possible ways to specify an object’s declaration, 
    using the = operator in the classical assignment notation and using the functional notation.
    The o2 and o3 objects will be created as twin copies of o1 and o2 objects respectively, but we need to stress that these three objects have nothing in common.
    In particular, each of them has its own data field. All three objects live their own lives, separate from their siblings. As you can predict, 
    the increment applied to the o1 object affects neither the o2, nor the o3 object.
    */
    Class o1(123);
    Class o2 = o1;
    Class o3(o2);

    o1.increment();
    cout << "o1.value() = " << o1.value() << endl;
    cout << "o2.value() = " << o2.value() << endl;
    cout << "o3.value() = " << o3.value() << endl;

    askOS();
    return 0; 
}

/*
Output:

o1.value() = 124
o2.value() = 123
o3.value() = 123
*/