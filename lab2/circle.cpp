#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

static const double PI = 3.14159265358979323846;

Circle::Circle() : Circle(1) {}

Circle::Circle(double radius)
    : radius(radius) {
}

Circle::~Circle() {
    cout << "Circle destroyed\n";
}

double Circle::area() const {
    return PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * PI * radius;
}

void Circle::display() const {
    cout << "Circle radius: " << radius
        << ", Area: " << area()
        << ", Perimeter: " << perimeter()
        << endl;
}