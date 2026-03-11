#include "Circle.h"
#include "Rectangle.h"
#include "triangle.h"
#include <iostream>
#include <utility>

using namespace std;

int main() {
    cout << "=== Default and parameterized constructors ===" << endl;
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

    cout << "\n=== Copy constructors ===" << endl;
    Circle c3(c2);
    Rectangle r3(r2);
    Triangle t3(t2);

    c3.display();
    r3.display();
    t3.display();

    cout << "\n=== Move constructors ===" << endl;
    Circle c4(std::move(c3));
    Rectangle r4(std::move(r3));
    Triangle t4(std::move(t3));

    c4.display();
    r4.display();
    t4.display();

    cout << "\n=== this pointer example ===" << endl;
    t1.setA(10);
    t1.display();

    cout << "\n=== Const objects ===" << endl;
    const Circle c5(7);
    const Rectangle r5(2, 8);
    const Triangle t5(6, 8, 10);

    c5.display();
    r5.display();
    t5.display();

    cout << "Circle area: " << c5.area() << endl;
    cout << "Rectangle area: " << r5.area() << endl;
    cout << "Triangle area: " << t5.area() << endl;

    cout << "\n=== Static fields and methods ===" << endl;
    cout << "Circle count: " << Circle::getCount() << endl;
    cout << "Rectangle count: " << Rectangle::getCount() << endl;
    cout << "Triangle count: " << Triangle::getCount() << endl;

    cout << "\n=== Binary operators ===" << endl;
    Triangle t6 = t2 + t4;
    t6.display();

    cout << "\n=== Unary operators ===" << endl;
    Triangle t7 = -t2;
    t7.display();

    cout << "\n=== Stream operators << and >> ===" << endl;
    cout << t2 << endl;

    Triangle t8;
    cin >> t8;
    cout << t8 << endl;

    return 0;
}