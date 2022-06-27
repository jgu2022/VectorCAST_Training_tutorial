#include "square.h"

Square::Square()
{
}

Square::Square(int x, int y, int size)
  : Rectangle( x, y, size, size ),
    mSize(size)
{
}

