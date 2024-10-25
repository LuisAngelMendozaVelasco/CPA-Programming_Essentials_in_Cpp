# Object-Oriented Programming

## Stack

Code:

```cpp
/*
It's a structure developed to store data in a very specific way. Imagine a stack. A stack of coins would be best here. 
You can’t put a coin anywhere else but on the top of the stack. Similarly, you can’t get a coin off the stack from anywhere other than the stack’s top. 
If you want to get the coin on the bottom, you have to remove all the coins that are sitting on top of it.
The alternative name for a stack (but only in IT terminology, of course) is LIFO. This is an abbreviation for a description of the stack’s behaviour: 
"Last In - First Out". The coin that goes onto the stack last comes off first.
A stack is an object to two elementary operations conventionally named "push" (when a new element is placed on the top) and 
"pop" (when an existing element is taken away from the top).
*/

#include <iostream>
using namespace std;

/* 
Use a vector for this job. We assume (somewhat recklessly) that there’ll be no more than 100 values on the stack at the same time. 
We also assume that the element at index 0 is at the bottom of the stack.
*/
int stack[100];
/* 
We need a variable that can be responsible for storing a number of elements currently stored on the stack. 
This variable is generally called a “stack pointer”, or SP for short.
Initially, the stack is empty, so the stack pointer should be assigned the value of 0.
*/
int SP = 0;

/* 
Function that places a value onto the stack:
    * The name for the function is "push".
    * The function gets one argument of type int (this is the value to be placed onto the stack).
    * The function returns nothing.
    * The function places the argument value into the first free element in the vector and increments the SP.
*/
void push(int value) // The function doesn’t check if there’s room for the new value.
{
    cout << "stack [" << SP << "] = " << value << endl;
    stack[SP++] = value;
}

/* 
Function to take a value off the stack:
    * The name for the function is "pop" (we don’t want to discover America again).
    * The function doesn’t have any arguments.
    * The function reads the value from the stack’s top and decrements SP.
    * The function returns the value taken from the stack.
*/
int pop() // The function doesn’t check if there’s any element on the stack.
{
    cout << "pop() stack = ";
    return stack[--SP];
}

int main() 
{
    push(3);
    push(2);
    push(1);

    cout << endl << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;

    return 0; 
}
```

Output:

```text
stack [0] = 3
stack [1] = 2
stack [2] = 1

pop() stack = 1
pop() stack = 2
pop() stack = 3
```

## Stack class

Code:

```cpp
#include <iostream>
using namespace std;

// We’ll use a vector as the stack’s storage and we’ll use an int variable as the stack pointer. We only have to place the two of them into the class.
class Stack {
/* 
We wanted to encapsulate both variables and make them inaccessible from the outside world.
This kind of data is called private in object programming. It’s private because only the class itself may access and modify it.
If we want to mark some part of a class’s data as private, we have to add the keyword before the declarations.
*/
private:
    int stackstore[100];
    int SP;
/* 
Components accessible to every class’s user (in contrast to the previously declared variables which are hidden from an ordinary class’s users). 
This type of component is called "public" and we have to use a keyword to emphasize this fact.
*/
public:
    /* 
    A “constructor” is responsible for the proper construction of each new object of the class.
    It must be named the same as its home class. Constructors aren’t real functions. They don’t have any return type – not even void.
    */
    Stack () 
    { 
        SP = 0; 
    }

    /* 
    Two functions that implement push and pop operations. The C++ language assumes that a function of this kind (being a class activity) 
    may be described in two different way:
        * inside the class, when the class body contains a full implementation of the method
        * outside the class, when the body contains only the function header; the function body is placed outside the class
    Both functions access the class variables (namely the stackstore and SP) without any obstacles. a class’s components are fully 
    visible to other components of the same class.
    */
    void push(int value); // Function outside the class
    
    int pop()  // Function inside the class body
    {
        return stackstore[--SP];
    }
};

/* 
The functions implementing the class’ activities and placed outside the class body need to be described in a very specific way. 
Their names should be qualified using the home class name and the “::” operator.
*/
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
    cout << funny_stack.pop() << endl;

    return 0; 
}
```

