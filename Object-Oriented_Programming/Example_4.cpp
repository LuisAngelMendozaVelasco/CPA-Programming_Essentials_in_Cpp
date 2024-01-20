//////////////////////////
// Copying constructors //
//////////////////////////

/*
There is a special kind of constructor intended to copy one object into another. Constructors of this kind have one parameter 
referenced to an object of the same class and are used to copy all important data from the source object to the newly created 
object (or more precisely, to the object currently being created). 
They are implicitly invoked when a declaration of an object is followed by an initiator. It may be also invoked if the declaration 
specifies a constructor suitable for the declaration.
The object data doesn’t actually need to be copied. It could just be manipulated and processed. What’s more important is that the 
data is taken from a different object of the same (or similar) class. 
*/
#include <iostream>
#include "../myFunctions.h"
using namespace std;

// Class with a copying constructor.
class Class1 {
    public:
        Class1(int val) 
        { 
            /* 
            "this pointer"
            We assume that each object is equipped with a special component containing the following traits:
                * its name is this
                * it mustn’t be declared explicitly (it’s a keyword) so it may not be overridden
                * it’s a pointer to the current object – each object has its own copy of the this pointer
            
            The general rule says that:
                * if S is a structure or class and S has a component named C and
                * if p is a pointer to a structure/class of type S
                * then the C component may be accessed in the two following ways:
                    * (*p).C where p is explicitly dereferenced in order to access the C component
                    * p->C where p is implicitly dereferenced in order to access the C component
            */
            this -> value = val; 
        }

        /* 
        The keyword const used in the parameter declaration is a promise that the function won’t attempt 
        to modify the values stored in the referenced object.The copying constructor will also be used when 
        the context requires a copy of a specific object, e.g. when a particular object is transferred to a function as a value-passed actual parameter.
        */
        Class1(Class1 const &source) 
        { 
            value = source.value + 100; 
        }
        int value;
};

// Class without a copying constructor.
class Class2 {
    public:
        Class2(int val) 
        { 
            this -> value = val; 
        }
        int value;
};

int main() 
{
    // Two objects are created for both of the classes while both of the second objects are created by copying the first ones.
    Class1 object11(100), object12 = object11;
    Class2 object21(200), object22 = object21;

    cout << "Class with a copying constructor:  object11.value = " << object11.value << ", object12.value =  " << object12.value << endl;
    cout << "Class without a copying constructor:  object21.value = " << object21.value << ", object22.value =  " << object22.value << endl;

    askOS();
    return 0; 
}

/*
Output:

Class with a copying constructor:  object11.value = 100, object12.value =  200
Class without a copying constructor:  object21.value = 200, object22.value =  200
*/