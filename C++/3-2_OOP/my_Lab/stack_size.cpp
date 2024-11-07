#include <iostream>

#include <stdlib.h>

int main(void) {


    char* ptr = (char *)malloc(sizeof(char) * 2147483649);
    char* big = (char *)malloc(sizeof(char) * 9223372036854775807);
    ptr[2147483646] = 'a';
    ptr[2147483647] = 'b';
    ptr[2147483648] = 'c';
    std::cout << ptr[2147483646] << std::endl;
    std::cout << ptr[2147483647] << std::endl;
    std::cout << ptr[2147483648] << std::endl;
    std::cout << sizeof(size_t) << std::endl;

    for (int i = 0; i < 2147483649; ++i) {
        ptr[i] = 'a';
    }

    for (size_t i = 0; i < 9223372036854775807; ++i) {
        big[i] = 'a';
    }



    // std::cout << (unsigned long long)18446744073709551615 << 
    return 0;
}
