# Exceptions

## Exceptions

Code:

```cpp
/*
If we’re determined to catch any of the flying exceptions, we need to put the catch statement directly after the try statement. There may be more than one catch statement.
Think of the catch statement as an unnamed function with one parameter specifying the desired kind of exceptions to be caught. 
The catch will catch only those exceptions that are compatible with the specified type.
If we write it this way:
    catch(string &anyproblem) { … }
it’ll mean: I want to catch the exceptions which carry strings.
This form:
    catch(exception &otherproblem) { … }
means: I’m going to catch the exceptions carrying objects of the exception class or of any other classes derived from the exception class.
If we want to throw an exception, we have to use the statement of the same name. The throw statement requires data that’ll be “packed” into an exception before its departure.
If we’re going to dispatch an int value, we’ll write something like this:
    throw 911;
If we want to throw an exception equipped with an object of any class, we need to specify the constructor to be invoked to prepare the data, like this:
    throw string("Bye world!");
*/

#include <iostream>
using namespace std;

float div(float a, float b)
{
    // The function will provide a result if the arguments are valid, otherwise it’ll throw an exception containing a complaining string.
    if(b == 0.0)
        throw string("division by zero :(\n");
    return a / b;
}

int main()
{
    float a, b;

    // Notice how the division is tried and how the exception is caught.
    cout << "a: ";

    // On Windows, ctrl-Z tells the terminal application that you're at the end of your input. On Unix systems, it's ctrl-D.
    while(cin >> a) {
        try {
            cout << "b: ";
            cin >> b;
            cout << "a / b = " << div(a, b) << endl << endl;
        } 
        catch (string &problem) {
            cout << "Look what we did, we bad user!" << endl;
            cout << problem << endl;
        }

        cout << "a: ";
    }
    cout << "\nThe End" << endl;

    return 0;
}
```

Output:

```text
a: 1
b: 2
a / b = 0.5

a: 1
b: 0
a / b = Look what we did, we bad user!
division by zero :(

a: 
The End
```

## How are exceptions not caught?

Code:

```cpp
#include <iostream>
using namespace std;

float div(float a, float b)
{
    if(b == 0.0)
        throw string("division by zero :(");
    return a/b;
}

int main() {
    float a, b;

    cout << "a: ";

    // On Windows, ctrl-Z tells the terminal application that you're at the end of your input. On Unix systems, it's ctrl-D.
    while(cin >> a) {
        try {
            cout << "b: ";
            cin >> b;
            cout << div(a, b) << endl << endl;
        } 
        /* 
        We’ve changed the type specification in the catch statement (it was: string &, now it’s int)
        When the second value is zero, the program will be aborted with a message saying that an instance of an unhandled exception has been thrown.
        */
        catch (int problem) {
            cout << "Look what you did, you bad user!" << endl;
            cout << problem << endl;
        }

        cout << "a: ";
    }
    cout << "\nThe End" << endl;

    return 0;
}
```

Output:

```text
a: 1
b: 2
0.5

a: 1
b: 0
terminate called after throwing an instance of 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >'
Aborted
```

## Throw and catch coupled together

Code:

```cpp
#include <iostream>
using namespace std;

// The do_calculations() function contains four “sensible” fragments where an error may occur: they’re connected to divisions which may go wrong sometimes.
float do_calculations(float a, float b, float c, float d)
{
    try {
        float x = 1.;

        /* 
        All these divisions are “protected” by appropriate checks and in case of a wrong argument, an exception is thrown. The exception is “packed” in a box of 
        type string and carries a simple message describing the problem.
        */
		if(a == 0.0)
			throw string("Bad arg a");
		x /= a;

		if(b == 0.0)
			throw string("Bad arg b");
		x /= b;

		if(c == 0.0)
			throw string("Bad arg c");
		x /= c;

		if(d == 0.0)
			throw string("Bad arg d");
        return x / d;
    } 
    /* 
    There’s also one catch branch designed to catch the exception and provide very simple handling. The exception specification placed in the catch branch header
    works like a local (automatic) variable declaration. 
    */
    catch(string &exc) {
        cout << "Something bad happened: " << exc << endl;
        return 0.0;
    }
}

int main()
{
    do_calculations(1, 2, 3, 0);

    return 0;
}
```

