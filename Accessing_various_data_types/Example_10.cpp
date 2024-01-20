/////////////////////////
// String operators: + //
/////////////////////////

/*
The + (concatenation) operator has one important limitation. It cannot concatenate literals. 
It can concatenate any variable with a literal, a literal with a variable, and obviously a variable with another variable, 
but concatenating literals is something the operator will never do.
*/

#include  <iostream>
#include  <string>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    string s;

    // s = "A" + "B";
    s = s + "C"; // Variable with a literal
    s = "B" + s; // Literal with a variable
    cout << "Concatenated string: " << s << endl;

    askOS();
    return 0;
}

/*
Output:

Concatenated string: BC
*/