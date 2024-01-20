///////////////////
// Main function //
///////////////////

// The code shows our Fraction class in action.

#include "fraction.h"
#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    Fraction f1(1,2), f2(2,3), f;

    cout << f1 << " -> " << f1.get_double() << endl;
    cout << f2 << " -> " << f2.get_double() << endl;

    f = f1 + f2;
    cout << f1 << " + " << f2 << " = " << f << endl;

    f = f2 + f2 + f2;
    cout << f2 << " + " << f2 << " + " << f2 << " = " << f << endl; 

    f = !f;
    cout << f2 << " + " << f2 << " + " << f2 << " = " << f << endl;

    f = f1 * f2;
    cout << f1 << " * " << f2 << " = " << f << endl;

    f = f1 / f2;
    cout << f1 << " / " << f2 << " = " << f << endl;

    Fraction f3(7,8);
    f3 += f1;
    cout << f3 << endl;

    askOS();
    return 0;
}

/*
Output:

[1/2] -> 0.5
[2/3] -> 0.666667
[1/2] + [2/3] = [7/6]
[2/3] + [2/3] + [2/3] = [6/3]
[2/3] + [2/3] + [2/3] = [2/1]
[1/2] * [2/3] = [1/3]
[1/2] / [2/3] = [3/4]
[11/8]
*/