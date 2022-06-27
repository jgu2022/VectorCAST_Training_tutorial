#include  "student.h"

using namespace std;

Student::Student(int postcode) : People( postcode ){}

void Student::setscore(float score){
	m_score = score; 
	cout<<"m_score: "<<m_score<<endl; //
	}
	
	
Student1::Student1(int postcode) : People( postcode ){}

void Student1::display_1( ) 
   {
      display();//Call base class member function to output member variable
      cout<<"ranking: "<<ranking<<endl; //
   } 




