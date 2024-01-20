////////////////////////////////////
// Conversions – gains and losses //
////////////////////////////////////

// We want to transfer the maximum value allowed for the int variables to the short variable.

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int i = 2147483647;
    short s = i;

    /*
    As the short integers usually use twice less bits than regular integers, 
    some higher bits of the i variable will be irretrievably lost during implicit conversion.
    */
    cout << "(" << s << " == " << i << "): ";
    if (i == s)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
        
    askOS();
    return 0;
}

/*
Output:

(-1 == 2147483647): not equal
*/