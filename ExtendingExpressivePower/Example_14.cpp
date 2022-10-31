#include <iostream>
#include "../myFunctions.h"

using namespace std;

void new_greet(string greet, int repeats)
{
    for (int i = 0; i < repeats; i++)
        if (i < repeats - 1)
            cout << greet << endl;
        else
            cout << greet;
}

int main() 
{
    new_greet("Hi!", 5);

    askOS();
    return 0;
}