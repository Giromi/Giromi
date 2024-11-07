#include "SavingAccount.hpp"

SavingAccount::SavingAccount(int dollars, int cents, double rate)
    : BankAccount(dollars, cents, rate) { }

void SavingAccount::deposit(int dollars, int cents) {
    double balance = getBalance();
    balance += dollars;
    balance += (static_cast<double>(cents) / 100);
    int newDollars = static_cast<int>(balance);
    // int newDollars = static_cast<int>(std::round(balance));
    int newCents = static_cast<int>((balance - newDollars) * 100);
    // int newCents = static_cast<int>(std::round((balance - newDollars) * 100));
    set(newDollars, newCents, getRate());
}

void SavingAccount::withdraw(int dollars, int cents) {
    double balance = getBalance();
    balance -= dollars;
    balance -= (static_cast<double>(cents) / 100);  
    int newDollars = static_cast<int>(balance); // Compile  time casting
    // int newDollars = (balance);              // Run      time casting
    int newCents = static_cast<int>((balance - newDollars) * 100);
    // int newCents = ((balance - newDollars) * 100);
    set(newDollars, newCents, getRate());
}
