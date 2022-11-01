/* String operators: +

It concatenates strings (i.e. it glues them together, giving a new string which 
has arisen out of the values of its arguments)*/
#include <iostream>
#include <string>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    string good = "Jekyll", bad = "Hyde";

    cout << good + " & " + bad << endl;
    cout << bad + " & " + good;

    askOS();
    return 0;
}