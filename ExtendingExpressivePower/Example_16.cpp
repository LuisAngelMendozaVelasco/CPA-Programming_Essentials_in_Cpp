/* Default parameters

This mechanism is useful, but to take full advantage of it you mustn’t forget about the following limitations:
* the order of parameters is very important (in contrast to regular, non-default parameters which may be in virtually any order); 
intuitively, we can say that non-default parameters must be coded before the default ones; the compiler won't be able to identify the parameters otherwise;
* if more than one parameter is declared with a default value and at least one argument is specified in the invocation, 
the arguments are assigned to their parameter counterparts in the same order in which they are listed in the function declaration; 
this means that you are not allowed to use the default value for the first parameter and specify an explicit value for the second.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

// more than one default parameter in one function
void new_greet(string greet = "Good morning", int repeats = 1) 
{
    for (int i = 0; i < repeats; i++)
        cout << greet << endl;
}

int main(void) {
    new_greet("Hello", 2);
    new_greet("Hi");
    new_greet();

    askOS();
    return 0;
}