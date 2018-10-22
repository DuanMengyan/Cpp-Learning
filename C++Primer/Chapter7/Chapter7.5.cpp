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
#include "Sales_data.h"
//#include "Book.h"


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

//ex7.43
class NoDefault
{
public:
	NoDefault(){ value = 6; };
	NoDefault(int num):value(num){};
	void getvalue()
	{
		cout << value << "\t";
	};
private:
	int value;
};

class C
{
public:
	//C():member(5){};
	C(){};
	void getmembervalue()
	{
		member.getvalue();
	}

private:
	NoDefault member;
};


//7.5.3 默认构造函数的作用
void Fun_The_Role_of_the_Default_Constructor()
{
	//ex7.43
	
	//ex7.44
	//不合法，因为NoDefault没有构造函数
	//vector<NoDefault> vec(10);
	//for (auto i = 0; i < 10; ++i)
	//{
	//	vec[1].getvalue();
	//}
	
	//ex7.45
	//合法，C定义了默认的构造函数
	//vector<C> vec(10);
	//for (auto i = 0; i < 10; ++i)
	//{
	//	vec[i].getmembervalue();
	//}
	
	//ex7.46
	//(a)类不提供构造函数时，由编译器给类合成默认构造函数
	//(b)给类成员提供默认值的构造函数是默认构造函数
	//(c)
	//(d)没有定义其他任何构造函数，编译器才合成默认构造函数；
}

//7.5.4 隐式的类类型转换
void Fun_Implicit_Class_Type_Conversions()
{
	//只允许一步类类型转换
	Sales_data item1("9999-999-99-9"), item2;
	//item.combine("9999-999-99-9");  错误，两次转换
	//显式转换为string，隐式转换为Sales_data；
	//item2=item1.combine(string("9999-999-99-9"));
	//print(cout, item2);
	//隐式转换为string,显式转换为Sales_data
	//item2 = item1.combine(Sales_data("9999-999-99-9"));
	//print(cout, item2);
	
	//类类型转换不是总有效
	//item2 = item1.combine(cin);
	//print(cout, item2);
	
	
	//抑制构造函数函数定义的隐式转换
	//explicit关键字抑制构造函数隐式转换
	//string null_book = "88-8-8";
	//item2 = item1.combine(cin);		 //编译不通过
	//item2 = item1.combine(null_book);  //编译不通过
	//print(cout, item2);

	//explicit只对一个实参的构造函数有效，需要多个实参的构造函数不能用于执行隐式转换。
	//explicit构造函数只能用于直接初始化，编译器不会在自动转换过程中使用该构造函数

	//为转换显式地使用构造函数
	
	//ex7.47 
	//优点：
	//1.抑制在需要隐式转换的的地方使用构造函数
	//2.可以定义一个只用于直接初始化形式的构造函数
	//缺点：
	//只对一个实参的构造函数有效
	
	//ex7.48
	//(1)直接初始化一个string对象
	//(2)隐式转换初始化一个item对象
	//(3)直接初始化一个item对象
	//声明explicit关键字，也没有问题
	
	
	//ex7.49
	//(1)合法
	//(2)不合法 Sales_data和Sales_data&之间不能转换
	//(3)不合法，最后的const不正确，因为该函数会改变this的值
	
	//ex7.50
	//ex7.51
}
int main()
{

	//7.5.1 构造函数初始值列表
	//Fun_Constructor_Initializer_List();
	//7.5.2 委托构造函数
	//Fun_Delegating_Constructors();
	//7.5.3 默认构造函数的作用
	//Fun_The_Role_of_the_Default_Constructor();
	//7.5.4 隐式的类类型转换
	Fun_Implicit_Class_Type_Conversions();

	return 0;

}