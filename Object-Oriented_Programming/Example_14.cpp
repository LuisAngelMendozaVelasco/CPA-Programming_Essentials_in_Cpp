/* 
A case when a static function named funS1 tries to invoke a non-static function named funN1.
A case like this is not possible, as the function being invoked exists when and only when any of the objects which contain this function also exists. 
The function cannot be successfully accessed without specifying the associated object.
This program cannot be successfully compiled.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Test {
    public:
        void funN1() 
        { 
            cout << "non-static" << endl; 
        }

        static void funS1() 
        { 
            funN1(); 
        }
};

int main()
{
    Test object;

    Test::funS1();
    object.funS1();

    askOS();
    return 0; 
}

/*
Output:

error: cannot call member function ‘void Test::funN1()’ without object
*/