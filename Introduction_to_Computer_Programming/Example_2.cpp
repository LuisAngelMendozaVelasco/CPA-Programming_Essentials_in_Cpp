#include <iostream>
#include <iomanip> // Setbase manipulator requires a header file called iomanip
#include "../myFunctions.h"
using namespace std;

int main()
{
	int byte = 255;

	cout << setbase(16) << byte << endl; // Setbase manipulator instructs the stream on what base value it should use during conversion

    askOS();
    return 0;
}

/*
Output:

ff
*/