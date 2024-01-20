/////////////////
// Stack again //
/////////////////

/*
We’ve introduced two important amendments compared to its previous incarnations:
the values stored in the stack are still located inside an array, but the size of the array is defined dynamically by the constructor; note the default stack size specification
as a consequence of the previous modification, we’ve had to add a destructor responsible for removing the array at the end of the stack’s life
A very simple main function proves that the stack behaves correctly.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Stack {
    private:
        int *stackstore;
        int stacksize;
        int SP;
        
    public:
        Stack(int size = 100);
        ~Stack();
        void push(int value);
        int pop();
};

Stack::Stack(int size)
{ 
    stackstore = new int[size];
    stacksize = size;
    SP = 0;
}

Stack::~Stack()
{
    delete [] stackstore;
}

void Stack::push(int value)
{
    stackstore[SP++] = value;
}

int Stack::pop()
{ 
    return stackstore[--SP]; 
}

int main()
{
    Stack stk;

    stk.push(1);
    cout << "stk.pop(): " << stk.pop() << endl;

    askOS();
    return 0;
}

/*
Output:

stk.pop(): 1
*/