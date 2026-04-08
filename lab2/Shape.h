#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
using namespace std;

class Drawable { // Interface  клас тільки з pure virtual функціями
public:
    virtual void draw() const = 0; //Полік
    virtual ~Drawable() {}  

class Shape : public Drawable { // Interface  клас тільки з pure virtual функціями
protected:
    string name;
    static int count;

public:
    Shape(string name = "Shape");
    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape& operator=(const Shape& other);
    virtual ~Shape(); // Virtual destructor потрібен для правильного видалення через вказівник на батьківський клас (Любий)

    virtual double area() const = 0;     // Pure virtual function  метод без реалізації
    virtual double perimeter() const = 0;
    virtual void display() const;
    virtual void info() const;
    virtual void draw() const override = 0;

    void showType() const; //Static binding (МЕТОД!!!!!)

    static int getCount();
};

#endif