#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月10日 星期一
> Last edited time: 2018年9月11日 星期二
> Topic:C++Primer Chapter6.4 函数重载
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;


const string &shorterString(const string &s1, const string &s2)
{
	cout << "const string" << endl;
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
	cout << "string" << endl;
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

int *reset(int *val)
{
	*val = 5;
	return val;
}

//double * reset(double *val)
//{
//	*val = 5.5;
//	return val;
//}
//函数重载
void Fun_Overloaded_Functions()
{
	//const_cast 和重载
	//string str1 = "hello,C++", str2 = "hello,python";
	//const string& re = str1;
	//shorterString(str1, str2) = "AAA";
	//cout << str1 << endl;

	//调用重载函数三种可能
	//(1)找到一个最佳匹配
	//(2)未找到匹配
	//(3)二义性调用

	//ex6.39
	//(a)合法，重复声明是合法的
	//(b)非法，除了返回类型，其他都一样
	//(c)合法，

	int num = 6;
	int *p = reset(&num);
	cout << num << endl;


}


int main()
{
	Fun_Overloaded_Functions();
	return 0;
}


