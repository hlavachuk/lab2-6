#include "polygon.h"
using namespace std;

Polygon::Polygon(string name, int sidesCount)
    : Shape(name), sidesCount(sidesCount) {
}

Polygon::Polygon(const Polygon& other)
    : Shape(other), sidesCount(other.sidesCount) {
}

Polygon::Polygon(Polygon&& other) noexcept
    : Shape(move(other)), sidesCount(other.sidesCount) {
    other.sidesCount = 0;
}

Polygon& Polygon::operator=(const Polygon& other) {
    if (this != &other) {
        Shape::operator=(other);
        sidesCount = other.sidesCount;
    }
    return *this;
}

Polygon::~Polygon() {}

void Polygon::display() const {
    Shape::display();
    cout << "Sides count: " << sidesCount << endl;
}

void Polygon::info() const {
    cout << "This is a polygon with " << sidesCount << " sides" << endl;
}

void Polygon::showType() const {
    cout << "Polygon method" << endl;
}