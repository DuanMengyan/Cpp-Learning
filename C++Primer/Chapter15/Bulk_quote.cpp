#include "Bulk_quote.h"


Bulk_quote::~Bulk_quote()
{
}

double Bulk_quote::net_price(size_t cnt)const
{
	if (cnt >= max_qty)
		return max_qty*(discount / 10)*price + (cnt - max_qty)*price;  //超出限定最大购买的部分原价出售
	else if (cnt >= min_qty)
		return cnt*(discount / 10)*price;
	else
		return cnt*price;
}