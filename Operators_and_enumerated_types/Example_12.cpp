//////////////////////////////////////////////
// Prefix increment and decrement operators //
//////////////////////////////////////////////

/*
"Operators"	                                "++ --"
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The prefix form of the ++/-- has to be implemented as a parameter-less operator function and (as it modifies its argument before it’s used) it should return a reference to the modified object.
We’re responsible for ensuring that the prefix and suffix operators leave their arguments in the same state and that both are coherent with +=1 and -=1. 
The compiler isn’t shrewd enough to do it for us.
the code shows us an overloaded prefix ++ which affects all vector elements. 
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

        V& operator++()
        {
            for(int i = 0; i < 2; i++)
                vec[i]++;
            return *this;
        }
};

int main()
{
    V v1(1, 2);

    ++v1;
    cout << "++(1, 2) = " << "(" << v1.vec[0] << ", " << v1.vec[1] << ")" << endl;

    askOS();
    return 0;
}

/*
Output:

++(1, 2) = (2, 3)
*/