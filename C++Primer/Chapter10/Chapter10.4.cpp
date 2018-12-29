#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月28日 星期五
> Last edited time: 2018年12月28日 星期五
> Topic:C++Primer Chapter10.4 再探迭代器
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"


using namespace std;
using namespace std::placeholders;		//引用占位符


//10.4 再探迭代器
//在头文件iterator中还定义了几种额外的迭代器




//ex10.4.1 插入迭代器
void Fun_Insert_Iterators()
{
	//插入迭代器用来向容器插入元素
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
	//front_iterator将元素插入容器开头，变成新的首元素
	//back_iterator将元素插入容器末尾
	//insert将元素插入到指定迭代器表示的元素之前


	//ex10.27
	//vector<int> vec = { 1,2,3,4,5,5,1,6,6,7,8,2 };
	//list<int> lst;
	//sort(vec.begin(),vec.end()); printitem(vec);
	//unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));	//相同连续的元素，只复制一个
	//printitem(lst);

	//ex10.28
	//vector<int> vec = { 1,2,3,4,5,6,7,8,9 };
	//vector<int> vec1, vec2;
	//list<int> lst3;
	//copy(vec.cbegin(), vec.cend(), inserter(vec1, vec1.begin()));		//123456789	
	//printitem(vec1);
	//copy(vec.cbegin(), vec.cend(), back_inserter(vec2));				//123456789
	//printitem(vec2);
	////front_inserter不能用于vector
	//copy(vec.cbegin(), vec.cend(), front_inserter(lst3));				//987654321
	//printitem(lst3);
}




//ex10.4.2
//ex10.4.3





int main()
{
	//ex10.4.1 插入迭代器
	Fun_Insert_Iterators();

	return 0;
}