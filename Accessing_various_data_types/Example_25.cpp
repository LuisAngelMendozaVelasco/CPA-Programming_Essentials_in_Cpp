/////////////////////////////
// Appending a (sub)string //
/////////////////////////////

/*
append() is designed to append one string to another.
Same task can be performed by the += operator. However, the append function is much more 
flexible and helpful than += and can give you more options.
We can use the append() function to append a string - here's an example:
    string str1 = "content"; str2 = "appendix"; str1.append(str2);
    // str1 contains "contentappendix" now
The append() function is able to append not only a string, but also a substring of the string, like this:
    string str1 = "content";  str1.append("tail",1,3);
    // str1 contains "contentail" now
The append can append a char (possibly repeated n times), like this:
    string str1 = "content";  str1.append(3, 'x');
    // str1 contains "contentxxx" now
All these variants not only affect the content of the string, but also return the modified string as a result.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string the_string = "content";
    string new_string;

    new_string.append(the_string); //Append a string to this string.
    cout << new_string << endl;
    new_string.append(the_string, 0, 3); //Append a substring.
    cout << new_string << endl;
    new_string.append(2, '!'); //Append multiple characters.
    cout << new_string << endl;

    askOS();
    return 0;
}

/*
Output:

content
contentcon
contentcon!!
*/