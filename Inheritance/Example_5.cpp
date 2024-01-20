////////////////////////
// Type compatibility //
////////////////////////

/*
The Dog and Cat classes are descendants (to be precise, children) of the common base class Pet. We’ve equipped all the classes with constructors, 
enabling us to give unique names to all the objects we’re going to create in the future. Our pets are also able to run (but you might need a leash).
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

// Objects derived from the Pet class are able to run. Pets cannot do all the thing that Cat and Dog can do
class Pet {
    protected:
        string name;

    public:
        Pet(string n)
        { 
            name = n; 
        }

        void run()
        { 
            cout << name << ": I'm running" << endl; 
        }
};

/* 
Objects derived from the Dog and Cat classes are able to run (they inherit this ability from their superclass); 
they can also make sounds (note that this skill is not available for objects of the Pet class).
Cat and Dog objects can do all the things Pets are able to do.
*/
class Dog : public Pet {
    public:
        Dog(string n) : Pet(n) {};

        void make_sound()
        { 
            cout << name << ": Woof! Woof!" << endl; 
        }
};

class Cat : public Pet {
    public:
        Cat(string n) : Pet(n) {};

        void make_sound() 
        { 
            cout << name << ": Meow! Meow!" << endl; 
        }
};

/* 
* Objects of the subclass have at least the same capabilities as the superclass objects.
* Objects of the superclass may not have the same capabilities as the subclass objects.
* Objects of the superclass are compatible with objects of the subclass.
* Objects of the subclass are not compatible with objects of the superclass.
*/
int main()
{
    Pet a_pet("pet");
    Cat a_cat("Tom");
    Dog a_dog("Spike");

    a_pet.run();
    a_dog.run(); 
    a_dog.make_sound();
    a_cat.run(); 
    a_cat.make_sound();

    askOS();
    return 0; 
}

/*
Output:

pet: I'm running
Spike: I'm running
Spike: Woof! Woof!
Tom: I'm running
Tom: Meow! Meow!
*/