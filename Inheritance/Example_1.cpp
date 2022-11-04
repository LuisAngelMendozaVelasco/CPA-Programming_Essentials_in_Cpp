/* Simple subclass

Objects of the Sub class may do almost the same things as their older siblings created from the Super class.
A subclass also means that the class has lost access to the private components of the superclass. We cannot 
write a member function of the Sub class which would be able to directly manipulate the storage variable.
If we want to define a class named Y as a subclass of a superclass named X, we use the following syntax:
    class Y :  visibility_specifier X { … };*/
#include <iostream>
#include "../myFunctions.h"

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

/* We’ve defined a class named Sub, which is a subclass of a class named Super. We may also say that the Sub class is derived from the Super class.
When we omit the visibility specifier, the compiler assumes that we’re going to apply a “private inheritance”. This means that all public superclass 
components turn into private access, and private superclass components won't be accessible at all. It consequently means that you’re not allowed to use 
the latter inside the subclass. We have to tell the compiler that we want to preserve the previously used access policy. We do this by using a “public” 
visibility specifier. This doesn’t mean that the private components of the Super class (like the storage variable) will magically turn into public ones. 
Private components will remain private, public components will remain public.*/
class Sub : public Super { };

int main()
{
    Sub object;

    object.put(100);
    object.put(object.get() + 1);
    cout << "Storage = " << object.get();

    askOS();
    return 0; 
}