Output:

```text
4
```

## Stack subclass

Code:

```cpp
#include <iostream>
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

    return 0; 
}
```

Output:

```text
stack = [1, 2, 3, 4, 5, 6, 7, 8, 9]
Sum stack = 45
Sum empty stack = 0
```

## Copying constructors

Code:

```cpp
/*
There is a special kind of constructor intended to copy one object into another. Constructors of this kind have one parameter 
referenced to an object of the same class and are used to copy all important data from the source object to the newly created 
object (or more precisely, to the object currently being created). 
They are implicitly invoked when a declaration of an object is followed by an initiator. It may be also invoked if the declaration 
specifies a constructor suitable for the declaration.
The object data doesn’t actually need to be copied. It could just be manipulated and processed. What’s more important is that the 
data is taken from a different object of the same (or similar) class. 
*/
#include <iostream>
using namespace std;

// Class with a copying constructor.
class Class1 {
    public:
        Class1(int val) 
        { 
            /* 
            "this pointer"
            We assume that each object is equipped with a special component containing the following traits:
                * its name is this
                * it mustn’t be declared explicitly (it’s a keyword) so it may not be overridden
                * it’s a pointer to the current object – each object has its own copy of the this pointer
            
            The general rule says that:
                * if S is a structure or class and S has a component named C and
                * if p is a pointer to a structure/class of type S
                * then the C component may be accessed in the two following ways:
                    * (*p).C where p is explicitly dereferenced in order to access the C component
                    * p->C where p is implicitly dereferenced in order to access the C component
            */
            this -> value = val; 
        }

        /* 
        The keyword const used in the parameter declaration is a promise that the function won’t attempt 
        to modify the values stored in the referenced object.The copying constructor will also be used when 
        the context requires a copy of a specific object, e.g. when a particular object is transferred to a function as a value-passed actual parameter.
        */
        Class1(Class1 const &source) 
        { 
            value = source.value + 100; 
        }
        int value;
};

// Class without a copying constructor.
class Class2 {
    public:
        Class2(int val) 
        { 
            this -> value = val; 
        }
        int value;
};

int main() 
{
    // Two objects are created for both of the classes while both of the second objects are created by copying the first ones.
    Class1 object11(100), object12 = object11;
    Class2 object21(200), object22 = object21;

    cout << "Class with a copying constructor:  object11.value = " << object11.value << ", object12.value =  " << object12.value << endl;
    cout << "Class without a copying constructor:  object21.value = " << object21.value << ", object22.value =  " << object22.value << endl;

    return 0; 
}
```

Output:

```text
Class with a copying constructor:  object11.value = 100, object12.value =  200
Class without a copying constructor:  object21.value = 200, object22.value =  200
```

## Memory leaks

Code:

```cpp
/*
In real programming many of the objects are allocated memory that they need for their operation. This memory should be released 
when the object finishes its activity and the best way to do this is to do the cleaning automatically. Failure to clean the memory 
will cause a phenomenon named "memory leaking", where the unused (but still allocated!) memory grows in size, affecting system performance.
We can also provoke memory leaking intentionally.
*/

#include <iostream>
using namespace std;

class Class {
    public:
        // Constructor, which is responsible for allocating memory of the size specified by its parameter value. 
        Class(int val) 
        { 
            value = new int[val]; 
            cout << "Allocation (" << val << ") done." << endl;
        }
        
        int *value;
};

// The object of this class is created as a local variable.
void make_a_leak() 
{
    Class object(1000);
}

/* 
We can imagine that object creation consists of two phases:
    1. The object itself is created and a part of the memory is implicitly allocated to the object.
    2. The constructor explicitly allocates another part of the memory.
The object variable is an example of an “automatic variable”. This means that the variable automatically finishes 
its life when the execution of the function containing the variable’s declaration ends.
*/
int main() 
{

    /* 
    We may want that returning from make_a_leak() will implicitly free all memory allocated to the object, 
    but (unfortunately), the memory explicitly allocated by the constructor remains allocated. To make matters worse, 
    we’ve also lost the only pointer that held the address of that memory (it was stored by the value field, 
    but the object containing this field doesn’t exist anymore).
    */
    make_a_leak();

    return 0; 
}
```

