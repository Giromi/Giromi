#include <iostream>

class Car {
public:
    Car(const std::string& brand, const unsigned int speed) 
        : brand(brand), speed(speed) { }
    ~Car(void) { }

    /* 멤버 변수 변경되므로 const 빠져야 함 */
    void accelerate(const unsigned int increment) {
        this->speed += increment;
    }

    std::string details(void) const {
        return brand + " running at " + std::to_string(speed) + " km/h";
    }

private:
        std::string brand;
        unsigned int speed;
};


int main() {
    Car car("Tesla", 60);
    car.accelerate(40);
    std::cout << car.details() << std::endl;
    return 0;
}
