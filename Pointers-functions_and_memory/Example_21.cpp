//////////////////////
// Memory on demand //
//////////////////////

/*
In the following program, we allocate an array containing 5 elements of type int, 
set their values, sum them up and, finally, release the previously allocated memory.
*/ 

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    int *tabptr = new int[5], sum = 0;

    cout << "vector: ";
    for (int i = 0; i < 5; i++) {
        tabptr[i] = i;
        if (i < 4)
            cout << i << ", ";
        else
            cout << i << endl;
        sum += tabptr[i];
    }

    delete [] tabptr;
    cout << "Sum vector = " << sum << endl;

    askOS();
    return 0;
}

/*
Output:

vector: 0, 1, 2, 3, 4
Sum vector = 10
*/