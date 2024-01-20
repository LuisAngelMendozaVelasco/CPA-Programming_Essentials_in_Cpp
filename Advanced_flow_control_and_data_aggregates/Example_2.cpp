///////////////////////////////////////
// Finding the larger of two numbers //
///////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int number1, number2;

    // Read two .
    cout << "Number 1: ";
    cin >> number1;
    cout << "Number 2: ";
    cin >> number2;

    // We will save the larger number here, we temporarily assume that the former number is the larger one, we will check it soon.
    int max = number1;

    // We check if the assumption was false.
    if (number2 > max)
        max = number2;

    // We print the result.
    cout << "\nThe larger number is " << max << endl;

    askOS();
    return 0;
}

/*
Output:

Number 1: 5
Number 2: 6
The larger number is 6
*/