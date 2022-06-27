#include "ForwardDeclaration.h"
int main()
{
    int x{}, y{}, z{};
    ptr_vector<int> v;
    v.push_back(&x);
    v.push_back(&y);
    v.push_back(&z);
    v.print();
}


