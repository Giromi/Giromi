

#include <vector>
#include <iostream>
#include <cstdio>

int main(void) {

    std::vector<int> v(0);


    std::vector<const int>::const_iterator it1 = v.begin();
    std::vector<const int>::const_iterator it2 = v.end();

    if (it1 == it2) {
        std::cout << "Same" << std::endl;
    } else {
        std::cout << "Different" << std::endl;
    }
    std::cout << &it1 << std::endl;
    std::cout << &it2 << std::endl;
    --it2;
    std::cout << *it2 << std::endl;

    // *it2 = 10;
    //
    


    return 0;
}
