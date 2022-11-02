/* Renaming a name space

It may happen that one of the name spaces you have or want to use has an inconvenient name (for any reason). 
We can rename it locally i.e. it’ll be recognized under its new name only in the source file where the act of renaming has occurred.
We can use it with a special form of the namespace statement – here it is:
    namespace new_name = old_name;
The new name of the name space may be used together with the old one. This means that the renaming is actually aliasing, since both of the names are still valid.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

namespace what_a_wonderful_place_for_a_young_sorcerer {
    int troll = 1;
    float wizard = -0.5;
}

namespace Mordor {
    int troll = 2;
    float wizard = 0.5;
}

namespace Hogwarts = what_a_wonderful_place_for_a_young_sorcerer;

int main() 
{
    cout << "Hogwarts::troll = " << Hogwarts::troll << ", what_a_wonderful_place_for_a_young_sorcerer::wizard = " <<
        what_a_wonderful_place_for_a_young_sorcerer::wizard << endl;
    cout << "Mordor::troll = " << Mordor::troll << ", Mordor::wizard = " << Mordor::wizard;

    askOS();
    return 0; 
}