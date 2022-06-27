#include  "people.h"

using namespace std;

People::People (int postcode){
	
	m_postcode = postcode;
	
}
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
void People::display(){
      cout<<"m_age: "<<m_age<<endl; 
      cout<<"m_name: "<<m_name<<endl;
    }






