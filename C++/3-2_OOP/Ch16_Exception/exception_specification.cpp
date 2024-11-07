//DISPLAY 16.5 Throwing an Exception Inside a Function
#include <iostream>
#include <cstdlib>
using namespace std;

class DivideByZero {};
class NegativeValue {};

double safeDivide(int top, int bottom) throw () {
    if (bottom == 0)
        throw NegativeValue();
        // throw DivideByZero();

    return top/static_cast<double>(bottom);
}

void functionC() throw (int) {
    throw 5.5;  
}

int main() {
    int numerator;
    int denominator;
    double quotient;
    cout << "Enter numerator:\n";
    cin >> numerator;
    cout << "Enter denominator:\n";
    cin >> denominator;

    try {
       quotient = safeDivide(numerator, denominator);
    } catch(DivideByZero) {
         cout << "Error: Division by zero!\n"
              << "Program aborting.\n";
         exit(0);
    } catch(NegativeValue) {
         cout << "Error: Negative value!\n"
              << "Program aborting.\n";
         exit(0);
    }

    cout << numerator << "/" << denominator
         << " = " << quotient << endl;

    cout << "End of program.\n";
    return 0;
}



