#include <string>
#include <iostream>
#include "HourlyEmployee.hpp"

namespace employeesavitch {
    HourlyEmployee::HourlyEmployee(void)
        : Employee(), wageRate(0), hours(0) { }

    HourlyEmployee::HourlyEmployee(std::string theName, std::string theSSN, 
                                            double theWageRate, double theHours)
        : Employee(theName, theSSN), wageRate(theWageRate), hours(theHours) { }

    void HourlyEmployee::setRate(double newWageRate) { wageRate = newWageRate; }
    void HourlyEmployee::setHours(double hoursWorked) { hours = hoursWorked; }
    double HourlyEmployee::getRate(void) const { return wageRate; }
    double HourlyEmployee::getHours(void) const { return hours; }

    void HourlyEmployee::printCheck(void) {
        setNetPay(hours * wageRate);
        std::cout << "\n________________________________________________\n";
        std::cout << "Pay to the order of " << getName() << std::endl;
        std::cout << "The sum of " << getNetPay() << " Dollars\n";
        std::cout << "________________________________________________\n";
        std::cout << "Check Stub: NOT NEGOTIABLE\n";
        std::cout << "Employee Number: " << getSSN() << std::endl;
        std::cout << "Hourly Employee. \nHours worked: " << hours << " Rate: " << wageRate << " Pay: " << getNetPay() << std::endl;
        std::cout << "_________________________________________________\n";
    }
}
