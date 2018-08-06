#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年07月28日 星期六
> Last edited time: 2018年08月3日 星期五
> Topic:C++Primer Chapter2
************************************************************************/



#include <iostream>//系统头文件的文件名要放在尖括号里给出，这是告诉编译器：应该到“标准的”地点寻找这个文件：#include <stdio.h>
#include "Chapter2.h"//自定义头文件的文件名要放在双引号里给出
#include <string>
#include <cstdlib>


using namespace std;

//2.3算数类型转换
void DataType() 
{ 		
	//unsigned int u = 10;		
	//int i = -42;	
	//std::cout << i + i << std::endl;	
	//std::cout << u + i << std::endl;	
	//unsigned u1 = 42, u2 = 10;	
	//std::cout << u1 - u2 << std::endl;
	//std::cout << u2 - u1 << std::endl;
	 
	
	//for (unsigned i = 10; i >= 0; --i)  //无符号的i永远也不会小于0，这种写法错误
	//	std::cout << i << std::endl;	
	
	
	
	/*表达式中既有带符号类型又有无符号类型；	
	当符号类型取值为负时，出现异常结果；
	因为带符号类型数会自动转换为无符号数。	*/
	
	int a = -1;	unsigned b = 1;	
	std::cout << a * b << std::endl;		//a转换为取模无符号数4294967295，结果为：4294967295
	unsigned u = 10, u2 = 42;	
	std::cout << u2 - u << std::endl;		//32	
	std::cout << u - u2 << std::endl;		//结果-32超出无符号类型范围，出现异常
	int i = 10, i2 = 42;	
	std::cout << i2 - i<< std::endl;		//32	
	std::cout << i - i2 << std::endl;		//-32	
	std::cout << i- u << std::endl;			//0	
	std::cout << u - i << std::endl;		//0


}

//2.8字面值常量
void LiteralConstant()  
{
	std::cout << "Hi \x4dO\115!\n";
	std::cout << '\115' << '\n';

	std::cout << "2\115" << std::endl;
	std::cout << '2' << '\t' << '\x4d' << std::endl;
}


std::string global_str; //空串
int global_int;
//2.10变量初始值
/*
/如果在定义变量时没有指定初值，那么变量会被默认初始化。
/三条性质：
/1、定义在任何函数体外的变量会被初始化为0。   
/2、定义在函数体内部的变量不会被初始化。 
/3、类的对象未被初始化，则初值由类决定。
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


//2.11变量声明与定义
/*
声明：使得名字为程序所知，如果想使用该变量，则必须实现包含其声明。声明会确定变量的名字和类型。

定义：创建与名字关联的实体。定义会申请存储空间，可能会赋予初始值。

如果想声明一个变量而不想定义它，那么可以在变量名前加extern关键字。
*/
void VariableDefinitionAndDeclaration()
{
	//int variable = 10; //定义变量variable
	std::cout << variable << std::endl;
	
}

//2.15引用(其实是变量的别名)
void Reference()
{	
	//int ival = 1.01;   //不合法的定义
	//int i = 1;
	//int &rval1 = i;  //非常量引用的初始值必须为左值（就是定义的变量，int i = 1；i是左值，1是右值）
	//rval1 = 2;
	//std::cout << rval1 << std::endl;
	//int &a = i;
	int i = 0, &ri = i;
	i = 5; ri = 10;
	std::cout << i << "  " << ri << std::endl;
}

//2.20指针
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
	//int **ppi2 = &pi;   //双重指针
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

// const限定符
void Fun_const()
{
	//int i = 42;
	//const int &r1 = i;	
	//const int &r2 = 42;
	//const int &r3 = r1 * 2;
	////int &r4 = r1 * 2;  //非常量的初始值必须为左值，也就是必须是非常量对象；

	//std::cout << r1 << std::endl;	//42
	//i = 45;
	//std::cout << r1 << std::endl;	//45
	//std::cout << r3 << std::endl;	//84,r3是对r1*2常量的引用

	//double dval = 3.14;
	//const int &ri = dval;
	//std::cout << ri << std::endl;   //3


	// 引用的类型必须与其所引用对象的类型一致，两种例外：
	//1.允许一个常量引用绑定非常量对象、字面值、甚至是一个一般表达式
	//2.

	// 指针的类型必须与其所指的对象的类型一致，两种例外：
	//1.允许一个指向常量的指针指向一个非常量对象
	//2.

	//定义的const int &(对int型常量的引用)和const int *(指向int型常量的指针) 
	//自以为指向了常量对象，所以自觉地不去改变所指对象的值，但是他们指向的并不一定是常量对象
	//仅仅要求他们不能通过引用和指针改变所指对象的值
	
	
	
	
	//const指针,常量指针，指针本身是一个常量，一旦初始化完成。它的值（即它所存放的地址）就不能改变了。
	//此类定义从右往左阅读理解声明的含义
	int errNumb = 0;
	int *const curErr = &errNumb;   //*放在const前说明指针是一个常量
	const double pi = 3.14159;
	const double *const pip = &pi;
	//常量指针curErr和pip，curErr指向一个int型变量，pip指向的是一个double型常量，
	//可以用curErr修改errNumb的值，但是不能用pip修改pi的值
	std::cout << *curErr << std::endl;  //0
	*curErr = 1;
	std::cout << *curErr << std::endl;	//1
}

