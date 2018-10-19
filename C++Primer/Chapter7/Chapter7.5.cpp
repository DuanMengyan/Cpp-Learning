#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��12�� ������
> Last edited time: 2018��10��19�� ������
> Topic:C++Primer Chapter7.5 ���캯����̽
************************************************************************/

#include "header_include.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstddef>
//#include <cctype>
//#include <stdexcept>
//#include <initializer_list>
//#include <ctime>
//#include "Sales_data.h"
#include "Book.h"


using namespace std;

//7.5 ���캯����̽
//Constructors Revisited


class ConstRef
{
public:
	ConstRef(int ii);
private:
	int i;
	const int ci;
	int &ri;
};
ConstRef::ConstRef(int ii) :i(ii), ci(ii), ri(i){}

class X
{
public:
	X();
	X(int val):j(val), i(j){};		//j��ʼ��Ϊval��iĬ�ϳ�ʼ��
	void getval()
	{
		//���i��j
		cout << i << "\t" << j << endl;
	}
private:
	int i;
	int j;
};


//7.5.1 ���캯����ʼֵ�б�
void Fun_Constructor_Initializer_List()
{
	//���캯����ʼֵ��ʱ�ز�����
	//�����Աʱconst���������õĻ������뽫���ʼ����
	//����Ա����ĳ�������Ͷ�����û�ж���Ĭ�Ϲ��캯��ʱ��Ҳ���뽫�����Ա��ʼ��
	//���Ź��캯����һ��ʼִ�У���ʼ��������ˣ�
	//���ǳ�ʼ��const���������͵����ݳ�Ա��Ψһ�������ͨ�����캯����ʼֵ
	//��ͨ�����캯����ʼֵ�б���г�ʼ��

	//��Ա��ʼ����˳��
	//���캯����ʼֵ�б��ʼ��˳�������ݳ�Ա���ඨ���еĳ���˳��һ��
	//�����캯����ʼֵ��˳�����Ա������˳�򱣳�һ�¡�
	//����������ܵĻ�����������ʹ��ĳЩ���ݳ�Ա��ʼ��������Ա
	//X x1(5);
	//x1.getval();0
	
	//Ĭ��ʵ�κ͹��캯��
	//���һ�����캯��Ϊ���в������ṩ��Ĭ��ʵ�Σ�����ʵ����Ҳ������Ĭ�Ϲ��캯����
	//Sales_data item1("jajaj");
	//cout << item1.bookNo <<"   "<<item1.revenue<<"  "<<item1.units_sold<< endl;

	//ex7.36
	//struct X
	//{
	//	X(int i, int j) :base(i), rem(base % j){}
	//	int base, rem;
	//};

	//ex7.37
	//ex7.38

	//Sales_data(std::istream &is = std::cin) { read(is, *this); }

	//ex7.39
	//���Ϸ�

	//ex7.40
	//Book book(cin);
	//print(cout, book);

}

//7.5.2 ί�й��캯��
void Fun_Delegating_Constructors()
{
	//��һ�����캯��ί�и���һ�����캯��ʱ����ί�еĹ��캯���ĳ�ʼֵ�б�ͺ�����һ��ִ�С�
	//������ί�еĹ��캯������������д���Ļ�������ִ����Щ���룬Ȼ�����Ȩ�Żύ����ί���ߵĺ�����
	

	//ex7.41
	//cout << "item1:" << endl;
	//Sales_data item1("55-661", 0, 0);
	//cout << "item2:" << endl;
	//Sales_data item2;
	//cout << "item3:" << endl;
	//Sales_data item3("55-663");
	//cout << "item4:" << endl;
	//Sales_data item4(cin);
	//print(cout, item1);
	//print(cout, item2);
	//print(cout, item3);
	//print(cout, item4);
	
	//ex7.42
	//cout << "Book1:" << endl;
	//Book book1("bookname","Tom","55-661");
	//cout << "Book2:" << endl;
	//Book book2;
	//cout << "Book3:" << endl;
	//Book book3(cin);
	//print(cout, book1);
	//print(cout, book2);
	//print(cout, book3);
}

//7.5.3 Ĭ�Ϲ��캯��������
void Fun_The_Role_of_the_Default_Constructor()
{
	

}

int main()
{

	//7.5.1 ���캯����ʼֵ�б�
	//Fun_Constructor_Initializer_List();
	//7.5.2 ί�й��캯��
	Fun_Delegating_Constructors();



	return 0;

}