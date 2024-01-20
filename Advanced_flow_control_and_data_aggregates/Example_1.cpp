#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;

    if(a + b != c) // Numbers stored as floating point data can be different from their real (precise) values
        cout << "Your computer is out of order!" << endl;

    askOS();
    return 0;
}

/*
Output:

Your computer is out of order!
*/