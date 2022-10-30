#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    int value;

    cout << "Give me a number and I will square it!\n";
    cout << "Number: ";
    cin >> value; // prompts the user to enter a single integer value

    int square = value * value; // squares it
    cout << "You've given " << value << endl;
    cout << "The squared value is " << square; // prints the result with an appropriate comment

    askOS();
    return 0;
}