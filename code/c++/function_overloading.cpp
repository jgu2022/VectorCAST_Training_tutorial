#include <stdio.h>

class Tester
{
    int i;
public:
    Tester()
    {
        printf("Tester::Tester()\n");
        this->i = 0;
    }
    
    Tester(int i)
    {
        printf("Tester::Tester(int i)\n");
        this->i = i;
    }
    
    Tester(const Tester& obj)
    {
        printf("Tester(const Tester& obj)\n");
        this->i = obj.i;
    }
    
    static void function()
    {
        printf("void Tester::function()\n");
    }
    
    void function(int i)
    {
        printf("void Tester::function(int i), i = %d\n", i);
    }
    
    int getI()
    {
        return i;
    }
};

void function()
{
    printf("void function()\n");
}

void function(int i)
{
    printf("void function(int i), i = %d\n", i);
}

int main()
{
    function();       //void function()
    function(1);      //void function(int i), i = 1
    
    Tester t;        // Tester::Tester()
    Tester t1(1);    // Tester::Tester(int i)
    Tester t2(t1);   // Tester(const Tester& obj)
    
    function();       // void function()
    Tester::function(); // void Tester::function()
    
    function(2);      // void function(int i), i = 2;
    t1.function(2);   // void Tester::function(int i), i = 2
    t1.function();    // void Tester::function()
    
    return 0;
}
