#pragma once

#ifndef STRVEC_H
#define STRVEC_H

#include "header_include.h"

using namespace std;


class StrVec
{
public:
	//构造函数，allocator成员进行默认初始化
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}				
	//拷贝构造函数
	StrVec(const StrVec&);
	//拷贝赋值运算符
	StrVec& operator=(const StrVec&);
	//析构函数
	~StrVec();

	//成员函数
	void push_pack(const string&);		//拷贝元素
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	//所包含的元素个数
	size_t size() const { return first_free - elements; }
	//StrVec可以保存的元素的数量
	size_t capacity() const { return cap - elements; }

private:
	static allocator<string> alloc;		//分配元素
	//被添加元素的函数所使用
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	//工具函数，被拷贝构造函数、拷贝赋值运算符和析构函数所使用
	pair<string*, string*> alloc_n_copy(const string*, const string*);

	void free();			//销毁元素并释放内存
	void reallocate();		//获得更多内存并拷贝已有元素
	string *elements;		//指向数组首元素的指针
	string *first_free;		//指向数组第一个空闲元素的指针
	string *cap;			//指向数组尾后位置的指针

};

#endif // !STRVEC_H