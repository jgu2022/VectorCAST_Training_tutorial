#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>
#include <unistd.h>
#include<string>
#include<vector>
#include<list>

using namespace std;

class DSV
{
    public:
       void init();
       void test();
static void* Thread(void* argv);
       int flg;
};

void DSV::test(){
cout<<"out of bound!"<<endl;
}

void* DSV::Thread(void* argv)
{
       DSV* handle = (DSV*)argv;
       
       // do something…
       handle->test();
 
       handle->flg;
 
       return 0;
}



