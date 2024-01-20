///////////////////////////////////////////
// Modern vectors can be freely expanded //
///////////////////////////////////////////

#include <iostream>
#include <vector>
#include "../myFunctions.h"
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

    askOS();
    return 0;
}

/*
Output:

Vector size: 3
Vector: [1, -1, 0]
*/