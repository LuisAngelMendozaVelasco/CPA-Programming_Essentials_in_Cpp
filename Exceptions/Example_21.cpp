/* 
When the exception arrives at a set of catch branches, the first compatible branch is chosen (and only this one) as a target handler.
This means that when a more general type/class is placed before the more specific compatible type/class, the second branch will receive no exceptions at all.
This is why the compiler warns us that the order of the catch branches is risky and some of the branches may be permanently omitted in the process of selecting the exception handler.
This is also why the branch with the exception class hides all the subsequence branches with types derived from the exception class.
Additionally, we’re not allowed to specify more than one branch with the same exception type/class. The compiler will treat this as an error.
The code shows us what happens when not all the exceptions find their handler.
*/

#include<iostream> 
#include "../myFunctions.h"
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        /* 
        The exception carried by the string type exception is, in a certain sense, orphaned: there’s no catch branch wanting to receive it. 
        It causes some alarming system messages and our program will terminate abnormally. We should expect this type of behaviour every time an unhandled exception 
        reaches the highest level of the program.
        */
        case 4: throw "so bad";
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            function(i);
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
    }

    askOS();
    return 0;
}

/*
Output:

Exception: 0
Exception: 1
Exception: std::exception
Exception: 2
terminate called after throwing an instance of 'char const*'
Aborted
*/