Output:

```text
Something bad happened: Bad arg d
```

## Throw and catch separated

Code:

```cpp
/*
The throw and the catch may live separately as well. We can put throw in one function, catch in another, and the mechanism will still work effectively, but of course, 
only when the functions invoke themselves in the proper order.
This means that the exception object is able to fly above the function’s boundaries and can even skip over more than one function in order to find its own catch.
Throw will stay in its home do_calculation() function, while catch will move to the main function. When the throw statement is executed inside the function, 
the function won’t be able to return any useful value. This isn’t a problem as the function isn’t going return to the place where the result may be used 
in any meaningful way. The link between the function and the invocation is irretrievably broken when the throw processing starts.
*/

#include <iostream>
using namespace std;

float do_calculations(float a, float b, float c, float d)
{
    float x = 1.;

    if(a == 0.0)
        throw string("Bad arg a");
    x /= a;

    if(b == 0.0)
        throw string("Bad arg b");
    x /= b;

    if(c == 0.0)
        throw string("Bad arg c");
    x /= c;

    if(d == 0.0)
        throw string("Bad arg d");
    return x / d;
}

int main()
{
    try {
        do_calculations(1, 2, 3, 0);
    } 
    catch(string &exc) {
        cout << "Something bad happened: " << exc << endl;
    }

    return 0;
}
```

Output:

```text
Something bad happened: Bad arg d
```

## Throw vs. function epilogue

Code:

```cpp
/*
The functions executions consist, in general, of three phases: prologue (when all automatic variables/objects are created), 
execution (when the function code is performed) and epilogue (when the previously created entities are destructed).
We know that the function won’t return after the footsteps but, in some measure, will go for shortcuts, omitting normal completion.
All desired cleanings will be done, giving the program a chance to retrieve its normal operation in the nearest future.
This is a routine, clear code, without any throw instruction. It demonstrates how the epilogue may manifest its effects, 
although normally it works quietly without bothering anybody.
*/

#include <iostream>
using namespace std;

// A simple class in the code equipped with one constructor and one destructor. They do nothing except output short messages proving that the functions were invoked.
class Class {
    public:
        Class()
        { 
            cout << "Object constructed" << endl; 
        }

        ~Class()
        { 
            cout << "Object destructed" << endl; 
        }

        void hello()
        { 
            cout << "Object says: hello" << endl; 
        }
};

float do_calculations()
{
    Class object;

    object.hello();
    return 42.;
}

int main()
{
    cout << do_calculations() << endl;

    return 0;
}
```

Output:

```text
Object constructed
Object says: hello
Object destructed
```

## Throw vs. function epilogue

Code:

```cpp
#include <iostream>
using namespace std;

class Class {
    public:
        Class()
        { 
            cout << "Object constructed" << endl; 
        }

        ~Class()
        { 
            cout << "Object destructed" << endl; 
        }

        void hello()
        {
            cout << "Object says: hello" << endl; 
        }
};	

/* 
We’ve added three throw instructions within the do_calculations() function. Now we can precisely control (using a parameter value) which one will be executed. 
Note that the first is placed at the function beginning, before the object is created, the second in the middle and the third at the end of the function.
*/
void do_calculations(int i)
{
    /* 
    In the first case, no objects were created during the (broken) function execution, as the throw occurred before the line where the object is declared. 
    There is no trace of either constructor or destructor activity.
    */
    if(i == 0) 
        throw string("fatal 1");

    /* 
    In both remaining cases, both constructor and destructor proved to us that they worked, although the function didn’t reach its normal end.
    We can use throw without the fear that we may cause memory leaks.
    */
    Class object;

    if(i == 1)
        throw string("fatal 2");

    object.hello();
    
    if(i == 2)
        throw string("fatal 3");
}

// The main() function will invoke do_calculations() three times and we’ll be able to observe the function’s behaviour.
int main()
{
    for(int i = 0; i < 3; i++)
    {
        try {
            cout << "-------" << endl;	
            do_calculations(i);
        }
        catch (string &exc) {
            cout << exc << endl;
        }
    }	

    return 0;
}
```

Output:

```text
-------
fatal 1
-------
Object constructed
Object destructed
fatal 2
-------
Object constructed
Object says: hello
Object destructed
fatal 3
```

