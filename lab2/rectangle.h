#pragma once
#include "Polygon.h"
#include <iostream>

using namespace std;

class Rectangle : public Polygon {
private:
    double width;
    double height;
    static int rectangleCount;

public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);

    double area() const override;
    double perimeter() const override;
    void display() const override;
    void info() const override;
    void draw() const override;

    Rectangle operator+(const Rectangle& other) const;
    Rectangle operator-(const Rectangle& other) const;

    friend ostream& operator<<(ostream& os, const Rectangle& r);
    friend istream& operator>>(istream& is, Rectangle& r);

    ~Rectangle() override;
};