////////////////////////////
// Objects inside objects //
////////////////////////////

// We want a constructor other than the default one to be invoked during the creation of an object which is part of another object.

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class Element {
    int value;

    public:
        Element(int value)
        { 
            this -> value = value;
            cout << "Element(" << value << ") constructed!" << endl; 
        }

        int get()
        { 
            return value; 
        }

        void put(int val)
        { 
            value = val; 
        }
};

/* 
The inner constructors have been invoked in the sequence reflecting the order of the declaration inside the Collections class (el1 first), 
not in the order in which the constructors were listed in the Class constructor header (el2 first).
*/
class Collection {
    Element el1, el2;

    public: 
        // We want a constructor other than the default one to be invoked during the creation of an object which is part of another object.
        Collection() : el2(2), el1(1) 
        { 
            cout << "Collection constructed!" << endl; 
        }

        int get(int elno) 
        { 
            return elno == 1 ? el1.get() : el2.get(); 
        }

        void put(int elno, int val)
        { 
            if(elno == 1) 
                el1.put(val); 
            else 
                el2.put(val); 
        }
};

int main() {
    Collection coll;

    askOS();
    return 0; 
}

/*
Output:

Element(1) constructed!
Element(2) constructed!
Collection constructed!
*/