#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double width, double height = 1);

    ~Rectangle();

    double area() const;
    double perimeter() const;

    void display() const;
};

#endif