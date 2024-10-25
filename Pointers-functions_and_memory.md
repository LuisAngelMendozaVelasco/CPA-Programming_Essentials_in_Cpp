# Pointers-functions and memory

## How the computer and compiler use the memory

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    cout << "This computing environment uses:" << endl;
    cout << sizeof(char) << " byte for chars" << endl;
    cout << sizeof(short int) << " bytes for shorts" << endl;
    cout << sizeof(int) << " bytes for ints" << endl;
    cout << sizeof(long int) << " bytes for longs" << endl;
    cout << sizeof(float) << " bytes for floats" << endl;
    cout << sizeof(double) << " bytes for doubles" << endl;
    cout << sizeof(bool) << " byte for bools" << endl;
    cout << sizeof(int *) << " bytes for pointers" << endl;

    return 0;
}
```

Output:

```text
This computing environment uses:
1 byte for chars
2 bytes for shorts
4 bytes for ints
8 bytes for longs
4 bytes for floats
8 bytes for doubles
1 byte for bools
8 bytes for pointers
```

## Pointers and vectors

Code:

```cpp
/*
The declaration of pointers follows this syntax:
    type * name;
where type is the data type pointed to by the pointer. This type is not the type of the pointer itself, 
but the type of the data the pointer points to.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	vector<int> vect {1, 2, 3}; // Three-element vector of type int.

    // Store information about the location of the data.
	int *ptr = vect.data(); // Return a pointer (initially set to a value associated with a very first element of the vector!).
	int *ptr2 = &vect[0]; // Store the address into the pointer.
    
    cout << "ptr: " << ptr << endl;
    cout << "ptr2: " << ptr2 << endl;
	cout << "(ptr == prt2): " << (bool)(ptr == ptr2) << endl; // ptr and ptr2 point to the same location inside memory - the first vector's element.

    return 0;
}
```

Output:

```text
ptr: 0x55cb87a772b0
ptr2: 0x55cb87a772b0
(ptr == prt2): 1
```

## Example 3

Code:

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> numbers {1, 2, 3};
    int *ptr = numbers.data() + 1; // Initial ptr's value points to numbers[1].

    cout << "Original numbers[0]: " << numbers[0] << endl;
    /* 
    ptr[-1] points to numbers[0]
    ptr[1] points to numbers[2]
    assignment can be rewritten as:
    *(ptr - 1) = *ptr + *(ptr + 1);
    */
    ptr[-1] = *ptr + ptr[1]; // Equivalent of numbers[0] = numbers[1] + numbers[2];
    cout << "Modified numbers[0]: " << numbers[0] << endl;

    return 0;
}
```

Output:

```text
Original numbers[0]: 1
Modified numbers[0]: 5
```

## Functions

Code:

```cpp
#include <iostream>
using namespace std;

/*
The parameters defined within the function are called formal parameters. 
The values actually transferred to the function (thus existing outside the function) 
are called actual parameters or arguments.
*/
float square(float x) 
{
    float result = x * x;

    return result;
}

int main() 
{
    float arg = 2.0;

    cout << "The second power of " << arg << " is " << square(arg) << endl;

    return 0;
}
```

Output:

```text
The second power of 2 is 4
```

## Example 5

Code:

```cpp
// It is possible to place the square function after the main function and not before.

#include <iostream>
using namespace std;

// Have to put the function declaration before the first function invocation.
float square(float);

int main() 
{
    float arg = 2.0;

    cout << "The second power of " << arg << " is " << square(arg) << endl;

    return 0;
}

float square(float x) 
{
    float result = x * x;

    return result;
}
```

Output:

```text
The second power of 2 is 4
```

## Example 6

Code:

```cpp
// The program asks a user for the size of his/her ego and responds with an adequate greeting.

#include <iostream>
using namespace std;

void greet() 
{
    cout << "Ave user!" << endl;
}

void greet_many_times(int how_many_times) 
{
    while (how_many_times > 0) {
        greet();
        how_many_times--;
    }
}

int main() 
{
    int size_of_ego;

    cout << "How big is your ego? [km]: ";
    cin >> size_of_ego;
    greet_many_times(1 + size_of_ego);

    return 0;
}
```

Output:

```text
How big is your ego? [km]: 1
Ave user!
Ave user!
```

## Converting temperature from Fahrenheit to Celsius

Code:

```cpp
#include <iostream>
using namespace std;

