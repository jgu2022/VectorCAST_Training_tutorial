#ifndef STUDENT_H
#define STUDENT_H

#include "people.h"

using namespace std;

//派生类Student 共有继承public
class Student: public People{
public:
    Student (int postcode);
    void setscore(float score);
protected:
    float m_score;
};


//派生类Student1 私有继承private
class Student1: private People
{
public:
   Student1 (int postcode);
   void display_1( );
private:
   int ranking;
};
#endif