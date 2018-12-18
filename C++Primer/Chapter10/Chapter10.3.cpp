#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��17�� ����һ
> Last edited time: 2018��12��18�� ���ڶ�
> Topic:C++Primer Chapter10.3 ���Ʋ���
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//10.3 ���Ʋ���
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
	//���Ȱ����ֵ�������֮��ȥ�����������ظ�����ɾ�����������ظ�Ԫ��
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


//10.3.1 ���㷨���ݺ���
void Fun_Passing_a_Function_to_an_Algorithm()
{
	//ν��
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	//printitem(words);
	////�ǵ����г���Ϊ3�ĵ������ڳ���Ϊ4�ĵ���֮ǰ��Ȼ���ǳ���Ϊ5�ĵ��ʣ��������ơ�
	//sort(words.begin(), words.end());
	//sort(words.begin(), words.end(), isShorter);
	//
	//printitem(words);
	
	
	//�����㷨
	//ifstream input("Text10.2.txt");
	//string word;
	//vector<string> words;
	//while (input >> word)
	//{
	//	words.push_back(word);
	//}
	////��word���ֵ����������򣬲������ظ�����
	//MyelimDups(words);
	//printitem(words);
	////���ճ����������򣬳�����ͬ�ĵ���ά���ֵ���
	//stable_sort(words.begin(), words.end(), isShorter);
	//printitem(words);
	
	//ex10.11
	
	//ex10.12
	//vector<Sales_data> vec;
	//Sales_data item;
	////���ļ��ж�ȡSales_data���ݲ����浽vec��
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
	////�Ƚ����������isbn��ʹ�øú�����������
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
	//10.3.1 ���㷨���ݺ���
	//Fun_Passing_a_Function_to_an_Algorithm();
	return 0;
}