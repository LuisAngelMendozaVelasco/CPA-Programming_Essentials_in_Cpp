/* The 'explicit' keyword

The explicit keyword may be placed in front of a class’s constructor declaration. It protects the constructor from being used in any context requiring the use of implicit conversions. 
This constructor may only be used in an explicit way; hence, the keyword is used when a programmer wants to avoid any side effects that may result from the reckless use of the selected constructors, 
or indeed of all constructors.*/
#include <iostream>
#include "../myFunctions.h"

/* There are two very similar classes, named A and B, respectively. They’re both dummies, in fact – they do nothing at all. 
They’re almost identical, the only difference comes from the constructor declaration: the A class makes use of the explicit keyword, while the B class doesn’t.*/
class A {  
public:
   explicit A(int) {}
};

class B {  
public:
   B(int) {}
};

/* The syntax used in both lines is implicitly presumed as it’s coded in the following way:
   A a(1);
but when the explicit keyword is used, this presumption is illegal.
The A class cannot implicitly convert integers into its objects*/
int main() {
   A a = 1;  // compilation error!
   B b = 1;  // OK!

   askOS();
   return 0;
}