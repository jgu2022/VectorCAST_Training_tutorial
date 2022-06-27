#include <iostream>

class test{
    public:
        int data;
        int func1();                                            //非静态成员函数声明
        virtual void func2() final;                             //可为虚函数，可使用 final/override
        virtual int getData() const {return data;}              //可内联定义
        void C_func() const, V_func() volatile, R_func() &&;    //可为CV限定或引用限定
        test():data(10){}                                       //构造函数亦是成员函数,可带有成员初始化列表
};

int test::func1() {return 1;}                                   //若不内联定义，则必须定义于命名空间

class d_test : public test{
    public:
        int data2;
        int getData() const override {return data * data2;}     //使用override重写getData函数
};


class s_test{
    public:
        s_test(){data++;}                                       //构造函数
        static int data;                                        //静态成员变量
        static int getData(){return data;}                      //静态成员函数
};

int s_test::data = 0;   //初始化类 s_test 的静态成员

class op_test{
    public:
        int num[3];
        op_test():num({1,2,3}){};
        int& operator[](int);

};

int& op_test::operator[](int index)
{
    std::cout << "operator[]" << std::endl;
    if(index < 0 || index >2)
        throw index;
    else
        return num[index];
}

int test_op_overloading()
{

    op_test a;
    op_test *p = &a;
    try
    {
        for(int i = 0; i < 4; i++)
        {
            std::cout << a[i] <<std::endl;        //这句和下面的作用一样。 这里也对[]进行了重载
            std::cout << p[0][i] <<std::endl;       //第一个[]运算符是下标运算符的原意，p[0]相当于*p，代表指针所指向的对象
                                                     //第二个[]运算符使用的是重载后的语义，表示从对象内部的成员数组中取数据
        }
    }
    catch(int index)
    {
        std::cout << "subscript out of range:"<< index << std::endl;
    }
    return 0;

}

int main()
{
    s_test a;
    s_test b;
    std::cout << "Final Stage Data: " << s_test::getData() << std::endl; //输出结果 ： 2
};

