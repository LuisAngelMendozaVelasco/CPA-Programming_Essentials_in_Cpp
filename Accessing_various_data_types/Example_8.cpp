////////////////////////////////////
// Conversions – gains and losses //
////////////////////////////////////

/*
When one int and one short are used in the same expression, we can expect that the value of the narrower range (short) 
will be promoted to the type with the wider range (int) and there won’t be any loss of value.
Similarly, when a float meets a double in the same expression, the float will be promoted to a double.

*/
#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    int Int = 2;
    char Char = 3;
    short Short = 4;
    float Float = 5.6;

    /*
    We can predict that the following implicit conversions will take place:
        * promotions go first, resulting in the following conversions:
            int(Short) + int(Char)

        * the sum of Short and Char as well as the Float variable will be converted to double, that is:
            double((int(Short) + int(Char)) + double(Float))

        * the final sum will be calculated as a double, but because of the context (arising from the type of the left argument of the = operator) 
          which is int, another conversion into an int type takes place; hence, the final form of the expression looks like this:
            int(double((int(Short) + int(Char)) + double(Float)))
    */
    Int = Short + Char + Float;
    cout << "Short + Char + Float: " << Int << endl;

    askOS();
    return 0;
}

/*
Output:

Short + Char + Float: 12
*/