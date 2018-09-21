#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��15�� ������
> Last edited time: 2018��9��21�� ������
> Topic:C++Primer Chapter7.1 ���������������
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>
#include "Sales_item.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;

//Defining Abstract Data Types

//
//struct Sales_data
//{
//	string bookNo;
//	unsigned units_sold = 0;	//����
//	double revenue = 0.0;    //������
//};

//7.1.1 ���Sales_data��
void Fun_Designing_the_Sales_data_Class()
{
	//Sales_data total;
	//if (cin >> total.bookNo >> total.unitis_sold >> total.revenue)
	//{
	//	Sales_data trans;
	//	while (cin >> trans.bookNo >> trans.unitis_sold >> trans.revenue)
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.unitis_sold += trans.unitis_sold;
	//			total.revenue += trans.revenue;
	//		}
	//		else
	//		{
	//			cout << total.bookNo << " " << total.unitis_sold << " " << total.revenue << endl;
	//			total = trans;
	//		}
	//	}
	//	cout << total.bookNo << " " << total.unitis_sold << " " << total.revenue << endl;
	//}
	//else
	//{
	//	std::cerr << "No data?!" << endl;
	//}
}

//�Ľ���Sales_data
struct Sales_data
{
	//����Sales_data����Ĳ��������������ڲ��ĺ�������ʽ��inline����
	string isbn() const { return bookNo; }  
	Sales_data &combine(const Sales_data&);
	double avg_price() const;	

	string bookNo;
	unsigned units_sold = 0;	//����
	double revenue = 0.0;    //������
};
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


//ex7.4
class Person
{
public:
	string get_name() const
	{
		return Name;
	};
	string get_address() const
	{
		return address;
	};

	//auto get_name() const -> std::string const& { return name; }
	//auto get_addr() const -> std::string const& { return address; }
	string Name;
	string address;
};
//ex7.9
ostream& output(ostream &os, const Person &per)
{
	os << per.get_name() << "    " << per.get_address();
	return os;
}

istream& input(istream &is,Person &per)
{
	is >> per.Name >> per.address;
	return is;
}


//7.1.2 ����Ľ���Sales_data��
void Fun_Defining_the_Revised_Sales_data_Class()
{
	//�����Ա����
	//����this
	//this����ָ���������������this��һ������ָ�룬������ı�this�б���ĵ�ַ
	
	//����const��Ա������const���������޸���ʽthisָ�������
	//Ĭ������£�this��������ָ�������ͷǳ����汾�ĳ���ָ�롣
	//��this����Ϊָ������ָ����������ߺ���������ԡ�
	//�����const�ؼ��ַ��ڳ�Ա�����Ĳ����б�֮��
	//�����ڲ����б�����const��ʾthis��һ��ָ������ָ��
	//������ʹ��const�ĳ�Ա��������Ϊ������Ա����
	
	//string Sales_data::isbn(const Sales_data *const this){return this->isbn;}


	//���������Լ�������������û�ָ�붼ֻ�ܵ��ó�����Ա����

	//��������ͳ�Ա����
	//��Ա�������������ʹ�����е�������Ա������������Щ��Ա���ֵĴ���


	//������ⲿ�����Ա����
	//���ⲿ����ĳ�Ա���������ֱ������������������

	//����һ������this����ĺ���
	//total.combine(trans);
	//һ����˵�������Ƕ���ĺ���������ĳ�����������ʱ��
	//Ӧ����ú�������Ϊ����ģ����������
	//���õĸ�ֵ������������������󵱳���ֵ����

	//ex7.2
	//struct Sales_data
	//{
	//	string isbn() const { return bookNo; }
	//	Sales_data& combine(const Sales_data&);

	//	std::string bookNo;			//Ĭ�ϳ�ʼ��Ϊ���ַ���
	//	unsigned units_sold = 0;	//��������
	//	double revenue = 0.0;		//������

	//};

	//Sales_data& Sales_data::combine(const Sales_data& rhs)
	//{
	//	units_sold += rhs.units_sold;
	//	revenue += rhs.revenue;
	//	return *this;
	//}

	//ex7.3
	//Sales_data total;
	//if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	//{
	//	Sales_data trans;
	//	while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.combine(trans);
	//		}
	//		else
	//		{
	//			cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	//			total = trans;
	//		}
	//	}
	//	cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	//}
	//else
	//{
	//	std::cerr << "No data?!" << endl;
	//}


	//ex7.4
	//ex7.5
	//Person person1;
	//person1.Name = "Tom";
	//person1.address = "hello world";
	//string str_name = person1.get_name();
	//string str_address = person1.get_address();
	//cout << str_name << "    " << str_address << endl;



}


//7.1.3 ��������صķǳ�Ա����
void Fun_Defining_Nonmember_Class_Related_Functions()
{
	//����read��print����������add����
	//Sales_data item1,item2;
	//read(cin, item1);
	//read(cin, item2);
	//print(cout, item1);
	//print(cout, item2);
	//print(cout, add(item1,item2));

	//ex7.7
	//Sales_data total;
	//if (read(cin,total))
	//{
	//	Sales_data trans;
	//	while (read(cin,trans))
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.combine(trans);
	//		}
	//		else
	//		{
	//			print(cout, total);
	//			total = trans;
	//		}
	//	}
	//	print(cout, total);
	//}
	//else
	//{
	//	std::cerr << "No data?!" << endl;
	//}

	//ex7.9
	//Person person1;
	//input(cin, person1);
	//output(cout, person1);

	//ex7.10

	//Sales_data item1, item2;
	//if (read(read(cin, item1), item2))
	//{
	//	cout << "hello" << endl;
	//	print(print(cout, item1), item2);
	//}


}

//7.1.4 ���캯��
void Fun_Constructors()
{


}


int main()
{
	//7.1.1 ���Sales_data��
	//Fun_Designing_the_Sales_data_Class();

	//7.1.2 ����Ľ���Sales_data��
	//Fun_Defining_the_Revised_Sales_data_Class();
	
	//7.1.3 ��������صķǳ�Ա����
	//Fun_Defining_Nonmember_Class_Related_Functions();

	//7.1.4 ���캯��
	Fun_Constructors();

	return 0;
}