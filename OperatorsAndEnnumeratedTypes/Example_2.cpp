/* Improving the << operator

There are two different ways of using the “<<” operator: one implemented by us and one we got from the streams library.
Stream operators may be chained like this:
    cout << i << endl;
Our operators aren’t that smart (yet). It’ll provoke a whole load of compilation errors.
The line we is interpreted by the compiler in the following way:
    (cout << i) << endl;
The expression inside the parentheses returns a reference to a stream (namely: the cout stream) so it can be used (reused) as a left argument for the next "<<" in a chain.
We can do the same thing with our stack, but it means that the operator functions may not be void anymore. They have to return a value as a reference 
to the stack object – the same object for which the operators were activated for the first time.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Stack {
private:
    int *stackstore;
    int SP;
public:
    Stack(int size = 100)
    {
        stackstore = new int[size];
        SP = 0;
    }
    ~Stack()
    {
        delete [] stackstore;
    }
    void push(int value)
    {
        stackstore[SP++] = value;
    }
    int pop()
    {
        return stackstore[--SP];
    }
    Stack& operator<< (int v);
    Stack& operator>> (int &v);
};

// The function returns a reference to its maternal object. We use the this pointer for that purpose.
Stack& Stack::operator<< (int v)
{
    push(v);
    return *this;
}

// We improve the “>>” operator in the same way.
Stack& Stack::operator>> (int &v)
{
    v = pop();
    return *this;
}

int main()
{
    int i = 2, j;
    Stack stk;

    stk << 1 << 2 * i;
    stk >> j >> i;
    cout << "push(): " << j << endl << "push(): " << i << endl;

    askOS();
    return 0; 
}