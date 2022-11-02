/* Using a name space

If the using namespace statement is placed inside a block, its scope ends in the same place where the block ends. 
We can use this effect to selectively use (and disuse) any of the available namespaces.*/
#include <iostream>
#include "../myFunctions.h"

// The std name space is used globally (in the whole source file)
using namespace std;

namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

int main() 
{
    // The Hogwarts and Mordor name spaces are used selectively (in the selected parts of the code)
    {
        using namespace Hogwarts;
        cout << "troll Hogwarts= " << troll;
    } 

    {
        using namespace Mordor;
        cout << ", troll Mordor = " << troll;
    }

    askOS();
    return 0; 
}