#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>

namespace employeesavitch {
    class Employee {
    public:
        Employee();
        Employee(std::string theName, std::string theSSN);
        std::string getName() const;
        std::string getSSN() const;
        double getNetPay() const;
        void setName(std::string new_name);
        void setSSN(std::string new_ssn);
        void setNetPay(double new_net_pay);
        void printCheck() const;
    private:
        std::string name;
        std::string ssn;
        double      net_pay;
    };
}

#endif
