/////////////////
// Name spaces //
/////////////////

/*
We've qualified all the ambiguous names with a prefix consisting of the home name space (std) and a special operator written as “::”.
The operator's official name is “scope resolution operator”. It has some more applications, not only qualifying names with their home name spaces; 
hence its name refers to more general concepts.
A qualifying act like this is an alternative (explicite) way of using the “using namespace” statement.
*/

#include <iostream>
#include "../myFunctions.h"

int main() 
{
    std::cout << "Play as time goes by" << std::endl;

    askOS();
    return 0; 
}

/*
Output:

Play as time goes by
*/