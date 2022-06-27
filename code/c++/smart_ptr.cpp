#include <vector>
#include <iostream>
#include <cassert>
#include <memory>
using namespace std;


class A
{
public:
    int i;
    A(int n):i(n) { };
    ~A() { cout << i << " " << "destructed" << endl; }
};



int unique_ptr_test(std::unique_ptr<A> ptr1) 
{
  int ret = 0;

  if (ptr1 == nullptr)
  {
     cout << "ptr1 is empty pointer"<<endl;
  }
  else
  {
     ret = ptr1->i;
  }
  return ret;
}

int shared_ptr_test(std::shared_ptr<A> ptr1) 
{
  int ret = 0;

  if (ptr1 == nullptr)
  {
     cout << "ptr1 is empty pointer"<<endl;
  }
  else
  {
     ret = ptr1->i;
  }
  return ret;
}

void weak_ptr_test()
{

    auto pi = make_shared<int>(100);
    auto pia(pi);
    weak_ptr<int>piw(pi);
    int count = piw.use_count();
 
    pi.reset();
    pia.reset();
    if(piw.expired() )
    {
        cout <<"对象已经过期"<<endl;
    }
}




