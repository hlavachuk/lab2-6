#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle() : Circle(1) {}

Circle::Circle(double radius)
    : radius(radius) {
}

Circle::~Circle() {
    cout << "Circle destroyed\n";
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::display() const {
    cout << "Circle radius: " << radius
        << ", Area: " << area()
        << ", Perimeter: " << perimeter()
        << endl;
}