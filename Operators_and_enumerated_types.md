# Operators and enumerated types

## Implementing the << operator

Code:

```cpp
/*
We’ll define an operator function for the “<<” operator (the new face of the push member function).
We’ll add a new method of declaration into the header file – this is what it looks like:
    void operator << (int v);
Note:
    * the operator must accept different forms of its arguments, like:
        * variable, e.g,
        * stack << VAR;
        * expression, e.g,
        * stack << 2 * VAR;
        * literal, e.g,
        * stack << 2;
        * etc
    this means that the corresponding parameter of the operator function must be passed by value
    * the operator may throw an exceptions just like an ordinary member function.
    * we’ve declared the operator function as void, as we don’t want the operator to evaluate any new values.
*/

#include <iostream>
using namespace std;

class Stack {
    private:
        int *stackstore;
        int SP;

    public:
        Stack(int size = 100)
        {
            stackstore = new int[size];
            SP = 0;
        }

        ~Stack()
        {
            delete [] stackstore;
        }

        void push(int value)
        {
            stackstore[SP++] = value;
        }

        int pop()
        {
            return stackstore[--SP];
        }

        void operator<< (int v);
};

/* 
The object of the class is the first of the operator’s arguments (the left one, to be precise) so we have nothing more to do except invoke the push() method 
with a value from the second (right) operator’s argument.
Despite these reservations, the function behaves quite normally and all the general rules referring to functions are obeyed.
The new operator works equally well with literals, expressions and variables.
*/
void Stack::operator<< (int v)
{
    push(v);
}

int main()
{
    int i = 2;
    Stack stk;

    stk << 1;
    stk << 2 * i;
    stk << i;
    cout << "stk.pop(): " << stk.pop() << endl;
    cout << "stk.pop(): " << stk.pop() << endl;
    cout << "stk.pop(): " << stk.pop() << endl;

    return 0; 
}
```

Output:

```text
stk.pop(): 2
stk.pop(): 4
stk.pop(): 1
```

## Improving the << operator

Code:

```cpp
/*
There are two different ways of using the “<<” operator: one implemented by us and one we got from the streams library.
Stream operators may be chained like this:
    cout << i << endl;
Our operators aren’t that smart (yet). It’ll provoke a whole load of compilation errors.
The line we is interpreted by the compiler in the following way:
    (cout << i) << endl;
The expression inside the parentheses returns a reference to a stream (namely: the cout stream) so it can be used (reused) as a left argument for the next "<<" in a chain.
We can do the same thing with our stack, but it means that the operator functions may not be void anymore. They have to return a value as a reference 
to the stack object – the same object for which the operators were activated for the first time.
*/

#include <iostream>
using namespace std;

class Stack {
    private:
        int *stackstore;
        int SP;

    public:
        Stack(int size = 100)
        {
            stackstore = new int[size];
            SP = 0;
        }

        ~Stack()
        {
            delete [] stackstore;
        }

        void push(int value)
        {
            stackstore[SP++] = value;
        }

        int pop()
        {
            return stackstore[--SP];
        }

        Stack& operator<< (int v);
        Stack& operator>> (int &v);
};

// The function returns a reference to its maternal object. We use the this pointer for that purpose.
Stack& Stack::operator<< (int v)
{
    push(v);
    return *this;
}

// We improve the “>>” operator in the same way.
Stack& Stack::operator>> (int &v)
{
    v = pop();
    return *this;
}

int main()
{
    int i = 2, j;
    Stack stk;

    stk << 1 << 2 * i;
    stk >> j >> i;
    cout << "push(): " << j << endl << "push(): " << i << endl;

    return 0; 
}
```

Output:

```text
push(): 4
push(): 1
```

## Overloaded operators

Code:

