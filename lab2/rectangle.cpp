#include "rectangle.h"
using namespace std;

Rectangle::Rectangle()
    : Polygon("Rectangle", 4), width(1), height(1), topLeft(0, 0) {
}

Rectangle::Rectangle(double width, double height, Point topLeft)
    : Polygon("Rectangle", 4), width(width), height(height), topLeft(topLeft) {
}

Rectangle::Rectangle(const Rectangle& other)
    : Polygon(other), width(other.width), height(other.height), topLeft(other.topLeft) {
}

Rectangle::Rectangle(Rectangle&& other) noexcept
    : Polygon(move(other)), width(other.width), height(other.height), topLeft(move(other.topLeft)) {
    other.width = 0;
    other.height = 0;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        Polygon::operator=(other);
        width = other.width;
        height = other.height;
        topLeft = other.topLeft;
    }
    return *this;
}

Rectangle::~Rectangle() {
    cout << "Rectangle destroyed" << endl;
}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::display() const {
    Polygon::display();
    cout << "rectangle: " << width << " x " << height << endl;
    cout << "top left: ";
    topLeft.display();
    cout << endl;
    cout << "area: " << area() << endl;
    cout << "perimeter: " << perimeter() << endl;
}

int Rectangle::getCount() {
    return Shape::getCount();
}