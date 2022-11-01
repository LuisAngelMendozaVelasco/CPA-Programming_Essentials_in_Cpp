/* How big is the string actually?

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
    int not_broader_than = any_string.max_size();*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

void print_info(string& s) // address of s
{
    cout << "length = " << s.length() << endl; // string's length
    cout << "capacity = " << s.capacity() << endl; // size of the currently allocated buffer
    cout << "max size = " << s.max_size() << endl; // limit string extension
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

    askOS();
    return 0;
}