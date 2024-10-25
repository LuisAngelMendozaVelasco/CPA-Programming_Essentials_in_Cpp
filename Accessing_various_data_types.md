# Accessing various data types

## Triangular matrices

Code:

```cpp
/*
The advantage of such arrays is that every row may be of a different length. 
This is useful for the algorithms that don’t need the entire array to run but only a slice of it.
*/ 

#include <iostream>
using namespace std;

int main() 
{
    // The size of the allocated memory block depends on the row number.
    int rows = 5;

    /*
    Allocate and initialize the array. The type of arr is "a pointer to a pointer to int".
    The elements of the array of rows will be pointers to the rows, so their type is int*
    */
    int **arr = new int* [rows];

    // Allocate memory for every row and store the resulting pointer inside the right element of the array of rows.
    for (int r = 0; r < rows; r++) {
        arr[r] = new int[r + 1];

        for (int c = 0; c <= r; c++) {
            arr[r][c] = (r + 1) * 10 + c + 1;
            cout << arr[r][c] << " ";
        }

        cout << endl;
    }

    // Free the array.
    for (int r = 0; r < rows; r++)
        delete[] arr[r];
    delete[] arr;

    return 0;
}
```

Output:

```text
11 
21 22 
31 32 33 
41 42 43 44 
51 52 53 54 55 
```

## Explicit conversions

Code:

```cpp
/*
In general, the C++ language give us three ways to specify explicit conversions:
    * the so-called functional notation, which is a native (but currently obsoleted) C++ syntax convention 
    (named because of its similarity to the well-known function invocation); in this case the name of a new (target) 
    type is treated like a function and the conversion takes the following form:
        new_type_name(expression_of_old_type)

    * the so-called C-style casting (named after the C++ predecessor, the C programming language, 
    which used, and still uses, a syntax of that kind); in this case, we specify the conversion in the following form:
        (new_type_name) expression_of_old_type

    * the so-called static casting, a native and currently recognized as recommended C++ syntax convention 
    where the conversion is done by an operator named static_cast; the operator takes the following form:
        static_cast<new_type_name>(expression_of_old_type)
*/

#include <iostream>
using namespace std;

int main() 
{
    float f = 3.21;
    double d = 1.23;
    long double l = 9.87;

    /*
    int(f) -> functional notation
    (int)d -> C-style casting
    static_cast<int>(l) -> static 
    */
    int k = int(f) + (int)d + static_cast<int>(l);

    cout << "int(3.21) + (int)1.23 + static_cast<int>(9.87) = " << k << endl;

    return 0;
}
```

Output:

```text
int(3.21) + (int)1.23 + static_cast<int>(9.87) = 13
```

## Conversions – gains and losses

Code:

```cpp
/*
Every time a conversion happens, the compiler does its best to preserve the original value, 
but that’s not always possible.
*/

#include <iostream>
using namespace std;

int main() 
{
    /*
    A good scenario is when the length of the memory representation remains the same or increases; 
    we can be confident then that the original value will be preserved. 
    */
    short s = 32767;
    int i = s;

    cout << "(" << s << " == " << i << "): ";
    if (i == s)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
```

Output:

```text
(32767 == 32767): equal
```

## Conversions – gains and losses

Code:

```cpp
// We want to transfer the maximum value allowed for the int variables to the short variable.

#include <iostream>
using namespace std;

int main() 
{
    int i = 2147483647;
    short s = i;

    /*
    As the short integers usually use twice less bits than regular integers, 
    some higher bits of the i variable will be irretrievably lost during implicit conversion.
    */
    cout << "(" << s << " == " << i << "): ";
    if (i == s)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
        
    return 0;
}
```

Output:

```text
(-1 == 2147483647): not equal
```

## Conversions – gains and losses

Code:

```cpp
/*
We'll convert the float value into a double value.
double values have not only a wider range than floats, but also better accuracy (precision).
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float f = 1234.5678;
    double d = f;
    
    cout << fixed;
    cout << setprecision(4);

    cout << "(" << f << " == " << d << "): ";
    if (d == f)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
```

Output:

```text
(1234.5677 == 1234.5677): equal
```