## Throw and the objects it throws

Code:

```cpp
/*
The throw statement is obligated to throw a value e.g. an object – it can’t throw nothing. Throw is able to throw any object of any accessible class. 
We also know that the type of the object thrown may be used to choose the catch which will be responsible for handling the exception.
*/

#include <iostream>
using namespace std;

/* 
We use the class in two roles: once as data being “processed” by the do_calculations() function and once as an exception container. 
These two applications have nothing in common! We want to show that these two paths (routine and exceptional) go completely separately.
*/
class Class {
    public:
        string msg;

        Class(string txt) : msg(txt)
        {
            cout << "Object [" << msg << "] constructed" << endl; 
        }

        ~Class()
        {
            cout << "Object [" << msg << "] destructed" << endl; 
        }

        void hello()
        { 
            cout << "Object [" << msg << "] says: hello" << endl; 
        }
};

void do_calculations(int i)
{
    if(i == 0) 
        /* 
        It will cause the creation of a new object of class Class. This means that the appropriate constructor will be invoked before the function ends its life.
        It doesn’t mean that the destructor will be invoked before the function ends its life. The object will be alive even after the function’s epilogue. 
        It must live until it finds its target catch and will die only when catch ends its job. Not sooner.
        */
        throw Class("exception 1");

    Class object("object");

    if(i == 1)
        throw Class("exception 2");

    object.hello();

    if(i == 2)
        throw Class("exception 3");
}

int main()
{
    for(int i = 0; i < 3; i++) {
        try {
            cout << "-------" << endl;
            do_calculations(i);
        }
        catch (Class &exc) {
            cout << "Caught!" << endl;
            cout << exc.msg << endl;
        }
    }   

    return 0;
}
```

Output:

```text
-------
Object [exception 1] constructed
Caught!
exception 1
Object [exception 1] destructed
-------
Object [object] constructed
Object [exception 2] constructed
Object [object] destructed
Caught!
exception 2
Object [exception 2] destructed
-------
Object [object] constructed
Object [object] says: hello
Object [exception 3] constructed
Object [object] destructed
Caught!
exception 3
Object [exception 3] destructed
```

## Example 8

Code:

```cpp
/* 
Throw and how we can find out about it

We can learn about it from reading the function body, but that isn’t a good idea. There are two important arguments worth considering:
    * The function may be very long and very complex – reading it may be time consuming and we may overlook some of the throw statements
    * The source code of the function may be inaccessible – it may happen if we use a ready-made library, written by other authors, 
      when we’ve compiled (binary) files containing only executable code and header files specifying function’s headers but not the bodies.
*/

#include <iostream>
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

void function(int i)
{
    throw Class("object");
}

int main()
{
    try {
        function(1);
    }
    catch(Class &exc) {
        cout << "Caught!" << endl;
    }

    return 0;
}
```

Output:

```text
Caught!
```

## Example 9

Code:

```cpp
/* 
To throw or not to throw

Knowing whether a certain function throws an exception or not can be very valuable to the compiler.
A function's epilogue can be much more complex when an exception is thrown somewhere inside function's body. It means that function which announces loudly that isn't going 
to throw exception can be compiled in more compact and economical way. 
throw(x) means that the function throws one kind of exception, of type x, for example:
    void the_fun() throw(string);
The more complex form looks like this:
    throw(x1, x2, … ,xn)
This means that the function throws n different exceptions of types x1, x2, ..., xn respectively, for example:
    int do_it(int i) throw(int, string, Class);
This function may throw exceptions of type int, string and Class.
The last form look like this:
    throw()
and means “the function throws no exceptions at all”.
COMPILATION ERROR!
*/

#include <iostream>
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

// We’ve added the throw specifications to two of our functions.
// It declares itself as throwing one kind of exceptions
void thrower() throw(Class)
{
    cout << "Thrower" << endl;
    throw Class("object");
}

// It renounces exception throwing completely.
void putter() throw()
{
    cout << "Putter" << endl;
}

int main()
{
    try {
        putter();
        thrower();
    }
    catch(Class &exc) {
        cout << "Caught!" << endl;
    }

    return 0;
}
```

Output:

```text
error: ISO C++17 does not allow dynamic exception specifications
    void thrower() throw(Class)
```

