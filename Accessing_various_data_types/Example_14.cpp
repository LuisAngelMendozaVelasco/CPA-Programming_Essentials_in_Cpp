///////////////////////
// Comparing strings //
///////////////////////

/*
Strings (just like any other data) may be compared. 
The simplest case occurs when you want to check if two variables of type string contain identical strings.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() {
    string secret = "abracadabra";
    string password;

    cout << "Enter password: ";
    getline(cin, password);
    if (secret == password)
        cout << "Access granted!" << endl;
    else
        cout << "Sorry!" << endl;

    askOS();
    return 0;
}

/*
Output:

Enter password: abracadabra
Access granted!
*/