#pragma once

#ifndef QUOTE_H
#define QUOTE_H

#include "header_include.h"

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {}

	string isbn()const { return bookNo; }

	//返回给定数量的书籍的销售总额
	//派生类负责改写并使用不用的折扣计算算法
	virtual double net_price(size_t n)const { return n*price; }

	//基类中通常应该定义一个虚析构函数
	//对析构函数进行动态绑定
	virtual ~Quote() = default;  
private:
	string bookNo;
protected:
	double price = 0.0;
};


#endif // !QUOTE_H