float fahrenheit_to_celsius(float temp) 
{
    return ((temp - 32.0) * 5.0) / 9.0;
}

void test_the_function(float temp) 
{
    cout << "Fahrenheit " << temp << " corresponds to " <<	fahrenheit_to_celsius(temp) << " Celcius" << endl;
}

int main() 
{
    test_the_function(32.0);
    test_the_function(212.0);
    test_the_function(451.0);

    return 0;
}
```

Output:

```text
Fahrenheit 32 corresponds to 0 Celcius
Fahrenheit 212 corresponds to 100 Celcius
Fahrenheit 451 corresponds to 232.778 Celcius
```

## Local and global variables

Code:

```cpp
/*
Local variable:
Any variable defined inside the function's body can be neither used nor accessed from outside the function. 
We can say that variables are isolated from the outer world. 
Moreover, such variables exist only when the function is executed and disappear when the function completes its execution. 
This means they cannot be used to store value between function invocations.

Global variable:
They are declared outside any function and thus are accessible for all the functions declared in the same source file.
Note that the variable declaration has to precede the function definition in order to be recognizable by the function.
Global variables allow functions to get and to provide data of any kind. If a function modifies any global variable that 
isn’t using any other mechanism of transferring data, we say that this function has a side effect.
*/

#include <iostream>
using namespace std;

int globvar = 0;

void func() 
{
    cout << "Thank you for invoking me :)" << endl;
    globvar++;
}

int main() 
{
    for (int i = 0; i < 5; i++)
        func();

    cout << endl << "The function was happy " << globvar << " times" << endl;

    return 0;
}
```

Output:

```text
Thank you for invoking me :)
Thank you for invoking me :)
Thank you for invoking me :)
Thank you for invoking me :)
Thank you for invoking me :)

The function was happy 5 times
```

## Example 9

Code:

```cpp
/* 
In a funtion the parameter's value doesn't replace the argument's value upon return from the function. 
We can say that the argument has a one-way ticket: it transports a value to the function and doesn't take it up to the invoker.
Don't forget that. This way of communication is based on transferring a value from the invoker to the function. 
And that’s why this method is called passing parameters by value.
*/

#include <iostream>
using namespace std;

void can_i_change_my_argument(int param)
{
    cout << "----------" << endl;
    cout << "I have got: " << param << endl;
    param++;
    cout << "I'm about to give back: " << param << endl;
    cout << "----------" << endl;
}

int main() 
{
    int var = 1;

    cout << "var = " << var << endl;
    can_i_change_my_argument(var);
    cout << "var = " << var << endl;

    return 0;
}
```

Output:

```text
var = 1
----------
I have got: 1
I'm about to give back: 2
----------
var = 1
```

## Passing by reference

Code:

```cpp
/*
When a parameter is passed by reference it means that a parameter is just a synonym of an argument. 
Every modification made into a parameter immediately affects an associated argument. 
We can informally say that arguments passed by reference have return tickets and bring their modified values back to the invoker.*/

#include <iostream>
using namespace std;

/* 
To pass any parameters by reference, wee need to announce it while declaring the function.
type& name – the name parameter is passed by reference
*/
void can_i_change_my_argument(int& param) 
{
    cout << "----------" << endl;
    cout << "I have got: " << param << endl;
    param++;
    cout << "I'm about to give back: " << param << endl;
    cout << "----------" << endl;
}

int main() 
{
    int var = 1;

    cout << "var = " << var << endl;
    can_i_change_my_argument(var);
    cout << "var = " << var << endl;

    return 0;
}
```

Output:

```text
var = 1
----------
I have got: 1
I'm about to give back: 2
----------
var = 2
```

## Passing by value and passing by reference

Code:

```cpp
// Use the “passing by value” if you don't need to share the function's results using the parameter's values, and use “passing by reference” in all other cases.
#include <iostream>
using namespace std;

void mixed_styles(int bval, int& bref) { // The first parameter is passed by value, while the second is passed by reference
    bref = bval + 1;
}

