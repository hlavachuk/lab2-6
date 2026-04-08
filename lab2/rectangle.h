#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "triangle.h"
using namespace std;

class Rectangle : public Polygon {
private:
    double width;
    double height;
    Point topLeft;

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
    void info() const override;
    void draw() const override;
    void showType() const;

    static int getCount();
};

#endif