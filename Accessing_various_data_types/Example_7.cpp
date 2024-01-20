////////////////////////////////////
// Conversions – gains and losses //
////////////////////////////////////

/*
Conversions from floating point types to integral types always cause a loss of accuracy. 
There’s no escaping this.  We always lose the fractional part of a float number.
*/

#include <iostream>
#include <iomanip>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    /* 
    Also when the float is extremely large (or extremely small) we’ll also experience a loss of value. 
    This applies to the values beyond the scope of the target integral type.
    */
    float f = 123.456;
    float g = 1e100;
    int i = f;
    int j = g;

    cout << fixed;
    cout << setprecision(3);
    cout << f << " -> " << i << endl;
    cout << g << " -> " << j << endl;

    askOS();
    return 0;
}

/*
Output:

123.456 -> 123
inf -> -2147483648
*/