#include <iostream>
using namespace std;

	class A {
	public:
		int x;
		
        A(){};
		
	    A(int x) : x(x)
	    {
		    cout << "Constructor" << endl;
	    }

		A(const A& a) : x(a.x)
		{
			cout << "Copy Constructor" << endl;
		}
	 
		A(A&& a) : x(a.x)
		{
			cout << "Move Constructor" << endl;
		}
		
		void member_func1( int a){
			
			x = a;
			cout << "test member function  TestA" << endl;	
		}
};



