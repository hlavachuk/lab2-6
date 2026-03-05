#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
private:
    double a;
    double b;
    double c;

public:
    Triangle();
    Triangle(double a, double b, double c = 1);

    ~Triangle();

    double area() const;
    double perimeter() const;

    void display() const;
};

#endif