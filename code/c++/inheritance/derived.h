#ifndef DERIVED_H
#define DERIVED_H

#include "based.h"
using namespace std;

class Derived: public BaseA, public BaseB{
public:
    Derived(int a, int b, int c, int d, int e);
    ~Derived();
public:
    void show();
private:
    int m_e;
};




#endif
