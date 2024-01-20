////////////////////////////
// The length of a string //
////////////////////////////

/*
Every string has a length. Even an empty string (containing no characters at all) has a length of zero.
This information is provided by two twin member functions.
Their informal prototypes look like these:
    int string_size = any_string.size();
    int string_length = any_string.length();
Both functions return a value equal to the number of all the characters currently stored within a string.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string str = "12345";
    int pos = 1;

    cout << "Original string: " << str << endl;
    /*
    Note that the substr function returns a string. This means that the resulting string retains all its original 
    traits and therefore has its own member functions like substr() or size().
    */
    cout << "str.substr(1).substr(1).substr(1).size() = " << str.substr(pos).substr(pos).substr(pos).size() << endl;

    askOS();
    return 0;
}

/*
Output:

Original string: 12345
str.substr(1).substr(1).substr(1).size() = 2
*/