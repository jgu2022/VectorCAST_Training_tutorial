#include <iostream>
class Demo
{
public: 
    Demo(){};
    ~Demo(){};
    static int counter;	//静态成员变量
    int local_counter;

    static void printCounter(); 
    static void setCounter();
    void setLocalCounter();
};
// int Demo::counter = 0; //静态成员变量初始化

void printStaticLocalVariable()
{
    static int count = 0; //静态局部变量
    std::cout << count << std::endl;
    count++;
}

//int Demo::counter = 0; //静态变量初始化
void Demo::setCounter()
{ 
    local_counter++;
}

void Demo::printCounter()
{
    std::cout << counter << std::endl;
}

void Demo::setLocalCounter()
{ 
    local_counter++;
}

int main()
{
    Demo d1;
    std::cout << d1.counter << std::endl;
    std::cout << MAX_COUNTER << std::endl;
    return 0;
}
