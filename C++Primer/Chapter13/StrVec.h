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
	//构造函数，使用初始化参数列表进行构造
	StrVec(initializer_list<string> il);


	//拷贝构造函数
	StrVec(const StrVec&);
	//拷贝赋值运算符
	StrVec& operator=(const StrVec&);
	//析构函数
	~StrVec();

	//成员函数
	void push_back(const string&);		//拷贝元素
	void print_str();					//打印元素
	string *begin() const { return elements; }
	string *end() const { return first_free; }

	//所包含的元素个数
	size_t size() const { return first_free - elements; }
	//StrVec可以保存的元素的数量
	size_t capacity() const { return cap - elements; }
	//通知容器它应该准备保存多少个元素
	void reserve(const size_t);
	//改变容器大小
	void resize(const size_t);
	void resize(const size_t, const string&);
	//判断是否为空
	bool empty();


private:
	//被添加元素的函数所使用
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	//工具函数，被拷贝构造函数、拷贝赋值运算符和析构函数所使用
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	//销毁元素并释放内存
	void free();			
	//获得更多内存并拷贝已有元素
	void reallocate();		
	//分配内存，将一定数量的元素从旧内存移动到新内存
	void alloc_move_n(size_t new_cap);
	//用一个范围内的元素进行。内存分配，然后初始化（拷贝）
	void range_initialize(const string*,const string*);
	
private:
	allocator<string> alloc;//分配元素
	string *elements;		//指向数组首元素的指针
	string *first_free;		//指向数组第一个空闲元素的指针
	string *cap;			//指向数组尾后位置的指针

};

#endif // !STRVEC_H