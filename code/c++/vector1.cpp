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
	cout << "请依次输入学生的学号、姓名、和身高：" << endl;

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
    //创建并初始化 map 容器
    //调用 begin()/end() 组合，遍历 map 容器
    for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}


int main()
{
	int n;
	StuInfor s;
	cout << "请输入学生人数：" << endl;
	cin >> n;
	vector<StuInfor>stu(n);
	Read(stu, n);
	s = FindHi(stu, n);
	cout << "最高的学生信息如下：" << endl;
	cout << "学号：" << s.num << endl;
	cout << "姓名：" << s.name << endl;
	cout << "身高：" << s.height <<"cm"<<endl;
	return 0;
}


int test_arry( std::array<int,4> values )
{
    //初始化 values 容器为 {0,1,2,3}
    for (int i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }
    //使用 get() 重载函数输出指定位置元素
    cout << get<3>(values) << endl;
    //如果容器不为空，则输出容器中所有的元素
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
