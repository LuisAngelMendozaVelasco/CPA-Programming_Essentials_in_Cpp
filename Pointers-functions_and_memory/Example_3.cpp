#include <vector>
#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main()
{
    vector<int> numbers {1, 2, 3};
    int *ptr = numbers.data() + 1; // Initial ptr's value points to numbers[1].

    cout << "Original numbers[0]: " << numbers[0] << endl;
    /* 
    ptr[-1] points to numbers[0]
    ptr[1] points to numbers[2]
    assignment can be rewritten as:
    *(ptr - 1) = *ptr + *(ptr + 1);
    */
    ptr[-1] = *ptr + ptr[1]; // Equivalent of numbers[0] = numbers[1] + numbers[2];
    cout << "Modified numbers[0]: " << numbers[0] << endl;

    askOS();
    return 0;
}

/*
Output:

Original numbers[0]: 1
Modified numbers[0]: 5
*/