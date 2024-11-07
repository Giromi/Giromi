#include <iostream>
#include <stdexcept>

class BaseException {
public:
    virtual const char* what() const noexcept {
        return "Base Exception";
    }
};

class DerivedException : public BaseException {
public:
    // DerivedException에서 BaseException을 상속하므로, what() 메서드를 재정의하지 않아도 됨
};

void handleException(const BaseException& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
}

/* 상속 관계에서는 예외 명시에 상위 클래스를 사용해도 하위 클래스의 예외를 잡을 수 있음 */
// void testThrow(const DerivedException& dException) throw(DerivedException) {
// }

int main() {
    try {
        // DerivedException 객체를 던짐
        BaseException dException;
        throw dException;
        // which can be writtne as 'throw DerivedException();'-> 임시객체 생성후 예외로 던짐
    } catch (const BaseException) {
        // BaseException을 예외 명시에 사용하고, 실제로는 DerivedException이 던져졌으나
        // BaseException으로 선언된 catch 블록에서도 잡힘
        // handleException(e);
        std::cerr << "BaseException exception" << std::endl;
    }
    return 0;
}