```cpp
/* 
Implementing overloaded operators as member functions is easy when we’re the “owner” of the class and we can modify its source code in any way. It may be impossible 
when the source code is unavailable. In many cases it may be possible to write our own subclass containing all the desired operators, but this may be inconvenient in some cases.
Fortunately, we’re allowed to write operator functions outside any class – using both kinds of operators is the same, and when we use an overloaded operator without knowing 
its implementation, we’re not able to guess which of the methods has been used.
*/

#include <iostream>
using namespace std;

class Stack {
    private:
        int *stackstore;
        int SP;

    public:
        Stack(int size = 100)
        {
            stackstore = new int[size];
            SP = 0;
        }

        ~Stack()
        {
            delete [] stackstore;
        }

        void push(int value)
        {
            stackstore[SP++] = value;
        }

        int pop()
        {
            return stackstore[--SP];
        }
};

/* 
A standalone operator function must have two arguments and the order of the arguments reflects the order of the operator’s arguments.
Not all operators may be overloaded in this way!
*/
Stack& operator<< (Stack &s, int v)
{
    s.push(v);
    return s;
}

Stack& operator>>(Stack &s, int &v)
{
    v = s.pop();
    return s;
}

int main()
{
    int i = 2, j;
    Stack stk;

    stk << 1 << 2 * i;
    stk >> j >> i;
    cout << "push(): " << j << endl << "push(): " << i << endl;

    return 0; 
}
```

Output:

```text
push(): 4
push(): 1
```

## An indexing operator for the stack

Code:

```cpp
/*
We’ll redefine the meaning of the indexing operator.
From a certain point of view, a stack is an array – a very specific one, but still an array.
We want the indexing to work in this odd way:
    Stack[0] returns a reference to the element lying at the top of the stack
    Stack[-1] returns a reference to the element lying below the top of the stack
This is a reference, not a value, as we want to use the operator inside l-value expressions, e.g. as a left argument of the assignment operator.
*/

#include <iostream>
using namespace std;

class Stack {
    private:
        int *stackstore;
        int SP;

    public:
        Stack(int size = 100)
        {
            stackstore = new int[size];
            SP = 0;
        }

        ~Stack()
        {
            delete [] stackstore;
        }

        void push(int value)
        {
            stackstore[SP++] = value;
        }

        int pop()
        {
            return stackstore[--SP];
        }

        int& operator[](int index);
};

/* 
The function returns a value of type int& as the stack’s element type is int.
The function has one argument – the index; we pass it by value as the array index doesn’t need to be a variable – it may be an expression too.
*/
int& Stack::operator[] (int index)
{
    // An attempt to reach for a non-existent stack element will cause an exception to be thrown. It seems that the std::range_error is the best candidate for this purpose.
    if(index > 0 || index <= -SP)
        throw std::range_error("out of stack");
    return stackstore[SP + index - 1];
}

Stack& operator<< (Stack &s, int v)
{
    s.push(v);
    return s;
}

Stack& operator>> (Stack &s, int &v)
{
    v = s.pop();
    return s;
}

int main()
{
    int i = 2, j;
    Stack stk;

    stk << 1 << 2 * i;
    cout << "stk[0]: " << stk[0] << endl << "stk[1]: " << stk[-1] << endl;
    stk[0] = stk[-1] = 0;
    stk >> i >> j;
    cout << "stk[1]: " << i << endl << "stk[0]: " << j << endl;

    return 0; 
}
```

Output:

```text
stk[0]: 4
stk[1]: 1
stk[1]: 0
stk[0]: 0
```

## Enumerated types

Code:

