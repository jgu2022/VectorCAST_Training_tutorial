#include <iostream>
#include <string>
#include <iostream>
class Demo
{
public: 
    Demo(){};
    ~Demo(){};
    static int counter;	//静态成员变量
    int local_counter;
    static void printCounter(); //静态成员函数
    static void setCounter();
    void setLocalCounter();
};

int Demo::counter = 0; //静态变量初始化

// 修改静态成员变量
void Demo::setCounter()
{ 
    Demo::counter++;
}

void Demo::printCounter()
{
    std::cout << Demo::counter << std::endl;
}

void Demo::setLocalCounter()
{ 
    local_counter++;
}

// 访问类的静态成员变量
int getCounter()
{
    Demo d1;
    std::cout << d1.counter << std::endl;
    std::cout << Demo::counter << std::endl;
    return 0;
}


// 操作静态局部变量
void printStaticLocalVariable()
{
    static int count = 0; //静态局部变量
    count++;
}
  
int main()
{
    for (int i=0; i<5; i++)
    {
        printStaticLocalVariable();
    }
    return 0;
}