#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月15日 星期六
> Last edited time: 2018年9月23日 星期日
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
#include "Sales_data.h"

using namespace std;

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
	//if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	//{
	//	Sales_data trans;
	//	while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.units_sold += trans.units_sold;
	//			total.revenue += trans.revenue;
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
}


//ex7.4
class Person
{
public:
	Person() = default;
	Person(const string &name) :Name(name) {};
	Person(const string &name, const string &addr) :Name(name), address(addr){};
	Person(istream&);

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
	os << per.get_name() << "    " << per.get_address() << endl;
	return os;
}

istream& input(istream &is,Person &per)
{
	is >> per.Name >> per.address;
	return is;
}

Person::Person(istream&is)
{
	input(is, *this);
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
	//类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫做构造函数
	//构造函数的任务是初始化类对象的数据成员，无论何时只要类的对象被创建，就会执行构造函数

	//构造函数的名字和类名相同，且没有返回类型
	//构造函数不能声明成const，构造函数在const对象的构造过程中可以向其写值

	//合成的默认构造函数
	//只有当类没有声明任何构造函数时，编译器才会自动生成默认构造函数

	//含有内置类型或复合类型成员的类应该在类的内部初始化这些成员，
	//或者定义一个自己的默认构造函数
	//否则用户在创建类的对象时就可能得到未定义的值

	//如果类中包含一个其他类型的成员且这个成员的类型没有默认构造函数，
	//那么编译器将无法初始化该成员，必须自定义默认构造函数

	//构造函数初始值列表
	//负责为新创建的对象的一个或几个数据成员赋值
	//构造函数使用类内初始值不失为一种好的选择，
	//因为只要这样的初始值存在，就可以确保为成员赋予了一个正确的值
	//如果编译器不支持类内初始值，则所有的构造函数都应该显式地初始化每个内置类型的成员


	//在类的外部定义构造函数

	//ex7.11
	//Sales_data item1;
	//print(cout, item1);

	//Sales_data item2("888888");
	//print(cout, item2);

	//Sales_data item3("888888", 5, 20.00);
	//print(cout, item3);

	//Sales_data item4(cin);
	//print(cout, item4);

	//ex7.12
	//在头文件开始声明struct Sales_data和read函数，然后在struct Sales_data结构体定义内部使用read函数

	//ex7.13
	//Sales_data total(cin);
	//if (!total.isbn().empty())
	//{
	//	while (cin)
	//	{
	//		Sales_data trans(cin);
	//		if (!cin) break;
	//		if (total.isbn() == trans.isbn())
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

	//ex7.14

	//ex7.15
	Person item1;
	cout << "Person1:\t";
	output(cout, item1);//默认是两个空字符串

	Person item2("Tom");
	cout << "Person2:\t";
	output(cout, item2);

	Person item3("Tom", "helloworld");
	cout << "Person3:\t";
	output(cout, item3);

	Person item4(cin);
	cout << "Person4:\t";
	output(cout, item4);
	
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