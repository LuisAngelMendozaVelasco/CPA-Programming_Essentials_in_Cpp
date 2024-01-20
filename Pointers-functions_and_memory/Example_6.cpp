// The program asks a user for the size of his/her ego and responds with an adequate greeting.

#include <iostream>
#include "../myFunctions.h"
using namespace std;

void greet() 
{
    cout << "Ave user!" << endl;
}

void greet_many_times(int how_many_times) 
{
    while (how_many_times > 0) {
        greet();
        how_many_times--;
    }
}

int main() 
{
    int size_of_ego;

    cout << "How big is your ego? [km]: ";
    cin >> size_of_ego;
    greet_many_times(1 + size_of_ego);

    askOS();
    return 0;
}

/*
Output:

How big is your ego? [km]: 1
Ave user!
Ave user!
*/