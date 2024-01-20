//////////////////////////
// Stack implementation //
//////////////////////////

#include "mystack.h"

stack_size_error::stack_size_error(const std::string &msg) : std::length_error(msg) { };

stack_bad_alloc::stack_bad_alloc(const std::string &msg) : std::bad_alloc() { };

stack_overflow::stack_overflow(const std::string &msg) : std::logic_error(msg) { };

stack_empty::stack_empty(const std::string &msg) : std::logic_error(msg) { };

/* 
Constructor
We’ve got two important things to do:
    * Check whether the initial stack size isn’t too low and will throw an exception in such a case.
    * Try to allocate memory for the stack and check if it was successful; we’re going to re-throw our own exception in such a case.
*/
Stack::Stack(int size)
{ 
    if(size <= 0)
        throw stack_size_error("stack size must be >= 0");

    try {
        stackstore = new int[size];
    }
    catch(std::bad_alloc &ba) {
        throw stack_bad_alloc("stack allocation error");
    }
    
    stacksize = size;
    SP = 0;
}

Stack::~Stack()
{
    delete [] stackstore;
}

// We need to check if the SP hasn’t exceeded its maximum allowable value (stacksize – 1) and we’ll throw an event in such a case.
void Stack::push(int value)
{
    if(SP == stacksize)
        throw stack_overflow("stack size exceeded");
    stackstore[SP++] = value;
}

// We need to check if the SP is not zero and we’ll throw an event in such a case.
int Stack::pop()
{ 
    if(SP == 0)
        throw stack_empty("stack is empty");
    return stackstore[--SP]; 
}

/*
Output:


*/