////////////////////////
// Type compatibility //
////////////////////////

/*
The static_cast operator looks like this:
    static_cast<target_type>(an_expression)
The target_type is a type name (or a type description) which we want the compiler to use when evaluating the value of an_expression.
For example the following form:
    static_cast<Dog *>(a_pet)
forces the compiler to assume that a_pet is (temporarily) converted into a pointer of type Dog *.
This means that our Dog gains the ability to bark.
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

        void run() 
        { 
            cout << name << ": I'm running" << endl; 
        }
};	

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

// We’ve applied the static_cast operator to enable our pets to make their sounds again.
int main()
{
    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");

    a_pet1 -> run(); 
    static_cast<Cat *>(a_pet1) -> make_sound();
    a_pet2 -> run();
    static_cast<Dog *>(a_pet2) -> make_sound();

    askOS();
    return 0; 
}

/*
Output:

Tom: I'm running
Tom: Meow! Meow!
Spike: I'm running
Spike: Woof! Woof!
*/