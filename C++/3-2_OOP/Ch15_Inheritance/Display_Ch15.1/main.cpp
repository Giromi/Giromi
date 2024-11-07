#include <iostream>
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"


int main(void) {
    employeesavitch::HourlyEmployee H;      // 이거 빼먹으면 안됨
    employeesavitch::SalariedEmployee S;

    std::cout << H.getName() << std::endl;
    std::cout << S.getName() << std::endl;

    H.printCheck();
    S.printCheck();

    return 0;
}
