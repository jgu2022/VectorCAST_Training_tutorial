#include <iostream>
#include <string>

void testFunc(int& ref);
//发现是引用，转换为 int* const ref = &a;
void testFunc(int& ref){
    ref = 100; // ref是引用，转换为*ref = 100
}

class B{
	
public:

B(){};

int n_b ;

};

class A{
	
public:

A(int a):m_a(a){};

int A_fun1( B& a){
m_b=a.n_b;
return m_b;
}

public:
int m_a ;
int m_b;

};