Output:

```text
Allocation (1000) done.
```

## Destructors

Code:

```cpp
/*
Destructors have the following restrictions:
    * If a class is named X, its destructor is named ~X.
    * A class can have no more than one destructor.
    * A destructor must be a parameter-less function (note that the two last restrictions are the same – can you explain why?).
    * A destructor shouldn’t be invoked explicitly.
*/

#include <iostream>
using namespace std;

class Class {
    public:
        Class(int val) 
        { 
            value = new int[val]; 
            cout << "Allocation (" << val << ") done." << endl; 
        }

        // The destructor frees the memory allocated to the value field, protecting us from memory leaking.
        ~Class() 
        {
            delete [] value;
            cout << "Deletion done." << endl;
        }

        int *value;
};

void make_a_leak() 
{
    Class object(1000);
}

int main() 
{
    make_a_leak();

    return 0; 
}
```

Output:

```text
Allocation (1000) done.
Deletion done.
```

## Automatic variables

Code:

```cpp
/*
All the variables in the code belong to one of two categories. They are:
    * Automatic variables, created and destroyed, sometimes repeatedly, and automatically (hence their name) during program execution.
    * Static variables, existing continuously during the whole program execution.
"C++" programming language assumes that all variables are automatic by default unless they are declared explicitly as static. 
*/

#include <iostream>
using namespace std;

void fun() 
{
    /* 
    The var variable is created each time the fun function is invoked and is destroyed each time the function completes its execution. 
    We can say that creation and deletion of the variable is automated.
    */
    int var = 99;

    cout << "var = " << ++var << endl;
}

int main() 
{
    // The function will always produce the same output.
    for(int i = 0; i < 5; i++)
        fun();

    return 0; 
}
```

Output:

```text
var = 100
var = 100
var = 100
var = 100
var = 100
```

## Static variables

Code:

```cpp
/*
We’ve just added the "static" keyword in front of "int".
The "var" variable is created and initiated once during the so-called "program prologue" and is destroyed after program completion 
during the operation of the so-called "program epilogue". This means that the var variable exists even when the fun function isn’t
working and in effect the variable’s value is preserved between subsequent fun invocations. This is how the static keyword affects variable fate.
*/

#include <iostream>
using namespace std;

void fun() 
{
    static int var = 99;

    cout << "var = " << ++var << endl;
}

int main() 
{
    for(int i = 0; i < 5; i++)
        fun();

    return 0; 
}
```

Output:

```text
var = 100
var = 101
var = 102
var = 103
var = 104
```

## Static components of the class

Code:

```cpp
/*
A static component exists throughout the whole life of the program. Moreover, there is always only one component 
regardless of the number of instances of the class. We can say that all the instances share the same static components.
The Static variable inside the public part of the Class is only a declaration. This means that the variable has to have 
both an explicitly expressed separate definition and a possible initialization, and both must be placed outside the class definition.
Another rationale says that the definition has to be separate from the class body because static variables are not actually part of any object. 
*/

#include <iostream>
using namespace std;

class Class {
	public:
		static int Static;
		int NonStatic;

		void print()
		{
			cout << "Static = " << ++Static << ", NonStatic = " << NonStatic << endl;
		}
};

int Class::Static = 0;

int main() 
{
	Class instance1, instance2;

	instance1.NonStatic = 10;
	instance2.NonStatic = 20;
	instance1.print();
	instance2.print();

    return 0; 
}
```

Output:

```text
Static = 1, NonStatic = 10
Static = 2, NonStatic = 20
```

## Static class variables

Code:

