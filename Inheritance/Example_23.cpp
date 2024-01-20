//////////////////////////
// Explicit constructor //
//////////////////////////

// The explicit constructor gets one parameter of type int.

#include <iostream>
#include "../myFunctions.h"
using namespace std;

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
    Class o2(o1.value());
    Class o3(o2.value());

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