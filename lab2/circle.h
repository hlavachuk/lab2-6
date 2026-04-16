#pragma once
#include "Shape.h"
#include <iostream>

using namespace std;

class Circle : public Shape {
private:
    double radius;
    static int circleCount;

public:
    Circle();
    Circle(double radius);
    Circle(const Circle& other);
    Circle(Circle&& other) noexcept;
    Circle& operator=(const Circle& other);

    double area() const override;
    double perimeter() const override;
    void display() const override;
    void info() const override;
    void draw() const override;

    Circle operator+(const Circle& other) const;
    Circle operator-(const Circle& other) const;

    friend ostream& operator<<(ostream& os, const Circle& c);
    friend istream& operator>>(istream& is, Circle& c);

    ~Circle() override;
};