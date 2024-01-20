/* 
The code shows a class that doesn’t have a constructor at all. We are aware of all the possible hazards connected with the use of uninitialized objects.
The class will be implicitly equipped with the so-called implicit default (parameter-less) constructor but the constructor will do nothing at all. 
Our will will be wilful indeed!
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// The class has no constructor. In effect its fields will not be initialized in any way. The values outputted by the display() method may be completely random then.
class NoConstructorsAtAll {
    public:
        int i;
        float f;

        void display()
        { 
            cout << "i = " << i << ", f = " << f << endl; 
        }
};

int main()
{
    NoConstructorsAtAll  o1;
    NoConstructorsAtAll *o2 = new NoConstructorsAtAll;

    o1.display();
    o2 -> display();

    askOS();
    return 0;   
}

/*
Output:

i = 73728, f = 0
i = 0, f = 0
*/