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

	//���ظ����������鼮�������ܶ�
	//�����ฺ���д��ʹ�ò��õ��ۿۼ����㷨
	virtual double net_price(size_t n)const { return n*price; }

	//������ͨ��Ӧ�ö���һ������������
	//�������������ж�̬��
	virtual ~Quote() = default;  
private:
	string bookNo;
protected:
	double price = 0.0;
};


#endif // !QUOTE_H


