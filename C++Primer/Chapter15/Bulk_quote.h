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

	//����ԭ������ĺ����汾����ʵ�ֻ��ڴ���������ۿ�����
	double net_price(size_t n)const override;

private:
	size_t min_qty = 0;		//ʹ���ۿ����ߵ���͹�����
	double discount = 0.0	//�ۿ۶�
};


#endif // !BULK_QUOTE_H

