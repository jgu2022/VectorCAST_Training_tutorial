#include <vector>
#include <iostream>
#include <cassert>
#include <memory>
#include <iostream>
#include <exception>
#include <utility>
#include <queue>
#include <deque>
#include <string>
#include <functional>
#include <algorithm>
#include <tuple>
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>




using namespace std;

class farther{

public:

int _age;

public :

farther(int age):_age(age){};

virtual int get_age( void ) const = 0;		
	
};

class son : public farther
{
public:

int _s_age;

public: 
	son(int a ): farther(a){};
	
	int get_age( void )const 
	{
		return _s_age;
    }
	
};

class person{
	
private:

static std::unique_ptr<farther> rich_farther; 

public :

void get_farther_age( std::unique_ptr<farther> p_f ){
	
	if (p_f==nullptr)
	{
		cout<<" nothing";
	}else
	{
		cout<<"got age information";
	
	}	
}	
};


class A
{
public:
    int i;
    A(int n):i(n) { };
    ~A() { cout << i << " " << "destructed" << endl; }
};


int shared_ptr_test(std::shared_ptr<A> ptr1,std::shared_ptr<A> ptr2,unsigned int n)
{
  if (ptr1 == nullptr)
  {
    return -1;
  }
  if (n == 1)
  {
      auto sp1(ptr1); //ptr1的关联指针交由sp1托管
      return sp1->i;
  }
  else if (n == 2)
  {
    auto sp1(ptr1); //ptr1的关联指针同时交由sp1托管
    auto sp2(ptr2); //ptr2的关联指针同时交由sp2托管
    sp1.reset();
    sp1 = ptr2;//ptr2的关联指针交由sp1托管
    cout << ptr1->i << ptr2->i <<endl;
    return ptr2->i;
  }
  else
  {
    cout << "n must be 1 or 2" <<endl;
    return -2;
  }
}

int unique_ptr_test(std::unique_ptr<A> ptr1) 
{
  int ret = 0;
  auto struct_ptr_2 = std::move(ptr1); 
  if (ptr1 == nullptr)
  {
    cout << "ptr1 is empty pointer"<<endl;
  }
  ret = struct_ptr_2->i;
  return ret;
}







