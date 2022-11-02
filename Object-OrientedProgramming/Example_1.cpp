/* Stack

It's a structure developed to store data in a very specific way. Imagine a stack. A stack of coins would be best here. 
You can’t put a coin anywhere else but on the top of the stack. Similarly, you can’t get a coin off the stack from anywhere other than the stack’s top. 
If you want to get the coin on the bottom, you have to remove all the coins that are sitting on top of it.
The alternative name for a stack (but only in IT terminology, of course) is LIFO. This is an abbreviation for a description of the stack’s behaviour: 
"Last In - First Out". The coin that goes onto the stack last comes off first.
A stack is an object to two elementary operations conventionally named "push" (when a new element is placed on the top) and 
"pop" (when an existing element is taken away from the top).*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

/* Use a vector for this job. We assume (somewhat recklessly) that there’ll be no more than 100 values on the stack at the same time. 
We also assume that the element at index 0 is at the bottom of the stack.*/
int stack[100];
/* We need a variable that can be responsible for storing a number of elements currently stored on the stack. 
This variable is generally called a “stack pointer”, or SP for short.
Initially, the stack is empty, so the stack pointer should be assigned the value of 0.*/
int SP = 0;

/* Function that places a value onto the stack:
* the name for the function is "push"
* the function gets one argument of type int (this is the value to be placed onto the stack)
* the function returns nothing
* the function places the argument value into the first free element in the vector and increments the SP*/
void push(int value) // The function doesn’t check if there’s room for the new value.
{
    cout << "stack [" << SP << "] = " << value << endl;
    stack[SP++] = value;
}

/* Function to take a value off the stack:
* the name for the function is "pop" (we don’t want to discover America again)
* the function doesn’t have any arguments
* the function reads the value from the stack’s top and decrements SP
* the function returns the value taken from the stack*/
int pop()  // The function doesn’t check if there’s any element on the stack
{
    cout << "pop() stack = ";
    return stack[--SP];
}

int main() 
{
    push(3);
    push(2);
    push(1);
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop();

    askOS();
    return 0; 
}