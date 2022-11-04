/* A case when a static function named funS2 tries to invoke another static function named funS1.
A case like this is always possible, as both functions are available during the entire life of the program. 
They can be successfully accessed from within an object and from within the class.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Test {
public:
    static void funS1() 
    { 
        cout << "static" << endl; 
    }
    static void funS2() 
    { 
        funS1(); 
    }
};

int main()
{
    Test object;

    Test::funS2();
    object.funS2();

    askOS();
    return 0; 
}