# Inheritance

## Simple subclass

Code:

```cpp
/*
Objects of the Sub class may do almost the same things as their older siblings created from the Super class.
A subclass also means that the class has lost access to the private components of the superclass. We cannot 
write a member function of the Sub class which would be able to directly manipulate the storage variable.
If we want to define a class named Y as a subclass of a superclass named X, we use the following syntax:
    class Y :  visibility_specifier X { … };
*/

#include <iostream>
using namespace std;

class Super {
    private:
        int storage;

    public:
        void put(int val)
        { 
            storage = val; 
        }

        int get() 
        { 
            return storage; 
        }
};

/* 
We’ve defined a class named Sub, which is a subclass of a class named Super. We may also say that the Sub class is derived from the Super class.
When we omit the visibility specifier, the compiler assumes that we’re going to apply a “private inheritance”. This means that all public superclass 
components turn into private access, and private superclass components won't be accessible at all. It consequently means that you’re not allowed to use 
the latter inside the subclass. We have to tell the compiler that we want to preserve the previously used access policy. We do this by using a “public” 
visibility specifier. This doesn’t mean that the private components of the Super class (like the storage variable) will magically turn into public ones. 
Private components will remain private, public components will remain public.
*/
class Sub : public Super { };

int main()
{
    Sub object;

    object.put(100);
    object.put(object.get() + 1);
    cout << "Storage = " << object.get() << endl;

    return 0; 
}
```

Output:

```text
Storage = 101
```

## Protected access level

Code:

```cpp
/*
The keyword protected means that any component marked with it behaves like a public component when used by any 
of the subclasses and looks like a private component to the rest of the world.
We should add that this is true only for publicly inherited classes.
*/

#include <iostream>
using namespace std;

class Super {
    protected:
        int storage;

    public:
        void put(int val)
        { 
            storage = val; 
        }

        int get() 
        { 
            return storage; 
    }
};

// The print function accesses the storage variable from the Superclass. This wouldn’t be possible if the variable was declared as private.
class Sub : public Super {
    public:
        void print() 
        { 
            cout << "storage = " << storage << endl; 
        }
};

// In the main function scope, the storage variable remains hidden anyway.
int main() 
{
    Sub object;

    object.put(100);
    object.put(object.get() + 1);
    object.print();

    return 0; 
}
```

Output:

```text
storage = 101
```

## Multi-inheritance

Code:

```cpp
/*
We need to emphasize that using this technique is commonly recognized as error-prone and obfuscating class hierarchy.
Any solution that avoids multi-inheritance is generally better and in fact many contemporary object programming languages 
don’t offer multi-inheritance at all. 
*/

#include <iostream>
using namespace std;

class SuperA {
    protected:
        int storage;

    public:
        void put(int val)
        { 
            storage = val; 
        }

        int get() 
        { 
            return storage; 
        }
};

class SuperB {
    protected:
        int safe;

    public:
        void insert(int val) 
        { 
            safe = val; 
        }
        
        int takeout()
        { 
            return safe; 
        }
};

class Sub : public SuperA, public SuperB {
    public:
        void print()
        { 
            cout << "storage = " << storage << endl; 
            cout << "safe = " << safe << endl;
        }
};

int main()
{
    Sub object;

    object.put(1);
    object.insert(2);
    object.put(object.get() + object.takeout());
    object.insert(object.get() + object.takeout());
    object.print();

    return 0; 
}
```

Output:

```text
storage = 3
safe = 5
```

## Objects compatibility

Code:

```cpp
/*
Each new class constitutes a new type of data. Each object constructed on the basis of such a class is like a value of the new type.
This means that any two objects may (or may not) be compatible in the sense of their types.
*/

#include <iostream>
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

    return 0; 
}
```

Output:

```text
Meow! Meow!
Woof! Woof!
```

## Type compatibility

Code:

```cpp
/*
The Dog and Cat classes are descendants (to be precise, children) of the common base class Pet. We’ve equipped all the classes with constructors, 
enabling us to give unique names to all the objects we’re going to create in the future. Our pets are also able to run (but you might need a leash).
*/

#include <iostream>
using namespace std;

// Objects derived from the Pet class are able to run. Pets cannot do all the thing that Cat and Dog can do
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

/* 
Objects derived from the Dog and Cat classes are able to run (they inherit this ability from their superclass); 
they can also make sounds (note that this skill is not available for objects of the Pet class).
Cat and Dog objects can do all the things Pets are able to do.
*/
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

/* 
* Objects of the subclass have at least the same capabilities as the superclass objects.
* Objects of the superclass may not have the same capabilities as the subclass objects.
* Objects of the superclass are compatible with objects of the subclass.
* Objects of the subclass are not compatible with objects of the superclass.
*/
int main()
{
    Pet a_pet("pet");
    Cat a_cat("Tom");
    Dog a_dog("Spike");

    a_pet.run();
    a_dog.run(); 
    a_dog.make_sound();
    a_cat.run(); 
    a_cat.make_sound();

    return 0; 
}
```

