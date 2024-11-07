
#include <iostream>
#include <string>
#include <cstdlib>
#include "Employee.hpp"

namespace employeesavitch {
    Employee::Employee()
        : name("No name yet"), ssn("No number yet"), net_pay(0) { }

    Employee::Employee(std::string theName, std::string theSSN)
        : name(theName), ssn(theSSN), net_pay(0) { }

    std::string Employee::getName() const { return name; }

    std::string Employee::getSSN() const { return ssn; }

    double Employee::getNetPay() const { return net_pay; }

    void Employee::setName(std::string new_name) { name = new_name; }

    void Employee::setSSN(std::string new_ssn) { ssn = new_ssn; }

    void Employee::setNetPay(double new_net_pay) { net_pay = new_net_pay; }

    void Employee::printCheck() const {
        std::cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
                  << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
                  << "Check with the author of the program about this bug.\n";
        exit(1);
    }

}
