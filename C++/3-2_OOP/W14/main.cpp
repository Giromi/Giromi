

#include <iostream>
#include <vector>

// template <typename T>
// void print(T& t) {
//     for (int i = 0; i < 10; i++) {
//         std::cout << t[i] << std::endl;
//     }
// }
//

// 1. c++ overloading
// 2. template 설명 
// 3. generic programming

void setZero(int& a) {
    a = 0;
}

int main(void) { 
    int a = 3;

              
    setZero(a); 

    std::cout << a << std::endl;
    
    return 0;
}