Output:

```text
pet: I'm running
Spike: I'm running
Spike: Woof! Woof!
Tom: I'm running
Tom: Meow! Meow!
```

## Type compatibility

Code:

```cpp
// The pointer to the superclass objects (a pointer of type Pet *) may serve as a pointer to subclass objects.

#include <iostream>
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

    return 0; 
}
```

Output:

```text
Tom: I'm running
Spike: I'm running
```

## Type compatibility

Code:

```cpp
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

    return 0; 
}
```

Output:

```text
Tom: I'm running
Tom: Meow! Meow!
Spike: I'm running
Spike: Woof! Woof!
```

## Type compatibility

Code:

```cpp
/*
It’s easy to misuse and abuse the power of the static_cast operator. If we use it thoughtlessly and without adequate care, 
we can get ourself into trouble.
Full pointer validity verification is possible when and only when the program is being executed (in other words, during runtime). 
The C++ language has a second conversion operator designed especially for this case. Its name is somewhat suggestive: dynamic_cast.
The name says that the conversion is carried out dynamically regarding the current state of all created objects. 
This means that the conversion may (or may not) be successful, causing our program to stop if it wants any dog to meow.
*/

#include <iostream>
using namespace std;

class Pet {
    protected:
        string name;

    public:
        Pet(string n) {name = n;}

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

/* 
We’ve tried to treat a cat like a dog and vice versa. The results are disastrous. This effect is caused by the fact that the compiler isn’t able 
to check if the pointer being converted is compatible with the object it points to. The compiler is forced to recognize the pointer as valid – it has no 
other choice, actually. It just has to trust that we know what we’re doing.
*/
int main()
{
    Pet *a_pet1 = new Cat("Tom");
    Pet *a_pet2 = new Dog("Spike");

    a_pet2 -> run(); 
    static_cast<Cat *>(a_pet2) -> make_sound();
    a_pet1 -> run();
    static_cast<Dog *>(a_pet1) -> make_sound();

    return 0; 	
}
```

Output:

```text
Spike: I'm running
Spike: Meow! Meow!
Tom: I'm running
Tom: Woof! Woof!
```

## Type compatibility

Code:

```cpp
/*
The rule stating that objects lying at higher levels are compatible with objects at lower levels of the class hierarchy works even 
when the inheritance chain is arbitrarily long. The program shows a chain of three classes. The pointer to the top-most superclass 
works perfectly for the bottom-most objects too.
*/

#include <iostream>
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
    Pet *a_pet;
    Persian *a_persian;

    a_pet = a_persian = new Persian("Mr. Bigglesworth");
    a_persian -> make_sound();
    static_cast<Persian *>(a_pet) -> make_sound();

    return 0; 	
}
```

Output:

```text
Mr. Bigglesworth: Meow! Meow!
Mr. Bigglesworth: Meow! Meow!
```

## Overriding a method in the subclass

Code:

```cpp
/*
When a subclass declares a method of the name previously known in its superclass, the original method is overridden. 
This means that the subclass hides the previous meaning of the method identifier and any invocation encoded within the subclass will refer to the newer method.
*/

#include <iostream>
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

    return 0; 
}
```

Output:

```text
Kitty the Cat says: Meow! Meow!
Kitty the Pet says: Shh! Shh!
Doggie the Dog says: Woof! Woof!
Doggie the Pet says: Shh! Shh!
```

## Overriding a method in the subclass

Code:

```cpp
/*
We don’t use the static_cast, but the some of the pointers are explicitly declared as pointing to the common superclass (Pet). 
The classes themselves remain untouched. We’ve merely changed the way in which we treat the pointers.
*/

#include <iostream>
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

int main() 
{
    Pet *a_pet1, *a_pet2;
    Cat *a_cat;
    Dog *a_dog;

    a_pet1 = a_cat = new Cat("Kitty");
    a_pet2 = a_dog = new Dog("Doggie");
    a_pet1 -> make_sound();
    a_cat  -> make_sound();
    a_pet2 -> make_sound();
    a_dog  -> make_sound();

    return 0; 
}
```

Output:

```text
Kitty the Pet says: Shh! Shh!
Kitty the Cat says: Meow! Meow!
Doggie the Pet says: Shh! Shh!
Doggie the Dog says: Woof! Woof!
```

## Polymorphism

Code:

```cpp
/*
This is a method to redefine the behaviour of a superclass (but only the one that explicitly agrees to be treated in this way!) without touching its implementation.
The word “polymorphism” means that the one and same class may show many (“poly” – like in “polygamy”) forms (“morphs”) not defined by the class itself, but by its subclasses.
Another definition says that polymorphism is the ability to realize class behaviour in multiple ways. Both definitions are ambiguous and could not actually be used to explain 
the true nature of the phenomenon.
*/

#include <iostream>
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

    return 0; 
}
```

Output:

```text
Kitty the Cat says: Meow! Meow!
Kitty the Cat says: Meow! Meow!
Kitty the Cat says: Meow! Meow!
Doggie the Dog says: Woof! Woof!
Doggie the Dog says: Woof! Woof!
Doggie the Dog says: Woof! Woof!
```

