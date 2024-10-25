# Introduction to Computer Programming

## Example 1

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
	cout << "It's me, your first program." << endl;

	return 0;
}
```

Output:

```text
It's me, your first program.
```

## Example 2

Code:

```cpp
#include <iostream>
#include <iomanip> // Setbase manipulator requires a header file called iomanip
using namespace std;

int main()
{
	int byte = 255;

	cout << setbase(16) << byte << endl; // Setbase manipulator instructs the stream on what base value it should use during conversion

    return 0;
}
```

Output:

```text
ff
```

## Example 3

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    char character = 'X', minus = '-';
    float floating = 2.5;

    /*
    In general, output streams (including cout) are able to recognize the type of the printed value and act accordingly 
    i.e. they’ll use a proper form of data presentation for char and float values.
    */
    cout << character << minus << floating << endl;

    return 0;
}
```

Output:

```text
X-2.5
```

## Example 4

Code:

```cpp
#include <iostream>
using namespace std;

int main()
{
    char character = 'X';
    int integer = character; // ASCII code is placed inside an int variable

    /*
    cout is able to recognize the actual type of its element even when it is an effect of a 
    conversion (an phenomenon which occurs when data is subject to type change).
    */
    cout << character << " " << static_cast<int>(character) << endl;
    cout << integer << " " << static_cast<char>(integer) << endl;

    return 0;
}
```

Output:

```text
X 88
88 X
```

## Example 5

Code:

```cpp
#include <iostream>
using namespace std;

int main() 
{
    int value;

    cout << "Give me a number and I will square it!\n";
    cout << "Number: ";
    cin >> value; // Prompts the user to enter a single integer value

    int square = value * value; // Squares it

    cout << "\nYou've given " << value << endl;
    cout << "The squared value is " << square << endl; // Prints the result with an appropriate comment

    return 0;
}
```

Output:

```text
Give me a number and I will square it!
Number: 5

You've given 5
The squared value is 25
```

## Example 6

Code:

```cpp
#include <iostream>
#include <cmath> // To use sqrtf you need to include a header file named cmath
using namespace std;

int main() 
{
    float value;

    cout << "Give me a number and I will find its square root:" << endl;
    cout << "Number: " ;
    cin >> value;

    if(value >= 0.0) { // If we enter a negative number, the program will just ignore the input completely
        float squareroot = sqrtf(value); // sqrtf (square root float) needs exactly one argument

        cout << "\nYou have given: " << value << endl;
        cout << "The square root is: " << squareroot << endl;
    }

    return 0;
}
```

Output:

```text
Give me a number and I will find its square root:
Number: 64

You have given: 64
The square root is: 8
```