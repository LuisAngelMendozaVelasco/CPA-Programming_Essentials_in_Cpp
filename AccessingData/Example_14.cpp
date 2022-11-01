/* Comparing strings

Strings (just like any other data) may be compared. 
The simplest case occurs when you want to check if two variables of type string contain identical strings.*/
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
        cout << "Access granted!";
    else
        cout << "Sorry!";

    askOS();
    return 0;
}