## Polymorphism

Code:

```cpp
/*
The binding between the origin of the virtual function (inside the superclass) and its replacement (defined within the subclass) is created dynamically, 
during the execution of the program.
*/

#include <iostream>
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

    return 0;   
}
```

Output:

```text
Kitty the Pet says: Shh! Shh!
Doggie the Pet says: Shh! Shh!
Kitty the Cat says: Meow! Meow!
Doggie the Dog says: Woof! Woof!
```

## Passing an object as a function parameter

Code:

```cpp
/*
Any object may be used as a function parameter and, vice versa, any function may have a parameter as an object of any class.
The code shows two ways to pass an object into a function: by pointer and by reference. We already know that passing a pointer is just a specific form 
of passing a value because a pointer is just a specific kind of value that enables us to modify an object’s state inside a function.
*/

#include <iostream>
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
There are two functions, both of them have two parameters, but only the second is actually of interest to us. The first function declares a pointer 
there and the second one a reference. In both cases, the target class is the same: “Pet”.
*/
void play_with_pet_by_pointer(string name, Pet *pet)
{
	pet -> name_me(name);
	pet -> make_sound();
}

void play_with_pet_by_reference(string name, Pet &pet)
{
	pet.name_me(name);
	pet.make_sound();
}

/* 
We create two objects within the main function: the first (p1) is handled by a pointer and created by the new keyword. The second (p2) is an automatic variable.
We invoke each of the functions twice, the first time according to their declarations, the second time by replacing the way in which the objects are handled: 
p2 is a subject to the & operator; p1 is dereferenced by the * operator.
*/
int main()
{
	Pet *p1 = new Pet();
	Pet p2;

	play_with_pet_by_pointer("anonymous", p1);
	play_with_pet_by_reference("no_name", p2);
	play_with_pet_by_pointer("no_name", &p2);
	play_with_pet_by_reference("anonymous", *p1);

    return 0;  
}
```

Output:

```text
anonymous says: no comments
no_name says: no comments
no_name says: no comments
anonymous says: no comments
```

## Passing an object by value

Code:

```cpp
/*
Any modification made to these parameters will not leave the function – the effects of any operations affecting the object will happen to the copy 
of the object, not the object itself.
There is also another serious inconvenience that turns up when we pass by value an object of a subclass of a class specified as a type of parameter. 
It may result in the “disappearance” of part of the object. So, passing an object by value isn’t generally a good idea. 
*/

#include <iostream>
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

    return 0;  
}
```

Output:

```text
no_name says: no comments
Beta says: no comments
Gamma says: no comments
```

## Passing an object of a subclass

Code:

```cpp
/*
There is a function called play_with_pet, ready to get one parameter of type Pet & (a reference to the Pet object). 
The function is invoked with four different objects taken from different levels of the class hierarchy.
*/

#include <iostream>
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

void play_with_pet(Pet &pet)
{
    pet.make_sound();
}

/* 
An object of the superclass is type compatible with the objects of any of the subclasses. We can declare a formal parameter of a type as a superclass 
and pass an actual parameter of any of the formal parameter’s subclasses.
*/
int main()
{
    Pet pet("creature");
    Dog dog("Dog");
    GermanShepherd shepherd("Hund");
    MastinEspanol mastin("Perro");

    play_with_pet(pet);
    play_with_pet(dog);
    play_with_pet(shepherd);
    play_with_pet(mastin);

    return 0;  
}
```

Output:

```text
creature is silent :(
Dog is silent :(
Hund is silent :(
Perro is silent :(
```

## Passing an object of a subclass

Code:

```cpp
#include <iostream>
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
    Pet *pet = new Pet("creature");
    Dog *dog = new Dog("Dog");
    GermanShepherd *shepherd = new GermanShepherd("Hund");
    MastinEspanol  *mastin = new MastinEspanol("Perro");

    play_with_pet(pet);
    play_with_pet(dog);
    play_with_pet(shepherd);
    play_with_pet(mastin);

    return 0; 
}
```

Output:

```text
creature is silent :(
Dog is silent :(
Hund is silent :(
Perro is silent :(
```

## The dynamic_cast operator

Code:

