#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <utility>

using namespace std;

void showByPointer(Shape* shape) { // полік через вказівник коли через Shape* викликається метод дочірнього класу динамічний або Runtime
    shape->display();
    shape->info();
    shape->draw();
    cout << "Area: " << shape->area() << endl;
    cout << "Perimeter: " << shape->perimeter() << endl;
}

void showByReference(const Shape& shape) { // полік через посилання коли через Shape* викликається метод дочірнього класу
    shape.display();
    shape.info();
    shape.draw();
    cout << "Area: " << shape.area() << endl;
    cout << "Perimeter: " << shape.perimeter() << endl;
}

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

    cout << "\n=== Static Method Binding ===\n";

    Shape* basePtr = &c2;
    basePtr->showType(); //Static binding  виклик не virtual методу (98 99 рядок)
    c2.showType();

    cout << "\n=== Run-time polymorphism with pointer ===\n";

    Shape* shapes[3];
    shapes[0] = &c2;
    shapes[1] = &r2;
    shapes[2] = &t2;

    for (int i = 0; i < 3; i++) {
        showByPointer(shapes[i]);
        cout << endl;
    }

    cout << "\n=== Run-time polymorphism with reference ===\n";

    showByReference(c2);
    cout << endl;
    showByReference(r2);
    cout << endl;
    showByReference(t2);
    cout << endl;

    cout << "\n=== Interface Drawable ===\n";

    Drawable* drawables[3]; // Використання інтерфейс
    drawables[0] = &c2;
    drawables[1] = &r2;
    drawables[2] = &t2;

    for (int i = 0; i < 3; i++) {
        drawables[i]->draw();
    }

    return 0;
}