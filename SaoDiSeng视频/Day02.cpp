/*************************************************************************
> File Name: C++基础Day02.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年06月26日 星期二
> Topic:namespace和iostream历史
************************************************************************/




#include "iostream"
using namespace std;

//定义命名空间
namespace namespaceA
{
	int a = 10;
}

namespace namespaceB
{
	int a = 20;
	namespace namespaceC   //命名空间嵌套
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


	using namespace namespaceB::namespaceC; //引用命名空间
	//using  namespaceB::namespaceC::teacher;  //直接引用变量
	teacher teacher1;
	cout << teacher1.name << endl;
	cout << teacher1.age << endl;
	cout << b << endl;

}

