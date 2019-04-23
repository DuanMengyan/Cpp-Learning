#pragma once
#pragma execution_character_set("utf-8")

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include "header_include.h"

using namespace std;


//�Ľ���Sales_data
class Sales_data
{
	friend istream& operator>>(istream &is, Sales_data& s);

	friend ostream& operator<<(ostream &os, const Sales_data& s);
	
	//��ֵ����
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

public:
	//���캯��
	Sales_data() = default;
	//explict���ƹ��캯����ʽת��
	explicit Sales_data(const string &s) :bookNo(s){ }
	Sales_data(const string&s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }

	Sales_data(istream &is) {input(is, *this);}
	
	//�������캯��
	Sales_data(const Sales_data &lhs);

	//������ֵ�����
	Sales_data& operator=(const Sales_data &lhs);
	
	//��������
	~Sales_data() {};

	//Chapter14.1 ���������
	bool operator==(const Sales_data &lhs);
	
	Sales_data& operator+=(const Sales_data &rhs);
	

	//����Sales_data����Ĳ��������������ڲ��ĺ�������ʽ��inline����
private:
	string bookNo;
	unsigned units_sold = 0;	//����
	double revenue = 0.0;		//������

	//���ߺ���
	string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);
	double avg_price() const;

	istream &input(istream &is, Sales_data &item);
	ostream &output(ostream &os, const Sales_data &item);
};

#endif //SALES_DATA_H