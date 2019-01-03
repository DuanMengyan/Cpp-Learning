#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter11.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��3�� ������
> Last edited time: 2019��1��3�� ������
> Topic:C++Primer Chapter11.1 ʹ�ù�������
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;



//Chapter11.1 ʹ�ù�������
void Fun_Using_an_Associative_Container()
{
	//ʹ��map:���ʼ���
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

	//ʹ��set:���Գ�������
	//map<string, size_t> word_count;
	//set<string> exclude = { "The","But","And","Or","An","A","a","an","the" ,"but" ,"and" ,"or" };
	//string word;
	//ifstream input("Chapter11.1.txt");
	//while (input>>word)
	//{
	//	//find����һ�����������������set�У�ָ��ùؼ��֣�����ָ��β�������
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
	//list:��Ҫ˫���б��ʱ��
	//vector:��Ҫ��̬�����ʱ��
	//deque:˫����У�֧�ֿ����������
	//map:�ֵ�
	//set:����Ԫ���������У�Ψһ

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
			//ȫ�����Сд����ɾ�����ı�����
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
	//Chapter11.1 ʹ�ù�������
	Fun_Using_an_Associative_Container();
	return 0;
}