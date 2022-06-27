#include <iostream>
#include <string>
void demo()
{ 
    // static local variable
    static int count = 0;
    count++;
}
  
int main()
{
    for (int i=0; i<5; i++)
    {
        demo();
        // count declared in function demo
        std::cout << count << std::endl; 
    }
    return 0;
}