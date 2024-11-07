#include <iostream>

class Shape {
public:
    virtual double area() {
        return 0.0;
    }

    virtual void printArea() {
        std::cout << "Area: " << area() << std::endl;
    }
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    double area() override { // override는 optional
        return 3.14159 * radius * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override {
        return width * height;
    }
private:
    double width;
    double height;
};


int main() {
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    shape1->printArea(); // Calls Circle's area function
    shape2->printArea(); // Calls Rectangle's area function

    delete shape1;
    delete shape2;

    return 0;
}
