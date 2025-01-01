#include <iostream>

#define CREATE_STRUCT(name) \
struct name { \
    int value; \
    name(int v) : value(v) {} \
};

CREATE_STRUCT(Foo)
CREATE_STRUCT(Bar)
CREATE_STRUCT(Baz)

int main() {
    Foo foo(42);
    Bar bar(100);
    Baz baz(7);

    std::cout << "Foo: " << foo.value << ", Bar: " << bar.value << ", Baz: " << baz.value << std::endl;
    return 0;
}
/*
 * 문제점
 *  1.	타입 안전성 부족: 텍스트 치환이라 구문 오류가 발생하기 쉽습니다.
 *	2.	확장성 부족: 매크로의 유연성이 Rust에 비해 부족합니다.
 *  3.	디버깅 어려움: 매크로는 단순 치환이므로 디버깅이 어렵습니다.
 */

