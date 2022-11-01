/*Conversions – gains and losses
Every time a conversion happens, the compiler does its best to preserve the original value, 
but that’s not always possible.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    /*A good scenario is when the length of the memory representation remains the same or increases; 
    we can be confident then that the original value will be preserved. */
    short s = 32767;
    int i = s;

    cout << "(" << s << " == " << i << "): ";
    if (i == s)
        cout << "equal";
    else
        cout << "not equal";

    askOS();
    return 0;
}