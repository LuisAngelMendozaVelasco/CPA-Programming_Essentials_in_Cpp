#include <iostream>
#include "../myFunctions.h"
using namespace std;

void new_greet(string greet, int repeats)
{
    for (int i = 0; i < repeats; i++)
        cout << greet << endl;
}

int main() 
{
    new_greet("Hi!", 5);

    askOS();
    return 0;
}

/*
Output:

Hi!
Hi!
Hi!
Hi!
Hi!
*/