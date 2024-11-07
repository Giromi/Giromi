#include <iostream>

int main(void) {
    try {

        throw 1;
        std::cout << "no int catch" << std::endl;
    }
    catch (float e) {
        std::cout << "Exception: " << e << std::endl;
    }

    std::cout << "finish" << std::endl;

    return 0;
}
