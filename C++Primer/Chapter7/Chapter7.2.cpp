#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��9��24�� ����һ
> Last edited time: 2018��9��25�� ���ڶ�
> Topic:C++Primer Chapter7.2 ���ʿ������װ
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using namespace std;

class Sales_data
{
	//ΪSales_data�ķǳ�Ա������������Ԫ����
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend istream &read(istream&, Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);

public:
	//���캯�����������ֶ���
	Sales_data() = default;
	Sales_data(const string &s):bookNo(s){ }
	Sales_data(const string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n){ }
	Sales_data(istream&);
	//���г�Ա�������������ֶ���
	string ibsn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);

private:
	double avg_price() const
	{
		return units_sold? revenue / units_sold : 0;
	}
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


//���캯������
Sales_data::Sales_data(istream &is)
{
	read(is, *this);
}

//�ӿڳ�Ա��������
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

//��Ԫ��������
Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
	Sales_data sum = item1; 
	sum.combine(item2);
	return sum;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.bookNo << "   " << item.units_sold << "   "
		<< item.revenue << "   " << item.avg_price() << endl;
	return os;
}

class Person
{
	//��Ԫ��������
	friend istream& input(istream&, Person&);
	friend ostream& output(ostream&, const Person&);

public:
	//���캯�����������ֶ���
	Person() = default;
	Person(const string &name) :Name(name) {};
	Person(const string &name, const string &addr) :Name(name), address(addr){};
	Person(istream&);
	//���г�Ա�������������ֶ���
	string get_name() const
	{
		return Name;
	};
	string get_address() const
	{
		return address;
	};

private:
	string Name;
	string address;
};

//��Ԫ��������
ostream& output(ostream &os, const Person &per)
{
	os << per.get_name() << "    " << per.get_address() << endl;
	return os;
}

istream& input(istream &is, Person &per)
{
	is >> per.Name >> per.address;
	return is;
}

//���캯������
Person::Person(istream&is)
{
	input(is, *this);
}

//7.2 ���ʿ������װ
void Fun_Access_Control_and_Encapsulation()
{
	//����˵����
	//public��Ա������Ľӿ�
	//private˵����֮��ĳ�Ա���Ա���ĳ�Ա�������ʣ����ǲ��ܱ�ʹ�ø���Ĵ������
	//private���ַ�װ��(��������)���ʵ��ϸ��
	//����˵������Ч��Χֱ��������һ������˵�������ߵ�����Ľ�β��Ϊֹ

	//ʹ��class��struct�ؼ���
	//classĬ�Ϸ���Ȩ����private,structĬ�Ϸ���Ȩ����public

	//ex7.16
	//��Ҫ���Ƶ������ز������������������Ա�ĳ�ʼ������������ֵ�����ٶ���ȶ�����public֮��
	//��ĳ�Ա�Լ����ʵ��ϸ�ڶ�����private��֮�󣬶�����û�����������ʵ��ϸ�ڣ�ʵ�ַ�װ

	//ex7.18
	//��װʵ������Ľӿں�ʵ�ֵķ��룬���������ʵ��ϸ�ڣ��û�ֻ�ܽӴ�����Ľӿ�
	//�ŵ㣺
	//(1)�������ʵ��ϸ�ڣ�
	//(2)��ʹ����ֻ��ͨ������涨�ķ������������ݣ�
	//(3)���Է���ļ����ȡ������䣬���Ʋ�����Ĳ�����
	//(4)������İ�ȫ��������ֻ�ܱ����ʲ��ܱ��޸ģ�
	//(5)���ϸ�ڿ�����ʱ�ı䣬����Ҫ�޸��û�����Ĵ���

	//ex7.19
	//public:���캯����get_name()��get_address()�ӿ�
	//private:name,address��Ա

}

//7.2.1 ��Ԫ
void Fun_friends()
{
	//�����������������ߺ����������ķǹ��г�Ա������������������ߺ�����Ϊ������Ԫ��
	//��Ԫ����ֻ�ܳ������ඨ����ڲ������������ڳ��ֵľ���λ�ò���
	//��Ԫ������ĳ�Ա��Ҳ����������������ʿ��Ƽ����Լ��

	//���ϣ������û��ܹ�����ĳ����Ԫ��������ô���Ǿͱ�������Ԫ����֮����ר�ŶԺ�������һ������

	//Sales_data item1;
	//print(cout, item1);

	//Sales_data item2("888888");
	//print(cout, item2);

	//Sales_data item3("888888", 5, 20.00);
	//print(cout, item3);

	//Sales_data item4(cin);
	//print(cout, item4);

	//Person person1;
	//output(cout, person1);

	//Person person2("Tom");
	//output(cout, person2);

	//Person person3("Tom", "helloworld!");
	//output(cout, person3);

	//Person person4(cin);
	//output(cout, person4);

	//ex7.20
	//��Ԫ����������������ߺ���������ǹ��г�Ա��
	//ֻҪ�ڱ����ڣ���һ����ǰ���ߺ���ǰ��friend�ؼ��ֵ��������ɡ�
	//�������Ŀ�ʼ���߽���ǰ������Ԫ

	//�ŵ㣻
	//��������ʵ����Ҫ�����������˽�г�Ա������ɵ����񣬱�����������֧��������Խ��л�ϱ�̣�
	//ͨ��ʹ����Ԫ�������ؿ��Ը���Ȼ��ʹ��C++���Ե�I/O��

	//ȱ�㣺
	//һ���ཫ�Էѹ��г�Ա�ķ���Ȩ��������������������ƻ���ķ�װ�ԣ����͸���Ŀɿ��ԺͿ�ά����


}


int main()
{
	//7.2.1 ��Ԫ
	Fun_friends();
	return 0;
}