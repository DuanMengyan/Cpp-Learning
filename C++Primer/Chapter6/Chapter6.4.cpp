#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter6.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��09��10�� ����һ
> Last edited time: 2018��9��11�� ���ڶ�
> Topic:C++Primer Chapter6.4 ��������
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

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


const string &shorterString(const string &s1, const string &s2)
{
	cout << "const string" << endl;
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
	cout << "string" << endl;
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

int *reset(int *val)
{
	*val = 5;
	return val;
}

//double * reset(double *val)
//{
//	*val = 5.5;
//	return val;
//}
//��������
void Fun_Overloaded_Functions()
{
	//const_cast ������
	//string str1 = "hello,C++", str2 = "hello,python";
	//const string& re = str1;
	//shorterString(str1, str2) = "AAA";
	//cout << str1 << endl;

	//�������غ������ֿ���
	//(1)�ҵ�һ�����ƥ��
	//(2)δ�ҵ�ƥ��
	//(3)�����Ե���

	//ex6.39
	//(a)�Ϸ����ظ������ǺϷ���
	//(b)�Ƿ������˷������ͣ�������һ��
	//(c)�Ϸ���

	int num = 6;
	int *p = reset(&num);
	cout << num << endl;


}


int main()
{
	Fun_Overloaded_Functions();
	return 0;
}


