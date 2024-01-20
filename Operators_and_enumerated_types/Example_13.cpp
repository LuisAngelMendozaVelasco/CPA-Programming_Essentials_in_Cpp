///////////////////////////////////////////////
// Postfix increment and decrement operators //
///////////////////////////////////////////////

/*
"Operators"	                                "++ --"
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The postfix form of the ++/-- has to be implemented as a one-parameter operator function (sic! note that the parameter of type int is a complete dummy and we mustn’t use it within the function) 
and since it serves the object before it’s affected by the modification, it should return a copy of the unmodified object.
The presence of the dummy int parameter is the only trait that allows the compiler to distinguish between prefix and postfix overloaded operators.
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

        V operator++(int none)
        {
            V v(vec[0],vec[1]);

            for(int i = 0; i < 2; i++)
                ++vec[i];
            return v;
        }
};

int main()
{
    V v1(2, 3);

    v1++;
    cout << "(2, 3)++ = " << "(" << v1.vec[0] << ", " << v1.vec[1] << ")" << endl;

    askOS();
    return 0;
}

/*
Output:

(2, 3)++ = (3, 4)
*/