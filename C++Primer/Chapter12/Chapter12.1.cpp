#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月10日 星期四
> Last edited time: 2019年1月12日 星期六
> Topic:C++Primer Chapter12.1 动态内存与智能指针
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

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
	//printitem(v1);
	
	//使用动态内存的一个常见原因是允许多个对象共享相同的状态
	
	//定义StrBlob类
	//元素访问成员函数
	//StrBlob的拷贝、赋值和销毁


}



int main()
{
	//12.1.1 shared_ptr类
	Fun_The_shared_ptr_Class();

	return 0;
}