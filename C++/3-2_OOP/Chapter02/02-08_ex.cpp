//DISPLAY 2.8 An if-else Statement
#include <iostream>
using namespace std;
int main( )
{
    int hours;
    double grossPay, grossPayOrigin, rate;

    cout << "Enter the hourly rate of pay: $";
    cin >> rate;
    cout << "Enter the number of hours worked,\n"
         << "rounded to a whole number of hours: ";
    cin >> hours;

    // Write your code here using if-else loop

    grossPay = rate * hours + (hours > 40) * rate * (hours - 40) * 1.5;
    if (hours > 40) {
        grossPayOrigin = rate * hours + rate * (hours - 40) * 1.5;
    } else {
        grossPayOrigin = rate * hours;
    }

    // Write your code to specify the output of type double (two decimal places should be shown)
    

    cout << "Hours = " << hours << endl;
    cout << "Hourly pay rate = $" << rate << endl;
    cout << "Gross pay = $" << grossPay << endl;

    cout  << grossPay << " == " << grossPayOrigin << endl;
    if (grossPay == grossPayOrigin) {
        cout << "grossPay == grossPayOrigin" << endl;
    } else {
        cout << "grossPay != grossPayOrigin" << endl;

    }

    return 0;
}
