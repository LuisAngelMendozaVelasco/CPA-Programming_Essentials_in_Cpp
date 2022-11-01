/*Explicit conversions

In general, the C++ language give us three ways to specify explicit conversions:
* the so-called functional notation, which is a native (but currently obsoleted) C++ syntax convention 
(named because of its similarity to the well-known function invocation); in this case the name of a new (target) 
type is treated like a function and the conversion takes the following form:
    new_type_name(expression_of_old_type)

* the so-called C-style casting (named after the C++ predecessor, the C programming language, 
which used, and still uses, a syntax of that kind); in this case, we specify the conversion in the following form:
    (new_type_name) expression_of_old_type

* the so-called static casting, a native and currently recognized as recommended C++ syntax convention 
where the conversion is done by an operator named static_cast; the operator takes the following form:
    static_cast<new_type_name>(expression_of_old_type)*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    float f = 3.21;
    double d = 1.23;
    long double l = 9.87;

    /*int(f) -> functional notation
    (int)d -> C-style casting
    static_cast<int>(l) -> static casting*/
    int k = int(f) + (int)d + static_cast<int>(l);

    cout << "int(3.21) + (int)1.23 + static_cast<int>(9.87) = " << k;

    askOS();
    return 0;
}