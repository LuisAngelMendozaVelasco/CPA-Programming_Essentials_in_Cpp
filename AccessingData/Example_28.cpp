/* Assigning a (sub)string or a character

The assign member function does a job which is very similar to the insert’s job, but does not 
retain the previous string content, and instead just replaces it with a new one. 
The assign() is as universal as the insert() or append() functions and so is more convenient 
in some specific applications.*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string sky;

    sky.assign(80, '*'); // Set value to multiple characters.
    cout << sky;

    askOS();
    return 0;  
}