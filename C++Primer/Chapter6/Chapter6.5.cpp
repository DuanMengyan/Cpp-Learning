#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月11日 星期二
> Last edited time: 2018年9月11日 星期二
> Topic:C++Primer Chapter6.5 特殊用途语言特性
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

//#define NDEBUG 
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

typedef string::size_type sz;

sz ht = 60;
sz wd = 80;
char def = ' ';

//默认实参初始值
void screen(sz = ht, sz = wd, char = def)
{
	cout << "ht: " << ht << endl;
	cout << "wd: " << wd << endl;
	cout << "def: " << def << endl;
}

//ex6.42
inline string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

//6.5.1默认实参
void Fun_Default_Arguments()
{
	//调用含有默认实参的函数时，可以包含该实参，也可以省略该实参
	//一旦某个形参被赋予了默认值，他后面的所有形参都必须有默认值

	//函数调用时实参按其位置解析，默认实参负责填补函数调用缺少的尾部实参
	//当设计含有默认实参的函数时，其中一项任务是合理设置形参的顺序，
	//尽量让不怎么使用默认值的形参出现在前面，而让那些经常使用默认值的形参出现在后面

	//默认实参声明
	//函数的后续声明只能为之前那些没有默认值的形参添加默认值，
	//而且该形参右侧的所有形参必须都有默认值。

	//默认实参初始值
	//用作默认实参的名字在函数声明所在的作用域内解析，
	//而这些名字的求值过程发生在函数调用时
	//ht = 120;
	//wd = 100;
	//def = '*';	
	//screen();

	//ex6.40
	//char *init(int wd, char, char bckgrnd, int he = 24);

	//6.41
	//(a)非法
	//(b)合法
	//(c)合法，但是与程序员初衷不符，wd将被赋值为*

	//ex6.42
	cout << make_plural(1, "success", "es") << endl;
	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "success", "es") << endl;
	cout << make_plural(2, "failure") << endl;


}

//ex6.44
inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

//6.5.2内联函数和constexpr函数
void Fun_Inline_and_constexpr_Functions()
{
	//内联函数可避免函数调用的开销
	//内联函数在每个调用点上“内联地”展开
	//在函数返回类型前面加上关键字inline,这样就可以将它声明成内联函数了
	//内联机制用于优化规模较小、流程直接、频繁调用的函数。

	//constexpr函数————能用于常量表达式的函数
	//遵循约定：函数的返回类型及所有形参的类型都得是字面值类型；
	//而且函数体中必须有且只有一条return语句
	//constexpr函数被隐式地指定为内联函数
	//允许constexpr函数的返回值并非一个常量，即它不一定返回常量表达式

	//内联函数和constexpr函数通常定义在头文件内

	//ex6.44
	cout << std::boolalpha << isShorter("hello,C++", "hello,python") << endl;

	//ex6.46

}

//ex6.5.3
void printVec(vector<int> &vec)
{
#ifndef NDEBUG
	cout<< "vector size: "<< vec.size() <<endl;
#endif
	if (!vec.empty())
	{
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		cout << tmp << " ";
	}
}

//6.5.3调试帮助
void Fun_Aids_for_Debugging()
{
	//assert预处理宏
	//assert宏使用一个表达式作为它的条件，
	//如果表达式为0，输出信息并终止程序执行
	//否则，assert什么也不做
	//assert宏常用于检查“不能发生”的条件

	//NDEBUG预处理表面
	//使用assert预处理宏。assert(expt); 若expr为假，则输出信息并终止程序。需包含头文件cassert。
	//使用预处理命令#define NDEBUG(置于cassert之前)可以关闭assert判断。
	//assert语句只在Debug下有效，Release下不会被执行

	vector<int> val_vec = { 1, 2, 3, 4, 5, 6 };
	printVec(val_vec);
}


int main()
{
	//6.5.1默认实参
	//Fun_Default_Arguments();

	//6.5.2内联函数和constexpr函数
	//Fun_Inline_and_constexpr_Functions();

	//6.5.3调试帮助
	Fun_Aids_for_Debugging();

	return 0;
}