#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter9.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月29日 星期一
> Last edited time: 2018年10月29日 星期一
> Topic:C++Primer Chapter9.2 容器库概览
************************************************************************/

#include "header_include.h"

using namespace std;


//9.2 容器库概览
void Fun_Container_Library_Overview()
{
	//ex9.2
	list<deque<int>> int_deque_list{ {0,1,2}, {1,2,3}, {2,3,4} };
	for (auto &a : int_deque_list)
	{
		a.push_front(5);	//	插入一个整数5
	}
	for (auto a : int_deque_list)
	{
		for (auto b : a)
		{
			cout << b << "  ";		//打印
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


//9.2.1 迭代器
void Fun_Iterators()
{
	//迭代器范围：左闭合区间[begin,end）
	//end不能在begin之前
	//使用左闭合范围蕴含的编程假定
	
	//ex.9.3
	//begin和end指向同一容器中的元素
	//begin反复递增到达end

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
		运算符<未在list中实现，list是双向链表，链表节点的地址不一定是连续的
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
	//9.2 容器库概览
	//Fun_Container_Library_Overview();
	//9.2.1 迭代器
	Fun_Iterators();
	return 0;
}