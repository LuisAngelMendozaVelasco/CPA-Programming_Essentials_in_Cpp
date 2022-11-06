// Passing an object of a subclass
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

// We’ve changed the interface of the play_with_pet() function and now the function accepts a pointer, not a reference.
void play_with_pet(Pet *pet)
{
    pet -> make_sound();
}

int main()
{
    Pet *pet 				 = new Pet("creature");
    Dog *dog 				 = new Dog("Dog");
    GermanShepherd *shepherd = new GermanShepherd("Hund");
    MastinEspanol  *mastin 	 = new MastinEspanol("Perro");

    play_with_pet(pet);
    play_with_pet(dog);
    play_with_pet(shepherd);
    play_with_pet(mastin);

    askOS();
    return 0; 
}