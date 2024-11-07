//DISPLAY 3.5 Multiway if-else Statement
//Program to compute state income tax.
#include <iostream>
using namespace std;


//This program outputs the amount of state income tax due computed
//as follows: 
// no tax on income up to $15,000; 
// 5% on income betwee $15,001 and $25,000;
// 10% on income over $25,000.

int main( )
{
    int netIncome;
    double taxBill;

    // (1) Print "Enter net income (rounded to whole dollars) $" and receive netIncome as input.
    // Write code here
    std::cout << "Enter net income (rounded to while dollars) $";
    std::cin >> netIncome;

    // (2) Write a program that can calculate state income tax due using an if-else statement.
    // Write code here 
    const int originalNetIncome = netIncome;
    const int tenPercentTaxStandard = 25000;
    const int fivePercentTaxStandard = 15000;
 	
    taxBill = 0;
    if (netIncome > tenPercentTaxStandard) {
        taxBill += (netIncome - tenPercentTaxStandard) * 0.1;
        netIncome = tenPercentTaxStandard;
    }
    taxBill += (netIncome > fivePercentTaxStandard) * (netIncome - fivePercentTaxStandard) * 0.05;

    // (3) Write code to print all results to two decimal places.
    // Write code here
    std::cout.setf(ios::fixed);
    std::cout.setf(ios::showpoint);
    std::cout.precision(2);

    // (4) Print the netIncome received as input and the calculated taxBill as the result.
    // Write code here
    std::cout << "Net income = $" << static_cast<double>(originalNetIncome) << std::endl;
    std::cout << "Tax bill = $" << taxBill << std::endl;

    return 0;
}
