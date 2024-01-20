////////////////////////////////////////////
// Adding an explicit copying constructor //
//////////////////////////////////////////// 

/*
Let’s assume that we don’t want our objects to share any data. We’re determined to isolate the objects and keep them all separate. 
Taking into account the structure of the class, we should consider adding an explicit copying constructor to our class.
*/

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

        /* 
        The constructor will be responsible for making a copy on its own. Don’t forget that no automatic activities will be performed if 
        a class is already equipped with a copying constructor.
        Our new copying constructor has allocated a new piece of memory and copied original data content to it. 
        This ensures that the object will be separate and will have no common parts.
        */
        Class(Class &source)
        { 
            data = new int;
            *data = source.value();
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

/*
Output:

o1.value() = 124
o2.value() = 123
o3.value() = 123
*/