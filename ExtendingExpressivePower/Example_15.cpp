// Default parameters
#include <iostream>
#include "../myFunctions.h"

using namespace std;

// signal that we want the compiler to assume the default value for the second parameter when we omit it during the invocation
void new_greet(string greet, int repeats = 1)
{
    cout << greet << endl;    
}

int main() 
{
    new_greet("Hello", 2);
    new_greet("Good morning"); // equal to new_greet("Good morning", 1);
    new_greet("Hi", 1);

    askOS();
    return 0;
}