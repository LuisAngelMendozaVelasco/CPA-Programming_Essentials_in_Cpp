/* Header file for stack

We’ve named it mystack.h. We’ve assumed that the file with all required definitions will be named mystack.cpp.

A file containing all the necessary declarations. The file can be included by any other source file making use of our newly built stack.
The header doesn’t contain any definitions, usually, as they aren’t needed during the compilation phase.

The #ifdef directive is used by a pre-processor to check if the compile-time symbol is defined or not. In our example the checked symbol is named __MYSTACK__. 
It’s essential to choose a name unique to the specific project. Usually the name derives from the header name itself, and we’ve followed that convention here.
If the symbol is not defined (ndef), the pre-processor will analyse the rest of the file, or skip it otherwise. 
Note that it doesn't skip the entire file content, but only the part nested between the #ifndef and #endif directives.
The next directive, #define, defines the __MYSTACK__ symbol. when the header file is included for the first time, it’s parsed as a whole, and every line is taken into consideration.
During the second and subsequent inclusions, its content is ignored because the pre-processor knows that the __MYSTACK__ has already been defined. This simple trick 
speeds up the compilation process and helps the pre-processor to avoid unnecessary multiple inclusions of the same header file.*/
#ifndef __MYSTACK__
#define __MYSTACK__

#include <iostream>
#include <exception>
#include <stdexcept>

/* Each of the constructors invokes its base class’s constructor and adds no new functionalities.
The implementation of the stack will change too. We assume that:
    * the constructor throws two exceptions: stack_size_error and stack_bad_alloc
    * the push function throws the stack_overflow exception
    * the pop function throws the stack_empty exception*/
class stack_size_error : public std::length_error {
public:
    explicit stack_size_error(const std::string &msg);
};

class stack_bad_alloc : public std::bad_alloc {
public:
    explicit stack_bad_alloc(const std::string &msg);
};

class stack_overflow : public std::logic_error {
public:
    explicit stack_overflow(const std::string &msg);
};

class stack_empty : public std::logic_error {
public:
    explicit stack_empty(const std::string &msg);
};

class Stack {
private:
    int *stackstore;
    int stacksize;
    int SP;
public:
    Stack(int size = 100);
    ~Stack();
    void push(int value);
    int pop();
};
#endif