#ifndef CIRCLE_H
#define CIRCLE_H

#include "triangle.h"
using namespace std;

class Circle : public Shape {
private:
    double radius;
    Point center;

public:
    Circle();
    Circle(double radius, Point center = Point());

    Circle(const Circle& other);
    Circle(Circle&& other) noexcept;
    Circle& operator=(const Circle& other);

    ~Circle();

    double area() const override;
    double perimeter() const override;
    void display() const override;
    void info() const override;
    void draw() const override;
    void showType() const;

    static int getCount();
};

#endif