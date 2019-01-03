#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月3日 星期四
> Last edited time: 2019年1月3日 星期四
> Topic:C++Primer Chapter11.1 使用关联容器
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;



//Chapter11.1 使用关联容器
void Fun_Using_an_Associative_Container()
{
	//使用map:单词计数
	//map<string, size_t> word_count;
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input>>word)
	//{
	//	++word_count[word];
	//}
	//for (const auto &w : word_count)
	//{
	//	cout << w.first << " \t: " << w.second << ((w.second > 1) ? "times" : "time") << endl;
	//}

	//使用set:忽略常见单词
	//map<string, size_t> word_count;
	//set<string> exclude = { "The","But","And","Or","An","A","a","an","the" ,"but" ,"and" ,"or" };
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input>>word)
	//{
	//	//find返回一个迭代器，如果存在set中，指向该关键字，否则，指向尾后迭代器
	//	if (exclude.find(word) == exclude.end())
	//	{
	//		++word_count[word];
	//	}
	//}
	//for (const auto &w : word_count)
	//{
	//	cout << w.first << " \t: " << w.second << ((w.second > 1) ? "times" : "time") << endl;
	//}

	//ex11.1

	//ex11.2
	//list:需要双向列表的时候
	//vector:需要动态数组的时候
	//deque:双向队列，支持快速随机访问
	//map:字典
	//set:保持元素有序排列，唯一

	//ex11.3
	
	//ex11.4
	map<string, size_t> word_count;
	set<string> exclude = { "The","But","And","Or","An","A","a","an","the" ,"but" ,"and" ,"or" };
	string word;
	ifstream input("Chapter11.1.txt");
	while (input>>word)
	{
		for (auto iter = word.begin(); iter != word.end();)
		{
			//全部变成小写，并删除最后的标点符号
			*iter = tolower(*iter);
			if (ispunct(*iter))  iter = word.erase(iter);
			else ++iter;
		}
		++word_count[word];
	}
	for (const auto &w : word_count)
	{
		cout << w.first << " \t: " << w.second << ((w.second > 1) ? "times" : "time") << endl;
	}

}



int main()
{
	//Chapter11.1 使用关联容器
	Fun_Using_an_Associative_Container();
	return 0;
}