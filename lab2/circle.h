#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    double radius;

public:
    Circle();
    Circle(double radius = 1);

    ~Circle();

    double area() const;
    double perimeter() const;

    void display() const;
};

#endif