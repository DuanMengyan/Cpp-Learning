#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年12月17日 星期一
> Last edited time: 2018年12月18日 星期二
> Topic:C++Primer Chapter10.3 定制操作
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//10.3 定制操作
template<typename Container>
void printitem(Container const& con)
{
	for (auto const &item : con)
	{
		cout << item << "   ";
	}
	cout << endl << "=============================" << endl;;
}

inline bool 
isShorter(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}

//ex10.11
void MyelimDups(vector<string> &words)
{
	//首先按照字典序排序，之后去除消除相邻重复项，最后删除排在最后的重复元素
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

//ex10.12
inline bool
compareIsbn(const Sales_data &item1,const Sales_data &item2)
{
	return item1.isbn() < item2.isbn();
}

//ex10.13
inline bool
stringsize(const string &str)
{
	return str.size() >= 5;
}


//10.3.1 向算法传递函数
void Fun_Passing_a_Function_to_an_Algorithm()
{
	//谓词
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	////是的所有长度为3的单词排在长度为4的单词之前，然后是长度为5的单词，依次类推。
	//sort(words.begin(), words.end());
	//sort(words.begin(), words.end(), isShorter);
	//
	//printitem(words);
	
	
	//排序算法
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	////将word按字典序重新排序，并消除重复单词
	//MyelimDups(words);
	//printitem(words);
	////按照长度重新排序，长度相同的单词维持字典序
	//stable_sort(words.begin(), words.end(), isShorter);
	//printitem(words);
	
	//ex10.11
	
	//ex10.12
	//vector<Sales_data> vec;
	//Sales_data item;
	////从文件中读取Sales_data数据并保存到vec中
	//ifstream input("Text10.3.txt");
	//while (read(input,item))
	//{
	//	vec.push_back(item);
	//}
	//for (auto &book : vec)
	//{
	//	print(cout, book);
	//}
	//cout << "==========================" << endl;
	////比较两个对象的isbn，使用该函数进行排序
	//sort(vec.begin(), vec.end(), compareIsbn);
	//for (auto &book : vec)
	//{
	//	print(cout, book);
	//}
	//cout << "==========================" << endl;

	//ex10.13
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	//auto flag = partition(words.begin(), words.end(), stringsize);
	//printitem(words);
	//auto iter = words.cbegin();
	//while (iter != flag)
	//{
	//	cout << *iter << "   ";
	//	++iter;
	//}
	//cout << endl;
}

int main()
{
	//10.3.1 向算法传递函数
	//Fun_Passing_a_Function_to_an_Algorithm();
	return 0;
}