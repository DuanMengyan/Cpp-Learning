#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter9.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��29�� ����һ
> Last edited time: 2018��10��29�� ����һ
> Topic:C++Primer Chapter9.2 ���������
************************************************************************/

#include "header_include.h"

using namespace std;


//9.2 ���������
void Fun_Container_Library_Overview()
{
	//ex9.2
	list<deque<int>> int_deque_list{ {0,1,2}, {1,2,3}, {2,3,4} };
	for (auto &a : int_deque_list)
	{
		a.push_front(5);	//	����һ������5
	}
	for (auto a : int_deque_list)
	{
		for (auto b : a)
		{
			cout << b << "  ";		//��ӡ
		}
		cout << endl;
	}

}

//ex.9.4 -9.5
vector<int>::const_iterator SearchKey(vector<int>::const_iterator left, vector<int>::const_iterator right, int key)
{
	if (left > right)
	{
		cout << "Error!" << endl;
		return right;
	}
	else
	{
		while (left != right)
		{
			if (*left == key)
			{
				return left;
			}
			++left;
		}
		return right;

	}
}


//9.2.1 ������
void Fun_Iterators()
{
	//��������Χ����պ�����[begin,end��
	//end������begin֮ǰ
	//ʹ����պϷ�Χ�̺��ı�̼ٶ�
	
	//ex.9.3
	//begin��endָ��ͬһ�����е�Ԫ��
	//begin������������end

	//ex.9.4
	//vector<int> int_vec{ 1, 3, 5, 6, 8, 9, 7 };
	//auto begin = int_vec.cbegin(), end = int_vec.cend();
	//cout << SearchKey(begin, end, 6) << endl;
	
	//ex.9.5
	//vector<int> int_vec{ 1, 3, 5, 6, 8, 9, 7 };
	//auto begin = int_vec.cbegin(), end = int_vec.cend();
	//auto result = SearchKey(begin, end, 2);
	//if (result != end)
	//{
	//	cout << *result << endl;
	//}
	//else
	//{
	//	cout << "Can not find value!" << endl;
	//}

	//ex.9.6
	list<int> lst1;
	list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
	while (iter1 != iter2)
	{
		/*
		�����<δ��list��ʵ�֣�list��˫����������ڵ�ĵ�ַ��һ����������
		*/
	}



	//ex.9
}



//9.2.2
//9.2.3
//9.2.4
//9.2.5
//9.2.6
//9.2.7


int main()
{
	//9.2 ���������
	//Fun_Container_Library_Overview();
	//9.2.1 ������
	Fun_Iterators();
	return 0;
}