//////////////////////////////////////////
// Finding the largest of three numbers //
//////////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int number1, number2, number3;

    // Read three numbers.
    cout << "Number 1: ";
    cin >> number1;
    cout << "Number 2: ";
    cin >> number2;
    cout << "Number 3: ";
    cin >> number3;

    // We will save the larger number here, we temporarily assume that the former number is the larger one, we will check it soon.
    int max = number1;

    // We check if the second value is the largest.
    if (number2 > max)
        max = number2;

    // We check if the third value is the largest.
    if (number3 > max)
        max = number3;

    // We print the result.
    cout << "\nThe largest number is " << max << endl;

    askOS();
    return 0;
}

/*
Output:

Number 1: 5
Number 2: 6
Number 3: 7

The largest number is 7
*/