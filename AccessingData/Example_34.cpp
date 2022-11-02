/* Using a name space

If any of the available name spaces is more usable or preferable, it may be used in a way that suggests that the compiler tries 
to qualify every unqualified name with this/these name space names.
The act of using a selected namespace is carried out by the using namespace statement. If the statement is placed outside any block, 
it affects the code after the statement until the end of the source file.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* Using namespace statements must not lead to a situation where an identifier could be considered to have originated from more than one name space.
We’re not allowed to use the following two statements in the same scope (block) of code:
    using namespace Hogwarts;
    using namespace Mordor;*/
namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

using namespace Hogwarts;

int main() 
{
    cout << "troll = " << troll << ", Mordor::troll = " << Mordor::troll;

    askOS();
    return 0; 
}