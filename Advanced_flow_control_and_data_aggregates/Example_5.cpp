////////////////////////////////////////////////////////////
// Counting odd and even numbers coming from the keyboard //
////////////////////////////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    // We will count the numbers here.
    int evens = 0, odds = 0;

    // We will store the incoming numbers here.
    int number;

    // Read first number.
    cout << "Number: ";
    cin >> number;

    // 0 terminates execution.
    while (number != 0) {
        // Check if the number is odd.
        if (number % 2 == 1)		
            // Increase „odd” counter.
            odds++;
        else
            // Increase „even” counter.
            evens++;
        // Read next number.
        cout << "Number: ";
        cin >> number;
    }

    // Print results.
    cout << "\nEven numbers: " << evens << endl;
    cout << "Odd numbers: " << odds << endl;

    askOS();
    return 0;
}

/*
Output:

Number: 1
Number: 2
Number: 3
Number: 4
Number: 5
Number: 0

Even numbers: 2
Odd numbers: 3
*/