#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0;

    do {
        cout << "Number: ";
        cin >> number;

        if(number == -1)
            continue; // Behaves as the program suddenly reached the end of the body; the end of the loop's body is reached and the condition expression is tested immediately.

        counter++;

        if(number > max)
            max = number;
    } while (number != -1);

    if(counter)
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