```cpp
/*
The unique traits of the static class variables predestine them to be used as counters of instances of a particular class. 
The Counter field is accessed directly when it’s being used inside the class and with the "::" operator when it’s being used outside the class. 
It’s also possible to access the static variable through any of the existing class instances, like this:
    cout << b.Counter ;
as long as the accessed variable is publicly available.
*/

#include <iostream>
using namespace std;

class Class {
    public:
        /* 
        First, we equip the Class class with the static field Counter. The Counter variable is defined outside the class and assigned 
        a value of zero to show that none of the class’s instances exist so far.
        */
        static int Counter;

        // We’ll increment the Counter inside the Class constructor and decrement it inside the Class destructor.
        Class() 
        { 
            ++Counter; 
        };

        ~Class() 
        { 
            --Counter; 
            if(Counter == 0) 
                cout << "Bye, bye!" << endl; 
        };

        void HowMany() 
        { 
            cout << Counter << " instances" << endl; 
        }
};

int Class::Counter = 0;

int main() 
{
    Class a;
    Class b;

    cout << Class::Counter << " instances so far" << endl;

    Class c;
    Class d;

    d.HowMany();

    return 0; 
}
```

Output:

```text
2 instances so far
4 instances
Bye, bye!
```

## Static class variables

Code:

```cpp
/*
There are no obstacles to making a particular variable private and static at the same time. This will obviously prevent direct access to the variable, 
but it may be something we want if we want to protect the value against any unauthorized modification.
*/

#include <iostream>
using namespace std;

class Class {
	static int Counter;

    public:
        Class() { 
            ++Counter; 
        };

        ~Class() 
        { 
            --Counter;
            if(Counter == 0) 
                cout << "Bye, bye!" << endl; 
        };

        void HowMany() 
        { 
            cout << Counter << " instances" << endl; 
        }
};

/* 
Note that any attempts to access the Counter variable expressed like this:
    Class::Counter = 1;
are strictly prohibited. 
*/
int Class::Counter = 0;

int main()
{
    Class a;
    Class b;

    b.HowMany();

    Class c;
    Class d;

    d.HowMany();

    return 0; 
}
```

Output:

```text
2 instances
4 instances
Bye, bye!
```

## Static class variables

Code:

```cpp
/*
It’s not only class variables that can be declared as static – functions can be declared like this, too.
The program displays a program containing a class with two static components: a variable and a function.
*/

#include <iostream>
using namespace std;

class Class {
	static int Counter;

    public:
        Class()
        { 
            ++Counter; 
        };

        ~Class()
        { 
            --Counter; 
            if(Counter == 0) 
                cout << "Bye, bye!" << endl; 
        };

        /* 
        The static function, like a static variable, may also be accessed (or more precisely, invoked) when no instances of the class have been created.
        Note that the static function may be invoked from inside the class, like this:
            HowMany();
        or by using any of the existing instances, like this:
            b.HowMany();
        */
        static void HowMany() 
        { 
            cout << Counter << " instances" << endl; 
        }
};

int Class::Counter = 0;

int main()
{
    Class::HowMany();

    Class a;
    Class b;

    b.HowMany();

    Class c;
    Class d;

    d.HowMany();

    return 0; 
}
```

Output:

```text
0 instances
2 instances
4 instances
Bye, bye!
```

## Example 13

Code:

```cpp
/* 
A case when a static function named funS2 tries to invoke another static function named funS1.
A case like this is always possible, as both functions are available during the entire life of the program. 
They can be successfully accessed from within an object and from within the class.
*/

#include <iostream>
using namespace std;

class Test {
    public:
        static void funS1() 
        { 
            cout << "static" << endl; 
        }

        static void funS2() 
        { 
            funS1(); 
        }
};

int main()
{
    Test object;

    Test::funS2();
    object.funS2();

    return 0; 
}
```

Output:

```text
static
static
```

## Example 14

Code:

