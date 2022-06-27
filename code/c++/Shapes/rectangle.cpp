#include "rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int x, int y, int height, int width)
  : Shape( x, y ),
    mHeight(height),
    mWidth(width)
{
}

float Rectangle::getArea() const
{
  return mHeight * mWidth;
}
