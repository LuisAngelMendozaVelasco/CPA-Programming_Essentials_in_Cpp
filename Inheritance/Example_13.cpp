//////////////////
// Polymorphism //
////////////////// 

/*
The binding between the origin of the virtual function (inside the superclass) and its replacement (defined within the subclass) is created dynamically, 
during the execution of the program.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

/* 
We invoke the make_sound method as part of the Pet constructor. We already know that the method is polymorphically replaced by the new implementations 
presented by the Cat and Dog subclasses. We don’t know yet when the replacement occurs.
*/
class Pet {
    protected:
        string name;

    public:
        Pet(string n)
        { 
            name = n;
            make_sound();
        }

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

/* The binding between the original functions and their polymorphic implementations is established when the subclass object is fully created, not sooner.*/
int main() 
{
    Cat *a_cat = new Cat("Kitty");
    Dog *a_dog = new Dog("Doggie");

    a_cat -> make_sound();
    a_dog -> make_sound();

    askOS();
    return 0;   
}

/*
Output:

Kitty the Pet says: Shh! Shh!
Doggie the Pet says: Shh! Shh!
Kitty the Cat says: Meow! Meow!
Doggie the Dog says: Woof! Woof!
*/