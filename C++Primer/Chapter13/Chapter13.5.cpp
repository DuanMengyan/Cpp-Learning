#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��3��8�� ������
> Last edited time: 2019��3��9�� ������
> Topic:C++Primer Chapter13.5 ��̬�ڴ������
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
	//infile��һ��ifstream��ָ������Ҫ������ļ�
	TextQuery tq(infile);
	tq.print();
	//���û���������ʾ����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
	while (true)
	{
		cout << "====================================================" << endl;
		cout << "Please enter word to look for, or q to quit: ";
		string s;
		//���û�����������Ϊ q
		if (!(cin >> s) || s == "q")
			break;
		//ָ���ѯ����ӡ���
		print(cout, tq.query(s)) << endl;
	}
}
//Chapter13.5 ��̬�ڴ������
void Fun_Classes_That_Manage_Dynamic_Memory()
{
	//ĳЩ����Ҫ�Լ������ڴ���䣬һ����˵���붨���Լ��Ŀ������Ƴ�Ա��������������ڴ�
	//ʵ�ֱ�׼��vector��ļ򻯰汾��ֻ������string������Ϊ��StrVec

	//StrVec������
	//ÿ��StrVec������ָ���Աָ����Ԫ����ʹ�õ��ڴ�
	
	//�ƶ����캯����std::move

	//ex13.39
	//������

	//ex13.40
	//������
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
	//first_freeָ�����һ����λ�ã�ǰ�õ����Ļ����һ��λ��

	//ex13.42
	//��TextQuery��QueryResult�ඨ��
	//ifstream input("Text1.txt");
	//runQueries(input);
	
	//ex13.43
	//��CPP�ļ�
		
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
//	//Chapter13.5 ��̬�ڴ������
//	Fun_Classes_That_Manage_Dynamic_Memory();
//
//	return 0;
//}