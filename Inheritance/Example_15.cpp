////////////////////////////////
// Passing an object by value //
////////////////////////////////

/*
Any modification made to these parameters will not leave the function – the effects of any operations affecting the object will happen to the copy 
of the object, not the object itself.
There is also another serious inconvenience that turns up when we pass by value an object of a subclass of a class specified as a type of parameter. 
It may result in the “disappearance” of part of the object. So, passing an object by value isn’t generally a good idea. 
*/

#include <iostream> 
#include "../myFunctions.h"
using namespace std;

class Pet {
    protected:
        string name;

    public:
        void name_me(string name)
        { 
            this -> name = name;
        }

        void make_sound()
        { 
            cout << name << " says: no comments" << endl; 
        }
};

/* 
All three possible variants for making use of an object within a function. The name of the individual function shows the way in which 
the function receives its parameter. All three functions try to name their parameter (i.e. to invoke its method named name_me()).
*/
void name_pet_by_value(string name, Pet pet)
{
    pet.name_me(name);
}

void name_pet_by_pointer(string name, Pet *pet)
{
    pet -> name_me(name);
}

void name_pet_by_reference(string name, Pet &pet)
{
    pet.name_me(name);
}

/* 
After the function invocation is complete, the make_sound method is activated in order to check if the naming has been successful and if 
it may be observed outside the function.
*/
int main() 
{
    Pet pet;

    pet.name_me("no_name");
    // Naming an object “Alpha” has affected a copy of the pet object, not the object itself.
    name_pet_by_value("Alpha", pet); // By value
    pet.make_sound();
    name_pet_by_pointer("Beta", &pet); // By pointer
    pet.make_sound();
    name_pet_by_reference("Gamma", pet); // By reference
    pet.make_sound();

    askOS();
    return 0;  
}

/*
Output:

no_name says: no comments
Beta says: no comments
Gamma says: no comments
*/