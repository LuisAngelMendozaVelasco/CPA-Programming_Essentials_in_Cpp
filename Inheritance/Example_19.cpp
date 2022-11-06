// The dynamic_cast operator
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

/* The play_with_pet function doesn’t have a pointer but a reference. */
void play_with_pet(Pet &pet)
{
    pet.make_sound();
    /* The form of dynamic_cast utilization is quite different here; the operator takes the following form:
        dynamic_cast<pointer_type>(pointer_to_object)
    and returns a newly transformed (converted) reference which, as a result, may be used like an ordinary l-value (a value that can be put on the left 
    side of = operator); we don’t need to assign it to a variable if we want to make use of it; this is exactly what we did inside the modified function.*/
    dynamic_cast<GermanShepherd &>(pet).laufen();
    dynamic_cast<MastinEspanol &>(pet).correr();
}

/* We mustn’t use a casted reference (or pointer) without being sure that the result is already defined. We already know how to do it using pointers.
However, we can’t do it with refrences*/
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