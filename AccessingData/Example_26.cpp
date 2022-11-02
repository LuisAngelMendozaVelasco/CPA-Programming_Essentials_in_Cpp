/* Appending a character

If we want to append just one character to a string, we can do it by using the append function, 
but there’s a more efficient way, by using the push_back member function.*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() {
    string the_string;

    for (char c = 'A'; c <= 'Z'; c++)
        the_string.push_back(c);
    cout << the_string;

    askOS();
    return 0;
}