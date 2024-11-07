#ifndef HOURLYEMPLOYEE_HPP
#define HOURLYEMPLOYEE_HPP

#include "Employee.hpp"

namespace employeesavitch {
    class HourlyEmployee : public Employee {
    public:
        HourlyEmployee(void);
        HourlyEmployee(std::string theName, std::string theSSN, double theWageRate, double theHours);
        void    setRate(double newWageRate);
        double  getRate(void) const;
        void    setHours(double hoursWorked);
        double  getHours(void) const;
        void    printCheck(void);
    private:
        double  wageRate;
        double  hours;
    };
}

#endif
