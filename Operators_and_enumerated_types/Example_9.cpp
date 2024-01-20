//////////////////////////
// Relational operators //
//////////////////////////

/*
"Operators"	                                "== != > >= < <="
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    boolean

All of the above operators are binary and all of them return a Boolean value representing the truthfulness of the condition being evaluated (checked).
overloading one of the operators has absolutely no impact on the others, e.g. redefining the meaning of the == operator doesn’t implicitly 
redefine the != operator, and vice versa. Overloading the < operator will automatically overload neither the > nor the >= operators.
The code shows the behaviour of two new operators: the first one returns true when both vectors contain the same values in the same order, while the second 
is a little tricky: it checks the “greater than” relation using the total sum of the vector elements.
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

        bool operator==(V &arg)
        {
            for(int i = 0; i < 2; i++)
                if(vec[i] != arg.vec[i])
                    return false;
            return true;
        }
};

bool operator>(V &l, V &r)
{
    return l.vec[0] + l.vec[1] > r.vec[0] + r.vec[1];
}

int main()
{
    V v1(4, 8), v2(3, 7);

    cout << "(4, 8) == (3, 7): " << (v1 == v2 ? "true" : "false") << endl;
    cout << "4 + 8 > 3 + 7: " << (v1 > v2 ? "true" : "false") << endl;

    askOS();
    return 0;
}

/*
Output:

(4, 8) == (3, 7): false
4 + 8 > 3 + 7: true
*/