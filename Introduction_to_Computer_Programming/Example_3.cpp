#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    char character = 'X', minus = '-';
    float floating = 2.5;

    /*
    In general, output streams (including cout) are able to recognize the type of the printed value and act accordingly 
    i.e. they’ll use a proper form of data presentation for char and float values.
    */
    cout << character << minus << floating << endl;

    askOS();
    return 0;
}

/*
Output:

X-2.5
*/