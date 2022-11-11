/* Subscript operator

    Operators	                                []
    May be implemented as a global function?	NO
    May be implemented as a member function?	YES
    Type of return value	                    A reference to an object or an l-value in general
The original form of the [] operator is very complex, in both syntax and semantic aspects.
Fundamentally, it requires two arguments, a pointer (because the name of an array is interpreted as a pointer to its first element) and an int value as an index. 
Moreover, the original form of the operator is commutative, i.e. in the following declaration:
    int arr[10];
both of these assignments are valid:
    arr[0] = 0;
    1[arr] = 1;
The overloaded index operator differs a bit from its regular ancestor. It may accept indexes when they’re not integers – virtually all data types (including classes) 
can be used as an index, allowing the programmer to implement complex search algorithms.
E.g. we can hide database searches and updates under a mask of indexing. Furthermore, int indexes may be negative. The semantics of such indexing is fully defined by the programmer.
The overloaded index operator isn’t commutative any more.
The operator needs to find a reference to the data either directly or indirectly pointed to by the index value, and thus the operator will work properly at both sides of the assignment operator.
The operator has to be declared as one-parameter: only the index value comes from the outer world, because the object itself is treated as a second argument.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* It’s a rather weird method of translating a number into the name of a variable. We can say that the Arr class is an array without an array. 
That pseudo-array accepts indexes starting from 1, not from 0 (this was a standard convention in the very first programming languages).*/
class Arr {
private:
    int a, b, c, d;
public:
    Arr()
    { 
        a = b = c = d = 0; 
    }

    int& operator[] (int index)
    {
        switch(index) {
            case 1:  return a;
            case 2:  return b;
            case 3:  return c;
            case 4:  return d;
            default: throw range_error("bad index");
        }
    }
};

int main()
{
    Arr arr;

    for(int i = 1; i <= 4; i++)
        arr[i] = i * i;
    for(int i = 4; i > 0; i--)
        cout << i << " * " << i << " = " << arr[i] << endl;

    askOS();
    return 0;
}