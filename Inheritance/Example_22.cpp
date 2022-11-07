/* Copying constructors

Blindly relying on the implicit copying constructor may be dangerous and may cause adverse effects.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* The data isn’t stored in a regular variable but in a piece of memory allocated by the new operator.
The data field is declared as a pointer to the int values (in other words, it’s a variable of type int *).
The implicit copying constructor makes a twin copy of an object. Note that this is of an object, not the entities existing outside the object. 
This means that the data field will obviously be copied (cloned) into the newly created object, but in effect it will point to the same piece of memory.
This also means that different objects may have something in common – they may share some data among them.*/
class Class {
    int *data;
public:
    Class(int value) 
    {
        data = new int;
        *data = value;
    }
    void increment()
    { 
        (*data)++; 
    }
    int value()
    { 
        return *data; 
    }
};

int main()
{
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