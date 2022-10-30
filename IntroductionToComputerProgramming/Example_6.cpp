#include <iostream>
#include <cmath> // to use sqrtf you need to include a header file named cmath
#include "../myFunctions.h"

using namespace std;

int main() 
{
    float value;

    cout << "Give me a number and I will find its square root:" << endl;
    cout << "Number: " ;
    cin >> value;
    if(value >= 0.0) { // If enter a negative number, the program will just ignore the input completely.
        float squareroot = sqrtf(value); // sqrtf (square root float) and needs exactly one argument
        cout << "You have given: " << value << endl;
        cout << "The square root is: " << squareroot;
    }

    askOS();
    return 0;
}