```cpp
#include <iostream>
using namespace std;

class Pet {
    protected:
        string name;

    public:
        Pet(string name) : name(name) {}

        // We’ve modified the make_sound method inside the top-level class – it’s virtual now. 
        virtual void make_sound()
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

/* 
We’ve made the class tree higher (or rather, deeper, regarding the fact that the tree grows from top to bottom). 
We’ve added two additional levels to the tree. The lowest level consists of two branches containing very specific 
species: German Shepherd and Mastin Espanol. 
*/
class GermanShepherd : public Dog {
    public:
        GermanShepherd(string name) : Dog(name) {}

        void make_sound()
        {
            cout << name << " says: Wuff!" << endl; 
        }

        void laufen()
        { 
            cout << name << " runs (shepherd)!" << endl; 
        }
};

class MastinEspanol : public Dog {
    public:
        MastinEspanol(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Guau!" << endl; 
        }

        void correr()
        { 
            cout << name << " runs (mastin)!" << endl; 
        }
};

/* 
The play_with_pet function gets a pointer of Pet * type (i.e. pointer to the top-level class objects). The function does two important things:
    It invokes the make_sound method; the method is marked as virtual so we expect the “national” objects will be able to make their native sounds;
    It tries to recognize the nature of the received pointer and to force the pointed object to behave according to its origin – this is the moment 
    when the dynamic_cast operator becomes indispensable.
If the dynamic_cast operator is used in the following way:
    dynamic_cast<pointer_type>(pointer_to_object)
and the conversion of pointer_to_object to the type of pointer_type is possible, then the result of the conversion is a new pointer which is fully usable. 
Otherwise, the result of the conversion is equal to noneptr.
*/
void play_with_pet(Pet *pet)
{
    pet -> make_sound();

    /* 
    If the pet pointer identifies an object of GermanShepherd class or (don’t forget!) any of its subclasses, we make use of the converted pointer 
    stored in the shepherd variable. Otherwise we do nothing.
    */
    GermanShepherd *shepherd = dynamic_cast<GermanShepherd *>(pet);
    if(shepherd != nullptr)
        shepherd -> laufen();

    MastinEspanol *mastin = dynamic_cast<MastinEspanol *>(pet);    
    if(mastin != nullptr)
        mastin -> correr();
}

int main()
{
    Pet *pet = new Pet("creature");
    Dog *dog = new Dog("Dog");
    GermanShepherd *shepherd = new GermanShepherd("Hund");
    MastinEspanol  *mastin = new MastinEspanol("Perro");

    play_with_pet(pet);
    cout << endl;
    play_with_pet(dog);
    cout << endl;
    play_with_pet(shepherd);
    cout << endl;
    play_with_pet(mastin);

    return 0; 
}
```

Output:

```text
creature is silent :(

Dog says: Woof!

Hund says: Wuff!
Hund runs (shepherd)!

Perro says: Guau!
Perro runs (mastin)!
```

## The dynamic_cast operator

Code:

```cpp
#include <iostream>
using namespace std;

class Pet {
    protected:
        string name;

    public:
        Pet(string name) : name(name) {}

        virtual void make_sound()
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

        void laufen()
        { 
            cout << name << " runs (shepherd)!" << endl; 
        }
};

class MastinEspanol : public Dog {
    public: 
        MastinEspanol(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Guau!" << endl; 
        }

        void correr()
        { 
            cout << name << " runs (mastin)!" << endl; 
        }
};

// The play_with_pet function doesn’t have a pointer but a reference.
void play_with_pet(Pet &pet)
{
    pet.make_sound();
    /* 
    The form of dynamic_cast utilization is quite different here; the operator takes the following form:
        dynamic_cast<pointer_type>(pointer_to_object)
    and returns a newly transformed (converted) reference which, as a result, may be used like an ordinary l-value (a value that can be put on the left 
    side of = operator); we don’t need to assign it to a variable if we want to make use of it; this is exactly what we did inside the modified function.
    */
    dynamic_cast<GermanShepherd &>(pet).laufen();
    dynamic_cast<MastinEspanol &>(pet).correr();
}

/* 
We mustn’t use a casted reference (or pointer) without being sure that the result is already defined. We already know how to do it using pointers.
However, we can’t do it with references.
*/
int main()
{
    Pet pet("creature");
    Dog dog("Dog");
    GermanShepherd shepherd("Hund");
    MastinEspanol mastin("Perro");

    play_with_pet(pet);
    play_with_pet(dog);
    play_with_pet(shepherd);
    play_with_pet(mastin);

    return 0; 
}
```

Output:

```text
creature is silent :(
terminate called after throwing an instance of 'std::bad_cast'
  what():  std::bad_cast
Aborted
```

## try-catch statement

Code:

