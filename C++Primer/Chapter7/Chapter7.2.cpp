#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月24日 星期一
> Last edited time: 2018年9月25日 星期二
> Topic:C++Primer Chapter7.2 访问控制与封装
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using namespace std;

class Sales_data
{
	//为Sales_data的非成员函数所做的友元声明
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend istream &read(istream&, Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);

public:
	//构造函数声明及部分定义
	Sales_data() = default;
	Sales_data(const string &s):bookNo(s){ }
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n){ }
	Sales_data(istream&);
	//共有成员函数声明及部分定义
	string ibsn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);

private:
	double avg_price() const
	{
		return units_sold? revenue / units_sold : 0;
	}
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


//构造函数定义
Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}

//接口成员函数定义
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

//友元函数定义
Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
	Sales_data sum = item1; 
	sum.combine(item2);
	return sum;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.bookNo << "   " << item.units_sold << "   "
		<< item.revenue << "   " << item.avg_price() << endl;
	return os;
}

class Person
{
	//友元函数声明
	friend istream& input(istream&, Person&);
	friend ostream& output(ostream&, const Person&);

public:
	//构造函数声明及部分定义
	Person() = default;
	Person(const string &name) :Name(name) {};
	Person(const string &name, const string &addr) :Name(name), address(addr){};
	Person(istream&);
	//共有成员函数声明及部分定义
	string get_name() const
	{
		return Name;
	};
	string get_address() const
	{
		return address;
	};

private:
	string Name;
	string address;
};

//友元函数定义
ostream& output(ostream &os, const Person &per)
{
	os << per.get_name() << "    " << per.get_address() << endl;
	return os;
}

istream& input(istream &is, Person &per)
{
	is >> per.Name >> per.address;
	return is;
}

//构造函数定义
Person::Person(istream&is)
{
	input(is, *this);
}

//7.2 访问控制与封装
void Fun_Access_Control_and_Encapsulation()
{
	//访问说明符
	//public成员定义类的接口
	//private说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问
	//private部分封装了(即隐藏了)类的实现细节
	//访问说明符有效范围直到出现下一个访问说明符或者到达类的结尾处为止

	//使用class或struct关键字
	//class默认访问权限是private,struct默认访问权限是public

	//ex7.16
	//需要控制的类的相关操作——————类成员的初始化、拷贝、赋值、销毁对象等定义在public之后
	//类的成员以及相关实现细节定义在private，之后，对类的用户隐藏类的相关实现细节，实现封装

	//ex7.18
	//封装实现了类的接口和实现的分离，隐藏了类的实现细节，用户只能接触到类的接口
	//优点：
	//(1)隐藏类的实现细节；
	//(2)让使用者只能通过程序规定的方法来访问数据；
	//(3)可以方便的加入存取控制语句，限制不合理的操作；
	//(4)类自身的安全性提升，只能被访问不能被修改；
	//(5)类的细节可以随时改变，不需要修改用户级别的代码

	//ex7.19
	//public:构造函数，get_name()和get_address()接口
	//private:name,address成员

}

//7.2.1 友元
void Fun_friends()
{
	//类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元。
	//友元声明只能出现在类定义的内部，但是在类内出现的具体位置不限
	//友元不是类的成员，也不受它所在区域访问控制级别的约束

	//如果希望类的用户能够调用某个友元函数，那么我们就必须在友元声明之外再专门对函数进行一次声明

	//Sales_data item1;
	//print(cout, item1);

	//Sales_data item2("888888");
	//print(cout, item2);

	//Sales_data item3("888888", 5, 20.00);
	//print(cout, item3);

	//Sales_data item4(cin);
	//print(cout, item4);

	//Person person1;
	//output(cout, person1);

	//Person person2("Tom");
	//output(cout, person2);

	//Person person3("Tom", "helloworld!");
	//output(cout, person3);

	//Person person4(cin);
	//output(cout, person4);

	//ex7.20
	//友元：类允许其他类或者函数访问其非共有成员，
	//只要在本类内，加一条类前或者函数前有friend关键字的声明即可。
	//最好在类的开始或者结束前声明友元

	//优点；
	//可以灵活地实现需要访问若干类的私有成员才能完成的任务，便于与其他不支持类的语言进行混合编程；
	//通过使用友元函数重载可以更自然地使用C++语言的I/O库

	//缺点：
	//一个类将对费共有成员的访问权限授予其他类或函数，会破坏类的封装性，降低该类的可靠性和可维护性


}


int main()
{
	//7.2.1 友元
	Fun_friends();
	return 0;
}