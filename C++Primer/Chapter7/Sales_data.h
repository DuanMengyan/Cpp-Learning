#pragma once
#pragma execution_character_set("utf-8")

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using namespace std;

struct  Sales_data;
istream &read(istream &is, Sales_data &item);

//�Ľ���Sales_data
struct Sales_data
{
	//�����Ĺ��캯��
	//Sales_data() = default;
	Sales_data(): bookNo(""), units_sold(0), revenue(0){ }//ʹ�����ڳ�ʼֵ��ʽ�س�ʼ����Ա
	Sales_data(const string &s) :bookNo(s){ }
	Sales_data(const string&s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) { }
	//Sales_data(istream&);//������ⲿ����
	Sales_data(istream & is)
	{
		read(is, *this);
	}

	//����Sales_data����Ĳ��������������ڲ��ĺ�������ʽ��inline����
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

	string bookNo;
	unsigned units_sold = 0;	//����
	double revenue = 0.0;    //������
};

//Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << "  " << item.units_sold << "  "
		<< item.revenue << "  " << item.avg_price() << endl;
	return os;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

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







#endif //SALES_DATA_H