```cpp
/*
We equip our code with the ability to output the weekday type values in a human readable form. We’ll do this by overloading the << stream operator.
In general, enum type values are ints and may be used as arguments in any operations accepting ints. Internally they’re stored just like ints too. E.g., the following line:
    cout << SUNDAY << endl;
will emit a line containing ‘0’ (the zero digit), not the word “SUNDAY”. Luckily, we can change it with the help of a little operator overloading.
*/

#include <iostream>
using namespace std;

/* 
Enumerated type:
    * the enum keyword begins the declaration of the type
    * ‘weekday’ is the name of the new type being created; the name of the type must obey the rules regarding names in general
    * next goes a list of all of the values creating the new type, separated by commas and enclosed in curly brackets
    * the compiler will implicitly assign the value of 0 to the first element of the list
    * any symbol except the first one will be assigned a value greater by one than the previous element in the list
This means that the SUNDAY symbol is assigned the value of 0, MONDAY – 1, TUESDAY – 2, etc.
*/
enum weekday { SUN, MON, TUE, WED, THU, FRI, SAT };

/* 
In general, any enum type value is implicitly promoted to the int type when used in a context requiring integral values e.g. when used in conjunction with operators like +, -, etc.
When the enumerated type plays the role of an l-value, the situation changes. Assigning an int value to it (e.g. like this: weekday day = 0;) will provoke a compilation warning 
as the compiler recognizes these assignments as a potential risk to data integrity.
You may have to modify the assignment in the following way:
    weekday day = static_cast<weekday>(0);
Adding an int to a weekday will take into account the cyclical nature of days and weeks, e.g. SUNDAY + 15 will result in MONDAY.
*/
weekday operator+(weekday day, int days) 
{
    return static_cast<weekday>((static_cast<int>(day) + days) % 7);
}

ostream& operator<< (ostream &strm, weekday day)
{
    switch(day) {
        case SUN: strm << "SUNDAY";                                 break;
        case MON: strm << "MONDAY";                                 break;
        case TUE: strm << "TUESDAY";                                break;
        case WED: strm << "WEDNESDAY";                              break;
        case THU: strm << "THURSDAY";                               break;
        case FRI: strm << "FRIDAY";                                 break;
        case SAT: strm << "SATURDAY";                               break;
        default:  strm << "Somewhere inside the depths of time..."; break;
    }

    return strm;
}

/* 
Using enum types may protect us from many threats, but some of them are still serious.
Take a look here:
    enum weekday { SUN, MON, TUE, WED, THU, FRI, SAT };
    int main()
    {
            weekday d = SAT;
            d = static_cast<weekday>(d + 1);
    }
The + operator is unaware of weekdays at all and may skip from SATURDAY to literally nowhere, leaving the permitted type domain.
We can avoid these problems by overloading the + operator.
*/
int main()
{
    weekday d = SAT;

    d = d + 16;
    cout << "SAT + 16 days = " << d << endl;

    return 0;
}
```

Output:

```text
SAT + 16 days = MONDAY
```

## Arithmetic operators

Code:

```cpp
/*
"Operators"	                                "+ - * / %"
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    Depending on context

All of the above operators are binary.
The code illustrates a simple implementation of a class storing 2-element vectors and can add them as well as find their dot product.
The first function returns a vector, while the second returns a scalar. The first of the functions is a member function, and the second is global.
*/

#include <iostream>
#include <vector>
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

    // The first of the newly defined operators may be chained.
    v3 = v1 + v2;
    x = v1 * v2;
    cout << "(" << v1.vec[0] << ", " << v1.vec[1] << ") + " << "(" << v2.vec[0] << ", " << v2.vec[1] << ") = " << "(" << v3.vec[0] << ", " << v3.vec[1] << ")" << endl;
    cout << "(" << v1.vec[0] << ", " << v1.vec[1] << ") * " << "(" << v2.vec[0] << ", " << v2.vec[1] << ") = " << x << endl;

    return 0;
}
```

Output:

```text
(0, 1) + (1, 0) = (1, 1)
(0, 1) * (1, 0) = 0
```

## Bitwise operators

Code:

```cpp
/*
"Operators"	                                "^ | & ~ << >>"
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    Depending on context

All of the above operators, except the ~ are binary.
Resist the temptation to overload the ^ operator for an exponentiation, like in FORTRAN or Python programming languages and in some spreadsheets.
The real exponentiation has a very high priority (higher than the * operator), while the ^ has a priority lower than other arithmetic operators. 
It may bring along some unexpected and undesired side effects.
*/

#include <iostream>
#include <vector>
using namespace std;

// The V class is able to bitwise right shift each of its elements and to evaluate their product (it’s a rather unusual use of the ~ operator).
class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        V operator>>(int arg)
        {
            V res(vec[0], vec[1]);

            for(int i = 0; i < 2; i++)
                res.vec[i] >>= arg;
            return res;
        }
};

int operator~(V &arg) 
{
    int res = 1;

    for(int i = 0; i < 2; i++)
        res *= arg.vec[i];
    return res;
}

int main()
{
    V v(15, 7);

    v = v >> 1;
    cout << ">>(17, 7) = " << "(" << v.vec[0] << ", " << v.vec[1] << ")" << endl;
    cout << "7 * 3 = " << ~v << endl;

    return 0;
}
```

Output:

```text
>>(17, 7) = (7, 3)
7 * 3 = 21
```

## Assignment operator

