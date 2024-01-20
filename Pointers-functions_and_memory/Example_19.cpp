/////////////////
// Bubble sort //
/////////////////

#include <iostream>
#include <vector>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    vector<int> numbers(5);

    // Ask the user to enter 5 values
    for (int i = 0; i < 5; i++) {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Sort them 
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < 4; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swapped = true;
                int aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
        }
    } while (swapped);

    // Print results 
    cout << endl << "Sorted vector: " << endl;
    for (int i = 0; i < 5; i++)
        cout << numbers[i] << " ";
    cout << endl;

    askOS();
    return 0;
}

/*
Output:

Enter value #1: 9
Enter value #2: 8
Enter value #3: 7
Enter value #4: 6
Enter value #5: 5

Sorted vector: 
5 6 7 8 9
*/