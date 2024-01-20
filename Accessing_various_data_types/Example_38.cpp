///////////////////////////
// An unnamed name space //
///////////////////////////

/*
We may define a name space without a name (an anonymous namespace).
This kind of namespace is implicitly and automatically used in a source file where its definition is visible. 
It's another way of introducing entities (e.g. variables) accessible through the whole source file.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

namespace {
    int troll = 1;
    float wizard = -0.5;
}

namespace Mordor {
    int troll = 2;
    float wizard = 0.5;
}

int main() 
{
    cout << "troll = " << troll << ", wizard = " << wizard << endl;
    cout << "Mordor::troll = " << Mordor::troll << ", Mordor::wizard = " << Mordor::wizard << endl;

    askOS();
    return 0; 
}

/*
Output:

troll = 1, wizard = -0.5
Mordor::troll = 2, Mordor::wizard = 0.5
*/