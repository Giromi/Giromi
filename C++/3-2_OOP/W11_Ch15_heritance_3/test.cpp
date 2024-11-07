

#include <iostream>

// return type?
int sum(int a, int b) {
    int sum = a + b;
    return sum;
}

sumPrint(int a, int b) {
    std::cout << sum(a, b) << std::endl;
    return ;
}

int main(void) {

    int a;
    a = sum(1, 2); // int
    sumPrint(1, 2); // void

    return 0;

}
