// The bubble sort program adopted to use new and delete mechanisms is in the editor.

#include <iostream>
#include "../myFunctions.h"
using namespace std;

int main() 
{
    cout << "How many numbers are you going to sort? ";
    int how_many_numbers;
    cin >> how_many_numbers;

    if(how_many_numbers <= 0 || how_many_numbers > 1000000) {
        cout << "Are you kidding?" << endl;
        return 0;
    }

    int *numbers = new int[how_many_numbers];
    for(int i = 0; i < how_many_numbers; i++) {
        cout << "Enter the number #" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Bubble sort
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < how_many_numbers - 1; i++)
            if (numbers[i] > numbers[i + 1]) {
                swapped = true;
                int aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
    } while (swapped);

    cout << endl << "The sorted array:" << endl;
    for (int i = 0; i < how_many_numbers; i++)
        if (i < how_many_numbers - 1)
            cout << numbers[i] << ", ";
        else
            cout << numbers[i] << endl;

    delete[] numbers;

    askOS();
    return 0;
}

/*
Output:

How many numbers are you going to sort? 5
Enter the number #1: 9
Enter the number #2: 7
Enter the number #3: 5
Enter the number #4: 3
Enter the number #5: 1

The sorted array:
1, 3, 5, 7, 9
*/