## Conversions – gains and losses

Code:

```cpp
/*
The value being converted is small enough to be stored in any float variable. 
The issue here is precision.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    // Floats can’t store as many significant digits as specified in the literal assigned to the d variable.
    double d = 123456.789012;
    float f = d;
    
    cout << fixed;
    cout << setprecision(6);

    cout << "(" << f << " == " << d << "): ";
    if (d == f)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    return 0;
}
```

Output:

```text
(123456.789062 == 123456.789012): not equal
```

## Conversions – gains and losses

Code:

```cpp
/*
Conversions from floating point types to integral types always cause a loss of accuracy. 
There’s no escaping this.  We always lose the fractional part of a float number.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    /* 
    Also when the float is extremely large (or extremely small) we’ll also experience a loss of value. 
    This applies to the values beyond the scope of the target integral type.
    */
    float f = 123.456;
    float g = 1e100;
    int i = f;
    int j = g;

    cout << fixed;
    cout << setprecision(3);
    cout << f << " -> " << i << endl;
    cout << g << " -> " << j << endl;

    return 0;
}
```

Output:

```text
123.456 -> 123
inf -> -2147483648
```

## Conversions – gains and losses

Code:

```cpp
/*
When one int and one short are used in the same expression, we can expect that the value of the narrower range (short) 
will be promoted to the type with the wider range (int) and there won’t be any loss of value.
Similarly, when a float meets a double in the same expression, the float will be promoted to a double.

*/
#include <iostream>
using namespace std;

int main() 
{
    int Int = 2;
    char Char = 3;
    short Short = 4;
    float Float = 5.6;

    /*
    We can predict that the following implicit conversions will take place:
        * promotions go first, resulting in the following conversions:
            int(Short) + int(Char)

        * the sum of Short and Char as well as the Float variable will be converted to double, that is:
            double((int(Short) + int(Char)) + double(Float))

        * the final sum will be calculated as a double, but because of the context (arising from the type of the left argument of the = operator) 
          which is int, another conversion into an int type takes place; hence, the final form of the expression looks like this:
            int(double((int(Short) + int(Char)) + double(Float)))
    */
    Int = Short + Char + Float;
    cout << "Short + Char + Float: " << Int << endl;

    return 0;
}
```

Output:

```text
Short + Char + Float: 12
```

## String operators: +

Code:

```cpp
// It concatenates strings (i.e. it glues them together, giving a new string which  has arisen out of the values of its arguments)
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string good = "Jekyll", bad = "Hyde";

    cout << good + " & " + bad << endl;
    cout << bad + " & " + good << endl;

    return 0;
}
```

Output:

```text
Jekyll & Hyde
Hyde & Jekyll
```

## String operators: +

Code:

```cpp
/*
The + (concatenation) operator has one important limitation. It cannot concatenate literals. 
It can concatenate any variable with a literal, a literal with a variable, and obviously a variable with another variable, 
but concatenating literals is something the operator will never do.
*/

#include  <iostream>
#include  <string>
using namespace std;

int main() 
{
    string s;

    // s = "A" + "B";
    s = s + "C"; // Variable with a literal
    s = "B" + s; // Literal with a variable
    cout << "Concatenated string: " << s << endl;

    return 0;
}
```

Output:

```text
Concatenated string: BC
```

## String operators: +=

Code:

```cpp
// + may be used as a short-cut operator.

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string the_question = "To be ";

    the_question += "or not to be.";
    cout << the_question << endl;

    return 0;
}
```

Output:

```text
To be or not to be.
```

## Inputting strings

Code:

```cpp
/*
Inputting strings is a bit more complicated, due to the fact that the cin stream treats spaces 
(to be precise, not only regular spaces but also all so-called white characters) as delimiters, 
demarcating limits between data. 
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string line_of_types;

    cout << "Input string: ";
    cin >> line_of_types;
    cout << "String: " << line_of_types << endl;

    return 0;
}
```

Output:

```text
Input string: Luis Mendoza
String: Luis
```

## Inputting strings

Code:

