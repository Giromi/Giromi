#include <iostream>

template <typename T>
struct Struct {
    T value;
    Struct(T v) : value(v) {}
};


int main() {
    Struct<int> foo(42);
    Struct<int> bar(100);
    Struct<int> baz(7);

    std::cout << "Foo: " << foo.value << ", Bar: " << bar.value << ", Baz: " << baz.value << std::endl;
    return 0;
}
