#include "shape.h"
using namespace std;

int Shape::count = 0;

Shape::Shape(string name) : name(name) {
    count++;
}

Shape::Shape(const Shape& other) : name(other.name) {
    count++;
}

Shape::Shape(Shape&& other) noexcept : name(other.name) {
    other.name = "MovedShape";
    count++;
}

Shape& Shape::operator=(const Shape& other) {
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

Shape::~Shape() {}

void Shape::display() const {
    cout << "Shape name: " << name << endl;
}

void Shape::info() const {
    cout << "This is a shape: " << name << endl;
}

void Shape::showType() const {
    cout << "Base Shape method" << endl;
}

int Shape::getCount() {
    return count;
}