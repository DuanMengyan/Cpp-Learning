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

	//����ԭ������ĺ����汾����ʵ�ֻ��ڴ���������ۿ�����
	double net_price(size_t n)const override;

private:
	size_t min_qty = 0;		//ʹ���ۿ����ߵ���͹�����
	size_t max_qty = 0;		//�����ۿ۵������������������ԭ�۳���
	double discount = 10;	//�ۿ۶�
};


#endif // !BULK_QUOTE_H

