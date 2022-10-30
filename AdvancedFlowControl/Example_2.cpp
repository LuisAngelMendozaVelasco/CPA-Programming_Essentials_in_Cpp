/* finding the larger of two numbers */
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    /* the two numbers */
    int number1, number2;

    /* read two numbers */
    cout << "Number 1: ";
    cin >> number1;
    cout << "Number 2: ";
    cin >> number2;

    /* we will save the larger number here */
    /* we temporarily assume that the former number is the larger one */
    /* we will check it soon */
    int max = number1;

    /* we check if the assumption was false */
    if (number2 > max)
        max = number2;

    /* we print the result */
    cout << "The larger number is " << max;

    askOS();
    return 0;
}