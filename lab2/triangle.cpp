#include "triangle.h"
using namespace std;

int Triangle::triangleCount = 0;

// Point

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(Point&& other) noexcept : x(other.x), y(other.y) {
    other.x = 0;
    other.y = 0;
}

Point& Point::operator=(const Point& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

Point::~Point() {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

void Point::display() const {
    cout << "(" << x << ", " << y << ")";
}

// Triangle

Triangle::Triangle()
    : Polygon("Triangle", 3), a(1), b(1), c(1), p1(0, 0), p2(1, 0), p3(0, 1) {
    triangleCount++;
}

Triangle::Triangle(double a, double b, double c, Point p1, Point p2, Point p3)
    : Polygon("Triangle", 3), a(a), b(b), c(c), p1(p1), p2(p2), p3(p3) {
    triangleCount++;
}

Triangle::Triangle(const Triangle& other)
    : Polygon(other), a(other.a), b(other.b), c(other.c),
    p1(other.p1), p2(other.p2), p3(other.p3) {
    triangleCount++;
}

Triangle::Triangle(Triangle&& other) noexcept
    : Polygon(move(other)), a(other.a), b(other.b), c(other.c),
    p1(move(other.p1)), p2(move(other.p2)), p3(move(other.p3)) {
    other.a = 0;
    other.b = 0;
    other.c = 0;
    triangleCount++;
}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        Polygon::operator=(other);
        a = other.a;
        b = other.b;
        c = other.c;
        p1 = other.p1;
        p2 = other.p2;
        p3 = other.p3;
    }
    return *this;
}

Triangle::~Triangle() {
    cout << "triangle destroyed" << endl;
}

double Triangle::perimeter() const {
    return a + b + c;
}

double Triangle::area() const {
    double s = perimeter() / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::display() const {
    Polygon::display();
    cout << "triangle sides: " << a << ", " << b << ", " << c << endl;
    cout << "points: ";
    p1.display();
    cout << " ";
    p2.display();
    cout << " ";
    p3.display();
    cout << endl;
    cout << "area: " << area() << endl;
    cout << "perimeter: " << perimeter() << endl;
}

Triangle Triangle::operator+(const Triangle& other) const {
    return Triangle(a + other.a, b + other.b, c + other.c, p1, p2, p3);
}

Triangle Triangle::operator-() const {
    return Triangle(a, b, c, p1, p2, p3);
}

ostream& operator<<(ostream& out, const Triangle& t) {
    out << "Triangle: sides = " << t.a << ", " << t.b << ", " << t.c;
    return out;
}

istream& operator>>(istream& in, Triangle& t) {
    cout << "Enter sides a, b, c: ";
    in >> t.a >> t.b >> t.c;
    return in;
}

int Triangle::getTriangleCount() {
    return triangleCount;
}