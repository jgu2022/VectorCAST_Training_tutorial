#include<iostream>
#include<vector>
#include<string>
#include <map> 
#include <array>

using namespace std;
struct StuInfor
{
	int num;
	string name;
	double height;
};
void Read(vector<StuInfor>&stu, int n)
{
	cout << "����������ѧ����ѧ�š�����������ߣ�" << endl;

		cin >> stu[0].num;
		cin >> stu[0].name;
		cin >> stu[0].height;
	
}
StuInfor FindHi(vector<StuInfor>stu, int n)
{
	int flag1 = 0;
	double highest = 0;
	for (int i = 0; i != n; ++i)
	{
		if (highest < stu[i].height) {
			highest = stu[i].height;
			flag1 = i;
		}
		if (highest == stu[i].height && stu[flag1].num > stu[i].num) {
			flag1 = i;
		}
	}
	return stu[flag1];
}


int Readmap( map<int, int>&myMap ) {
    //��������ʼ�� map ����
    //���� begin()/end() ��ϣ����� map ����
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}


int main()
{
	int n;
	StuInfor s;
	cout << "������ѧ��������" << endl;
	cin >> n;
	vector<StuInfor>stu(n);
	Read(stu, n);
	s = FindHi(stu, n);
	cout << "��ߵ�ѧ����Ϣ���£�" << endl;
	cout << "ѧ�ţ�" << s.num << endl;
	cout << "������" << s.name << endl;
	cout << "��ߣ�" << s.height <<"cm"<<endl;
	return 0;
}


int test_arry( std::array<int,4> values )
{
    //��ʼ�� values ����Ϊ {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }
    //ʹ�� get() ���غ������ָ��λ��Ԫ��
    cout << get<3>(values) << endl;
    //���������Ϊ�գ���������������е�Ԫ��
    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {
            cout << *val << " ";
        }
    }
}

struct CELL{
	
	int a;
	float f;
};

typedef struct CELL t_CELL;

class Test_arry{
	
	
public: 

    
	std::array<t_CELL,4> cells;
	

};
