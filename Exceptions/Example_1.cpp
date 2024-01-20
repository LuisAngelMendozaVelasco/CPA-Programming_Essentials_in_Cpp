////////////////
// Exceptions //
////////////////

/*
If we’re determined to catch any of the flying exceptions, we need to put the catch statement directly after the try statement. There may be more than one catch statement.
Think of the catch statement as an unnamed function with one parameter specifying the desired kind of exceptions to be caught. 
The catch will catch only those exceptions that are compatible with the specified type.
If we write it this way:
    catch(string &anyproblem) { … }
it’ll mean: I want to catch the exceptions which carry strings.
This form:
    catch(exception &otherproblem) { … }
means: I’m going to catch the exceptions carrying objects of the exception class or of any other classes derived from the exception class.
If we want to throw an exception, we have to use the statement of the same name. The throw statement requires data that’ll be “packed” into an exception before its departure.
If we’re going to dispatch an int value, we’ll write something like this:
    throw 911;
If we want to throw an exception equipped with an object of any class, we need to specify the constructor to be invoked to prepare the data, like this:
    throw string("Bye world!");
*/

#include <iostream>
#include "../myFunctions.h"
using namespace std;

float div(float a, float b)
{
    // The function will provide a result if the arguments are valid, otherwise it’ll throw an exception containing a complaining string.
    if(b == 0.0)
        throw string("division by zero :(\n");
    return a / b;
}

int main()
{
    float a, b;

    // Notice how the division is tried and how the exception is caught.
    cout << "a: ";

    // On Windows, ctrl-Z tells the terminal application that you're at the end of your input. On Unix systems, it's ctrl-D.
    while(cin >> a) {
        try {
            cout << "b: ";
            cin >> b;
            cout << "a / b = " << div(a, b) << endl << endl;
        } 
        catch (string &problem) {
            cout << "Look what we did, we bad user!" << endl;
            cout << problem << endl;
        }

        cout << "a: ";
    }
    cout << "\nThe End" << endl;

    askOS();
    return 0;
}

/*
Output:

a: 1
b: 2
a / b = 0.5

a: 1
b: 0
a / b = Look what we did, we bad user!
division by zero :(

a: 
The End
*/