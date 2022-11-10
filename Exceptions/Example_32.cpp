// We’ll check if the constructor properly detects stack size values that are too low
#include "mystack.h"
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main()
{
    try {
        Stack stack(0);
        stack.push(1);
        cout << stack.pop() << endl;
    }
    catch(stack_bad_alloc &sba) {
        cout << "No room for the stack - sorry!" << endl;
    }
    catch(stack_size_error &sse) {
        cout << "Stacks of that size don't exist - sorry!" << endl;
    }
    catch(stack_overflow &se) {
        cout << "Stack is too small for that many pushes - sorry!" << endl;
    }
    catch(stack_empty &su) {
        cout << "Stack is empty - sorry!" << endl;
    }
    catch(...) {
        cout << "I don't know what I'm doing";
    }

    askOS();
    return 0;
}