Code:

```cpp
/*
"Operators"                                 "="
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The default behaviour of the = operators is rather simple when applied to objects: it just copies the object’s content field by field, making a carbon copy of the source object.
t may be dangerous if the copied object contains pointers to dynamically allocated data, because two or more different objects may make use of implicitly shared data. 
It may be useful when done intentionally, but it may also be critical when done by mistake.
Overloading the = operator may protect the object from problems of this nature and may also add some, maybe somewhat tricky, functionalities to simple assignments.
The code shows an assignment which swaps the vector being assigned.
*/

#include <iostream>
#include <vector>
using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        V& operator=(V &arg)
        {
            for(int i = 0; i < 2; i++)
                vec[i] = arg.vec[1 - i];
            return *this;
        }
};

int main()
{
    V v1(4, 8), v2;
    v2 = v1;

    cout << "swap(4, 8) = " << "(" << v2.vec[0] << ", " << v2.vec[1] << ")" << endl;

    return 0;
}
```

Output:

```text
swap(4, 8) = (8, 4)
```

## Relational operators

Code:

```cpp
/*
"Operators"	                                "== != > >= < <="
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    boolean

All of the above operators are binary and all of them return a Boolean value representing the truthfulness of the condition being evaluated (checked).
overloading one of the operators has absolutely no impact on the others, e.g. redefining the meaning of the == operator doesn’t implicitly 
redefine the != operator, and vice versa. Overloading the < operator will automatically overload neither the > nor the >= operators.
The code shows the behaviour of two new operators: the first one returns true when both vectors contain the same values in the same order, while the second 
is a little tricky: it checks the “greater than” relation using the total sum of the vector elements.
*/

#include <iostream>
#include <vector>
using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        bool operator==(V &arg)
        {
            for(int i = 0; i < 2; i++)
                if(vec[i] != arg.vec[i])
                    return false;
            return true;
        }
};

bool operator>(V &l, V &r)
{
    return l.vec[0] + l.vec[1] > r.vec[0] + r.vec[1];
}

int main()
{
    V v1(4, 8), v2(3, 7);

    cout << "(4, 8) == (3, 7): " << (v1 == v2 ? "true" : "false") << endl;
    cout << "4 + 8 > 3 + 7: " << (v1 > v2 ? "true" : "false") << endl;

    return 0;
}
```

Output:

```text
(4, 8) == (3, 7): false
4 + 8 > 3 + 7: true
```

## Relational operators

Code:

```cpp
/*
"Operators"	                                "! && ||"
May be implemented as a global function?	YES
May be implemented as a member function?	YES
Type of return value	                    boolean

All of the above operators (except !) - are binary and return a Boolean value evaluated in the sense of the Bool’s algebra.
The original (not overloaded) binary operators use a short-circuit evaluation tactic which means that they try to omit an evaluation of the right argument 
if the left argument is sufficient to determine the final result.
    When the left argument of || is true, the whole expression is also true, regardless of the right argument value.
    When the left argument of && is false, the whole expression is also false, regardless of the right argument value.
It doesn’t matter whether the arguments are variables or simple relations, but it does matter when they’re function invocations.
Let’s assume that we’ve got two functions, f1() and f2(), both returning bool. In the following expression:
    f1() && f2()
the f2() function will be invoked or not depending on the f1() result.
As the overloaded logical function can’t make such a distinction, both of the above functions will be invoked when used together in the same expression.
The code defines the && operator to check the following, verbally defined, condition:
    Left and right vectors have at least one non-zero element.
The second of the operators returns a value reflecting the condition:
    All vector elements are non-zero.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        bool operator&&(V &arg)
        {
            return abs(vec[0]) + abs(vec[1]) > 0 && 
                    abs(arg.vec[0]) + abs(arg.vec[1]) > 0;
        }
};

bool operator!(V &v)
{
    return v.vec[0] * v.vec[1] != 0;
}

int main()
{
    V v1(4, 8), v2(3, 7);

    cout << "Left and right vectors have at least one non-zero element: " << (v1 && v2 ? "true" : "false") << endl;
    cout << "All vector elements are non-zero: " << (!v1 ? "true" : "false") << endl;

    return 0;
}
```

Output:

