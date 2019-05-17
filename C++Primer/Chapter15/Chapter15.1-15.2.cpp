#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter15.1-15.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年5月13日 星期一
> Last edited time: 2019年5月17日 星期五
> Topic:C++Primer Chapter15.1 OOP：概述; Chapter15.2 定义基类和派生类
************************************************************************/

#include "header_include.h"
#include "Quote.h"
#include "Bulk_quote.h"

using namespace std;

//Chapter15.1 OOP：概述
void Fun_OOP_An_Overview()
{
	//面向对象程序设计的核心思想是数据抽象、继承和动态绑定

	//继承
	
}

//Chapter15.2 定义基类和派生类

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}


//15.2.1定义基类
void Fun_Define_A_Base_Class()
{
	//基类中的两种成员函数
	//1.基类希望派生类进行重写覆盖的函数————虚函数
	//2.基类希望派生类直接继承而不要改变的函数

	//访问控制与继承
	//派生类能访问基类中公有成员和protected访问运算符说明的成员，而不能访问其私有成员	

	//ex15.1
	//virtual关键字声明的成员，希望派生类定义自己的版本
	
	//15.2
	//protected成员，派生类可以访问，其他用户不能访问
	//private成员，只有基类自己可以访问

	//15.3
	//见相关h文件和cpp文件
}

//15.2.2定义派生类
void Fun_Define_A_Derived_Class()
{
	//如果一个派生是公有的则基类的公有成员也是派生类接口的组成部分。

	//派生类中的虚函数
	//派生类经常覆盖它继承的虚函数。派生类可以在它覆盖的函数前使用virtual关键字，但并不是非得这么做。
	//C++11允许派生类显示地注明他使用某个成员函数覆盖了它继承的虚函数 关键字override

	//派生类对象及派生类向基类的类型转换
	//派生类中含有与其基类对应的部分，因此可以把派生类对象当成基类对象来使用
	//也可以将基类的指针或引用绑定到派生类对象的基类部分上

	//派生类构造函数
	//派生类应该遵循基类的接口，并且通过调用基类的构造函数来初始化它的基类部分

	//派生类使用基类的成员
	//派生类的作用域嵌套在基类的作用域之内

	//继承与静态成员
	//如果基类定义了一个静态成员，则在整个继承体系中只存在改成员的唯一定义
	//静态成员遵循通用的访问控制规则

	//派生类的声明中包含类名，但是不包含派生列表

	//被用作基类的类必须已经定义而非仅仅声明
	//一个类不能派生它本身，但是可以同时做基类和派生类
	//最终的派生类包含其直接基类的子对象以及每个间接基类的子对象

	//防止继承的发生，在类名后跟一个关键字，final

	//ex15.4
	//(a)错误，一个类不能继承自身
	//(b)错误，是定义而非声明
	//(c)错误，派生类的声明不能包含派生列表

	//ex15.5
	//见相关文件
	
	//ex15.6
	//Quote book1("book1", 50.0);
	//double price1 = print_total(cout, book1, 3);
	//
	//Bulk_quote book2("book2", 50.0, 3, 8);   //买够3本书，打8折
	//double price2 = print_total(cout, book2, 3);
	
	//ex15.7
	Bulk_quote book2("book2", 50.0, 3, 10, 8);			//买够3本书，打8折，限购10本，超出部分原价出售
	double price1 = print_total(cout, book2, 2);		//2本不打折，100
	double price2 = print_total(cout, book2, 5);		//5本打八折，200
	double price3 = print_total(cout, book2, 10);		//10本也打八折，400
	double price4 = print_total(cout, book2, 12);		//10本打八折，2本原价出售 500
}







int main()
{

	//15.2.1定义基类
	//Fun_Define_A_Base_Class();
	//15.2.2定义派生类
	Fun_Define_A_Derived_Class();



	return 0;

}