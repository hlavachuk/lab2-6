#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

class Drawable {
public:
    virtual void draw() const = 0;
    virtual ~Drawable() {}
};

class Shape : public Drawable {
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
    virtual void info() const;
    virtual void draw() const = 0;

    void showType() const;

    static int getCount();
};

#endif