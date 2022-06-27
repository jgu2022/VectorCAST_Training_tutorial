#include <iostream>

using namespace std;

class B
{
public:
    B() { };
    const int getData() const{
    return num;
    };
public:
    int num {5};
};

void foo( const B& b)
{  
    if (b.getData()==5){
    
	cout<<"return value is true";
    
    }else{
    
	cout<<"return value is true";
    
    }
    if(b.num ==5){
    
        cout<<"value is right";
        
    }else{
        
        cout<<"value is wrong";
    }
   
}


struct data_csv{
	
	int a;
	int b;
	int c;	
};


const volatile struct data_csv object ={0,0,0};

int test_const(){
	
	if ( object.a ){
		
		printf("true");
		
	}else{
		
		printf("false");		
	}	
}

const volatile int flag=0;

int test_const_2(){

	if ( flag){
		
		printf("true");
		
	}else{
		
		printf("false");		
	}

}


