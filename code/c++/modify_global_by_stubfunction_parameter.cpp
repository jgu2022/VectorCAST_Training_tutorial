#include <iostream>

 
struct A{
int ID;
};
struct B{
B(){}
int ID;
};
void stub_A(A&);
void stub_AA(A*);
void stub_B(B&);
 
void test()
{
A a1;
A a2;
B b;
stub_A(a1);
stub_AA(&a2);
stub_B(b);
std::cout << a1.ID <<std::endl;
std::cout << a2.ID <<std::endl;
std::cout << b.ID <<std::endl;
}