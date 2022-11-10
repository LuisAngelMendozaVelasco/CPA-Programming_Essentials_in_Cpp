/* An indexing operator for the stack

We’ll redefine the meaning of the indexing operator.
From a certain point of view, a stack is an array – a very specific one, but still an array.
We want the indexing to work in this odd way:
    Stack[0] returns a reference to the element lying at the top of the stack
    Stack[-1] returns a reference to the element lying below the top of the stack*/
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
    int& operator[](int index);
};

int& Stack::operator[] (int index)
{
    if(index > 0 || index <= -SP)
        throw std::range_error("out of stack");
    return stackstore[SP + index - 1];
}

Stack& operator<< (Stack &s, int v)
{
    s.push(v);
    return s;
}

Stack& operator>>(Stack &s, int &v)
{
    v = s.pop();
    return s;
}

int main()
{
    int i = 2, j;
    Stack stk;

    stk << 1 << 2 * i;
    cout << "stk[0]: " << stk[0] << endl << "stk[1]: " << stk[-1] << endl;
    stk[0] = stk[-1] = 0;
    stk >> i >> j;
    cout << "stk[1]: " << i << endl << "stk[0]: " << j << endl;

    askOS();
    return 0; 
}