```cpp
/*
To input a whole line of text and treat the white characters just like any other character, we have to use the getline() function. 
This function gets/reads all the characters entered as-is and does not favour any character except from the char representing the key, 
which marks the end of the line. As a result, all the characters entered before pressing the key will be input as one string.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string line_of_types;

    cout << "Input string: ";
    getline(cin, line_of_types);
    cout << "String: " << line_of_types << endl;

    return 0;
}
```

Output:

```text
Input string: Luis Mendoza
String: Luis Mendoza
```

## Comparing strings

Code:

```cpp
/*
Strings (just like any other data) may be compared. 
The simplest case occurs when you want to check if two variables of type string contain identical strings.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string secret = "abracadabra";
    string password;

    cout << "Enter password: ";
    getline(cin, password);
    if (secret == password)
        cout << "Access granted!" << endl;
    else
        cout << "Sorry!" << endl;

    return 0;
}
```

Output:

```text
Enter password: abracadabra
Access granted!
```

## Comparing strings

Code:

```cpp
/*
We can compare two strings in more flexible ways too. All the operators designed to compare data: > < >= <= !=. 
We can check if one of the strings is greater/lesser than the other, but remember that these comparisons are 
carried out in alphabetical order where 'a' is greater than 'A' (sic) and obviously 'z' is greater than 'a', 
but less obviously, 'a' is greater than '1'.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1, str2;

    cout << "Enter 2 lines of text:" << endl;
    cout << "First line: ";
    getline(cin, str1);
    cout << "Second line: ";
    getline(cin, str2);
    cout << endl << "You've entered:" << endl;

    if (str1 == str2)
        cout << "\"" << str1 << "\" == \"" << str2 << "\"" << endl;
    else if (str1 > str2)
        cout << "\"" << str1 << "\" > \"" << str2 << "\"" << endl;
    else
        cout << "\"" << str2 << "\" > \"" << str1 << "\"" << endl;

    return 0;
}
```

Output:

```text
Enter 2 lines of text:
First line: Luis
Second line: Mendoza

You've entered:
"Mendoza" > "Luis"
```

## Comparing strings – the object-oriented approach

Code:

```cpp
/*
Strings offer another more complex, but also more powerful, method of comparison.
The member function is called “compare” and the name speaks for itself: it’s designed to compare a string with another string. 
The member function returns 0 (zero) if the strings are identical.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string secret = "abracadabra";
    string password;

    cout << "Enter password: ";
    getline(cin, password);

    if (!secret.compare(password))
        cout << "Access granted!" << endl;
    else
        cout << "Sorry!" << endl;

    return 0;
}
```

Output:

```text
Enter password: abracadabra
Access granted!
```

## Comparing strings – the object-oriented approach

Code:

```cpp
/*
The possibilities of the compare member function don’t stop at checking the identity of the strings. 
The function can also diagnose all of the possible relations between two strings. Here’s how it works:
    * str1.compare(str2) == 0 when str1 == str2
    * str1.compare(str2) > 0 when str1 > str2
    * str1.compare(str2) < 0 when str1 < str2
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1, str2;

    cout << "Enter 2 lines of text:" << endl;
    cout << "First line: ";
    getline(cin, str1);
    cout << "Second line: ";
    getline(cin, str2);
    cout << endl << "You've entered:'" << endl;

    if (str1.compare(str2) == 0)
        cout << "\"" << str1 << "\" == \"" << str2 << "\"" << endl;
    else if (str1.compare(str2) > 0)
        cout << "\"" << str1 << "\" > \"" << str2 << "\"" << endl;
    else
        cout << "\"" << str2 << "\" < \"" << str1 << "\"" << endl;

    return 0;
}
```

Output:

```text
Enter 2 lines of text:
First line: Luis
Second line: Mendoza

You've entered:'
"Mendoza" < "Luis"
```

## Substrings

Code:

