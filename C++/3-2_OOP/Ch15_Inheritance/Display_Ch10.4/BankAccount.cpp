#include "BankAccount.hpp"

BankAccount::BankAccount(int dollars, int cents, double rate) {
    if ((dollars < 0) || (cents < 0) || (rate < 0)) {
        std::cout << "Illegal values for money or interest rate." << std::endl;
        exit(1);
    }
    dollarsPart = dollars;
    centsPart = cents;
    interestRate = rate;
}

BankAccount::BankAccount(int dollars, double rate) {
    if ((dollars < 0) || (rate < 0)) {
        std::cout << "Illegal values for money or interest rate." << std::endl;
        exit(1);
    }
    dollarsPart = dollars;
    centsPart = 0;
    interestRate = rate;
}

void BankAccount::set(int dollars, int cents, double rate) {
    if (dollars < 0 || cents < 0 || rate < 0) {
        std::cout << "Illegal values for money or interest rate." << std::endl;
        exit(1);
    }
    dollarsPart = dollars;
    centsPart = cents;
    interestRate = rate;
}

void BankAccount::output(std::ostream& outs) {
    outs.setf(std::ios::fixed);
    outs.setf(std::ios::showpoint);
    outs.precision(2);
    outs << "Account balance $" << getBalance() << std::endl;
    outs << "Interest rate " << getRate() << "%"<< std::endl;
}

double BankAccount::getBalance(void) { 
    return (dollarsPart + (static_cast<double>(centsPart) * 0.01)); 
}

double BankAccount::getRate(void) { 
    return interestRate; 
}
