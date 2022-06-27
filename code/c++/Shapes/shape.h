#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
  public:
    Shape();
    Shape(int x, int y);
    
    void setPosition(int x, int y);

    int getX() const;
    int getY() const;
    
    virtual std::string getName() const = 0;
    virtual float getArea() const = 0;

  private:
    int mX;
    int mY;
};

#endif
