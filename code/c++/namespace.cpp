#include <typeinfo>
#include <typeindex>
#include "namespace.h" 
using std::cout; // 只引入std命名空间中的cout和endl
using std::endl;

/* 场景一                         */
/* 访问命名空间中的类型，函数和变量 */
void test_namespace_members()
{
    f(); // 全局空间的f()
    g(); // 匿名空间的g()
    cout << "A::val is " << A::val << endl;  // 访问A::val
    A::B ab; // 访问inline命名空间内成员，内联命名空间名foo可以省略
    ab.size = 1;
    cout << "Member 'size' of A::B instance is " << ab.size << "\n" << endl;

    // 调用foo::bar::baz命名空间中声明为friend的函数
    fbz::B objB; // foo::bar::baz::B类
    fbz::f(objB); // foo::bar::baz::f
    fbz::g(); // foo::bar::baz::g
    fbz::B::C objC; // foo::bar::baz::B::C
    fbz::h(objC); // foo::bar::baz::h是C的友元函数，可以访问C类型中的私有和保护成员
}

/* 场景二 */
/* 重名与重载 */
void test_overloading()
{
    // 定义一个临时的函数
    using fbz::f;   // 引入foo::bar::baz中的函数f(B)
    void f(char); // f(char)和f(B)入参类型不同，属于函数重载
    fbz::B obj;
    f(obj);  // 调用foo::bar::baz::f(B)
 
    using fbz::g; // 同时引入foo::bar::baz中的struct g， g()，g(char)
    g();          // 调用foo::bar::baz::g()
    g('a');       // 调用foo::bar::baz::g(char)
    struct g g1;  // 声明g1类型为结构体foo::bar::baz::g
 
    using A::Book;   // 引入A::Book变量
    using fbz::Book; // 引入foo::bar::baz::Book结构体
    struct Book bk1; // 声明bk1为foo::bar::baz::Book结构体类型的变量
    cout << typeid(Book).name() << endl; // 查看Book的类型，为int
    Book = 99;       // 赋值给A::Book
    cout << typeid(fbz::Book).name() << endl; // 查看fbz::Book的类型
}

/* 场景三     */
/* 引入的命名空间中有同名的类导致歧义 */
void test_type_ambigous()
{
    #ifdef WITH_ERROR
    using namespace A; // 命名空间A和foo::bar::baz::B都有类B会导致歧义
    // using A::h;
    #endif
    int val;
    using namespace fbz; // 下文只用到B类，使用using fbz::B只引入B更合适
    B obj(1);  // 直接使用B表示foo::bar::baz::B；使用全名foo::bar::baz::B则可以避免歧义的发生 
}

int main()
{
    test_namespace_members();
    test_overloading();
    test_type_ambigous();
    return 0;
}

