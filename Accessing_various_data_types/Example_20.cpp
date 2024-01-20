/////////////////////////////////////
// More detailed string comparison //
/////////////////////////////////////

/*
Compare functions allow us not only to compare whole strings, but also their substrings.
Their prototypes are clear to understand and easy to use:
    any_string.compare(substr_start, substr_length, other_string)
    any_string.compare(substr_start, substr_length, other_string,  other_substr_start, other_substr_length)
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string s = "ABC";
    cout << "Original string: " << s << endl;

    /*
    s.compare(1, 1, "BC") -> This variant of the compare member function compares the entire other string 
    to the substring of the source string. This means that the following snippet will output -1 (the strings are not equal)
    s.compare(2, 1, s, 2, 2) -> This variant allows us to use only a part of the s string. It will output 0.
    */
    cout << "s.compare(1, 1, \"BC\") + s.compare(2, 1, s, 2, 2) = " << s.compare(1, 1, "BC") + s.compare(2, 1, s, 2, 2) << endl;

    askOS();
    return 0;
}

/*
Output:

Original string: ABC
s.compare(1, 1, "BC") + s.compare(2, 1, s, 2, 2) = -1
*/