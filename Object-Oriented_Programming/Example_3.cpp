////////////////////
// Stack subclass //
////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Stack {
    private:
        int stackstore[100];
        int SP;

    public:
        Stack() 
        { 
            SP = 0; 
        }

        void push(int value);

        int pop() 
        {
            return stackstore[--SP];
        }
};

void Stack::push(int value) 
{
    stackstore[SP++] = value;
}

/* 
We want a new class not only to handle stacks but we also want it to be able to evaluate a sum of all the elements currently stored on the stack.
Moreover, we don’t want to modify the previously defined stack. It’s good enough as it is, and we don’t want to change it in any way. 
We want a new stack with new capabilities. In other words, we want to construct a subclass of the Stack class.
We’ll just define a new subclass pointing out the class to be used as a superclass.
It derives all the components defined by its superclass – the name of the superclass is written after the colon directly after the new class name.
Any object of the AddingStack class can do everything that each Stack class’ object does.
*/
class AddingStack : Stack {
    /* 
    We add a new variable to the class. It’ll be a private variable. 
    We don’t want anybody to manipulate the sum value.
    */
    private:
        int sum;
    public:
        /* 
        We’re going to change the functionality of the functions, not their names. We can say more precisely that the interface of the class 
        remains the same when we change the implementation at the same time.
        */
        AddingStack();
        void push(int value);
        int pop();  
        int get_sum();
};

/* 
When we create the AddingStack class object, we should take care of the superclass initialisations, too. 
The phrase : Stack() is a request to invoke the superclass constructor before the current constructor starts its work.
*/
AddingStack::AddingStack() : Stack() 
{
    sum = 0;
}

void AddingStack::push(int value)
{
    sum += value; // add the value to the sum variable
    /* 
    We don’t need to define the operation of pushing the value onto the stack once again. The implementation for that activity is implemented 
    inside the Stack class. The only thing we need to do is to use it, but we must clearly indicate the class containing the function to avoid 
    confusing it with any other function of the same name. This is why we have to put the Stack:: prefix in front of the invocation.
    */
    Stack::push(value); // push the value onto the stack
}

int AddingStack::pop() 
{
    int val = Stack::pop();
    sum -= val;
    return val;
}

// Its only task is to return the sum value. We reveal it, but do it in a way that still protects it from modification.
int AddingStack::get_sum() 
{
    return sum;
}

int main() 
{
    AddingStack super_stack;

    cout << "stack = [";
    for(int i = 1; i < 10; i++) {
        if (i < 9)
            cout << i << ", ";
        else
            cout << i << "]" << endl;
        super_stack.push(i);
    }

    cout << "Sum stack = " << super_stack.get_sum() << endl;

    for(int i = 1; i < 10; i++)
        super_stack.pop();
        
    cout << "Sum empty stack = " << super_stack.get_sum() << endl;

    askOS();
    return 0; 
}

/*
Output:

stack = [1, 2, 3, 4, 5, 6, 7, 8, 9]
Sum stack = 45
Sum empty stack = 0
*/