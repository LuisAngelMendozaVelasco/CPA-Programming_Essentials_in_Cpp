/* Substrings

The strings allow themselves to be processed in a more precise way when only selected parts of them are taken into consideration. 
A part of a string is called a "substring".
If we want to create a new string consisting of characters taken from another (or even the same) string's substring, 
we can use a member function called substr, and its simplified, informal prototype looks like this:
    newstr = oldstr.substr(substring_start_position, length_of_substring)

The substring of any string is defined by two “coordinates”:
* a place where the substring begins (specified by the substring_start_position parameter);
* its length (specified by the length_of_substring parameter).
Note that characters within a string are numbered, and the first character is that number 0. Therefore, if a string contains n characters, 
the last one is the number n – 1.

Both parameters have default values. This enables us to use the function in a more flexible way. So:
* s.substr(1,2) describes a substring of the s string, starting at its second character and ending at its third character (inclusively)
* s.substr(1) describes a substring starting at the second character of the s string and containing all of the remaining characters of s, 
including the last one; the omitted length_of_substring parameter defaults to covering all the remaining characters in the s string
* s.substr() is just a copy of the whole s string (the substring_start_position parameters defaults to 0)*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string str1 = "ABCDEF";

    cout << "Original string: " << str1 << endl;
    string str2 = str1.substr(1, 1) + str1.substr(4) + str1.substr();

    cout << "Concatenated substrings: str1.substr(1, 1) + str1.substr(4) + str1.substr() = " << str2;

    askOS();
    return 0;
}