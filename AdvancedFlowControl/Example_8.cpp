#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0;

    for (;;) { // infinite loop
        cout << "Number: ";
        cin >> number;
        if (number == -1)
            break; // exits the loop immediately and unconditionally ends the loop’s operation
        counter++;
        if (number > max)
            max = number;
    }

    if (counter)
        cout << "The largest number is " << max;
    else
        cout << "Are you kidding? You haven't entered any number!";

    askOS();
    return 0;
}