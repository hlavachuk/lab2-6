#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Triangle(1, 1, 1) {}

Triangle::Triangle(double a, double b, double c)
    : a(a), b(b), c(c) {
}

Triangle::~Triangle() {
    std::cout << "triangle destroyed\n";
}

double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::display() const {
    std::cout << "triangle sides: " << a << ", " << b << ", " << c
        << ", area: " << area()
        << ", perimeter: " << perimeter()
        << std::endl;
}