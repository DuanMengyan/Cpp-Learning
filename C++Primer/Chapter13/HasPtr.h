#pragma once

#ifndef HASPTR_H
#define HASPTR_H

#include "header_include.h"

using namespace std;


class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	
	//拷贝构造函数
	//对ps指向的string，每个HasPtr对象都有自己的拷贝
	HasPtr(const HasPtr &item) :ps(new string(*item.ps)), i(item.i) 
	{ 
		cout << *ps << " ***The_Copy_Constructor" << endl;
	}
	//拷贝赋值运算符
	HasPtr& operator=(const HasPtr &);

	//析构函数
	~HasPtr()
	{
		delete ps;
		//cout << *ps << " ***The_Destructor" << endl;
	}
private:
	string *ps;
	int i;
};


#endif // !HASPTR_H