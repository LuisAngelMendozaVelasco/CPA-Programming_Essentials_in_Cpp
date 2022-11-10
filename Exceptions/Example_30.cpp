/* Stack main function

#include "mystack.h" -> This is how the compiler learns about the stack and all of its components, as well as the exceptions we’ve jointly defined.
The compilation process should look as follows:
    * The compiler compiles the “mystack.cpp” file and produces an object file (its name may be different on different platforms – some compilers may use “mystack.o”, 
    others “mystack.obj” – don’t be surprised).
    * The compiler compiles the “main.cpp” file and produces an object file of a name, e.g. “main.obj”
    * The linker links both files, adding a code taken from standard libraries, and produces an executable file in the end.*/
#include "mystack.h"
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main()
{
    Stack stack;
    stack.push(1);
    cout << stack.pop() << endl;

    askOS();
    return 0;
}