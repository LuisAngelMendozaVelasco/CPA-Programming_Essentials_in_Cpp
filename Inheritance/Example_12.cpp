//////////////////
// Polymorphism //
//////////////////

/*
This is a method to redefine the behaviour of a superclass (but only the one that explicitly agrees to be treated in this way!) without touching its implementation.
The word “polymorphism” means that the one and same class may show many (“poly” – like in “polygamy”) forms (“morphs”) not defined by the class itself, but by its subclasses.
Another definition says that polymorphism is the ability to realize class behaviour in multiple ways. Both definitions are ambiguous and could not actually be used to explain 
the true nature of the phenomenon.
*/

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

        /* 
        Virtual means that the method won’t be overridden within any of the possible subclasses. It also means that the method will be redefined (replaced) 
        at the level of the original class.
        */
        virtual void make_sound()
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

/* 
We’ve invoked the make_sound method six times: twice for the objects of the Pet class (a_dog and a_cat) and four times for their superclass (a_pet1 and a_pet2).
We’ve received the exact same output as if the make_sound function defined within the Pet class had simply... disappeared.
It seems that the Pet class is not always the same – any of its subclasses may change its behaviour.
In other words, you cannot predict the behaviour of the class containing a virtual function when you don’t know all of its subclasses. 
It may also mean that some of the aspects of the class are defined outside the class.
This is how polymorphism works.
*/
int main()
{
    Pet *a_pet1, *a_pet2;
    Cat *a_cat;
    Dog *a_dog;

    a_pet1 = a_cat = new Cat("Kitty");
    a_pet2 = a_dog = new Dog("Doggie");	
    a_pet1 -> make_sound();
    a_cat  -> make_sound();
    static_cast<Pet *>(a_cat) -> make_sound();
    a_pet2 -> make_sound();
    a_dog  -> make_sound();
    static_cast<Pet *>(a_dog) -> make_sound();

    askOS();
    return 0; 
}

/*
Output:

Kitty the Cat says: Meow! Meow!
Kitty the Cat says: Meow! Meow!
Kitty the Cat says: Meow! Meow!
Doggie the Dog says: Woof! Woof!
Doggie the Dog says: Woof! Woof!
Doggie the Dog says: Woof! Woof!
*/