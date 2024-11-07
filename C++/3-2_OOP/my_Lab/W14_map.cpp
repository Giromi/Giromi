
#include <iostream>
#include <map>

int main(void) {
    std::map<std::string, std::string> m;

    m.insert(std::make_pair("1", "one"));
    m.insert(std::make_pair("2", "two"));

    std::cout << m.size() << std::endl;
    // m.~map();                        // 모든 원소를 제거하고 메모리 해제
                 
    m.insert(std::make_pair("3", "three"));
    m.insert(std::make_pair("4", "four"));

    std::map<std::string, std::string>::iterator cit = m.find("2");
    // if (cit != m.end()) {
    std::pair<const std::string, std::string>& pRef = *cit;
    // }

    std::cout << m["5"] << std::endl;                      // m.insert(std::make_pair("five", 5)); 와 동일

    m.insert(std::make_pair("6", "six"));
    std::cout << m.size() << std::endl;

    std::cout << "cit->first : " << cit->first << std::endl;
    std::cout << "pRef.first : " << pRef.first << std::endl;

    m.erase(m.begin()->first);

    std::cout << "cit->first : " << cit->first << std::endl;
    std::cout << "pRef.first : " << pRef.first << std::endl;
    


    return 0;

}
