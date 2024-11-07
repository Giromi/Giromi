
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
    Base b = Derived(0);         // 선언과 동시에 어떻게 만들고 싶은데...(slice problem)
    // slice problem => 소멸자를 부름                                
   
    Derived d = Derived(1);
    Base* bp = new Derived(2);   // 동적할당을 해야되는구나 
    Derived* dp = new Derived(3);   // 동적할당을 해야되는구나 
    Base& br = d;               // 아니면 참조로 하던가
                                // => Extend type capatibility(미리 사이즈 만들기)

    b.print();
    br.print();
    bp->print();
    std::cout << std::endl;
    std::cout << std::endl;

    delete bp;
    delete dp;

    return 0;
}

