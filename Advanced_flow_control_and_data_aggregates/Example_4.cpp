#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    // Temporary storage for the incoming numbers.
    int number;

    // Get the first value.
    cout << "Number: ";
    cin >> number;

    // We will store the currently greatest number here.
    int max = number;

    // If the number is not equal to -1 we will continue.
    while (number != -1) {
        // Is the number greater than max?
        if (number > max)
            // Yes – update max.
            max = number;
        // Get next number.
        cout << "Number: ";
        cin >> number;
    }

    // Print the largest number.
    cout << "\nThe largest number is " << max << endl;

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
Number: -1

The largest number is 5
*/