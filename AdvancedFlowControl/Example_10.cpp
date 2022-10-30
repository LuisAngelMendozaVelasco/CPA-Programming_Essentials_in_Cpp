/*The shift operators in the C++ language are a pair of digraphs, << and >>, clearly suggesting in which direction the shift will act. 
The left argument of these operators is the integer value whose bits are shifted. The right argument determines the size of the shift. */

#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    int w_sign = -8;
    unsigned wo_sign = 4; // only represent non-negative integer numbers (positive numbers and zero)

    int var_s;
    unsigned var_u;

    /* equivalent to division by 2 –> var_s == -4 */
    var_s = w_sign >> 1;
    cout << var_s << endl;

    /* equivalent to multiplication by 4 –> var_s == -32 */
    var_s = w_sign << 2;
    cout << var_s << endl;

    /* equivalent to division by 4 –> var_u == 1 */
    var_u = wo_sign >> 2;
    cout << var_u << endl;

    /* equivalent to multiplication by 2 –> var_u == 2 */
    var_u = wo_sign << 1;
    cout << var_u << endl;

    askOS();
    return 0;
}