// Stack class
#include <iostream>
#include "../myFunctions.h"

using namespace std;

// We’ll use a vector as the stack’s storage and we’ll use an int variable as the stack pointer. We only have to place the two of them into the class.
class Stack {
/* We wanted to encapsulate both variables and make them inaccessible from the outside world.
This kind of data is called private in object programming. It’s private because only the class itself may access and modify it.
If we want to mark some part of a class’s data as private, we have to add the keyword before the declarations.*/
private:
    int stackstore[100];
    int SP;
/* Components accessible to every class’s user (in contrast to the previously declared variables which are hidden from an ordinary class’s users). 
This type of component is called "public" and we have to use a keyword to emphasize this fact.*/
public:
    /* A “constructor” is responsible for the proper construction of each new object of the class.
    It must be named the same as its home class. Constructors aren’t real functions. They don’t have any return type – not even void.*/
    Stack() 
    { 
        SP = 0; 
    }

    /* Two functions that implement push and pop operations. The C++ language assumes that a function of this kind (being a class activity) 
    may be described in two different way:
    * inside the class, when the class body contains a full implementation of the method
    * outside the class, when the body contains only the function header; the function body is placed outside the class
    Both functions access the class variables (namely the stackstore and SP) without any obstacles. a class’s components are fully 
    visible to other components of the same class.*/
    void push(int value); // function outside the class
    int pop()  // function inside the class body
    {
        return stackstore[--SP];
    }
};

/* The functions implementing the class’ activities and placed outside the class body need to be described in a very specific way. 
Their names should be qualified using the home class name and the “::” operator.*/
void Stack::push(int value) 
{
    stackstore[SP++] = value;
}

int main() 
{
    Stack little_stack, another_stack, funny_stack;

    little_stack.push(1);
    another_stack.push(little_stack.pop() + 1);
    funny_stack.push(another_stack.pop() + 2);
    cout << funny_stack.pop();

    askOS();
    return 0; 
}