## Example 10

Code:

```cpp
/* 
Newer compilers accepts completely differ syntax for the same purpose. A function which throws an exception (no matter which exactly) announces its intent using the following form:.
    noexcept(false)
A statement to the contrary is written as:
    noexcept(true)
or simply as:
    noexcept   
*/

#include <iostream>
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

void thrower() noexcept(false)
{
    cout << "Thrower" << endl;
    throw Class("object");
}

void putter() noexcept(true)
{
    cout << "Putter" << endl;
}

int main()
{
    try {
        putter();
        thrower();
    }
    catch(Class &exc) {
        cout << "Caught!" << endl;
    }

    return 0;
}
```

Output:

```text
Putter
Thrower
Caught!
```

## Crime and Punishment

Code:

```cpp
// What happens when the promise expressed as noexcept(true) isn't kept? 

#include <iostream>
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

// The unreliable() function declares itself as throwing no exceptions and recklessly breaks the promise.
void unreliable() noexcept(true) {
    throw string("");
}

/* 
Compiler warnings something really catastrophic will occur here. Our program will be immediately terminated when any exception is thrown inside the function. 
The catch is neither reached nor executed. This is what the penalty for perjury looks like.
*/
int main()
{
    try {
        unreliable();
    } 
    catch(string &exc) {
        cout << "Caught!" << endl;
    }

    return 0;
}
```

Output:

```text
warning: ‘throw’ will always call ‘terminate’ [-Wterminate]
    throw string("");
```

## Example 12

Code:

```cpp
/* 
It’s a very simple illustration of the concept saying that exception handling may be distributed among different parts of the program. 
We can handle our exceptions in the most suitable places and don’t need to collect all catches in one function or module.
*/

#include <iostream>
using namespace std;

class Class {
    public:
        string msg;
        Class(string txt) : msg(txt) {}
};

// The function thrower() throws two different exceptions, but exceptions of different types are handled differently.
void thrower(int i)
{
    switch(i) {
        case 0 : throw string("string");
        case 1 : throw Class("object");
        default: cout << "OK" << endl;
    }
}

/* 
There’s another function (named midlevel()) which has created an intermediate level between the function and the main.
The midlevel() function catches exceptions of type string (the objects of this class end their lives there), but Class exceptions fly on to the main() function and are caught there.
*/
void midlevel(int i) 
{
    try {
        thrower(i);
    } 
    catch(string &exc) {
        cout << "String [" << exc << "] caught in level()" << endl;
    }    
}

int main()
{
    for(int i = 0; i < 3; i++) {
        cout << "-------" << endl;

        try {
            midlevel(i);
        } 
        catch(Class &exc) {
            cout << "Object [" << exc.msg << "] caught in main()" << endl;
        }
    }

    return 0;
}
```

Output:

```text
-------
String [string] caught in level()
-------
Object [object] caught in main()
-------
OK
```

## The 'explicit' keyword

Code:

```cpp
/*
The explicit keyword may be placed in front of a class’s constructor declaration. It protects the constructor from being used in any context requiring the use of implicit conversions. 
This constructor may only be used in an explicit way; hence, the keyword is used when a programmer wants to avoid any side effects that may result from the reckless use of the selected 
constructors, or indeed of all constructors.
*/

#include <iostream>

/* 
There are two very similar classes, named A and B, respectively. They’re both dummies, in fact – they do nothing at all. 
They’re almost identical, the only difference comes from the constructor declaration: the A class makes use of the explicit keyword, while the B class doesn’t.
*/
class A {  
   public:
      explicit A(int) {}
};

class B {  
   public:
      B(int) {}
};

/* 
The syntax used in both lines is implicitly presumed as it’s coded in the following way:
   A a(1);
but when the explicit keyword is used, this presumption is illegal.
The A class cannot implicitly convert integers into its objects.
*/
int main() {
   A a = 1;  // compilation error!
   B b = 1;  // OK!

   return 0;
}
```

Output:

```text
error: conversion from ‘int’ to non-scalar type ‘A’ requested
   A a = 1;  // compilation error!
```

## The 'exception' class

Code:

