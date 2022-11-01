/* Inputting strings

Inputting strings is a bit more complicated, due to the fact that the cin stream treats spaces 
(to be precise, not only regular spaces but also all so-called white characters) as delimiters, 
demarcating limits between data. */
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string line_of_types;

    cout << "Input string: ";
    cin >> line_of_types;
    cout << "String: " << line_of_types;

    askOS();
    return 0;
}