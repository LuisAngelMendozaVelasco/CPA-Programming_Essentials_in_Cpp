////////////////////////
// Default parameters //
////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// Signal that we want the compiler to assume the default value for the second parameter when we omit it during the invocation.
void new_greet(string greet, int repeats = 1)
{
    for (int i = 0; i < repeats; i++)
        cout << greet << endl;    
}

int main() 
{
    new_greet("Hello", 2);
    new_greet("Good morning"); // Equal to new_greet("Good morning", 1);
    new_greet("Hi", 1);

    askOS();
    return 0;
}

/*
Output:

Hello
Hello
Good morning
Hi
*/