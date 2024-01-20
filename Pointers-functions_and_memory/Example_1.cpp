//////////////////////////////////////////////////
// How the computer and compiler use the memory //
//////////////////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    cout << "This computing environment uses:" << endl;
    cout << sizeof(char) << " byte for chars" << endl;
    cout << sizeof(short int) << " bytes for shorts" << endl;
    cout << sizeof(int) << " bytes for ints" << endl;
    cout << sizeof(long int) << " bytes for longs" << endl;
    cout << sizeof(float) << " bytes for floats" << endl;
    cout << sizeof(double) << " bytes for doubles" << endl;
    cout << sizeof(bool) << " byte for bools" << endl;
    cout << sizeof(int *) << " bytes for pointers" << endl;

    askOS();
    return 0;
}

/*
Output:

This computing environment uses:
1 byte for chars
2 bytes for shorts
4 bytes for ints
8 bytes for longs
4 bytes for floats
8 bytes for doubles
1 byte for bools
8 bytes for pointers
*/