```cpp
/*
The exception class is a base (or a root) for all other predefined exceptions. It contains a function called what(), which is designed to provide a pointer to the so-called “C”-style string 
(a character sequence terminated with a null character) describing the nature of the exception.
The exact form of this message is implementation-dependent and different compilers may name the same events in different ways.
*/

#include <iostream>
#include <exception>
using namespace std;

class A {  
    public:
        virtual void f() {}
};

class AA : public A {  
    public:
        void aa() {};
};

int main()
{
    A a;

    // We’ve tried to perform illegal typecasting and used the exception object caught by the catch statement to demonstrate the message we may get.
    try {
        dynamic_cast<AA &>(a).aa();
    } 
    catch (exception ex) {
        cout << "[" << ex.what() << "]" << endl;
    }

    return 0;
}
```

Output:

```text
[std::exception]
```

## Example 15

Code:

```cpp
/* 
Proper handling of the bad_exception exception requires the function to specify bad_exception on its throw list (it looks like a paradox but it’s true), 
and the unexpected handler function must be defined and set. Failure to meet any of these conditions will result in undesired program behaviour.
*/

#include <iostream>
#include <exception>
using namespace std;

/* 
Note the empty throw statement inside the unexp function. This form doesn’t mean that the function throws nothing – on the contrary, 
it means that the exception received by the function is re-thrown.
*/
void unexp()
{
    cout << "Unexpected exception arrived!" << endl;
    throw;
}

void function() throw(int, bad_exception) 
{
    throw 3.14; 
}

int main()
{
    set_unexpected(unexp);

    try {
        function();
    } 
    catch(double f) {
        cout << "Got double" << endl;	
    } 
    catch(bad_exception bad) {
        cout << "It's so bad..." << endl;
    }

    cout << "Done" << endl;

    return 0;
}
```

Output:

```text
error: ISO C++17 does not allow dynamic exception specifications
    void function() throw(int, bad_exception)
```

## Different catches for different purposes

Code:

```cpp
/*
The catch instruction is supposed to “catch” events passing through the instruction’s scope. We also know that the catch “catches” only these 
exceptions that are compatible in type with the catch header. 
For example, the following instruction:
    catch(string excp) {  }
catches exceptions encapsulated inside objects of type string, and ignores all others.
There’s a specialized form of the catch that’s able to catch literally all passing exceptions – it looks like:
    catch(...) { … }
but in contrast to the previous form, it can neither identify the exception object, nor make any use of it. Therefore, it’s intended for some very general actions, 
such as final cleanings, rather than for the subtle and finesse handling of a well-recognized problem.
If a try block contains more than one catch branch, then at most one of them may be executed. An exception caught by one of the branches leaves the try block and 
any of its other catches won’t be bothered.
*/

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
    }
}

int main()
{
    for(int i = 0; i < 3; i++) {
        try {
            function(i);
        }
        // The “...” tri-graph is known as an ellipsis
        catch(...) {
            cout << "Exception caught!" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Exception caught!
Exception caught!
Exception caught!
```

## Example 17

Code:

```cpp
// We’ve changed the catch header and added the “exception &ex” instead of the ellipsis.

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        // All exceptions (excluding the last one, which is just a class exception) thrown by a function are derived from the exception class and thus are compatible in type.
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        case 3: throw exception();
    }
}

int main()
{
    for(int i = 0; i < 4; i++) {
        try {
            function(i);
        }
        /* 
        The branch is allowed to catch all exceptions whose objects are compatible in type with the exceptions class.
        We can identify an object, name it locally (as ex) and make use of its properties and/or functions. 
        We invoke the what function to find out what the object wants to say about itself.
        */
        catch(exception &ex) {
            cout << "Exception caught: " << ex.what() << endl;
        }
    }

    return 0;
}
```

Output:

```text
Exception caught: 0
Exception caught: 1
Exception caught: 2
Exception caught: std::exception
```

## Example 18

Code:

```cpp
/* 
We can selectively choose the exceptions we want to catch and handle carefully, and those that we want to handle very briefly.
The code mixes the two previous approaches: some of the exceptions are caught individually while others go to the ellipsis.
There’s one important condition: the ellipsis branch, if it exists, must be the last specified branch. Otherwise, the compiler will produce an error.
*/

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        case 3: throw exception();
        case 4: throw "so bad";
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            function(i);
        }
        catch(out_of_range &ofr) {
            cout << "Out of range: " << ofr.what() << endl;
        }
        catch(overflow_error &ovf) {
            cout << "Overflow: " << ovf.what() << endl;
        }
        catch(domain_error &dmn) {
            cout << "Domain: " << dmn.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Out of range: 0
Overflow: 1
Domain: 2
Exception: std::exception
Something bad happened
```

