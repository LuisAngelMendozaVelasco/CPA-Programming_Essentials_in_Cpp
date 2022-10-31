// Functions

#include <iostream>
#include "../myFunctions.h"

using namespace std;

/*The parameters defined within the function are called formal parameters. 
The values actually transferred to the function (thus existing outside the function) 
are called actual parameters or arguments.*/
float square(float x) 
{
    float result = x * x;

    return result;
}

int main() 
{
    float arg = 2.0;

    cout << "The second power of " << arg << " is " << square(arg);

    askOS();
    return 0;
}