#pragma once

#include "BankAccount.hpp"

class SavingAccount : public BankAccount {
public:
    SavingAccount(int dollars, int cents, double rate);

    void deposit(int dollars, int cents);

    void withdraw(int dollars, int cents);
private:
};
