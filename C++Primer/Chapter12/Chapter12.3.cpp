#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月25日 星期五
> Last edited time: 2019年1月25日 星期五
> Topic:C++Primer Chapter12.3 使用标准库：文本查询程序
************************************************************************/


#include "header_include.h"
#include "fun.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "ConstStrBlobPtr.h"
//#include "QueryResult.h"
//#include "TextQuery.h"
#include "ex12.32.h"

using namespace std;

//Chapter12.3 使用标准库：文本查询程序
//Using the Library: A Text-Query Program

void runQueries(ifstream &infile)
{
	//infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile);
	//tq.print();
	tq.print_file();
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
		//print(cout, tq.query(s)) << endl;
		print_result(cout, tq.query(s)) << endl;
	}
}

//Chapter12.3.1 文本查询程序设计
void Fun_Design_of_the_Query_Program()
{
	//首先列出程序所需的操作，从而帮助我们分析需要什么样的数据结构
	//数据结构，定义一个更加抽象的解决方案，更加有效
	//从定义一个保存输入文件的类开始，TextQuery
	//查询返回结果也定义为一个类，QueryResult

	//在类之间共享数据
	//使用TextQuery类
	//在设计一个类时，在真正实现成员之前，先编写程序使用这个类，可以看到类是否具有我们所需要的操作


	//ex12.27

	//ex12.28
	//ifstream input("Text3.txt");
	//string strline;
	//size_t row = 0;
	//map<size_t, vector<string>> dectory;
	//set<size_t> word_set;
	//while (getline(input, strline))
	//{
	//	istringstream words(strline);
	//	string word;
	//	while (words >> word)
	//	{
	//		word = str_proc(word);
	//		dectory[row].push_back(word);
	//	}
	//	++row;
	//}
	//
	//打印文件读取结果
	//for (size_t i = 0; i != row; ++i)
	//{
	//	cout << "Line " << i << ": ";
	//	for (auto word : dectory[i])
	//		cout << word << " ";
	//	cout << endl;
	//}
	//cout << "==================" << endl;
	//


	//查询过程并输出查询结果
	//while (true)
	//{
	//	string s;
	//	int count = 0;
	//	cout << "Please enter word to look for, or q to quit: ";
	//	if (!(cin >> s) || s == "q")
	//	{
	//		cout << "End of query." << endl;
	//		break;
	//	}		
	//	else
	//	{
	//		//进行查询
	//		for (size_t i = 0; i != row; ++i)
	//		{
	//			for (auto word1 : dectory[i])
	//			{
	//				if (word1 == s)
	//				{
	//					++count;
	//					word_set.insert(i);
	//				}
	//			}
	//		}
	//		//打印查询结果
	//		cout << s << " occurs " << count << " time" << ((count > 1) ? "s: " : ": ") << endl;
	//		for (auto iter = word_set.begin(); iter != word_set.end(); ++iter)
	//		{
	//			cout << "(line " << *iter+1 << ") ";
	//			for (auto word2 : dectory[*iter])
	//			{
	//				cout << word2 << " ";
	//			}
	//			cout << endl;
	//		}
	//		cout << "=======================================================" << endl;
	//		word_set.clear();
	//	}
	//}


	//ex12.29
	//do
	//{
	//	//查询过程并打印查询结果
	//} while (true);

}

//Chapter12.3.2 文本查询程序类的定义
void Fun_Defining_the_Query_Program_Classes()
{
	//ex12.30
	//ifstream input("Text3.txt");
	//runQueries(input);
	
	//ex12.31
	//vector不能保证元素唯一，set更好，唯一，且有序

	//ex12.32
	//ifstream input("Text3.txt");
	//runQueries(input);

	//ex12.33
	ifstream input("Text3.txt");
	runQueries(input);
}



int main()
{
	//Chapter12.3.1 文本查询程序设计
	//Fun_Design_of_the_Query_Program();
	//Chapter12.3.2 文本查询程序类的定义
	Fun_Defining_the_Query_Program_Classes();
	return 0;
}
