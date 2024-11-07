#include <iostream>
#include <cmath>
#include "SavingAccount.hpp"

int main(void) {
    SavingAccount account(100, 50, 5.5);
    account.output(std::cout);
    // std::cout << std::endl;
    std::cout << "Depositing $10.25." << std::endl;
    account.deposit(10, 25);
    account.output(std::cout); // 내부에서 설정
    // std::cout << std::endl;
    std::cout << "Withdrawing $11.80." << std::endl;
    account.withdraw(11, 80);
    account.output(std::cout);
    // std::cout << std::endl;
}

/*
 * c++ 10.4-9.cpp BankAccount.cpp SavingAccount.cpp -g
 */

