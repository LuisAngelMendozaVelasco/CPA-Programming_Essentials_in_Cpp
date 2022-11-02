/* Inserting a (sub)string or a character

Inserting a string into a string is like distending its contents from within. 
A new set of contents is just “pushed” into the old one.
insert() function -> the first parameter specifies where the insertion should be, while the second says what should be inserted there. 
This is only one among various possibilities offered by the function. Another member function can insert a substring of a specified string 
in a way very similar to the append function. There’s also a function that can insert a single character, optionally duplicated more than once*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string quote = "Whyserious?", anyword = "monsoon";

    cout << "quote: " << quote << endl;
    cout << "anyword: " << anyword << endl;
    quote.insert(3, 2, ' ').insert(4, anyword, 3, 2);
    cout << "quote.insert(3, 2, ' ').insert(4, anyword, 3, 2) = " << quote;

    askOS();
    return 0;  
}