#include <string>
// make_exception_ptr example
#include <iostream>       // std::cout
#include <exception>      // std::make_exception_ptr, std::rethrow_exception
#include <stdexcept>      // std::logic_error

using namespace std;

int basic_test(){
	
    string str = "this is UT test";

    try{
        char ch2 = str.at(5);
        cout<<ch2<<endl;
    }
	catch(exception &e){  
        cout<<"out of bound!"<<endl;
	}
	try{
	cout<<"This statement will not be executed."<<endl;	
	}	
	catch(const char* &e){
        cout<<e<<endl;
    }
    return 0;
}
 
void handle_eptr(std::exception_ptr eptr) // passing by value is ok
{
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}



int make_excep_test () {
  auto p = std::make_exception_ptr(std::logic_error("logic_error"));

  try {
     std::rethrow_exception (p);
  } catch (const std::exception& e) {
     std::cout << "exception caught: " << e.what() << '\n';
  }
  return 0;
}

