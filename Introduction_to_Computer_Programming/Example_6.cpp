#include <iostream>
#include <cmath> // To use sqrtf you need to include a header file named cmath
#include "../myFunctions.h"
using namespace std;

int main() 
{
    float value;

    cout << "Give me a number and I will find its square root:" << endl;
    cout << "Number: " ;
    cin >> value;

    if(value >= 0.0) { // If we enter a negative number, the program will just ignore the input completely
        float squareroot = sqrtf(value); // sqrtf (square root float) needs exactly one argument

        cout << "\nYou have given: " << value << endl;
        cout << "The square root is: " << squareroot << endl;
    }

    askOS();
    return 0;
}

/*
Output:

Give me a number and I will find its square root:
Number: 64

You have given: 64
The square root is: 8
*/