## Order of the catch branches

Code:

```cpp
// The order of the catch branches matters yes and no. We’ll start from the “no” variant.

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        case 3: throw exception();
        case 4: throw "so bad";
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            function(i);
        }
        // We’ve swapped two of the first catch branches. The program doesn't produce compilation errors.
        catch(overflow_error &ovf) {
            cout << "Overflow: " << ovf.what() << endl;
        }
        catch(out_of_range &ofr) {
            cout << "Out of range: " << ofr.what() << endl;
        }
        catch(domain_error &dmn) {
            cout << "Domain: " << dmn.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Out of range: 0
Overflow: 1
Domain: 2
Exception: std::exception
Something bad happened
```

## Order of the catch branches

Code:

```cpp
/*
We’ve swapped the first and the fourth catch branches. The program’s behaviour changes.
We should expect that the compiler is going to produce some warning messages. It won’t prevent our program from being successfully compiled, 
but the warnings suggest that not everything has gone as we would have liked.
*/

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw out_of_range("0");
        case 1: throw overflow_error("1");
        case 2: throw domain_error("2");
        case 3: throw exception();
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
        catch(out_of_range &ofr) {
            cout << "Out of range: " << ofr.what() << endl;
        }
        catch(overflow_error &ovf) {
            cout << "Overflow: " << ovf.what() << endl;
        }
        catch(domain_error &dmn) {
            cout << "Domain: " << dmn.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
warning: exception of type ‘std::out_of_range’ will be caught by earlier handler [-Wexceptions]
    catch(out_of_range &ofr) {
Exception: 0
Exception: 1
Exception: 2
Exception: std::exception
Something bad happened
```

## Example 21

Code:

```cpp
/* 
When the exception arrives at a set of catch branches, the first compatible branch is chosen (and only this one) as a target handler.
This means that when a more general type/class is placed before the more specific compatible type/class, the second branch will receive no exceptions at all.
This is why the compiler warns us that the order of the catch branches is risky and some of the branches may be permanently omitted in the process of selecting the exception handler.
This is also why the branch with the exception class hides all the subsequence branches with types derived from the exception class.
Additionally, we’re not allowed to specify more than one branch with the same exception type/class. The compiler will treat this as an error.
The code shows us what happens when not all the exceptions find their handler.
*/

#include<iostream>
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

    return 0;
}
```

Output:

```text
Exception: 0
Exception: 1
Exception: std::exception
Exception: 2
terminate called after throwing an instance of 'char const*'
Aborted
```

## Example 22

Code:

```cpp
// We can repair our program in a very simple way – all we have to do here is add an ellipsis branch, which will be responsible for taking care of all the orphaned exceptions.

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
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
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Exception: 0
Exception: 1
Exception: std::exception
Exception: 2
Something bad happened
```

## Process of selecting the target exception handler

Code:

```cpp
#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            function(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Logic error: 0
Logic error: 1
Exception: std::exception
Exception: 2
Something bad happened
```

## Process of selecting the target exception handler

Code:

```cpp
#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            function(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error &re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Logic error: 0
Logic error: 1
Exception: std::exception
Runtime error: 2
Something bad happened
```

## Sharing the responsibility

Code:

```cpp
/*
We’ve added a broker between the main() and the function(). The broker handles some of the passing exceptions, namely those compatible with the exception class. 
Now the handling process is dispersed over two levels: lower (inside broker) and upper (inside main).
*/

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

/* 
Most of the exceptions have been handled by the broker and haven’t reached the main function.We can use this method when we want to divide the responsibility 
of handling different kinds of exceptions between different layers of the program logic.
*/
void broker(int i)
{
    try { 
        function(i); 
    }
    catch(exception &ex) { 
        cout << "Broker - exception: " << ex.what() << endl; 
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            broker(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error &re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Broker - exception: 0
Broker - exception: 1
Broker - exception: std::exception
Broker - exception: 2
Something bad happened
```

