#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月12日 星期五
> Last edited time: 2018年10月19日 星期五
> Topic:C++Primer Chapter7.5 构造函数再探
************************************************************************/

#include "header_include.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstddef>
//#include <cctype>
//#include <stdexcept>
//#include <initializer_list>
//#include <ctime>
//#include "Sales_data.h"
#include "Book.h"


using namespace std;

//7.5 构造函数再探
//Constructors Revisited


class ConstRef
{
public:
	ConstRef(int ii);
private:
	int i;
	const int ci;
	int &ri;
};
ConstRef::ConstRef(int ii) :i(ii), ci(ii), ri(i){}

class X
{
public:
	X();
	X(int val):j(val), i(j){};		//j初始化为val，i默认初始化
	void getval()
	{
		//输出i和j
		cout << i << "\t" << j << endl;
	}
private:
	int i;
	int j;
};


//7.5.1 构造函数初始值列表
void Fun_Constructor_Initializer_List()
{
	//构造函数初始值有时必不可少
	//如果成员时const或者是引用的话，必须将其初始化；
	//当成员属于某种类类型而该类没有定义默认构造函数时，也必须将这个成员初始化
	//随着构造函数体一开始执行，初始化就完成了，
	//我们初始化const和引用类型的数据成员的唯一机会就是通过构造函数初始值
	//即通过构造函数初始值列表进行初始化

	//成员初始化的顺序
	//构造函数初始值列表初始化顺序与数据成员在类定义中的出现顺序一致
	//最好令构造函数初始值的顺序与成员声明的顺序保持一致。
	//而且如果可能的话，尽量避免使用某些数据成员初始化其他成员
	//X x1(5);
	//x1.getval();0
	
	//默认实参和构造函数
	//如果一个构造函数为所有参数都提供了默认实参，则它实际上也定义了默认构造函数。
	//Sales_data item1("jajaj");
	//cout << item1.bookNo <<"   "<<item1.revenue<<"  "<<item1.units_sold<< endl;

	//ex7.36
	//struct X
	//{
	//	X(int i, int j) :base(i), rem(base % j){}
	//	int base, rem;
	//};

	//ex7.37
	//ex7.38

	//Sales_data(std::istream &is = std::cin) { read(is, *this); }

	//ex7.39
	//不合法

	//ex7.40
	//Book book(cin);
	//print(cout, book);

}

//7.5.2 委托构造函数
void Fun_Delegating_Constructors()
{
	//当一个构造函数委托给另一个构造函数时，受委托的构造函数的初始值列表和函数体一次执行。
	//假如受委托的构造函数函数体包含有代码的话，将先执行这些代码，然后控制权才会交还给委托者的函数体
	

	//ex7.41
	//cout << "item1:" << endl;
	//Sales_data item1("55-661", 0, 0);
	//cout << "item2:" << endl;
	//Sales_data item2;
	//cout << "item3:" << endl;
	//Sales_data item3("55-663");
	//cout << "item4:" << endl;
	//Sales_data item4(cin);
	//print(cout, item1);
	//print(cout, item2);
	//print(cout, item3);
	//print(cout, item4);
	
	//ex7.42
	//cout << "Book1:" << endl;
	//Book book1("bookname","Tom","55-661");
	//cout << "Book2:" << endl;
	//Book book2;
	//cout << "Book3:" << endl;
	//Book book3(cin);
	//print(cout, book1);
	//print(cout, book2);
	//print(cout, book3);
}

//7.5.3 默认构造函数的作用
void Fun_The_Role_of_the_Default_Constructor()
{
	

}

int main()
{

	//7.5.1 构造函数初始值列表
	//Fun_Constructor_Initializer_List();
	//7.5.2 委托构造函数
	Fun_Delegating_Constructors();



	return 0;

}