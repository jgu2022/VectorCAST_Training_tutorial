#ifndef PEOPLE_H
#define PEOPLE_H

#include<iostream>
using namespace std;
//基类People
class People{
public:
    People (int postcode);
    void setname(char *name);
    void setage(int age);
    void display();
public:
    char *m_name;
    int m_age;
	int m_postcode;

};


#endif
