//DISPLAY 2.16 Charge Card Program
#include <iostream>
#include <iomanip>

using namespace std;
int main( )
{
    double balance = 50.00;
    int count = 0;

    cout << "This program tells you how long it takes\n"
         << "to accumulate a debt of $100, starting with\n"
         << "an initial balance of $50 owed.\n"
         << "The interest rate is 2% per month.\n";
    // Write your code here using while-loop 
    while (balance < 100) {
        balance *= 1.02;
        cout << balance << endl;
        ++count;
    }
    

    cout << "After " << count << " months,\n";
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(2);
    cout << "your balance due will be $" << balance << endl;
    cout << "your balance due will be $" << fixed << setprecision(2) << balance << endl;

    return 0;
}
