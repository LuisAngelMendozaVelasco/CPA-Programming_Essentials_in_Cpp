#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0;

    for (;;) { // Infinite loop
        cout << "Number: ";
        cin >> number;

        if (number == -1)
            break; // Exits the loop immediately and unconditionally ends the loop’s operation.

        counter++;

        if (number > max)
            max = number;
    }

    if (counter)
        cout << "\nThe largest number is " << max << endl;
    else
        cout << "\nAre you kidding? You haven't entered any number!" << endl;

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