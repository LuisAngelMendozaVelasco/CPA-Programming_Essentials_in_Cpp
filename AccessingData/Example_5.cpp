/* Conversions – gains and losses

We’ll convert the float value into a double value.
double values have not only a wider range than floats, but also better accuracy (precision)*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main()
{
    float f = 1234.5678;
    double d = f;

    cout << "(" << f << " == " << d << "): ";
    if (d == f)
        cout << "equal";
    else
        cout << "not equal";

    askOS();
    return 0;
}