```text
Left and right vectors have at least one non-zero element: true
All vector elements are non-zero: true
```

## Compound assignment operators

Code:

```cpp
/*
"Operators"	                                "+= -= *= %= /= &= |= ^= >>= <<="
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

None of the above operators is implicitly derived from its regular counterpart and vice versa. Overloading the + operator doesn’t produce the += operator and so on. 
The implementation of both components of such a pair should be compatible (i.e. X += Y should be evaluated in the same way and result in the same value as X = X + Y), 
but there’s no automation in it.
All the operator functions from this category have one argument and directly modify their home object. The function should return a reference to the modified object to allow chaining.
The code defines both + and += operators.
*/

#include <iostream>
#include <vector>
using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0); 
            vec.push_back(a1);
        }

        V& operator+=(V &arg)
        {
            for(int i = 0; i < 2; i++)
                vec[i] += arg.vec[i];
            return *this;
        }
};

V& operator+(V &left, V &right)
{
    V *res = new V(0, 0);

    for(int i = 0; i < 2; i++)
        res->vec[i] = left.vec[i] + right.vec[i];
    return *res;
}

int main()
{
    V v1(0, 0), v2(1, 2), v3(3, 4);

    v1 = v2 + v3;
    v1 += v1;
    cout << "(4, 6) + (4, 6) = " << "(" << v1.vec[0] << ", " << v1.vec[1] << ")" << endl;

    return 0;
}
```

Output:

```text
(4, 6) + (4, 6) = (8, 12)
```

## Prefix increment and decrement operators

Code:

```cpp
/*
"Operators"	                                "++ --"
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The prefix form of the ++/-- has to be implemented as a parameter-less operator function and (as it modifies its argument before it’s used) it should return a reference to the modified object.
We’re responsible for ensuring that the prefix and suffix operators leave their arguments in the same state and that both are coherent with +=1 and -=1. 
The compiler isn’t shrewd enough to do it for us.
the code shows us an overloaded prefix ++ which affects all vector elements. 
*/

#include <iostream>
#include <vector>
using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        V& operator++()
        {
            for(int i = 0; i < 2; i++)
                vec[i]++;
            return *this;
        }
};

int main()
{
    V v1(1, 2);

    ++v1;
    cout << "++(1, 2) = " << "(" << v1.vec[0] << ", " << v1.vec[1] << ")" << endl;

    return 0;
}
```

Output:

```text
++(1, 2) = (2, 3)
```

## Postfix increment and decrement operators

Code:

```cpp
/*
"Operators"	                                "++ --"
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The postfix form of the ++/-- has to be implemented as a one-parameter operator function (sic! note that the parameter of type int is a complete dummy and we mustn’t use it within the function) 
and since it serves the object before it’s affected by the modification, it should return a copy of the unmodified object.
The presence of the dummy int parameter is the only trait that allows the compiler to distinguish between prefix and postfix overloaded operators.
*/

#include <iostream>
#include <vector>
using namespace std;

class V {
    public:
        vector<int> vec;

        V(int a0 = 0, int a1 = 0)
        { 
            vec.push_back(a0);
            vec.push_back(a1);
        }

        V operator++(int none)
        {
            V v(vec[0],vec[1]);

            for(int i = 0; i < 2; i++)
                ++vec[i];
            return v;
        }
};

int main()
{
    V v1(2, 3);

    v1++;
    cout << "(2, 3)++ = " << "(" << v1.vec[0] << ", " << v1.vec[1] << ")" << endl;

    return 0;
}
```

Output:

```text
(2, 3)++ = (3, 4)
```

## Subscript operator

Code:

