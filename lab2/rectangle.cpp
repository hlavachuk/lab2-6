#include "rectangle.h"

using namespace std;

int Rectangle::rectangleCount = 0;

Rectangle::Rectangle() : width(1), height(1) {
    rectangleCount++;
}

Rectangle::Rectangle(double width, double height) : width(width), height(height) {
    rectangleCount++;
}

Rectangle::Rectangle(const Rectangle& other) : width(other.width), height(other.height) {
    rectangleCount++;
}

Rectangle::Rectangle(Rectangle&& other) noexcept : width(other.width), height(other.height) {
    other.width = 0;
    other.height = 0;
    rectangleCount++;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
    }
    return *this;
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::display() const {
    cout << "Rectangle: width = " << width << ", height = " << height << endl;
}

void Rectangle::info() const {
    cout << "This is rectangle" << endl;
}

void Rectangle::draw() const {
    cout << "Drawing rectangle" << endl;
}

Rectangle Rectangle::operator+(const Rectangle& other) const {
    return Rectangle(width + other.width, height + other.height);
}

Rectangle Rectangle::operator-(const Rectangle& other) const {
    return Rectangle(width - other.width, height - other.height);
}

ostream& operator<<(ostream& os, const Rectangle& r) {
    os << r.width << " " << r.height;
    return os;
}

istream& operator>>(istream& is, Rectangle& r) {
    is >> r.width >> r.height;
    return is;
}

Rectangle::~Rectangle() {
    cout << "Rectangle destroyed" << endl;
}