//////////////////////
// Enumerated types //
//////////////////////

/*
We equip our code with the ability to output the weekday type values in a human readable form. We’ll do this by overloading the << stream operator.
In general, enum type values are ints and may be used as arguments in any operations accepting ints. Internally they’re stored just like ints too. E.g., the following line:
    cout << SUNDAY << endl;
will emit a line containing ‘0’ (the zero digit), not the word “SUNDAY”. Luckily, we can change it with the help of a little operator overloading.
*/

#include <iostream>
#include "../myFunctions.h"
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

    askOS();
    return 0;
}

/*
Output:

SAT + 16 days = MONDAY
*/