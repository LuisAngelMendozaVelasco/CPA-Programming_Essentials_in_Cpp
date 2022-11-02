/*Using an entity

There’s another form of statement that allows us to selectively decide which entities should be used and which should remain hidden inside the space. 
But there’s one important condition: none of the statements used may cause ambiguity in the process of identifying all the entities used in your code.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

namespace Hogwarts {
    int Troll = 1;
    float Wizard = -0.5;
}

namespace Mordor {
    int Troll = 2 ;
    float Wizard = 0.5;
}

using Mordor::Troll;
using Hogwarts::Wizard;

int main() 
{
    cout << "Hogwarts::Troll = " << Hogwarts::Troll << ", Wizard Hogwarts = " << Wizard << endl;
    cout << "Troll Mordor = " << Troll << ", Mordor::Wizard = " << Mordor::Wizard;

    askOS();
    return 0; 
}
