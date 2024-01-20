////////////////////////////////////
// Control the size of the string //
////////////////////////////////////

/*
It isn't possible to implement even the simplest cipher code without being able to 
analyse and modify every single char of any string.
strings aren't vectors, but they are able to present their content as if it were an actual vector. 
We can assume that it's a kind of very useful masquerade – a string can wear a mask and show itself as an ordinary (well, almost ordinary) vector. 
It allows us to read and write every character separately.
*/

#include <iostream>
#include <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string the_string = "content";

    // It converts its every char to upper case.
    for (int i = 0; i < the_string.length(); i++)
        the_string[i] = the_string[i] - 'a' + 'A';
    cout << the_string << endl;

    askOS();
    return 0;
}

/*
Output:

CONTENT
*/