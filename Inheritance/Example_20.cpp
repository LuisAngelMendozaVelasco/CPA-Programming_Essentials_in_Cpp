/////////////////////////
// try-catch statement //
/////////////////////////

/*
It looks like this:
    try {
        thing_we_want_to_try_although_we_are_not_quite_sure_if_it_is_reasonable();
    } 
    catch(...) {}
Using this statement we can “try” some risky activities and “catch” errors that appear during the execution.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Pet {
    protected: 
        string name;

    public:
        Pet(string name) : name(name) {}

        virtual void make_sound()
        { 
            cout << name << " is silent :(" << endl; 
        }
};

class Dog : public Pet {
    public:	
        Dog(string name) : Pet(name) {}

        void make_sound()
        { 
            cout << name << " says: Woof!" << endl; \
        }
};

class GermanShepherd : public Dog {
    public:	
        GermanShepherd(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Wuff!" << endl; 
        }

        void laufen()
        { 
            cout << name << " runs (shepherd)!" << endl; 
        }
};

class MastinEspanol : public Dog {
    public:	
        MastinEspanol(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Guau!" << endl; 
        }

        void correr()
        { 
            cout << name << " runs (mastin)!" << endl; 
        }
};

/* 
We catch the error and do nothing. Thanks to that, our dogs are ready to return to their normal life.
The error that arises during the unsuccessful casting is simply ignored, but in effect (paradoxically), the casting is safe now 
and will cause no harm in the case of failure.
*/
void play_with_pet(Pet &pet) {
    pet.make_sound();

    try {
        dynamic_cast<GermanShepherd &>(pet).laufen();
    } 
    catch(...) {}

    try {
        dynamic_cast<MastinEspanol &>(pet).correr();
    }
    catch(...) {}
}

int main() 
{
    Pet pet("creature");
    Dog dog("Dog");
    GermanShepherd shepherd("Hund");
    MastinEspanol mastin("Perro");

    play_with_pet(pet);
    cout << endl;
    play_with_pet(dog);
    cout << endl;
    play_with_pet(shepherd);
    cout << endl;
    play_with_pet(mastin);

    askOS();
    return 0; 
    }

/*
Output:

creature is silent :(

Dog says: Woof!

Hund says: Wuff!
Hund runs (shepherd)!

Perro says: Guau!
Perro runs (mastin)!
*/