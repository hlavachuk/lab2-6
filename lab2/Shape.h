#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

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

#endif