#include "Bulk_quote.h"


Bulk_quote::~Bulk_quote()
{
}

double Bulk_quote::net_price(size_t cnt)const
{
	if (cnt >= max_qty)
		return max_qty*(discount / 10)*price + (cnt - max_qty)*price;  //�����޶������Ĳ���ԭ�۳���
	else if (cnt >= min_qty)
		return cnt*(discount / 10)*price;
	else
		return cnt*price;
}