#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��12��17�� ����һ
> Last edited time: 2018��12��17�� ����һ
> Topic:C++Primer Chapter10.3 ���Ʋ���
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//10.3 ���Ʋ���



bool isShorter(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}
//ex10.11
void elimDups2(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

//ex10.12
bool compareIsbn(const Sales_data &item1,const Sales_data &item2)
{
	return item1.isbn < item2.isbn();
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
	//for (auto item : words)
	//{
	//	cout << item << "   ";
	//}
	//cout << endl << "=========================" << endl;
	////�ǵ����г���Ϊ3�ĵ������ڳ���Ϊ4�ĵ���֮ǰ��Ȼ���ǳ���Ϊ5�ĵ��ʣ��������ơ�
	//sort(words.begin(), words.end());
	//sort(words.begin(), words.end(), isShorter);
	//
	//for (auto item : words)
	//{
	//	cout << item << "   ";
	//}
	//cout << endl << "=========================" << endl;
	
	
	//�����㷨
	//elimDups2(words);
	//for (auto item : words)
	//{
	//	cout << item << "   ";
	//}
	//cout << endl << "=========================" << endl;
	//stable_sort(words.begin(), words.end(), isShorter);
	//for (auto item : words)
	//{
	//	cout << item << "   ";	
	//}
	//cout << endl << "=========================" << endl;
	
	//ex10.11



	//ex10.12
	//vector<Sales_data> vec;
	//Sales_data item;



	//ex10.13
}

int main()
{
	//10.3.1 ���㷨���ݺ���
	Fun_Passing_a_Function_to_an_Algorithm();
	return 0;
}