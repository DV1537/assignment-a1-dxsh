#ifndef POINT_H
#define POINT_H
#include "Shape.h"

class Point: public Shape {
  public:
    Point() : Shape("Point") {}
    std::string getType() const;
    int area() const;
    int position() const;
    bool isConvex() const;
    int distance(Shape& s) const;
};

#endif
/* vim: set ts=2 sw=2 tw=79 ft=cpp et :*/
