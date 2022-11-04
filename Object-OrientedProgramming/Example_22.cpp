/* Objects inside objects

An object of any class may be the field of an object of any other class. All rules concerning access to class components are honoured in this case too.*/
#include <iostream>
#include "../myFunctions.h"

using namespace std;

// There’s a very simple class named Element. It’s intended to store one int value. 
class Element {
    int value;
public:
    int get()
    { 
        return value; 
    }
    void put(int value)
    { 
        this -> value = value;
    }
};

// There’s an interesting thing about class Collection: there are two fields of the Element class.
class Collection {
    Element el1, el2;
public:	
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

int main()
{
    Collection coll;

    for(int i = 1; i <= 2; i++)
        coll.put(i, i + 1);
    for(int i = 1; i <= 2; i++)
        cout << "Element #" << i << " = " << coll.get(i) << endl;

    askOS();
    return 0; 
}