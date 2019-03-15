#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年3月8日 星期五
> Last edited time: 2019年3月9日 星期六
> Topic:C++Primer Chapter13.5 动态内存管理类
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "HasPtr.h"
//#include "HasPtr2.h"
//#include "Folder.h"
//#include "Message.h"
#include "StrVec.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "MyString.h"


using namespace std;


//ex13.42
void runQueries(ifstream &infile)
{
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);
	tq.print();
	//与用户交互，提示输入要查询的单词，完成查询并打印结果
	while (true)
	{
		cout << "====================================================" << endl;
		cout << "Please enter word to look for, or q to quit: ";
		string s;
		//如果没有输入或输入为 q
		if (!(cin >> s) || s == "q")
			break;
		//指向查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}
//Chapter13.5 动态内存管理类
void Fun_Classes_That_Manage_Dynamic_Memory()
{
	//某些类需要自己进行内存分配，一般来说必须定义自己的拷贝控制成员来管理所分配的内存
	//实现标准库vector类的简化版本，只适用于string，命名为：StrVec

	//StrVec类的设计
	//每个StrVec有三个指针成员指向其元素所使用的内存
	
	//移动构造函数和std::move

	//ex13.39
	//见定义

	//ex13.40
	//见定义
	//initializer_list<string> il = { "hello","world","C++" };
	//StrVec vec(il);
	//cout << vec.size() << endl;
	//cout << vec.capacity() << endl;
	//vec.print_str();
	//cout << "======================" << endl;
	//vec.resize(2,"hahah");
	//cout << vec.size() << endl;
	//cout << vec.capacity() << endl;
	//vec.print_str();
	
	//ex13.41
	//first_free指向的是一个空位置，前置递增的话会空一个位置

	//ex13.42
	//见TextQuery和QueryResult类定义
	//ifstream input("Text1.txt");
	//runQueries(input);
	
	//ex13.43
	//见CPP文件
		
	//ex13.44
	//char s[10] = { 'h','e','l','l','o', };
	//MyString str1(s);
	//printstr(cout, str1);
	//MyString str2(str1);
	//cout << str2.strlen() << endl;

}

//
//int main()
//{
//	//Chapter13.5 动态内存管理类
//	Fun_Classes_That_Manage_Dynamic_Memory();
//
//	return 0;
//}