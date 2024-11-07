


#include <iostream>
// make slice problem
class Base {
public:
    Base(void) : name("Base") { 
        std::cout << "Base constructor" << std::endl;
    };
    Base(const std::string& newName) : name(newName) { };
    // virtual ~Base(void) {
    ~Base() { 
        std::cout << "Base destructor" << std::endl;
    };
    virtual void print() const {
        std::cout << "Base" << std::endl;
    }
private:
    std::string name;
};

class Derived : public Base {
public:
    Derived(int newType) : Base("Derived"), type(newType) { 
        std::cout << "Derived constructor" << std::endl;
    };
    virtual ~Derived(void) { 
        std::cout << "Derived destructor" << std::endl;
        std::cout << "type: " << type << std::endl;
    };

    virtual void print(void) const {
        std::cout << "Derived" << std::endl;
        std::cout << "type: " << type << std::endl;
    }
private:
    int type;
};

int main(void) {
    Derived d = Base("Base");
}
