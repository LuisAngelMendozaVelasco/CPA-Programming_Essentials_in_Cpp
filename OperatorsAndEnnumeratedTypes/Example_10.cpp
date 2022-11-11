/* Relational operators

    Operators	                                !   &&   ||
    May be implemented as a global function?	YES
    May be implemented as a member function?	YES
    Type of return value	                    boolean
All of the above operators (except !) - are binary and return a Boolean value evaluated in the sense of the Bool’s algebra.
The original (not overloaded) binary operators use a short-circuit evaluation tactic which means that they try to omit an evaluation of the right argument 
if the left argument is sufficient to determine the final result.
    When the left argument of || is true, the whole expression is also true, regardless of the right argument value.
    When the left argument of && is false, the whole expression is also false, regardless of the right argument value.
It doesn’t matter whether the arguments are variables or simple relations, but it does matter when they’re function invocations.
Let’s assume that we’ve got two functions, f1() and f2(), both returning bool. In the following expression:
    f1() && f2()
the f2() function will be invoked or not depending on the f1() result.
As the overloaded logical function can’t make such a distinction, both of the above functions will be invoked when used together in the same expression.
The code defines the && operator to check the following, verbally defined, condition:
    Left and right vectors have at least one non-zero element.
The second of the operators returns a value reflecting the condition:
    All vector elements are non-zero.*/
#include <iostream>
#include <vector>
#include <cmath>
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

    bool operator&&(V &arg)
    {
        return abs(vec[0]) + abs(vec[1]) > 0 && 
                abs(arg.vec[0]) + abs(arg.vec[1]) > 0;
    }
};

bool operator!(V &v)
{
    return v.vec[0] * v.vec[1] != 0;
}

int main()
    {
    V v1(4, 8), v2(3, 7);
    cout << "Left and right vectors have at least one non-zero element: " << (v1 && v2 ? "true" : "false") << endl;
    cout << "All vector elements are non-zero: " << (!v1 ? "true" : "false") << endl;

    askOS();
    return 0;
}