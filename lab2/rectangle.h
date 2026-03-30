#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "triangle.h"
using namespace std;

class Rectangle : public Polygon {
private:
    double width;
    double height;
    Point topLeft;   // HAS-A

public:
    Rectangle();
    Rectangle(double width, double height, Point topLeft = Point());

    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);

    ~Rectangle();

    double area() const override;
    double perimeter() const override;
    void display() const override;

    static int getCount();
};

#endif