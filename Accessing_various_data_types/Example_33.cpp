///////////////////////////
// Defining a name space //
///////////////////////////

/*
We want to use trolls (two, to be precise) in our software. We’re going to take one from Hogwarts and one from Mordor.
We have to create two different name spaces and to bind the trolls to their origins. Defining a name space looks like this:
    namespace the_name_of_the_space {}
Any entity declared inside a namespace (between its opening and closing brackets) will be bound to this namespace and therefore, 
logically separated from any other entity with the same name.

Let’s assume that two independent programmers have implemented different parts of a very complex system. 
We cannot guarantee that all the names they’ve used are pairwise different. Such a requirement would be impractical and difficult to enforce 
(developers would have to agree on every new name introduced to their codes). It’s easier to assume that all their entities 
(e.g. variables and functions) are bound to (or rather enclosed inside) different name spaces named after the developer’s given names or their nicknames.
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

int main() 
{
    cout << "Hogwarts::troll: " << Hogwarts::troll << endl << "Mordor::troll: " << Mordor::troll << endl;

    askOS();
    return 0; 
}

/*
Output:

Hogwarts::troll: 1
Mordor::troll: 2
*/