//2.4.2节练习
void Const_and_pointer()
{
	//const int *p;
	//int i = 5;
	//p = &i;
	//i = 6;
	//std::cout << *p << std::endl;

	//顶层const（任意对象本身是常量，不可修改）和底层const（指针或引用的对象时const，其本身可以修改）
	int i = 42, j = 45;
	const int *pi = &i;		//底层const，允许改变pi的值
	pi = &j;
	std::cout << *pi << std::endl;
}


//constexpr常量表达式
void Fun_constexper()
{
	//const int *p = nullptr;			//p是一个指向整数常量的指针
	//constexpr int *q = nullptr;		//q是一个指向整数的常量指针
	//constexpr int *np = nullptr;	//np是一个指向整数的常量指针，其值为空

	//int j = 0;
	//constexpr int i = 42;			//i的类型是整型常量
	//constexpr const int *p = &i;	//p是常量指针，指向整型常量i；
	////constexpr int *pl = &j;		//表达式必须含有常量值


}


//类型别名typedef
void Fun_typedef()
{
	char mychar1 = 'A', mychar2 = 'B';
	typedef char *pstring;				//pstring是char*类型的别名，那么pstring就是指针
	const pstring cstr = &mychar1;		//cstr是一个指向char('A')的常量指针 const修饰pstring类型，所以sctr就是一个常量指针
	const pstring *ps = &cstr;			//ps是一个指针，它指向的对象是指向char的常量指针；ps首先是一个指针，是指向一个常量指针的指针

	std::cout << *cstr << std::endl;	//输出A；
	std::cout << **ps << std::endl;		//输出A；

	char *const cstr2 = &mychar1;		//cstr2先是一个指向字符型的常量指针，与cstr类型一致
	std::cout << *cstr2 << std::endl;	//输出A；

	*cstr2 = 'C';					
	std::cout << *cstr2 << std::endl;	//输出C；

	const char *cstr3 = &mychar1;		//cstr3是一个指向字符常量的指针
	cstr3 = &mychar2;
	std::cout << *cstr3 << std::endl;	//输出B；
}

//auto类型说明符，auto让编译器通过初始值来推算变量类型，auto定义的变量必须有初始值
void Fun_auto()
{
	//int val1 = 3,val2 = 3;
	//auto item = val1 + val2;  //item类型为val1和val2相加的结果
	//std::cout << item << std::endl;
		
	//int i = 0, &r = i;
	//auto a = r;						//a是一个整数
	//const int ci = 1, &cr = ci;		
	//auto b = ci;					//b是一个整数（hulve顶层const）
	//auto c = cr;					//c是一个整数
	//auto d = &i;					//d是一个整型指针（整数的地址就是指向整数的指针）
	//auto e = &ci;					//e是一个指向整数常量的指针（底层const）
	//const auto f = ci;				//f是一个整型常量const int
	//auto &g = ci;					//g是一个整型常量的引用
	////auto &h = 42;					//错误，非常量引用的初始值必须为左值
	//const auto &j = 42;				//常量引用可以绑定字面值


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



//devltype类型指示符
void Fun_decltype()
{
	//int i = 42, *p = &i, &r = i;
	//decltype(r + 0) b;
	//decltype(*p) c = i;
	
	//ex2.36
	//int a = 3, b = 4;
	//decltype(a) c = a;		//c是个整型int
	//decltype((b)) d = a;	//d是个整型引用
	//++c;					// 4
	//++d;					//4

	//ex2.37
	//int a = 3, b = 4;			//a = 3,b = 4;
	//decltype(a) c = a;			//c是一个整型int，3
	//decltype(a = b) d = a;		//d是一个整型引用，d = 3；  a = b并不执行

	//ex2.38
	//decltype指定类型和auto指定的类型都由编译器得到；
	//int i = 0, &r = i;
	//auto a = i;
	//decltype(i) b = i;

	//auto c = r;			//c是一个int
	//decltype(r) d = r;	//d是一个引用
}

//自定义数据结构
struct Sales_data
{
	std::string bookNo;			//默认初始化为空字符串
	//std::string bookName;
	unsigned units_sold = 0;	//销售数量
	double revenue = 0.0;		//收入
	double price = 0.0;			//售价
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



