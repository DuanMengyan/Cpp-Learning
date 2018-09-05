#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年09月03日 星期一
> Last edited time: 2018年9月05日 星期三
> Topic:C++Primer Chapter6.1 函数基础
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include "Chapter6.1.h"

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;
using std::begin;
using std::end;

//ex6.3
int fact(int i)
{
	if (i<0)
	{
		runtime_error err("Input cannot be a negative number");
		cout << err.what() << endl;
	}
	return i > 1 ? i * fact(i - 1) : 1;
}

//ex6.4
void myfact()
{
	for (int val, num; cout << "Enter val:" << endl, cin >> val;)
	{
		if (val < 0)
		{
			runtime_error err("Val cannot bo a negative number!");
			cout << err.what() << endl;
		}
		else
		{
			num = val;
			unsigned long long result = 1;
			while (num > 1)
				result *= num--;
			cout << val << "! = " << result << endl;
		}
	}

}

//ex6.5
void myabs(int val)
{
	cout << (val < 0 ? -val : val) << endl;
}

//Chapter6.1.1 局部静态对象
size_t const_calls()
{
	static size_t ctr = 0;  //局部静态对象，返回该函数被调用次数
	return ++ctr;
}

//ex6.7
size_t calls_count()
{
	static size_t num = 0;
	return num++;
}

//Chapter6.1 函数基础
void Fun_function_basics()
{
	//ex6.3
	//std::boolalpha 在输出流中将bool解析为单词true, false.
	//std::cout << std::boolalpha << (120 == fact(-1)) << std::endl;
	
	//ex6.4
	//myfact();

	//ex6.5
	//myabs(-5);

	//Chapter6.1.1 局部对象（Local Objects）
	//for (size_t i = 0; i != 10; ++i)
	//{
	//	cout << const_calls() << endl;
	//}

	//ex6.7
	//for (int i = 0; i < 5; ++i)
	//{
	//	cout << i + 1 << "  " << calls_count() << endl;
	//}

	//Chapter6.1.2 函数声明（Function Declarations）
	//Chapter6.1.3 分离式编译（Separate Compilation）

	cout << "hahah" << endl;


}




int main()
{
	Fun_function_basics();
	return 0;
}

