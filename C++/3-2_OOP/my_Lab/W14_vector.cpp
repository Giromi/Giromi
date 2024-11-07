#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::vector<std::string> v;

    v.push_back("one");
    v.push_back("two");

    std::cout << v.size() << std::endl;
    // v.~map();                        // 모든 원소를 제거하고 메모리 해제
                 
    v.push_back("three");
    v.push_back("four");


    std::vector<std::string>::iterator cit = find(v.begin(), v.end(), "two");
    std::string& vRef = *cit;
    // }

    std::cout << "size : " << v.size() << std::endl;
    std::cout << "cit->first : " << *cit << std::endl;
    std::cout << "pRef.first : " << vRef << std::endl;

    v.push_back("five");

    std::cout << std::endl;
    std::cout << "erase : " << *(v.begin()) << std::endl;
    std::cout << "size : " << v.size() << std::endl;

    v.erase(v.begin());
    std::cout << "cit->first : " << *cit << std::endl;
    std::cout << "pRef.first : " << vRef << std::endl;

    std::vector<std::string>::iterator cit2 = find(v.begin(), v.end(), "two");
    std::string& vRef2 = *cit2;

    std::cout << "cit->first : " << *cit2 << std::endl;
    std::cout << "pRef.first : " << vRef2 << std::endl;
    return 0;

}
