#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0; // to count the numbers entered so we can instruct the user that we cannot search for the greatest number if no number is given
    
    do {
        cout << "Number: ";
        cin >> number;
        if (number != -1)
            counter++;
        if (number > max)
            max = number;
    } while (number != -1);

    if (counter)
        cout << "The largest number is " << max;
    else
        cout << "Are you kidding? You haven't entered any number!";

    askOS();
    return 0;
}