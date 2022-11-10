/* Implementing the << operator

We’ll define an operator function for the “<<” operator (the new face of the push member function).
We’ll add a new method of declaration into the header file – this is what it looks like:
    void operator << (int v);
Note:
    * the operator must accept different forms of its arguments, like:
        * variable, e.g,
        * stack << VAR;
        * expression, e.g,
        * stack << 2 * VAR;
        * literal, e.g,
        * stack << 2;
        * etc
    this means that the corresponding parameter of the operator function must be passed by value
    * the operator may throw an exceptions just like an ordinary member function
    * we’ve declared the operator function as void, as we don’t want the operator to evaluate any new values*/
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
    void operator<< (int v);
};

/* The object of the class is the first of the operator’s arguments (the left one, to be precise) so we have nothing more to do except invoke the push() method 
with a value from the second (right) operator’s argument.
Despite these reservations, the function behaves quite normally and all the general rules referring to functions are obeyed.
The new operator works equally well with literals, expressions and variables.*/
void Stack::operator<< (int v)
{
    push(v);
}

int main()
{
    int i = 2;
    Stack stk;

    stk << 1;
    stk << 2 * i;
    stk << i;
    cout << "stk.pop(): " << stk.pop() << endl;
    cout << "stk.pop(): " << stk.pop() << endl;
    cout << "stk.pop(): " << stk.pop() << endl;

    askOS();
    return 0; 
}