#include "fraction.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

/* 
LCM and GDM
The implementations of the LCM and GDM algorithms are classic. They are not the best or the most effective, but they are short and simple.
*/

int Fraction::LCM(int x, int y)
{
    int i = y;

    while(y % x)
        y += i;

    return y;
}

int Fraction::GCD(int x, int y)
{
    for(;;) {
        x %= y;
        if(!x)
            return y;

        y %= x;
        if(!y)
            return x;
    }
}

/* 
"Constructors"
We’re a little careless when it comes to recognizing and storing the sign of the fraction. We don’t check if the numerator and the denominator have identical or different signs.
Maybe it’s worth arranging this in a more thoughtful way.
*/
Fraction::Fraction() : numerator(0), denominator(1) { };

Fraction::Fraction(int n) : numerator(n), denominator(1) { };

Fraction::Fraction(int n,int d) : numerator(n), denominator(d)
{
    if(denominator == 0)
        throw std::domain_error("bad fraction");
};

/* 
"to_string() and get_double()"
We’ve implemented the to_string() function using the ostringstream class. The object of this class behaves like an output stream but sends the output text not to a file or a device, 
but to an internal buffer which may be accessed using the str() method.
It requires the inclusion of the <sstream> header file.
The get_double() function is simple.
*/
std::string Fraction::to_string()
{
    std::ostringstream os;
    os << "[" << numerator << "/" << denominator << "]";
    return os.str();
}

double Fraction::get_double()
{
    return double(numerator) / double(denominator);
}

/* 
"Reducing the fraction"
The ! operator performs the reduction. We implement it using the GCD function and we create a new, reduced fraction object.
*/
Fraction Fraction::operator!()
{
    int gcd = GCD(numerator, denominator);
    return Fraction(numerator / gcd, denominator / gcd);
}

/* 
"Adding fractions"
The + operator performs the addition. 
Firstly, we find a new common denominator for both arguments (using the LCM function), and secondly, we evaluate the resulting numerator.
A newly created object containing the result is returned as the operator’s result. Note that we don’t reduce the result.
*/
Fraction Fraction::operator+(Fraction arg)
{
    int common_denom = LCM(denominator, arg.denominator);
    int new_numer = numerator * common_denom / denominator + 
                    arg.numerator * common_denom / arg.denominator;
    Fraction f(new_numer, common_denom);
    return f;
}

/* 
"Multiplying fractions"
The * operator performs the multiplication. 
A newly created object containing the result is returned as the operator’s result.
Note that we reduce the result.
*/
Fraction Fraction::operator*(Fraction arg)
{
    int numera = numerator * arg.numerator;
    int denomi = denominator * arg.denominator;
    Fraction f(numera, denomi);
    return !f;
}

/* 
"Dividing fractions"
The / operator performs the division.
We have to protect ourselves from creating a fraction with the nominator equal to zero. We’ll throw an exception in this case.
A newly created object containing the result is returned as the operator’s result.
Note that we reduce the result.
*/
Fraction Fraction::operator/(Fraction arg)
{
    if(arg.numerator == 0)
        throw std::domain_error("division by zero");
    int numera = numerator * arg.denominator;
    int denomi = denominator * arg.numerator;
    Fraction f(numera, denomi);
    return !f;
}

/* 
"Compound addition"
We’ve decided to add an extra operator to our class: +=
We can use it as a base for implementing all (or some) of the remaining compound operators.
*/
Fraction& Fraction::operator+=(Fraction arg)
{
    int common_denom = LCM(denominator, arg.denominator);
    int numera = numerator * common_denom / denominator + 
                arg.numerator * common_denom / arg.denominator;
    numerator   = numera;
    denominator = common_denom;
    return *this;
}

/* 
"Sending fraction to output stream"
The last part of our code is rather simple: it’s the implementation of the overloaded << stream operator.
*/
std::ostream& operator<< (std::ostream &ostr, Fraction &f)
{
    return ostr << f.to_string();
}