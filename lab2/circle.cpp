#include "circle.h"
using namespace std;

Circle::Circle()
    : Shape("Circle"), radius(1), center(0, 0) {
}

Circle::Circle(double radius, Point center)
    : Shape("Circle"), radius(radius), center(center) {
}

Circle::Circle(const Circle& other)
    : Shape(other), radius(other.radius), center(other.center) {
}

Circle::Circle(Circle&& other) noexcept
    : Shape(move(other)), radius(other.radius), center(move(other.center)) {
    other.radius = 0;
}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        Shape::operator=(other);
        radius = other.radius;
        center = other.center;
    }
    return *this;
}

Circle::~Circle() {
    cout << "Circle destroyed" << endl;
}

double Circle::area() const {
    return 3.14159 * radius * radius;
}

double Circle::perimeter() const {
    return 2 * 3.14159 * radius;
}

void Circle::display() const {
    Shape::display();
    cout << "radius: " << radius << endl;
    cout << "center: ";
    center.display();
    cout << endl;
    cout << "area: " << area() << endl;
    cout << "perimeter: " << perimeter() << endl;
}

int Circle::getCount() {
    return Shape::getCount();
}