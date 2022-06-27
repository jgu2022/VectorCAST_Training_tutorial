#include <stdio.h>

class Complex 
{
    int a;
    int b;
public:
    Complex(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }
    
    int getA()
    {
        return a;
    }
    
    int getB()
    {
        return b;
    }
    
    Complex operator + (const Complex& p)
    {
        Complex ret;
        printf("Complex operator + (const Complex& p)\n");
        ret.a = this->a + p.a;
        ret.b = this->b + p.b;
        
        return ret;
    }
    
    friend Complex operator + (const Complex& p1, const Complex& p2);
};

Complex operator + (const Complex& p1, const Complex& p2)
{
    Complex ret;
    printf("Complex operator + (const Complex& p1, const Complex& p2)\n");
    ret.a = p1.a + p2.a;
    ret.b = p1.b + p2.b;
    
    return ret;
}

int main()
{

    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1 + c2; // same as c1.operator + (c2),call member function
    Complex c4 = operator +(c1, c2); //call friend function
    
    printf("c3.a = %d, c3.b = %d\n", c3.getA(), c3.getB());
    printf("c4.a = %d, c4.b = %d\n", c4.getA(), c4.getB());

    return 0;
}
