#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main()
{
    /* temporary storage for the incoming numbers */
    int number;
    /* get the first value */
    cout << "Number: ";
    cin >> number;
    /* we will store the currently greatest number here */
    int max = number;
    /* if the number is not equal to -1 we will continue */
    while (number != -1) {
        /* is the number greater than max? */
        if (number > max)
            /* yes – update max */
            max = number;
        /* get next number */
        cout << "Number: ";
        cin >> number;
    }
    /* print the largest number */
    cout << "The largest number is " << max;

    askOS();
    return 0;
}