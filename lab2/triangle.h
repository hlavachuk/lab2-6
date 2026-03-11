#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>

using namespace std;

class Triangle {
private:
    double a;
    double b;
    double c;

    static int triangleCount;   

public:
    Triangle();
    Triangle(double a, double b, double c);

    Triangle(const Triangle& other);
    Triangle(Triangle&& other);

    ~Triangle();

    double perimeter() const;
    double area() const;

    void display() const;
    void setA(double a);

    static int getCount();

    Triangle operator+(const Triangle& other);

    friend ostream& operator<<(ostream& os, const Triangle& t);
    friend istream& operator>>(istream& is, Triangle& t);
};

#endif