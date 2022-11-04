/* Refers to the situation where a non-static function named funN1 invokes a static function named funS1.
A case like this is always possible, as the static function is available before any object has been created.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Test {
public:
    static void funS1() 
    { 
        cout << "static" << endl; 
    }
    void funN1() 
    { 
        funS1(); 
    }
};

int main()
{
    Test object;

    object.funN1();

    askOS();
    return 0; 
}