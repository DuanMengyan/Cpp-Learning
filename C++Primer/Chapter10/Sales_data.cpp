#include "Sales_data.h"




//Sales_data�ķǳ�Ա�ӿں���
//Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
//{
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}
//
//ostream &print(ostream &os, const Sales_data &item)
//{
//	os << item.isbn() << " " << item.units_sold << " "
//		<< item.revenue << " " << item.avg_price() << endl;
//	return os;
//}
//
//istream &read(istream &is, Sales_data &item)
//{
//	double price = 0;
//	is >> item.bookNo >> item.units_sold >> price;
//	item.revenue = price * item.units_sold;
//	return is;
//}

//Sales_data::Sales_data(std::istream &is)
//{
//	read(is, *this);//read�����������Ǵ�is�ж�ȡһ��������ϢȻ�����this������
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
	units_sold += rhs.units_sold;		//��rhs�ĳ�Ա�ӵ�this����ĳ�Ա��
	revenue += rhs.revenue;
	return *this;						//���ص��øú����Ķ���
}




// assumes that both objects refer to the same ISBN
Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

