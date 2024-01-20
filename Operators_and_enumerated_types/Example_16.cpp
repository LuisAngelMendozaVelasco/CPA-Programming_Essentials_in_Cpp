///////////////////////
// Pointer operators //
///////////////////////

/*
"Operators"	                                "& *"
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    any

In spite of their many differences, these two operators are grouped together due to their similar usage context.
They’re used to create pseudo-pointers or so-called smart pointers i.e. values which may not have a real “pointing” meaning (it makes no sense to create synthetically 
produced real pointers when they’re already offered by the language).
These pseudo-pointer values can be of any kind and type (e.g. they may be strings used as keys in databases) but don’t forget that our fantasy should conform to reasonable limitations. 
It would be good to ensure that P is always equal to *&P.
The code shows a very limited example of using these operators. Analyse how we’ve used strings as pseudo-pointers. The & operator overloaded inside the P class creates a new “pointer”, 
representing an object with the selected no field value, while the overloaded * operator creates a new object based on the dereferenced “pointer” (string actually) value.
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

class P {
    public:
        int no;

        P(int n) : no(n) { }
        P() : no(0) { }

        string operator&()
        {
            string res = "";

            switch(no) {
                case 0: res = "alpha";
                case 1: res = "bravo";
                case 2: res = "charlie";
            }
            return res;
        }
};

P& operator*(string s)
{
    P *p;

    if(!s.compare("alpha"))
        p = new P(0);
    else if(!s.compare("bravo"))
        p = new P(1);
    else if(!s.compare("charlie"))
        p = new P(2);
    else
        p = new P(-1);

    return *p;
}

int main()
{
    P p1(2);
    string s = &p1;
    P p2 = *s;
    
    cout << "'" << s << "' -> " << p2.no << endl;

    askOS();
    return 0;
}

/*
Output:

'charlie' -> 2
*/