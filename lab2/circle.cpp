#include "Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle() : Circle(1) {}

Circle::Circle(double radius)
    : radius(radius) {
}

Circle::~Circle() {
    std::cout << "Circle destroyed\n";
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::display() const {
    std::cout << "Circle radius: " << radius
        << ", Area: " << area()
        << ", Perimeter: " << perimeter()
        << std::endl;
}