```cpp
/*
"Operators"	                                "[]"
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    A reference to an object or an l-value in general

The original form of the [] operator is very complex, in both syntax and semantic aspects.
Fundamentally, it requires two arguments, a pointer (because the name of an array is interpreted as a pointer to its first element) and an int value as an index. 
Moreover, the original form of the operator is commutative, i.e. in the following declaration:
    int arr[10];
both of these assignments are valid:
    arr[0] = 0;
    1[arr] = 1;
The overloaded index operator differs a bit from its regular ancestor. It may accept indexes when they’re not integers – virtually all data types (including classes) 
can be used as an index, allowing the programmer to implement complex search algorithms.
E.g. we can hide database searches and updates under a mask of indexing. Furthermore, int indexes may be negative. The semantics of such indexing is fully defined by the programmer.
The overloaded index operator isn’t commutative any more.
The operator needs to find a reference to the data either directly or indirectly pointed to by the index value, and thus the operator will work properly at both sides of the assignment operator.
The operator has to be declared as one-parameter: only the index value comes from the outer world, because the object itself is treated as a second argument.
*/

#include <iostream>
using namespace std;

/* 
It’s a rather weird method of translating a number into the name of a variable. We can say that the Arr class is an array without an array. 
That pseudo-array accepts indexes starting from 1, not from 0 (this was a standard convention in the very first programming languages).
*/
class Arr {
    private:
        int a, b, c, d;

    public:
        Arr()
        { 
            a = b = c = d = 0; 
        }

        int& operator[] (int index)
        {
            switch(index) {
                case 1: return a;
                case 2: return b;
                case 3: return c;
                case 4: return d;
                default: throw range_error("bad index");
            }
        }
};

int main()
{
    Arr arr;

    for(int i = 1; i <= 4; i++)
        arr[i] = i * i;

    for(int i = 4; i > 0; i--)
        cout << i << " * " << i << " = " << arr[i] << endl;

    return 0;
}
```

Output:

```text
4 * 4 = 16
3 * 3 = 9
2 * 2 = 4
1 * 1 = 1
```

## Function invocation operator

Code:

```cpp
/*
"Operators"	                                "()"
May be implemented as a global function?	NO
May be implemented as a member function?	YES
Type of return value	                    any

The function invocation operator is very different. Here are some of its characteristics:
    * the number of its parameters isn’t predefined; you can use as many parameters as you want
    * the return type is neither predefined nor suggested; use the one you need
    * one class may contain more than one overloaded operator () function; specify as many as you need, but remember to keep them all distinguishable by the number and 
    types of parameters (relate it to the requirements for overloaded functions)
The operator may be used to create objects that pretend to be functions (they can be used to do more advanced things).
The code shows this type of imitating class. It overloads the () operator twice to create a guise for two overloaded functions, finding a maximal of their arguments.
*/

#include <iostream>
using namespace std;

class Fun {
    public:
        int operator() (int a1, int a2)
        {
            return a1 > a2 ? a1 : a2;
        }

        int operator() (int a1, int a2, int a3)
        {
            return a1 > a2 ? (a1 > a3 ? a1 : a3) : (a2 > a3 ? a2 : a3);
        }
};

int main()
{
    Fun f;

    cout << "max(1, 2) = " << f(1, 2) << endl;
    cout << "max(1, 2, 3) = " << f(1, 2, 3) << endl;

    return 0;
}
```

Output:

```text
max(1, 2) = 2
max(1, 2, 3) = 3
```

## Pointer operators

Code:

```cpp
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

 
    return 0;
}
```

Output:

```text
'charlie' -> 2
```

## Main function

Code:

```h
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
```

```cpp
// The code shows our Fraction class in action.

#include "fraction.h"
#include <iostream>
using namespace std;

int main()
{
    Fraction f1(1,2), f2(2,3), f;

    cout << f1 << " -> " << f1.get_double() << endl;
    cout << f2 << " -> " << f2.get_double() << endl;

    f = f1 + f2;
    cout << f1 << " + " << f2 << " = " << f << endl;

    f = f2 + f2 + f2;
    cout << f2 << " + " << f2 << " + " << f2 << " = " << f << endl; 

    f = !f;
    cout << f2 << " + " << f2 << " + " << f2 << " = " << f << endl;

    f = f1 * f2;
    cout << f1 << " * " << f2 << " = " << f << endl;

    f = f1 / f2;
    cout << f1 << " / " << f2 << " = " << f << endl;

    Fraction f3(7,8);
    f3 += f1;
    cout << f3 << endl;

    return 0;
}
```

Output:

```text
[1/2] -> 0.5
[2/3] -> 0.666667
[1/2] + [2/3] = [7/6]
[2/3] + [2/3] + [2/3] = [6/3]
[2/3] + [2/3] + [2/3] = [2/1]
[1/2] * [2/3] = [1/3]
[1/2] / [2/3] = [3/4]
[11/8]
```