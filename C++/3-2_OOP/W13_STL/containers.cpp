#include <iostream>

template <typename T>
void containerTest(T& c) {

    c.push_back(1);
    c.push_back(2);


    std::cout << c.size() << std::endl;
    c.~vector();                        // 모든 원소를 제거하고 메모리 해제
                 
    c.push_back(3);

    std::cout << c.size() << std::endl;


    if (c.empty()) {
        std::cout << "c is empty" << std::endl;
    } else {
        std::cout << "c is not empty" << std::endl;
    }


    if (c.size()) {
        std::cout << "c has a size" << std::endl;
    } else {
        std::cout << "c doesn't have a size" << std::endl;
    }




}

int main(void) {

    
    std::vector<int> v;

    vectorTest(v);
    return 0;
}
