#pragma once

#ifndef MYSTRING_H
#define MYSTRING_H

#include "header_include.h"

using namespace std;

class MyString
{
	friend void printstr(ostream& os,MyString& str);
public:
	//构造函数
	MyString() = default;
	//接受c风格字符串参数的构造函数
	MyString(const char *s);

	//拷贝构造函数
	MyString(const MyString&);
	
	//拷贝赋值运算符
	MyString& operator=(const MyString&);
	
	//析构函数
	~MyString();

	//移动构造函数
	MyString(MyString&&) noexcept;

	//移动赋值运算符
	MyString& operator=(MyString &&) noexcept;

	
	size_t strlen() { return end_after_char - first_char; }
	char* begin() const { return first_char; }
	char* end() const { return end_after_char; }


private:
	//一些工具函数
	//会分配足够的内存来保存给定范围的元素，并将这些元素拷贝到新分配的内存中
	pair<char*, char*>alloc_n_copy(const char*begin, const char*end);
	
	//用一个范围内的元素进行初始化（拷贝）
	void range_initialize(const char*,const char*);

	//释放内存
	void free();


private:
	//数据成员
	allocator<char> alloc;  //分配内存

	char *first_char;
	char *end_after_char;

};
#endif // !MYSTRING_H




