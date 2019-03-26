#pragma once

#ifndef HASPTR_H
#define HASPTR_H

#include "header_include.h"

using namespace std;
class HasPtr2
{
public:
	friend void swap(HasPtr2 &, HasPtr2 &);
	friend bool operator<(const HasPtr2&, const HasPtr2 &);
	friend void show(vector<HasPtr2>&);

	HasPtr2(const string &s = string()) :ps(new string(s)), i(0){}

	//拷贝构造函数
	//对ps指向的string，每个HasPtr对象都有自己的拷贝
	HasPtr2(const HasPtr2 &item) :ps(new string(*item.ps)), i(item.i)
	{
		//cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//拷贝赋值运算符
	HasPtr2& operator=(const HasPtr2 &);
	
	
	//赋值运算符既是移动赋值运算符，也是拷贝赋值运算符
	//HasPtr2& operator=(HasPtr2 rhs)
	//{
	//	cout << "assignment" << endl;
	//	swap(*this, rhs);
	//	return *this;
	//}
	
	//添加的移动构造函数
	HasPtr2(HasPtr2 && p) noexcept:ps(p.ps), i(p.i) 
	{ 
		p.ps = nullptr;
		cout << "move constructor" << endl;
	}

	//移动赋值运算符
	HasPtr2& HasPtr2::operator=(HasPtr2 && p) noexcept
	{
		cout << "move assignment" << endl;
		if (this != &p)
		{
			ps = p.ps;
			i = p.i;
			p.ps = nullptr;
			p.i = 0;
		}
		return *this;
	}



	//打印字符串内容
	void print_str();

	//析构函数
	~HasPtr2()
	{
		delete ps;		//释放string内存
		//cout << *ps << " ***The_Destructor" << endl;
	}
private:
	string *ps;
	int i;

};


#endif // !HASPTR_H