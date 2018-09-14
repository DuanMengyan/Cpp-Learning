#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月14日 星期五
> Last edited time: 2018年9月14日 星期五
> Topic:C++Primer Chapter6.6 函数匹配
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;

//ex6.51
void f()
{
	cout << "f():null" << endl;
}
void f(int val)
{
	cout << "f(int): f(" << val << ")" << endl;
}
void f(int val1, int val2)
{
	cout << "f(int,int): f(" << val1 <<","<< val2 << ")" << endl;
}
void f(double val1, double val2= 3.14)
{
	cout << "f(double,double = 3.14): f(" << val1 << "," << val2 << ")" << endl;
}

// 函数匹配
void Fun_function_matching()
{
	//候选函数
	//与被调用的函数同名
	//其声明在调用点可见

	//可行函数，能被所给实参调用的函数

	//含有多个形参的函数匹配
	//编译器在可行函数中依次检查每个实参，以寻找最佳匹配
	//如果检查了所有实参之后，没有那个函数脱颖而出，则该调用是错误的，报告二义性调用的信息


	//ex6.50
	//(a)调用二义性
	//(b)f(int)
	//(c)f(int,int)
	//(d)f(double,double = 3.14)
	//

	//ex6.51
	//f(2.56, 42);			//调用二义性
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}

//6.6.1 实参类型转换
void Fun_Argument_Type_Conversions()
{
	//所有算数类型转换的级别都一样

	//函数匹配和const实参

	//ex6.52
	//void mainp(int, int);
	//double dobj;
	//(a)类型提升，char提升为int
	//(b)double类型转为int

	//ex6.53
	//(c)不合法，形参都是char*
}


int main()
{
	Fun_function_matching();
	return 0;
}