#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
  public:
    Rectangle();
    Rectangle(int x, int y, int height, int width);

    virtual float getArea() const;
    virtual std::string getName() const { return "Rectangle"; }

  private:
    int mHeight;
    int mWidth;
};

#endif
