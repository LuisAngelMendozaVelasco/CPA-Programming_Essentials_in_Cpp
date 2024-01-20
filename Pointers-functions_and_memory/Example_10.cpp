//////////////////////////
// Passing by reference //
//////////////////////////

/*
When a parameter is passed by reference it means that a parameter is just a synonym of an argument. 
Every modification made into a parameter immediately affects an associated argument. 
We can informally say that arguments passed by reference have return tickets and bring their modified values back to the invoker.*/

#include <iostream>
#include "../myFunctions.h"
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

    askOS();
    return 0;
}

/*
Output:

var = 1
----------
I have got: 1
I'm about to give back: 2
----------
var = 2
*/