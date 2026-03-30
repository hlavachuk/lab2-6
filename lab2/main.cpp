#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <utility>

using namespace std;

int main() {

    cout << "=== Constructors ===\n";

    Circle c1, c2(5);
    Rectangle r1, r2(4, 6);
    Triangle t1, t2(3, 4, 5);

    c1.display();
    c2.display();

    r1.display();
    r2.display();

    t1.display();
    t2.display();

    cout << "\n=== Copy constructors ===\n";

    Circle c3 = c2;
    Rectangle r3 = r2;
    Triangle t3 = t2;

    c3.display();
    r3.display();
    t3.display();

    cout << "\n=== Move constructors ===\n";

    Circle c4 = move(c3);
    Rectangle r4 = move(r3);
    Triangle t4 = move(t3);

    c4.display();
    r4.display();
    t4.display();

    cout << "\n=== Const objects ===\n";

    const Circle c5(7);
    const Rectangle r5(2, 8);
    const Triangle t5(6, 8, 10);

    cout << "Circle area: " << c5.area() << endl;
    cout << "Rectangle area: " << r5.area() << endl;
    cout << "Triangle area: " << t5.area() << endl;

    cout << "\n=== Static ===\n";

    cout << "Total circles: " << Circle::getCount() << endl;
    cout << "Total rectangles: " << Rectangle::getCount() << endl;
    cout << "Total triangles: " << Triangle::getTriangleCount() << endl;

    cout << "\n=== Binary operators ===\n";

    Triangle t6 = t2 + t4;
    t6.display();

    cout << "\n=== Unary operators ===\n";

    Triangle t7 = -t2;
    t7.display();

    cout << "\n=== Stream operators ===\n";

    cout << t2 << endl;

    Triangle t8;
    cin >> t8;
    cout << t8 << endl;

    return 0;
}