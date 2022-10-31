/* Local and global variables

Local variable:
Any variable defined inside the function's body can be neither used nor accessed from outside the function. 
We can say that variables are isolated from the outer world. 
Moreover, such variables exist only when the function is executed and disappear when the function completes its execution. 
This means they cannot be used to store value between function invocations.

Global variable:
They are declared outside any function and thus are accessible for all the functions declared in the same source file.
Note that the variable declaration has to precede the function definition in order to be recognizable by the function.
Global variables allow functions to get and to provide data of any kind. If a function modifies any global variable that 
isn’t using any other mechanism of transferring data, we say that this function has a side effect.
*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int globvar = 0;

void func() 
{
    cout << "Thank you for invoking me :)" << endl;
    globvar++;
}

int main() 
{
    for (int i = 0; i < 5; i++)
        func();

    cout << endl << "The function was happy " << globvar << " times";

    askOS();
    return 0;
}