#ifndef CIRCLE_H
#define CIRCLE_H

using namespace std;

class Circle {
private:
    double radius;

public:
    Circle();
    Circle(double radius);

    ~Circle();

    double area() const;
    double perimeter() const;

    void display() const;
};

#endif