```cpp
/*
The strings allow themselves to be processed in a more precise way when only selected parts of them are taken into consideration. 
A part of a string is called a "substring".
If we want to create a new string consisting of characters taken from another (or even the same) string's substring, 
we can use a member function called substr, and its simplified, informal prototype looks like this:
    newstr = oldstr.substr(substring_start_position, length_of_substring).

The substring of any string is defined by two “coordinates”:
    * a place where the substring begins (specified by the substring_start_position parameter);
    * its length (specified by the length_of_substring parameter).
Note that characters within a string are numbered, and the first character is that number 0. Therefore, if a string contains n characters, 
the last one is the number n – 1.

Both parameters have default values. This enables us to use the function in a more flexible way. So:
    * s.substr(1,2) describes a substring of the s string, starting at its second character and ending at its third character (inclusively).
    * s.substr(1) describes a substring starting at the second character of the s string and containing all of the remaining characters of s, 
      including the last one; the omitted length_of_substring parameter defaults to covering all the remaining characters in the s string.
    * s.substr() is just a copy of the whole s string (the substring_start_position parameters defaults to 0).
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1 = "ABCDEF";

    cout << "Original string: " << str1 << endl;
    string str2 = str1.substr(1, 1) + str1.substr(4) + str1.substr();
    cout << "Concatenated substrings: str1.substr(1, 1) + str1.substr(4) + str1.substr() = " << str2 << endl;

    return 0;
}
```

Output:

```text
Original string: ABCDEF
Concatenated substrings: str1.substr(1, 1) + str1.substr(4) + str1.substr() = BEFABCDEF
```

## The length of a string

Code:

```cpp
/*
Every string has a length. Even an empty string (containing no characters at all) has a length of zero.
This information is provided by two twin member functions.
Their informal prototypes look like these:
    int string_size = any_string.size();
    int string_length = any_string.length();
Both functions return a value equal to the number of all the characters currently stored within a string.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str = "12345";
    int pos = 1;

    cout << "Original string: " << str << endl;
    /*
    Note that the substr function returns a string. This means that the resulting string retains all its original 
    traits and therefore has its own member functions like substr() or size().
    */
    cout << "str.substr(1).substr(1).substr(1).size() = " << str.substr(pos).substr(pos).substr(pos).size() << endl;

    return 0;
}
```

Output:

```text
Original string: 12345
str.substr(1).substr(1).substr(1).size() = 2
```

## More detailed string comparison

Code:

```cpp
/*
Compare functions allow us not only to compare whole strings, but also their substrings.
Their prototypes are clear to understand and easy to use:
    any_string.compare(substr_start, substr_length, other_string)
    any_string.compare(substr_start, substr_length, other_string,  other_substr_start, other_substr_length)
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string s = "ABC";
    cout << "Original string: " << s << endl;

    /*
    s.compare(1, 1, "BC") -> This variant of the compare member function compares the entire other string 
    to the substring of the source string. This means that the following snippet will output -1 (the strings are not equal)
    s.compare(2, 1, s, 2, 2) -> This variant allows us to use only a part of the s string. It will output 0.
    */
    cout << "s.compare(1, 1, \"BC\") + s.compare(2, 1, s, 2, 2) = " << s.compare(1, 1, "BC") + s.compare(2, 1, s, 2, 2) << endl;

    return 0;
}
```

Output:

```text
Original string: ABC
s.compare(1, 1, "BC") + s.compare(2, 1, s, 2, 2) = -1
```

## Finding strings inside strings

Code:

```cpp
/*
To find a substring within another string, taking into account the possibility that it may fail
Strings can search for a substring or for a single character. For this purpose, we need to use one of the variants of the find member function. 
Two of them are particularly useful:
    int where_it_begins = any_string.find(another_string, start_here);
    int where_it_is = any_string.find(any_character, start_here);

In both variants, the start_here parameter defaults to 0, so when we omit it, the string will be searched from the beginning.
The result returned by the functions points to the first location within the string where the searched string begins or where 
the searched character is located (depending on the variant). If the search fails, both functions return a special value denoted 
as string::npos. We can use it to check if our haystack contains the desired find.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string greeting = "My name is Bond, James Bond.";
    string we_need_him = "James";

    cout << "Main string: "<< greeting << endl;
    cout << "String to find: " << we_need_him << endl;

    if (greeting.find(we_need_him) != string::npos)
        cout << endl << "OMG! He's here!";
    else
        cout << endl << "It's not him.";

    int comma = greeting.find(',');

    if (comma != string::npos)
        cout << endl << "Interesting. He used a comma." << endl;

    return 0;
}
```

