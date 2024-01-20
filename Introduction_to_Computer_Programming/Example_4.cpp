#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    char character = 'X';
    int integer = character; // ASCII code is placed inside an int variable

    /*
    cout is able to recognize the actual type of its element even when it is an effect of a 
    conversion (an phenomenon which occurs when data is subject to type change).
    */
    cout << character << " " << static_cast<int>(character) << endl;
    cout << integer << " " << static_cast<char>(integer) << endl;

    askOS();
    return 0;
}

/*
Output:

X 88
88 X
*/