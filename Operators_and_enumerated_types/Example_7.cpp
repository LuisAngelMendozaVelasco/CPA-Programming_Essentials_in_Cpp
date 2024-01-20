///////////////////////
// Bitwise operators //
///////////////////////

/*
"Operators"	                                "^ | & ~ << >>"
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    Depending on context

All of the above operators, except the ~ are binary.
Resist the temptation to overload the ^ operator for an exponentiation, like in FORTRAN or Python programming languages and in some spreadsheets.
The real exponentiation has a very high priority (higher than the * operator), while the ^ has a priority lower than other arithmetic operators. 
It may bring along some unexpected and undesired side effects.
*/

#include <iostream>
#include <vector>
#include "../myFunctions.h"
using namespace std;

// The V class is able to bitwise right shift each of its elements and to evaluate their product (it’s a rather unusual use of the ~ operator).
class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        V operator>>(int arg)
        {
            V res(vec[0], vec[1]);

            for(int i = 0; i < 2; i++)
                res.vec[i] >>= arg;
            return res;
        }
};

int operator~(V &arg) 
{
    int res = 1;

    for(int i = 0; i < 2; i++)
        res *= arg.vec[i];
    return res;
}

int main()
{
    V v(15, 7);

    v = v >> 1;
    cout << ">>(17, 7) = " << "(" << v.vec[0] << ", " << v.vec[1] << ")" << endl;
    cout << "7 * 3 = " << ~v << endl;

    askOS();
    return 0;
}

/*
Output:

>>(17, 7) = (7, 3)
7 * 3 = 21
*/