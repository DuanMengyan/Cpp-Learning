#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月10日 星期四
> Last edited time: 2019年1月21日 星期一
> Topic:C++Primer Chapter12.1 动态内存与智能指针
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
#include "StrBlob.h"

using namespace std;

//Chapter12.1 动态内存与智能指针
//Dynamic_Memory_and_Smart_Pointers


shared_ptr<int> factory(int i)
{
	return make_shared<int>(i);
}

shared_ptr<int> factory2(int i)
{
	shared_ptr<int> p = factory(i);
	return p;
}//p离开了作用于，但它指向的内存不会被释放掉

//12.1.1 shared_ptr类
void Fun_The_shared_ptr_Class()
{
	//shared_ptr<string> p1;
	//shared_ptr<list<int>> p2;
	//string str = "HI";
	//if (p1 && p1->empty())
	//{
	//	*p1 = str;
	//}


	//make_shares函数,安全地使用和分配动态内存
	//此函数在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr。
	//shared_ptr<int> p3 = make_shared<int>(42);
	//shared_ptr<string> p4 = make_shared<string>(10, '9');
	//cout << p3 << "   " << *p3 << endl;
	//shared_ptr<int> p5 = make_shared<int>();
	//cout << p5 << "   " << *p5 << endl;
	//vector<string> vec{ "C++","hello" };
	//auto p6 = make_shared<vector<string>>(vec);
	//cout << p6 << "   " << *((*p6).begin()) << endl;
	
	//shared_ptr的拷贝和赋值
	//auto p = make_shared<int>(42);
	//auto q(p);
	//cout << *q << endl;
	//cout << p.use_count() << endl;			//2,返回与p共享对象的智能指针数量,引用计数
	////一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象
	//auto r = make_shared<int>(50);
	//cout << r.use_count() << endl;			//1，此时只有r指向了在动态内存中分配的int 50
	//r = q;									//r被赋予一个新值，原来的int50自动被销毁
	//cout << p.use_count() << endl;			//3，q赋值给了r，引用计数+1
	//cout << r.use_count() << endl;			//3，r和p、q都指向int 42，引用计数为3

	//shared_ptr自动销毁所管理的对象
	//析构函数控制此类型对象销毁时做什么操作，析构函数一般用来释放对象所分配的资源
	
	//shared_ptr还会自动释放相关联的内存

	//auto q = factory2(42);
	//cout << q << "  " << *q << "  " << q.use_count() << endl;
	//如果将shared_ptr存放在一个容器中，随后重排了容器，从而不再需要某些元素。
	//在这种情况下，应该确保用erase删除那些不再需要的shared_ptr元素。
	
	//使用了动态生存期的资源的类。
	//程序使用动态内存的原因：
	//1.程序不知道自己需要使用多少对象；
	//2.程序不知道所需对象的准确类型；
	//3.程序需要在多个对象间共享数据；
	//vector<string> v1;
	//{
	//	//新作用域
	//	vector<string> v2 = { "a","an","the" };
	//	v1 = v2;
	//}
	
	//使用动态内存的一个常见原因是允许多个对象共享相同的状态
	
	//定义StrBlob类
	//元素访问成员函数
	//StrBlob的拷贝、赋值和销毁

	//ex12.
	//StrBlob b1;
	//{
	//	StrBlob b2 = { "a","an","the" };
	//	b1 = b2;
	//	b2.push_back("about");
	//}
	//cout << b1.size() << endl;  //4，b2不存在了

	//ex12.2
	//略

	//ex12.3
	//可以，但是没有必要。StrBlob只是一个指针，因为push_back和pop_back并不修改数据，它们修改数据指向的vector<string>;

	//ex12.4
	//因为i是vector<string>::size_type类型，是unsigned，当i小于0时，会自动转换成大于0的数	

	//ex12.5
	//StrBlob item2 = { "C++","hello","primer","python" };
	//构造函数只能直接初始化，不能使用上面拷贝形式的初始化过程
}


//ex12.6
vector<int> *fun1()
{
	vector<int> *p_vec = new vector<int>;
	return p_vec;
}

