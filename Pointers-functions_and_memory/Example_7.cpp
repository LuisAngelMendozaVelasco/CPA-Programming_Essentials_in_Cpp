///////////////////////////////////////////////////////
// Converting temperature from Fahrenheit to Celsius //
///////////////////////////////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

float fahrenheit_to_celsius(float temp) 
{
    return ((temp - 32.0) * 5.0) / 9.0;
}

void test_the_function(float temp) 
{
    cout << "Fahrenheit " << temp << " corresponds to " <<	fahrenheit_to_celsius(temp) << " Celcius" << endl;
}

int main() 
{
    test_the_function(32.0);
    test_the_function(212.0);
    test_the_function(451.0);

    askOS();
    return 0;
}

/*
Output:

Fahrenheit 32 corresponds to 0 Celcius
Fahrenheit 212 corresponds to 100 Celcius
Fahrenheit 451 corresponds to 232.778 Celcius
*/