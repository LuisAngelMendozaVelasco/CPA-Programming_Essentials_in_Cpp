/* Static components of the class

A static component exists throughout the whole life of the program. Moreover, there is always only one component 
regardless of the number of instances of the class. We can say that all the instances share the same static components.
The Static variable inside the public part of the Class is only a declaration. This means that the variable has to have 
both an explicitly expressed separate definition and a possible initialization, and both must be placed outside the class definition.
Another rationale says that the definition has to be separate from the class body because static variables are not actually part of any object. */
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Class {
public:
	static int Static;
	int NonStatic;
	void print()
	{
		cout << "Static = " << ++Static << 
		        ", NonStatic = " << NonStatic << endl;
	}
};

int Class::Static = 0;

int main() 
{
	Class instance1, instance2;

	instance1.NonStatic = 10;
	instance2.NonStatic = 20;
	instance1.print();
	instance2.print();

    askOS();
    return 0; 
}