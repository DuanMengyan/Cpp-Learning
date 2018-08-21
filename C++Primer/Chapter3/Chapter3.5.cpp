#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter3.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年08月21日 星期二
> Last edited time: 2018年8月21日 星期二
> Topic:C++Primer Chapter3.5 数组
************************************************************************/



#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::vector;
using std::string;

//3.5.1定义和初始化数组
void Fun_arrays_define_initial()
{
	 
}


//3.5.2访问数组元素
void Fun_arrays_element()
{
	//unsigned scores[11] = {};
	//unsigned grade;
	//while (cin >> grade)
	//{
	//	if (grade <= 100)
	//		++scores[grade / 10];
	//}
	//for (auto i : scores)
	//	cout << i << "   ";
	//cout << endl;


	//ex3.31
	//unsigned array_a[10];
	//for (unsigned i = 0; i < 10; i++)
	//{
	//	array_a[i] = i;
	//	cout << array_a[i]<<"   ";
	//}
	//cout << endl;

	//ex3.32
	//unsigned array_b[10];
	//for (unsigned i : a)
	//{
	//	array_b[i] = array_a[i];
	//	cout << array_b[i] << "   ";
	//}
	//cout << endl;

	vector<unsigned> vec_a(10, 0);
	unsigned i = 0;
	for (auto &a : vec_a)
	{
		a = i++;
		cout << a << "   ";
	}
	cout << endl;
	vector<unsigned> vec_b = vec_a;
	for (auto b : vec_b)
	{
		cout << b << "   ";
	}
	cout << endl;
}


int main()
{
	Fun_arrays_element();

	return 0;
}