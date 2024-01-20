//////////////////////////////
// Fraction – a header file //
//////////////////////////////

/*
A class with overloaded operators. 
We’ll implement the fraction as a pair of int values representing a numerator and a denominator.
We’re going to equip the class with a basic set of operators allowing us to manipulate the fractions in terms of the four basic arithmetic operations.
We want our new class to:
    * have two int fields, one each for the numerator and the denominator (both private!)
    * have a set of convenient constructors:
        * a default constructor, which sets the fraction to the value of zero (actually 0/1)
        * a one-parameter constructor, which sets the fraction to the value equal to the value of the parameter (actually parameter/1)
        * a two-parameter constructor, which sets the fraction with the numerator equal to the first parameter and the fraction with the denominator equal to the second parameter; 
        the constructor should protect the object from setting the denominator to 0
    * have a set of convenient operators:
        * an operator designed to reduce the fraction – we’ve decided to use the ! for this purpose (yes, we know it looks weird, but we don’t have any better ideas)
        * four operators performing addition, subtraction, multiplication and division; the last one shouldn’t allow us to perform division by zero
        * two helper functions, which evaluate the Greatest Common Divisor and the Lowest Common Multiplier (both private!)
    * have a set of useful functions:
        * a function converting a fraction into a human-readable form, e.g. “[3/5]” for “three fifths”
        * a function converting a fraction into a double, e.g. 3/5 into 0.6
We also want to have an overloaded stream operator allowing us to output the fractions directly to the output streams.
*/

#ifndef __FRACTION_H__
#define __FRACTION_H__
#include <string>

class Fraction {
    private:
        int numerator, denominator;
        int LCM(int x, int y); // Short for Lowest Common Multiplier
        int GCD(int x, int y); // Short of Greatest Common Divisor

    public:
        Fraction();
        Fraction(int n);
        Fraction(int n,int d);
        std::string to_string(); // A function converting a fraction into a string
        double get_double(); // A function converting a fraction into a double value
        Fraction operator!();
        Fraction operator+(Fraction arg);
        Fraction operator*(Fraction arg);
        Fraction operator/(Fraction arg);
        Fraction& operator+=(Fraction arg);
};

std::ostream& operator<< (std::ostream &ostr, Fraction &f);

#endif