```cpp
/* 
A case when a static function named funS1 tries to invoke a non-static function named funN1.
A case like this is not possible, as the function being invoked exists when and only when any of the objects which contain this function also exists. 
The function cannot be successfully accessed without specifying the associated object.
This program cannot be successfully compiled.
*/

#include <iostream>
using namespace std;

class Test {
    public:
        void funN1() 
        { 
            cout << "non-static" << endl; 
        }

        static void funS1() 
        { 
            funN1(); 
        }
};

int main()
{
    Test object;

    Test::funS1();
    object.funS1();

    return 0; 
}
```

Output:

```text
error: cannot call member function ‘void Test::funN1()’ without object
```

## Example 15

Code:

```cpp
/* 
Refers to the situation where a non-static function named funN1 invokes a static function named funS1.
A case like this is always possible, as the static function is available before any object has been created.
*/

#include <iostream>
using namespace std;

class Test {
    public:
        static void funS1() 
        { 
            cout << "static" << endl; 
        }

        void funN1() 
        { 
            funS1(); 
        }
};

int main()
{
    Test object;

    object.funN1();

    return 0; 
}
```

Output:

```text
static
```

## Pointers to objects

Code:

```cpp
/*
We’ve treated objects like ordinary variables and assumed that an object is created in the place where it is declared and destroyed when its declaration scope is exited. 
This is only one of the many possible object incarnations. Objects may also exist as dynamically created and destroyed entities. 
In other words, objects may appear on demand – when they’re needed – and vanish in the same way.
*/

#include <iostream>
using namespace std;

/* 
The class has no fields and no member functions. There’s only one constructor and one destructor within this class. 
They both do nothing – their only activity is to announce that they’ve been invoked.
*/
class Class {
    public:
        Class() 
        {
            cout << "Object constructed!" << endl;
        }

        ~Class() 
        {
            cout << "Object destructed!" << endl;
        }
};

/* The main function declares the ptr variable, which is a pointer to objects of the Class class. 
Next, we’ve created one object of that class using the new keyword. Note that we can omit the empty parentheses after the Class name – in either case, 
the parameter-less constructor will be activated - check it, please. Finally, the object is destroyed using the delete keyword. 
The process of destroying the object begins with the implicit invocation of its destructor.*/
int main() 
{
    Class *ptr = new Class();

    delete ptr;

    return 0; 
}
```

Output:

```text
Object constructed!
Object destructed!
```

## Pointers to fields

Code:

```cpp
/*
All the variables, including objects, brought to life in the “ordinary” way (by declaration, not by the use of the new keyword) 
live in a separate area of memory called the stack. It’s a memory region dedicated to storing all automatic entities.
Try to imagine the stack as a living creature whose size varies during the execution of the program. The stack grows when new automatic 
variables are created and shrinks when the variables are no longer needed.
The entities created “on demand” (by the new keyword) are created in a specific memory region usually called a heap. 
In contrary to the stack, the heap is almost fully under our control. We decide how many variables, arrays, objects, etc. 
will occupy the heap and it’s up to us when these entities end their lives.
The object being stored in the heap must be accessed in a way that resembles the access to the dynamically allocated structures. 
You mustn’t use the ordinary “dotted” notation as there’s no structure (object) which can play the role of the left argument of the "." operator 
unless you dereference the pointer. You need to use the “arrow” (->) operator instead.
*/

#include <iostream>
using namespace std;

/* 
We’ve added one field to the Class. It’s declared in the public part of the class so we can access it freely from outside the class.
The static entities accessed at the class level using the :: operator behave as usual.
*/ 
class Class {
    public:
        Class()
        {
            cout << "Object constructed!" << endl;
        }

        ~Class()
        {
            cout << "Object destructed!" << endl;
        }

        int value;
};

int main()
{
    Class *ptr = new Class;

    // There’s one catch – we have to use the “->” operator.
    ptr -> value = 0;
    cout << "++(ptr -> value) = " << ++(ptr -> value) << endl;
    delete ptr;

    return 0; 
}
```

Output:

```text
Object constructed!
++(ptr -> value) = 1
Object destructed!
```

## Pointers to functions

Code:

