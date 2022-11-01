/* String operators: +=

+ may be used as a short-cut operator.*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string the_question = "To be ";

    the_question += "or not to be";
    cout << the_question;

    askOS();
    return 0;
}