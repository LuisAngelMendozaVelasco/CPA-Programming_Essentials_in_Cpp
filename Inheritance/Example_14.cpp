///////////////////////////////////////////////
// Passing an object as a function parameter //
///////////////////////////////////////////////

/*
Any object may be used as a function parameter and, vice versa, any function may have a parameter as an object of any class.
The code shows two ways to pass an object into a function: by pointer and by reference. We already know that passing a pointer is just a specific form 
of passing a value because a pointer is just a specific kind of value that enables us to modify an object’s state inside a function.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Pet {
	protected:
		string name;

	public:
		void name_me(string name)
		{ 
			this -> name = name; 
		}

		void make_sound()
		{ 
			cout << name << " says: no comments" << endl; 
		}
};

/* 
There are two functions, both of them have two parameters, but only the second is actually of interest to us. The first function declares a pointer 
there and the second one a reference. In both cases, the target class is the same: “Pet”.
*/
void play_with_pet_by_pointer(string name, Pet *pet)
{
	pet -> name_me(name);
	pet -> make_sound();
}

void play_with_pet_by_reference(string name, Pet &pet)
{
	pet.name_me(name);
	pet.make_sound();
}

/* 
We create two objects within the main function: the first (p1) is handled by a pointer and created by the new keyword. The second (p2) is an automatic variable.
We invoke each of the functions twice, the first time according to their declarations, the second time by replacing the way in which the objects are handled: 
p2 is a subject to the & operator; p1 is dereferenced by the * operator.
*/
int main()
{
	Pet *p1 = new Pet();
	Pet p2;

	play_with_pet_by_pointer("anonymous", p1);
	play_with_pet_by_reference("no_name", p2);
	play_with_pet_by_pointer("no_name", &p2);
	play_with_pet_by_reference("anonymous", *p1);

    askOS();
    return 0;  
}

/*
Output:

anonymous says: no comments
no_name says: no comments
no_name says: no comments
anonymous says: no comments
*/