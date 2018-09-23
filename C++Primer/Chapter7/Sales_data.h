#pragma once
#pragma execution_character_set("utf-8")

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using namespace std;

struct  Sales_data;
istream &read(istream &is, Sales_data &item);

//改进的Sales_data
struct Sales_data
{
	//新增的构造函数
	//Sales_data() = default;
	Sales_data(): bookNo(""), units_sold(0), revenue(0){ }//使用类内初始值显式地初始化成员
	Sales_data(const string &s) :bookNo(s){ }
	Sales_data(const string&s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
	//Sales_data(istream&);//在类的外部定义
	Sales_data(istream & is)
	{
		read(is, *this);
	}

	//关于Sales_data对象的操作，定义在类内部的函数是隐式的inline函数
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

	string bookNo;
	unsigned units_sold = 0;	//销量
	double revenue = 0.0;    //总收入
};

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

//Sales_data::Sales_data(std::istream &is)
//{
//	read(is, *this);//read函数的作用是从is中读取一条交易信息然后存入this对象中
//}

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







#endif //SALES_DATA_H