/*************************************************************************
> File Name: C++����Day02.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��06��26�� ���ڶ�
> Topic:namespace��iostream��ʷ
************************************************************************/




#include "iostream"
using namespace std;

//���������ռ�
namespace namespaceA
{
	int a = 10;
}

namespace namespaceB
{
	int a = 20;
	namespace namespaceC   //�����ռ�Ƕ��
	{

		int b = 30;
		struct teacher
		{
			char name[20];
			int age = 25;
		};
	}
}

int main()
{
	using namespace namespaceA;
	cout << namespaceB::a << endl;
	using namespace namespaceB;
	cout << namespaceB::a << endl;


	using namespace namespaceB::namespaceC; //���������ռ�
	//using  namespaceB::namespaceC::teacher;  //ֱ�����ñ���
	teacher teacher1;
	cout << teacher1.name << endl;
	cout << teacher1.age << endl;
	cout << b << endl;

}

