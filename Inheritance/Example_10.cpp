/////////////////////////////////////////
// Overriding a method in the subclass //
/////////////////////////////////////////

/*
When a subclass declares a method of the name previously known in its superclass, the original method is overridden. 
This means that the subclass hides the previous meaning of the method identifier and any invocation encoded within the subclass will refer to the newer method.
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

        void make_sound()
        { 
            cout << name << " the Pet says: Shh! Shh!" << endl; 
        }
};

/* 
We can experience the effects of overriding when we invoke the make_sound from within the a_cat and a_dog objects. 
We’ll obviously “hear” the sound adequate to the class of animals that emits them.
*/
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
We can see that the effects of the overriding may be reversed (or voided) if we use the static_cast operator in reverse. 
We’re trying to treat a pointer to a subclass (Dog or Cat) as a pointer to its superclass (Pet) – called “uppercasting”.
In our case, the uppercasting unhides the original implementation of the make_sound method.
*/
int main()
{
    Cat *a_cat = new Cat("Kitty");;
    Dog *a_dog = new Dog("Doggie");;

    a_cat -> make_sound();
    static_cast<Pet *>(a_cat) -> make_sound();
    a_dog -> make_sound();
    static_cast<Pet *>(a_dog) -> make_sound();

    askOS();
    return 0; 
}

/*
Output:

Kitty the Cat says: Meow! Meow!
Kitty the Pet says: Shh! Shh!
Doggie the Dog says: Woof! Woof!
Doggie the Pet says: Shh! Shh!
*/