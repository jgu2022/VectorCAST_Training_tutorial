#include <iostream>
#include <functional>

//std::function as input parameter

void call_when_event(int event, const std::function<void(int)>& f)
{
	if( !(event & 1) )
	{
		f(event);
		std::cout<<"event"<<std::endl;		
	}	
}



//classB注册一个成员函数作为回调函数到classA中，classA会保存这个回调函数（std::function对象）到成员变量中，用于后面使用，


class classA
{
       
typedef std::function<void(int i)> callback_t;

public:
    classA() {}
    ~classA() {}
    
    void handle(int i)
    {
        std::cout << "classA::handle" << std::endl;
        
        cbHandle(i);
    }

    void registCb(callback_t func)
    {
    	cbHandle = std::move(func);
    }
    
private:
    callback_t cbHandle;
};


class classB
{
       
public:
    classB(classA& cA) 
    {       
        cA.registCb([this](int i){classB::handle(i);});
    }
    ~classB() {}
    
    void handle(int i)
    {
        std::cout << "classB, handle message" << i << std::endl;
    }
};



int main(void){
	
    	classA testa;
     	classB testb(testa);

    	testa.handle(10);		
	return 0;
}


