/* Multi-inheritance

We need to emphasize that using this technique is commonly recognized as error-prone and obfuscating class hierarchy.
Any solution that avoids multi-inheritance is generally better and in fact many contemporary object programming languages 
don’t offer multi-inheritance at all. */
#include <iostream>
#include "../myFunctions.h"

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
        cout << "safe    = " << safe << endl;
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

    askOS();
    return 0; 
}