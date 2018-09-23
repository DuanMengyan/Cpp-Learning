#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��15�� ������
> Last edited time: 2018��9��23�� ������
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
#include "Sales_data.h"

using namespace std;

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
	//if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	//{
	//	Sales_data trans;
	//	while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
	//	{
	//		if (total.bookNo == trans.bookNo)
	//		{
	//			total.units_sold += trans.units_sold;
	//			total.revenue += trans.revenue;
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
}


//ex7.4
class Person
{
public:
	Person() = default;
	Person(const string &name) :Name(name) {};
	Person(const string &name, const string &addr) :Name(name), address(addr){};
	Person(istream&);

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
	os << per.get_name() << "    " << per.get_address() << endl;
	return os;
}

istream& input(istream &is,Person &per)
{
	is >> per.Name >> per.address;
	return is;
}

Person::Person(istream&is)
{
	input(is, *this);
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
	//��ͨ��һ���򼸸�����ĳ�Ա���������������ĳ�ʼ�����̣���Щ�����������캯��
	//���캯���������ǳ�ʼ�����������ݳ�Ա�����ۺ�ʱֻҪ��Ķ��󱻴������ͻ�ִ�й��캯��

	//���캯�������ֺ�������ͬ����û�з�������
	//���캯������������const�����캯����const����Ĺ�������п�������дֵ

	//�ϳɵ�Ĭ�Ϲ��캯��
	//ֻ�е���û�������κι��캯��ʱ���������Ż��Զ�����Ĭ�Ϲ��캯��

	//�����������ͻ򸴺����ͳ�Ա����Ӧ��������ڲ���ʼ����Щ��Ա��
	//���߶���һ���Լ���Ĭ�Ϲ��캯��
	//�����û��ڴ�����Ķ���ʱ�Ϳ��ܵõ�δ�����ֵ

	//������а���һ���������͵ĳ�Ա�������Ա������û��Ĭ�Ϲ��캯����
	//��ô���������޷���ʼ���ó�Ա�������Զ���Ĭ�Ϲ��캯��

	//���캯����ʼֵ�б�
	//����Ϊ�´����Ķ����һ���򼸸����ݳ�Ա��ֵ
	//���캯��ʹ�����ڳ�ʼֵ��ʧΪһ�ֺõ�ѡ��
	//��ΪֻҪ�����ĳ�ʼֵ���ڣ��Ϳ���ȷ��Ϊ��Ա������һ����ȷ��ֵ
	//�����������֧�����ڳ�ʼֵ�������еĹ��캯����Ӧ����ʽ�س�ʼ��ÿ���������͵ĳ�Ա


	//������ⲿ���幹�캯��

	//ex7.11
	//Sales_data item1;
	//print(cout, item1);

	//Sales_data item2("888888");
	//print(cout, item2);

	//Sales_data item3("888888", 5, 20.00);
	//print(cout, item3);

	//Sales_data item4(cin);
	//print(cout, item4);

	//ex7.12
	//��ͷ�ļ���ʼ����struct Sales_data��read������Ȼ����struct Sales_data�ṹ�嶨���ڲ�ʹ��read����

	//ex7.13
	//Sales_data total(cin);
	//if (!total.isbn().empty())
	//{
	//	while (cin)
	//	{
	//		Sales_data trans(cin);
	//		if (!cin) break;
	//		if (total.isbn() == trans.isbn())
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

	//ex7.14

	//ex7.15
	Person item1;
	cout << "Person1:\t";
	output(cout, item1);//Ĭ�����������ַ���

	Person item2("Tom");
	cout << "Person2:\t";
	output(cout, item2);

	Person item3("Tom", "helloworld");
	cout << "Person3:\t";
	output(cout, item3);

	Person item4(cin);
	cout << "Person4:\t";
	output(cout, item4);
	
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