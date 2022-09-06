#include <iostream>
#include<initializer_list>
#include<cstdarg> 

using namespace std;

/*
下面给出一个例子，需要注意的是，含有initializer_list形参的函数也可以同时拥有其他形参。另外，如果想给initializer_list形参传递一个实参的序列，必须把序列放在一对花括号内：
*/
string func(initializer_list<string> li)
{
	string str;
	for(auto beg=li.begin(); beg!=li.end(); ++beg)
		str += *beg;
	return str;
}

/*
函数可以用省略符形参”…”表示不定参数部分，省略符形参只能出现在形参列表的最后一个位置，它的形式如下：

// va_list是一种数据类型，args用于持有可变参数。
// 定义typedef char* va_list;
va_list args;

// 调用va_start并传入两个参数：第一个参数为va_list类型的变量
// 第二个参数为"..."前最后一个参数名
// 将args初始化为指向第一个参数（可变参数列表）
va_start(args, paramN);

// 检索参数，va_arg的第一个参数是va_list变量，第二个参数指定返回值的类型
// 每一次调用va_arg会获取当前的参数，并自动更新指向下一个可变参数。
va_arg(args,type);

// 释放va_list变量
va_end(args);

*/

int cal_nums(char *name,  int count,...)
{
    cout<< *name <<"name";

	int result[count];
	
	va_list args;
	va_start(args, count);
	for(int i=0; i<count; ++i)
		result[i]= va_arg(args, int);
	va_end(args);
    if (count ==3){
        if (result[0]==1){
            cout<<"result[0] 值正确";
        }
        if (result[1]==2){
            cout<<"result[1] 值正确";
        }
        if (result[2]==3){
            cout<<"result[2] 值正确";
        }		
	}
	return 0;
}

int add_nums(int count,...)
{
	int result=0;
	
	va_list args;
	va_start(args, count);
	for(int i=0; i<count; ++i)
		result+= va_arg(args, int);
	va_end(args);
	return result;
}

/*一个可变参数模板（variadic template）就是一个接受可变数目参数的模板函数或模板类。可变数目的参数被称为参数包（parameter packet）。存在两种参数包：模板参数包（表示零个或多个模板参数）和函数参数包（表示零个或多个函数参数）。
可变参数函数模板通常是递归的。第一步调用处理包中的第一个实参，然后用剩余的实参调用自身。为了终止递归，我们还需要定义一个非可变参数的函数模板：
*/


template <typename T>
void print(const T &t)
{
	cout << t;
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename...Args>
void print(const T &t, const Args&...rest)
{
	cout << t << " ";     // 打印第一个实参
	print(rest...);       // 递归调用，打印其他实参
}


/* 使用借助初始化列表来实现的方式，虽然可以定义一个接受可变数目实参的函数，但这些参数必须具有同一类型 使用可变模版参数的关键是如何展开参数包 */

template<typename T>
void Print_2(T t) {
    std::cout << "end: " << t << std::endl;
}

template<typename ... Args>
void Print_2 (Args ... args)
{
    //逗号表达式+初始化列表
    int arr[] = { (Print_2(args), 0)... };
}

/*wrapper函数来调用可变长形参的函数(wrapper主要用于调用其他函数的函数)*/
// int test_1()
// {
	// cout << func({"This"," ","is"," ","C++"}) << endl;
	// cout << add_nums(4, 25, 25, 50, 50) << endl;
	// print("string1", 2, 3.14f, "string2", 42);
	// Print_2(1, 2, 3); 
	// return 0;
// }