```cpp
/*
Member functions invoked for an object accessed through the pointer have to be accessed using the arrow operator, too.
We’ve added a member function to our class.
*/

#include <iostream>
using namespace std;

class Class {
    public:
        Class()
        {
            cout << "Object constructed!" << endl;
        }

        ~Class()
        {
            cout << "Object destructed!" << endl;
        }

        void inc_and_print()
        {
            cout << "value = " << ++value << endl;
        }

        int value;
};	

int main()
{
    Class *ptr = new Class;

    ptr -> value = 1;
    ptr -> inc_and_print();
    delete ptr;

    return 0; 
}
```

Output:

```text
Object constructed!
value = 2
Object destructed!
```

## Selecting the constructor

Code:

```cpp
/*
If a class has more than one constructor, one of them may be chosen during object creation. This is done by specifying the form of the parameter 
list associated with the class name. The list should be unambiguously compatible with one of the available class constructors.
*/

#include <iostream>
using namespace std;

// There are already two constructors.
class Class {
    public:
        Class()
        { 
            cout << "Object constructed (#1)" << endl; 
        }

        Class(int value) 
        { 
            this -> value = value; 
            cout << "Object constructed (#2)" << endl; 
        }

        ~Class()
        { 
            cout << "Object destructed! val = " << value << endl; 
        }

        void inc_and_print()
        {
            cout << "value = " << ++value << endl;
        }

        int value;
};

/* 
We’ve created two new objects inside the main functions. They differ in the constructor used to build each of the objects. 
In effect, their value fields have different values assigned to them.
*/
int main()
{
    Class *ptr1 = new Class, *ptr2 = new Class(2);

    ptr1 -> value = 1;
    ptr1 -> inc_and_print();
    ptr2 -> inc_and_print();

    delete ptr2;
    delete ptr1;

    return 0; 
}
```

Output:

```text
Object constructed (#1)
Object constructed (#2)
value = 2
value = 3
Object destructed! val = 3
Object destructed! val = 2
```

## Pointers to objects

Code:

```cpp
#include <iostream>
using namespace std;

/* 
There’s a class that implements a very simple array containing elements of type int. The size of the array is determined by 
the parameter’s value passed to the constructor of the class.
The class offers us two methods for accessing the array. The first (named get()) returns the value of the element stored in 
the cell of an index specified by the value of the parameter. The second (named put()) is able to set a new value of the selected 
cell (the parameters of the functions specify the index and the value respectively).
*/

class Array {
    int *values;
    int  size;

    public:
        Array(int size)
        { 
            this -> size = size; 
            values = new int[size];
            cout << "Array of " << size << " ints constructed." << endl; 
        }

        ~Array()
        { 
            delete [] values; 
            cout << "Array of " << size << " ints destructed." << endl; 
        }

        int get(int index)
        { 
            return values[index];
        }

        void put(int index, int value) 
        { 
            values[index] = value;
        }
};

int main()
{
    Array *arr = new Array(2);

    for(int i = 0; i < 2; i++)
        arr -> put(i, i + 100);

    for(int i = 0; i < 2; i++)
        cout << "#" << i + 1 << ": " << arr -> get(i) << endl;

    delete arr;

    return 0; 
}
```

Output:

```text
Array of 2 ints constructed.
#1: 100
#2: 101
Array of 2 ints destructed.
```

##  Vectors of pointers to objects

Code:

```cpp
// There are no obstacles to gathering pointers to objects inside a vector. The program demonstrates the syntax we need to use in order to access such a collection.

#include <iostream>
#include <vector>
using namespace std;

class Array {
    int *values;
    int  size;

    public:
        Array(int size) { 
            this -> size = size;
            values = new int[size];
            cout << "Array of " << size << " ints constructed." << endl; 
        }

        ~Array()
        { 
            delete [] values; 
            cout << "Array of " << size << " ints destructed." << endl; 
        }

        int get(int index)
        { 
            return values[index];
        }

        void put(int index, int value)
        { 
            values[index] = value; 
        }
};  

/* 
We’ve used two objects of the Array class and stored pointers to them in the ptrvect vector (don’t confuse these two entities: 
Array is a class defined by us, ptrvect is an ordinary, language built-in vector).
*/
int main()
{
    vector<Array *> ptrvect = {new Array(2), new Array(2)};

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            ptrvect[i] -> put(j, j + 10 + i);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            cout << "#" << i + 1 << ":" << ptrvect[i] -> get(j) << "; ";
        cout << endl;
    }

    delete ptrvect[0];
    delete ptrvect[1];

    return 0; 
}
```

