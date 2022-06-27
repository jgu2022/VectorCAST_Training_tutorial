
#include "stack.h"

using namespace std;

int main()
{
  using IntStack = Stack<int>; // typedef Stack<int> IntStack
  IntStack intStack; // Stack<int> intStack
  intStack.push(42);
  std::cout << intStack.top(); // 42
  Stack<std::string> stringStack;
  stringStack.push("hi");
  std::cout << stringStack.top(); // hi
  stringStack.pop();
}


struct umi_B
{
int age;
int get_age();
};
class C
{
public:
const int age_;
C(umi_B* a):age_(a->get_age()){}
int test()
{
return this->age_;
}

};