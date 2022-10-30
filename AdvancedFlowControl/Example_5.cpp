// This program counts odd and even numbers coming from the keyboard
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    /* we will count the numbers here */
    int evens = 0, odds = 0;

    /* we will store the incoming numbers here */
    int number;

    /* read first number */
    cout << "Number: ";
    cin >> number;

    /* 0 terminates execution */
    while (number != 0) {
        /* check if the number is odd */
        if (number % 2 == 1)		
            /* increase „odd” counter */
            odds++;
        else
            /* increase „even” counter */
            evens++;
        /* read next number */
        cout << "Number: ";
        cin >> number;
    }
    /* print results */
    cout << "Even numbers: " << evens << endl;
    cout << "Odd numbers: " << odds;

    askOS();
    return 0;
}