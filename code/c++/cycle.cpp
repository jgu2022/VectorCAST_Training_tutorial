#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<list>
#include<mutex>
#include <algorithm>  


using namespace std;
std::vector<int> array = { 1, 2, 3, 4, 5 };

void test_for(std::vector<int> my_array)
{

for (auto it = my_array.begin(); it != my_array.end(); ++it)
    
    {
            *it *= 2;
            if (*it<10){
            
            continue ;
            }                        
            cout << *it<< "输出大于10的值" ;
    }
}

 
int test_continue ()
{
   // 局部变量声明
   int a = 10;

   // do 循环执行
   do
   {
       if( a == 15)
       {
          // 跳过迭代
          a = a + 1;
          continue;
       }
       cout << "a 的值：" << a << endl;
       a = a + 1;
   }while( a < 20 );
 
   return 0;
}

int test2 ()
{
   // 局部变量声明
   int a = 10;

   // do 循环执行
   do
   {
       cout << "a 的值：" << a << endl;
       a = a + 1;
       if( a > 15)
       {
          // 终止循环
          break;
       }
   }while( a < 20 );
 
   return 0;
}

struct Sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};
 
 std::vector<int> nums{3, 4, 2, 8, 15, 267};
 
int test(std::vector<int> num)
{
    
 
    auto print = [](const int& n) { std::cout << " " << n; };
 
    std::cout << "before:";
    std::for_each(nums.cbegin(), nums.cend(), print);
    std::cout << '\n';
 
    std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });
 
    // calls Sum::operator() for each number
    Sum s = std::for_each(nums.begin(), nums.end(), Sum());
 
    std::cout << "after: ";
    std::for_each(nums.cbegin(), nums.cend(), print);
    std::cout << '\n';
    std::cout << "sum: " << s.sum << '\n';
}



