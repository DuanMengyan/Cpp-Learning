#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月08日 星期六
> Last edited time: 2018年9月10日 星期一
> Topic:C++Primer Chapter6.3 返回类型和return语句
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::initializer_list;



//6.3.1
void swap(int &v1, int &v2)
{
	if (v1 == v2)
	{
		cout << "fun_end" << endl;
		return;
	}
	int temp = v1;
	v1 = v2;
	v2 = temp;
	cout << v1 <<"  swap  "<< v2 << endl;
}

//6.3.1 无返回值函数
void Fun_function_without_return_value()
{
	//int val1 = 5, val2 = 6;
	//swap(val1, val2);
}

//引用返回左值
char &get_value(string &str, string::size_type ix)
{
	return str[ix];
}

//列表初始化返回值
vector<string> process(string expected,string actual)
{
	if (expected.empty())
		return{};
	else if (expected == actual)
		return{ "functionX", "okay" };
	else
		return{ "functionX", expected, actual };
}

//递归
int factorial(int val)
{
	if (val > 1)
		return val * factorial(val - 1);
	return 1;
}

//ex6.30
bool str_subrange(const string &str1, const string &str2)
{
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
	for (decltype(size)i = 0; i != size; ++i)
	{
		if (str1[i] != str2[i])
			return  false;
	}
	return true;
}

//ex6.32
int &get(int *array, int index) { return array[index]; }

//ex6.33
void print_vec(vector<int>::const_iterator first,vector<int>::const_iterator last)
{
	if (first != last)
	{
		cout << *first << "  ";
		print_vec(first + 1, last);
	}
	else cout << endl;
}

//6.3.2 有返回值函数
void Fun_function_with_return_value()
{
	//函数返回一个值的方式和初始化一个变量或形参的方式完全一样：返回的是用于初始化调用点的一个临时量
	//同其他引用一样，如果函数返回引用，则该引用仅是她所引用对象的一个别名。

	//不要返回局部对象的引用或指针
	//函数完成之后，它所占用的存储空间随之被释放掉，局部变量的引用将指向不再有效的内存区域

	//引用返回左值
	//调用一个返回引用的函数得到左值，其他返回类型得到右值

	//string s("a value");
	//cout << s << endl;
	//get_value(s, 0) = 'A';
	//cout << s << endl;

	//列表初始化返回值
	//string str1 = "helloworld", str2 = "helloworld";
	//vector<string> str_vec;
	//str_vec = process(str1,str2);
	//for (auto str : str_vec)
	//{
	//	cout << str << endl;
	//}
	
	//cout << factorial(5) << endl;

	//ex6.30
	//string str1 = "HelloWorld", str2 = "HelloWorld";
	//cout << std::boolalpha << str_subrange(str1, str2) << endl;
	
	//ex6.32
	//int ia[10];
	//for (int i = 0; i != 10; ++i)
	//{
	//	get(ia, i) = i;
	//}
	//for (int i = 0; i != 10; ++i)
	//{
	//	cout << ia[i] << endl;
	//}


	//ex6.33
	//vector<int> vec{ 0, 1, 2, 3, 4, 5 };
	//print_vec(vec.begin(), vec.end());
}


//ex6.36 声明一个返回数组指针的函数
string (&func(string (&arrstr)[5]))[5];

//typedef string arrT[5];
using arrT = string[5];

//ex6.37 类型别名
arrT& func(arrT arr_string);

//ex6.37 使用尾置返回类型
auto func(int i)-> string (&)[5];

//ex6.37-ex6.38 使用decltype
string str1[5] = { "hello1", "hello1", "hello1", "hello1", "hello1" };
string str2[5] = { "hello2", "hello2", "hello2", "hello2", "hello2" };

decltype(str1) & arrPtr(int i)
{
	return (i % 2) ? str1 : str2;
}


//6.3.3 返回数组指针
void Fun_Returning_a_Pointer_to_an_Array()
{
	//string str3[] = { "hello", "world" };
	//func(str3);

	arrPtr(3)[4] = "AAA";
	cout << arrPtr(3)[4] << endl;
}

int main()
{
	//6.3.1 无返回值函数
	//Fun_function_without_return_value();

	//6.3.2 无返回值函数
	//Fun_function_with_return_value();

	//6.3.3 返回数组指针
	Fun_Returning_a_Pointer_to_an_Array();

	return 0;
}