////////////////////////////////////////
// An indexing operator for the stack //
////////////////////////////////////////

/*
We’ll redefine the meaning of the indexing operator.
From a certain point of view, a stack is an array – a very specific one, but still an array.
We want the indexing to work in this odd way:
    Stack[0] returns a reference to the element lying at the top of the stack
    Stack[-1] returns a reference to the element lying below the top of the stack
This is a reference, not a value, as we want to use the operator inside l-value expressions, e.g. as a left argument of the assignment operator.
*/

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

/* 
The function returns a value of type int& as the stack’s element type is int.
The function has one argument – the index; we pass it by value as the array index doesn’t need to be a variable – it may be an expression too.
*/
int& Stack::operator[] (int index)
{
    // An attempt to reach for a non-existent stack element will cause an exception to be thrown. It seems that the std::range_error is the best candidate for this purpose.
    if(index > 0 || index <= -SP)
        throw std::range_error("out of stack");
    return stackstore[SP + index - 1];
}

Stack& operator<< (Stack &s, int v)
{
    s.push(v);
    return s;
}

Stack& operator>> (Stack &s, int &v)
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

/*
Output:

stk[0]: 4
stk[1]: 1
stk[1]: 0
stk[0]: 0
*/