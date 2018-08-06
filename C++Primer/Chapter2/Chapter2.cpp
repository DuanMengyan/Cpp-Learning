#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��07��28�� ������
> Last edited time: 2018��08��3�� ������
> Topic:C++Primer Chapter2
************************************************************************/



#include <iostream>//ϵͳͷ�ļ����ļ���Ҫ���ڼ���������������Ǹ��߱�������Ӧ�õ�����׼�ġ��ص�Ѱ������ļ���#include <stdio.h>
#include "Chapter2.h"//�Զ���ͷ�ļ����ļ���Ҫ����˫���������
#include <string>
#include <cstdlib>


using namespace std;

//2.3��������ת��
void DataType() 
{ 		
	//unsigned int u = 10;		
	//int i = -42;	
	//std::cout << i + i << std::endl;	
	//std::cout << u + i << std::endl;	
	//unsigned u1 = 42, u2 = 10;	
	//std::cout << u1 - u2 << std::endl;
	//std::cout << u2 - u1 << std::endl;
	 
	
	//for (unsigned i = 10; i >= 0; --i)  //�޷��ŵ�i��ԶҲ����С��0������д������
	//	std::cout << i << std::endl;	
	
	
	
	/*���ʽ�м��д��������������޷������ͣ�	
	����������ȡֵΪ��ʱ�������쳣�����
	��Ϊ���������������Զ�ת��Ϊ�޷�������	*/
	
	int a = -1;	unsigned b = 1;	
	std::cout << a * b << std::endl;		//aת��Ϊȡģ�޷�����4294967295�����Ϊ��4294967295
	unsigned u = 10, u2 = 42;	
	std::cout << u2 - u << std::endl;		//32	
	std::cout << u - u2 << std::endl;		//���-32�����޷������ͷ�Χ�������쳣
	int i = 10, i2 = 42;	
	std::cout << i2 - i<< std::endl;		//32	
	std::cout << i - i2 << std::endl;		//-32	
	std::cout << i- u << std::endl;			//0	
	std::cout << u - i << std::endl;		//0


}

//2.8����ֵ����
void LiteralConstant()  
{
	std::cout << "Hi \x4dO\115!\n";
	std::cout << '\115' << '\n';

	std::cout << "2\115" << std::endl;
	std::cout << '2' << '\t' << '\x4d' << std::endl;
}


std::string global_str; //�մ�
int global_int;
//2.10������ʼֵ
/*
/����ڶ������ʱû��ָ����ֵ����ô�����ᱻĬ�ϳ�ʼ����
/�������ʣ�
/1���������κκ�������ı����ᱻ��ʼ��Ϊ0��   
/2�������ں������ڲ��ı������ᱻ��ʼ���� 
/3����Ķ���δ����ʼ�������ֵ���������
*/
void VariableInitialValue()
{
	int local_int = 1;
	std::string local_str;
	std::cout << &global_str << std::endl;		
	std::cout << global_int << std::endl;
	std::cout << &local_str << std::endl;
	std::cout << local_int << std::endl;
}


//2.11���������붨��
/*
������ʹ������Ϊ������֪�������ʹ�øñ����������ʵ�ְ�����������������ȷ�����������ֺ����͡�

���壺���������ֹ�����ʵ�塣���������洢�ռ䣬���ܻḳ���ʼֵ��

���������һ�����������붨��������ô�����ڱ�����ǰ��extern�ؼ��֡�
*/
void VariableDefinitionAndDeclaration()
{
	//int variable = 10; //�������variable
	std::cout << variable << std::endl;
	
}

//2.15����(��ʵ�Ǳ����ı���)
void Reference()
{	
	//int ival = 1.01;   //���Ϸ��Ķ���
	//int i = 1;
	//int &rval1 = i;  //�ǳ������õĳ�ʼֵ����Ϊ��ֵ�����Ƕ���ı�����int i = 1��i����ֵ��1����ֵ��
	//rval1 = 2;
	//std::cout << rval1 << std::endl;
	//int &a = i;
	int i = 0, &ri = i;
	i = 5; ri = 10;
	std::cout << i << "  " << ri << std::endl;
}

//2.20ָ��
void Pointer()
{
	//int *p1 = nullptr;
	//int *p2 = 0;
	//int *p3 = NULL;
	//std::cout << p1 << std::endl;
	//std::cout << p2 << std::endl;
	//std::cout << p3 << std::endl;	
	//int *pi = 0;
	//int i = 42;
	//int *pi = &i;
	//int **ppi2 = &pi;   //˫��ָ��
	//std::cout << i << std::endl;
	//std::cout << *pi << std::endl;
	//std::cout << **ppi2 << std::endl;
	int i = 42;
	int *p;
	int *&r = p;
	r = &i;
	*r = 0;
	std::cout << i << std::endl;
}

