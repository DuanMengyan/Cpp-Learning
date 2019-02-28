#pragma once

#ifndef HASPTR_H
#define HASPTR_H

#include "header_include.h"

using namespace std;


class HasPtr
{
public:
	friend void swap(HasPtr &, HasPtr &);
	friend bool operator<(const HasPtr&, const HasPtr &);
	friend void show(vector<HasPtr>&);

	HasPtr(const string &s = string()) :ps(new string(s)), i(0),use(new size_t(1)) {}
	
	//拷贝构造函数
	//对ps指向的string，每个HasPtr对象都有自己的拷贝
	HasPtr(const HasPtr &item) :ps(new string(*item.ps)), i(item.i),use(item.use)
	{ 
		++*use;
		cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//拷贝赋值运算符
	HasPtr& operator=(const HasPtr &);
	
	

	//析构函数
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;		//释放string内存
			delete use;		//释放计数器内存
		}
		
		//cout << *ps << " ***The_Destructor" << endl;
	}
private:
	string *ps;
	int i;
	size_t *use;
};


#endif // !HASPTR_H