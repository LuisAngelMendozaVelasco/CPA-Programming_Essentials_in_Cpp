/* In a funtion the parameter's value doesn't replace the argument's value upon return from the function. 
We can say that the argument has a one-way ticket: it transports a value to the function and doesn't take it up to the invoker.
Don't forget that. This way of communication is based on transferring a value from the invoker to the function. 
And that’s why this method is called passing parameters by value.
*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

void can_i_change_my_argument(int param)
{
    cout << "----------" << endl;
    cout << "I have got: " << param << endl;
    param++;
    cout << "I'm about to give back: " << param << endl;
    cout << "----------" << endl;
}

int main() 
{
    int var = 1;

    cout << "var = " << var << endl;
    can_i_change_my_argument(var);
    cout << "var = " << var;

    askOS();
    return 0;
}