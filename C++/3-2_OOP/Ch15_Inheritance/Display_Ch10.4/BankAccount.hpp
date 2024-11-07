#pragma once

#include <iostream>

class BankAccount {
public:
    BankAccount(int dollars, int cents, double rate);
    BankAccount(int dollars, double rate);
    BankAccount(void);

    void set(int dollars, int cents, double rate);
    void set(int dollars, double rate);
    void update(void);

    double  getBalance(void);
    double  getRate(void);
    void    output(std::ostream& outs);
private:
    int     dollarsPart;
    int     centsPart;
    double  interestRate;
};

