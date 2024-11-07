
#include <iostream>
#include <vector>
using std::cout;

// using std::vector<int>::iterator;
//fix upper line




int main(void) {

    cout << "Hello, world!\n";

    std::vector<int> v = {1, 2, 3, 4, 5};

    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator it2 = it + 2;

    // std::vector<int>::iterator it2 = v[2];

}
