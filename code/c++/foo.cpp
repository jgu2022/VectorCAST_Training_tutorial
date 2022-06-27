using namespace std;
#include <iostream>


namespace {

class local_class {
public:
    void test() {
        std::cout << "test from foo.cpp" << std::endl;
    }
};

}



namespace test{
class foo {
public:
    foo();
};






foo::foo() {
    local_class l;
    l.test();
}

}
