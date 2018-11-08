#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
 private:
   std::string shape;
 
 public:
   Shape();
   Shape(std::string shape) : shape{shape} {}  /* ? */
   virtual std::string getType() const = 0;
   virtual int area() const = 0;
   virtual int position() const = 0;
   virtual bool isConvex() const = 0;
   virtual int distance(Shape& s) const = 0;
};

#endif
/* vim: set ts=2 sw=2 tw=79 ft=cpp et :*/
