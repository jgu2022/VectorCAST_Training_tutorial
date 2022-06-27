#include <iostream>
#include <string>

/* 四种不同形式的命名空间  */
// 全局命名空间
int f()
{
    std::cout << "Call f() in global scope!" << std::endl;
    return 0;
}
char ch= 'a';

// 匿名命名空间
namespace
{
    int i;

    void g()
    {
        std::cout << "Call g() In unnamed namespace!" << std::endl;
    }    
}

// 命名空间A
namespace A
{
    void h(int);
    int val = -1;
    int Book;
    
    // 内联命名空间
    inline namespace foo
    {
        void h(char); //与A::h不冲突，参数类型不同，属于函数重载
        class B{      //可以使用A::B直接访问
        public:
            B(){}
            ~B(){}
            int size;
        };
    }
}

// 嵌套内联命名空间
// C++20的特性，需要g++9或以上版本
#if(__cplusplus == 202002L)
    namespace Lib::inline Lib1   
    {
        template <typename T> class A; 
        template <typename T> void g(T);
    }
#endif


/* 命名空间嵌套声明 */
namespace foo::bar::baz
{
    struct g 
        {
            int size;
        };
    void f(int);
    void f(double);
    void g(char)
    {
        std::cout << "In foo::bar::baz::g(char)" << std::endl;
    } // 函数名g与结构体类型g同名

    class B{ // 类名与A::B同名，如果同时引入A和foo::bar::baz命名空间会产生歧义
    public:
        B(){};
        explicit B(int para)
        {
            id = para;
        }
        ~B(){};
        friend void f(B);       // foo::bar::baz::f是友元函数，可以访问B的私有和保护成员
    protected:
        static constexpr int MASK = 255;
    private:
        int id;
    public:
        class C
        {
            friend void g();  // foo::bar::baz::g是友元函数，可以访问C的私有成员
            friend void h(C); // foo::bar::baz::h是友元函数，可以访问C的私有成员，与全局的::h不冲突
        };
    };
    // foo::bar::baz::f, foo::bar::baz::g和foo::bar::baz::h在命名空间范围内还不可见
    // 即使f(), g()和h()现在都是foo::bar::baz命名空间的成员


    B obj;
    void g()  // foo::bar::baz::g可以访问同一个namespace下的f函数
    {
        std::cout << "In foo::bar::baz::g()" << std::endl;
        f(obj); // 通过ADL定位到foo::bar::baz::B::f
    }

    // foo::bar::baz::f的定义
    void f(B obj)
    {
        std::cout << "In foo::bar::baz::f()" << std::endl;
        std::cout << "Value of private member id is " << obj.id << std::endl; // 访问B类的私有成员id
        std::cout << "Value of protect member MASK is " << obj.MASK << std::endl; // 访问B类的保护成员protect
    }   

    // foo::bar::baz::h的定义
    void h(B::C para)
    {
        std::cout << "In foo::bar::baz::h" << std::endl;
    } // foo::bar::baz::h的定义
    // foo::bar::baz::f, foo::bar::baz::g和foo::bar::baz::h现在可以通过命名空间访问了
    // 并且它们是两个类foo::bar::baz::B和foo::bar::baz::C的友元函数
}

/* 命令空间扩展 */
namespace foo
{
    // 嵌套的命名空间
    namespace bar
    {
        namespace baz
        {
            int qux = 42;
            struct Book
            {
                int price;
                std::string name;
            };
        }

        /* 引入全局/匿名/其他命名空间中的函数 */
        using ::f;        // 必须以::打头
        using ::g;        // 引入匿名空间中的g，现在成为foo::bar::g
        using A::h;       // 引入A中的h函数
    }
}
namespace fbz = foo::bar::baz; // 命名空间别名
using qBook = fbz::Book ; //类型别名





