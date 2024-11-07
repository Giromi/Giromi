#include <string>
#include <iostream>
#include "SalariedEmployee.hpp"

namespace employeesavitch {
    SalariedEmployee::SalariedEmployee(void) : Employee(), salary(0) { }

    SalariedEmployee::SalariedEmployee(std::string theName, std::string theSSN, double theWeeklySalary)
        : Employee(theName, theSSN), salary(theWeeklySalary) { }

    void SalariedEmployee::setSalary(double newSalary) {
        salary = newSalary;
    }

    double SalariedEmployee::getSalary(void) const {
        return salary;
    }

    void SalariedEmployee::printCheck(void) {
        setNetPay(salary);
        std::cout << "\n__________________________________________________\n";
        std::cout << "Pay to the order of " << getName() << std::endl;
        std::cout << "The sum of " << getNetPay() << " Dollars\n";
        std::cout << "_________________________________________________\n";
        std::cout << "Check Stub NOT NEGOTIABLE \n";
        std::cout << "Employee Number: " << getSSN() << std::endl;
        std::cout << "Salaried Employee. Regular Pay: " << salary << std::endl;
        std::cout << "_________________________________________________\n";
    }
}