vector<int> fun2(vector<int>*p_vec)
{
	int num;
	ifstream input("Text1.txt");
	while (input >> num)
	{
		p_vec->push_back(num);
	}
	return *p_vec;
}

void fun_print(vector<int> vec)
{
	printitem(vec);
}

//ex12.7
using Sptr = shared_ptr<vector<int>>;

Sptr fun3()
{
	Sptr p_vec = make_shared<vector<int>>() ;
	return p_vec;
}

Sptr fun4(Sptr p_vec)
{
	int num;
	ifstream input("Text1.txt");
	while (input >> num)
	{
		p_vec->push_back(num);
	}
	return p_vec;
}

void fun_print2(Sptr p_vec)
{
	printitem(*p_vec);
}



//12.1.2 直接管理内存
void Fun_Managing_Memory_Directly()
{
	//运算符new分配内存，delete释放new分配的内存
	//使用new动态分配和初始化对象。
	//自由空间分配的内存是无名的，new返回一个指向该对象的指针。
	
	//int *pi = new int;						//*pi未定义
	//string *ps = new string(10, '9');		//值初始化
	//值初始化的内置类型对象有着良好定义的值，而默认初始化的对象的值则是未定义的
	//类中依赖于编译器合成的默认构造函数的内置类型成员，如果它们未在类内被初始化，那么他们的值也是未定义的。
	//当括号中仅有单一初始化器时才可以使用auto

	//动态分配const对象
	//一个动态分配的const对象必须进行初始化
	//const int *pci = new const int(1024);
	//cout << *pci << endl;
	//const string *pcs = new const string("hello world!");
	//cout << *pcs << endl;

	//内存耗尽
	//定位new表达式允许我们向new传递额外的参数。
	//int *p2 = new (nothrow) int;			//如果内存分配失败，new返回一个空指针
	
	//释放动态内存
	//我们通过delete表达式来将动态内存归还给系统。
	//delete表达式接受一个指针，指针我们想要释放的对象。
	//销毁对象，释放内存

	//指针值和delete
	//传递给delete的指针必须指向动态分配的内存，或者是一个空指针。
	//释放一块非new分配的内存，或者将相同的指针值释放多次，其行为是未定义的。
	//int i, *pi1 = &i, *pi2 = nullptr;
	//double *pd = new double(33), *pd2 = pd;
	//cout << *pd2 << endl;	
	//delete pd;
	//cout << *pd2 << endl;  //异常值(不是33)

	//动态对象的生存期直到被释放时为止
	//由内置指针(而不是智能指针)管理的动态内存在被显示释放前一直都会存在
	
	//动态内存的管理非常容易出错：因此要坚持使用智能指针。
	//1.忘记delete内存；
	//2.使用已经释放掉的对象；
	//3.同一块内存释放两次

	//delete之后重置指针值
	//可以在delete只有将nullptr赋予指针，表示指针不指向任何对象
	//在实际系统中，查找指向相同内存的所有指针是异常困难的

	//ex12.6
	//vector<int> *temp_vec = fun1();
	//fun_print(fun2(temp_vec));
	//delete temp_vec;

	//ex12.7
	//Sptr temp_vec = fun3();
	//fun_print2(fun4(temp_vec));
	
	//ex12.8
	//p将转换为bool型，动态分配的内存将无法释放，最终会造成内存泄漏
	
	//ex12.9
	//int *q = new int(42), *r = new int(100);
	//r = q;		//内存泄漏r指向动态内存中的42，保存100的内存还未被释放，需要delete r，否则会造成内存泄漏;
	//cout << *r << endl;		
	//auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
	//r2 = q2;	//安全，最后一个指向动态内存中100的智能指针r2指向42，保存100的内存被自动释放；
	//cout << *r2 << endl;


}


int main()
{
	//12.1.1 shared_ptr类
	//Fun_The_shared_ptr_Class();
	//12.1.2 直接管理内存
	Fun_Managing_Memory_Directly();
	return 0;
}