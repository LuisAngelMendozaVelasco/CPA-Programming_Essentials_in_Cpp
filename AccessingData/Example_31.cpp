/* Exchanging the contents of two strings

This action is performed by a member function called swap(). 
This function is many times faster than ordinary (physically performed) swapping.*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string drink = "A martini";
    string needs = "Shaken, not stirred";

    cout << "Original order: " << drink << ". " << needs << "." << endl;
    drink.swap(needs);
    cout << "Modified order: "  << drink << ". " << needs << ".";

    askOS();
    return 0; 
}