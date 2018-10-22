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
#include "Sales_data.h"
//#include "Book.h"


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

//ex7.43
class NoDefault
{
public:
	NoDefault(){ value = 6; };
	NoDefault(int num):value(num){};
	void getvalue()
	{
		cout << value << "\t";
	};
private:
	int value;
};

class C
{
public:
	//C():member(5){};
	C(){};
	void getmembervalue()
	{
		member.getvalue();
	}

private:
	NoDefault member;
};


//7.5.3 Ĭ�Ϲ��캯��������
void Fun_The_Role_of_the_Default_Constructor()
{
	//ex7.43
	
	//ex7.44
	//���Ϸ�����ΪNoDefaultû�й��캯��
	//vector<NoDefault> vec(10);
	//for (auto i = 0; i < 10; ++i)
	//{
	//	vec[1].getvalue();
	//}
	
	//ex7.45
	//�Ϸ���C������Ĭ�ϵĹ��캯��
	//vector<C> vec(10);
	//for (auto i = 0; i < 10; ++i)
	//{
	//	vec[i].getmembervalue();
	//}
	
	//ex7.46
	//(a)�಻�ṩ���캯��ʱ���ɱ���������ϳ�Ĭ�Ϲ��캯��
	//(b)�����Ա�ṩĬ��ֵ�Ĺ��캯����Ĭ�Ϲ��캯��
	//(c)
	//(d)û�ж��������κι��캯�����������źϳ�Ĭ�Ϲ��캯����
}

//7.5.4 ��ʽ��������ת��
void Fun_Implicit_Class_Type_Conversions()
{
	//ֻ����һ��������ת��
	Sales_data item1("9999-999-99-9"), item2;
	//item.combine("9999-999-99-9");  ��������ת��
	//��ʽת��Ϊstring����ʽת��ΪSales_data��
	//item2=item1.combine(string("9999-999-99-9"));
	//print(cout, item2);
	//��ʽת��Ϊstring,��ʽת��ΪSales_data
	//item2 = item1.combine(Sales_data("9999-999-99-9"));
	//print(cout, item2);
	
	//������ת����������Ч
	//item2 = item1.combine(cin);
	//print(cout, item2);
	
	
	//���ƹ��캯�������������ʽת��
	//explicit�ؼ������ƹ��캯����ʽת��
	//string null_book = "88-8-8";
	//item2 = item1.combine(cin);		 //���벻ͨ��
	//item2 = item1.combine(null_book);  //���벻ͨ��
	//print(cout, item2);

	//explicitֻ��һ��ʵ�εĹ��캯����Ч����Ҫ���ʵ�εĹ��캯����������ִ����ʽת����
	//explicit���캯��ֻ������ֱ�ӳ�ʼ�����������������Զ�ת��������ʹ�øù��캯��

	//Ϊת����ʽ��ʹ�ù��캯��
	
	//ex7.47 
	//�ŵ㣺
	//1.��������Ҫ��ʽת���ĵĵط�ʹ�ù��캯��
	//2.���Զ���һ��ֻ����ֱ�ӳ�ʼ����ʽ�Ĺ��캯��
	//ȱ�㣺
	//ֻ��һ��ʵ�εĹ��캯����Ч
	
	//ex7.48
	//(1)ֱ�ӳ�ʼ��һ��string����
	//(2)��ʽת����ʼ��һ��item����
	//(3)ֱ�ӳ�ʼ��һ��item����
	//����explicit�ؼ��֣�Ҳû������
	
	
	//ex7.49
	//(1)�Ϸ�
	//(2)���Ϸ� Sales_data��Sales_data&֮�䲻��ת��
	//(3)���Ϸ�������const����ȷ����Ϊ�ú�����ı�this��ֵ
	
	//ex7.50
	//ex7.51
}
int main()
{

	//7.5.1 ���캯����ʼֵ�б�
	//Fun_Constructor_Initializer_List();
	//7.5.2 ί�й��캯��
	//Fun_Delegating_Constructors();
	//7.5.3 Ĭ�Ϲ��캯��������
	//Fun_The_Role_of_the_Default_Constructor();
	//7.5.4 ��ʽ��������ת��
	Fun_Implicit_Class_Type_Conversions();

	return 0;

}