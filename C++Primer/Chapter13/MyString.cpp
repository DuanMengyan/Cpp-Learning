#include "MyString.h"

//打印string
void printstr(ostream & os, MyString & str)
{
	auto c = str.begin();
	for(;c!=str.end();++c) os << *c;
	os << endl;
}

//接受c风格字符串参数的构造函数
MyString::MyString(const char * s)
{
	auto s1 = const_cast<char*>(s);
	while (*s1)
	{
		++s1;
	}
	range_initialize(s,s1);
}	

//拷贝构造函数
MyString::MyString(const MyString &str)
{
	range_initialize(str.begin(), str.end());
	printstr(cout, *this);
	cout << "copy constructor" << endl; 
}

//拷贝赋值运算符
MyString & MyString::operator=(const MyString &str)
{
	auto data = alloc_n_copy(str.begin(), str.end());
	free();
	first_char = data.first;
	end_after_char = data.second;
	cout << "copy assignment operator" << endl;
	return *this;
}

//析构函数
MyString::~MyString()
{
	free();
}

//移动构造函数
MyString::MyString(MyString &&str)noexcept:first_char(str.first_char),end_after_char(str.end_after_char)
{
	cout << "move constructor" << endl;
	str.first_char = str.end_after_char = nullptr;
}

//移动赋值运算符
MyString & MyString::operator=(MyString && str) noexcept
{
	cout << "move assignment" << endl;
	if (this != &str)
	{
		free();
		first_char = std::move(str.first_char);
		end_after_char = std::move(str.end_after_char);
		str.first_char = str.end_after_char = nullptr;
	}
	return *this;
}


//一些工具函数
//会分配足够的内存来保存给定范围的元素，并将这些元素拷贝到新分配的内存中
pair<char*, char*> MyString::alloc_n_copy(const char * begin, const char * end)
{
	auto data = alloc.allocate(end - begin);
	return{ data,uninitialized_copy(begin,end,data) };
}

//用一个范围内的元素进行初始化（拷贝）
void MyString::range_initialize(const char *begin, const char *end)
{
	auto newdata = alloc_n_copy(begin, end);
	first_char = newdata.first;
	end_after_char = newdata.second;
}

//释放内存
void MyString::free()
{
	if (first_char)
	{
		for_each(first_char, end_after_char, [this](char& c) {alloc.destroy(&c); });
		alloc.deallocate(first_char, end_after_char - first_char);
	}
}


