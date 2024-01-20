/////////////////////////////
// Replacing a (sub)string //
/////////////////////////////

/*
The replace() member function is more subtle. It can replace a part of the string with 
another string or another string’s substring.
The function needs to know which part of the string it’s going to replace and you have 
to specify this by delivering two numbers:
    * the first describing the starting position;
    * the second saying how many characters will be replaced.
The first overloaded function needs a string (as a third parameter) to replace the old content 
(it may be either longer or shorter or equal in size in comparison to the original). 
The second function enables you to specify the substring to be used as a substitution.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string to_do = "I'll think about that in one hour";
    string schedule = "today yesterday tomorrow";

    cout << "First string: " << to_do << endl;
    cout << "Second string: " << schedule << endl;
    to_do.replace(22, 12, schedule, 16, 8);
    cout << "Output string: " << to_do << endl;

    askOS();
    return 0;  
}

/*
Output:

First string: I'll think about that in one hour
Second string: today yesterday tomorrow
Output string: I'll think about that tomorrow
*/