// const�޶���
void Fun_const()
{
	//int i = 42;
	//const int &r1 = i;	
	//const int &r2 = 42;
	//const int &r3 = r1 * 2;
	////int &r4 = r1 * 2;  //�ǳ����ĳ�ʼֵ����Ϊ��ֵ��Ҳ���Ǳ����Ƿǳ�������

	//std::cout << r1 << std::endl;	//42
	//i = 45;
	//std::cout << r1 << std::endl;	//45
	//std::cout << r3 << std::endl;	//84,r3�Ƕ�r1*2����������

	//double dval = 3.14;
	//const int &ri = dval;
	//std::cout << ri << std::endl;   //3


	// ���õ����ͱ������������ö��������һ�£��������⣺
	//1.����һ���������ð󶨷ǳ�����������ֵ��������һ��һ����ʽ
	//2.

	// ָ������ͱ���������ָ�Ķ��������һ�£��������⣺
	//1.����һ��ָ������ָ��ָ��һ���ǳ�������
	//2.

	//�����const int &(��int�ͳ���������)��const int *(ָ��int�ͳ�����ָ��) 
	//����Ϊָ���˳������������Ծ��ز�ȥ�ı���ָ�����ֵ����������ָ��Ĳ���һ���ǳ�������
	//����Ҫ�����ǲ���ͨ�����ú�ָ��ı���ָ�����ֵ
	
	
	
	
	//constָ��,����ָ�룬ָ�뱾����һ��������һ����ʼ����ɡ�����ֵ����������ŵĵ�ַ���Ͳ��ܸı��ˡ�
	//���ඨ����������Ķ���������ĺ���
	int errNumb = 0;
	int *const curErr = &errNumb;   //*����constǰ˵��ָ����һ������
	const double pi = 3.14159;
	const double *const pip = &pi;
	//����ָ��curErr��pip��curErrָ��һ��int�ͱ�����pipָ�����һ��double�ͳ�����
	//������curErr�޸�errNumb��ֵ�����ǲ�����pip�޸�pi��ֵ
	std::cout << *curErr << std::endl;  //0
	*curErr = 1;
	std::cout << *curErr << std::endl;	//1
}

//2.4.2����ϰ
void Const_and_pointer()
{
	//const int *p;
	//int i = 5;
	//p = &i;
	//i = 6;
	//std::cout << *p << std::endl;

	//����const������������ǳ����������޸ģ��͵ײ�const��ָ������õĶ���ʱconst���䱾������޸ģ�
	int i = 42, j = 45;
	const int *pi = &i;		//�ײ�const������ı�pi��ֵ
	pi = &j;
	std::cout << *pi << std::endl;
}


//constexpr�������ʽ
void Fun_constexper()
{
	//const int *p = nullptr;			//p��һ��ָ������������ָ��
	//constexpr int *q = nullptr;		//q��һ��ָ�������ĳ���ָ��
	//constexpr int *np = nullptr;	//np��һ��ָ�������ĳ���ָ�룬��ֵΪ��

	//int j = 0;
	//constexpr int i = 42;			//i�����������ͳ���
	//constexpr const int *p = &i;	//p�ǳ���ָ�룬ָ�����ͳ���i��
	////constexpr int *pl = &j;		//���ʽ���뺬�г���ֵ


}


//���ͱ���typedef
void Fun_typedef()
{
	char mychar1 = 'A', mychar2 = 'B';
	typedef char *pstring;				//pstring��char*���͵ı�������ôpstring����ָ��
	const pstring cstr = &mychar1;		//cstr��һ��ָ��char('A')�ĳ���ָ�� const����pstring���ͣ�����sctr����һ������ָ��
	const pstring *ps = &cstr;			//ps��һ��ָ�룬��ָ��Ķ�����ָ��char�ĳ���ָ�룻ps������һ��ָ�룬��ָ��һ������ָ���ָ��

	std::cout << *cstr << std::endl;	//���A��
	std::cout << **ps << std::endl;		//���A��

	char *const cstr2 = &mychar1;		//cstr2����һ��ָ���ַ��͵ĳ���ָ�룬��cstr����һ��
	std::cout << *cstr2 << std::endl;	//���A��

	*cstr2 = 'C';					
	std::cout << *cstr2 << std::endl;	//���C��

	const char *cstr3 = &mychar1;		//cstr3��һ��ָ���ַ�������ָ��
	cstr3 = &mychar2;
	std::cout << *cstr3 << std::endl;	//���B��
}

