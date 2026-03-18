#include "triangle.h"
#include <iostream>
#include <cmath>

using namespace std;


int Triangle::triangleCount = 0;


Triangle::Triangle() : Triangle(1, 1, 1) {}

Triangle::Triangle(double a, double b, double c)
    : a(a), b(b), c(c) {
    triangleCount++;
}


Triangle::Triangle(const Triangle& other)
    : a(other.a), b(other.b), c(other.c) {
    triangleCount++;
    cout << "Copy constructor called\n";
}


Triangle::Triangle(Triangle&& other)
    : a(other.a), b(other.b), c(other.c) {

    other.a = 0;
    other.b = 0;
    other.c = 0;

    triangleCount++;
    cout << "Move constructor called\n";
}


Triangle::~Triangle() {
    cout << "Triangle destroyed\n";
    triangleCount--;
}


double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::display() const {
    cout << "Triangle sides: " << a << ", " << b << ", " << c
        << ", area: " << area()
        << ", perimeter: " << perimeter()
        << endl;
}


void Triangle::setA(double a) {
    this->a = a;
}

int Triangle::getCount() {
    return triangleCount;
}


Triangle Triangle::operator+(const Triangle& other) {
    return Triangle(a + other.a, b + other.b, c + other.c);
}

bool Triangle::operator==(const Triangle& other) {
    return (a == other.a && b == other.b && c == other.c);
}

Triangle Triangle::operator-() {
    return Triangle(-a, -b, -c);
}

ostream& operator<<(ostream& os, const Triangle& t) {
    os << "Triangle sides: " << t.a << ", " << t.b << ", " << t.c
        << ", area: " << t.area()
        << ", perimeter: " << t.perimeter();
    return os;
}

istream& operator>>(istream& is, Triangle& t) {
    cout << "Enter 3 sides: ";
    is >> t.a >> t.b >> t.c;
    return is;
}