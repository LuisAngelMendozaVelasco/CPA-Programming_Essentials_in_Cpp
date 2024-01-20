/////////////////////////
// Pointers to objects //
/////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

/* 
There’s a class that implements a very simple array containing elements of type int. The size of the array is determined by 
the parameter’s value passed to the constructor of the class.
The class offers us two methods for accessing the array. The first (named get()) returns the value of the element stored in 
the cell of an index specified by the value of the parameter. The second (named put()) is able to set a new value of the selected 
cell (the parameters of the functions specify the index and the value respectively).
*/

class Array {
    int *values;
    int  size;

    public:
        Array(int size)
        { 
            this -> size = size; 
            values = new int[size];
            cout << "Array of " << size << " ints constructed." << endl; 
        }

        ~Array()
        { 
            delete [] values; 
            cout << "Array of " << size << " ints destructed." << endl; 
        }

        int get(int index)
        { 
            return values[index];
        }

        void put(int index, int value) 
        { 
            values[index] = value;
        }
};

int main()
{
    Array *arr = new Array(2);

    for(int i = 0; i < 2; i++)
        arr -> put(i, i + 100);

    for(int i = 0; i < 2; i++)
        cout << "#" << i + 1 << ": " << arr -> get(i) << endl;

    delete arr;

    askOS();
    return 0; 
}

/*
Output:

Array of 2 ints constructed.
#1: 100
#2: 101
Array of 2 ints destructed.
*/