```cpp
/*
It looks like this:
    try {
        thing_we_want_to_try_although_we_are_not_quite_sure_if_it_is_reasonable();
    } 
    catch(...) {}
Using this statement we can “try” some risky activities and “catch” errors that appear during the execution.
*/

#include <iostream>
using namespace std;

class Pet {
    protected: 
        string name;

    public:
        Pet(string name) : name(name) {}

        virtual void make_sound()
        { 
            cout << name << " is silent :(" << endl; 
        }
};

class Dog : public Pet {
    public:	
        Dog(string name) : Pet(name) {}

        void make_sound()
        { 
            cout << name << " says: Woof!" << endl; \
        }
};

class GermanShepherd : public Dog {
    public:	
        GermanShepherd(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Wuff!" << endl; 
        }

        void laufen()
        { 
            cout << name << " runs (shepherd)!" << endl; 
        }
};

class MastinEspanol : public Dog {
    public:	
        MastinEspanol(string name) : Dog(name) {}

        void make_sound()
        { 
            cout << name << " says: Guau!" << endl; 
        }

        void correr()
        { 
            cout << name << " runs (mastin)!" << endl; 
        }
};

/* 
We catch the error and do nothing. Thanks to that, our dogs are ready to return to their normal life.
The error that arises during the unsuccessful casting is simply ignored, but in effect (paradoxically), the casting is safe now 
and will cause no harm in the case of failure.
*/
void play_with_pet(Pet &pet) {
    pet.make_sound();

    try {
        dynamic_cast<GermanShepherd &>(pet).laufen();
    } 
    catch(...) {}

    try {
        dynamic_cast<MastinEspanol &>(pet).correr();
    }
    catch(...) {}
}

int main() 
{
    Pet pet("creature");
    Dog dog("Dog");
    GermanShepherd shepherd("Hund");
    MastinEspanol mastin("Perro");

    play_with_pet(pet);
    cout << endl;
    play_with_pet(dog);
    cout << endl;
    play_with_pet(shepherd);
    cout << endl;
    play_with_pet(mastin);

    return 0; 
}
```

Output:

```text
creature is silent :(

Dog says: Woof!

Hund says: Wuff!
Hund runs (shepherd)!

Perro says: Guau!
Perro runs (mastin)!
```

## Copying constructors

Code:

```cpp
/*
The copying constructor is a specific form of constructor designed to make a more or less literal copy of an object. 
You can recognize this constructor by its distinguishable header.
Assuming that a class is called A, its copying constructor will be declared as:
    A(A &)
This means that the constructor expects one parameter to be a reference to an object whose content is intended to be copied to the newly created object. 
There’s no obligation to declare your own copying constructor within any of the classes.
If there’s no explicit copying constructor in some class, an implicit constructor will be used instead. 
The implicit constructor simply clones (bit by bit) the source object, producing a twin copy of it. It works satisfactorily in most cases, 
but requires attention and some consideration when used with objects that contain other objects or pointers.
*/

#include <iostream>
using namespace std;

// The class declared in the example has no explicit copying constructor. We expect that an implicit constructor will be used then.
class Class {
    int data;

    public:
        Class(int value) : data(value) {}

        void increment() 
        {
            data++; 
        }

        int value()
        { 
            return data; 
        }
};

int main()
{
    /* 
    It’ll be activated twice – during the initializations of the o2 and o3 objects. The example reminds us of two possible ways to specify an object’s declaration, 
    using the = operator in the classical assignment notation and using the functional notation.
    The o2 and o3 objects will be created as twin copies of o1 and o2 objects respectively, but we need to stress that these three objects have nothing in common.
    In particular, each of them has its own data field. All three objects live their own lives, separate from their siblings. As you can predict, 
    the increment applied to the o1 object affects neither the o2, nor the o3 object.
    */
    Class o1(123);
    Class o2 = o1;
    Class o3(o2);

    o1.increment();
    cout << "o1.value() = " << o1.value() << endl;
    cout << "o2.value() = " << o2.value() << endl;
    cout << "o3.value() = " << o3.value() << endl;

    return 0; 
}
```

Output:

```text
o1.value() = 124
o2.value() = 123
o3.value() = 123
```

## Copying constructors

Code:

```cpp
// Blindly relying on the implicit copying constructor may be dangerous and may cause adverse effects.

#include <iostream>
using namespace std;

/* 
The data isn’t stored in a regular variable but in a piece of memory allocated by the new operator.
The data field is declared as a pointer to the int values (in other words, it’s a variable of type int *).
The implicit copying constructor makes a twin copy of an object. Note that this is of an object, not the entities existing outside the object. 
This means that the data field will obviously be copied (cloned) into the newly created object, but in effect it will point to the same piece of memory.
This also means that different objects may have something in common – they may share some data among them.
*/
class Class {
    int *data;

    public:
        Class(int value) 
        {
            data = new int;
            *data = value;
        }

        void increment()
        { 
            (*data)++; 
        }

        int value()
        { 
            return *data; 
        }
};

int main()
{
    Class o1(123);
    Class o2 = o1;
    Class o3(o2);

    o1.increment();
    cout << "o1.value() = " << o1.value() << endl;
    cout << "o2.value() = " << o2.value() << endl;
    cout << "o3.value() = " << o3.value() << endl;

    return 0; 
}
```

Output:

```text
o1.value() = 124
o2.value() = 124
o3.value() = 124
```

## Explicit constructor

Code:

```cpp
// The explicit constructor gets one parameter of type int.

#include <iostream>
using namespace std;

class Class {
    int *data;

    public:
        Class(int value)
        {
            data = new int;
            *data = value;
        }

        void increment()
        {
            (*data)++; 
        }

        int value()
        { 
            return *data; 
        }
};

int main()
{
    Class o1(123);
    Class o2(o1.value());
    Class o3(o2.value());

    o1.increment();
    cout << "o1.value() = " << o1.value() << endl;
    cout << "o2.value() = " << o2.value() << endl;
    cout << "o3.value() = " << o3.value() << endl;

    return 0;     
}
```

