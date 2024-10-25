# Advanced flow control and data aggregates

## Example 1

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;

    if(a + b != c) // Numbers stored as floating point data can be different from their real (precise) values
        cout << "Your computer is out of order!" << endl;

    return 0;
}
```

Output:

```text
Your computer is out of order!
```

## Finding the larger of two numbers

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int number1, number2;

    // Read two .
    cout << "Number 1: ";
    cin >> number1;
    cout << "Number 2: ";
    cin >> number2;

    // We will save the larger number here, we temporarily assume that the former number is the larger one, we will check it soon.
    int max = number1;

    // We check if the assumption was false.
    if (number2 > max)
        max = number2;

    // We print the result.
    cout << "\nThe larger number is " << max << endl;

    return 0;
}
```

Output:

```text
Number 1: 5
Number 2: 6
The larger number is 6
```

## Finding the largest of three numbers

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int number1, number2, number3;

    // Read three numbers.
    cout << "Number 1: ";
    cin >> number1;
    cout << "Number 2: ";
    cin >> number2;
    cout << "Number 3: ";
    cin >> number3;

    // We will save the larger number here, we temporarily assume that the former number is the larger one, we will check it soon.
    int max = number1;

    // We check if the second value is the largest.
    if (number2 > max)
        max = number2;

    // We check if the third value is the largest.
    if (number3 > max)
        max = number3;

    // We print the result.
    cout << "\nThe largest number is " << max << endl;

    return 0;
}
```

Output:

```text
Number 1: 5
Number 2: 6
Number 3: 7

The largest number is 7
```

## Example 4

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    // Temporary storage for the incoming numbers.
    int number;

    // Get the first value.
    cout << "Number: ";
    cin >> number;

    // We will store the currently greatest number here.
    int max = number;

    // If the number is not equal to -1 we will continue.
    while (number != -1) {
        // Is the number greater than max?
        if (number > max)
            // Yes – update max.
            max = number;
        // Get next number.
        cout << "Number: ";
        cin >> number;
    }

    // Print the largest number.
    cout << "\nThe largest number is " << max << endl;

    return 0;
}
```

Output:

```text
Number: 1
Number: 2
Number: 3
Number: 4
Number: 5
Number: -1

The largest number is 5
```

## Counting odd and even numbers coming from the keyboard

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    // We will count the numbers here.
    int evens = 0, odds = 0;

    // We will store the incoming numbers here.
    int number;

    // Read first number.
    cout << "Number: ";
    cin >> number;

    // 0 terminates execution.
    while (number != 0) {
        // Check if the number is odd.
        if (number % 2 == 1)		
            // Increase „odd” counter.
            odds++;
        else
            // Increase „even” counter.
            evens++;
        // Read next number.
        cout << "Number: ";
        cin >> number;
    }

    // Print results.
    cout << "\nEven numbers: " << evens << endl;
    cout << "Odd numbers: " << odds << endl;

    return 0;
}
```

Output:

```text
Number: 1
Number: 2
Number: 3
Number: 4
Number: 5
Number: 0

Even numbers: 2
Odd numbers: 3
```

## Example 6

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0; // To count the numbers entered so we can instruct the user that we cannot search for the greatest number if no number is given.
    
    do {
        cout << "Number: ";
        cin >> number;

        if (number != -1)
            counter++;

        if (number > max)
            max = number;
    } while (number != -1);

    if (counter)
        cout << "\nThe largest number is " << max << endl;
    else
        cout << "\nAre you kidding? You haven't entered any number!" << endl;

    return 0;
}
```

Output:

```text
Number: 1
Number: 2
Number: 3
Number: 4
Number: 5
Number: -1

The largest number is 5
```

