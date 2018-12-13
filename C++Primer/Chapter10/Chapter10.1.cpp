#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月13日 星期四
> Last edited time: 2018年12月13日 星期四
> Topic:C++Primer Chapter10.1 概述
************************************************************************/

#include "header_include.h"

using namespace std;

//Chapter10.1 概述
void Fun_Overview()
{
	//int val = 42;
	//vector<int> ivec = { 0,1,2,3,4,5,6,42,3,2,5,6 };
	//auto result = find(ivec.cbegin(), ivec.cend(), val);
	////find返回指向第一个等于给定值的元素的迭代器，如果没有，则返回二个参数，c.end()表示搜索失败
	//cout << "The value " << val
	//	<< (result == ivec.cend() ? " is not present " : " is present ") << endl;

	//可以用find在数组中查找值
	//使用标准库中的begin和end函数获得指向ia中首元素和尾元素之后位置的指针，并传递给find
	//int ia[] = { 27,210,12,47,109,83 };
	//int val = 83;
	//int *result = find(begin(ia), end(ia), val);

	//迭代器令算法不依赖于容器..........但算法依赖于元素类型的操作

	//ex.10.1
	//vector<int> ivec = { 1,2,4,5,10,25,2,4,10,15,1,2,10,2,1,0,10 };
	//int val = 10;
	//int val_count = count(ivec.cbegin(), ivec.cend(), val);
	//cout << "The value " << val
	//	<< " presents " << (val_count ? val_count : 0) << " times." << endl;

	//ex.10.2
	list<string> str_list = { "C++","Primer","hello","world","C++" };
	string str = "C++";
	int str_count = count(str_list.cbegin(), str_list.cend(), str);
	cout << "The string \"" << str
		<< "\" presents " << (str_count ? str_count : 0) << " times." << endl;



	//ex.10.

}




int main()
{

	//Chapter10.1 概述
	Fun_Overview();
	return 0;
}
