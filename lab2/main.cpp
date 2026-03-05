#include "Circle.h"
#include "Rectangle.h"
#include "triangle.h"

int main() {

    Circle c1;
    Circle c2(5);

    Rectangle r1;
    Rectangle r2(4, 6);

    Triangle t1;
    Triangle t2(3, 4, 5);

    c1.display();
    c2.display();

    r1.display();
    r2.display();

    t1.display();
    t2.display();

    return 0;
}