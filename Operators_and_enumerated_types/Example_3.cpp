/* 
Implementing overloaded operators as member functions is easy when we’re the “owner” of the class and we can modify its source code in any way. It may be impossible 
when the source code is unavailable. In many cases it may be possible to write our own subclass containing all the desired operators, but this may be inconvenient in some cases.
Fortunately, we’re allowed to write operator functions outside any class – using both kinds of operators is the same, and when we use an overloaded operator without knowing 
its implementation, we’re not able to guess which of the methods has been used.
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
};

/* 
A standalone operator function must have two arguments and the order of the arguments reflects the order of the operator’s arguments.
Not all operators may be overloaded in this way!
*/
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
    stk >> j >> i;
    cout << "push(): " << j << endl << "push(): " << i << endl;

    askOS();
    return 0; 
}

/*
Output:

push(): 4
push(): 1
*/