Output:

```text
Array of 2 ints constructed.
Array of 2 ints constructed.
#1:10; #1:11; 
#2:11; #2:12; 
Array of 2 ints destructed.
Array of 2 ints destructed.
```

## Objects inside objects are

Code:

```cpp
// An object of any class may be the field of an object of any other class. All rules concerning access to class components are honoured in this case too.

#include <iostream>
using namespace std;

// There’s a very simple class named Element. It’s intended to store one int value. 
class Element {
    int value;

    public:
        int get()
        { 
            return value; 
        }

        void put(int value)
        { 
            this -> value = value;
        }
};

// There’s an interesting thing about class Collection: there are two fields of the Element class.
class Collection {
    Element el1, el2;

    public:	
        int get(int elno)
        { 
            return elno == 1 ? el1.get() : el2.get(); 
        }

        void put(int elno, int val)
        { 
            if(elno == 1) 
                el1.put(val); 
            else
                el2.put(val); 
        }
};

int main()
{
    Collection coll;

    for(int i = 1; i <= 2; i++)
        coll.put(i, i + 1);

    for(int i = 1; i <= 2; i++)
        cout << "Element #" << i << " = " << coll.get(i) << endl;

    return 0; 
}
```

Output:

```text
Element #1 = 2
Element #2 = 3
```

## Objects inside objects

Code:

```cpp
// Constructors from inner objects (objects stored inside other objects) are invoked before the outer object’s constructors start their work.

#include <iostream>
using namespace std;

class Element {
    int value;

    public:
        Element()
        { 
            cout << "Element constructed!" << endl; 
        }

        int get()
        { 
            return value; 
        }

        void put(int val)
        { 
            value = val; 
        }
};

class Collection {
    Element el1, el2;

    public: 
        Collection()
        { 
            cout << "Collection constructed!" << endl; 
        }

        int get(int elno)
        { 
            return elno == 1 ? el1.get() : el2.get();
        }

        void put(int elno, int val)
        { 
            if(elno == 1)
                el1.put(val);
            else
                el2.put(val); 
        }
};

int main()
{
    Collection coll;

    return 0; 
}
```

Output:

```text
Element constructed!
Element constructed!
Collection constructed!
```

## Objects inside objects

Code:

```cpp
// We want a constructor other than the default one to be invoked during the creation of an object which is part of another object.

#include <iostream>
using namespace std;

class Element {
    int value;

    public:
        Element(int value)
        { 
            this -> value = value;
            cout << "Element(" << value << ") constructed!" << endl; 
        }

        int get()
        { 
            return value; 
        }

        void put(int val)
        { 
            value = val; 
        }
};

/* 
The inner constructors have been invoked in the sequence reflecting the order of the declaration inside the Collections class (el1 first), 
not in the order in which the constructors were listed in the Class constructor header (el2 first).
*/
class Collection {
    Element el1, el2;

    public: 
        // We want a constructor other than the default one to be invoked during the creation of an object which is part of another object.
        Collection() : el2(2), el1(1) 
        { 
            cout << "Collection constructed!" << endl; 
        }

        int get(int elno) 
        { 
            return elno == 1 ? el1.get() : el2.get(); 
        }

        void put(int elno, int val)
        { 
            if(elno == 1) 
                el1.put(val); 
            else 
                el2.put(val); 
        }
};

int main() {
    Collection coll;

    return 0; 
}
```

Output:

```text
Element(1) constructed!
Element(2) constructed!
Collection constructed!
```