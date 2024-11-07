#include <iostream>
#include <cmath>

int main(void) {

    std::cout << static_cast<int>(3.14) << std::endl;
    std::cout << static_cast<int>(3.54) << std::endl;
    std::cout << static_cast<int>(3.74) << std::endl;
    // 무조건 버림

    std::cout << "====================" << std::endl;
    std::cout << static_cast<int>(std::round(3.14)) << std::endl;
    std::cout << static_cast<int>(std::round(3.54)) << std::endl;
    std::cout << static_cast<int>(std::round(3.74)) << std::endl;

}