int main(void) {
    int var1 = 1, var2;

    mixed_styles(var1, var2);
    cout << "var1 = " << var1 << ", var2 = " << var2 << endl;

    return 0;
}
```

Output:

```text
var1 = 1, var2 = 2
```

## Passing by reference limitation

Code:

```cpp
/*
A function can’t place a value in something other than a variable. It cannot assign a new value to a literal, or force an expression to change its result. 
All the following invocations are permitted:
    by_val(var);
    by_val(var + 2);
    by_val(var * fun(1));
If you want to modify the invocations to take advantage of the by_ref() function, you can only use the first one. All the others will cause a compilation error.*/

#include <iostream>
using namespace std;

/*
An argument referring to a “passed by value” parameter may be an expression in general, 
so we can use not only a variable but also a literal, or even a function invocation's result.
*/
void by_val(int parameter)
{
    parameter++;
}

/* 
If a parameter is declared as passed by reference (so it is preceded by the & sign) 
its corresponding argument must be a variable.
*/
void by_ref(int& parameter)
{
    parameter++;
}

int main()
{
    int var = 1;

    by_val(var);
    cout << "var = " << var << endl;

    by_ref(var);
    cout << "var = " << var << endl;

    return 0;
}
```

Output:

```text
var = 1
var = 2
```

## Passing parameters by value

Code:

```cpp
/*
It is possible to utilize “passing by value” and be able to propagate the  value outside the function despite the one-way nature of this method.
The idea is based on transferring a pointer to a value, not the value itself. 
If you declare a function with a prototype like this one:
    void by_ptr(int* ptr);
you enable the function to deal with the addresses pointing to int values, and therefore you give the function the chance to modify the values pointed to by the parameter.
*/

#include <iostream>
using namespace std;

// It's an old “passing by value” method! 
void by_ptr(int* ptr) 
{
    // If p is a pointer to a value, the *p represents the value itself.
    *ptr = *ptr + 1;
}

int main() 
{
    int variable = 1;
    int *pointer = &variable;

    by_ptr(pointer);
    cout << "variable = " << variable << endl;

    return 0;
}
```

Output:

```text
variable = 2
```

## Example 14

Code:

```cpp
#include <iostream>
using namespace std;

void new_greet(string greet, int repeats)
{
    for (int i = 0; i < repeats; i++)
        cout << greet << endl;
}

int main() 
{
    new_greet("Hi!", 5);

    return 0;
}
```

Output:

```text
Hi!
Hi!
Hi!
Hi!
Hi!
```

## Default parameters

Code:

```cpp
#include <iostream>
using namespace std;

// Signal that we want the compiler to assume the default value for the second parameter when we omit it during the invocation.
void new_greet(string greet, int repeats = 1)
{
    for (int i = 0; i < repeats; i++)
        cout << greet << endl;    
}

int main() 
{
    new_greet("Hello", 2);
    new_greet("Good morning"); // Equal to new_greet("Good morning", 1);
    new_greet("Hi", 1);

    return 0;
}
```

Output:

```text
Hello
Hello
Good morning
Hi
```

## Default parameters

Code:

```cpp
/*
This mechanism is useful, but to take full advantage of it you mustn’t forget about the following limitations:
    * the order of parameters is very important (in contrast to regular, non-default parameters which may be in virtually any order); 
      intuitively, we can say that non-default parameters must be coded before the default ones; the compiler won't be able to identify the parameters otherwise;
    * if more than one parameter is declared with a default value and at least one argument is specified in the invocation, 
      the arguments are assigned to their parameter counterparts in the same order in which they are listed in the function declaration; 
      this means that you are not allowed to use the default value for the first parameter and specify an explicit value for the second.
*/

#include <iostream>
using namespace std;

// More than one default parameter in one function.
void new_greet(string greet = "Good morning", int repeats = 1) 
{
    for (int i = 0; i < repeats; i++)
        cout << greet << endl;
}

int main(void) {
    new_greet("Hello", 2);
    new_greet("Hi");
    new_greet();

    return 0;
}
```

Output:

```text
Hello
Hello
Hi
Good morning
```

## Anatomy of a function invocation

Code:

```cpp
/*
Each function's code has to be supplemented with two important elements: a prologue and an epilogue.
A "prologue" is the part of the code implicitly executed before the function. The prologue is responsible for 
transferring arguments from the invoker's code and for storing them in a special transient area called a “stack”.
The "epilogue" is implicitly executed just after the function's code and is responsible for transferring the 
result of the function and for clearing the stack of the values placed there by the prologue.
*/

