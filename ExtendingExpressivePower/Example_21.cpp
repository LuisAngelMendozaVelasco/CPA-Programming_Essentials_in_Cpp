/* Memory on demand
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
            cout << i;
        sum += tabptr[i];
    }

    delete [] tabptr;
    cout << endl << "sum vector = " << sum;

    askOS();
    return 0;
}