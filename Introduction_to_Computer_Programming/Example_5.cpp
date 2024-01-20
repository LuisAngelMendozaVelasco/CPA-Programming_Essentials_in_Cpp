#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int value;

    cout << "Give me a number and I will square it!\n";
    cout << "Number: ";
    cin >> value; // Prompts the user to enter a single integer value

    int square = value * value; // Squares it

    cout << "\nYou've given " << value << endl;
    cout << "The squared value is " << square << endl; // Prints the result with an appropriate comment

    askOS();
    return 0;
}

/*
Output:

Give me a number and I will square it!
Number: 5

You've given 5
The squared value is 25
*/