//auto����˵������auto�ñ�����ͨ����ʼֵ������������ͣ�auto����ı��������г�ʼֵ
void Fun_auto()
{
	//int val1 = 3,val2 = 3;
	//auto item = val1 + val2;  //item����Ϊval1��val2��ӵĽ��
	//std::cout << item << std::endl;
		
	//int i = 0, &r = i;
	//auto a = r;						//a��һ������
	//const int ci = 1, &cr = ci;		
	//auto b = ci;					//b��һ��������hulve����const��
	//auto c = cr;					//c��һ������
	//auto d = &i;					//d��һ������ָ�루�����ĵ�ַ����ָ��������ָ�룩
	//auto e = &ci;					//e��һ��ָ������������ָ�루�ײ�const��
	//const auto f = ci;				//f��һ�����ͳ���const int
	//auto &g = ci;					//g��һ�����ͳ���������
	////auto &h = 42;					//���󣬷ǳ������õĳ�ʼֵ����Ϊ��ֵ
	//const auto &j = 42;				//�������ÿ��԰�����ֵ


	//ex2.35
	const int i = 42;
	auto j = i;
	const auto &k = i;
	auto *p = &i;
	const auto j2 = i, &k2 = i;

	// print i means int, and PKi means pointer to const int.
	std::cout << "j is " << typeid(j).name()
		<< "\nk is " << typeid(k).name()
		<< "\np is " << typeid(p).name()
		<< "\nj2 is " << typeid(j2).name()
		<< "\nk2 is " << typeid(k2).name()
		<< std::endl;
}



//devltype����ָʾ��
void Fun_decltype()
{
	//int i = 42, *p = &i, &r = i;
	//decltype(r + 0) b;
	//decltype(*p) c = i;
	
	//ex2.36
	//int a = 3, b = 4;
	//decltype(a) c = a;		//c�Ǹ�����int
	//decltype((b)) d = a;	//d�Ǹ���������
	//++c;					// 4
	//++d;					//4

	//ex2.37
	//int a = 3, b = 4;			//a = 3,b = 4;
	//decltype(a) c = a;			//c��һ������int��3
	//decltype(a = b) d = a;		//d��һ���������ã�d = 3��  a = b����ִ��

	//ex2.38
	//decltypeָ�����ͺ�autoָ�������Ͷ��ɱ������õ���
	//int i = 0, &r = i;
	//auto a = i;
	//decltype(i) b = i;

	//auto c = r;			//c��һ��int
	//decltype(r) d = r;	//d��һ������
}

//�Զ������ݽṹ
struct Sales_data
{
	std::string bookNo;			//Ĭ�ϳ�ʼ��Ϊ���ַ���
	//std::string bookName;
	unsigned units_sold = 0;	//��������
	double revenue = 0.0;		//����
	double price = 0.0;			//�ۼ�
};

void Fun_sales_data1()
{
	//freopen("book_sales", "r", stdin);
	Sales_data book1,book2;
	std::cin >> book1.bookNo >> book1.units_sold >> book1.price;
	std::cin >> book2.bookNo >> book2.units_sold >> book2.price;
	book1.revenue = book1.units_sold*book1.price;
	book2.revenue = book2.units_sold*book2.price;
	//std::cout << book1.bookNo << std::endl;
	if (book1.bookNo == book2.bookNo)
	{
		unsigned total_sold = book1.units_sold + book2.units_sold;
		double total_revenue = book1.revenue + book2.revenue;
		std::cout << book1.bookNo << " " << total_sold << " " << total_revenue << " ";
		if (total_sold != 0)
		{
			double average_price = total_revenue / total_sold;
			std::cout << average_price << std::endl;
		}
		else
		{
			std::cout << "(No sales)" << std::endl;
		}
	}
	else
	{
		std::cerr << "Data must refer to the same ISBN" << std::endl;
	}
}

void Fun_sales_data2()
{
	Sales_data total;
	if (std::cin >> total.bookNo >> total.units_sold >> total.price)
	{
		total.revenue = total.units_sold*total.price;
		Sales_data trans;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price)
		{
			trans.revenue = trans.units_sold*trans.price;
			if (total.bookNo == trans.bookNo)
			{
				total.revenue += total.revenue + trans.revenue;
				total.units_sold += total.units_sold + trans.units_sold;
			}
			else
			{
				std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
				if (total.units_sold != 0)
				{
					total.price = total.revenue / total.units_sold;
					std::cout << total.price << std::endl;
				}
				else
					std::cout << "(no sales)" << std::endl;

				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
		if (total.units_sold != 0)
		{
			total.price = total.revenue / total.units_sold;
			std::cout << total.price << std::endl;
		}
		else
		{
			std::cout << "(no sales)" << std::endl;
		}
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
	}
}
int main()
{

	//DataType();
	//LiteralConstant();
	//VariableInitialValue();
	//VariableDefinitionAndDeclaration();

	//Reference();
	//Pointer();
	//Fun_const();

	//Const_and_pointer();
	//Fun_typedef();
	//Fun_auto();

	//Fun_decltype();
	//Fun_sales_data1();
	Fun_sales_data2();
	return 0;
}



