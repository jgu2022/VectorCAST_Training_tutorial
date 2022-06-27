#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class movedemo{
public:
    movedemo():num(new int(0)){
        cout<<"construct!"<<endl;
    }
    //�������캯��
    movedemo(const movedemo &d):num(new int(*d.num)){
        cout<<"copy construct!"<<endl;
    }
    //�ƶ����캯��
    movedemo(movedemo &&d):num(d.num){
        d.num = NULL;
        cout<<"move construct!"<<endl;
    }
	
	void test_move( void );
	
public:     //����Ӧ���� private��ʹ�� public ��Ϊ�˸�����˵������
    int *num;
};




void movedemo::test_move(void)
{
    std::string str = "Hello";
    std::vector<std::string> v;
    //���ó���Ŀ������캯�����½��ַ����飬��������
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";
}
