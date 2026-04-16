#include "circle.h"
#include <cmath>

using namespace std;

int Circle::circleCount = 0;

Circle::Circle() : radius(1) {
    circleCount++;
}

Circle::Circle(double radius) : radius(radius) {
    circleCount++;
}

Circle::Circle(const Circle& other) : radius(other.radius) {
    circleCount++;
}

Circle::Circle(Circle&& other) noexcept : radius(other.radius) {
    other.radius = 0;
    circleCount++;
}

Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        radius = other.radius;
    }
    return *this;
}

double Circle::area() const {
    return 3.14159 * radius * radius;
}

double Circle::perimeter() const {
    return 2 * 3.14159 * radius;
}

void Circle::display() const {
    cout << "Circle: radius = " << radius << endl;
}

void Circle::info() const {
    cout << "This is circle" << endl;
}

void Circle::draw() const {
    cout << "Drawing circle" << endl;
}

Circle Circle::operator+(const Circle& other) const {
    return Circle(radius + other.radius);
}

Circle Circle::operator-(const Circle& other) const {
    return Circle(radius - other.radius);
}

ostream& operator<<(ostream& os, const Circle& c) {
    os << c.radius;
    return os;
}

istream& operator>>(istream& is, Circle& c) {
    is >> c.radius;
    return is;
}

Circle::~Circle() {
    cout << "Circle destroyed" << endl;
}