///////////////////////////
// Objects compatibility //
///////////////////////////

/*
Each new class constitutes a new type of data. Each object constructed on the basis of such a class is like a value of the new type.
This means that any two objects may (or may not) be compatible in the sense of their types.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Cat {
    public:
        void make_sound()
        { 
            cout << "Meow! Meow!" << endl; 
        }
};

class Dog {
    public:
        void make_sound()
        { 
                cout << "Woof! Woof!" << endl; 
        }
};  

/* 
The objects of the Cat class are not compatible with the objects of the Dog class, although the structure of both classes is identical. 
Neither of the following assignments is valid and both of them will cause a compiler error:
    a_dog = a_cat;
    a_cat = a_dog;
As you see, the Dog and Cat classes have nothing in common in the sense of inheritance – they’re both completely independent.
So we can say that objects derived from classes which lie in different branches of the inheritance tree are always incompatible.
*/
int main()
{
    Cat *a_cat = new Cat();
    Dog *a_dog = new Dog();

    a_cat -> make_sound();
    a_dog -> make_sound();

    askOS();
    return 0; 
}

/*
Output:

Meow! Meow!
Woof! Woof!
*/