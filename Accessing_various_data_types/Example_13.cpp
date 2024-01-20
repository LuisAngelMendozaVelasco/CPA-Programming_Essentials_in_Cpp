///////////////////////
// Inputting strings //
///////////////////////

/*
To input a whole line of text and treat the white characters just like any other character, we have to use the getline() function. 
This function gets/reads all the characters entered as-is and does not favour any character except from the char representing the key, 
which marks the end of the line. As a result, all the characters entered before pressing the key will be input as one string.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string line_of_types;

    cout << "Input string: ";
    getline(cin, line_of_types);
    cout << "String: " << line_of_types << endl;

    askOS();
    return 0;
}

/*
Output:

Input string: Luis Mendoza
String: Luis Mendoza
*/