
// show error undefined reference to Base virtual table

#include <iostream>

class Base {
public:
    virtual void f(void) {
        std::cout << "Base::f()" << std::endl;
    }
    virtual void g(void); // virtual compilation error
    // virtual void g(void) = 0;
    virtual void h(void) {
        std::cout << "Base::h()" << std::endl;
    }
};

class Derived : public Base {
public:
    virtual void f(void) {
        std::cout << "Derived::f()" << std::endl;
    }
    virtual void g(void) {
        std::cout << "Derived::g()" << std::endl;
    }
    virtual void h(void) {
        std::cout << "Derived::h()" << std::endl;
    }
};

int main(void) {
    Derived d;

    Base *ptr = &d;
    ptr->f();
    ptr->g();
    ptr->h();

    return 0;
}