## Sharing the responsibility

Code:

```cpp
#include <iostream>

using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

void broker(int i)
{
    try { 
        function(i); 
    }
    catch(logic_error &le) { 
        cout << "Broker - logic_error: " << le.what() << endl; 
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            broker(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error &re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Broker - logic_error: 0
Broker - logic_error: 1
Exception: std::exception
Runtime error: 2
Something bad happened
```

## Example 27

Code:

```cpp
/* 
A badly constructed broker may ruin the exception handling logic at higher levels. 
The broker’s decided to take control over all arriving exceptions. None of them will leave the broker. 
We can say that “everything that comes to the broker stays in the broker”.
*/

#include <iostream>
using namespace std;

void function(int i) {
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

void broker(int i)
{
    try {
        function(i);
    }
    catch(...) {
        cout << "Broker swept problems under the carpet" << endl;
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            broker(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error &re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Broker swept problems under the carpet
Broker swept problems under the carpet
Broker swept problems under the carpet
Broker swept problems under the carpet
Broker swept problems under the carpet
```

## Example 28

Code:

```cpp
/* 
The responsibility of handling exceptions may not only be divided – it may be shared, too. This means that the handling of the same exceptions may be provided at more than one level.
Note that any of the catch branches might throw an exception too, and the exception won’t be handled in the place where it was created, but at a higher level.
The broker tries to catch all the exceptions (and succeeds!), but immediately re-throws all of them using the argument-less throw instruction.
This is the only possible way of re-throwing an exception in the ellipsis branch where the caught exception is completely anonymous and therefore imperceptible.
This form may be used in other kinds of catches, but there are no obstacles to using less anonymous variants, like this one:
    catch(exception &ex) {
        throw ex;
    }
We can throw another (new) exception instead of throwing the received exception. This might be a good idea when we want to change the category of the exception.
Here’s an example:
    catch(logic_error &err) {
        throw "We have a problem";
    }
*/

#include <iostream>
using namespace std;

void function(int i)
{
    switch(i) {
        case 0: throw domain_error("0");
        case 1: throw logic_error("1");
        case 2: throw exception();
        case 3: throw range_error("2");
        case 4: throw "so bad";
    }
}

void broker(int i)
{
    try {
        function(i);
    }
    catch(...) {
        cout << "Broker swept problems under the carpet " << endl;
        throw;
    }
}

int main()
{
    for(int i = 0; i < 5; i++) {
        try {
            broker(i);
        }
        catch(logic_error &le) {
            cout << "Logic error: " << le.what() << endl;
        }
        catch(runtime_error &re) {
            cout << "Runtime error: " << re.what() << endl;
        }
        catch(exception &ex) {
            cout << "Exception: " << ex.what() << endl;
        }
        catch(...) {
            cout << "Something bad happened" << endl;
        }
    }

    return 0;
}
```

Output:

```text
Broker swept problems under the carpet 
Logic error: 0
Broker swept problems under the carpet 
Logic error: 1
Broker swept problems under the carpet 
Exception: std::exception
Broker swept problems under the carpet 
Runtime error: 2
Broker swept problems under the carpet 
Something bad happened
```

## Stack again

Code:

```cpp
/*
We’ve introduced two important amendments compared to its previous incarnations:
the values stored in the stack are still located inside an array, but the size of the array is defined dynamically by the constructor; note the default stack size specification
as a consequence of the previous modification, we’ve had to add a destructor responsible for removing the array at the end of the stack’s life
A very simple main function proves that the stack behaves correctly.
*/

#include <iostream>
using namespace std;

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

Stack::Stack(int size)
{ 
    stackstore = new int[size];
    stacksize = size;
    SP = 0;
}

Stack::~Stack()
{
    delete [] stackstore;
}

void Stack::push(int value)
{
    stackstore[SP++] = value;
}

int Stack::pop()
{ 
    return stackstore[--SP]; 
}

int main()
{
    Stack stk;

    stk.push(1);
    cout << "stk.pop(): " << stk.pop() << endl;

    return 0;
}
```

Output:

```text
stk.pop(): 1
```

## Stack main function

Code:

```h
///////////////////////
// Stack header file //
///////////////////////

/*
We’ve named it mystack.h. We’ve assumed that the file with all required definitions will be named mystack.cpp.

A file containing all the necessary declarations. The file can be included by any other source file making use of our newly built stack.
The header doesn’t contain any definitions, usually, as they aren’t needed during the compilation phase.

The #ifdef directive is used by a pre-processor to check if the compile-time symbol is defined or not. In our example the checked symbol is named __MYSTACK__. 
It’s essential to choose a name unique to the specific project. Usually the name derives from the header name itself, and we’ve followed that convention here.
If the symbol is not defined (ndef), the pre-processor will analyse the rest of the file, or skip it otherwise. 
Note that it doesn't skip the entire file content, but only the part nested between the #ifndef and #endif directives.
The next directive, #define, defines the __MYSTACK__ symbol. when the header file is included for the first time, it’s parsed as a whole, and every line is taken into consideration.
During the second and subsequent inclusions, its content is ignored because the pre-processor knows that the __MYSTACK__ has already been defined. This simple trick 
speeds up the compilation process and helps the pre-processor to avoid unnecessary multiple inclusions of the same header file.
*/

#ifndef __MYSTACK__
#define __MYSTACK__
#include <iostream>
#include <exception>
#include <stdexcept>

/* 
Each of the constructors invokes its base class’s constructor and adds no new functionalities.
The implementation of the stack will change too. We assume that:
    * the constructor throws two exceptions: stack_size_error and stack_bad_alloc.
    * the push function throws the stack_overflow exception.
    * the pop function throws the stack_empty.
*/
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
```

```cpp
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
```

```cpp
/*
#include "mystack.h" -> This is how the compiler learns about the stack and all of its components, as well as the exceptions we’ve jointly defined.
The compilation process should look as follows:
    * The compiler compiles the “mystack.cpp” file and produces an object file (its name may be different on different platforms – some compilers may use “mystack.o”, 
    others “mystack.obj” – don’t be surprised).
    * The compiler compiles the “main.cpp” file and produces an object file of a name, e.g. “main.obj”
    * The linker links both files, adding a code taken from standard libraries, and produces an executable file in the end.
*/

#include "mystack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack stack;
    stack.push(1);
    cout << stack.pop() << endl;

    return 0;
}
```

Output:

```text
1
```

## Example 31

Code:

```cpp
// We’re prepared for all circumstances. All stack operations are covered by the try block, and we have a complete set of catches ready to diagnose all problems.

#include "mystack.h"
#include <iostream>
using namespace std;

int main()
{
    try {
        Stack stack;
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

    return 0;
}
```

Output:

```text
1
```

## Example 32

Code:

```cpp
// We’ll check if the constructor properly detects stack size values that are too low.

#include "mystack.h"
#include <iostream>
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
        cout << "I don't know what I'm doing" << endl;
    }

    return 0;
}
```

Output:

```text
Stacks of that size don't exist - sorry!
```

## Example 33

Code:

```cpp
// We’ll check if the constructor can handle our exorbitant demands on the stack size.

#include "mystack.h"
#include <iostream>
using namespace std;

int main()
{
    try {
        Stack stack(2000000000);
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
        cout << "I don't know what I'm doing" << endl;
    }

    return 0;
}
```

Output:

```text
1
```

## Example 34

Code:

```cpp
// We’ll check if the stack can handle too many pushes.

#include "mystack.h"
#include <iostream>
using namespace std;

int main()
{
    try {
        Stack stack(1);
        stack.push(1);
        stack.push(2);
        stack.push(3);
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
        cout << "I don't know what I'm doing" << endl;
    }

    return 0;
}
```

Output:

```text
Stack is too small for that many pushes - sorry!
```

## Example 35

Code:

```cpp
// We’ll check if the stack can handle too many pops.

#include "mystack.h"
#include <iostream>
using namespace std;

int main()
{
    try {
        Stack stack;
        stack.push(1);
        cout << "stack.pop(): " << stack.pop() << endl;
        cout << "stack.pop(): " << stack.pop() << endl;        
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
        cout << "I don't know what I'm doing" << endl;
    }

    return 0;
}
```

Output:

```text
stack.pop(): 1
stack.pop(): Stack is empty - sorry!
```