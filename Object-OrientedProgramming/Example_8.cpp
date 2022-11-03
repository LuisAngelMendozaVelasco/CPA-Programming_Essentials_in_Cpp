/* Static variables

We’ve just added the "static" keyword in front of "int".
The "var" variable is created and initiated once during the so-called "program prologue" and is destroyed after program completion 
during the operation of the so-called "program epilogue". This means that the var variable exists even when the fun function isn’t
working and in effect the variable’s value is preserved between subsequent fun invocations. This is how the static keyword affects variable fate.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

void fun() 
{
    static int var = 99;
    cout << "var = " << ++var << endl;
}

int main() 
{
    for(int i = 0; i < 5; i++)
        fun();

    askOS();
    return 0; 
}