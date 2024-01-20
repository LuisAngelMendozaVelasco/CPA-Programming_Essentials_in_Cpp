//////////////////////////////////////////////////////
// Comparing strings – the object-oriented approach //
//////////////////////////////////////////////////////

/*
The possibilities of the compare member function don’t stop at checking the identity of the strings. 
The function can also diagnose all of the possible relations between two strings. Here’s how it works:
    * str1.compare(str2) == 0 when str1 == str2
    * str1.compare(str2) > 0 when str1 > str2
    * str1.compare(str2) < 0 when str1 < str2
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
    cout << endl << "You've entered:'" << endl;

    if (str1.compare(str2) == 0)
        cout << "\"" << str1 << "\" == \"" << str2 << "\"" << endl;
    else if (str1.compare(str2) > 0)
        cout << "\"" << str1 << "\" > \"" << str2 << "\"" << endl;
    else
        cout << "\"" << str2 << "\" < \"" << str1 << "\"" << endl;

    askOS();
    return 0;
}

/*
Output:

Enter 2 lines of text:
First line: Luis
Second line: Mendoza

You've entered:'
"Mendoza" < "Luis"
*/