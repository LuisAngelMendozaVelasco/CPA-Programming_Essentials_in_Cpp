///////////////////////////
// Erasing a (sub)string //
///////////////////////////

/*
We can also remove a part of a string, making the string shorter than before. We can do this by using a member function called erase() 
and the function requires two numbers in order to perform its duty:
    * the place where the substring to be removed starts (this value defaults to zero);
    * the length of the substring (this value defaults to the original string’s length).
This means that an invocation like this:
    the_string.erase();
erases all the characters from the string and leaves it empty.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string where_are_we = "I've got a feeling we're not in Kansas anymore";
    cout << "Original string: " << where_are_we << endl;

    where_are_we.erase(38, 8).erase(25, 4); // Remove characters.
    cout << "Modified string: " << where_are_we << endl;

    askOS();
    return 0;  
}

/*
Output:

Original string: I've got a feeling we're not in Kansas anymore
Modified string: I've got a feeling we're in Kansas
*/