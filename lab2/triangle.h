#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <string>
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

class Shape {
protected:
    string name;
    static int count;

public:
    Shape(string name = "Shape");
    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape& operator=(const Shape& other);
    virtual ~Shape();

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const;

    static int getCount();
};

class Polygon : public Shape {
protected:
    int sidesCount;

public:
    Polygon(string name = "Polygon", int sidesCount = 0);
    Polygon(const Polygon& other);
    Polygon(Polygon&& other) noexcept;
    Polygon& operator=(const Polygon& other);
    virtual ~Polygon();

    void display() const override;
};

class Triangle : public Polygon {
private:
    double a, b, c;
    Point p1, p2, p3;   // HAS-A relationship
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