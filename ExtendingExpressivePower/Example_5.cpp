/*It is possible to place the square function 
after the main function and not before*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

// Have to put the function declaration before the first function invocation
float square(float);

int main() 
{
    float arg = 2.0;

    cout << "The second power of " << arg << " is " << square(arg);
    
    askOS();
    return 0;
}

float square(float x) 
{
    float result = x * x;

    return result;
}