
#include <iostream>

int main(void) {
    try {

        throw (1. 3.3);
        std::cout << "no int catch" << std::endl;
    } catch (int a) {
        std::cout << "int catch" << a << std::endl;
    } catch (float) {
        std::cout << "float catch" << std::endl;
    } catch (...) {
        std::cout << "Exception: " << std::endl;
    } 


    std::cout << "finish" << std::endl;

    return 0;
}