Output:

```text
Main string: My name is Bond, James Bond.
String to find: James

OMG! He's here!
Interesting. He used a comma.
```

## How big is the string actually?

Code:

```cpp
/*
We can retrieve information regarding the string's length by using the size of length member functions.
It tells us how many characters are currently stored within the string, but says nothing about the memory
occupied by the buffers allocated to that string.
Every time we extend the string, e.g. concatenating another string to it, the new content is placed in the buffers. 
If the buffers are large enough, then extending the string doesn't require the buffers to extend. 
Of course, when the buffers are full and the string is being extended again, the buffers are reallocated to fit the new content.
We can ask any string for the size of the currently allocated buffers. The answer comes from the member function called capacity(). 
We can use it in the following way:
    int currently_used = any_string.capacity();
The result of the function is always greater or equal to the string's size/length 
Every string can grow, but there’s a limit to its extension.  We can find it out by using another function called max_size()
Here’s an example of how to use it:
    int not_broader_than = any_string.max_size();
*/

#include <iostream>
#include <string>
using namespace std;

void print_info(string& s) // Address of s
{
    cout << "length = " << s.length() << endl; // String's length
    cout << "capacity = " << s.capacity() << endl; // Size of the currently allocated buffer
    cout << "max size = " << s.max_size() << endl; // Limit string extension
    cout << "---------" << endl;
}

int main() 
{
    string the_string = "content";

    cout << "string: " << the_string << endl;
    print_info(the_string);

    for (int i = 0; i < 10; i++)
        the_string += the_string;
    print_info(the_string);

    return 0;
}
```

Output:

```text
string: content
length = 7
capacity = 15
max size = 4611686018427387903
---------
length = 7168
capacity = 7680
max size = 4611686018427387903
---------
```

## Control the size of the string

Code:

```cpp
/*
We can control the size of the memory a string uses with the reserve() member function. 
It can work in both directions with the same ease, i.e. it can shrink the buffers as well as expand them. 
The function requires one parameter of type int to specify the desired size of the allocated buffers.
The content of the string isn't changed in any way - we can say that the content is immune to the effect of the reserve() function.
The function, however, may not be as strict as you when it comes to determining the eventual size of the allocated memory. 
It may round the value of the parameter to fit it to the current memory requirements and/or target platform conditions.
*/

#include <iostream>
#include <string>
using namespace std;

void print_info(string& s) 
{
    cout << "content = \"" << s << "\", ";
    cout << "capacity = " << s.capacity() << endl;
    cout << "---------" << endl;
}

int main()
{
    string the_string = "content";

    print_info(the_string);
    the_string.reserve(100); // Control the size of the memory
    print_info(the_string);
    the_string.reserve(0); // Control the size of the memory
    print_info(the_string);

    return 0;
}
```

Output:

```text
content = "content", capacity = 15
---------
content = "content", capacity = 100
---------
content = "content", capacity = 100
---------
```

## Control the size of the string

Code:

```cpp
/*
It isn't possible to implement even the simplest cipher code without being able to 
analyse and modify every single char of any string.
strings aren't vectors, but they are able to present their content as if it were an actual vector. 
We can assume that it's a kind of very useful masquerade – a string can wear a mask and show itself as an ordinary (well, almost ordinary) vector. 
It allows us to read and write every character separately.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string the_string = "content";

    // It converts its every char to upper case.
    for (int i = 0; i < the_string.length(); i++)
        the_string[i] = the_string[i] - 'a' + 'A';
    cout << the_string << endl;

    return 0;
}
```

Output:

```text
CONTENT
```

## Appending a (sub)string

Code:

