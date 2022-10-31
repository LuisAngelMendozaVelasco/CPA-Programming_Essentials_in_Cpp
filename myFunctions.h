#include <iostream>

using namespace std;

void askOS() {
    #ifdef _WIN32 //Ask for the OS
        cout << endl << endl;
        system("pause");
    #else
        cout << endl << endl;
    #endif
    
    return;
}