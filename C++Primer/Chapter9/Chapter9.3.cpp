#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter9.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��11��9�� ������
> Last edited time: 2018��11��9�� ������
> Topic:C++Primer Chapter9.3 ˳����������
************************************************************************/

#include "header_include.h"

using namespace std;

//9.3 ˳����������
//Sequential Container Operations

//9.3.1 ��˳���������Ԫ��
void Fun_Adding_Elements_to_a_Sequential_Container()
{
	//��һ��vector ��string �� deque����Ԫ�ػ�������ָ�������ĵ����������ú�ָ��ʧЧ

	//ʹ��push_back

	//string str = "hello world";
	//str.push_back('!');			//�ȼ���str += 's'

	//��һ�������ʼ������ʱ����һ��������뵽������ʱ��ʵ���Ϸ��뵽�����е��Ƕ���ֵ��һ������
	//����������Ԫ�ص��κθı䲻��Ӱ�쵽ԭʼ���󣬷�֮��Ȼ


	//ʹ��push_back
	//list<int> ilist;
	//for (size_t ix = 0; ix != 4; ++ix)
	//	ilist.push_front(ix);

	//for (auto i : ilist)
	//{
	//	cout << i << "  ";
	//}
	
	//deque��vectorһ���ṩ���������Ԫ�ص������������ṩ��vector����֧�ֵ�push_front��
	//deque��֤��������β���в����ɾ��Ԫ�صĲ��������ѳ���ʱ��
	//��vectorһ������deque��β֮���λ�ò���Ԫ�ػ�ܺ�ʱ


	//�������е��ض�λ�����Ԫ��
	//vector��deque��list��string��֧��insert��Ա

	//���뷶Χ��Ԫ��
	//��������ʾҪ�����ķ�Χ������ָ�����Ԫ�ص�Ŀ������
	list<int> ilist;
	vector<int>  v = { 1, 2, 3, 4 };
	auto i = ilist.insert(ilist.begin(), v.end() - 2, v.end());
	cout << *i << endl;
	
	//ʹ��insert�ķ���ֵ
	list<string> lst;

}

//9.3


//9.3


//9.3




int main()
{
	//9.3.1 ��˳���������Ԫ��
	Fun_Adding_Elements_to_a_Sequential_Container();

	return 0;
}