```cpp
/*
append() is designed to append one string to another.
Same task can be performed by the += operator. However, the append function is much more 
flexible and helpful than += and can give you more options.
We can use the append() function to append a string - here's an example:
    string str1 = "content"; str2 = "appendix"; str1.append(str2);
    // str1 contains "contentappendix" now
The append() function is able to append not only a string, but also a substring of the string, like this:
    string str1 = "content";  str1.append("tail",1,3);
    // str1 contains "contentail" now
The append can append a char (possibly repeated n times), like this:
    string str1 = "content";  str1.append(3, 'x');
    // str1 contains "contentxxx" now
All these variants not only affect the content of the string, but also return the modified string as a result.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string the_string = "content";
    string new_string;

    new_string.append(the_string); //Append a string to this string.
    cout << new_string << endl;
    new_string.append(the_string, 0, 3); //Append a substring.
    cout << new_string << endl;
    new_string.append(2, '!'); //Append multiple characters.
    cout << new_string << endl;

    return 0;
}
```

Output:

```text
content
contentcon
contentcon!!
```

## Appending a character

Code:

```cpp
/*
If we want to append just one character to a string, we can do it by using the append function, 
but there's a more efficient way, by using the push_back member function.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string the_string;

    for (char c = 'A'; c <= 'Z'; c++)
        the_string.push_back(c);
    cout << the_string << endl;

    return 0;
}
```

Output:

```text
ABCDEFGHIJKLMNOPQRSTUVWXYZ
```

## Inserting a (sub)string or a character

Code:

```cpp
/*
Inserting a string into a string is like distending its contents from within. 
A new set of contents is just “pushed” into the old one.
insert() function -> the first parameter specifies where the insertion should be, while the second says what should be inserted there. 
This is only one among various possibilities offered by the function. Another member function can insert a substring of a specified string 
in a way very similar to the append function. There’s also a function that can insert a single character, optionally duplicated more than once.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string quote = "Whyserious?", anyword = "monsoon";

    cout << "quote: " << quote << endl;
    cout << "anyword: " << anyword << endl;
    quote.insert(3, 2, ' ').insert(4, anyword, 3, 2);
    cout << "quote.insert(3, 2, ' ').insert(4, anyword, 3, 2) = " << quote << endl;

    return 0;  
}
```

Output:

```text
quote: Whyserious?
anyword: monsoon
quote.insert(3, 2, ' ').insert(4, anyword, 3, 2) = Why so serious?
```

## Assigning a (sub)string or a character

Code:

```cpp
/*
The assign member function does a job which is very similar to the insert's job, but does not 
retain the previous string content, and instead just replaces it with a new one. 
The assign() is as universal as the insert() or append() functions and so is more convenient 
in some specific applications.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string sky;

    sky.assign(80, '*'); // Set value to multiple characters.
    cout << sky << endl;

    return 0;  
}
```

Output:

```text
********************************************************************************
```

## Replacing a (sub)string

Code:

```cpp
/*
The replace() member function is more subtle. It can replace a part of the string with 
another string or another string’s substring.
The function needs to know which part of the string it’s going to replace and you have 
to specify this by delivering two numbers:
    * the first describing the starting position;
    * the second saying how many characters will be replaced.
The first overloaded function needs a string (as a third parameter) to replace the old content 
(it may be either longer or shorter or equal in size in comparison to the original). 
The second function enables you to specify the substring to be used as a substitution.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string to_do = "I'll think about that in one hour";
    string schedule = "today yesterday tomorrow";

    cout << "First string: " << to_do << endl;
    cout << "Second string: " << schedule << endl;
    to_do.replace(22, 12, schedule, 16, 8);
    cout << "Output string: " << to_do << endl;

    return 0;  
}
```

Output:

```text
First string: I'll think about that in one hour
Second string: today yesterday tomorrow
Output string: I'll think about that tomorrow
```

## Erasing a (sub)string

Code:

```cpp
/*
We can also remove a part of a string, making the string shorter than before. We can do this by using a member function called erase() 
and the function requires two numbers in order to perform its duty:
    * the place where the substring to be removed starts (this value defaults to zero);
    * the length of the substring (this value defaults to the original string’s length).
This means that an invocation like this:
    the_string.erase();
erases all the characters from the string and leaves it empty.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string where_are_we = "I've got a feeling we're not in Kansas anymore";
    cout << "Original string: " << where_are_we << endl;

    where_are_we.erase(38, 8).erase(25, 4); // Remove characters.
    cout << "Modified string: " << where_are_we << endl;

    return 0;  
}
```

Output:

