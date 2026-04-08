#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
using namespace std;

class Polygon : public Shape {
protected:
    int sidesCount;

public:
    Polygon(string name = "Polygon", int sidesCount = 0);
    Polygon(const Polygon& other);
    Polygon(Polygon&& other) noexcept;
    Polygon& operator=(const Polygon& other);
    virtual ~Polygon();

    void display() const override;
};

#endif