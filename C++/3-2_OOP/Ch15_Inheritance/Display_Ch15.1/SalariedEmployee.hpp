
#ifndef SALARIEDEMPLOYEE_HPP
#define SALARIEDEMPLOYEE_HPP

#include "Employee.hpp"

namespace employeesavitch {
    class SalariedEmployee : public Employee {
    public:
        SalariedEmployee(void);
        SalariedEmployee(std::string theName, std::string theSSN, double theWeeklySalary);
        void    setSalary(double newSalary);
        double  getSalary(void) const;
        void    printCheck(void);
    private:
        double  salary; // weekly
    };
}

#endif
