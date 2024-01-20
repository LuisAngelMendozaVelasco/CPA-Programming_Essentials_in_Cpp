/* 
We’ve changed the header of the existing constructor by adding default values to both parameters. This means that from a compiler’s perspective, 
an invocation like this one:
    WithConstructor()
is solvable even when the parameter-less constructor cannot be found within the class.
The compiler will look for another compatible candidate for the invocation and will find it, assuming that it corresponds to the following invocation:
    WithConstructor(0, 0.)
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class WithConstructor {
    public:
        int i;
        float f;

        WithConstructor(int a = 0, float b = 0.) : i(a), f(b) { }

        void display()
        { 
            cout << "i = " << i << ", f = " << f << endl; 
        }
};

int main()
{
    WithConstructor  o1;
    WithConstructor *o2 = new WithConstructor();

    o1.display();
    o2 -> display();

    askOS();
    return 0; 
}

/*
Output:

i = 0, f = 0
i = 0, f = 0
*/