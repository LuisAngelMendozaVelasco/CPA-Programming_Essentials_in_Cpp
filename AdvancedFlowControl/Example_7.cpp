#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    int pow = 1;

    // The exp variable is used as a control variable for the loop and indicates the current value of the exponent
    for(int exp = 0; exp < 16; exp++) {
        if (exp < 15)
            cout << "2 to the power of " << exp << " is " << pow << endl;
        else
            cout << "2 to the power of " << exp << " is " << pow;
        pow *= 2;
    }

    askOS();
    return 0;
}