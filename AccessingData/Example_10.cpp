/* String operators: +

The + (concatenation) operator has one important limitation. It cannot concatenate literals. 
It can concatenate any variable with a literal, a literal with a variable, and obviously a variable with another variable, 
but concatenating literals is something the operator will never do*/
#include  <iostream>
#include  <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string s;

    // s = "A" + "B";
    s = s + "C"; // variable with a literal
    s = "B" + s; // literal with a variable
    cout << "Concatenated string: " << s;

    askOS();
    return 0;
}