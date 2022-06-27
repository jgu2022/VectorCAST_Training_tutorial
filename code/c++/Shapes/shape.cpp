#include "shape.h"

Shape::Shape()
{
}

Shape::Shape(int x, int y)
  : mX(x),
    mY(y)
{
}

void Shape::setPosition(int x, int y)
{
  mX = x;
  mY = y;
}

int Shape::getX() const
{
  return mX;
}

int Shape::getY() const
{
  return mY;
}
