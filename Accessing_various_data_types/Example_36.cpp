////////////////////////////
// Expanding a name space //
////////////////////////////

/*
Let's assume that all the name space definitions that use the same identifier are “glued” together and build one, larger name space together. 
Note that each extension may be placed inside a separate source file. 
This means that any of the name spaces may be dispersed among many source files created by different developers.
Note that the first appearance of a name space is called “an original name space”. Any name space with the same name (identifier) that 
appears after the original name space is called “an extension name space”. There may be more than one extension of a name space.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

namespace Hogwarts {
    float wizard = -0.5;
}

namespace Mordor {
    float wizard = 0.5;
}

int main() 
{
    cout << "Hogwarts::troll = " << Hogwarts::troll << ", Hogwarts::wizard = " << Hogwarts::wizard << endl;
    cout << "Mordor::troll = "  << Mordor::troll << ", Mordor::wizard = " << Mordor::wizard << endl;

    askOS();
    return 0; 
}

/*
Output:

Hogwarts::troll = 1, Hogwarts::wizard = -0.5
Mordor::troll = 2, Mordor::wizard = 0.5
*/