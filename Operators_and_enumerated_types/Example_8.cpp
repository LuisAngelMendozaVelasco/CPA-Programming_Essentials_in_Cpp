/////////////////////////
// Assignment operator //
/////////////////////////

/*
"Operators"                                 "="
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The default behaviour of the = operators is rather simple when applied to objects: it just copies the object’s content field by field, making a carbon copy of the source object.
t may be dangerous if the copied object contains pointers to dynamically allocated data, because two or more different objects may make use of implicitly shared data. 
It may be useful when done intentionally, but it may also be critical when done by mistake.
Overloading the = operator may protect the object from problems of this nature and may also add some, maybe somewhat tricky, functionalities to simple assignments.
The code shows an assignment which swaps the vector being assigned.
*/

#include <iostream>
#include <vector>
#include "../myFunctions.h"
using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        V& operator=(V &arg)
        {
            for(int i = 0; i < 2; i++)
                vec[i] = arg.vec[1 - i];
            return *this;
        }
};

int main()
{
    V v1(4, 8), v2;
    v2 = v1;

    cout << "swap(4, 8) = " << "(" << v2.vec[0] << ", " << v2.vec[1] << ")" << endl;

    askOS();
    return 0;
}

/*
Output:

swap(4, 8) = (8, 4)
*/