#include <iostream>
#include <cstring>
#include <string>
#include <assert.h>

using namespace std;

class WR
{
public:

    WR(int num)
        :_num(num){
              
        }
    
	void set() 
	{
	    
        _total = _num+5;
	}
	
	int get() const 
	{
        return _total;
	}
	

private:
    int   _num;
    int   _total;
}; 




int test()
{

    static int num =10;
    WR wr_er(num);
    wr_er.set();
    
    assert( wr_er.get() == 15);

    return 0;
};



