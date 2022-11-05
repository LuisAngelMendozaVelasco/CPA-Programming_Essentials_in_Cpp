/* Type compatibility

The pointer to the superclass objects (a pointer of type Pet *) may serve as a pointer to subclass objects.*/
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

int main()
{
    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");

    a_pet1 -> run(); 
    // 'a_pet1 -> make_sound();' is not allowed here!
    a_pet2 -> run();
    // 'a_pet2 -> make_sound();' is not allowed here!

    askOS();
    return 0; 
}