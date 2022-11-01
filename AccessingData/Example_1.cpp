/* Triangular matrices
The advantage of such arrays is that every row may be of a different length. 
This is useful for the algorithms that don’t need the entire array to run but only a slice of it.*/ 
#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    // the size of the allocated memory block depends on the row number
    int rows = 5;

    // allocate and initialize the array
    // the type of arr is "a pointer to a pointer to int" 
    // the elements of the array of rows will be pointers to the rows, so their type is int*
    int **arr = new int* [rows];

    // allocate memory for every row and store the resulting pointer inside the right element of the array of rows
    for (int r = 0; r < rows; r++) {
        arr[r] = new int[r + 1];
        for (int c = 0; c <= r; c++) {
            arr[r][c] = (r + 1) * 10 + c + 1;
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    // free the array
    for (int r = 0; r < rows; r++)
        delete[] arr[r];
    delete[] arr;

    askOS();
    return 0;
}