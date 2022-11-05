/* Type compatibility

The rule stating that objects lying at higher levels are compatible with objects at lower levels of the class hierarchy works even 
when the inheritance chain is arbitrarily long. The program shows a chain of three classes. The pointer to the top-most superclass 
works perfectly for the bottom-most objects too.*/
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

class Cat : public Pet {
public:
    Cat(string n) : Pet(n) {};
    void make_sound()
    { 
        cout << name << ": Meow! Meow!" << endl; 
    }
};

class Persian : public Cat {
public:
    Persian(string n) : Cat(n) {};
};

int main()
{
    Pet 	*a_pet;
    Persian *a_persian;

    a_pet = a_persian = new Persian("Mr. Bigglesworth");
    a_persian -> make_sound();
    static_cast<Persian *>(a_pet) -> make_sound();

    askOS();
    return 0; 	
}