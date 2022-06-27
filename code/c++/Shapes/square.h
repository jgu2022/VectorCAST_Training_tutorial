#ifndef Square_H
#define Square_H

#include "rectangle.h"

class Square : public Rectangle
{
  public:
    Square();
    Square(int x, int y, int size);

    virtual std::string getName() const { return "Square"; }

  private:
    float mSize;

};

#endif
