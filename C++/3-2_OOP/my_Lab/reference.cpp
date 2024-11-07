#include<iostream>
template <typename T>
void print(T* x, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
}
//
// //
template <typename T>
void fillZero(T x[], size_t size) {
    std::cout << "Array" << std::endl;
    for (size_t i = 0; i < size; ++i) {
        x[i] = 0;
    }
}

template <typename T>
void fillZero(T& x, size_t size) {
    std::cout << "Reference" << std::endl;
    // for (size_t i = 1; i < size; ++i) {
    //     x[i] = 0;
    // }
 
    // 배열에 접근하지 않는 코드면 가독서에 문제가 생김.
    std::cout << x << std::endl;
}
/* redefine error */

// template <typename T>
// void fillZero(T* x, size_t size) { 
//     for (size_t i = 0; i < size; ++i)
//         std::cout << x[i] << " ";
//     std::cout << std::endl;
// }
//

int main(void) {
    std::cout << "< Int > " << std::endl;
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 9, 8, 0 };
    int* aPtr = a;          // 8 bytes
    print(a, 10); fillZero(a, 10); print(a, 10);

    std::cout << std::endl;

    std::cout << "< Float > " << std::endl;
    float b[] = { 1.2, 2.4, 3.6, 4.8, 5.0, 6.2, 7.4, 9.6, 8.8, 0.0 };
    float (&bRef)[10] = b;  // 0 bytes 사실상 
    print(bRef, 10); fillZero(bRef, 10); print(bRef, 10);

    int x = 3;
    fillZero(x, 10);

    return 0;
}
