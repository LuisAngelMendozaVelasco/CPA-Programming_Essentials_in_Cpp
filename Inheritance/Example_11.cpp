/* Overriding a method in the subclass

We don’t use the static_cast, but the some of the pointers are explicitly declared as pointing to the common superclass (Pet). 
The classes themselves remain untouched. We’ve merely changed the way in which we treat the pointers.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Pet {
protected:
	string name;
public:
	Pet(string n)
	{ 
		name = n; 
	}
	void make_sound()
	{
		cout << name << " the Pet says: Shh! Shh!" << endl; 
	}
};

class Cat : public Pet {
public:
	Cat(string n) : Pet(n) { }
	void make_sound()
	{
		cout << name << " the Cat says: Meow! Meow!" << endl; 
	}
};

class Dog : public Pet {
public:
	Dog(string n) : Pet(n) { }
	void make_sound()
	{
		cout << name << " the Dog says: Woof! Woof!" << endl; 
	}
};	

int main() 
{
    Pet *a_pet1, *a_pet2;
    Cat *a_cat;
    Dog *a_dog;

    a_pet1 = a_cat = new Cat("Kitty");
    a_pet2 = a_dog = new Dog("Doggie");
    a_pet1 -> make_sound();
    a_cat  -> make_sound();
    a_pet2 -> make_sound();
    a_dog  -> make_sound();

    askOS();
    return 0; 
}