## Example 7

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int pow = 1;

    // The exp variable is used as a control variable for the loop and indicates the current value of the exponent.
    for(int exp = 0; exp < 16; exp++) {
        cout << "2 to the power of " << exp << " is " << pow << endl;
        pow *= 2;
    }

    return 0;
}
```

Output:

```text
2 to the power of 0 is 1
2 to the power of 1 is 2
2 to the power of 2 is 4
2 to the power of 3 is 8
2 to the power of 4 is 16
2 to the power of 5 is 32
2 to the power of 6 is 64
2 to the power of 7 is 128
2 to the power of 8 is 256
2 to the power of 9 is 512
2 to the power of 10 is 1024
2 to the power of 11 is 2048
2 to the power of 12 is 4096
2 to the power of 13 is 8192
2 to the power of 14 is 16384
2 to the power of 15 is 32768
```

##  Example 8

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0;

    for (;;) { // Infinite loop
        cout << "Number: ";
        cin >> number;

        if (number == -1)
            break; // Exits the loop immediately and unconditionally ends the loop’s operation.

        counter++;

        if (number > max)
            max = number;
    }

    if (counter)
        cout << "\nThe largest number is " << max << endl;
    else
        cout << "\nAre you kidding? You haven't entered any number!" << endl;

    return 0;
}
```

Output:

```text
Number: 1
Number: 2
Number: 3
Number: 4
Number: 5
Number: -1

The largest number is 5
```

## Example 9

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0;

    do {
        cout << "Number: ";
        cin >> number;

        if(number == -1)
            continue; // Behaves as the program suddenly reached the end of the body; the end of the loop's body is reached and the condition expression is tested immediately.

        counter++;

        if(number > max)
            max = number;
    } while (number != -1);

    if(counter)
        cout << "\nThe largest number is " << max << endl;
    else 
        cout << "\nAre you kidding? You haven't entered any number!" << endl;

    return 0;
}
```

Output:

```text
Number: 1
Number: 2
Number: 3
Number: 4
Number: 5
Number: -1

The largest number is 5
```

## Example 10

Code:

```cpp
/*
The shift operators in the C++ language are a pair of digraphs, << and >>, clearly suggesting in which direction the shift will act. 
The left argument of these operators is the integer value whose bits are shifted. The right argument determines the size of the shift. 
*/

#include <iostream>
using namespace std;

int main() 
{
    int w_sign = -8;
    unsigned wo_sign = 4; // Only represent non-negative integer numbers (positive numbers and zero).

    int var_s;
    unsigned var_u;

    // Equivalent to division by 2 –> var_s == -4
    var_s = w_sign >> 1;
    cout << var_s << endl;

    // Equivalent to multiplication by 4 –> var_s == -32
    var_s = w_sign << 2;
    cout << var_s << endl;

    // Equivalent to division by 4 –> var_u == 1
    var_u = wo_sign >> 2;
    cout << var_u << endl;

    // Equivalent to multiplication by 2 –> var_u == 2
    var_u = wo_sign << 1;
    cout << var_u << endl;

    return 0;
}
```

Output:

```text
-4
-32
1
8
```

## Vectors

Code:

```cpp
/*
The power of the modern vectors (compared to old-style solutions) lies in the fact that 
they are equipped with a numerous methods what makes them elastic and flexible.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int elements = 10;
    vector<int> vect(elements); // Vector declaration
    int current_size = vect.size(); // Vectors have a method named size which provides you with current size of the subject vector.

    cout << "Vector size: " << current_size << endl;

    return 0;
}
```

Output:

```text
Vector size: 10
```

## Vectors old-fashioned declaration

Code:

```cpp
/*
There is no simple way to determine number of vector's elements - the size() 
method does not exist and cannot be invoked 
*/

#include <iostream>
using namespace std;

int main() 
{
    /* 
    Tricks that can be used instead is to determine whole vector's size and 
    to divide it by single element's size.
    */
    int elements = 10;
    int vect[elements];
    int current_size = sizeof(vect) / sizeof(vect[0]);

    cout << "Vector size: " << current_size << endl;

    return 0;
}
```

Output:

```text
Vector size: 10
```

## Modern vectors can be freely expanded

Code:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> vect(0);
    /* 
    A method named push_back(value) is able to extend vector's size by one and 
    to put a new value at vector's end.
    */
    vect.push_back(1);
    vect.push_back(-1);
    vect.push_back(0);
    cout << "Vector size: " << vect.size() << endl;
    cout << "Vector: [";

    for(int i = 0; i < vect.size(); i++)
        if (i < vect.size() - 1)
            cout << vect[i] << ", ";
        else
            cout << vect[i] << "]" << endl;

    return 0;
}
```

Output:

```text
Vector size: 3
Vector: [1, -1, 0]
```