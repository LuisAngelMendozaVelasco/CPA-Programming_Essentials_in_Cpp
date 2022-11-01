/* Finding strings inside strings

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
#include "../myFunctions.h"

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
        cout << endl << "Interesting. He used a comma.";

    askOS();
    return 0;
}