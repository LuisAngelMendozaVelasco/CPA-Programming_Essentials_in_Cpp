/* Function invocation operator

    Operators	                                ()
    May be implemented as a global function?	NO
    May be implemented as a member function?	YES
    Type of return value	                    any
The function invocation operator is very different. Here are some of its characteristics:
    * the number of its parameters isn’t predefined; you can use as many parameters as you want
    * the return type is neither predefined nor suggested; use the one you need
    * one class may contain more than one overloaded operator () function; specify as many as you need, but remember to keep them all distinguishable by the number and 
    types of parameters (relate it to the requirements for overloaded functions)
The operator may be used to create objects that pretend to be functions (they can be used to do more advanced things).
The code shows this type of imitating class. It overloads the () operator twice to create a guise for two overloaded functions, finding a maximal of their arguments.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Fun {
public:
    int operator() (int a1, int a2)
    {
        return a1 > a2 ? a1 : a2;
    }
    int operator() (int a1, int a2, int a3)
    {
        return a1 > a2 ? (a1 > a3 ? a1 : a3) : (a2 > a3 ? a2 : a3);
    }
};

int main()
{
    Fun f;

    cout << "max(1, 2) = " << f(1, 2) << endl;
    cout << "max(1, 2, 3) = " << f(1, 2, 3) << endl;

    askOS();
    return 0;
}