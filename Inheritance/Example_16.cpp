/////////////////////////////////////
// Passing an object of a subclass //
/////////////////////////////////////

/*
There is a function called play_with_pet, ready to get one parameter of type Pet & (a reference to the Pet object). 
The function is invoked with four different objects taken from different levels of the class hierarchy.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Pet {
    protected:
        string name;

    public:
        Pet(string name)
        { 
            this -> name = name; 
        }

        void make_sound()
        { 
            cout << name << " is silent :(" << endl; 
        }
};

class Dog : public Pet {
    public:
        Dog(string name) : Pet(name) {}

        void make_sound()
        { 
            cout << name << " says: Woof!" << endl; 
        }
};

class GermanShepherd : public Dog {
    public:
        GermanShepherd(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Wuff!" << endl; 
        }
};

class MastinEspanol : public Dog {
    public:
        MastinEspanol(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Guau!" << endl; 
        }
};

void play_with_pet(Pet &pet)
{
    pet.make_sound();
}

/* 
An object of the superclass is type compatible with the objects of any of the subclasses. We can declare a formal parameter of a type as a superclass 
and pass an actual parameter of any of the formal parameter’s subclasses.
*/
int main()
{
    Pet pet("creature");
    Dog dog("Dog");
    GermanShepherd shepherd("Hund");
    MastinEspanol mastin("Perro");

    play_with_pet(pet);
    play_with_pet(dog);
    play_with_pet(shepherd);
    play_with_pet(mastin);

    askOS();
    return 0;  
}

/*
Output:

creature is silent :(
Dog is silent :(
Hund is silent :(
Perro is silent :(
*/