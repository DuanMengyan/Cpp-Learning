#pragma once

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H


#include "Quote.h"
class Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t n, double disc) :Quote(book, price), min_qty(n), discount(disc) {}

	~Bulk_quote();

	//覆盖原来基类的函数版本，以实现基于大量购买的折扣政策
	double net_price(size_t n)const override;

private:
	size_t min_qty = 0;		//使用折扣政策的最低购买量
	double discount = 0.0	//折扣额
};


#endif // !BULK_QUOTE_H

