
#include <iostream>

class Parent {
public:
    Parent(void) = default;
    ~Parent(void) {
        std::cout << "Parent destructor" << std::endl;
    };
};

class Child : public Parent {
public:
    Child(void) = default;
    ~Child(void) {
        std::cout << "Child destructor" << std::endl;
    };
};

int main(void) {
    Child c;
    Child *c2 = new Child();
    delete c2;
    return 0;
}
