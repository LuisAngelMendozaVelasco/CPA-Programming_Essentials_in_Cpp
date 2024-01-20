///////////////////////
// Comparing strings //
///////////////////////

/*
We can compare two strings in more flexible ways too. All the operators designed to compare data: > < >= <= !=. 
We can check if one of the strings is greater/lesser than the other, but remember that these comparisons are 
carried out in alphabetical order where 'a' is greater than 'A' (sic) and obviously 'z' is greater than 'a', 
but less obviously, 'a' is greater than '1'.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string str1, str2;

    cout << "Enter 2 lines of text:" << endl;
    cout << "First line: ";
    getline(cin, str1);
    cout << "Second line: ";
    getline(cin, str2);
    cout << endl << "You've entered:" << endl;

    if (str1 == str2)
        cout << "\"" << str1 << "\" == \"" << str2 << "\"" << endl;
    else if (str1 > str2)
        cout << "\"" << str1 << "\" > \"" << str2 << "\"" << endl;
    else
        cout << "\"" << str2 << "\" > \"" << str1 << "\"" << endl;

    askOS();
    return 0;
}

/*
Output:

Enter 2 lines of text:
First line: Luis
Second line: Mendoza

You've entered:
"Mendoza" > "Luis"
*/