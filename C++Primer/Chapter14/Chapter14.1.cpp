#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter14.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年4月22日 星期一
> Last edited time: 2019年4月23日 星期二
> Topic:C++Primer Chapter14.1 基本概念
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"
#include "Book.h"

using namespace std;

void Fun_Basic_Concepts()
{

	/*
	对于一个运算符来说，它或者是类的成员，或者至少包含有一个类类型的参数
	当运算符作用于内置类型的运算对象时，我们无法改变该运算符的含义
	*/

	//通常情况下不应该重载逗号、取地址、逻辑或和逻辑与运算符	
	//因为&&和||运算符的重载版本无法保留内置版本运算符的短路求值属性，两个运算对象总是会被求值。

	//使用与内置类型一致的含义
	//赋值和复合赋值运算符
	
	//选择作为成员或者非成员
	//具有对称性的运算符可能任意一端的运算对象，例如算术、相等性、关系和位运算符等，
	//因此他们通常应该是普通的非成员函数
	//当我们把运算符定义成类的成员函数时，它的左侧运算对象必须是运算符所属类的一个对象

	//ex14.1
	
	//区别
	//1.重载的运算符函数可以以函数形式直接调用，也可以以运算符的形式使用。
	//2.重载的运算符函数必须是类的成员，或者至少有一个类类型的参数。
	//3.一些运算符保留了运算对象的求值顺序。 
	//这些运算符的重载版本无法保留内置版本运算符的短路求值属性，两个运算对象总是会被求值。重载它们通常是一个坏主意。

	//相同
	//重载运算符与相应的内置运算符具有相同的优先级和关联性。

	//ex14.2
	//Sales_data book1("XXX", 5, 20.0), book2("XXX", 5, 25.0);
	//Sales_data book3(book1 + book2);
	//cout << book3 << endl;
	//Sales_data book4;
	//cin >> book4;
	//cout << book4 << endl;
	
	//ex14.3
	//(A)内置版本的==
	//(B)string重载版本的==
	//(C)vector重载版本的==
	//(D)string重载版本的==
	//
	
	//ex14.4
	//(a)非类成员，对称性的运算符
	//(b)类成员，复合赋值运算符
	//(c)类成员，改变对象状态的运算符，递增运算符
	//(d)类成员，成员访问箭头，必须是类成员
	//(e)非类成员，
	//(f)非类成员
	//(g)非类成员，对称性的运算符
	//(h)类成员，赋值、下标、调用和成员访问文箭头必须是类成员


	//ex14.5
	Book b1(cin), b2(cin);
	cout << b1 << b2;
	if (b1 == b2) cout << "two same books" << endl;
}



int main()
{
	//Chapter14.1
	Fun_Basic_Concepts();
	return 0;
}