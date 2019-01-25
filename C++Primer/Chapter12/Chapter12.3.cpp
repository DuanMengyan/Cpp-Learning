#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��25�� ������
> Last edited time: 2019��1��25�� ������
> Topic:C++Primer Chapter12.3 ʹ�ñ�׼�⣺�ı���ѯ����
************************************************************************/


#include "header_include.h"
//#include "fun.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "ConstStrBlobPtr.h"
#include "QueryResult.h"
#include "TextQuery.h"

using namespace std;

//Chapter12.3 ʹ�ñ�׼�⣺�ı���ѯ����
//Using the Library: A Text-Query Program



//void runQueries(ifstream &infile)
//{
//	//infile��һ��ifstream��ָ������Ҫ������ļ�
//	TextQuery tq(infile);
//	//���û���������ʾ����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
//	while (true)
//	{
//		cout << "Please enter word to look for, or q to quit: ";
//		string s;
//		//���û�����������Ϊ q
//		if (!(cin >> s) || s == "q")
//			break;
//		//ָ���ѯ����ӡ���
//		//print(cout, tq.query(s)) << endl;
//	}
//}

string str_proc(string &word)
{
	for (auto iter = word.begin(); iter != word.end();)
	{
		//ȫ�����Сд����ɾ�����ı�����
		*iter = tolower(*iter);
		if (ispunct(*iter) && (iter + 1 == word.end()))
			iter = word.erase(iter);
		else ++iter;
	}
	return word;
}


//Chapter12.3.1 �ı���ѯ�������
void Fun_Design_of_the_Query_Program()
{
	//�����г���������Ĳ������Ӷ��������Ƿ�����Ҫʲô�������ݽṹ
	//���ݽṹ������һ�����ӳ���Ľ��������������Ч
	//�Ӷ���һ�����������ļ����࿪ʼ��TextQuery
	//��ѯ���ؽ��Ҳ����Ϊһ���࣬QueryResult

	//����֮�乲������
	//ʹ��TextQuery��
	//�����һ����ʱ��������ʵ�ֳ�Ա֮ǰ���ȱ�д����ʹ������࣬���Կ������Ƿ������������Ҫ�Ĳ���


	//ex12.27

	//ex12.28
	ifstream input("Text3.txt");
	string strline;
	size_t row = 0;
	map<size_t, vector<string>> dectory;
	set<size_t> word_set;
	while (getline(input, strline))
	{
		istringstream words(strline);
		string word;
		while (words >> word)
		{
			word = str_proc(word);
			dectory[row].push_back(word);
		}
		++row;
	}
	//
	////��ӡ�ļ���ȡ���
	////for (size_t i = 0; i != row; ++i)
	////{
	////	cout << "Line " << i << ": ";
	////	for (auto word : dectory[i])
	////		cout << word << " ";
	////	cout << endl;
	////}
	//cout << "==================" << endl;
	//
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
	//		//���в�ѯ
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
	//		//��ӡ��ѯ���
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
	

}





//Chapter12.3.2




int main()
{
	//Chapter12.3.1 �ı���ѯ�������
	Fun_Design_of_the_Query_Program();
	return 0;
}