```text
Original string: I've got a feeling we're not in Kansas anymore
Modified string: I've got a feeling we're in Kansas
```

## Exchanging the contents of two strings

Code:

```cpp
/*
This action is performed by a member function called swap(). 
This function is many times faster than ordinary (physically performed) swapping.
*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string drink = "A martini";
    string needs = "Shaken, not stirred";

    cout << "Original order: " << drink << ". " << needs << "." << endl;
    drink.swap(needs);
    cout << "Modified order: "  << drink << ". " << needs << "." << endl;

    return 0; 
}
```

Output:

```text
Original order: A martini. Shaken, not stirred.
Modified order: Shaken, not stirred. A martini.
```

## Name spaces

Code:

```cpp
/*
We've qualified all the ambiguous names with a prefix consisting of the home name space (std) and a special operator written as “::”.
The operator's official name is “scope resolution operator”. It has some more applications, not only qualifying names with their home name spaces; 
hence its name refers to more general concepts.
A qualifying act like this is an alternative (explicite) way of using the “using namespace” statement.
*/

#include <iostream>

int main() 
{
    std::cout << "Play as time goes by" << std::endl;

    return 0; 
}
```

Output:

```text
Play as time goes by
```

## Defining a name space

Code:

```cpp
/*
We want to use trolls (two, to be precise) in our software. We’re going to take one from Hogwarts and one from Mordor.
We have to create two different name spaces and to bind the trolls to their origins. Defining a name space looks like this:
    namespace the_name_of_the_space {}
Any entity declared inside a namespace (between its opening and closing brackets) will be bound to this namespace and therefore, 
logically separated from any other entity with the same name.

Let’s assume that two independent programmers have implemented different parts of a very complex system. 
We cannot guarantee that all the names they’ve used are pairwise different. Such a requirement would be impractical and difficult to enforce 
(developers would have to agree on every new name introduced to their codes). It’s easier to assume that all their entities 
(e.g. variables and functions) are bound to (or rather enclosed inside) different name spaces named after the developer’s given names or their nicknames.
*/

#include <iostream>
using namespace std;

namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

int main() 
{
    cout << "Hogwarts::troll: " << Hogwarts::troll << endl << "Mordor::troll: " << Mordor::troll << endl;

    return 0; 
}
```

Output:

```text
Hogwarts::troll: 1
Mordor::troll: 2
```

## Using a name space

Code:

```cpp
/*
If any of the available name spaces is more usable or preferable, it may be used in a way that suggests that the compiler tries 
to qualify every unqualified name with this/these name space names.
The act of using a selected namespace is carried out by the using namespace statement. If the statement is placed outside any block, 
it affects the code after the statement until the end of the source file.
*/

#include <iostream>
using namespace std;

/*
Using namespace statements must not lead to a situation where an identifier could be considered to have originated from more than one name space.
We’re not allowed to use the following two statements in the same scope (block) of code:
    using namespace Hogwarts;
    using namespace Mordor;
*/
namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

using namespace Hogwarts;

int main() 
{
    cout << "troll = " << troll << ", Mordor::troll = " << Mordor::troll << endl;

    return 0; 
}
```

Output:

```text
troll = 1, Mordor::troll = 2
```

## Using a name space

Code:

```cpp
/*
If the using namespace statement is placed inside a block, its scope ends in the same place where the block ends. 
We can use this effect to selectively use (and disuse) any of the available namespaces.
*/

#include <iostream>
// The std name space is used globally (in the whole source file).
using namespace std;

namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

int main() 
{
    // The Hogwarts and Mordor name spaces are used selectively (in the selected parts of the code).
    {
        using namespace Hogwarts;
        cout << "troll Hogwarts= " << troll;
    } 

    {
        using namespace Mordor;
        cout << ", troll Mordor = " << troll << endl;
    }

    return 0; 
}
```

Output:

```text
troll Hogwarts= 1, troll Mordor = 2
```

## Expanding a name space

Code:

