#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0);
    Point(const Point& other);
    Point(Point&& other) noexcept;
    Point& operator=(const Point& other);
    ~Point();

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    void display() const;
};

class Triangle : public Polygon {
private:
    double a, b, c;
    Point p1, p2, p3;
    static int triangleCount;

public:
    Triangle();
    Triangle(double a, double b, double c,
        Point p1 = Point(), Point p2 = Point(), Point p3 = Point());

    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);

    ~Triangle();

    double area() const override;
    double perimeter() const override;
    void display() const override;

    Triangle operator+(const Triangle& other) const;
    Triangle operator-() const;

    friend ostream& operator<<(ostream& out, const Triangle& t);
    friend istream& operator>>(istream& in, Triangle& t);

    static int getTriangleCount();
};

#endif