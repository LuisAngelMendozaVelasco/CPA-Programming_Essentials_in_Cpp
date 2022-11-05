/* Type compatibility

It’s easy to misuse and abuse the power of the static_cast operator. If we use it thoughtlessly and without adequate care, 
we can get ourself into trouble.
Full pointer validity verification is possible when and only when the program is being executed (in other words, during runtime). 
The C++ language has a second conversion operator designed especially for this case. Its name is somewhat suggestive: dynamic_cast.
The name says that the conversion is carried out dynamically regarding the current state of all created objects. 
This means that the conversion may (or may not) be successful, causing our program to stop if it wants any dog to meow.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

class Pet {
protected:
    string name;
public:
    Pet(string n) { name = n; }
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

/* We’ve tried to treat a cat like a dog and vice versa. The results are disastrous. This effect is caused by the fact that the compiler isn’t able 
to check if the pointer being converted is compatible with the object it points to. The compiler is forced to recognize the pointer as valid – it has no 
other choice, actually. It just has to trust that we know what we’re doing.*/
int main()
{
    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");

    a_pet2 -> run(); 
    static_cast<Cat *>(a_pet2) -> make_sound();
    a_pet1 -> run();
    static_cast<Dog *>(a_pet1) -> make_sound();

    askOS();
    return 0; 	
}