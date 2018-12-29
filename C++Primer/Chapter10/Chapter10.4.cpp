#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��28�� ������
> Last edited time: 2018��12��28�� ������
> Topic:C++Primer Chapter10.4 ��̽������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"


using namespace std;
using namespace std::placeholders;		//����ռλ��


//10.4 ��̽������
//��ͷ�ļ�iterator�л������˼��ֶ���ĵ�����




//ex10.4.1 ���������
void Fun_Insert_Iterators()
{
	//�����������������������Ԫ��
	//vector<int> vec;
	//auto it = vec.begin();
	//for (int i = 0; i < 5; ++i)
	//{
	//	it = vec.insert(it, i);
	//	//it++;
	//}	
	//printitem(vec);

	//list<int> lst = { 1,2,3,4 };
	//list<int> lst2 = { 5,6 }, lst3 = { 5,6 }, lst4 = { 5,6 };
	//copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	//copy(lst.cbegin(), lst.cend(), back_inserter(lst3));
	//copy(lst.cbegin(), lst.cend(), inserter(lst4,lst4.begin()));
	//printitem(lst2);		//4   3   2   1   5   6
	//printitem(lst3);		//5   6   1   2   3   4
	//printitem(lst4);		//1   2   3   4   5   6


	//ex10.26
	//front_iterator��Ԫ�ز���������ͷ������µ���Ԫ��
	//back_iterator��Ԫ�ز�������ĩβ
	//insert��Ԫ�ز��뵽ָ����������ʾ��Ԫ��֮ǰ


	//ex10.27
	//vector<int> vec = { 1,2,3,4,5,5,1,6,6,7,8,2 };
	//list<int> lst;
	//sort(vec.begin(),vec.end()); printitem(vec);
	//unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));	//��ͬ������Ԫ�أ�ֻ����һ��
	//printitem(lst);

	//ex10.28
	//vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//vector<int> vec1, vec2;
	//list<int> lst3;
	//copy(vec.cbegin(), vec.cend(), inserter(vec1, vec1.begin()));		//123456789	
	//printitem(vec1);
	//copy(vec.cbegin(), vec.cend(), back_inserter(vec2));				//123456789
	//printitem(vec2);
	////front_inserter��������vector
	//copy(vec.cbegin(), vec.cend(), front_inserter(lst3));				//987654321
	//printitem(lst3);
}




//ex10.4.2
//ex10.4.3





int main()
{
	//ex10.4.1 ���������
	Fun_Insert_Iterators();

	return 0;
}