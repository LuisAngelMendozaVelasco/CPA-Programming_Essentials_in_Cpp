/* Arithmetic operators

    Operators	                                + - * / %
    May be implemented as a global function?	YES
    May be implemented as a member function?	YES
    Type of return value	                    Depending on context
All of the above operators are binary.
The code illustrates a simple implementation of a class storing 2-element vectors and can add them as well as find their dot product.
The first function returns a vector, while the second returns a scalar. The first of the functions is a member function, and the second is global.*/
#include <iostream>
#include <vector>
#include "../myFunctions.h"

using namespace std;

class V {
public:
    vector<float> vec;

    V(float a0 = 0.f, float a1 = 0.f)
    { 
        vec.push_back(a0);
        vec.push_back(a1);    
    }

    V operator+(V &arg)
    {
        V res;

        for(int i = 0; i < 2; i++)
            res.vec[i] = vec[i] + arg.vec[i];
        return res;
    }   
};

float operator*(V &left, V &right)
{
    float res = 0.0;
    for(int i = 0; i < 2; i++)
        res += left.vec[i] * right.vec[i];
    return res;
}

int main()
{
    V v1(0.0f, 1.0f), v2(1.0f, 0.0f), v3(0.0f, 0.0f);
    float x;

    // The first of the newly defined operators may be chained
    v3 = v1 + v2;
    x = v1 * v2;
    cout << "(" << v1.vec[0] << ", " << v1.vec[1] << ") + " << "(" << v2.vec[0] << ", " << v2.vec[1] << ") = " << "(" << v3.vec[0] << ", " << v3.vec[1] << ")" << endl;
    cout << "(" << v1.vec[0] << ", " << v1.vec[1] << ") * " << "(" << v2.vec[0] << ", " << v2.vec[1] << ") = " << x << endl;

    askOS();
    return 0;
}