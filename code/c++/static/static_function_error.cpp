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
    virtual static void virtualPrintCounter();
    static void constPrintCounter() const;
    volatile static void volatilePrintCounter();

private:
    static void privatePrintCounter(); // declare as private
protected:
    static void protectPrintCounter(); // declare as protected
};
void Demo::privatePrintCounter()
{
    std::cout << counter << std::endl;
}

void Demo::protectPrintCounter()
{
    std::cout << counter << std::endl;
}

void printStaticLocalVariable()
{
    static int count = 0; //静态局部变量
    std::cout << count << std::endl;
    count++;
}

int Demo::counter = 0; //静态变量初始化
void Demo::setCounter()
{ 
    Demo::counter++;
    local_counter++;
}

void Demo::printCounter()
{
    std::cout << Demo::counter << std::endl;
}

void Demo::setLocalCounter()
{ 
    local_counter++;
}

int main()
{
    Demo d1;
    std::cout << d1.counter << std::endl;
    d1.privatePrintCounter(); // access private static functions
    d1.protectPrintCounter(); // access protected static functions
    return 0;
}