Output:

```text
o1.value() = 124
o2.value() = 123
o3.value() = 123
```

## Adding an explicit copying constructor

Code:

```cpp
/*
Let’s assume that we don’t want our objects to share any data. We’re determined to isolate the objects and keep them all separate. 
Taking into account the structure of the class, we should consider adding an explicit copying constructor to our class.
*/

#include <iostream>
using namespace std;

class Class {
    int *data;
    public:
        Class(int value)
        {
            data = new int;
            *data = value;
        }

        /* 
        The constructor will be responsible for making a copy on its own. Don’t forget that no automatic activities will be performed if 
        a class is already equipped with a copying constructor.
        Our new copying constructor has allocated a new piece of memory and copied original data content to it. 
        This ensures that the object will be separate and will have no common parts.
        */
        Class(Class &source)
        { 
            data = new int;
            *data = source.value();
        }

        void increment()
        {
            (*data)++;
        }

        int value()
        { 
            return *data; 
        }
};

int main()
{
    Class o1(123);
    Class o2 = o1;
    Class o3(o2);

    o1.increment();
    cout << "o1.value() = " << o1.value() << endl;
    cout << "o2.value() = " << o2.value() << endl;
    cout << "o3.value() = " << o3.value() << endl

    return 0;   
}
```

Output:

```text
o1.value() = 124
o2.value() = 123
o3.value() = 123
```

## Copying constructors

Code:

```cpp
/*
Using an object as function parameters passed by value isn’t a good idea. The mechanism of passing parameters by value assumes that a function
operates on the copy of an actual parameter. This is clear when we consider parameters of simple types (like int or float), 
but it becomes more complex when the parameter is an object.
We do not simply make a copy of an object. The only automatic way in which the copy may be obtained is to invoke the copying constructor 
and to face up to all the advantages and disadvantages of that approach.
*/

#include <iostream>
using namespace std;

class Dummy {
    public:
        Dummy(int value) {}

        /* 
        The copying constructor will be invoked when an object is passed to a function by value. We’ve had to make the constructor a 
        little verbose – this is the simplest way to trace its paths.
        */
        Dummy(Dummy &source)
        { 
            cout << "Hi from the copy constructor!" << endl;
        }
};

void do_something(Dummy ob)
{
    cout << "I'm here!" << endl;
}

int main()
{
    Dummy o1(123);

    do_something(o1);

    return 0;   
}
```

Output:

```text
Hi from the copy constructor!
I'm here!
```

## Copying constructors

Code:

```cpp
/*
In some cases, we may want to prevent any use of the copying constructor forcing the user of our class to construct its objects in a more detailed way.
All we have to do is specify the explicit copying constructor (it may be empty) and put it inside the private part of our class.
Any attempt to make use of the copying constructor (whether implicit or explicit) will cause a compilation error.
*/

#include <iostream>
using namespace std;

class Dummy {
    private:
        Dummy(Dummy &source) {}

    public:
        Dummy(int value) {}
};

void do_something(Dummy ob)
{
    cout << "I'm here!" << endl;
}

/* 
Errors are caused by the fact that the copying constructor is private i.e. it's unaccessible in contexts where it is invoked implicitly e.g. during o2 declaration. 
The same problem appears during do_something() invocation when o1 is copied into parameter passed by value. 
Moving the constructor to public part eliminates these errors.
*/
int main()
{
    Dummy o1(123);
    Dummy o2 = o1; // Error

    do_something(o1); //Error

    return 0;   
}
```

Output:

```text
error: ‘Dummy::Dummy(Dummy&)’ is private within this context
note: declared private here
    Dummy(Dummy &source) {}
```

## Example 27

Code:

```cpp
/* 
The code shows a class that doesn’t have a constructor at all. We are aware of all the possible hazards connected with the use of uninitialized objects.
The class will be implicitly equipped with the so-called implicit default (parameter-less) constructor but the constructor will do nothing at all. 
Our will will be wilful indeed!
*/

#include <iostream>
using namespace std;

// The class has no constructor. In effect its fields will not be initialized in any way. The values outputted by the display() method may be completely random then.
class NoConstructorsAtAll {
    public:
        int i;
        float f;

        void display()
        { 
            cout << "i = " << i << ", f = " << f << endl; 
        }
};

int main()
{
    NoConstructorsAtAll  o1;
    NoConstructorsAtAll *o2 = new NoConstructorsAtAll;

    o1.display();
    o2 -> display();

    return 0;   
}
```

Output:

```text
i = 73728, f = 0
i = 0, f = 0
```

## Example 28

Code:

```cpp
/* 
The code cause compilation errors. There’s a constructor within the class. The existence of any constructor is like a statement given by a 
developer: “I’m ready to use constructors in my class”.
The statement is recognized by the compiler as a readiness to provide all the needed constructors so the compiler won’t produce the implicit 
default constructor for that class anymore.
The default constructor has to be implicitly invoked when a new object is created. We can write our own default (parameter-less) constructor.
It’ll make our code fully compilable and it can look something like this:
    WithConstructor() : i(0), f(0.0) { }
and be placed somewhere in the public part of the class. It’ll cause both of the fields to be zeroed at the beginning of an object’s life.
*/

#include <iostream>
using namespace std;

class WithConstructor {
    public:
        int i;
        float f;

        WithConstructor(int a, float b) : i(a), f(b) { }

        void display()
        { 
            cout << "i = " << i << ", f = " << f << endl; 
        }
};

int main()
{
    WithConstructor  o1;
    WithConstructor *o2 = new WithConstructor;

    o1.display();
    o2 -> display();

    return 0; 
}
```

Output:

```text
error: no matching function for call to ‘WithConstructor::WithConstructor()’
    WithConstructor  o1;
note: candidate: ‘WithConstructor::WithConstructor(int, float)’
    WithConstructor(int a, float b) : i(a), f(b) { }
note:   candidate expects 2 arguments, 0 provided
```

## Example 29

Code:

```cpp
/* 
We’ve changed the header of the existing constructor by adding default values to both parameters. This means that from a compiler’s perspective, 
an invocation like this one:
    WithConstructor()
is solvable even when the parameter-less constructor cannot be found within the class.
The compiler will look for another compatible candidate for the invocation and will find it, assuming that it corresponds to the following invocation:
    WithConstructor(0, 0.)
*/

#include <iostream>
using namespace std;

class WithConstructor {
    public:
        int i;
        float f;

        WithConstructor(int a = 0, float b = 0.) : i(a), f(b) { }

        void display()
        { 
            cout << "i = " << i << ", f = " << f << endl; 
        }
};

int main()
{
    WithConstructor  o1;
    WithConstructor *o2 = new WithConstructor();

    o1.display();
    o2 -> display();

    return 0; 
}
```

Output:

```text
i = 0, f = 0
i = 0, f = 0
```

## Compositions vs. constructors

Code:

```cpp
/*
Inheritance isn’t the only form of class/object coexistence. In fact, inheritance is completely useless when we express many of the complicated relationships 
existing in the real world.
For example, we can imagine a class designed to gather different kinds of dogs. Making a class and putting it at the bottom of a dog breed inheritance tree 
isn’t a good idea and won’t bear desirable fruit. The right solution will come to our minds when we understand the actual role of the class – it should gather 
some dogs so, in fact, it will consists of dogs (like a kennel).
This means that the class should include dogs, not inherit them. The kennel has nothing or really very little in common with a dog 
(for example, there is no kennel that can bark).
This means that the class should include dogs, not inherit them. The kennel has nothing or really very little in common with a dog (for example, there is no kennel that can bark).
We can say that any complex structure is composed using simpler elements – for example, a car is composed of an engine, transmission, suspension, etc. If we imagine all these 
parts as classes we’ll see the car class as a composition that has nothing to do with inheritance. Building a class is called composition.
*/

#include <iostream>
using namespace std;

class A { 
    public:
        void do_it() 
        { 
            cout << "A is doing something" << endl; 
        }
};

class B { 
    public:
        void do_it() 
        { 
            cout << "B is doing something" << endl; 
        }
};

// This example shows a simple dummy class consisting (composed) of two objects of two independent classes.
class Compo {
    public:
        A f1;
        B f2;
};

int main() 
{
    Compo  co;

    co.f1.do_it();
    co.f2.do_it();

    return 0; 
}
```

Output:

```text
A is doing something
B is doing something
```

## Example 31

Code:

```cpp
/* 
The classes have been equipped them with copying constructors. They aren’t all that complex and they don’t actually do anything useful. 
They only emit a message allowing us to notice that the constructor has been invoked. We’ve had to add default constructors too.
*/

#include <iostream>
using namespace std;

class A { 
    public:
        A(A &src)
        { 
            cout << "copying A..." << endl; 
        }

        A() { }

        void do_it() 
        { 
            cout << "A is doing something" << endl; 
        }
};

class B { 
    public:
        B(B &src) 
        { 
            cout << "copying B..." << endl; 
        }

        B(){ }

        void do_it() 
        { 
            cout << "B is doing something" << endl; 
        }
};

/* 
The Compo class doesn’t have a copying constructor. This means that the compiler will generate an implicit copying constructor for the class.
This constructor copies the objects bit by bit.
Besides its normal activity (the cloning), the copying constructor takes into consideration all the existing copying constructors 
(implicit and explicit) defined within the objects used to compose the class. This gives a chance to copy the components in the most appropriate way.
*/
class Compo {
    public:
        Compo() { } ;
        A f1;
        B f2;
};

int main() 
{
    Compo co1;
    Compo co2 = co1;

    co2.f1.do_it();
    co2.f2.do_it();

    return 0; 
}
```

Output:

```text
copying A...
copying B...
A is doing something
B is doing something
```

## Example 32

Code:

```cpp
// Compo class has its own copying constructor. It’ll be implicitly invoked once during the life of our program at the moment the co2 object is created.

#include <iostream>
using namespace std;

class A { 
    public:
        A(A &src)
        { 
            cout << "copying A..." << endl; 
        }

        A() { }

        void do_it()
        { 
            cout << "A is doing something" << endl; 
        }
};

class B { 
    public:
        B(B &src)
        { 
            cout << "copying B..." << endl; 
        }

        B(){ };

        void do_it()
        { 
            cout << "B is doing something" << endl; 
        }
};

/* 
The explicit copying constructor (written by us) has invoked none of the component’s copying constructors. Unfortunately, defining our own 
copying constructor means we assume full responsibility for all the activities needed to carry out responsible copying. 
This means that we need to modify the constructor. One way to do this is to add a line like this one:
    Compo(Compo &src) : f1(src.f1), f2(src.f2)
    { 
        cout << "Copying Compo..." << endl; 
    }
instead of
    Compo(Compo &src)
    { 
        cout << "Copying Compo..." << endl; 
    }
*/
class Compo {
    public:
        Compo(Compo &src)
        { 
            cout << "Copying Compo..." << endl; 
        }

        Compo() { };

        A f1;
        B f2;
};

int main() 
{
    Compo  co1;
    Compo  co2 = co1;

    co2.f1.do_it();
    co2.f2.do_it();

    return 0; 
}
```

Output:

```text
Copying Compo...
A is doing something
B is doing something
```

## Friend

Code:

```cpp
/*
A friend of a class may be:
    * A class (it’s called the friend class)
    * A function (it’s called the friend function)
A friend (class of function) can access those components hidden from others. Friends are allowed to access or to use private and protected components of the class.
If there are two classes called, for example, A and B, and if A wants B to be able to access its private possessions, it has to announce that B is its friend. 
The announcement works in one direction only. The B class can’t just say, “I am A’s friend” – it won’t work.
*/

#include <iostream>
using namespace std;

/* 
A class named Class has announced that Friend is its friend. In effect, an object of the Friend class is able to manipulate the Class’s private 
fields and invoke its private methods.
It doesn’t matter where we add the friendship declaration, i.e. the line starting with the phrase:
    friend class ... ;
may exist inside any of the class parts (public, private or protected), but must be placed outside any function or aggregate.
*/
class Class {
    friend class Friend;

    private:
        int field;

        void print()
        { 
            cout << "It's a secret, that field = " << field << endl; 
        }
};

class Friend {
    public:
        void do_it(Class &c) 
        { 
            c.field = 100; 
            c.print(); 
        }
};

int main()
{
    Class o;
    Friend f;

    f.do_it(o);

    return 0; 
}
```

Output:

```text
It's a secret, that field = 100
```

## Friends rules

Code:

```cpp
/*
There are some additional rules that must be taken into account:
    * a class may be a friend of many classes.
    * a class may have many friends.
    * my friend’s friend isn’t my friend.
    * friendship isn’t inherited – the subclass has to define its own friendships.
*/

#include <iostream>
using namespace std;

class A {
    friend class B;
    friend class C;

    private:
        int field;

    protected:
        void print() 
        { 
            cout << "It's a secret, that field = " << field << endl; 
        }
};

class C {
    public:
        void do_it(A &a)
        { 
            a.print(); 
        }
};

class B {
    public:
        void do_it(A &a, C &c)
        { 
            a.field = 111; c.do_it(a); 
        }
};

int main()
{
    A a; B b; C c;

    b.do_it(a, c);

    return 0; 
}
```

Output:

```text
It's a secret, that field = 111
```

## Friend functions

Code:

```cpp
/*
A function may be a class’s friend too. Such a function may access all the private and/or protected components of the class.
The rules are a bit different:
    * a friendship declaration must contain a complete prototype of the friend function (including return type); a function with the same name, 
      but incompatible in the sense of the parameters’ conformance, will not be recognized as a friend.
    * a class may have many friend functions.
    * a function may be a friend of many classes.
    * a class may recognize as friends both global and member functions.
*/

#include <iostream>
using namespace std;

/* 
It does nothing except inform the compiler that a class named A will be in use. The lack of line will cause compilation errors as the compiler 
won’t be aware of the existence of the A class when analysing the C class body.
*/
class A;

class C {
    public:
        void dec(A &a);
};

/* 
The A class has three friends. They are:
    * the B class.
    * the global do_it() function.
    * the member function dec() (from the C class).
*/
class A {
    friend class B;
    friend void C::dec(A&);
    friend void do_it(A&);

    private:
        int field;

    protected:
        void print() 
        { 
            cout << "It's a secret, that field = " << field << endl; 
        }
};

void C::dec(A &a) 
{ 
    a.field--; 
}

class B {
    public:
        void do_it(A &a) 
        { 
            a.print(); 
        }
};

void do_it(A &a) 
{
    a.field = 99;
}

int main() 
{
    A a; B b; C c;

    do_it(a);
    b.do_it(a);

    return 0; 
}
```

Output:

```text
It's a secret, that field = 99
```