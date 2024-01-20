/////////////////////////////////////
// Vectors of pointers to objects //
////////////////////////////////////

// There are no obstacles to gathering pointers to objects inside a vector. The program demonstrates the syntax we need to use in order to access such a collection.

#include <iostream>
#include <vector>
#include "../myFunctions.h"
using namespace std;

class Array {
    int *values;
    int  size;

    public:
        Array(int size) { 
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

/* 
We’ve used two objects of the Array class and stored pointers to them in the ptrvect vector (don’t confuse these two entities: 
Array is a class defined by us, ptrvect is an ordinary, language built-in vector).
*/
int main()
{
    vector<Array *> ptrvect = {new Array(2), new Array(2)};

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            ptrvect[i] -> put(j, j + 10 + i);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            cout << "#" << i + 1 << ":" << ptrvect[i] -> get(j) << "; ";
        cout << endl;
    }

    delete ptrvect[0];
    delete ptrvect[1];

    askOS();
    return 0; 
}

/*
Output:

Array of 2 ints constructed.
Array of 2 ints constructed.
#1:10; #1:11; 
#2:11; #2:12; 
Array of 2 ints destructed.
Array of 2 ints destructed.
*/