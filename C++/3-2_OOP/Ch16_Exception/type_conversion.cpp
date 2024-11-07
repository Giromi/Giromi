
//DISPLAY 16.5 Throwing an Exception Inside a Function
#include <iostream>
#include <cstdlib>
using namespace std;

void functionC() throw (int, double) {
    throw 5.5;  
}

void functionA() throw (int) {
    throw 5.5;  
}


int main() {
    try {
        cout << "In main: Calling functionC." << endl;
        // functionC();
        // cout << "In main: functionC completed normally." << endl;
 
        functionA();
        cout << "In main: functionA completed normally." << endl;
    } catch (int x) {
        cout << "In main: The exception was " << x << endl;
    } catch (double x) {
        cout << "In main: The exception was " << x << endl;
    }
    cout << "End of program.\n";
    return 0;
}



