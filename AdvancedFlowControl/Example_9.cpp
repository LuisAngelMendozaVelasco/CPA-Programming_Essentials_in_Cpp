#include <iostream>
#include "../myFunctions.h"

using namespace std;

int main() 
{
    int number;
    int max = -100000;
    int counter = 0;

    do {
        cout << "Number: ";
        cin >> number;
        if(number == -1)
            continue; // behaves as the program suddenly reached the end of the body; the end of the loop's body is reached and the condition expression is tested immediately
        counter++;
        if(number > max)
            max = number;
    } while (number != -1);

    if(counter)
        cout << "The largest number is " << max;
    else 
        cout << "Are you kidding? You haven't entered any number!";

    askOS();
    return 0;
}