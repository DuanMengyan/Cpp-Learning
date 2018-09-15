#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter6.7.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月14日 星期五
> Last edited time: 2018年9月15日 星期六
> Topic:C++Primer Chapter6.6 函数指针
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

bool lengthCompare(const string &, const string &);

//void ff(int*);
//void ff(unsigned int);
//void (*pf1)(unsigned int) = ff;

//第三个形参是函数类型，它会自动转换成指向函数的指针
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &)); 
//等价声明：显式地将形参定义成指向函数的指针
void useBigger(const string &s1, const string &s2, bool(*pf)(const string &, const string &));


//Func和Func2是函数类型
typedef bool Func(const string&, const string &);
typedef decltype(lengthCompare) Func2;
//FuncP和FuncP2是指向函数的指针
typedef bool(*FuncP)(const string&,const string&);
typedef decltype(lengthCompare) *FuncP2;

void useBigger(const string &s1,const string &s2,Func);//编译器自动将Func表示的函数类型转换成指针
void useBigger(const string &s1, const string &s2, FuncP2);

//使用类型别名，声明一个返回函数指针的函数
using F = int(int*, int*);
using PF = int(*)(int*, int);

int(*f1(int)) (int*, int);  
auto f1(int)->int(*)(int * ,int);

PF f1(int);
F* f2(int);
//F f3(int);   //不允许使用返回函数的函数


//ex6.54
int func(int a, int b)
{
	cout << "hello" << endl;
	return a + b;
}

using pFunc1 = decltype(func);			//函数
typedef decltype(func) *pFunc2;			//函数指针
using pFunc3 = int(*)(int a, int b);	//函数指针
using pFunc4 = int(int a, int b);		//函数
typedef int(*pFunc5)(int a, int b);		//函数指针
using pFunc6 = decltype(func);			//函数

//ex6.55
int add(int a, int b)
{
	cout << "add:" << endl;
	return a + b;
}

int subtract(int a, int b)
{
	cout << "subtract:" << endl;
	return a - b;
}
int multiply(int a, int b)
{
	cout << "multiply:" << endl;
	return a * b;
}
int divide(int a, int b)
{
	cout << "divide:" << endl;
	return (b == 0) ? 0 : a / b;
}


//函数指针
void Fun_Pointers_to_Functions()
{
	//要声明一个可以指向函数的指针，只需要用指针替换函数名即可

	//使用函数指针
	//当把函数名作为一个值使用时，该函数自动的转换成指针
	//还能直接使用指向函数的指针调用该函数，无需提前解引用指针

	//重载函数的指针
	//使用重载函数时，上下文必须清晰地界定到底应该选用哪个函数
	//编译器通过指针类型决定选用哪个函数，指针类型必须与重载函数中的某一个精确匹配

	//函数指针形参
	//可以直接把函数作为实参使用，此时它会自动转换成指针

	//返回指向函数的指针

	//将auto和decltype用于函数指针类型

	//ex6.54
	//vector<int(*)(int, int)> fun_vec;
	//fun_vec.push_back(func);

	//vector<pFunc6*>fun_vec2;
	//fun_vec2.push_back(func);

	//vector<pFunc5> fun_vec3;
	//fun_vec3.push_back(func);

	//int sum = fun_vec2[0](5, 6);
	//cout << sum << endl;


	//ex6.55-ex6.56
	vector<int(*)(int, int)> fun_vec;
	fun_vec.push_back(add);
	fun_vec.push_back(subtract);
	fun_vec.push_back(multiply);
	fun_vec.push_back(divide);
	cout << fun_vec[0](5, 6) << endl;
	cout << fun_vec[1](8, 6) << endl;
	cout << fun_vec[2](5, 6) << endl;
	cout << fun_vec[3](30, 6) << endl;
}



int main()
{
	Fun_Pointers_to_Functions();
	return 0;
}