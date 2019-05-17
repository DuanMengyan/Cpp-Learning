#pragma once

#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H


#include "Quote.h"
class Bulk_quote :public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t min_n, size_t max_n, double disc) :
		Quote(book, price), min_qty(min_n), max_qty(max_n)
	{
		if (disc<0.0 || disc>10.0)
			cout << "error discount, no discount" << endl;
		else discount = disc;	
	}

	~Bulk_quote();

	//覆盖原来基类的函数版本，以实现基于大量购买的折扣政策
	double net_price(size_t n)const override;

private:
	size_t min_qty = 0;		//使用折扣政策的最低购买量
	size_t max_qty = 0;		//享受折扣的最大购买量，超出部分原价出售
	double discount = 10;	//折扣额
};


#endif // !BULK_QUOTE_H

