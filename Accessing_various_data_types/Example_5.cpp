////////////////////////////////////
// Conversions – gains and losses //
////////////////////////////////////

/*
We'll convert the float value into a double value.
double values have not only a wider range than floats, but also better accuracy (precision).
*/

#include <iostream>
#include <iomanip>
#include "../myFunctions.h"
using namespace std;

int main()
{
    float f = 1234.5678;
    double d = f;
    
    cout << fixed;
    cout << setprecision(4);

    cout << "(" << f << " == " << d << "): ";
    if (d == f)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    askOS();
    return 0;
}

/*
Output:

(1234.5677 == 1234.5677): equal
*/