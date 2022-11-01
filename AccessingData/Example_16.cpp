/* 
Comparing strings – the object-oriented approach

Strings offer another more complex, but also more powerful, method of comparison.
The member function is called “compare” and the name speaks for itself: it’s designed to compare a string with another string. 
The member function returns 0 (zero) if the strings are identical.*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string secret = "abracadabra";
    string password;

    cout << "Enter password: ";
    getline(cin, password);
    if (!secret.compare(password))
        cout << endl << "Access granted!";
    else
        cout << endl << "Sorry!";

    askOS();
    return 0;
}