```cpp
/*
Let's assume that all the name space definitions that use the same identifier are “glued” together and build one, larger name space together. 
Note that each extension may be placed inside a separate source file. 
This means that any of the name spaces may be dispersed among many source files created by different developers.
Note that the first appearance of a name space is called “an original name space”. Any name space with the same name (identifier) that 
appears after the original name space is called “an extension name space”. There may be more than one extension of a name space.
*/

#include <iostream>
using namespace std;

namespace Hogwarts {
    int troll = 1;
}

namespace Mordor {
    int troll = 2;
}

namespace Hogwarts {
    float wizard = -0.5;
}

namespace Mordor {
    float wizard = 0.5;
}

int main() 
{
    cout << "Hogwarts::troll = " << Hogwarts::troll << ", Hogwarts::wizard = " << Hogwarts::wizard << endl;
    cout << "Mordor::troll = "  << Mordor::troll << ", Mordor::wizard = " << Mordor::wizard << endl;

    return 0; 
}
```

Output:

```text
Hogwarts::troll = 1, Hogwarts::wizard = -0.5
Mordor::troll = 2, Mordor::wizard = 0.5
```

## Using an entity

Code:

```cpp
/*
There's another form of statement that allows us to selectively decide which entities should be used and which should remain hidden inside the space. 
But there's one important condition: none of the statements used may cause ambiguity in the process of identifying all the entities used in your code.
*/

#include <iostream>
using namespace std;

namespace Hogwarts {
    int Troll = 1;
    float Wizard = -0.5;
}

namespace Mordor {
    int Troll = 2 ;
    float Wizard = 0.5;
}

using Mordor::Troll;
using Hogwarts::Wizard;

int main() 
{
    cout << "Hogwarts::Troll = " << Hogwarts::Troll << ", Wizard Hogwarts = " << Wizard << endl;
    cout << "Troll Mordor = " << Troll << ", Mordor::Wizard = " << Mordor::Wizard << endl;

    return 0; 
}
```

Output:

```text
Hogwarts::Troll = 1, Wizard Hogwarts = -0.5
Troll Mordor = 2, Mordor::Wizard = 0.5
```

## An unnamed name space

Code:

```cpp
/*
We may define a name space without a name (an anonymous namespace).
This kind of namespace is implicitly and automatically used in a source file where its definition is visible. 
It's another way of introducing entities (e.g. variables) accessible through the whole source file.
*/

#include <iostream>
using namespace std;

namespace {
    int troll = 1;
    float wizard = -0.5;
}

namespace Mordor {
    int troll = 2;
    float wizard = 0.5;
}

int main() 
{
    cout << "troll = " << troll << ", wizard = " << wizard << endl;
    cout << "Mordor::troll = " << Mordor::troll << ", Mordor::wizard = " << Mordor::wizard << endl;

    return 0; 
}
```

Output:

```text
troll = 1, wizard = -0.5
Mordor::troll = 2, Mordor::wizard = 0.5
```

## Renaming a name space

Code:

```cpp
/*
It may happen that one of the name spaces you have or want to use has an inconvenient name (for any reason). 
We can rename it locally i.e. it'll be recognized under its new name only in the source file where the act of renaming has occurred.
We can use it with a special form of the namespace statement - here it is:
    namespace new_name = old_name;
The new name of the name space may be used together with the old one. This means that the renaming is actually aliasing, since both of the names are still valid.
*/

#include <iostream>
using namespace std;

namespace what_a_wonderful_place_for_a_young_sorcerer {
    int troll = 1;
    float wizard = -0.5;
}

namespace Mordor {
    int troll = 2;
    float wizard = 0.5;
}

namespace Hogwarts = what_a_wonderful_place_for_a_young_sorcerer;

int main() 
{
    cout << "Hogwarts::troll = " << Hogwarts::troll << ", what_a_wonderful_place_for_a_young_sorcerer::wizard = " << what_a_wonderful_place_for_a_young_sorcerer::wizard << endl;
    cout << "Mordor::troll = " << Mordor::troll << ", Mordor::wizard = " << Mordor::wizard << endl;

    return 0; 
}
```

Output:

```text
Hogwarts::troll = 1, what_a_wonderful_place_for_a_young_sorcerer::wizard = -0.5
Mordor::troll = 2, Mordor::wizard = 0.5
```