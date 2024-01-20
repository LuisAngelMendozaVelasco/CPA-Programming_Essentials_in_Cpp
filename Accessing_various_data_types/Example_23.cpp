////////////////////////////////////
// Control the size of the string //
////////////////////////////////////

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
#include "../myFunctions.h"
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

    askOS();
    return 0;
}

/*
Output:


*/