///////////////////////////////////////////////
// Passing by value and passing by reference //
///////////////////////////////////////////////

// Use the “passing by value” if you don't need to share the function's results using the parameter's values, and use “passing by reference” in all other cases.
#include <iostream>
#include "../myFunctions.h"
using namespace std;

void mixed_styles(int bval, int& bref) { // The first parameter is passed by value, while the second is passed by reference
    bref = bval + 1;
}

int main(void) {
    int var1 = 1, var2;

    mixed_styles(var1, var2);
    cout << "var1 = " << var1 << ", var2 = " << var2 << endl;

    askOS();
    return 0;
}

/*
Output:

var1 = 1, var2 = 2
*/