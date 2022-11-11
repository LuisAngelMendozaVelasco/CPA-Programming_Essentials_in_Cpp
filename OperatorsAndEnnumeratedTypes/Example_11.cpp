/* Compound assignment operators

    Operators	                                += -= *= %= /= &= |= ^= >>= <<=
    May be implemented as a global function?	NO
    May be implemented as a member function?	YES
    Type of return value	                    A reference to an object or an l-value in general
None of the above operators is implicitly derived from its regular counterpart and vice versa. Overloading the + operator doesn’t produce the += operator and so on. 
The implementation of both components of such a pair should be compatible (i.e. X += Y should be evaluated in the same way and result in the same value as X = X + Y), 
but there’s no automation in it.
All the operator functions from this category have one argument and directly modify their home object. The function should return a reference to the modified object to allow chaining.
The code defines both + and += operators.*/
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

    V& operator+=(V &arg)
    {
        for(int i = 0; i < 2; i++)
            vec[i] += arg.vec[i];
        return *this;
    }
};

V& operator+(V &left, V &right)
{
    V *res = new V(0, 0);
    for(int i = 0; i < 2; i++)
        res->vec[i] = left.vec[i] + right.vec[i];
    return *res;
}

int main()
{
    V v1(0, 0), v2(1, 2), v3(3, 4);

    v1 = v2 + v3;
    v1 += v1;
    cout << "(4, 6) + (4, 6) = " << "(" << v1.vec[0] << ", " << v1.vec[1] << ")" << endl;

    askOS();
    return 0;
}