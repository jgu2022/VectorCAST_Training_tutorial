#include <iostream>

long double operator"" _mm(long double x) { return x / 1000; }
long double operator"" _m(long double x)  { return x; }
long double operator"" _km(long double x) { return x * 1000; }

int main()
{
    std::cout << 1.0_mm << std::endl; //0.001
    std::cout << 1.0_m  << std::endl; //1
    std::cout << 1.0_km << std::endl; //1000

    return 0;
}

