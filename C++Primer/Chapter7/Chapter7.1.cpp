#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月15日 星期六
> Last edited time: 2018年9月21日 星期五
> Topic:C++Primer Chapter7.1 定义抽象数据类型
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>
#include "Sales_item.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;

//Defining Abstract Data Types

//
//struct Sales_data
//{
//	string bookNo;
//	unsigned units_sold = 0;	//销量
//	double revenue = 0.0;    //总收入
//};

//7.1.1 设计Sales_data类
void Fun_Designing_the_Sales_data_Class()
{
	//Sales_data total;
	//if (cin >> total.bookNo >> total.unitis_sold >> total.revenue)
	//{
	//	Sales_data trans;
	//	while (cin >> trans.bookNo >> trans.unitis_sold >> trans.revenue)
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.unitis_sold += trans.unitis_sold;
	//			total.revenue += trans.revenue;
	//		}
	//		else
	//		{
	//			cout << total.bookNo << " " << total.unitis_sold << " " << total.revenue << endl;
	//			total = trans;
	//		}
	//	}
	//	cout << total.bookNo << " " << total.unitis_sold << " " << total.revenue << endl;
	//}
	//else
	//{
	//	std::cerr << "No data?!" << endl;
	//}
}

//改进的Sales_data
struct Sales_data
{
	//关于Sales_data对象的操作，定义在类内部的函数是隐式的inline函数
	string isbn() const { return bookNo; }  
	Sales_data &combine(const Sales_data&);
	double avg_price() const;	

	string bookNo;
	unsigned units_sold = 0;	//销量
	double revenue = 0.0;    //总收入
};
double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;		//把rhs的成员加到this对象的成员上
	revenue += rhs.revenue;
	return *this;						//返回调用该函数的对象
}


//Sales_data的非成员接口函数
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << "  " << item.units_sold << "  "
		<< item.revenue << "  " << item.avg_price() << endl;
	return os;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}


//ex7.4
class Person
{
public:
	string get_name() const
	{
		return Name;
	};
	string get_address() const
	{
		return address;
	};

	//auto get_name() const -> std::string const& { return name; }
	//auto get_addr() const -> std::string const& { return address; }
	string Name;
	string address;
};
//ex7.9
ostream& output(ostream &os, const Person &per)
{
	os << per.get_name() << "    " << per.get_address();
	return os;
}

istream& input(istream &is,Person &per)
{
	is >> per.Name >> per.address;
	return is;
}


//7.1.2 定义改进的Sales_data类
void Fun_Defining_the_Revised_Sales_data_Class()
{
	//定义成员函数
	//引入this
	//this总是指向“这个”对象，所以this是一个常量指针，不允许改变this中保存的地址
	
	//引入const成员函数，const的作用是修改隐式this指针的类型
	//默认情况下，this的类型是指向类类型非常量版本的常量指针。
	//把this设置为指向常量的指针有助于提高函数的灵活性。
	//允许把const关键字放在成员函数的参数列表之后，
	//紧跟在参数列表后面的const表示this是一个指向常量的指针
	//像这样使用const的成员函数被称为常量成员函数
	
	//string Sales_data::isbn(const Sales_data *const this){return this->isbn;}


	//常量对象，以及常量对象的引用或指针都只能调用常量成员函数

	//类作用域和成员函数
	//成员函数体可以随意使用类中的其他成员而无须在意这些成员出现的次序。


	//在类的外部定义成员函数
	//类外部定义的成员函数的名字必须包含它所属的类名

	//定义一个返回this对象的函数
	//total.combine(trans);
	//一般来说，当我们定义的函数类似于某个内置运算符时，
	//应该令该函数的行为尽量模仿这个运算符
	//内置的赋值运算符把它左侧运算对象当成左值返回

	//ex7.2
	//struct Sales_data
	//{
	//	string isbn() const { return bookNo; }
	//	Sales_data& combine(const Sales_data&);

	//	std::string bookNo;			//默认初始化为空字符串
	//	unsigned units_sold = 0;	//销售数量
	//	double revenue = 0.0;		//总收入

	//};

	//Sales_data& Sales_data::combine(const Sales_data& rhs)
	//{
	//	units_sold += rhs.units_sold;
	//	revenue += rhs.revenue;
	//	return *this;
	//}

	//ex7.3
	//Sales_data total;
	//if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	//{
	//	Sales_data trans;
	//	while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.combine(trans);
	//		}
	//		else
	//		{
	//			cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	//			total = trans;
	//		}
	//	}
	//	cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	//}
	//else
	//{
	//	std::cerr << "No data?!" << endl;
	//}


	//ex7.4
	//ex7.5
	//Person person1;
	//person1.Name = "Tom";
	//person1.address = "hello world";
	//string str_name = person1.get_name();
	//string str_address = person1.get_address();
	//cout << str_name << "    " << str_address << endl;



}


//7.1.3 定义类相关的非成员函数
void Fun_Defining_Nonmember_Class_Related_Functions()
{
	//定义read和print函数，定义add函数
	//Sales_data item1,item2;
	//read(cin, item1);
	//read(cin, item2);
	//print(cout, item1);
	//print(cout, item2);
	//print(cout, add(item1,item2));

	//ex7.7
	//Sales_data total;
	//if (read(cin,total))
	//{
	//	Sales_data trans;
	//	while (read(cin,trans))
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.combine(trans);
	//		}
	//		else
	//		{
	//			print(cout, total);
	//			total = trans;
	//		}
	//	}
	//	print(cout, total);
	//}
	//else
	//{
	//	std::cerr << "No data?!" << endl;
	//}

	//ex7.9
	//Person person1;
	//input(cin, person1);
	//output(cout, person1);

	//ex7.10

	//Sales_data item1, item2;
	//if (read(read(cin, item1), item2))
	//{
	//	cout << "hello" << endl;
	//	print(print(cout, item1), item2);
	//}


}

//7.1.4 构造函数
void Fun_Constructors()
{


}


int main()
{
	//7.1.1 设计Sales_data类
	//Fun_Designing_the_Sales_data_Class();

	//7.1.2 定义改进的Sales_data类
	//Fun_Defining_the_Revised_Sales_data_Class();
	
	//7.1.3 定义类相关的非成员函数
	//Fun_Defining_Nonmember_Class_Related_Functions();

	//7.1.4 构造函数
	Fun_Constructors();

	return 0;
}