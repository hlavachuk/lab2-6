#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle() : Rectangle(1, 1) {}

Rectangle::Rectangle(double width, double height)
    : width(width), height(height) {
}

Rectangle::~Rectangle() {
    cout << "Rectangle destroyed\n";
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::display() const {
    cout << "Rectangle width: " << width
        << ", height: " << height
        << ", Area: " << area()
        << ", Perimeter: " << perimeter()
        << endl;
}