#include <iostream>
using namespace std;

int function(int parameter)
{
    return parameter * 2;
}

int main() 
{
    int var = 1;

    var = function(var);
    var = function(var);
    var = function(var);
    cout << "var: " << var << endl;

    return 0;
}
```

Output:

```text
var: 8
```

## Inline functions

Code:

```cpp
/*
The tactic of compiling function invocations is called function inlining. 
A function compiled like this is called an inline function.
It doesn't matter whether the inline keyword is placed before or after the 
name of the type; both of the following lines are syntactically correct:
    * inline int function(int parameter)
    * int inline function(int parameter)
*/

#include <iostream>
using namespace std;

inline int function(int parameter) // Inline function
{
    return parameter * 2;
}

int main()
{
    int var = 1;

    var = function(var);
    var = function(var);
    var = function(var);
    cout << "var: " << var << endl;
    
    return 0;
}
```

Output:

```text
var: 8
```

## Bubble sort

Code:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> numbers(5);

    // Ask the user to enter 5 values
    for (int i = 0; i < 5; i++) {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Sort them 
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < 4; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swapped = true;
                int aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
        }
    } while (swapped);

    // Print results 
    cout << endl << "Sorted vector: " << endl;
    for (int i = 0; i < 5; i++)
        cout << numbers[i] << " ";
    cout << endl;

    return 0;
}
```

Output:

```text
Enter value #1: 9
Enter value #2: 8
Enter value #3: 7
Enter value #4: 6
Enter value #5: 5

Sorted vector: 
5 6 7 8 9
```

## Memory on demand

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    /*
    We declare a variable called arr which will point to the data of type float (the pointer's type is float *); no value is initially assigned to this variable.
    We use the "new" keyword to allocate a block of memory sufficient to store a float array consisting of 5 elements.
    */
    float *arr = new float[5];

    for (int i = 0; i < 5; i++) {
        arr[i] = i * i;
        cout << arr[i] << endl;
    }

    // We make use of the newly allocated array (to be precise, a vector) and next we release it using the delete keyword.
    delete[] arr;

    return 0;
}
```

Output:

```text
0
1
4
9
16
```

## Memory on demand

Code:

```cpp
/*
In the following program, we allocate an array containing 5 elements of type int, 
set their values, sum them up and, finally, release the previously allocated memory.
*/ 

#include <iostream>
using namespace std;

int main()
{
    int *tabptr = new int[5], sum = 0;

    cout << "vector: ";
    for (int i = 0; i < 5; i++) {
        tabptr[i] = i;
        if (i < 4)
            cout << i << ", ";
        else
            cout << i << endl;
        sum += tabptr[i];
    }

    delete [] tabptr;
    cout << "Sum vector = " << sum << endl;

    return 0;
}
```

Output:

```text
vector: 0, 1, 2, 3, 4
Sum vector = 10
```

## Example 22

Code:

```cpp
// The bubble sort program adopted to use new and delete mechanisms is in the editor.

#include <iostream>
using namespace std;

int main() 
{
    cout << "How many numbers are you going to sort? ";
    int how_many_numbers;
    cin >> how_many_numbers;

    if(how_many_numbers <= 0 || how_many_numbers > 1000000) {
        cout << "Are you kidding?" << endl;
        return 0;
    }

    int *numbers = new int[how_many_numbers];
    for(int i = 0; i < how_many_numbers; i++) {
        cout << "Enter the number #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Bubble sort
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < how_many_numbers - 1; i++)
            if (numbers[i] > numbers[i + 1]) {
                swapped = true;
                int aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
    } while (swapped);

    cout << endl << "The sorted array:" << endl;
    for (int i = 0; i < how_many_numbers; i++)
        if (i < how_many_numbers - 1)
            cout << numbers[i] << ", ";
        else
            cout << numbers[i] << endl;

    delete[] numbers;

    return 0;
}
```

Output:

```text
How many numbers are you going to sort? 5
Enter the number #1: 9
Enter the number #2: 7
Enter the number #3: 5
Enter the number #4: 3
Enter the number #5: 1

The sorted array:
1, 3, 5, 7, 9
```