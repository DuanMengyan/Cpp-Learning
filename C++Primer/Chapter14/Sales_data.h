#pragma once
#pragma execution_character_set("utf-8")

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include "header_include.h"

using namespace std;


//改进的Sales_data
class Sales_data
{
	friend istream& operator>>(istream &is, Sales_data& s);

	friend ostream& operator<<(ostream &os, const Sales_data& s);
	
	//按值返回
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

public:
	//构造函数
	Sales_data() = default;
	//explict抑制构造函数隐式转换
	explicit Sales_data(const string &s) :bookNo(s){ }
	Sales_data(const string&s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }

	Sales_data(istream &is) {input(is, *this);}
	
	//拷贝构造函数
	Sales_data(const Sales_data &lhs);

	//拷贝赋值运算符
	Sales_data& operator=(const Sales_data &lhs);
	
	//析构函数
	~Sales_data() {};

	//Chapter14.1 运算符重载
	bool operator==(const Sales_data &lhs);
	
	Sales_data& operator+=(const Sales_data &rhs);
	

	//关于Sales_data对象的操作，定义在类内部的函数是隐式的inline函数
private:
	string bookNo;
	unsigned units_sold = 0;	//销量
	double revenue = 0.0;		//总收入

	//工具函数
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

	istream &input(istream &is, Sales_data &item);
	ostream &output(ostream &os, const Sales_data &item);
};

#endif //SALES_DATA_H