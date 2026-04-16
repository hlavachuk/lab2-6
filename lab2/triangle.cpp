#include "triangle.h"
#include <cmath>

using namespace std;

int Triangle::triangleCount = 0;

Triangle::Triangle() : a(1), b(1), c(1) {
    triangleCount++;
}

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {
    triangleCount++;
}

Triangle::Triangle(const Triangle& other) : a(other.a), b(other.b), c(other.c) {
    triangleCount++;
}

Triangle::Triangle(Triangle&& other) noexcept : a(other.a), b(other.b), c(other.c) {
    other.a = 0;
    other.b = 0;
    other.c = 0;
    triangleCount++;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::display() const {
    cout << "Triangle: a = " << a << ", b = " << b << ", c = " << c << endl;
}

void Triangle::info() const {
    cout << "This is triangle" << endl;
}

void Triangle::draw() const {
    cout << "Drawing triangle" << endl;
}

Triangle Triangle::operator+(const Triangle& other) const {
    return Triangle(a + other.a, b + other.b, c + other.c);
}

Triangle Triangle::operator-(const Triangle& other) const {
    return Triangle(a - other.a, b - other.b, c - other.c);
}

ostream& operator<<(ostream& os, const Triangle& t) {
    os << t.a << " " << t.b << " " << t.c;
    return os;
}

istream& operator>>(istream& is, Triangle& t) {
    is >> t.a >> t.b >> t.c;
    return is;
}

Triangle::~Triangle() {
    cout << "Triangle destroyed" << endl;
}