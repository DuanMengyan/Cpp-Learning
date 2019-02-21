#pragma once
#pragma execution_character_set("utf-8")

#ifndef SALES_DATA_H
#define SALES_DATA_H


#include "header_include.h"

using namespace std;

struct  Sales_data;
extern istream &read(istream &is, Sales_data &item);

//改进的Sales_data
struct Sales_data
{
	//新增的构造函数
	Sales_data() = default;
	//Sales_data(): bookNo(""), units_sold(0), revenue(0){ }//使用类内初始值显式地初始化成员
	//explict抑制构造函数隐式转换
	explicit Sales_data(const string &s) :bookNo(s){ }
	Sales_data(const string&s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
	//Sales_data(istream&);//在类的外部定义
	//Sales_data(std::istream &is = std::cin) { read(is, *this); }
	Sales_data(istream & is)
	{
		read(is, *this);
	}
	bool operator==(const Sales_data &);
	Sales_data& operator+=(const Sales_data&);
	//Sales_data(string s, unsigned cnt, double price) :
	//	bookNo(s), units_sold(cnt), revenue(cnt*price) 
	//	{
	//		// << "Constructor_three" << endl;
	//	}
	////委托构造函数
	//Sales_data() :Sales_data("", 0, 0) 
	//{ 
	//	//cout << "Constructor_default" << endl; 
	//}
	//Sales_data(string s) :Sales_data(s, 0, 0)
	//{
	//	//cout << "Constructor_string_s" << endl; 
	//}

	//Sales_data(istream &is) :Sales_data() { read(is, *this); }



	//关于Sales_data对象的操作，定义在类内部的函数是隐式的inline函数
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

	string bookNo;
	unsigned units_sold = 0;	//销量
	double revenue = 0.0;    //总收入
};


//Sales_data& Sales_data::operator+=(const Sales_data& rhs)
//{
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}
//
//Sales_data
//operator+(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data ret(lhs);  // copy (|lhs|) into a local object that we'll return
//	ret += rhs;           // add in the contents of (|rhs|) 
//	return ret;           // return (|ret|) by value
//}




#endif //SALES_DATA_H