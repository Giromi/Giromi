
#include <iostream>

int main(void) {


    // static cast 안해도 되는 경우?
    int hello = 'A';
    std::cout << hello << std::endl;

    int num = 10000;
    std::cout << static_cast<char>(num) << std::endl;

    /* Error */
    char world = static_cast<int>(1000000);
    std::cout << world << std::endl;




    return 0;
}
