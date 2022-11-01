/*Conversions – gains and losses

The value being converted is small enough to be stored in any float variable. 
The issue here is precision.*/
#include <iostream>
#include <iomanip>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    // Floats can’t store as many significant digits as specified in the literal assigned to the d variable.
    double d = 123456.789012;
    float f = d;
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    cout << "(" << f << " == " << d << "): ";
    if (d == f)
        cout << "equal";
    else
        cout << "not equal";

    askOS();
    return 0;
}