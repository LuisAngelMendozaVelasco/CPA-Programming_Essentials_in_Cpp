///////////////////////////////
// The dynamic_cast operator //
///////////////////////////////

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Pet {
    protected:
        string name;

    public:
        Pet(string name) : name(name) {}

        // We’ve modified the make_sound method inside the top-level class – it’s virtual now. 
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
            cout << name << " says: Woof!" << endl; 
        }
};

/* 
We’ve made the class tree higher (or rather, deeper, regarding the fact that the tree grows from top to bottom). 
We’ve added two additional levels to the tree. The lowest level consists of two branches containing very specific 
species: German Shepherd and Mastin Espanol. 
*/
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
The play_with_pet function gets a pointer of Pet * type (i.e. pointer to the top-level class objects). The function does two important things:
    It invokes the make_sound method; the method is marked as virtual so we expect the “national” objects will be able to make their native sounds;
    It tries to recognize the nature of the received pointer and to force the pointed object to behave according to its origin – this is the moment 
    when the dynamic_cast operator becomes indispensable.
If the dynamic_cast operator is used in the following way:
    dynamic_cast<pointer_type>(pointer_to_object)
and the conversion of pointer_to_object to the type of pointer_type is possible, then the result of the conversion is a new pointer which is fully usable. 
Otherwise, the result of the conversion is equal to noneptr.
*/
void play_with_pet(Pet *pet)
{
    pet -> make_sound();

    /* 
    If the pet pointer identifies an object of GermanShepherd class or (don’t forget!) any of its subclasses, we make use of the converted pointer 
    stored in the shepherd variable. Otherwise we do nothing.
    */
    GermanShepherd *shepherd = dynamic_cast<GermanShepherd *>(pet);
    if(shepherd != nullptr)
        shepherd -> laufen();

    MastinEspanol *mastin = dynamic_cast<MastinEspanol *>(pet);    
    if(mastin != nullptr)
        mastin -> correr();
}

int main()
{
    Pet *pet = new Pet("creature");
    Dog *dog = new Dog("Dog");
    GermanShepherd *shepherd = new GermanShepherd("Hund");
    MastinEspanol  *mastin = new MastinEspanol("Perro");

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