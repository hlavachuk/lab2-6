#pragma once
#include "polygon.h"
#include <iostream>

using namespace std;

class Triangle : public Polygon {
private:
    double a;
    double b;
    double c;
    static int triangleCount;

public:
    Triangle();
    Triangle(double a, double b, double c);
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);

    double area() const override;
    double perimeter() const override;
    void display() const override;
    void info() const override;
    void draw() const override final;

    Triangle operator+(const Triangle& other) const;
    Triangle operator-(const Triangle& other) const;

    friend ostream& operator<<(ostream& os, const Triangle& t);
    friend istream& operator>>(istream& is, Triangle& t);

    ~Triangle() override;
};